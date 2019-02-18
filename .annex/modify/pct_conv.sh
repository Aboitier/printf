#!/bin/bash

#
### CLEANING
#
	. .annex/modify/cleaning/clean.sh
#
### SETTING UP
#
	. .annex/modify/prompt/line_nb.sh
	. .annex/modify/prompt/conv_choice.sh
#
### INPUTTING
#

i=0
add_var=""
m_var=""
while [[ "$i" -lt "$line_nb" ]]
do
	j=0
	input_pf=""
	var_name=""
	if ! [[ $1 ]]; then
		pct_nb=$[ ( RANDOM % 4 ) + 1]
	else 
		pct_nb=$1
	fi
	while [ "$j" -lt "$pct_nb" ]
	do
		var_index="$i$j"
		. .annex/modify/random_tools/conv_select.sh "$choice"
		. .annex/modify/random_tools/variables.sh "${conv}"
		if [[ $conv == 's' ]];then
			m_var=`echo $var | cut -c 2- | rev | cut -c 3- | rev`
			input_pf+="$conv $m_var = %$conv"
		else
			input_pf+="\"_BBLUE\"$conv\"_END\" \"_MAGENTA\"$var\"_END\" = %$conv"	
		fi
		. .annex/modify/random_tools/designation.sh "${conv}" "${var_index}"
		add_var=([0]=""${designation[0]}" = "${var[0]}"")
		perl -0777 -pe "s {\)\n\{} {$&\n\t${add_var[0]}}g" .annex/main_test.c > .annex/tmp
		cat .annex/tmp > .annex/main_test.c
		. .annex/modify/random_tools/var_name.sh $conv $var_index
		var_name+="$chosen_name,"
		j=$[$j + 1]
	done
	var_name=`echo $var_name | sed 's/.$//'`
	if [ $i -lt 1 ];then
		awk '/return/{c++;if(c==1){printf "\n"; c=0}} 1' .annex/main_test.c > .annex/tmp
		cat .annex/tmp > .annex/main_test.c
	fi
	awk -v input="$input_pf" -v name="$var_name" '
	/return/ {
	c++
	if(c==1) {
		printf "\tprintf(\"%s\", %s);\n", input, name
		c=1
	}
}
1 { print }' .annex/main_test.c > .annex/tmp
cat .annex/tmp > .annex/main_test.c
i=$[$i + 1]
done

sed -i '' 's/%[diouxXfpcs]/&\\n/g' .annex/main_test.c

	. .annex/modify/prompt/flags_or_not.sh
	. .annex/modify/prompt/colors.sh
rm .annex/tmp

echo "Your test is now ready, gl hf"
