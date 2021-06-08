function prime {
	n=$1
	# flag=1
	i=2
	res=$(( $i * $i - $n )) 
	while [ $res -le 0 ]
	do
		if [ `expr $n % $i` -eq 0 ]
		then
			return 0
		fi
		i=$(( $i + 1))
		res=$(( $i * $i - $n ))
	done

	return 1
}

prime $1
n=$?

echo $n
