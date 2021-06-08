__kernel void stringCopy( __global char *A, __global char *res, __global int *len){
	int id = get_global_id(0);
	id = id * (*len);
	for(int i = 0; i < *len; i++){
		res[id + i] = A[i];
	}
}
