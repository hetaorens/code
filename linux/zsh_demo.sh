#!/bin/zsh
set -x

x=*
echo $x
x=(*)
echo $x
set +x
set |grep x=|grep "x*)$"




