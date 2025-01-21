//-----------------------------------------------------------------------------
/*!
   \internal
   \file       x_memclass.h
   \brief      project specific memory attributes and defines

   \implementation
   project     project name
   copyright   STW (c) 1999-201x
   license     use only under terms of contract / confidential

   \endimplementation
*/
//-----------------------------------------------------------------------------

#ifndef X_MEMCLASS_H
#define X_MEMCLASS_H


#ifdef __cplusplus
extern "C" {
#endif


/* -- Defines ------------------------------------------------------------- */

/**
   These are memory defines for static heap memory that can be reserved by the application
   WARNING: Variables defined with these attributes are used to reserve memory for an
            "application defined heap". They must not be used elsewhere within the application!
**/
// Variables defined with MEM_APPL_STATIC_HEAP_INT_DSPR will be located in a memory section that is
// used by memory class X_MEMCLASS_STATIC_APPL_INT_DSPR for memory allocation.
// The TriCore intern DSPR memory used by these Variables is fast an can be used for safety related data
#define MEM_APPL_STATIC_HEAP_INT_DSPR  __attribute__ ((section (".application_static_heap.int_dspr")))

// Variables defined with MEM_APPL_STATIC_HEAP_EXT_RAM will be located in a memory section that is
// used by memory class X_MEMCLASS_STATIC_APPL_EXT_RAM for memory allocation.
// The extern RAM memory used by these Variables is big, but CANNOT be used for safety related data
#define MEM_APPL_STATIC_HEAP_EXT_RAM   __attribute__ ((section (".application_static_heap.data")))


/**
   These define different HEAP areas
   For the "static application" stack memclasses, the application needs to define
   static stack variables with the required size.
**/
#define X_MEMCLASS_DEFAULT_HEAP           (0u)     // Default HEAP in extern RAM (used by malloc & Co.)
#define X_MEMCLASS_SRAM_HEAP              (1u)     // TriCore internal SRAM HEAP (reserved for STW BIOS)
#define X_MEMCLASS_PROTECTED_HEAP         (2u)     // Protected application HEAP (not in use for ESX-3CS)
#define X_MEMCLASS_DSPR_HEAP              (3u)     // TriCore internal DSPR HEAP (not in use for ESX-3CS)
#define X_MEMCLASS_STATIC_HEAP_INT_DSPR   (4u)     // MPU-Protected HEAP in on-chip DSPRAM for task stack allocation
                                                   // defined by static variable in application
#define X_MEMCLASS_STATIC_HEAP_EXT_RAM    (5u)     // MPU-Protected HEAP in external RAM for task stack allocation
                                                   // defined by static variable in application


#ifdef __cplusplus
} /* end of extern "C" */
#endif

#endif  /* X_MEMTYPE_H */
