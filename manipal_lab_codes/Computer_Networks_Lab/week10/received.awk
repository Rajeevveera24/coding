BEGIN {
	count = 0;
}
{
	if($1 == "r" && $4 == "2"){
		count++;
	}
}
END{
	printf("%d\n", count);	
}