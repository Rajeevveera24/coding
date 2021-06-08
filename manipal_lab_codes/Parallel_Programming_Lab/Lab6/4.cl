  __kernel void reverse (__global char *S, int len, __global int *indices) {
	int id = get_global_id(0);
	int start = indices[id] + 1;
	int end = indices[id + 1];
	for (int i=start;i<(end + start)/2;i++) {
		char t = S[end + start - 1 - i];
		S[end + start - 1 - i] = S[i];
		S[i] = t;
	}
}