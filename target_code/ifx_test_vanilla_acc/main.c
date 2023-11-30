#include <stdlib.h>
#include <stdio.h>
#include "vanilla_acc.h"
#include "csr.h"

void test_vanilla_acc(void)
{

#if 0
	// clear irq enable for our IRQ, this will suppress the IRQ, even if requested. 
	unsigned int mie = read_csr(mie);
	write_csr(mie, mie & ~(1<<20));
#endif

	float  i0[9] = { 1, 0, 1, 1, 0, 1, 1, 0, 1 };
	float  i1[9] = { 1, 1, 1, 1, 1, 1, 1, 1, 1 };
	float  result[9];
	
	uint32_t status = vanilla_accelerator_conv2dnchw(i0, i1, result, 1, 3, 3, 1, 3, 3);

	if(status == 1)
	{
		printf("HW completed with result: float:");
		for( int i = 0; i < sizeof(result)/sizeof(int32_t); ++i)
		{
			printf("%f ", result[i]);
		}
		printf("\n");
	}
	else 
	{
		printf("Ohhh, HW reported incomplete status of 0x%08x\n", status);
	}
}

int main()
{
	printf("test: ifx_test_vanilla_acc!\n");
	test_vanilla_acc();
	printf("**** completed!!\n");
}

/* IRQ handling section */
#if !defined(VANILLA_IRQ)
#error "halt: IRQ number not defined!"
#endif
const int vanilla_irq = VANILLA_IRQ;

extern void unhandled_interupt_handler_c(unsigned long irq, unsigned long mepc);
void default_interupt_handler_c(unsigned long irq, unsigned long mepc)
{
	if( irq == vanilla_irq)
	{	
		/* clear pending irq */
		unsigned int mip = read_csr(mip);
		write_csr(mip, mip & ~(1<<irq));
		printf("catched IRQ %lu\n", irq);
		ISR_ACC();
	}
	else 
	{
		unhandled_interupt_handler_c(irq, mepc);
	}
}