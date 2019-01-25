#!/bin/sh


#awk '{for(i=1;i<=NF;i++) {if ($i == "%") beginning=i;if($i == /[^\x00-\x47 ] || $i ==[\x61-\x67] || $i ==[\x6d-\x6e ] || $i == [ \x70-\x73 ]) ending=i }; for (j=beginning;j<=ending;j++) printf $j" ";printf "\n" }' .annex/real_printf.c

awk '{gsub(/%[^A-Ga-gm-np-s]+/, "%")} 1' .annex/real_printf.c > .annex/modify/tmp
cat .annex/modify/tmp > .annex/real_printf.c
#awk '/%/{flag=1;next}/[A-G],[a-g],[m-n], [p-s]/{flag=0}flag' .annex/real_printf.c

perl -pe 's{%}{++$n == 2 ? "%'$1'" : $&}ge' .annex/real_printf.c > .annex/modify/tmp
cat .annex/modify/tmp > .annex/real_printf.c
