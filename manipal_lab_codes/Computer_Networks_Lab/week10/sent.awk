BEGIN {
	count = 0;
}
{
	if($1 == "+" && $3 == "0"){
		count++;
	}
}
END{
	printf("%d\n", count);	
}