__kernel void swap1(__global int *A){
	
	int id = get_global_id(0);
	
	id = id * 2;
	
	A[id] += A[id+1] ;
	A[id+1] = A[id] - A[id+1];
	A[id] = A[id] - A[id + 1];
	
}