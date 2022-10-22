#!/bin/bash
a=$1
b=${#a}
b=`expr $b - 4 `
echo $b
echo ${a:0:-4}
nasm -f elf $a &&ld -m elf_i386 -s ${a:0:b}.o