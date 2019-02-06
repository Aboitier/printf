#!/bin/bash

#
### CLEANING
#
sed -i '' "/;/d" .annex/real_printf.c
sed -i '' '/^[[:space:]]*$/d' .annex/real_printf.c
awk -v n=3 -v s="\n" 'NR == n {print s} {print}' .annex/real_printf.c > .annex/tmp
cat .annex/tmp > .annex/real_printf.c
perl -0777 -pe 's {\{} {$&\n\treturn (0);}g' .annex/real_printf.c > .annex/tmp
cat .annex/tmp > .annex/real_printf.c
#
### SETTING UP
#
re='^[0-9]+$'
i=0
echo "Hi, how many printf lines do you want?"

read line_nb

if ! [[ $line_nb =~ "$re" ]];then
	while ! [[ $line_nb =~ $re ]]; do
		if [[ $i = 0 ]];then 
			echo "That was not correct, please input a number between 0 and 5 (or more)"
		elif [[ $i = 1 ]];then
			echo "can you read English?"
		elif [[ $i = 2 ]];then
			echo "you life is a lie and your mum a b****"
		elif [[ $i = 3 ]];then
			echo "just fcking get lost, DISAPPEAR!! YOURE NOT WORTH MY TIME"
		elif [[ $i -gt 3 ]];then
			echo "..................."
		fi
		read line_nb
		i=$[$i+1]
	done
fi

echo "Thank you. $line_nb lines have been set up."

#
### INPUTTING
#
i=0
add_var=""
while [[ "$i" -lt "$line_nb" ]]
do
	j=0
	input_pf=""
	var_name=""
	pct_nb=$[ ( RANDOM % 4 ) + 1]
	while [ "$j" -lt "$pct_nb" ]
	do
		var_index="$i$j"
		. .annex/modify/random_tools/conv_select.sh
   		input_pf+=%$conv
		. .annex/modify/random_tools/variables.sh "${conv}"
		. .annex/modify/random_tools/designation.sh "${conv}" "${var_index}"
		add_var=([0]=""${designation[0]}" = "${var[0]}"")
		perl -0777 -pe "s {\)\n\{} {$&\n\t${add_var[0]}}g" .annex/real_printf.c > .annex/tmp
		cat .annex/tmp > .annex/real_printf.c
		. .annex/modify/random_tools/var_name.sh $conv $var_index
		var_name+="$chosen_name,"
		j=$[$j + 1]
	done
		var_name=`echo $var_name | sed 's/.$//'`
		if [ $i -lt 1 ];then
			awk '/return/{c++;if(c==1){printf "\n"; c=0}} 1' .annex/real_printf.c > .annex/tmp
			cat .annex/tmp > .annex/real_printf.c
		fi
	awk -v input="$input_pf" -v name="$var_name" '
	/return/ {
	  c++
	    if(c==1) {
		printf "\tprintf(\"%s\", %s);\n", input, name
		c=1
		}
	}
	1 { print }' .annex/real_printf.c > .annex/tmp
	cat .annex/tmp > .annex/real_printf.c
	i=$[$i + 1]
done

sed -i '' 's/%[diouxXfpcs]/&\\n/g' .annex/real_printf.c

while true; do
	read -p "Do you also want to generate random flags?" yn
	case $yn in
	[Yy]* ) sh .annex/modify/change_flags.sh; echo "Your test is now ready"; break;;
	[Nn]* ) exit;;
	* ) echo "Please answer yes or no, no joke this time";;
	esac
done
