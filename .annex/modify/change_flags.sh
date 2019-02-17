#!/bin/sh

##														    	##
 #### REMOVE WHAT'S BETWEEN % AND THE CONVERSION INDICATOR	#####
##																##

awk '{gsub(/%[^A-Ga-gm-no-sixXu]+/, "%")} 1' .annex/main_test.c > .annex/modify/tmp
cat .annex/modify/tmp > .annex/main_test.c

##																##
 #### 	INPUT RANDOM FLAG AFTER THE NTH OCCURRENCE OF % 	#####
##																##

i=1
nb_pcent=`grep -o "%" .annex/main_test.c | wc -l`							## nb de % dans le file
a_pct=`grep -o -m$i -E "%.{0,1}" .annex/main_test.c` 					## 
a_pct_c=`grep -o -m$i -E "%.{0,1}" .annex/main_test.c | cut -c2 | wc -l` ## nb de conv par ligne par match $i + matchs anterieurs
diff=0
diffi=1

while [ $diffi -lt $nb_pcent ] 
do
	flag=""
	diffi=$[$i + $diff]
	a_pct_c=`grep -o -m$i -E "%.{0,1}" .annex/main_test.c | cut -c2 | wc -l`
	if [ "$a_pct_c" -gt "$diffi" ];then
		j=$[$i+$diff]
		while [ "$j" -le "$a_pct_c" ]
		do
			flag=""
			curr_conv=`grep -oa -m$i -E "%.{0,1}" .annex/main_test.c | cut -c2 | sed -n ''$j'p'`
			if [[ $curr_conv = [diouxXf] ]];then
				. .annex/modify/random_tools/flag_options.sh
				. .annex/modify/random_tools/width.sh $flag
				. .annex/modify/random_tools/precision.sh $flag
			fi	
			if [[ $curr_conv = [diouxX] ]];then
				. .annex/modify/random_tools/flag_dioux.sh $flag
			elif [[ $curr_conv = 'f' ]];then
				. .annex/modify/random_tools/flag_f.sh $flag
			elif [[ $curr_conv = [scp] ]]; then
				flag=""
			fi
			perl -pe 's{[;]"_END" [=] %}{++$n == '$j' ? "\"_END\" >\"_RED\"'$flag'\"_END\"<; = %'$flag'" : $&}ge' .annex/main_test.c > .annex/modify/tmp
			cat .annex/modify/tmp > .annex/main_test.c
			diff=$[$diff + 1]
			j=$[$j + 1]
		done
	else
		diffi=$[$i+$diff]
		i=$[$i + 1]
		curr_conv=`grep -oa -m$i -E "%.{0,1}" .annex/main_test.c | cut -c2 | sed -n ''$diffi'p'`
			if [[ $curr_conv = [diouxXf] ]];then
				. .annex/modify/random_tools/flag_options.sh
				. .annex/modify/random_tools/width.sh $flag
				. .annex/modify/random_tools/precision.sh $flag
			fi	
			if [[ $curr_conv = [diouxX] ]];then
				. .annex/modify/random_tools/flag_dioux.sh $flag
			elif [[ $curr_conv = 'f' ]];then
				. .annex/modify/random_tools/flag_f.sh $flag
			elif [[ $curr_conv = [scp] ]];then
				flag=""
			fi
			perl -pe 's{[;]"_END" [=] %}{++$n == '$diffi' ? "\"_END\" >\"_CYAN\"'$flag'\"_END\"<; = %'$flag'" : $&}ge' .annex/main_test.c > .annex/modify/tmp
			cat .annex/modify/tmp > .annex/main_test.c
	fi
done
