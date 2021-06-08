echo "Enter a and b"

read a
read b

stop=0

while test $stop -eq 0

do
	cat<<ENDOFMENU
	+:add
	-:subtract
	/:divide
	*:multiply
	e:exit
	ENDOFMENU

	echo "Choice"

	read operation

	case $operation in
		"+")
			res = `expr $a + $b`
			echo $res
			;;
		"-")
			res = `expr $a - $b`
			echo $res
			;;
		"*")
			res = `expr $a \* $b`
			echo $res
			;;
		"/")
			res = `expr $a \/ $b`
			echo $res
			;;
		"e")
			stop = 1
			;;
	esac
done
