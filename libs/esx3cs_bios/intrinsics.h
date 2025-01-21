//-----------------------------------------------------------------------------
/*!
   \internal
   \file       intrinsics.h
   \brief      C interface for TriCore special machine instructions

   \implementation
   project     project name
   copyright   STW (c) 1999-200x
   license     use only under terms of contract / confidential

   \created     22.02.2008  Herb
   \endimplementation

*/
//-----------------------------------------------------------------------------

#ifndef _INTRINSICS_H
#define _INTRINSICS_H


/* -- Includes ------------------------------------------------------------ */

#include "stwtypes.h"


#ifdef __cplusplus
extern "C" {
#endif


/***************************************************************************
 * temporary MISRA deviations:
 *
 * message 1006 off:
 * message 3006 off: use of inline assembly is mandatory (intrinsic functions)
 *
 * message 3219 off:
 * message 3450 off: the TriCore GCC need inline functions to be declared static
 * message 3480 off: inline functions are defined inside the header file
 * message 6002 off: inline functions are declared static, but they have global scope
 *
 * message 3204 off: can't use const qualifier on variables which are changed by
 *                   inline assembly code
 * message 3206 off: don't warn about unused inline function parameters (no MISRA rule)
 *                   parameters are used by inline assembly code
 ***************************************************************************/

// PRQA S 3006, 1006 ++
// PRQA S 3219, 3450, 3480, 6002 ++
// PRQA S 3204 ++
// PRQA S 3206 ++


/* -- Defines ------------------------------------------------------------- */

#define CACHE_LINE_SIZE          (32u)             // size of a TriCore V1.6 data cache line
#define UNCACHED_SEGMENT_ADDR    (0x20000000u)     // define to create a non-cached address (logic OR)


/**********************************************************
 * intrinsic assembly inline functions
 **********************************************************/

/*********************************************************************
 *  STW SEPI functions, data types and error codes are each          *
 *  placed into a separate namespace for C++.                        *
 *  The following #ifdef instruction will load either the standard   *
 *  C - API style or the C++ style with namespaces.                  *
 *********************************************************************/
#ifdef __cplusplus
namespace stw_sepi
{
   #include "./hpp/intrinsics.hpp"
}
#else


//-----------------------------------------------------------------------------
/*!
   \brief    insert a nop command (no operation)

   \ingroup

   \created  22.02.2008  Herb

*/
//-----------------------------------------------------------------------------

INLINE void nop(void)
{
   asm volatile ("nop" : : : "memory");
}


//-----------------------------------------------------------------------------
/*!
   \brief    debug command: setup a break event, if debug engine is enabled

   \ingroup

   \created  22.02.2008  Herb

*/
//-----------------------------------------------------------------------------

INLINE void debug(void)
{
   asm volatile ("debug" : : : "memory");
}


//-----------------------------------------------------------------------------
/*!
   \brief    insert a instruction sync command
             1. Wait until all instructions semantically prior to the ISYNC have completed.
             2. Flush the CPU pipeline and cancel all instructions semantically after the ISYNC.
             3. Invalidate all cached state in the pipeline.
             4. Re-Fetch the next instruction after the ISYNC.

   \ingroup

   \created  22.02.2008  Herb

*/
//-----------------------------------------------------------------------------

INLINE void isync(void)
{
   asm volatile ("isync" : : : "memory");
}


//-----------------------------------------------------------------------------
/*!
   \brief    insert a data sync command
             The DSYNC instruction guarantees that all data accesses associated
             with instructions semantically prior to the DSYNC instruction are completed before any
             data memory accesses associated with an instruction semantically after DSYNC are
             initiated. This includes all accesses to the system bus and local data memory.

   \ingroup

   \created  22.02.2008  Herb

*/
//-----------------------------------------------------------------------------

INLINE void dsync(void)
{
   asm volatile ("dsync" : : : "memory");
}


//-----------------------------------------------------------------------------
/*!
   \brief    read a single bit from word u32_DataReg at u32_Pos

   \ingroup

   \param    ou32_DataReg 32bit memory/register that should be read
   \param    ou32_Pos     bit position  [0..31]

   \return   u32_Bit     bit data      [0..1]

   \created  10.11.2006  Herb

*/
//-----------------------------------------------------------------------------

INLINE uint32 get_bit(volatile uint32 ou32_DataReg, uint32 ou32_Pos)
{
   uint32 u32_Bit = 0;

   asm volatile ("extr.u %0, %1, %2, 1" : "=d" (u32_Bit) : "d" (ou32_DataReg), "d" (ou32_Pos));

   return u32_Bit;
}


//-----------------------------------------------------------------------------
/*!
   \brief    read a bit field from word u32_DataReg at u32_Pos

   \ingroup

   \param    ou32_DataReg 32bit memory/register that should be read
   \param    ou32_Pos     bit position    [0..31]
   \param    ou8_Width    bit field width [0..31]

   \return   u32_Bitfield bitfield data

   \created  05.12.2007  Herb

*/
//-----------------------------------------------------------------------------

INLINE uint32 get_bitfield(volatile uint32 ou32_DataReg, uint32 ou32_Pos, const uint8 ou8_Width)
{
   uint32 u32_Bitfield = 0;

   asm volatile ("extr.u %0, %1, %2, %3"
   : "=d" (u32_Bitfield) : "d" (ou32_DataReg), "d" (ou32_Pos), "i" (ou8_Width));

   return u32_Bitfield;
}


//-----------------------------------------------------------------------------
/*!
   \brief    insert a single bit into u32_DataReg at u32_Pos

   \ingroup

   \param    ou32_DataReg 32bit data register that should be written
   \param    ou32_Pos     bit position  [0..31]
   \param    ou32_Bit     bit data      [0..1]

   \return   modified data register

   \created  03.12.2008  Herb

*/
//-----------------------------------------------------------------------------

INLINE uint32 insert_bit(volatile uint32 ou32_DataReg, uint32 ou32_Pos, uint32 ou32_Bit)
{
   uint32 u32_Data = 0;

   asm volatile ("insert %0,%1,%2,%3,1"
   : "=d" (u32_Data) : "d" (ou32_DataReg), "d" (ou32_Bit), "d" (ou32_Pos));

   return u32_Data;
}


//-----------------------------------------------------------------------------
/*!
   \brief    insert a bit field into u32_DataReg at u32_Pos

   \ingroup

   \param    ou32_DataReg   32bit data register that should be written
   \param    ou32_Pos       bit position    [0..31]
   \param    ou8_Width      bit field width [0..31]
   \param    ou32_Bitfield  bitfield data

   \return   modified data register

   \created  03.12.2008  Herb

*/
//-----------------------------------------------------------------------------

INLINE uint32 insert_bitfield(volatile uint32 ou32_DataReg, uint32 ou32_Pos, const uint8 ou8_Width,
                              uint32 ou32_Bitfield)
{
   uint32 u32_Data = 0;

   asm volatile ("insert %0,%1,%2,%3,%4"
   : "=d" (u32_Data) : "d" (ou32_DataReg), "d" (ou32_Bitfield), "d" (ou32_Pos), "i" (ou8_Width));

   return u32_Data;
}


//-----------------------------------------------------------------------------
/*!
   \brief    modify (atomic) a memory location addressed by pu32_RegPtr
             *pu32_RegPtr = (*pu32_RegPtr & ~u32_Mask) | (u32_Data & u32_Mask)

   \ingroup

   \param    opu32_RegPtr pointer to 32bit memory/register that should be modified
   \param    ou32_Mask    bit mask: only set bits are modified
   \param    ou32_Data    data that should be copied to *pRegPtr

   \created  24.10.2005  Herb

*/
//-----------------------------------------------------------------------------

INLINE void modify_mask(volatile uint32 *opu32_RegPtr, uint32 ou32_Mask, uint32 ou32_Data)
{
   asm volatile ("   mov   %%d12, %2         # load data into D12                            \n\t" \
                 "   mov   %%d13, %1         # load mask into D13                            \n\t" \
                 "   ldmst [%0]0, %%e12      # modify memory location addressed by pRegPtr   \n\t" \
                 : : "a" (opu32_RegPtr), "d" (ou32_Mask), "d" (ou32_Data) : "d12", "d13", "memory");
}


//-----------------------------------------------------------------------------
/*!
   \brief    modify (atomic) a single bit addressed by pu32_RegPtr at u32_Pos

   \ingroup

   \param    opu32_RegPtr pointer to 32bit memory/register that should be modified
   \param    ou32_Pos     bit position  [0..31]
   \param    ou32_Bit     bit data      [0..1]

   \created  24.10.2005  Herb

*/
//-----------------------------------------------------------------------------

INLINE void modify_bit(volatile uint32 *opu32_RegPtr, uint32 ou32_Pos, uint32 ou32_Bit)
{
   asm volatile ("   imask %%e12, %2, %1, 1  # load bit mask and data into E12               \n\t" \
                 "   ldmst [%0]0, %%e12      # modify memory location addressed by pRegPtr   \n\t" \
                 : : "a" (opu32_RegPtr), "d" (ou32_Pos), "d" (ou32_Bit) : "d12", "d13", "memory");
}


//-----------------------------------------------------------------------------
/*!
   \brief    modify (atomic) a bit field addressed by pu32_RegPtr at u32_Pos

   \ingroup

   \param    opu32_RegPtr pointer to 32bit memory/register that should be modified
   \param    ou32_Pos     bit position    [0..31]
   \param    ou8_Width    bit field width [0..31]
   \param    ou32_Data    bit field data

   \created  24.10.2005  Herb

*/
//-----------------------------------------------------------------------------

INLINE void modify_bitfield(volatile uint32 *opu32_RegPtr, uint32 ou32_Pos, const uint8 ou8_Width, uint32 ou32_Data)
{
   asm volatile ("   imask %%e12, %2, %1, %3 # load bit mask and data into E12               \n\t" \
                 "   ldmst [%0]0, %%e12      # modify memory location addressed by pRegPtr   \n\t" \
   : : "a" (opu32_RegPtr), "d" (ou32_Pos), "d" (ou32_Data), "i" (ou8_Width) : "d12", "d13", "memory");
}


//-----------------------------------------------------------------------------
/*!
   \brief    swap (atomic) contents of memory location addressed by opu32_RegPtr
             with ou32_Data, return previous memory content

   \ingroup

   \param    opu32_RegPtr pointer to 32bit memory/register
   \param    ou32_Data    data that should be swapped

   \return   previous content of memory location addressed by opu32_RegPtr

   \created  24.10.2005  Herb

*/
//-----------------------------------------------------------------------------

INLINE uint32 swap_uint32(volatile uint32 *opu32_RegPtr, uint32 ou32_Data)
{
   asm volatile ("swap.w [%1]0,%0" : "=d" (ou32_Data) : "a" (opu32_RegPtr), "0" (ou32_Data) : "memory");

   return ou32_Data;
}


//-----------------------------------------------------------------------------
/*!
   \brief    perform a dummy read on address opu32_RegPtr to finish former write access

   \param    opu32_RegPtr pointer to 32bit memory/register

*/
//-----------------------------------------------------------------------------

INLINE void dummy_read(const volatile uint32* const opu32_RegPtr)
{
   asm volatile ("ld.w %%d15,[%0]" : : "a" (opu32_RegPtr): "d15", "memory");
}


//-----------------------------------------------------------------------------
/*!
   \brief    calculate position of most significant bit = 1

   \ingroup

   \note     if no bit is set in u32_Value the function returns 0xFFFFFFFF

   \param    ou32_Value    32bit value

   \created  24.10.2005    Herb

*/
//-----------------------------------------------------------------------------

INLINE uint32 msb_pos(uint32 ou32_Value)
{
   uint32 u32_BitPosMSB = 0;

   asm volatile ("clz %0,%1" : "=d" (u32_BitPosMSB) : "d" (ou32_Value));

   u32_BitPosMSB = (31u - u32_BitPosMSB);

   return u32_BitPosMSB;
}


//-----------------------------------------------------------------------------
/*!
   \brief    get minimum value from u32_Data1 and u32_Data2

   \ingroup

   \param    ou32_Data1    unsigned 32bit data value 1
   \param    ou32_Data2    unsigned 32bit data value 2

   \return   u32_Min       min. data value

   \created  10.08.2007    Herb

*/
//-----------------------------------------------------------------------------

INLINE uint32 min_u32(const uint32 ou32_Data1, const uint32 ou32_Data2)
{
   uint32 u32_Min = 0;

   asm volatile ("min.u %0, %1, %2" : "=d" (u32_Min) : "d" (ou32_Data1), "d" (ou32_Data2));

   return u32_Min;
}


//-----------------------------------------------------------------------------
/*!
   \brief    get minimum value from s32_Data1 and s32_Data2

   \ingroup

   \param    os32_Data1    signed 32bit data value 1
   \param    os32_Data2    signed 32bit data value 2

   \return   s32_Min       min. data value

   \created  10.08.2007    Herb

*/
//-----------------------------------------------------------------------------

INLINE sint32 min_s32(const sint32 os32_Data1, const sint32 os32_Data2)
{
   sint32 s32_Min = 0;

   asm volatile ("min %0, %1, %2" : "=d" (s32_Min) : "d" (os32_Data1), "d" (os32_Data2));

   return s32_Min;
}


//-----------------------------------------------------------------------------
/*!
   \brief    get maximum value from u32_Data1 and u32_Data2

   \ingroup

   \param    ou32_Data1    unsigned 32bit data value 1
   \param    ou32_Data2    unsigned 32bit data value 2

   \return   u32_Max       max. data value

   \created  10.08.2007    Herb

*/
//-----------------------------------------------------------------------------

INLINE uint32 max_u32(const uint32 ou32_Data1, const uint32 ou32_Data2)
{
   uint32 u32_Max = 0;

   asm volatile ("max.u %0, %1, %2" : "=d" (u32_Max) : "d" (ou32_Data1), "d" (ou32_Data2));

   return u32_Max;
}


//-----------------------------------------------------------------------------
/*!
   \brief    get maximum value from s32_Data1 and s32_Data2

   \ingroup

   \param    os32_Data1    signed 32bit data value 1
   \param    os32_Data2    signed 32bit data value 2

   \return   s32_Max       max. data value

   \created  10.08.2007    Herb

*/
//-----------------------------------------------------------------------------

INLINE sint32 max_s32(const sint32 os32_Data1, const sint32 os32_Data2)
{
   sint32 s32_Max = 0;

   asm volatile ("max %0, %1, %2" : "=d" (s32_Max) : "d" (os32_Data1), "d" (os32_Data2));

   return s32_Max;
}


//-----------------------------------------------------------------------------
/*!
   \brief    calculate the absolute value (unsigned) of a given sint32 value

   \ingroup

   \param    os32_Data     signed data

   \return   u32_Result    abs(s32_Data)
*/
//-----------------------------------------------------------------------------
INLINE uint32 abs_s32(const sint32 os32_Data)
{
   uint32 u32_Result = 0;

   asm volatile ("abs %0, %1" : "=d" (u32_Result) : "d" (os32_Data) : "memory");

   return u32_Result;
}


//-----------------------------------------------------------------------------
/*!
   \brief    calculate the (byte) difference between two uint32 data words

   \ingroup

   \param    ou32_Data1    data word 1
   \param    ou32_Data2    data word 2

   \return   u32_Diff      u32_Diff = abs(ou32_Data1 - ou32_Data2)

   \created  21.07.2015    Herb

*/
//-----------------------------------------------------------------------------

INLINE uint32 abs_diff_u32(const uint32 ou32_Data1, const uint32 ou32_Data2)
{
   uint32 u32_Diff = 0;

   asm volatile ("max.u %0, %1, %2 # %0 = max value      \n\t" \
                 "min.u %1, %1, %2 # %1 = min value      \n\t" \
                 "sub   %0, %0, %1 # %0 = (%0 - %1)      \n\t" \
                 : "=&d" (u32_Diff) : "d" (ou32_Data1), "d" (ou32_Data2) : "memory");

   return u32_Diff;
}


//-----------------------------------------------------------------------------
/*!
   \brief    calculate the (byte) difference between two sint32 data words

   \ingroup

   \param    os32_Data1    data word 1
   \param    os32_Data2    data word 2

   \return   u32_Diff      u32_Diff = abs(os32_Data1 - os32_Data2)

   \created  21.07.2015    Herb

*/
//-----------------------------------------------------------------------------

INLINE uint32 abs_diff_s32(const sint32 os32_Data1, const sint32 os32_Data2)
{
   uint32 u32_Diff = 0;

   asm volatile ("absdif %0, %1, %2" : "=d" (u32_Diff) : "d" (os32_Data1), "d" (os32_Data2) : "memory");

   return u32_Diff;
}


//-----------------------------------------------------------------------------
/*!
   \brief    round the input value of32_Data to an unsigned integer
             using the current FPU rounding mode set in PSW.RM
             default rounding mode is "round to nearest"

   \ingroup

   \param    of32_Data     float32 input value

   \return   u32_Result    of32_Data rounded to unsigned integer

   \created  18.12.2012    Herb

*/
//-----------------------------------------------------------------------------

INLINE uint32 float_to_uint32(const float32 of32_Data)
{
   uint32 u32_Result = 0;

   asm volatile ("ftou %0,%1" : "=d" (u32_Result) : "d" (of32_Data));

   return u32_Result;
}


//-----------------------------------------------------------------------------
/*!
   \brief    round the input value of32_Data to a signed integer
             using the current FPU rounding mode set in PSW.RM
             default rounding mode is "round to nearest"

   \ingroup

   \param    of32_Data     float32 input value

   \return   s32_Result    of32_Data rounded to signed integer

   \created  18.12.2012    Herb

*/
//-----------------------------------------------------------------------------

INLINE sint32 float_to_sint32(const float32 of32_Data)
{
   sint32 s32_Result = 0;

   asm volatile ("ftoi %0,%1" : "=d" (s32_Result) : "d" (of32_Data));

   return s32_Result;
}


//-----------------------------------------------------------------------------
/*!
   \brief    multiply float32 value of32_Mult1 by of32_Mult2 and add of32_Add

   \ingroup

   \param    of32_Mult1  multiplier
   \param    of32_Mult2  multiplier
   \param    of32_Add    offset

   \return   f32_Result = of32_Mult1 * of32_Mult2 + of32_Add

   \created  07.11.2008  Herb

*/
//-----------------------------------------------------------------------------

INLINE float32 madd_f32(float32 of32_Mult1, float32 of32_Mult2, float32 of32_Add)
{
   float32 f32_Result = 0.0f;

   asm volatile ("madd.f %0, %3, %1, %2" : "=d" (f32_Result)
                                         : "d" (of32_Mult1), "d" (of32_Mult2), "d" (of32_Add));
   return f32_Result;
}


//-----------------------------------------------------------------------------
/*!
   \brief    multiply float32 value of32_Mult1 by of32_Mult2 and
             subtract product from of32_Minuend

   \ingroup

   \param    of32_Mult1     multiplier
   \param    of32_Mult2     multiplier
   \param    of32_Minuend   minuend

   \return   f32_Result = of32_Minuend - of32_Mult1 * of32_Mult2

   \created  07.11.2008  Herb

*/
//-----------------------------------------------------------------------------

INLINE float32 msub_f32(float32 of32_Mult1, float32 of32_Mult2, float32 of32_Minuend)
{
   float32 f32_Result = 0.0f;

   asm volatile ("msub.f %0, %3, %1, %2" : "=d" (f32_Result)
                                         : "d" (of32_Mult1), "d" (of32_Mult2), "d" (of32_Minuend));
   return f32_Result;
}


//-----------------------------------------------------------------------------
/*!
   \brief   unsigned subtraction with saturation:
            if ((ou32_Minuend - ou32_Subtrahend) < 0)
               u32_Result = 0;
            else
               u32_Result = ou32_Minuend - ou32_Subtrahend;

   \ingroup

   \param    ou32_Minuend     minuend
   \param    ou32_Subtrahend  subtrahend

   \return   u32_Result       see description above

   \created  08.05.2013  Herb

*/
//-----------------------------------------------------------------------------

INLINE uint32 subs_u32(const uint32 ou32_Minuend, const uint32 ou32_Subtrahend)
{
   uint32 u32_Result = 0;

   asm volatile ("subs.u %0, %1, %2" : "=d" (u32_Result) : "d" (ou32_Minuend), "d" (ou32_Subtrahend));

   return u32_Result;
}


//-----------------------------------------------------------------------------
/*!
   \brief   signed subtraction with saturation:
            if ((os32_Minuend - os32_Subtrahend) < -2^31)
               s32_Result = -2^31;
            else if ((os32_Minuend - os32_Subtrahend) > 2^31-1)
               s32_Result = 2^31-1
            else
               s32_Result = os32_Minuend - os32_Subtrahend;

   \ingroup

   \param    os32_Minuend     minuend
   \param    os32_Subtrahend  subtrahend

   \return   s32_Result       see description above

   \created  08.05.2013  Herb

*/
//-----------------------------------------------------------------------------

INLINE sint32 subs_s32(const sint32 os32_Minuend, const sint32 os32_Subtrahend)
{
   sint32 s32_Result = 0;

   asm volatile ("subs %0, %1, %2" : "=d" (s32_Result) : "d" (os32_Minuend), "d" (os32_Subtrahend));

   return s32_Result;
}


//-----------------------------------------------------------------------------
/*!
   \brief   unsigned addition with saturation:
            if ((ou32_Summand1 + ou32_Summand2) > 0xFFFFFFFF)
               u32_Result = 0xFFFFFFFF;
            else
               u32_Result = ou32_Summand1 + ou32_Summand2

   \ingroup

   \param    ou32_Summand1    summand
   \param    ou32_Summand2    summand

   \return   u32_Result       see description above

   \created  08.05.2013  Herb

*/
//-----------------------------------------------------------------------------

INLINE uint32 adds_u32(const uint32 ou32_Summand1, const uint32 ou32_Summand2)
{
   uint32 u32_Result = 0;

   asm volatile ("adds.u %0, %1, %2" : "=d" (u32_Result) : "d" (ou32_Summand1), "d" (ou32_Summand2));

   return u32_Result;
}


//-----------------------------------------------------------------------------
/*!
   \brief   signed addition with saturation:
            if ((os32_Summand1 + os32_Summand2) < -2^31)
               s32_Result = -2^31;
            else if ((os32_Summand1 + os32_Summand2) > 2^31-1)
               s32_Result = 2^31-1
            else
               s32_Result = os32_Summand1 + os32_Summand2;

   \ingroup

   \param    os32_Summand1    summand
   \param    os32_Summand2    summand

   \return   s32_Result       see description above

   \created  08.05.2013  Herb

*/
//-----------------------------------------------------------------------------

INLINE sint32 adds_s32(const sint32 os32_Summand1, const sint32 os32_Summand2)
{
   sint32 s32_Result = 0;

   asm volatile ("adds %0, %1, %2" : "=d" (s32_Result) : "d" (os32_Summand1), "d" (os32_Summand2));

   return s32_Result;
}


//-----------------------------------------------------------------------------
/*!
   \brief    convert a uint32 value into a void* address pointer

   \ingroup

   \param    ou32_UInt32   uint32 value

   \return   void* address pointer

   \created  31.03.2006    Herb

*/
//-----------------------------------------------------------------------------

INLINE void* uint32_to_ptr(const uint32 ou32_UInt32)
{
   void *pvVoid = 0;

   /* move u32_UInt32 (data register value) into pvVoid (address register value) */
   asm volatile ("mov.a %0, %1" : "=a" (pvVoid) : "d" (ou32_UInt32));

   return pvVoid;
}


//-----------------------------------------------------------------------------
/*!
   \brief    convert a void* pointer into a uint32 value

   \ingroup

   \param    opv_Void      address pointer

   \return   u32_UInt32    uint32 value

   \created  31.03.2006    Herb

*/
//-----------------------------------------------------------------------------

INLINE uint32 ptr_to_uint32(const volatile void *opv_Void)
{
   uint32 u32_UInt32 = 0;

   /* move pvVoid (address register value) into u32_UInt32 (data register value) */
   asm volatile ("mov.d %0, %1" : "=d" (u32_UInt32) : "a" (opv_Void));

   return u32_UInt32;
}

//-----------------------------------------------------------------------------
/*!
   \brief    calculate the (byte) difference between two void pointers

   \ingroup

   \param    opv_Void1     address pointer1
   \param    opv_Void2     address pointer2

   \return   u32_Diff      u32_Diff = abs(opv_Void1 - opv_Void2)

   \created  03.04.2006    Herb

*/
//-----------------------------------------------------------------------------

INLINE uint32 ptr_addr_diff(const volatile void* opv_Void1, const volatile void* opv_Void2)
{
   uint32 u32_Diff = 0;                // preset variable to prevent warning

   asm volatile ( "sub.a %%a15, %1, %2 # %1 = (%1 - %2)      \n\t" \
                  "mov.d %0, %%a15     # %0 = (%1 - %2)      \n\t" \
                  "abs   %0, %0        # %0 = ABS(%1 -%2)    \n\t" \
                  : "=d" (u32_Diff) : "a" (opv_Void1), "a" (opv_Void2) : "a15");

   return u32_Diff;
}


//-----------------------------------------------------------------------------
/*!
   \brief    add signed (byte) offset to void pointer

   \ingroup

   \param    opv_Void      address pointer
   \param    os32_Offset   signed address byte offset

   \return   pvVoidOffset  pvVoidOffset = pvVoid + iOffset;

   \created  31.03.2006    Herb

*/
//-----------------------------------------------------------------------------

INLINE void* ptr_addr_offset(const volatile void* opv_Void, sint32 os32_Offset)
{
   void *pvVoidOffset = 0;         // preset variable to prevent compiler warning

   asm volatile ( "addsc.a %0, %1, %2, 0      # %0 = (%1 + %2)      \n\t" \
                  : "=a" (pvVoidOffset) : "a" (opv_Void), "d" (os32_Offset));

   return pvVoidOffset;
}


//-----------------------------------------------------------------------------
/*!
   \brief   Check, if address opu8_Data points to a cached address space

            Return TRUE when opu8_Data is a cached address otherwise return FALSE

   \param   opu8_Data      pointer
*/
//-----------------------------------------------------------------------------

INLINE uint32 address_is_cached(const volatile void* opv_Data)
{
   const uint32 u32_Addr = ptr_to_uint32(opv_Data);

   return ((u32_Addr & 0xE0000000UL) == 0x80000000UL);
}


//-----------------------------------------------------------------------------
/*!
   \brief   translate the pointer address into an uncached address

   \param   opu8_Data      pointer

   \return  uncached address
*/
//-----------------------------------------------------------------------------

INLINE void* address_make_uncached(const volatile void* opv_Data)
{
   const uint32 u32_Addr = ptr_to_uint32(opv_Data);

   return uint32_to_ptr(u32_Addr | UNCACHED_SEGMENT_ADDR);
}


//-----------------------------------------------------------------------------
/*!
   \brief   Write back and invalidate cache lines associated with address range

      This function can be used to force a cache sync with the associated memory.
      "Dirty" data in the cache line(s) will be written back to physical memory
      and marked as "invalid".

      Cached data must be synced before another bus master (eg. DMA, CPU2, etc.)
      accesses this memory area. Otherwise, inconsistency of data may occur.
      Program cache does not need to be synced as code will not be changed during
      runtime.

      This function returns a pointer to the opu8_Data memory start address aligned to
      the next cache line start address.

   \note    TriCore DCACHE and PCACHE are implemented as a "write-back" cache type.
            Cache is organized in 512 lines with each of 32 byte size.
            Write back and invalidation is always done for a complete line.

   \param   opu8_Data      pointer to base address
   \param   ou32_Count     size of memory area (in bytes)

   \return  pointer to the opu8_Data memory start address aligned to the next cache line

*/
//-----------------------------------------------------------------------------

INLINE void* cache_writeback_invalidate(const volatile void* opu8_Data, uint32 ou32_Count)
{
   const uint32 u32_Addr = ptr_to_uint32(opu8_Data);
   const uint32 u32_AddrCacheAligned = u32_Addr & 0xFFFFFFE0UL;

   // check, if source address is a cached address and ou32_Count > 0
   if (((u32_Addr & 0xE0000000UL) == 0x80000000UL) && (ou32_Count != 0))
   {
      // PRQA S 3205 1  // variable u32_CacheLineCount is used by the inline assembly code
      const uint32 u32_CacheLineCount = ((u32_Addr & 0x0000001FUL)+(ou32_Count-1)) >> 5;

      // synchronize CPU data cache and memory
      asm volatile ("   mov.a     %%a13, %0           # load destination address                         \n\t"
                    "   mov.a     %%a15, %1           # load loop counter                                \n\t"
                    " 1:                                                                                 \n\t"
                    "   cachea.wi [%%a13+]32          # invalidate cache line associated with address    \n\t"
                    "   loop      %%a15, 1b           # iterate till memory has been invalidated + saved \n\t"
                    "   dsync                         # finish all memory write transactions             \n\t"
                    :  : "d" (u32_AddrCacheAligned), "d" (u32_CacheLineCount) : "a13", "a15", "memory");
   }

   return (void*)uint32_to_ptr(u32_AddrCacheAligned);
}


/**********************************************************
 * deprecated intrinsic function names
 **********************************************************/

INLINE uint32 umin(const uint32 ou32_Data1, const uint32 ou32_Data2) DEPRECATED;
INLINE uint32 umin(const uint32 ou32_Data1, const uint32 ou32_Data2)
{
   return min_u32(ou32_Data1, ou32_Data2);
}

INLINE sint32 smin(const sint32 os32_Data1, const sint32 os32_Data2) DEPRECATED;
INLINE sint32 smin(const sint32 os32_Data1, const sint32 os32_Data2)
{
   return min_s32(os32_Data1, os32_Data2);
}

INLINE uint32 umax(const uint32 ou32_Data1, const uint32 ou32_Data2) DEPRECATED;
INLINE uint32 umax(const uint32 ou32_Data1, const uint32 ou32_Data2)
{
   return max_u32(ou32_Data1, ou32_Data2);
}

INLINE sint32 smax(const sint32 os32_Data1, const sint32 os32_Data2) DEPRECATED;
INLINE sint32 smax(const sint32 os32_Data1, const sint32 os32_Data2)
{
   return max_s32(os32_Data1, os32_Data2);
}

INLINE float32 madd_f(float32 of32_Mult1, float32 of32_Mult2, float32 of32_Add) DEPRECATED;
INLINE float32 madd_f(float32 of32_Mult1, float32 of32_Mult2, float32 of32_Add)
{
   return madd_f32(of32_Mult1, of32_Mult2, of32_Add);
}

INLINE float32 msub_f(float32 of32_Mult1, float32 of32_Mult2, float32 of32_Minuend) DEPRECATED;
INLINE float32 msub_f(float32 of32_Mult1, float32 of32_Mult2, float32 of32_Minuend)
{
   return msub_f32(of32_Mult1, of32_Mult2, of32_Minuend);
}



#endif  //__cplusplus


#ifdef __cplusplus
} /* end of extern "C" */
#endif


#endif  /* _INTRINSICS_H */
