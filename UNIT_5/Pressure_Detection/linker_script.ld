/* linker_script.ld
   eng hesham elngar
*/

MEMORY
{
    flash (rx)   : ORIGIN = 0x08000000, LENGTH = 128K
    sram  (rwx) : ORIGIN = 0x20000000, LENGTH = 20K
}

SECTIONS
{
    .text :
    {
        *(.vectors)    /* Ensure the interrupt vector table is kept */
        *(.text*)
        *(.rodata*)
        _E_TEXT = .;    /* Define end of .text section */
    } > flash

    .data : AT(_E_TEXT)
    {
        _S_DATA = .;    /* Define start of .data section */
        *(.data*)
        . = ALIGN(4);
        _E_DATA = .;    /* Define end of .data section */
    } > sram 

    .bss :
    {
        _S_BSS = .;    /* Define start of .bss section */
        *(.bss*)
        *(COMMON)
        _E_BSS = .;    /* Define end of .bss section */
        . = ALIGN(4);
    } > sram

    /* Define stack space */
    .stack (NOLOAD) :
    {
        . = ALIGN(4);
        _stack_top = .;  /* Define start of stack */
        . += 0x1000;     /* 4KB stack size, adjust as needed */
        _stack_end = .;  /* Define end of stack */
    } > sram
}
