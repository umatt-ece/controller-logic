/*
 * GNU GCC linker script extension for standard Tricore Projects
 *
 * Christoph Baldauf, STW                         20.03.2013
 *
 * This file defines the standard linker script definitions and sections,
 * which must be defined before any project specific sections.
 *
 */


OUTPUT_FORMAT("elf32-tricore")
OUTPUT_ARCH(tricore)
ENTRY(_start)


/*
 * memory statistics, only for information (see also statistic section)
 */
MEM_INT_ROM1_START = ORIGIN(int_rom1);
MEM_INT_ROM1_END   = ORIGIN(int_rom1) + LENGTH(int_rom1);
MEM_INT_ROM1_SIZE  = LENGTH(int_rom1);
MEM_INT_ROM1_USED  = MEM_INT_ROM1_USED_END - MEM_INT_ROM1_START;

MEM_INT_ROM2_START = ORIGIN(int_rom2);
MEM_INT_ROM2_END   = ORIGIN(int_rom2) + LENGTH(int_rom2);
MEM_INT_ROM2_SIZE  = LENGTH(int_rom2);
MEM_INT_ROM2_USED  = MEM_INT_ROM2_USED_END - MEM_INT_ROM2_START;

MEM_EXT_ROM_START = ORIGIN(ext_rom);
MEM_EXT_ROM_END   = ORIGIN(ext_rom) + LENGTH(ext_rom);
MEM_EXT_ROM_SIZE  = LENGTH(ext_rom);
MEM_EXT_ROM_USED  = MEM_EXT_ROM_USED_END - MEM_EXT_ROM_START;

MEM_EXT_RES_START = ORIGIN(ext_res);
MEM_EXT_RES_END   = ORIGIN(ext_res) + LENGTH(ext_res);
MEM_EXT_RES_SIZE  = LENGTH(ext_res);

MEM_EXT_RAM_START = ORIGIN(ext_ram);
MEM_EXT_RAM_END   = ORIGIN(ext_ram) + LENGTH(ext_ram);
MEM_EXT_RAM_SIZE  = LENGTH(ext_ram);
MEM_EXT_RAM_USED  = MEM_EXT_RAM_USED_END - MEM_EXT_RAM_START;

MEM_EXT_PRAM_START = ORIGIN(ext_pram);
MEM_EXT_PRAM_END   = ORIGIN(ext_pram) + LENGTH(ext_pram);
MEM_EXT_PRAM_SIZE  = LENGTH(ext_pram);
MEM_EXT_PRAM_USED  = MEM_EXT_PRAM_USED_END - MEM_EXT_PRAM_START;

MEM_INT_SRAM_START = ORIGIN(int_sram);
MEM_INT_SRAM_END   = ORIGIN(int_sram) + LENGTH(int_sram);
MEM_INT_SRAM_SIZE  = LENGTH(int_sram);
MEM_INT_SRAM_USED  = MEM_INT_SRAM_USED_END - MEM_INT_SRAM_START;

MEM_INT_DSPR_START = ORIGIN(int_dspr);
MEM_INT_DSPR_END   = ORIGIN(int_dspr) + LENGTH(int_dspr);
MEM_INT_DSPR_SIZE  = LENGTH(int_dspr);
MEM_INT_DSPR_USED  = MEM_INT_DSPR_USED_END - MEM_INT_DSPR_START;

MEM_INT_PSPR_START = ORIGIN(int_pspr);
MEM_INT_PSPR_END   = ORIGIN(int_pspr) + LENGTH(int_pspr);
MEM_INT_PSPR_SIZE  = LENGTH(int_pspr);
MEM_INT_PSPR_USED  = MEM_INT_PSPR_USED_END - MEM_INT_PSPR_START;

MEM_PCP_DATA_START = ORIGIN(pcp_data);
MEM_PCP_DATA_END   = ORIGIN(pcp_data) + LENGTH(pcp_data);
MEM_PCP_DATA_SIZE  = LENGTH(pcp_data);
MEM_PCP_DATA_USED  = MEM_PCP_DATA_USED_END - MEM_PCP_DATA_START;

MEM_PCP_TEXT_START = ORIGIN(pcp_text);
MEM_PCP_TEXT_END   = ORIGIN(pcp_text) + LENGTH(pcp_text);
MEM_PCP_TEXT_SIZE  = LENGTH(pcp_text);
MEM_PCP_TEXT_USED  = MEM_PCP_TEXT_USED_END - MEM_PCP_TEXT_START;


/* statistic data of stack and CSA area */
__ISTACK_BEGIN = __ISTACK_START;                               /* interrupt stack begin         */
__ISTACK_END = __ISTACK;                                       /* interrupt stack end address   */
__USTACK_BEGIN = __ISTACK;                                     /* user stack begin              */
__USTACK_END = __USTACK;                                       /* user stack start end address  */
__CSA_END = ORIGIN(MEM_CSA_RAM) + LENGTH(MEM_CSA_RAM);         /* end of CSA area               */
__CSA_SIZE = __CSA_END - __CSA_BEGIN;                          /* define CSA size               */


STW_BIOS_TEXT_USED       = SEC_STW_BIOS_TEXT_END - SEC_STW_BIOS_TEXT_START;
STW_BIOS_RODATA_USED     = SEC_STW_BIOS_RODATA_END - SEC_STW_BIOS_RODATA_START;
STW_BIOS_CODERAM_L1_USED = SEC_STW_BIOS_CODERAM_L1_END - SEC_STW_BIOS_CODERAM_L1_START;
STW_BIOS_CODERAM_L2_USED = SEC_STW_BIOS_CODERAM_L2_END - SEC_STW_BIOS_CODERAM_L2_START;
STW_BIOS_CODERAM_L3_USED = SEC_STW_BIOS_CODERAM_L3_END - SEC_STW_BIOS_CODERAM_L3_START;
STW_BIOS_DATARAM_L1_USED = SEC_STW_BIOS_DATARAM_L1_END - SEC_STW_BIOS_DATARAM_L1_START;
STW_BIOS_DATARAM_L2_USED = SEC_STW_BIOS_DATARAM_L2_END - SEC_STW_BIOS_DATARAM_L2_START;
STW_BIOS_DATARAM_L3_USED = SEC_STW_BIOS_DATARAM_L3_END - SEC_STW_BIOS_DATARAM_L3_START;

STW_BIOS_EXT_RAM_USED    = (SEC_STW_BIOS_DATARAM_L3_END - SEC_STW_BIOS_DATARAM_L3_START) +
                           (SEC_STW_BIOS_BSS_END        - SEC_STW_BIOS_BSS_START       ) +
                           (SEC_STW_BIOS_NOINIT_END     - SEC_STW_BIOS_NOINIT_START    );



/*
 * The heap is the memory between __HEAP and __HEAP_END
 * programs can dynamically allocate space in this area using malloc()
 * and various other functions.
 * Below you can define the minimum amount of memory that the heap
 * should provide.
 */
__HEAP_MIN = DEFINED (__HEAP_MIN) ? __HEAP_MIN : 512K;
__HEAP_SRAM_MIN = DEFINED (__HEAP_SRAM_MIN) ? __HEAP_SRAM_MIN : 16K;
__HEAP_STW_BIOS_MIN = DEFINED (__HEAP_STW_BIOS_MIN) ? __HEAP_STW_BIOS_MIN : 0;
__HEAP_PROTECTED_MIN = DEFINED (__HEAP_PROTECTED_MIN) ? __HEAP_PROTECTED_MIN : 0;
__HEAP_DSPR_MIN = DEFINED (__HEAP_DSPR_MIN) ? __HEAP_DSPR_MIN : 0;

/* check user / interrupt stack address and size */
_. = ASSERT ((__ISTACK & 7) == 0 , "ISTACK not doubleword aligned");
_. = ASSERT ((__USTACK & 7) == 0 , "USTACK not doubleword aligned");

/* Make sure CSA, stack and heap addresses are properly aligned.  */
_. = ASSERT ((__CSA_BEGIN & 0x3f) == 0 , "illegal CSA start address");
_. = ASSERT ((__CSA_SIZE & 0x3f) == 0 , "illegal CSA size");
_. = ASSERT (__CSA_SIZE >= __CSA_MIN , "not enough memory for CSA");
_. = ASSERT ((__CSA_SIZE >> 6) > __LCX_HEADROOM , "LCX does not fit in CSA area");
_. = ASSERT (__LCX_HEADROOM >= 6 , "__LCX_HEADROOM should be >= 6");


/* Define a default symbol for address 0.  */
NULL = DEFINED (NULL) ? NULL : 0;

/* force linking of library version information */
/* even if not referenced by the application    */
EXTERN(gt_x_lib_version);


/*
   Emit special address boundaries for MPU usage
*/
MPU_EXPORT_DATA_MIN_ADDR = 0x80000000;                         /* first data address is cached read only data from internal flash */
MPU_EXPORT_DATA_MAX_ADDR = 0xE0000000;                         /* mpu can check addresses up to 0xE0000000 where the periphery address space starts*/
MPU_EXPORT_CODE_MIN_ADDR = MEM_INT_ROM1_START;                 /* code can be executed from the internal flash... */
MPU_EXPORT_CODE_MAX_ADDR = MEM_INT_PSPR_END;                   /* up to the scratchpad ram area                   */
MPU_EXPORT_SRAM_START    = MEM_INT_SRAM_START;
MPU_EXPORT_SRAM_END      = MEM_INT_SRAM_END;
MPU_EXPORT_EXT_RAM_START = MEM_EXT_RAM_START;
MPU_EXPORT_EXT_PRAM_START = MEM_EXT_PRAM_START;
MPU_EXPORT_EXT_RAM_END   = MEM_EXT_PRAM_END;

/*
 *   Now we start with the definition of the output sections.
 *   At first all sections must be located, that have a special
 *   address constraint (i.e. should be loaded to fixed addresses).
 */

SECTIONS
{
   /*
    *   We start with the boot code that must be the first address of
    *   application rom. It is expected that the first address of the
    *   boot rom will be execued due to a cpu reset or a jump from
    *   another application.
    */

   .boot ORIGIN(MEM_APPLICATION_ROM) :
   {
      KEEP(*(.boot_code))
   } > MEM_APPLICATION_ROM = 0

   /*
    * This magic key signals a valid application to the flash loader
    */
   .validprogramkey (ORIGIN(MEM_APPLICATION_ROM) + 0x18) :
   {
      LONG(0x900dc0de);
   } > MEM_APPLICATION_ROM = 0

   /*
    * allocate the ECU (mainboard) library information data at address offset 0x20
    */
   .libversion (ORIGIN(MEM_APPLICATION_ROM) + 0x20) :
   {
      KEEP(*(.libversion))
   } > MEM_APPLICATION_ROM = 0

   /*
    * If signature block <= V3 is available: allocate it at address offset 0x80
    */
   .block_signature (ORIGIN(MEM_APPLICATION_ROM) + 0x80) :
   {
      KEEP(*(.block_signature))
   } > MEM_APPLICATION_ROM = 0

   /*
    * external libraries are arbitrary in number and must be placed somewhere after
    * "fixed memory sections". We place the start address of the .extlibinfo section
    * here so that it can be easily obtained.
    */
   .extlibinfo_start (ORIGIN(MEM_APPLICATION_ROM) + 0xFC) :
   {
      LONG(__EXTLIBINFO_OFFSET);
   } > MEM_APPLICATION_ROM = 0

   /*
    * allocate the default trap vector table code at address offset 0x100 (load address)
    * the run time location is the scratchpad ram memory (int_tvram)
    * the code is loaded by the startup code (see also __copy_table)
    */
   .tvect :
   {
      KEEP(*(.traptab))
   } > int_tvram AT> MEM_APPLICATION_ROM

   /*
    * export the trap vector table load address for tc core library
    */
   gu32_default_trap_vect = LOADADDR(.tvect);

   /*
    * If signature block V4 is available: allocate it at address offset 0x200,
    * the application info must follow directly
    * Important:
    * - The ALIGN statement is needed to guarantee the alignment of the following .fingerprint resp.
    *   application_info section if no signature block V4 is available
    * - The ALIGN statement can't be placed in the next output section, because then the application info
    *   might not be linked directly after the signatrue block V4
    * - The input section .block_signature_v4 can't be placed into the same output section as the aplication,
    *   info, as it is filled later by a separate linker script. Using the same output section would change
    *   the order of the sections.
    */
   .block_signature_v4 (ORIGIN(MEM_APPLICATION_ROM) + 0x200): 
   {
      . = ALIGN(8);
      KEEP(*(.block_signature_v4))
   } > MEM_APPLICATION_ROM = 0
   
   /*
    * If application information data available: allocate it directly after signature
    * block V4, resp. at address offset 0x200 if signature block V3 is used
    * (Note: after .application_info, section start addresses are floating)
    */
   .application_info :
   {
      KEEP(*(.fingerprint))         /* KEFEX flashloader version info */
      KEEP(*(.application_info))    /* common application information */
   } AT> MEM_APPLICATION_ROM = 0

   /*
    * allocate external library information data
    */
   .extlibinfo : ALIGN(8)
   {
      __EXTLIBINFO_START = ABSOLUTE(.);
      KEEP(*(.extlibinfo))
   } AT> MEM_APPLICATION_ROM = 0

   /* store .extlibinfo start address in .extlibinfo_start */
   __EXTLIBINFO_OFFSET = (SIZEOF(.extlibinfo) > 0) ? (__EXTLIBINFO_START - ORIGIN(MEM_APPLICATION_ROM)) : 0 ;

   /*
   * provide the end address of the used ROM area (1st. unused address)
   * C usage (external definition):
   * extern const uint32 gu32_EndOfUsedRom;
   */
   .romendinfo : ALIGN(4)
   {
      gu32_EndOfUsedRomInternal1 = .;     /* provide this symbol for HLL access */
      LONG(MEM_INT_ROM1_USED_END);        /* 1st unused internal ROM address */
      gu32_EndOfUsedRomInternal2 = .;     /* provide this symbol for HLL access */
      LONG(MEM_INT_ROM2_USED_END);        /* 1st unused internal ROM address */
      gu32_EndOfUsedRom = .;              /* provide this symbol for HLL access */
      LONG(MEM_EXT_ROM_USED_END);         /* 1st unused external ROM address */
   } AT> MEM_APPLICATION_ROM = 0


   /*
    * Create the clear and copy tables that tell the startup code
    * which memory areas to clear and to copy, respectively.
    */
   .clear_sec : ALIGN(4)
   {
      __clear_table = .;
      /* include additional clear sections */
      *(.clear_sec)
   } AT> MEM_INIT_DATA_ROM = 0

    /*
    * The copy table is used for sections that are special, because their
    * initial code or data (if any) must also be stored in the ROM part of an
    * executable, but they "live" at completely different addresses
    * at runtime -- usually in RAM areas.  NOTE: This is not really
    * necessary if you use a special program loader (e.g., a debugger)
    * to load a complete executable consisting of code, data, BSS, etc.
    * into the RAM of some target hardware or a simulator, but it *is*
    * necessary if you want to burn your application into non-volatile
    * memories such as EPROM or FLASH.
    */
   .copy_sec : ALIGN(4)
   {
      __copy_table = .;
      LONG(LOADADDR(.tvect));   LONG(0 + ADDR(.tvect));     LONG(SIZEOF(.tvect));
      /* include additional copy sections */
      *(.copy_sec)
   } AT> MEM_INIT_DATA_ROM = 0
}



/*
 *   The zdata sections must be placed first in the zdata memory region because
 *   absolute data addressing is only possible at memory segment start
 */
SECTIONS
{
   /*
    * Allocate space for absolute addressable sections; this requires that
    * "int_sram" starts at a TriCore segment (256M) and points to
    * some RAM area!  If these conditions are not met by your particular
    * hardware setup, you should either not use absolute data, or you
    * must move .{z,b}{data,bss}{,.*} input sections to some appropriate
    * memory area.
    */
   .zdata : ALIGN(8)
   {
      ZDATA_BASE = ABSOLUTE(.);
      *(.zdata)
      *(.zdata.*)
      *(.gnu.linkonce.z.*)
      *(.bdata)
      *(.bdata.*)
      . = ALIGN(8);
      ZDATA_END = ABSOLUTE(.);
   } > MEM_ZDATA AT> MEM_INIT_DATA_ROM

   /* make sure, that zdata is placed at an absolute addressable memory region */
   _. = ASSERT(((ZDATA_BASE & 0x0FFFC000) == 0) &&
               ((ZDATA_END & 0x0FFFC000) == 0) &&
               ((ZDATA_BASE & 0xF0000000) == (ZDATA_END & 0xF0000000)),
               "zdata section must be inside an absolute addressable memory region!");

   .zbss (NOLOAD) : ALIGN(8)
   {
      ZBSS_BASE = ABSOLUTE(.);
      *(.zbss)
      *(.zbss.*)
      *(.gnu.linkonce.zb.*)
      *(.bbss)
      *(.bbss.*)
      . = ALIGN(8);
      ZBSS_END = ABSOLUTE(.);
   } > MEM_ZDATA

   /* make sure that zbss is placed at an absolute addressable memory region */
   _. = ASSERT(((ZBSS_BASE & 0x0FFFC000) == 0) &&
               ((ZBSS_END & 0x0FFFC000) == 0) &&
               ((ZBSS_BASE & 0xF0000000) == (ZBSS_END & 0xF0000000)),
               "zdata section must be inside an absolute addressable memory region!");


   .clear_sec :
   {
      LONG(0 + ADDR(.zbss));    LONG(SIZEOF(.zbss));
   } AT> MEM_INIT_DATA_ROM


   .copy_sec :
   {
      LONG(LOADADDR(.zdata));   LONG(0 + ADDR(.zdata));     LONG(SIZEOF(.zdata));
   } AT> MEM_INIT_DATA_ROM

}

