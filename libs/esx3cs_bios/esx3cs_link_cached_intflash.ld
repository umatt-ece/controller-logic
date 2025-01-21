/*
 * GNU GCC linker script for ESX-3CS executables
 *
 * Ulrich Herb, STW                                19.06.2015
 *
 *
 * external RAM memory 0x84000000..0x847FFFFF (8MB)
 *
 * usage of external RAM memory (see MEMORY {...} statement):
 *
 * ext_res: 0x84000000..0x8400FFFF, 64KB RAM reserved for debugger
 * ext_ram: 0x84010000..0x847FFFFF, ~8MB (-64KB) memory
 *
 * internal static RAM memory 0xB0000000..0xB0020000 (128KB)
 *
 * user & interrupt stack located inside internal data scratch pad RAM (int_dspr)
 *
 */


/* define available memory regions: */

MEMORY
{
   int_rom1  (rx!p) :   org = 0x80040000, len = 0x001BFE00     /* TC1793 on chip flash ROM 0 (no cache)                    */
   int_rom2  (rx!p) :   org = 0x80800000, len = 0x001FFE00     /* TC1793 on chip flash ROM 1 (no cache)                    */
   ext_rom   (rx!p) :   org = 0x83020000, len = 0              /* no external ROM                                          */

   ext_res   (!wxp) :   org = 0x84000000, len = 0x00010000     /* reserved external RAM (used by Lauterbach Emulator)      */
   ext_ram   (wx!p) :   org = 0x84010000, len = 0x007D0000     /* external RAM                                             */
   ext_pram  (wx!p) :   org = 0x847E0000, len = 0              /* no external protected RAM (SIL1, PLc)                    */
   ext_ram1  (wx!p) :   org = 0x847E0000, len = 0x00020000     /* external RAM not covered by RAM test                     */

   int_drom1 (r!xp) :   org = 0xAF000000, len = 0x00018000     /* TC1793 on chip data flash bank1 (no cache available)     */
   int_drom2 (r!xp) :   org = 0xAF080000, len = 0x00018000     /* TC1793 on chip data flash bank2 (no cache available)     */

   int_sram  (wx!p) :   org = 0x90000000, len = 0x00020000     /* TC1793 internal SRAM (cached)                            */

   int_dspr  (w!xp) :   org = 0xD0000000, len = 0x00020000     /* TC1793 internal data scratch pad RAM                     */

   int_ivram (rx!p) :   org = 0xC0000000, len = 0x00002000     /* scratch pad RAM interrupt vector table                   */
   int_tvram (rx!p) :   org = 0xC0002000, len = 0x00000100     /* scratch pad RAM trap vector table                        */
   int_pspr  (rx!p) :   org = 0xC0002200, len = 0x00005E00     /* TC1793 internal program scratch pad RAM                  */

   pcp_data  (wp!x) :   org = 0xF0050000, len = 16K            /* TC1793 PCP data memory                                   */
   pcp_text  (rxp)  :   org = 0xF0060000, len = 32K            /* TC1793 PCP code memory                                   */
}


/* TC1793 Memory Region Aliases                       */
REGION_ALIAS("MEM_CODERAM_L1"             , int_pspr);
REGION_ALIAS("MEM_CODERAM_L2"             , int_sram);
REGION_ALIAS("MEM_CODERAM_L3"             , ext_ram );

/* note: because of CPU_TC.118 memory region "int_dspr" should not be used for storage of variables
         that expects modifications by atomic load/modify/store operations
         therefore we locate memory region "MEM_DATARAM_L1" into "int_sram" */
REGION_ALIAS("MEM_DATARAM_L1"             , int_sram);
REGION_ALIAS("MEM_DATARAM_L2"             , int_sram);
REGION_ALIAS("MEM_DATARAM_L3"             , ext_ram );
REGION_ALIAS("MEM_ZDATA"                  , int_sram);

/* Build Target Memory Region Aliases                 */
REGION_ALIAS("MEM_APPLICATION_ROM"        , int_rom1);
REGION_ALIAS("MEM_NONINTERFERING_CODE_ROM", int_rom1);
REGION_ALIAS("MEM_APPLICATION_RAM"        , ext_ram );
REGION_ALIAS("MEM_STW_BIOS_ROM"           , int_rom1);
REGION_ALIAS("MEM_STW_BIOS_CODE_RAM"      , ext_ram );
REGION_ALIAS("MEM_STW_BIOS_DATA_RAM"      , int_sram );
REGION_ALIAS("MEM_PROTECTED_CODE_RAM"     , ext_ram );
REGION_ALIAS("MEM_PROTECTED_DATA_RAM"     , int_sram );
REGION_ALIAS("MEM_INIT_DATA_ROM"          , int_rom1);
REGION_ALIAS("MEM_SDATA_STW_BIOS_RAM"     , int_sram);
REGION_ALIAS("MEM_SDATA_STW_BIOS_ROM"     , int_rom1);
REGION_ALIAS("MEM_SDATA_APPLICATION_RAM"  , int_sram);
REGION_ALIAS("MEM_SDATA_APPLICATION_ROM"  , int_rom1);

REGION_ALIAS("MEM_HEAP"                   , ext_ram );
REGION_ALIAS("MEM_STACK_RAM"              , int_dspr);
REGION_ALIAS("MEM_DP_RAM"                 , int_dspr);
REGION_ALIAS("MEM_CSA_RAM"                , int_dspr);


/*
 * define hardware stack size
 */
__ISTACK_SIZE = 4K;                          /* interrupt stack size          */
__USTACK_SIZE = 20K;                         /* user stack size               */

/*
 * define minimum CSA area
 */
__CSA_MIN = 24K;                             /* min. size of CSA area in byte    */

/*
 * Define the headroom for the LCX in number of CSAs before __CSA_END
 * any user defined trap handler needs 3 CSAs (without any
 * subroutines inside the user trap handler function!)
 * the worst case condition is to service a synchronous trap that is
 * interrupted by a asynchronous trap
 */
__LCX_HEADROOM = 6;

/*
 * define minimum heap size
 */
__HEAP_MIN = 512K;            /* define minimum __HEAP size (used by malloc)                                */
__HEAP_USE_MAX = 1;           /* use max. available memory until end of memory region                       */
__HEAP_SRAM_MIN = 16K;        /* define minimum __HEAP_SRAM size (system heap, used for buffers)            */
__HEAP_SRAM_USE_MAX = 1;      /* use max. available memory until end of memory region                       */

/* force linking of library version information */
/* even if not referenced by the application    */
EXTERN(gt_x_lib_info);
EXTERN(gt_xs_lib_info);


/******************************************************************************************************************
 *                                                                                                                *
 *  These Assertions are used to ensure that output sections are allocated in the correct order. If these         *
 *  conditions aren't met, the memory protection will fail to protect certain areas from unauthorized access.     *
 *                                                                                                                *
 ******************************************************************************************************************/

/** All STW BIOS Data must form a contiguous block that is not intersected by other sections **/

/* tricore_std_sections.ld allocates the stw_bios.coderam_L3 first, followed by  stw_bios.dataram_L3*/
/* _. = ASSERT(((SEC_STW_BIOS_DATARAM_L3_START - SEC_STW_BIOS_CODERAM_L3_END) < 8), "STW BIOS coderam and STW BIOS data sections must be contiguous!"); */

/* stw_bios.dataram_L3 is followed then by stw_bios.bss */
_. = ASSERT(((SEC_STW_BIOS_BSS_START - SEC_STW_BIOS_DATARAM_L3_END)  < 8), "STW BIOS data and bss sections must be contiguous!");

/* After all STW BIOS ram sections, the application coderam section is located */
/* _. = ASSERT((SEC_CODERAM_START >= MPU_EXPORT_STW_BIOS_RAM_END), "Allocation of STW C-HAL data and application data is not in right order!"); */

/* Followed by the protected data and bss sections */
/* _. = ASSERT(((SEC_PROTECTED_DATA_START - SEC_CODERAM_END)       <= 12), "coderam and protected data sections must be contiguous!"); */

/* Make sure that the protected sections are not intersected by other sections */
_. = ASSERT(((SEC_PROTECTED_BSS_START - SEC_PROTECTED_DATA_END) <= 12), "protected data and bss sections must be contiguous!");

/* __ISTACK_START must be set to the start address of the memory region so that a stack overflow will result in invalid address trap */
_. = ASSERT (__ISTACK_START == (ORIGIN(MEM_STACK_RAM)), "Interrupt stack (__ISTACK_START) must start with first memory segment address!");

/* make sure, that interrupt and user stack are within MPU - protected area */
_. = ASSERT (((MPU_EXPORT_DATA_MIN_ADDR <= __ISTACK_START) && (MPU_EXPORT_DATA_MAX_ADDR >= (__ISTACK_START + __ISTACK_SIZE))), "interrupt Stack must be within MPU protected area!");
_. = ASSERT (((MPU_EXPORT_DATA_MIN_ADDR <= __USTACK_START) && (MPU_EXPORT_DATA_MAX_ADDR >= (__USTACK_START + __USTACK_SIZE))), "user Stack must be within MPU protected area!");


/* Include all standard sections that don't change with the build targets */
INCLUDE tricore_std_sections_begin.ld
INCLUDE esx3cs_link_signature_v4.ld
INCLUDE tricore_std_sections_end.ld

/* export start/end of reserved external RAM area not covered by RAM test */
MEM_EXT_RAM1_START = ORIGIN(ext_ram1);
MEM_EXT_RAM1_END   = ORIGIN(ext_ram1) + LENGTH(ext_ram1);
MPU_EXPORT_EXT_RAM_END = MEM_EXT_RAM1_END;


/*
 * check for any unallocated input sections
 */
SECTIONS
{
   .unallocated : { *(*) }

   /* Make sure that the .unallocated output section is empty  */
   _. = ASSERT (SIZEOF(.unallocated) == 0, "there are unallocated input sections");
}
