#!/bin/sh

### REMOVE WHAT'S BETWEEN % AND THE CONVERSION INDICATOR ###
awk '{gsub(/%[^A-Ga-gm-no-si-ix-xX-X]+/, "%")} 1' .annex/real_printf.c > .annex/modify/tmp
cat .annex/modify/tmp > .annex/real_printf.c

### INPUT $1 AFTER THE NTH OCCURRENCE OF % ###
i=1
nb_pcent=`grep -o "%" .annex/real_printf.c | wc -l`							## nb de % dans le file
a_pct=`grep -o -m$i -E "%.{0,1}" .annex/real_printf.c` 					## 
a_pct_c=`grep -o -m$i -E "%.{0,1}" .annex/real_printf.c | cut -c2 | wc -l` ## nb de conv par ligne par match $i + matchs anterieurs
diff=0
diffi=1

while [ $diffi -lt $nb_pcent ] 
do
	diffi=$[$i + $diff]
	a_pct_c=`grep -o -m$i -E "%.{0,1}" .annex/real_printf.c | cut -c2 | wc -l`
	if [ "$a_pct_c" -gt "$diffi" ];then
		j=$[$i+$diff]
		while [ "$j" -le "$a_pct_c" ]
		do
			curr_conv=`grep -oa -m$i -E "%.{0,1}" .annex/real_printf.c | cut -c2 | sed -n ''$j'p'`
			if [[ $curr_conv = "d" || $curr_conv = "i" || $curr_conv = "o" || $curr_conv = "u" || $curr_conv = "x" || $curr_conv = "X" ]];then
				. .annex/modify/random_tools/flag_select.sh 5
				. .annex/modify/random_tools/flag_dioux.sh $flag_select
			elif [ $curr_conv = "f" ];then
				. .annex/modify/random_tools/flag_select.sh 3
				. .annex/modify/random_tools/flag_f.sh $flag_select
			elif [[ $curr_conv = "s" || $curr_conv = "c" || $curr_conv = "p" ]]; then
				flag=""
			fi
			if [[ $curr_conv = "d" || $curr_conv = "i" || $curr_conv = "o" || $curr_conv = "u" || $curr_conv = "x" || $curr_conv = "X" || $curr_conv = "f" ]];then
				. .annex/modify/random_tools/flag_select.sh 6 
				. .annex/modify/random_tools/flag_options.sh $flag_select $flag
			fi	
			perl -pe 's{%}{++$n == '$j' ? "%'$flag'" : $&}ge' .annex/real_printf.c > .annex/modify/tmp
			cat .annex/modify/tmp > .annex/real_printf.c
			diff=$[$diff + 1]
			j=$[$j + 1]
		done
	else
		diffi=$[$i+$diff]
		i=$[$i + 1]
		curr_conv=`grep -oa -m$i -E "%.{0,1}" .annex/real_printf.c | cut -c2 | sed -n ''$diffi'p'`
			if [[ $curr_conv = "d" || $curr_conv = "i" || $curr_conv = "o" || $curr_conv = "u" || $curr_conv = "x" || $curr_conv = "X" ]];then
				. .annex/modify/random_tools/flag_select.sh 5
				. .annex/modify/random_tools/flag_dioux.sh $flag_select
			elif [ $curr_conv = "f" ];then
				. .annex/modify/random_tools/flag_select.sh 3
				. .annex/modify/random_tools/flag_f.sh $flag_select
			elif [[ $curr_conv = "s" || $curr_conv = "c" || $curr_conv = "p" ]];then
				flag=""
			fi
			if [[ $curr_conv = "d" || $curr_conv = "i" || $curr_conv = "o" || $curr_conv = "u" || $curr_conv = "x" || $curr_conv = "X" || $curr_conv = "f" ]];then
				. .annex/modify/random_tools/flag_select.sh 6 
				. .annex/modify/random_tools/flag_options.sh $flag_select $flag
			fi	
			perl -pe 's{%}{++$n == '$diffi' ? "%'$flag'" : $&}ge' .annex/real_printf.c > .annex/modify/tmp
			cat .annex/modify/tmp > .annex/real_printf.c
	fi
done
	
#perl -pe 's{%}{++$n == 2 ? "%'$1'" : $&}ge' .annex/real_printf.c > .annex/modify/tmp
#cat .annex/modify/tmp > .annex/real_printf.c
#perl OK
#grep OK

