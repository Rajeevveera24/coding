module class2(x,y,z,p,q);
	input x,y,z;
	output p,q;
	assign p = x|(y&z);
	assign q = (x|y)&(x|z);
endmodule 
