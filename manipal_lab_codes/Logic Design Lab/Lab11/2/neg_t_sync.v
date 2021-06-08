module neg_t_sync(T,Clock,Resetn,Q);
	input T,Clock,Resetn;
	output Q;
	reg Q;
	always@(negedge Clock)
	if(!Resetn)
		Q<=0;
	else
		Q<= Q ^ T;
endmodule
