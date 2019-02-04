#!/bin/sh

flag=$2
if [  \( "$1" == 1 \) ];then
	flag+="\x20";
elif [  \( "$1" == 2 \) ];then
    flag+="#";
elif [  \( "$1" == 3 \) ];then
    flag+="0";
elif [  \( "$1" == 4 \) ];then
    flag+="+";
elif [  \( "$1" == 5 \) ];then
    flag+="-";
elif [  \( "$1" == 6 \) ];then
    flag+="";
fi
export flag
