#ifndef PLATFORM_H
#define PLATFORM_H
/******************************************************************************/
/*!
   \file
      This file defines the generic types that are used by the VIRTEC libraries
      on the STW ESX-3XM hardware platform.

   \copyright
      Copyright (C) 2015  DISTek Integration, Inc.  All Rights Reserved.

   \author
      Chris Thatcher
*/
/******************************************************************************/
//! Version of the Platform Header  (Product,Major,minor,build)
#define PLATFORM_VERSION SoftwareVersion("Platform",1,1,3)

#define SoftwareVersion(P,M,m,b)  P "," #M "." #m "." #b "#"


#include "stdtypes.h"
#include "stwtypes.h"


//! Unsigned 8-bit integer
typedef uint8 uint8_t;

//! Unsigned 16-bit integer
typedef uint16 uint16_t;

//! Unsigned 32-bit integer
typedef uint32 uint32_t;

//! Signed 8-bit integer
typedef sint8 int8_t;

//! Signed 16-bit integer
typedef sint16 int16_t;

//! Signed 32-bit integer
typedef sint32 int32_t;

//! IEEE 754 32-bit floating point type
typedef float32 float32_t;


//! This is a boolean type.  Holds values TRUE and FALSE.
typedef uint8 bool_t;

//! Return type of SIZEOF()  (Note:  Size_T MUST be at least 32-bit)
typedef uint32 Size_T;


//! Dependent on the processor architecture.  Typically 8-bits.
typedef uint8 MinAddressable_T;
//! Macro for explicitly identifying the number of bits in MinAddressable_T
#define MIN_ADDRESSABLE_SIZE_BITS  8
//! Macro for explicitly casting to MinAddressable_T - ensures proper truncation
#define CAST_MinAddressable_T(x)  ((MinAddressable_T)(x))

#define DEFAULT_MEMORY_CLASS
#define QUEUE_MEMORY_CLASS
#define GENERAL_MEMORY_CLASS

#define PTR_TO_VAR(ptr_t, mem_class, ptr_class) ptr_t *
#define CONST_PTR_TO_VAR(ptr_t, mem_class, ptr_class) ptr_t * const
#define PTR_TO_CONST(ptr_t, mem_class, ptr_class) const ptr_t *
#define MAKE_MemoryPointer_T(address) ((void*) address)

//! User-defined structure to reference arbitrary memory locations
typedef struct MemoryPointer_S
{
   //! Pointer to location
   void *Address;
} MemoryPointer_T;


//! Generic type for implementing Mutexes  (Currently not implemented)
typedef uint32_t  Mutex_T;


/******************************************************************************/
/*!
   \brief    Macro used to initialize a Mutex_T

   \details  This macro is used to create a Mutex_T.

   \param    priority  Priority of highest priority task that accesses this
                       structure
*/
/******************************************************************************/
#define MAKE_Mutex_T(priority)  0


//! Initialize the priority class of the process
extern void Mutex_Init(Mutex_T *mutex);

//! Initialize the Mutex using information from another Mutex
extern void Mutex_CopyInit(Mutex_T *mutex_to_init, const Mutex_T *copy_from_mutex);

//! Increase the priority of the current task to the ceiling (and returns the base priority)
extern void Mutex_Get(Mutex_T *mutex);

//! Restore the current task to the base priority
extern void Mutex_Release(Mutex_T *mutex);


/******************************************************************************/
/*
   Copyright (C) 2015  DISTek Integration, Inc.  All Rights Reserved.

   Developed by:
      DISTek(R) Integration, Inc.
      6612 Chancellor Drive Suite 600
      Cedar Falls, IA 50613
      Tel: 319-859-3600
*/
/******************************************************************************/
#endif //PLATFORM_H
