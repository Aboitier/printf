#!/bin/sh

if [ \( "$1" == 1 \) ];then
	flag="hh";
elif [ \( "$1" == 2 \) ];then
	flag="h";
elif [  \( "$1" == 3 \) ];then
	flag="l";
elif [  \( "$1" == 4 \) ];then
	flag="ll";
elif [  \( "$1" == 5 \) ];then
	flag="";
fi
export flag
