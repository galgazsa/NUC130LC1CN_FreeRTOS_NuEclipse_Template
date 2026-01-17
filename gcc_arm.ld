/* Nuvoton NUC100Series GCC linker script */
/* Compatible with startup_NUC100Series.S */

ENTRY(Reset_Handler)

/* Memory definition */
MEMORY
{
    FLASH (rx)  : ORIGIN = 0x00000000, LENGTH = 128K
    RAM   (rwx) : ORIGIN = 0x20000000, LENGTH = 16K
}

/* Stack top */
__StackTop = ORIGIN(RAM) + LENGTH(RAM);
PROVIDE(__stack = __StackTop);

SECTIONS
{
    /* Vector table + code */
    .text :
    {
        KEEP(*(.isr_vector))
        *(.text*)
        *(.rodata*)
        KEEP(*(.init))
        KEEP(*(.fini))
    } > FLASH

    /* ARM exception tables (must be before data AT) */
    .ARM.extab :
    {
        *(.ARM.extab* .gnu.linkonce.armextab.*)
    } > FLASH

    .ARM.exidx :
    {
        __exidx_start = .;
        *(.ARM.exidx* .gnu.linkonce.armexidx.*)
        __exidx_end = .;
    } > FLASH

    /* End of text section (used by startup) */
    __etext = .;

    /* Initialized data */
    .data : AT (__etext)
    {
        __data_start__ = .;
        *(.data*)
        __data_end__ = .;
    } > RAM

    /* Zero-initialized data */
    .bss :
    {
        __bss_start__ = .;
        *(.bss*)
        *(COMMON)
        __bss_end__ = .;
    } > RAM

    /* Heap start */
    __end__ = .;
    PROVIDE(end = .);
}
