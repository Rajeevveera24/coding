module class3(a,b,c,d,f);
	input a,b,c,d;
	output f;
	assign f = (b|d)&(b|~c)&(~a|c|~d)&(a|~c|~d); 
endmodule
