/*
 * GNU GCC linker script extension for standard Tricore Projects
 *
 * Christoph Baldauf, STW                         20.03.2013
 *
 * This file defines the standard linker script definitions and sections
 * that will be defined after project specific sections.
 *
 * NOTE:
 * MPU_EXPORT_* symbols are used as address boundaries for the MPU configuration.
 * TriCore 1.6 Core architecture requires an 8 Byte alignement for these
 * address values. Therefore every MPU_EXPORT_ definition should be prepend by an
 * ALIGN(8) instruction. This may sometimes override the section alignement
 * definition, which defines the minimum alignement requirements of the current
 * output section, to a stricter alignement.
 */



/*
 *  Stack and Interrupt vector table definition
 */
SECTIONS
{
   /*
    * allocate interrupt and user hardware stack
    */
   .stack :
   {
      . = ALIGN(8);
      MPU_EXPORT_ISTACK_START = ABSOLUTE (.);
      __ISTACK_START = ABSOLUTE(.);
      . += __ISTACK_SIZE;
      /* ISTACK must be 64 Bit aligned */
      . = ALIGN(8);
      __ISTACK = ABSOLUTE(.);
      MPU_EXPORT_ISTACK_END = ABSOLUTE(.);
      /* Add an 32 Byte gap for the MPU. This is needed to protect the ISTACK from USTACK overflow */
      . += 32;
      . = ALIGN(8);
      MPU_EXPORT_USTACK_START = ABSOLUTE(.);
      __USTACK_START = ABSOLUTE(.);
      . += __USTACK_SIZE;
      /* USTACK must be 64 Bit aligned */
      . = ALIGN(8);
      __USTACK = ABSOLUTE(.);
      MPU_EXPORT_USTACK_END = ABSOLUTE(.);
      /* Add an 32 Byte gap to make a USTACK underflow better detectable by the MPU */
      . += 32;
      /* Add symbol to export MPU setting for adjacent memory area */
      MPU_EXPORT_USTACK_NEXT = ABSOLUTE(.);
      /* add another 8 Byte MPU safety zone... */
      . += 8;
   } > MEM_STACK_RAM


   .ivect :
   {
      KEEP(*(.inttab))
   } > int_ivram AT> MEM_INIT_DATA_ROM

   .copy_sec :
   {
      LONG(LOADADDR(.ivect));   LONG(0 + ADDR(.ivect));     LONG(SIZEOF(.ivect));
   } AT> MEM_INIT_DATA_ROM
}


/*
 *  Output sections required by crtstuff.c and for C++ programming
 */
SECTIONS
{
   /*
    * C++ Constructors and destructors.
    */
   .ctors : ALIGN(8) FLAGS(arl)
   {
      __CTOR_LIST__ = . ;
      LONG((__CTOR_END__ - __CTOR_LIST__) / 4 - 2);
      KEEP(*(.ctors))
      LONG(0);
      __CTOR_END__ = . ;
   } AT> MEM_INIT_DATA_ROM = 0

   .dtors : ALIGN(8) FLAGS(arl)
   {
      __DTOR_LIST__ = . ;
      LONG((__DTOR_END__ - __DTOR_LIST__) / 4 - 2);
      KEEP(*(.dtors))
      LONG(0);
      __DTOR_END__ = . ;
   } AT> MEM_INIT_DATA_ROM = 0


   /*
    * C++ exception handling tables.  NOTE: gcc emits .eh_frame
    * sections when compiling C sources with debugging enabled (-g).
    * If you can be sure that your final application consists
    * exclusively of C objects (i.e., no C++ objects), you may use
    * the -R option of the "strip" and "objcopy" utilities to remove
    * the .eh_frame section from the executable.
    */
   .eh_frame : ALIGN(8)
   {
      *(.gcc_except_table)
      __EH_FRAME_BEGIN__ = . ;
      KEEP (*(.eh_frame))
      __EH_FRAME_END__ = . ;
   } AT> MEM_INIT_DATA_ROM = 0


   /*
    *   crtstuff.c sections (init/fini/jcr)
    */
   .init : ALIGN(8)
   {
      /* we have to keep all .init/.fini section
       * because the linker should not delete this
       * sections with --gc-sections
       */
      KEEP( *(SORT(.init*)) )
      KEEP( *(SORT(.fini*)) )
   } AT> MEM_INIT_DATA_ROM = 0


   .jcr_ctors : ALIGN(8)
   {
      *(.jcr)
   } AT> MEM_INIT_DATA_ROM = 0
}


/*
 *  PCP text and data will reside in "init data rom" and loaded to the pcptext
 *  and pcpdata destination address at startup
 *  It is important to align the size of the pcp_text and pcp_data section to
 *  a 4byte boundary because this memory regions can only be initialized with
 *  uint32 word access
 */
SECTIONS
{
   .pcptext : ALIGN(8)
   {
      KEEP(*(.pcptext))
      KEEP(*(.pcptext.*))
      . = ALIGN(4);
   } > pcp_text AT> MEM_INIT_DATA_ROM

   .pcpdata : ALIGN(8)
   {
      KEEP(*(.pcpdata))
      KEEP(*(.pcpdata.*))
      . = ALIGN(4);
   } > pcp_data AT> MEM_INIT_DATA_ROM


   .copy_sec :
   {
      LONG(LOADADDR(.pcptext)); LONG(0 + ADDR(.pcptext));   LONG(SIZEOF(.pcptext));
      LONG(LOADADDR(.pcpdata)); LONG(0 + ADDR(.pcpdata));   LONG(SIZEOF(.pcpdata));
   } AT> MEM_INIT_DATA_ROM
}


/*
 *  We can define 4 small data areas.
 *  - 2 areas for STW small data/bss (ram) and rodata (rom)
 *  - 2 areas for application small data/bss (ram) and rodata (rom)
 */
SECTIONS
{
   /* small data and bss section, addressed by global register A3 */
   .sdata4 : ALIGN(8)
   {
      SEC_STW_BIOS_SDATA_START = ABSOLUTE(.);
      *(.sdata.stw_bios)
      *(.sdata.stw_bios.*)
      SEC_STW_BIOS_SDATA_END = ABSOLUTE(.);
   } > MEM_SDATA_STW_BIOS_RAM AT> MEM_INIT_DATA_ROM

   .sbss4 (NOLOAD) : ALIGN(8)
   {
      SEC_STW_BIOS_SDATA_BSS_START = ABSOLUTE(.);
      *(.sbss.stw_bios)
      *(.sbss.stw_bios.*)
      SEC_STW_BIOS_SDATA_BSS_END = ABSOLUTE(.);
   } > MEM_SDATA_STW_BIOS_RAM


   /* small rodata section in for STW BIOS, addressed by global register A2 */
   .sdata3 : ALIGN(8)
   {
      SEC_STW_BIOS_SDATA_RODAT_START = ABSOLUTE(.);
      *(.sdata.stw_bios_rodata)
      *(.sdata.stw_bios_rodata.*)
      SEC_STW_BIOS_SDATA_RODAT_END = ABSOLUTE(.);
   } AT> MEM_SDATA_STW_BIOS_ROM


   /* The sdata2 section should be used for small rodata */
   .sdata2 : ALIGN(8)
   {
      *(.sdata.rodata)
      *(.sdata.rodata.*)
   } AT> MEM_SDATA_APPLICATION_ROM


   /* small data and bss section, addressed by global register A0 */
   /* This .sdata/sbss set can be used by the application         */
   .sdata : ALIGN(8)
   {
      *(.sdata)
      *(.sdata.*)
      *(.gnu.linkonce.s.*)
   } > MEM_SDATA_APPLICATION_RAM AT> MEM_INIT_DATA_ROM

   .sbss (NOLOAD) : ALIGN(8)
   {
      *(.sbss)
      *(.sbss.*)
      *(.gnu.linkonce.sb.*)
   } > MEM_SDATA_APPLICATION_RAM


   .clear_sec :
   {
      LONG(0 + ADDR(.sbss4));   LONG(SIZEOF(.sbss4));
      LONG(0 + ADDR(.sbss));    LONG(SIZEOF(.sbss));
   } AT> MEM_INIT_DATA_ROM


   .copy_sec :
   {
      LONG(LOADADDR(.sdata4));  LONG(0 + ADDR(.sdata4));    LONG(SIZEOF(.sdata4));
      LONG(LOADADDR(.sdata));   LONG(0 + ADDR(.sdata));     LONG(SIZEOF(.sdata));
   } AT> MEM_INIT_DATA_ROM
}


/*
 *   We locate special data RAM locations for variables that need fast access.
 *   Memory speed is classified in speed levels L1 (fastest) - Lx (slowest)
 */
SECTIONS
{
   .dataram_L1 : ALIGN(8)
   {
      SEC_STW_BIOS_DATARAM_L1_START = ABSOLUTE(.);
      KEEP(*(*.stw_bios.dram))                     /* load old - style STW .dram input sections             */
      KEEP(*(*.stw_bios.dram*))                    /* load all STW .dram* sub sections like .dram_c, ...    */
      KEEP(*(*.stw_bios.dataram_L1*))              /* STW data in ram with speed level 1 (fastest)          */
      SEC_STW_BIOS_DATARAM_L1_END = ABSOLUTE(.);

      SEC_STW_DIAG_RAM_START = ABSOLUTE(.);
      KEEP(*(.diag_ram*))
      SEC_STW_DIAG_RAM_END = ABSOLUTE(.);

      KEEP(*(*.dram))                              /* load old - style .dram input sections                 */
      KEEP(*(*.dram*))                             /* load all .dram* sub sections like .dram_c, ...        */
      KEEP(*(.dataram_L1*))
   } > MEM_DATARAM_L1 AT> MEM_INIT_DATA_ROM

   .coderam_L1 : ALIGN(8) FLAGS(x)
   {
      SEC_STW_BIOS_CODERAM_L1_START = ABSOLUTE(.);
      KEEP(*(*.stw_bios.fastram*))                 /* old - style fastram section                           */
      KEEP(*(*.stw_bios.coderam_L1*))              /* code executed in ram with speed level 1 (fastest)     */
      SEC_STW_BIOS_CODERAM_L1_END = ABSOLUTE(.);

      KEEP(*(.fastram))                            /* old - style fastram section                           */
      KEEP(*(.coderam_L1))                         /* code executed in ram with speed level 1 (fastest)     */
   } > MEM_CODERAM_L1 AT> MEM_INIT_DATA_ROM

   .dataram_L2 : ALIGN(8)
   {
      SEC_STW_BIOS_DATARAM_L2_START = ABSOLUTE(.);
      KEEP(*(*.stw_bios.sram))                     /* load old - style STW .sram input sections             */
      KEEP(*(*.stw_bios.sram*))                    /* load all STW .sram* sub sections like .sram_c, ...    */
      KEEP(*(*.stw_bios.dataram_L2))               /* STW data in ram with speed level 2                    */
      SEC_STW_BIOS_DATARAM_L2_END = ABSOLUTE(.);

      *(.sram)                                     /* load old - style .sram input sections                 */
      *(.sram_*)                                   /* load all .sram_* sub sections like .sram_c, ...       */
      *(.sram.data)                                /* load .sram.data input sections                        */
      *(.dataram_L2)                               /* data in ram with speed level 2                        */
   } > MEM_DATARAM_L2 AT> MEM_INIT_DATA_ROM

   .coderam_L2 : ALIGN(8) FLAGS(x)
   {
      SEC_STW_BIOS_CODERAM_L2_START = ABSOLUTE(.);
      KEEP(*(*.stw_bios.coderam_L2))               /* code executed in ram with speed level 2         */
      SEC_STW_BIOS_CODERAM_L2_END = ABSOLUTE(.);
      KEEP(*(.coderam_L2))                         /* code executed in ram with speed level 2         */
   } > MEM_CODERAM_L2 AT> MEM_INIT_DATA_ROM


   /*
    *  TC1796 has dual ported ram. Other targets should use int_dspr memory for compatibility
    */
   .dp_ram : ALIGN(8)
   {
      SEC_STW_BIOS_DP_RAM_START = ABSOLUTE(.);
      KEEP(*(*.stw_bios.dpram*))                   /* for compatibility  */
      SEC_STW_BIOS_DP_RAM_END = ABSOLUTE(.);

      KEEP(*(*.dpram*))                            /* for compatibility  */
   } > MEM_DP_RAM AT> MEM_INIT_DATA_ROM


   .copy_sec :
   {
      LONG(LOADADDR(.dp_ram));      LONG(0 + ADDR(.dp_ram));         LONG(SIZEOF(.dp_ram));
      LONG(LOADADDR(.dataram_L1));  LONG(0 + ADDR(.dataram_L1));     LONG(SIZEOF(.dataram_L1));
      LONG(LOADADDR(.coderam_L1));  LONG(0 + ADDR(.coderam_L1));     LONG(SIZEOF(.coderam_L1));
      LONG(LOADADDR(.dataram_L2));  LONG(0 + ADDR(.dataram_L2));     LONG(SIZEOF(.dataram_L2));
      LONG(LOADADDR(.coderam_L2));  LONG(0 + ADDR(.coderam_L2));     LONG(SIZEOF(.coderam_L2));
   } AT> MEM_INIT_DATA_ROM
}



/*
 *  we locate the STW Bios Sections for .data, .bss and .noinit first,
 *  in case they share the same memory region as the application
 *
 *  MPU_EXPORT_STW_BIOS_EXT_RAM_START and MPU_EXPORT_STW_BIOS_RAM_END
 *  are exported as values for the MPU
 */
SECTIONS
{
   /* locate slow coderam sections (usually external ram) */
   .stw_coderam_L3 : ALIGN(8) FLAGS(x)
   {
      /* Export address for MPU usage */
      . = ALIGN(8);
      MPU_EXPORT_STW_BIOS_RAM_START = ABSOLUTE(.);
      /* add another 8 Byte MPU safety zone... */
      . += 8;
      SEC_STW_BIOS_CODERAM_L3_START = ABSOLUTE(.);
      KEEP(*(*.stw_bios.coderam))         /* old style coderam attribute */
      KEEP(*(*.stw_bios.coderam_L3))      /* code executed in RAM with speed level 3 */
      SEC_STW_BIOS_CODERAM_L3_END = ABSOLUTE(.);
   } > MEM_STW_BIOS_CODE_RAM AT> MEM_INIT_DATA_ROM


   .stw_bios_data : ALIGN(8)
   {
      SEC_STW_BIOS_DATARAM_L3_START = ABSOLUTE(.);
      KEEP(*(*.stw_bios.data*))
      KEEP(*(*.stw_bios.dataram_L3*))
      SEC_STW_BIOS_DATARAM_L3_END = ABSOLUTE(.);
   } > MEM_STW_BIOS_DATA_RAM AT> MEM_INIT_DATA_ROM


   .stw_bios_bss (NOLOAD) : ALIGN(8)
   {
      SEC_STW_BIOS_BSS_START = ABSOLUTE(.);
      KEEP(*(*.stw_bios.bss*))
      SEC_STW_BIOS_BSS_END = ABSOLUTE(.);

      SEC_STW_BIOS_NOINIT_START = ABSOLUTE(.);
      KEEP(*(*.stw_bios.noinit*))
      SEC_STW_BIOS_NOINIT_END = ABSOLUTE(.);

      /*Align for extern system heap */
      . = ALIGN(8);
      /* Reserve memory for extern system heap in STW - protected memory area */
      __HEAP_STW_BIOS = ABSOLUTE(.);
      __HEAP_STW_BIOS_SIZE_MAX = ORIGIN(MEM_STW_BIOS_DATA_RAM) + LENGTH(MEM_STW_BIOS_DATA_RAM) - __HEAP_STW_BIOS;
      /* subtract 8 Byte MPU safety zone */
      __HEAP_STW_BIOS_SIZE_MAX -= 8;
      __HEAP_STW_BIOS_SIZE = DEFINED(__HEAP_STW_BIOS_USE_MAX) ? __HEAP_STW_BIOS_SIZE_MAX : __HEAP_STW_BIOS_MIN;
      . += __HEAP_STW_BIOS_SIZE;
      /* heap end address should be also double word aligned */
      . = ALIGN(8);
      __HEAP_STW_BIOS_END = ABSOLUTE(.);
      /* add another 8 Byte MPU safety zone... */
      . += 8;
      /* ... before we export the last address used by the STW Bios */
      MPU_EXPORT_STW_BIOS_RAM_END = ABSOLUTE(.);
   } > MEM_STW_BIOS_DATA_RAM


   /* Make sure enough memory is available for extern system heap.  */
   _. = ASSERT ((__HEAP_STW_BIOS & 7) == 0 , "STW BIOS heap not doubleword aligned");
   _. = ASSERT ((__HEAP_STW_BIOS_END - __HEAP_STW_BIOS) >= __HEAP_STW_BIOS_MIN , "not enough memory for STW BIOS heap");


   .clear_sec :
   {
      LONG(SEC_STW_BIOS_BSS_START);   LONG(SEC_STW_BIOS_BSS_END - SEC_STW_BIOS_BSS_START);
   } AT> MEM_INIT_DATA_ROM


   .copy_sec :
   {
      LONG(LOADADDR(.stw_coderam_L3));  LONG(0 + ADDR(.stw_coderam_L3));   LONG(SIZEOF(.stw_coderam_L3));
      LONG(LOADADDR(.stw_bios_data));   LONG(0 + ADDR(.stw_bios_data));    LONG(SIZEOF(.stw_bios_data));
   } AT> MEM_INIT_DATA_ROM
}




/*
 *  Followed by .data, .bss and .noinit sections for the
 *  "protected application data"
 *
 *  MPU_EXPORT_PROTECTED_EXT_RAM_START and MPU_EXPORT_PROTECTED_EXT_RAM_END
 *  are exported as values for the MPU
 */
SECTIONS
{
   /* locate coderam sections before protected data */
   .user_coderam : ALIGN(8) FLAGS(x)
   {
      SEC_CODERAM_START = ABSOLUTE(.);
      KEEP(*(.coderam_L3))                          /* code executed in RAM with speed level 3 */
      KEEP(*(.coderam))                             /* old-style coderam section               */
      SEC_CODERAM_END = ABSOLUTE(.);
   } > MEM_PROTECTED_CODE_RAM AT> MEM_INIT_DATA_ROM


   .protected_data : ALIGN(8)
   {
      /* Export address for MPU usage */
      . = ALIGN(8);
      MPU_EXPORT_PROTECTED_RAM_START = ABSOLUTE(.);
      /* Add 8 Byte MPU safety zone (unused) */
      . += 8;
      SEC_PROTECTED_DATA_START = ABSOLUTE(.);
      KEEP(*(*.protected.data*))
      SEC_PROTECTED_DATA_END = ABSOLUTE(.);
   } > MEM_PROTECTED_DATA_RAM AT> MEM_INIT_DATA_ROM


   /* protected_bss MUST be adjacent with protected_data section */
   .protected_bss (NOLOAD) : ALIGN(8)
   {
      SEC_PROTECTED_BSS_START = ABSOLUTE(.);
      KEEP(*(*.protected.bss*))
      SEC_PROTECTED_BSS_END = ABSOLUTE(.);

      SEC_PROTECTED_NOINIT_START = ABSOLUTE(.);
      KEEP(*(*.protected.noinit*))
      SEC_PROTECTED_NOINIT_END = ABSOLUTE(.);

      /* Reserve memory for protected application heap */
      . = ALIGN(8);
      __HEAP_PROTECTED = ABSOLUTE(.);
      __HEAP_PROTECTED_SIZE_MAX = ORIGIN(MEM_PROTECTED_DATA_RAM) + LENGTH(MEM_PROTECTED_DATA_RAM) - __HEAP_PROTECTED;
      /* subtract 8 Byte MPU safety zone */
      __HEAP_PROTECTED_SIZE_MAX -= 8;
      __HEAP_PROTECTED_SIZE = DEFINED(__HEAP_PROTECTED_USE_MAX) ? __HEAP_PROTECTED_SIZE_MAX : __HEAP_PROTECTED_MIN;
      . += __HEAP_PROTECTED_SIZE;
      /* heap end address should be also double word aligned */
      . = ALIGN(8);
      __HEAP_PROTECTED_END = ABSOLUTE(.);

      /* add another 8 Byte MPU safety zone... */
      . += 8;
      /* ... before we export the last address used by the safety application */
      MPU_EXPORT_PROTECTED_RAM_END = ABSOLUTE(.);
   } > MEM_PROTECTED_DATA_RAM

   /* Make sure enough memory is available for protected application heap.  */
   _. = ASSERT ((__HEAP_PROTECTED & 7) == 0 , "Protected application heap not doubleword aligned");
   _. = ASSERT ((__HEAP_PROTECTED_END - __HEAP_PROTECTED) >= __HEAP_PROTECTED_MIN , "not enough memory for protected application heap");

   .clear_sec :
   {
      LONG(SEC_PROTECTED_BSS_START);   LONG(SEC_PROTECTED_BSS_END - SEC_PROTECTED_BSS_START);
   } AT> MEM_INIT_DATA_ROM

   .copy_sec :
   {
      LONG(LOADADDR(.user_coderam));     LONG(0 + ADDR(.user_coderam));  LONG(SIZEOF(.user_coderam));
      LONG(LOADADDR(.protected_data));   LONG(0 + ADDR(.protected_data));LONG(SIZEOF(.protected_data));
   } AT> MEM_INIT_DATA_ROM
}



/*
 * Locate application standard data sections...
 */

SECTIONS
{
   .data : ALIGN(8)
   {
      . = ALIGN(8);
      MPU_EXPORT_UNPROTECTED_EXT_RAM_START = ABSOLUTE(.);
      /* Add 8 Byte MPU safety zone (unused) */
      . += 8;
      SEC_DATA_START = ABSOLUTE(.);
      *(.data)

      /* sort data according to their alignement (only needed with -maligned-data-sections compiler switch) */
      *(.data.a1)                  /* 1-byte alignement       */
      *(.data.a2)                  /* 2-byte alignement       */
      *(.data.a4)                  /* 4-byte alignement       */
      *(.data.a8)                  /* >= 8-byte alignement    */
      *(.data.*)

      *(.gnu.linkonce.d.*)
      SEC_DATA_END = ABSOLUTE(.);
      . = ALIGN(8);
   } > MEM_APPLICATION_RAM AT> MEM_INIT_DATA_ROM

   /*
    * Allocate space for BSS sections.
    */
   .bss (NOLOAD) : ALIGN(8)
   {
      SEC_BSS_START = ABSOLUTE(.);
      *(.bss)

      /* sort bss according to their alignement (only needed with -maligned-data-sections compiler switch) */
      *(.bss.a1)                /* 1-byte alignement       */
      *(.bss.a2)                /* 2-byte alignement       */
      *(.bss.a4)                /* 4-byte alignement       */
      *(.bss.a8)                /* >= 8-byte alignement    */
      *(.bss.*)

      *(.gnu.linkonce.b.*)
      *(COMMON)
      . = ALIGN(8);
      SEC_BSS_END = ABSOLUTE(.);
      BSS_CLEAR = ABSOLUTE(.) - (SEC_BSS_START);

      SEC_NOINIT_START = ABSOLUTE(.);
      *(.noinit)
      SEC_NOINIT_END = ABSOLUTE(.);

      . = ALIGN(8) ;
      /* Add 8 Byte MPU safety zone (unused) */
      . += 8;
      MPU_EXPORT_UNPROTECTED_EXT_RAM_END = ABSOLUTE(.);
   } > MEM_APPLICATION_RAM


   .clear_sec :
   {
      LONG(0 + ADDR(.bss));     LONG(BSS_CLEAR);
   } AT> MEM_INIT_DATA_ROM

   .copy_sec :
   {
      LONG(LOADADDR(.data));    LONG(0 + ADDR(.data));      LONG(SIZEOF(.data));
   } AT> MEM_INIT_DATA_ROM
}



/*
 *  Allocate special data sections for Application defined HEAP areas.
 *  The HEAP areas are sorted and named after the memory area they reside in.
 *  The HEAP areas are not initialized during startup code execution (noinit).
 */

SECTIONS
{
   /* Allocate (application defined) static heap to the intern DSPR memory section */
   .int_dspr_static_heap (NOLOAD) : ALIGN(8)
   {
      . = ALIGN(8);
      MPU_EXPORT_INT_DSPR_APPLICATION_HEAP_START = ABSOLUTE(.);
      . += 8;
      SEC_INT_DSPR_APPL_HEAP_START = ABSOLUTE(.);
      KEEP(*(*.application_static_heap.int_dspr))
      . = ALIGN(8);
      SEC_INT_DSPR_APPL_HEAP_END = ABSOLUTE(.);
      . += 8;
      MPU_EXPORT_INT_DSPR_APPLICATION_HEAP_END = ABSOLUTE(.);
   } > int_dspr


   /* Allocate (application defined) static heap to the intern SRAM memory section */
   .int_sram_static_heap (NOLOAD) : ALIGN(8)
   {
      . = ALIGN(8);
      MPU_EXPORT_INT_SRAM_APPLICATION_HEAP_START = ABSOLUTE(.);
      . += 8;
      SEC_INT_SRAM_APPL_HEAP_START = ABSOLUTE(.);
      KEEP(*(*.application_static_heap.int_sram))
      . = ALIGN(8);
      SEC_INT_SRAM_APPL_HEAP_END = ABSOLUTE(.);
      . += 8;
      MPU_EXPORT_INT_SRAM_APPLICATION_HEAP_END = ABSOLUTE(.);
   } > int_sram


   /* Allocate (application defined) static heap to the application .data memory section */
   .data_static_heap (NOLOAD) : ALIGN(8)
   {
      . = ALIGN(8);
      MPU_EXPORT_EXT_RAM_APPLICATION_HEAP_START = ABSOLUTE(.);
      . += 8;
      SEC_EXT_RAM_APPL_HEAP_START = ABSOLUTE(.);
      KEEP(*(*.application_static_heap.data))
      . = ALIGN(8);
      SEC_EXT_RAM_APPL_HEAP_END = ABSOLUTE(.);
      . += 8;
      MPU_EXPORT_EXT_RAM_APPLICATION_HEAP_END = ABSOLUTE(.);
   } > MEM_APPLICATION_RAM
}



/*
 * All relocatable sections have been defined. We can now terminate the clear and copy table
 */
SECTIONS
{
   .clear_sec :
   {
      LONG(-1);                 LONG(-1);
   } AT> MEM_INIT_DATA_ROM

   .copy_sec :
   {
      LONG(-1);                 LONG(-1);                  LONG(-1);
   } AT> MEM_INIT_DATA_ROM
}


/*
 * Emit definition of interrupt and trap table sizes and base addresses for startup code
 */
SECTIONS
{
   __INTVECT_SIZE = SIZEOF(.ivect);
   __TRAPVECT_SIZE = SIZEOF(.tvect);

   __INTVECT_BASE = (0 + ADDR(.ivect));
   __TRAPVECT_BASE = (0 + ADDR(.tvect));
}


/*
 * All dedicated rom sections have been located. Now we locate the application text and rodata section
 * starting with the chosen default rom section. If this section is full, we continue with int_rom1,
 * int_rom2 and finally ext_rom
 */

SECTIONS
{
   /*
    * allocate all STW .text ( = executable code) sections
    */
   .stw_text : ALIGN(4)
   {
      KEEP(*(.startup_code))
      SEC_STW_BIOS_TEXT_START = ABSOLUTE(.);

      /*
       *  Within stw_bios.text section, we define a subsection for safety critical code and export
       *  it's address boundaries for the MPU code protection. This allows an MPU configuration, which
       *  can deny safety critical code access from non-interfering code.
       */
      . = ALIGN(8);
      MPU_EXPORT_SAFETY_CRITICAL_STW_BIOS_CODE_START = ABSOLUTE(.);
      /* Safety zone not required for code protection */
      KEEP(*(*.safety_critical.stw_bios.text*))
      . = ALIGN(8);
      MPU_EXPORT_SAFETY_CRITICAL_STW_BIOS_CODE_END = ABSOLUTE(.);

      /* allocate remaining stw_bios.text sections */
      KEEP(*(*.stw_bios.text*))

      SEC_STW_BIOS_TEXT_END = ABSOLUTE(.);
   } AT> MEM_STW_BIOS_ROM = 0

   /*
    * allocate all STW read only data sections
    */
   .stw_rodata : ALIGN(8)
   {
      SEC_STW_BIOS_RODATA_START = ABSOLUTE(.);
      KEEP(*(*.stw_bios.rodata*))
      SEC_STW_BIOS_RODATA_END = ABSOLUTE(.);
   } AT> MEM_STW_BIOS_ROM = 0

   /*
    * allocate non-interfering code (not callable from safety relevant code )
    */
   .ext_noninterfering.text : ALIGN(4)
   {
      SEC_EXT_NONINTERFERING_CODE_START = ABSOLUTE(.);
      . = ALIGN(8);
      MPU_EXPORT_NONINTERFERING_CODE_START = ABSOLUTE(.);
      KEEP(*(*.ext_noninterfering.text.*))
      KEEP(*(*.ext_noninterfering.text))
      . = ALIGN(8) ;
      MPU_EXPORT_NONINTERFERING_CODE_END = ABSOLUTE(.);
      SEC_EXT_NONINTERFERING_CODE_END = ABSOLUTE(.);
   } AT> MEM_NONINTERFERING_CODE_ROM = 0


   .text : ALIGN(4)
   {
      *(.text)
      *(.text.*)
      /* .gnu.linkonce sections are used by gcc for vague linking   */
      *(.gnu.linkonce.t.*)
      /* .gnu.warning sections are handled specially by elf32.em.   */
      *(.gnu.warning)
   } AT> MEM_APPLICATION_ROM = 0

   .rodata : ALIGN(8)
   {
      *(.rodata)

      /* sort rodata according to their alignement (only needed with -maligned-data-sections compiler switch) */
      *(.rodata.a1)             /* 1-byte alignement                */
      *(.rodata.a2)             /* 2-byte alignement                */
      *(.rodata.a4)             /* 4-byte alignement                */
      *(.rodata.a8)             /* >= 8-byte alignement             */
      *(.rodata.*)

      /* .gnu.linkonce sections are used by gcc for vague linking   */
      *(.gnu.linkonce.r.*)
      *(.rodata1)
   } AT> MEM_APPLICATION_ROM = 0


   .text_introm1 : ALIGN(4)
   {
      *(.text)
      *(.text.*)
      /* .gnu.linkonce sections are used by gcc for vague linking   */
      *(.gnu.linkonce.t.*)
      /* .gnu.warning sections are handled specially by elf32.em.   */
      *(.gnu.warning)
   } AT> int_rom1 = 0

   .rodata_introm1 : ALIGN(8)
   {
      *(.rodata)

      /* sort rodata according to their alignement (only needed with -maligned-data-sections compiler switch) */
      *(.rodata.a1)             /* 1-byte alignement                */
      *(.rodata.a2)             /* 2-byte alignement                */
      *(.rodata.a4)             /* 4-byte alignement                */
      *(.rodata.a8)             /* >= 8-byte alignement             */
      *(.rodata.*)

      /* .gnu.linkonce sections are used by gcc for vague linking   */
      *(.gnu.linkonce.r.*)
      *(.rodata1)
   } AT> int_rom1 = 0

   .text_introm2 : ALIGN(4)
   {
      *(.text)
      *(.text.*)
      /* .gnu.linkonce sections are used by gcc for vague linking   */
      *(.gnu.linkonce.t.*)
      /* .gnu.warning sections are handled specially by elf32.em.   */
      *(.gnu.warning)
   } AT> int_rom2 = 0

   .rodata_introm2 : ALIGN(8)
   {
      *(.rodata)

      /* sort rodata according to their alignement (only needed with -maligned-data-sections compiler switch) */
      *(.rodata.a1)             /* 1-byte alignement                */
      *(.rodata.a2)             /* 2-byte alignement                */
      *(.rodata.a4)             /* 4-byte alignement                */
      *(.rodata.a8)             /* >= 8-byte alignement             */
      *(.rodata.*)

      /* .gnu.linkonce sections are used by gcc for vague linking   */
      *(.gnu.linkonce.r.*)
      *(.rodata1)
   } AT> int_rom2 = 0

   .text_extrom : ALIGN(4)
   {
      *(.text)
      *(.text.*)
      /* .gnu.linkonce sections are used by gcc for vague linking   */
      *(.gnu.linkonce.t.*)
      /* .gnu.warning sections are handled specially by elf32.em.   */
      *(.gnu.warning)
   } AT> ext_rom = 0

   .rodata_extrom : ALIGN(8)
   {
      *(.rodata)

      /* sort rodata according to their alignement (only needed with -maligned-data-sections compiler switch) */
      *(.rodata.a1)             /* 1-byte alignement                */
      *(.rodata.a2)             /* 2-byte alignement                */
      *(.rodata.a4)             /* 4-byte alignement                */
      *(.rodata.a8)             /* >= 8-byte alignement             */
      *(.rodata.*)

      /* .gnu.linkonce sections are used by gcc for vague linking   */
      *(.gnu.linkonce.r.*)
      *(.rodata1)
   } AT> ext_rom = 0
}



/*
 * Statistic variables (must be declared after all sections has been filled with static data)
 */
SECTIONS
{
   /* set marker for end of used int_crom*/
   .int_rom1_stat :
   {
      /* end of used internal rom will be exported as uint32 to the application and should be aligned */
      MEM_INT_ROM1_USED_END = ABSOLUTE(ALIGN(4));
   } AT> int_rom1


   /* set marker for end of used int_crom*/
   .int_rom2_stat :
   {
      /* end of used internal rom will be exported as uint32 to the application and should be aligned */
      MEM_INT_ROM2_USED_END = ABSOLUTE(ALIGN(4));
   } AT> int_rom2


   /* set marker for end of used ext_crom */
   .ext_rom_stat :
   {
      /* end of used external rom will be exported as uint32 to the application and should be aligned */
      MEM_EXT_ROM_USED_END = ABSOLUTE(ALIGN(4));
   } AT> ext_rom


   /* define end of ext_ram data; All memory left after this marker may be used as heap memory */
   .ext_ram_stat :
   {
      MEM_EXT_RAM_USED_END = ABSOLUTE(.);
   } > ext_ram


   /* define end of ext_pram data; All memory left after this marker may be used as protected heap memory */
   .ext_pram_stat :
   {
      MEM_EXT_PRAM_USED_END = ABSOLUTE(.);
   } > ext_pram


   /* define end of int_sram data; All memory left after this marker will be used as internal system heap memory */
   .int_sram_stat :
   {
      MEM_INT_SRAM_USED_END = ABSOLUTE(.);
   } > int_sram


   /* define end of int_dspr data; All memory left after this marker will be used by DSPR heap and CSA */
   .int_dspr_stat :
   {
      MEM_INT_DSPR_USED_END = ABSOLUTE(.);
      . = ALIGN(8);
      MPU_EXPORT_DSPR_USED_END = ABSOLUTE(.);
      . += 8;
   } > int_dspr


   /* define end of int_pspr memory (program scratch pad RAM = fast code memory) */
   .int_pspr_stat :
   {
      MEM_INT_PSPR_USED_END = ABSOLUTE(.);
   } > int_pspr


   /* set marker for end of used pcp_data */
   .pcp_data_stat :
   {
      MEM_PCP_DATA_USED_END = ABSOLUTE(.);
   } > pcp_data


   /* set marker for end of used pcp_text */
   .pcp_text_stat :
   {
      MEM_PCP_TEXT_USED_END = ABSOLUTE(.);
   } > pcp_text
}


/*
 * Static data statistics have been set.
 * Now we use the rest of the remaining memory for dynamic data. (Heap and CSA)
 */
SECTIONS
{
   .int_dspr_heap :
   {
      /* locate space for SYSTEM heap behind last DSPR section, but before CSA area */
      . = ALIGN(8);
      MPU_EXPORT_HEAP_DSPR_START = ABSOLUTE(.);
      . += 8;
      __HEAP_DSPR = ABSOLUTE(.);
      __HEAP_DSPR_SIZE_MAX = ORIGIN(int_dspr) + LENGTH(int_dspr) - __HEAP_DSPR;
      /* subtract 8 Byte MPU safety zone */
      __HEAP_DSPR_SIZE_MAX -= 8;
      __HEAP_DSPR_SIZE = DEFINED(__HEAP_DSPR_USE_MAX) ? __HEAP_DSPR_SIZE_MAX : __HEAP_DSPR_MIN;
      . += __HEAP_DSPR_SIZE;
      . = ALIGN(8);
      __HEAP_DSPR_END = ABSOLUTE(.);
      . += 8;
      MPU_EXPORT_HEAP_DSPR_END = ABSOLUTE(.);
  } > int_dspr

   /* Make sure enough memory is available for SRAM heap.  */
   _. = ASSERT ((__HEAP_DSPR & 7) == 0 , "DSPR HEAP not doubleword aligned");
   _. = ASSERT ((__HEAP_DSPR_END - __HEAP_DSPR) >= __HEAP_DSPR_MIN , "not enough memory for SRAM HEAP");


   .dram_csa : ALIGN(0x40)
   {
      /* CSA starts after DRAM end address */
      MPU_EXPORT_CSA_START = ABSOLUTE(.);
      __CSA_BEGIN = ABSOLUTE(.);
   } > MEM_CSA_RAM


   .int_sram_heap :
   {
      /* locate space for SYSTEM heap behind last SRAM section */
      . = ALIGN(8);
      . += 8;
      __HEAP_SRAM = ABSOLUTE(.);
      __HEAP_SRAM_SIZE_MAX = ORIGIN(int_sram) + LENGTH(int_sram) - __HEAP_SRAM;
      /* subtract 8 Byte MPU safety zone */
      __HEAP_SRAM_SIZE_MAX -= 8;
      __HEAP_SRAM_SIZE = DEFINED(__HEAP_SRAM_USE_MAX) ? __HEAP_SRAM_SIZE_MAX : __HEAP_SRAM_MIN;
      . += __HEAP_SRAM_SIZE;
      . = ALIGN(8);
      __HEAP_SRAM_END = ABSOLUTE(.);
   } > int_sram

   /* Make sure enough memory is available for SRAM heap.  */
   _. = ASSERT ((__HEAP_SRAM & 7) == 0 , "SRAM HEAP not doubleword aligned");
   _. = ASSERT ((__HEAP_SRAM_END - __HEAP_SRAM) >= __HEAP_SRAM_MIN , "not enough memory for SRAM HEAP");


   .application_heap :
   {
      /* locate space for heap behind last external RAM section */
      . = ALIGN(8);
      . += 8;
      __HEAP = ABSOLUTE(.);
      __HEAP_SIZE_MAX = ORIGIN(MEM_HEAP) + LENGTH(MEM_HEAP) - __HEAP;
      /* subtract 8 Byte MPU safety zone */
      __HEAP_SIZE_MAX -= 8;
      __HEAP_SIZE = DEFINED(__HEAP_USE_MAX) ? __HEAP_SIZE_MAX : __HEAP_MIN;
      . += __HEAP_SIZE;
      . = ALIGN(8);
      __HEAP_END = ABSOLUTE(.);

      /* symbols edata and end are used by newlib malloc function */
      PROVIDE(edata = __HEAP);
      PROVIDE(end = __HEAP_END);
   } > MEM_HEAP

   /* Make sure enough memory is available for heap.  */
   _. = ASSERT ((__HEAP & 7) == 0 , "HEAP not doubleword aligned");
   _. = ASSERT ((__HEAP_END - __HEAP) >= __HEAP_MIN , "not enough memory for HEAP");
}


/*
 * DWARF debug sections.
 * Symbols in the DWARF debugging sections are relative to the
 * beginning of the section, so we begin them at 0.
 */
SECTIONS
{
   /*
    * DWARF 1
    */
   .comment         0 : { *(.comment) }
   .debug           0 : { *(.debug) }
   .line            0 : { *(.line) }
   /*
    * GNU DWARF 1 extensions
    */
   .debug_srcinfo   0 : { *(.debug_srcinfo) }
   .debug_sfnames   0 : { *(.debug_sfnames) }
   /*
    * DWARF 1.1 and DWARF 2
    */
   .debug_aranges   0 : { *(.debug_aranges) }
   .debug_pubnames  0 : { *(.debug_pubnames) }
   /*
    * DWARF 2
    */
   .debug_info      0 : { *(.debug_info) }
   .debug_abbrev    0 : { *(.debug_abbrev) }
   .debug_line      0 : { *(.debug_line) }
   .debug_frame     0 : { *(.debug_frame) }
   .debug_str       0 : { *(.debug_str) }
   .debug_loc       0 : { *(.debug_loc) }
   .debug_macinfo   0 : { *(.debug_macinfo) }
   .debug_ranges    0 : { *(.debug_ranges) }
   /*
    * SGI/MIPS DWARF 2 extensions
    */
   .debug_weaknames 0 : { *(.debug_weaknames) }
   .debug_funcnames 0 : { *(.debug_funcnames) }
   .debug_typenames 0 : { *(.debug_typenames) }
   .debug_varnames  0 : { *(.debug_varnames) }
   /*
    * Optional sections that may only appear when relocating.
    */
   /*
    * Optional sections that may appear regardless of relocating.
    */
   .version_info    0 : { *(.version_info) }
   .boffs           0 : { KEEP (*(.boffs)) }
}
