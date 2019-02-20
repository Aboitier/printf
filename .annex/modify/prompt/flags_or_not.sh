#!/bin/bash

if [[ $1 ]]; then
	sh .annex/modify/change_flags.sh
	exit
fi

while true; do
	read -p "Do you also want to generate random flags, options, width...for your variables? [y/n] " yn
	case $yn in
		[Yy]* ) sh .annex/modify/change_flags.sh; break;;
		[Nn]* ) break;;
		* ) echo "Please answer yes or no, no joke this time";;
	esac
done

