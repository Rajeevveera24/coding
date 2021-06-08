module pos_JK_sync(J,K,Clock,Resetn,Q);
	input J,K,Clock,Resetn;
	output Q;
	reg Q;
	always@(posedge Clock)
	if(!Resetn)
		Q<=0;
	else
		Q<= ~Q&J | ~K&Q;
endmodule
