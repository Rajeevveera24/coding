__kernel void odd( __global int *A){
	
	int id = get_global_id(0);
	int n = get_global_size(0);
	
	if( id%2 != 0 && id != n-1){
		if( A[id] > A[id + 1]){
			A[id] += A[id+1];
			A[id+1] = A[id] - A[id + 1];
			A[id] -= A[id+1];
		}
	}
}		

__kernel void even( __global int *A){
	
	int id = get_global_id(0);
	int n = get_global_size(0);
	
	if( id%2 == 0 && id != n-1){
		if( A[id] > A[id + 1]){
			A[id] += A[id+1];
			A[id+1] = A[id] - A[id + 1];
			A[id] -= A[id+1];
		}
	}
}		