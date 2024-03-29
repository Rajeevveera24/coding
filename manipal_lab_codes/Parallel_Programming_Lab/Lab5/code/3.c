#include <stdio.h>
#include <CL/cl.h>
#include <stdlib.h>

#define MSS (0x100000)	//max source size...

int main(void){
	int i, LIST_SIZE;

	printf("Enter the number of elements: ");
	scanf("%d", &LIST_SIZE);

	int *A = (int*)malloc(sizeof(int) * LIST_SIZE);

//	printf("Enter the elements of the array: ");

	for(int i=0; i<LIST_SIZE; i++){
		A[i] = i;
	}

//	LIST_SIZE /= 2;

	FILE *fp;
	char *source_str;
	size_t source_size;

	fp = fopen("swap.cl", "r");

	if(!fp){
		fprintf(stderr, "Failed to load kernel\n");
		getchar();
		exit(1);
	}

	source_str = (char*)malloc(MSS);
	source_size = fread(source_str, 1, MSS, fp);

	fclose(fp);

	cl_platform_id platform_id = NULL;
	cl_device_id device_id = NULL;
	cl_uint ret_num_devices;
	cl_uint ret_num_platforms;

	cl_int ret = clGetPlatformIDs(1, &platform_id, &ret_num_platforms);
	ret = clGetDeviceIDs(platform_id, CL_DEVICE_TYPE_GPU, 1, &device_id, &ret_num_devices);

	cl_context context = clCreateContext(NULL, 1, &device_id, NULL, NULL, ret);

	cl_command_queue command_queue = clCreateCommandQueue(context, device_id, NULL, &ret);

	cl_mem a_mem_obj =clCreateBuffer(context, CL_MEM_READ_WRITE, LIST_SIZE * sizeof(int), NULL, &ret);
//	cl_mem b_mem_obj =clCreateBuffer(context, CL_MEM_WRITE_ONLY, LIST_SIZE * sizeof(int), NULL, &ret);
//	cl_mem c_mem_obj =clCreateBuffer(context, CL_MEM_READ_ONLY, LIST_SIZE * sizeof(int), NULL, &ret);

	ret = clEnqueueWriteBuffer(command_queue, a_mem_obj, CL_TRUE, 0, LIST_SIZE * sizeof(int), A, 0, NULL, NULL);
//	ret = clEnqueueWriteBuffer(command_queue, b_mem_obj, CL_TRUE, 0, LIST_SIZE * sizeof(int), B, 0, NULL, NULL);

	cl_program program = clCreateProgramWithSource(context, 1, (const char **)&source_str, (const size_t *)&source_size, &ret);

	ret = clBuildProgram(program, 1, &device_id, NULL, NULL, NULL);

	cl_kernel kernel = clCreateKernel(program, "swap1", &ret);

	ret = clSetKernelArg(kernel, 0, sizeof(cl_mem), (void*)&a_mem_obj);
//	ret = clSetKernelArg(kernel, 1, sizeof(cl_mem), (void*)&b_mem_obj);
//	ret = clSetKernelArg(kernel, 2, sizeof(cl_mem), (void*)&c_mem_obj);

	size_t global_item_size = LIST_SIZE / 2;
	size_t local_item_size = 1;

	cl_event event;
	ret = clEnqueueNDRangeKernel(command_queue, kernel, 1, NULL, &global_item_size, &local_item_size, 0, NULL, NULL);

	ret = clFinish(command_queue);

//	int *B = (int*)malloc(sizeof(int) * LIST_SIZE);

	ret = clEnqueueReadBuffer(command_queue, a_mem_obj, CL_TRUE, 0, LIST_SIZE * sizeof(int), A, 0, NULL, NULL);

	for(i = 0; i < LIST_SIZE * 2; i++){
		printf("%d ", A[i]);
	}

	ret = clFlush(command_queue);
	ret = clReleaseKernel(kernel);
	ret = clReleaseProgram(program);
	ret = clReleaseMemObject(a_mem_obj);
//	ret = clReleaseMemObject(b_mem_obj);
//	ret = clReleaseMemObject(c_mem_obj);
	ret = clReleaseCommandQueue(command_queue);
	ret = clReleaseContext(context);

	free(A);
//	free(B);
//	free(C);

	getchar();
	return 0;

}
