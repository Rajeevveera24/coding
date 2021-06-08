BEGIN{
	count = 0;
}
{
	if($1 == "d"){
		count++;
	}
}	
END{
	printf("%d\n", count);
}