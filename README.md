# lib2shell  

**Author: Sean Pesce**  
**Modified by Jonas Heschl**

## Why this fork?

This fork fixes two issues when attemtping code execution using lib2shell.

1. ssh-keygen makes a rudimentary check when loading libraries using `ssh-keygen -D`. If the check fails (eg. ssh-keygen does not think the provided library is really a pkcs11 library) the library will never be loaded and thus the code never be executed.

2. This fork preserves the effective user id when spawning a shell. This is mostly useful when ssh-keygen/openssl has SUID set.

## Overview  

Shared library implementations that transform the containing process into a shell on load (useful for privilege escalation, argument injection, file overwrites, etc.). A write-up of the original version found on [Sean Pesces blog](https://seanpesce.blogspot.com/2023/03/leveraging-ssh-keygen-for-arbitrary.html).

## Usage  

**([Many examples on GTFOBins](https://gtfobins.github.io/#+library%20load))**  

Examples for Unix operating systems:  

```
ssh-keygen -D ./lib2shell.so
```

```
openssl req -engine ./lib2shell.so
```

## Compiling  

Unix:  

```
cd unix

make
```

## Windows

Note that this fork drops Windows support. Feel free to open a PR if you know your way around that operating system!

