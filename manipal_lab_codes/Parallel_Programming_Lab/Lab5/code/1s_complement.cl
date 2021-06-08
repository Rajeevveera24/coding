__kernel void vector_convert( __global int *A, __global int *B){
	int x = get_global_id(0);
	int a = A[x], count = 0;
	int b = a;
	while(a>0){
		count++;
		a/=10;
	}
	a = b;
	int a1[100], b1[100];
	for(int i=0; i<count; i++){
		a1[i] = a % 10;
		a /= 10;
		b1[i] = a1[i] ^ 1;
	}
	b = 0;
	for(int i=count-1; i>=0; i--){
		b = b*10 + b1[i];
	}
	
	B[x] = b;
}
