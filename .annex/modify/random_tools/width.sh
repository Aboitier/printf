#!/bin/bash

flag=$1
width=$[ ( RANDOM % 3 ) + 1 ]
	if [ $width == "1" ];then
		flag+="";
	elif [ $width == "2" ];then
		flag+=$[ ( RANDOM % 5 ) + 1 ];
	elif [ $width == "3" ];then
		flag+=$[ ( RANDOM % 12 ) + 5 ];
	fi
export flag
