#include "gtest/gtest.h"
#include "elma/elma.h"
#include "stopwatch.h"
#include "random_process.h"
#include "filter.h"
#include "integrator.h"
#include "derivative.h"
#include <iostream>

#define SLEEP std::this_thread::sleep_for(std::chrono::milliseconds(1500))


namespace {
    using namespace std;
    using namespace std::chrono; 
    using namespace elma;   
    typedef std::chrono::duration<int,std::nano> nanoseconds_type;

    TEST(Stopwatch, Test) {
        Stopwatch w; // should set the stopwatch to 0 seconds
        w.start(); 
        SLEEP;
        w.stop();
        ASSERT_NEAR(w.get_seconds(), 1.5, 0.01);
        SLEEP;
        ASSERT_NEAR(w.get_seconds(), 1.5, 0.01);
        w.start(); 
        SLEEP;
        w.stop();    
        ASSERT_NEAR(w.get_seconds(), 3.0, 0.01);
        w.reset();
        ASSERT_NEAR(w.get_seconds(), 0.0, 0.01);
    }

    class TestProcess : public Process {
        public:

        TestProcess(std::string name) : Process(name) {}
        void init() {}
        void start() {}
        void update() {
            if (toggle) {
                channel("link").send(0.25);
            } else {
                channel("link").send(0.75);
            }
            toggle = !toggle;
        }
        void stop() {}

        private:

        bool toggle = true;;
    };

    TEST(Filter, Test) {
        elma::Manager m;

        TestProcess p("alternate");
        Filter f("filter");
        elma::Channel link("link");

        m.schedule(p, 1_ms)
         .schedule(f, 1_ms)
         .add_channel(link)
         .init()
         .run(100_ms);
        
        ASSERT_EQ(f.value(), 0.5);
    }

    TEST(RandomProcess, sendRandVal) {
        elma::Manager m;
        RandomProcess r("random numbers");
        Filter f("filter");
        elma::Channel link("link");

        m.schedule(r, 1_ms)
         .schedule(f, 1_ms)
         .add_channel(link)
         .init()
         .run(10000_ms);
        
        ASSERT_NEAR(f.value(), 0.5, 0.2);
    }

    class TestIntegrator : public Process {
        public:
        
            TestIntegrator(std::string name) : Process(name) {}
            void init() {}
            void start() {}
            void update() {
                channel("link").send(_input);
                _input++;
            }
            void stop() {}
        
        private:
            double _input = 1;
    };

    TEST(Integrator, Integrate) {
        elma::Manager m;
        elma::Channel link("link");
        TestIntegrator ti("test integrator");
        Integrator i("integrate numbers");
        m.schedule(ti, 1_ms)
         .schedule(i, 1_ms)
         .add_channel(link)
         .init()
         .run(10_ms);
        
        ASSERT_NEAR(i.value(), 45 , 3);
    }

    class TestDerivative : public Process {
        public:
        TestDerivative(std::string name) : Process(name) {}
        void init() {}
        void start() {}
        void update() {
            channel("link").send(_input);
            _input++;
        }
        void stop() {}
        private:
        double _input = 1;
    };

    TEST(Derivative, Derivative) {
        elma::Manager m;
        elma::Channel link("link");
        TestDerivative td("test derivative");
        Derivative d("take derivative");
        m.schedule(td, 1_ms)
         .schedule(d, 1_ms)
         .add_channel(link)
         .init()
         .run(10_ms);
        
        ASSERT_NEAR(d.value(), 1, 0.1);
    }
}