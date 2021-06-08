n=2
c=0
while [ $c -lt $1 ]
do
	flag=1
	i=2
	res=$(( n - $i*$i ))
	while [ $res -ge 0 ]
	do
		if [ `expr $n % $i` -eq 0 ]
		then
			flag=0
			break
		fi
		i=$(($i + 1))
		res=$((n - $i * $i))
	done
	if [ $flag -eq 1 ]
	then	
		echo $n
		c=$(($c + 1))
	fi
	n=$(($n +1))
done
exit 0
