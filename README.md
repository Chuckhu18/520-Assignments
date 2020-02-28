# EE P 520 A Wi 20

Software Engineering For Embedded Applications

## Homeworks

Use docker container to mount on local drive.

```bash
docker run -v $PWD/520-Assignments:/source -it klavins/520w20:cpp bash
```

For elma updates.

```bash
docker pull klavins/elma:latest
docker run -v $PWD:/source -it klavins/elma:latest bash
```

