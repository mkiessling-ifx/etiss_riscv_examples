#include <stdlib.h>
#include <stdio.h>
#include "qvanilla_acc.h"

void test_qvanilla_acc(void)
{
	printf("qvanilla_accelerator test:\n");
	
	int8_t  i0[9] = { 1, 0, 1, 1, 0, 1, 1, 0, 1 };
	int8_t  i1[9] = { 1, 1, 1, 1, 1, 1, 1, 1, 1 };
	int32_t bias_data[9] = { -1, 0, -1, 1, 0, 1, 1, 0, 1 };
	int32_t result[9];
	
	qvanilla_accelerator_conv2dnchw(i0, i1, bias_data, result, 1, 3, 3, 1, 3, 3, 0, 0);
			
	printf("result: 0x");
	for( int i = 0; i < sizeof(result)/sizeof(int32_t); ++i)
	{
		printf("%08x ", result[i]);
	}
	printf("\n");
}


int main()
{
	printf("test: ifx_test_qvanilla_acc!\n");
	test_qvanilla_acc();
	printf("**** completed!!\n");
}
