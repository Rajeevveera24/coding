#include <stdio.h>
#include <CL/cl.h>
#include <stdlib.h>
#include <string.h>

#define MSS (0x100000)	//max source size...

int main(void){

	int n;

	printf("Enter the number of devices: ");
	scanf("%d", &n);

	char *A = (char*)malloc(sizeof(char) * 100);

	printf("Enter the string\n");
	scanf("%s", A);

	int *len = (int*)malloc(sizeof(int));
	*len = strlen(A);

	int len1 = *len;

//	printf("%d\n", *len);

	FILE *fp;
	char *source_str;
	size_t source_size;

	fp = fopen("1.cl", "r");

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

	cl_mem a_mem_obj = clCreateBuffer(context, CL_MEM_READ_ONLY, len1 * sizeof(char), NULL, &ret);
	cl_mem res_mem_obj = clCreateBuffer(context, CL_MEM_WRITE_ONLY, len1 * n * sizeof(char), NULL, &ret);
//	cl_mem c_mem_obj =clCreateBuffer(context, CL_MEM_READ_ONLY, LIST_SIZE * sizeof(int), NULL, &ret);
	cl_mem len_mem_obj = clCreateBuffer(context, CL_MEM_READ_ONLY, sizeof(int), NULL, &ret);

	ret = clEnqueueWriteBuffer(command_queue, a_mem_obj, CL_TRUE, 0, len1 * sizeof(char), A, 0, NULL, NULL);
//	ret = clEnqueueWriteBuffer(command_queue, b_mem_obj, CL_TRUE, 0, LIST_SIZE * sizeof(int), B, 0, NULL, NULL);
	ret = clEnqueueWriteBuffer(command_queue, len_mem_obj, CL_TRUE, 0, sizeof(int), len, 0, NULL, NULL);

	cl_program program = clCreateProgramWithSource(context, 1, (const char **)&source_str, (const size_t *)&source_size, &ret);

	ret = clBuildProgram(program, 1, &device_id, NULL, NULL, NULL);

	cl_kernel kernel = clCreateKernel(program, "stringCopy", &ret);

	ret = clSetKernelArg(kernel, 0, sizeof(cl_mem), (void*)&a_mem_obj);
	ret = clSetKernelArg(kernel, 1, sizeof(cl_mem), (void*)&res_mem_obj);
	ret = clSetKernelArg(kernel, 2, sizeof(cl_mem), (void*)&len_mem_obj);
//	ret = clSetKernelArg(kernel, 2, sizeof(cl_mem), (void*)&c_mem_obj);

	size_t global_item_size = n;
	size_t local_item_size = 1;

	cl_event event;

	ret = clEnqueueNDRangeKernel(command_queue, kernel, 1, NULL, &global_item_size, &local_item_size, 0, NULL, NULL);

	ret = clFinish(command_queue);

	char *res = (char*)malloc(sizeof(char) * len1 * n);

	ret = clEnqueueReadBuffer(command_queue, res_mem_obj, CL_TRUE, 0, len1 * n * sizeof(char), res, 0, NULL, NULL);


	printf("%s", res);

	ret = clFlush(command_queue);
	ret = clReleaseKernel(kernel);
	ret = clReleaseProgram(program);
	ret = clReleaseMemObject(a_mem_obj);
	ret = clReleaseMemObject(res_mem_obj);
	ret = clReleaseMemObject(len_mem_obj);
//	ret = clReleaseMemObject(c_mem_obj);
	ret = clReleaseCommandQueue(command_queue);
	ret = clReleaseContext(context);

	free(A);
	free(res);
//	free(C);

	getchar();
	return 0;

}
