#!/bin/sh

flag=$1
rand=$[ ( RANDOM % 3 ) + 1 ]
if [  \( "$rand" == 1 \) ];then
	flag+="l";
elif [  \( "$rand" == 2 \) ];then
	flag+="ll";
elif [  \( "$rand" == 3 \) ];then
	flag+="";
fi
export flag
