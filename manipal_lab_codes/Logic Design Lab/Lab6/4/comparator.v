module comparator(a,b,aeqb,agtb,alsb);
	input [3:0]a,b;
	output aeqb,agtb,alsb;
	xor(I3,a[3],b[3]);
	not(i3,I3);
	xor(I2,a[2],b[2]);
	not(i2,I2);
	xor(I1,a[1],b[1]);
	not(i1,I1);
	xor(I0,a[0],b[0]);
	not(i0,I0);
	and(aeqb,i3,i2,i1,i0);
	assign agtb = (a[3]&~b[3])|(i3&a[2]&~b[2])|(i3&i2&a[1]&~b[1])|(i3&i2&i1&a[0]&~b[0]);
	assign alsb = ~agtb | ~aeqb;
endmodule
