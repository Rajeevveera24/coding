
i=0
m=1


until [ $i -ge $1 ]

do
	if [ `expr $i % 2` -eq 1 ]
	then
		echo $i
		i=$(( ($i) + 1))
	fi
done
