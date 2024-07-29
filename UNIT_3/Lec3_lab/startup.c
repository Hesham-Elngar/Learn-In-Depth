//startup.c
//Hesham Elngar

#include <stdint.h>

void Reset_Handler();
extern void main();

extern uint32_t _S_DATA;
extern uint32_t _E_DATA;
extern uint32_t _E_TEXT;
extern uint32_t _S_BSS;
extern uint32_t _E_BSS;
extern uint32_t _stack_top;

void Default_Handler()
{
   Reset_Handler();
}

void NMI_Handler() __attribute__ ((weak,alias("Default_Handler")));
void H_Fault_Handler()__attribute__ ((weak,alias("Default_Handler")));
void Bus_Fault()__attribute__ ((weak,alias("Default_Handler")));
void Usage_Fault_Handler()__attribute__ ((weak,alias("Default_Handler")));

uint32_t vectors[] __attribute__((section(".vectors")))= {
(uint32_t) &_stack_top,
(uint32_t) &Reset_Handler,
(uint32_t) &NMI_Handler,
(uint32_t) &H_Fault_Handler,
(uint32_t) &Bus_Fault,
(uint32_t) &Usage_Fault_Handler
};

void Reset_Handler()
{
        uint32_t Data_size = (uint32_t)&_E_DATA - (uint32_t)&_S_DATA;
    uint32_t *Src = (uint32_t *)&_E_TEXT;
    uint32_t *Dst = (uint32_t *)&_S_DATA;
    for (int i = 0; i < Data_size; ++i) {
        *(Dst++) = *(Src++);
    }

    Data_size = (uint32_t) &_E_BSS - (uint32_t) &_S_BSS;
    Dst = (uint32_t *) &_S_BSS;
    for (int i = 0; i < Data_size; ++i) {
        *(Dst++) = 0U;
    }
	main();
}

