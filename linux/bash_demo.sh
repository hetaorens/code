#!/bin/bash
set -x
x=*
echo $x

x=(*)
echo $x
echo ${x[@]}
set +x
set |grep x=|grep "x*)$"




