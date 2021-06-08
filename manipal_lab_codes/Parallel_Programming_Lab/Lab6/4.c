#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <CL/cl.h>
#define MAX_SOURCE_SIZE (0x100000)

int main ()
{		
	int i;
	char *input = "EHT ERIPME DID GNIHTON GNORW";
	int len = strlen(input);
	char *output = (char *)malloc(len*sizeof(char));
	
	int spaces = 0;
	for (i=0;i<len;i++)
		if(input[i]==' ')
			spaces += 1;
	spaces += 1;
	
	int *indices = (int *)calloc(spaces + 1,sizeof(int));
	int k = 0;
	indices[k++] = -1;
	for (i = 0; i < len; ++i) {
		if (input[i] == ' ') {
			indices[k++] = i;
		}
	}
	indices[k++] = len;

	FILE *fp = fopen("reverse_each_word.cl", "r");
	if (fp == NULL)
	{
		printf("Kernel loading failed.");
		exit(1);
	}
	
	char *source_str = (char *)malloc(MAX_SOURCE_SIZE);
	size_t source_size = fread(source_str,1,MAX_SOURCE_SIZE,fp);
	fclose(fp);
	
	cl_int status;
	cl_platform_id platform;			
	cl_device_id device;	
	
	status = clGetPlatformIDs(1,&platform,NULL);
	status = clGetDeviceIDs(platform,CL_DEVICE_TYPE_GPU,1,&device,NULL);


	cl_context context = clCreateContext(NULL,1,&device,NULL,NULL,&status);
	
	cl_command_queue command = clCreateCommandQueue(context,device,0,&status);
	
	cl_mem mem_input = clCreateBuffer(context,CL_MEM_READ_WRITE,sizeof(char)*len,NULL,NULL);
	cl_mem mem_indices = clCreateBuffer(context,CL_MEM_READ_ONLY,sizeof(int)*(spaces + 1),NULL,NULL);
	
	status = clEnqueueWriteBuffer(command,mem_input,CL_TRUE,0,sizeof(char)*len,input,0,NULL,NULL);
	status = clEnqueueWriteBuffer(command,mem_indices,CL_TRUE,0,sizeof(int)*(spaces + 1),indices,0,NULL,NULL);

	cl_program program = clCreateProgramWithSource(context,1,(const char **)&source_str,NULL,&status);
	
	status = clBuildProgram(program,0,NULL,NULL,NULL,NULL);
	
	cl_kernel kernel = clCreateKernel(program,"reverse",&status);
	
	status = clSetKernelArg(kernel,0,sizeof(cl_mem),&mem_input);
	status = clSetKernelArg(kernel,1,sizeof(cl_int),&len);
	status = clSetKernelArg(kernel,2,sizeof(cl_mem),&mem_indices);
	
	size_t global = spaces;
	size_t local = 1;
	
	status = clEnqueueNDRangeKernel(command,kernel,1,NULL,&global,&local,0,NULL,NULL);

 	status = clFinish(command);

	status = clEnqueueReadBuffer(command,mem_input,CL_TRUE,0,sizeof(char)*len,output,0,NULL,NULL);

	printf("Original : %s\nModified : %s\n",input,output);
	
	status = clFlush(command)
	status = clReleaseMemObject(mem_input);
	status = clReleaseProgram(program);
	status = clReleaseKernel(kernel);
	status = clReleaseCommandQueue(command);
	status = clReleaseContext(context);

	return 0;
}