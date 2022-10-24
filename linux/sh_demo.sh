#!/bin/sh
set -x

x=*
echo $x
set +x

set |grep x=|grep "^x"


