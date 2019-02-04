!/bin/sh

if [  \( "$1" == 1 \) ];then
	flag="l";
elif [  \( "$1" == 2 \) ];then
	flag="ll";
elif [  \( "$1" == 3 \) ];then
	flag="";
fi
export flag
