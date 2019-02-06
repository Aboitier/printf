#!/bin/sh

rand=$[ ( RANDOM % 6 ) + 1 ]
if [  \( "$rand" == 1 \) ];then
	flag+="\x20";
elif [  \( "$rand" == 2 \) ];then
    flag+="#";
elif [  \( "$rand" == 3 \) ];then
    flag+="0";
elif [  \( "$rand" == 4 \) ];then
    flag+="+";
elif [  \( "$rand" == 5 \) ];then
    flag+="-";
elif [  \( "$rand" == 6 \) ];then
    flag+="";
fi
export flag
