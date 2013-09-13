#! /bin/bash

#
#Which IP gets the most bytes sent to them.
#

source log_sum_result.sh

function log_sum_t() {

	index=0
	for line in "${linesSorted[@]}" ; do
		numBytes=$(echo $line | grep 'GET\|HEAD\|TRACE\|OPTIONS\|CONNECT' | egrep -o ' [[:digit:]]{3} [[:digit:]]{1,} ')
		numBytes=${numBytes:5:${#numBytes}-1}
	
		if [ ${#numBytes} -gt 0 ] ; then	
			ip=$(echo $line | grep $numBytes | egrep -o '[[:digit:]]{1,3}\.[[:digit:]]{1,3}\.[[:digit:]]{1,3}\.[[:digit:]]{1,3} ')
			result="$ip \t $numBytes"
			results[$index]=$result #"$ip 	$numBytes"
			index=$(expr $index + 1)
		fi
	done

	t_header=("IP Address: \t Number of bytes:")
	t_results=$(for result in "${results[@]}" ; do
		echo -e $result
	done | sort -k2 -n -r | uniq)

	finalResults=("${t_header[@]}" "${t_results[@]}")

	for i in "${finalResults[@]}" ; do
		echo -e "$i"
	done
}
