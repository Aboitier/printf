#!/bin/bash

### CLEAN
sed -i '' "/;/d" .annex/real_printf.c
perl -0777 -pe 's {\{} {$&\n\treturn (0);}g' .annex/real_printf.c > .annex/tmp
cat .annex/tmp > .annex/real_printf.c

### INPUT
i=0
add_var=""
line_nb=$[ ( RANDOM % 4 ) + 1 ]
while [[ "$i" -lt "$1" ]]
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
	awk -v input="$input_pf" -v name="$var_name" '
	/return/ {
	  c++
	    if(c==1) {
		printf "\t\tprintf(\"%s\", %s);\n", input, name
		c=1
		}
	}
	1 { print }' .annex/real_printf.c > .annex/tmp
	cat .annex/tmp > .annex/real_printf.c
	i=$[$i + 1]
done
