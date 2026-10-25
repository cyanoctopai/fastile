# Fastile

Fastile is a fast image tiling and chipping tool written in C. It was written to easily load in large image files and tile them out into smaller, potentially overlapping images. It works by loading a reference to the image file instead of the image itself. This allows the application to directly read the bytes from the image files instead of having to load the full image in memory. This makes the program quite memory-efficient and fast. It also includes additional functionality to chip out smaller regions from the source image and save those out to separate image files.

## Building the application

In order to build the application, you will need a C compiler like GCC. Then you can simply build the application by linking in the source code:

```bash
gcc -o fastile main.c
```

A helper script to do this has been provided, and can be run with the following commands:

```bash
chmod 777 build.sh
bash build.sh
```

Then you can run the program:

```bash
./fastile
```
