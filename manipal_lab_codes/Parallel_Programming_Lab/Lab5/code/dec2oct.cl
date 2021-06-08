__kernel void vector_convert( __global int *A, __global int *B){
	int x = get_global_id(0);
	int i = 0, power;
	int a = A[x], b = 0;
	
	while (a>0){
		power = 1;
		for(int j=0; j<i; j++ ){
			power *= 10;
		}
		b += (a%8)*power;
		a /= 8;
		i++;
	}
	
	B[x] = b;
}
