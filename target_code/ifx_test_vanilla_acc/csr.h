#ifndef __CSR_H__
#define __CSR_H__

#define read_csr(reg)                                 \
    ({                                                \
        unsigned long __tmp;                          \
        asm volatile("csrr %0, " #reg : "=r"(__tmp)); \
        __tmp;                                        \
    })

#define write_csr(csr, value)  asm volatile ("csrw\t\t" #csr ", %0" : /* no output */ : "r" (value))

#endif