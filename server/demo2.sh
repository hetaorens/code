#!/bin/bash
for ((i=1;i<=9;i++));do
   for ((j=1;j<=i;j++));do
     echo -n "$i x $j = $(expr $i \* $j) "
    if [ $j -eq $i ];then echo 
    fi
 done
done

for ((i=1;i<=9;i++))
do
	for ((j=1;j<=i;j++); do
		echo -n "$i x $j =$(expr $i \* $j)"
		if [ $j-eq $i ];then echo
		fi
	done
	done
