#ifndef FOUNDATION_H
#define FOUNDATION_H
/******************************************************************************/
/*!
   \file
      Foundation Functionality API
   \copyright
      Copyright (C) 2017  DISTek Integration, Inc.  All Rights Reserved.
*/
/******************************************************************************/
//! Version of the Foundation Library  (Product,Major,minor,build)
#define FOUNDATION_VERSION SoftwareVersion("Foundation",2,3,1)
//! This structure is used to notify a module when a packet has been sent
typedef struct ISOBUS_Callback_S
{
   //! Callback function pointer
   void (*Function)(const struct ISOBUS_Callback_S *pointer);
   //! Pointer to arbitrary data for use by callback
   void *Pointer_1;
   //! Pointer to arbitrary data for use by callback
   const void *Pointer_2;
} ISOBUS_Callback_T;
// Ensure that compiler abstraction macros are defined
#ifndef DEFAULT_MEMORY_CLASS
//! Default memory class (near/far/huge)
#define DEFAULT_MEMORY_CLASS
#endif //DEFAULT_MEMORY_CLASS
#ifndef QUEUE_MEMORY_CLASS
//! Queue memory class (near/far/huge)
#define QUEUE_MEMORY_CLASS
#endif //QUEUE_MEMORY_CLASS
#ifndef GENERAL_MEMORY_CLASS
//! General memory class (near/far/huge)
#define GENERAL_MEMORY_CLASS
#endif //GENERAL_MEMORY_CLASS
#ifndef PTR_TO_VAR
/******************************************************************************/
/*!
   \brief    Macro for defining compiler syntax for a pointer to a variable
   \details  This macro provides the ability to customize syntax for
             near/far/huge pointers based on compiler
   \param    ptr_t      Data type that is being pointed at
   \param    mem_class  Memory class where pointer is located  (pointer located in near memory)
   \param    ptr_class  Memory class of data being pointed at  (data located in huge memory)
*/
/******************************************************************************/
#define PTR_TO_VAR(ptr_t, mem_class, ptr_class) ptr_t *
#endif //PTR_TO_VAR
#ifndef CONST_PTR_TO_VAR
/******************************************************************************/
/*!
   \brief    Macro for defining compiler syntax for a const pointer to a variable
   \details  This macro provides the ability to customize syntax for const
             near/far/huge pointers based on compiler
   \param    ptr_t      Data type that is being pointed at
   \param    mem_class  Memory class where pointer is located  (pointer located in near memory)
   \param    ptr_class  Memory class of data being pointed at  (data located in huge memory)
*/
/******************************************************************************/
#define CONST_PTR_TO_VAR(ptr_t, mem_class, ptr_class) ptr_t * const
#endif //CONST_PTR_TO_VAR
#ifndef PTR_TO_CONST
/******************************************************************************/
/*!
   \brief    Macro for defining compiler syntax for a pointer to a constant
   \details  This macro provides the ability to customize syntax for
             near/far/huge pointers to constant data based on compiler
   \param    ptr_t      Data type that is being pointed at
   \param    mem_class  Memory class where pointer is located  (pointer located in near memory)
   \param    ptr_class  Memory class of data being pointed at  (data located in huge memory)
*/
/******************************************************************************/
#define PTR_TO_CONST(ptr_t, mem_class, ptr_class) const ptr_t *
#endif //PTR_TO_CONST
#if (MIN_ADDRESSABLE_SIZE_BITS == 8)
//! Macro to translate compiler sizeof() response to number of 8-bit bytes
#define SIZEOF(x)   ((Size_T)sizeof(x))
//! Macro for declaring an array of 8-bit elements
#define Declare8BitArray(array,size)  MinAddressable_T array[size]
//! Macro for accessing 8-bit elements stored compacted in a MinAddressable_T array
#define Get8BitArrayIndex(array,index)  (((PTR_TO_CONST(MinAddressable_T, GENERAL_MEMORY_CLASS, DEFAULT_MEMORY_CLASS))array)[index])
//! Macro for accessing 8-bit elements stored compacted in a MinAddressable_T array
#define Write8BitArrayIndex(array,index,value)  (((PTR_TO_VAR(MinAddressable_T, GENERAL_MEMORY_CLASS, DEFAULT_MEMORY_CLASS))array)[index] = (value))
#else
//! Macro to translate compiler sizeof() response to number of 8-bit bytes
#define SIZEOF(x)   ((Size_T)(sizeof(x)*(MIN_ADDRESSABLE_SIZE_BITS)/8/sizeof(MinAddressable_T)))
//! Macro for declaring an array of 8-bit elements
#define Declare8BitArray(array,size)  MinAddressable_T array[(size-1)/SIZEOF(MinAddressable_T)+1]
//! Macro for accessing 8-bit elements stored compacted in a MinAddressable_T array
#define Get8BitArrayIndex(array,index)  ((((PTR_TO_CONST(MinAddressable_T, GENERAL_MEMORY_CLASS, DEFAULT_MEMORY_CLASS))array)[(index) / SIZEOF(MinAddressable_T)] >> (((index) % SIZEOF(MinAddressable_T))*8)) && 0xFF)
//! Macro for accessing 8-bit elements stored compacted in a MinAddressable_T array
#define Write8BitArrayIndex(array,index,value)  (((PTR_TO_VAR(MinAddressable_T, GENERAL_MEMORY_CLASS, DEFAULT_MEMORY_CLASS))array)[(index) / SIZEOF(MinAddressable_T)] = (array[(index) / SIZEOF(MinAddressable_T)] & (0xFF << (((index) % SIZEOF(MinAddressable_T)))*8)) | ((value) << (((index) % SIZEOF(MinAddressable_T))*8)))
#endif //(MIN_ADDRESSABLE_SIZE_BITS == 8)
#ifndef FALSE
//! Boolean value for FALSE (if not already defined)
#define FALSE 0
#endif //FALSE
#ifndef TRUE
//! Boolean value for TRUE (if not already defined)
#define TRUE 1
#endif //TRUE
#ifndef NULL
//! Value for NULL (if not already defined)
#define NULL 0
#endif //NULL
#ifndef max
/******************************************************************************/
/*!
   \brief    Macro that returns maximum of two values
   \param  v1  First value
   \param  v2  Second value
*/
/******************************************************************************/
#define max(v1,v2)  (((v1)>(v2)) ? (v1) : (v2))
#endif //max
#ifndef min
/******************************************************************************/
/*!
   \brief    Macro that returns minimum of two values
   \param  v1  First value
   \param  v2  Second value
*/
/******************************************************************************/
#define min(v1,v2)  (((v1)<(v2)) ? (v1) : (v2))
#endif //min
/******************************************************************************/
/*!
   \brief    Macro for taking the ceiling of the result of integer division
   \details  Returns the ceiling of the result of the division of two integers
             n and d.
   \param  n  Numerator of the division
   \param  d  Denominator of the division
*/
/******************************************************************************/
#define Utility_Ceiling(n,d)  (((n)-1)/(d)+1)
/******************************************************************************/
/*!
   \brief    Macro for rounding the result of integer division
   \details  Returns the result of the division of two integers n and d rounded
             to the nearest integer.
   \param  n  Numerator of the division
   \param  d  Denominator of the division
*/
/******************************************************************************/
#define Utility_Round(n,d)  (((n)<0) ? (((n)-(d)/2)/(d)) : (((n)+(d)/2)/(d)))
#ifndef ASSERT
/******************************************************************************/
//!
//!   \brief    Macro to explicitly state assumptions that are verified at run-time
//!
//!   \details  By default, this macro does nothing.  A compatible ASSERT() macro
//!             defined via the Platform.h include allows the user to specify
//!             useful action in the case that this is FALSE.
//!
//!   \param  is_true    Boolean expression that is expected to be TRUE
//!   \param  string     NULL-terminated char array containing useful
//!                      information if the expression evaluates FALSE
//!
//!   \attention  The `string` parameter should always be parenthesized, which will
//!               allow pre-C99 compilers to expand to use a variadic function like
//!               printf.  For Example:
//!
//! ~~~~{.c}
//! // Example ASSERT() definition
//! #define ASSERT(is_true, string)  if(!(is_true)) { printf string; }
//!
//! // Example function calling ASSERT()
//! void SomeFunction(void *pointer)
//! {
//!    ASSERT(pointer == NULL, ("SomeFunction(): `pointer` parameter is not NULL!  Actual value is: 0x%08X\n", (uint32_t)pointer));
//!    // expands to:
//!    if(!(pointer == NULL)) { printf ("SomeFunction(): `pointer` parameter is not NULL!  Actual value is: 0x%08X\n", (uint32_t)pointer); };
//! }
//! ~~~~
//!
//!   \note  Since most embedded systems do not have a display to `printf` to, here
//!          is a sample implementation of a wrapper function that takes the
//!          `printf` parameters, but calls `vsprintf` instead.  This may be helpful
//!          to dump data to the network via a proprietary means:
//!
//! ~~~~{.c}
//! void  Assert_printf(const char *format, ...)
//! {
//!    // local to pointer to `...` parameter
//!    va_list arg;
//!    // local char string to print into
//!    char  buffer[200];
//!
//!    // assign `arg` the start address of the parameter list
//!    // 1st parameter after `format`)
//!    va_start (arg, format);
//!    // Call sprintf() and pass the incoming paramters (tacking in buffer)
//!    (void)vsprintf(buffer, format, arg);
//!    // Flag that the processing of `arg` is complete
//!    va_end (arg);
//!
//!    // Push the string into a debug buffer (for output later)
//!    Pipe_InsertString(SomeDebugWritePipeHandle, buffer);
//! }
//! ~~~~
//!
/******************************************************************************/
#define ASSERT(is_true, string)
#endif //ASSERT
//! Data type used to store a frequency
typedef uint32_t Frequency_T;
//! Convert value from Hz to Frequency_T
#define Hz(x) ((Frequency_T)(x))
//! Convert value from kHz to Frequency_T
#define kHz(x) ((Frequency_T)(x) * (Frequency_T)1000U)
//! Convert value from MHz to Frequency_T
#define MHz(x) ((Frequency_T)(x) * (Frequency_T)1000000UL)
//! Convert from Frequency_T to Hz
#define FrequencyInHz(x) (x)
//! Convert from Frequency_T to kHz
#define FrequencyInkHz(x) ((x) / (Frequency_T)1000U)
//! Convert from Frequency_T to MHz
#define FrequencyInMHz(x) ((x) / (Frequency_T)1000000UL)
/******************************************************************************/
/*!
   \details  Copies from source to destination
   \param    destination  Destination for data to copy
   \param    source       Source of data to copy
   \param    size         size of data to copy (from sizeof())
*/
/******************************************************************************/
extern void Utility_MemoryCopy(PTR_TO_VAR(void, GENERAL_MEMORY_CLASS, DEFAULT_MEMORY_CLASS) destination, PTR_TO_CONST(void, GENERAL_MEMORY_CLASS, DEFAULT_MEMORY_CLASS) source, Size_T size);
/******************************************************************************/
/*!
   \details  Compares memory at locations `comp1` and `comp2`
   \param    comp1        Data to compare comp2 against
   \param    comp2        Data to compare comp1 to
   \param    size         size of data to compare (from sizeof())
   \return  bool_t
   \retval  TRUE   The memory at `comp1` and `comp2` match
   \retval  FALSE  The memory at `comp1` and `comp2` does not match
*/
/******************************************************************************/
extern bool_t Utility_MemoryMatch(PTR_TO_CONST(void, GENERAL_MEMORY_CLASS, DEFAULT_MEMORY_CLASS) comp1, PTR_TO_CONST(void, GENERAL_MEMORY_CLASS, DEFAULT_MEMORY_CLASS) comp2, Size_T size);
/******************************************************************************/
/*!
   \details  Converts character to lower case
   \param    character  Character to convert
   \return   char
*/
/******************************************************************************/
extern char Utility_ToLowerCase(char character);
/******************************************************************************/
/*!
   \details  Converts character to upper-case
   \param    character  Character to convert
   \return   char
*/
/******************************************************************************/
extern char Utility_ToUpperCase(char character);
//! Node intended to be registered with a LinkedList_List_S
struct LinkedList_Node_S
{
   //! Pointer to list mutex (assigned when registered)
   Mutex_T *Mutex;
   //! Pointer to next link/node in list
   struct LinkedList_Node_S *Next;
   //! Pointer to the data structure (this LinkedList_Node_S is typically a member)
   void *This;
};
/******************************************************************************/
/*!
   \brief    Macro used to create a LinkedList_Node_S
   \details  This macro is used to create a LinkedList_Node_S structure which
             will be registered in a LinkedList_List_S.
   \param    declaration  Pointer to a data structure intended to be registered
             into the linked list.
*/
/******************************************************************************/
#define MAKE_LinkedList_Node_S(declaration) {NULL, NULL, declaration}
//! Linked list structure - intended for registering LinkedList_Node_S structures
struct LinkedList_List_S
{
   //! Mutex protecting the list
   Mutex_T Mutex;
   //! Pointer to the head of the linked list
   struct LinkedList_Node_S *Head;
   //! Pointer representing the end of the linked list (Not a valid node!!!)
   struct LinkedList_Node_S *EndOfList;
};
/******************************************************************************/
/*!
   \brief    Macro used to create a LinkedList_List_S
   \details  This macro is used to create a LinkedList_List_S structure which
             contains a list of registered LinkedList_Node_S.
   \param    priority  Priority of highest priority task that accesses this
                       list or its nodes
*/
/******************************************************************************/
#define MAKE_LinkedList_List_S(priority) {MAKE_Mutex_T(priority), NULL, NULL}
/******************************************************************************/
/*!
   \details  Initialize the Linked List
   \param  list  Linked List to initialize
*/
/******************************************************************************/
extern void LinkedList_Init(struct LinkedList_List_S *list);
/******************************************************************************/
/*!
   \brief    Adds `node` to `list`
   \details  Register a `node` in a linked `list`
   \param  list  Pointer to Linked List structure
   \param  node  Linked List `node` to register in the `list`
   \return  bool_t
   \retval  TRUE   Node successfully registered
   \retval  FALSE  Node not registered (possibly already registered here or elsewhere)
*/
/******************************************************************************/
extern bool_t LinkedList_Register(struct LinkedList_List_S *list, struct LinkedList_Node_S *node);
/******************************************************************************/
/*!
   \brief    Removes `node` from `list`
   \details  Unregister a `node` in a linked `list`
   \param  list  Pointer to Linked List structure
   \param  node  Linked List `node` to register in the `list`
   \return  bool_t
   \retval  TRUE   Node successfully unregistered
   \retval  FALSE  Node not found (possibly not registered in this `list`)
*/
/******************************************************************************/
extern bool_t LinkedList_Unregister(struct LinkedList_List_S *list, struct LinkedList_Node_S *node);
//! Data type used to store an amount of time
typedef uint32_t Time_T;
//! Timer value when it has expired
#define TIMER_EXPIRED ((Time_T)0) /* timer counts down to zero*/
//! Convert value from microseconds to Time_T
#define microseconds(x) (Utility_Ceiling((Time_T)(x),(Time_T)1000U))
//! Convert value from milliseconds to Time_T
#define milliseconds(x) ((Time_T)(x))
//! Convert value from seconds to Time_T
#define seconds(x) ((Time_T)(x) * (Time_T)1000U)
//! Convert from Time_T to microseconds
#define TimeInMicroseconds(x) ((x)*(Time_T)1000U)
//! Convert from Time_T to milliseconds
#define TimeInMilliseconds(x) (x)
//! Convert from Time_T to seconds
#define TimeInSeconds(x) Utility_Ceiling((x),(Time_T)1000U)
//! This structure is used to register Software Timers
typedef struct SoftwareTimer_S
{
   //! Member for registering in linked list
   struct LinkedList_Node_S LinkedList_Node;
   //! Current timer value
   Time_T Value;
   //! \brief    Callback when timer expires
   //! \warning  DO NOT block in the callback!  This is currently used as a watchdog.
   ISOBUS_Callback_T Callback;
} SoftwareTimer_T;
/******************************************************************************/
/*!
   \brief    Macro used to initialize a SoftwareTimer_T
   \details  This macro is used to create a SoftwareTimer_T.
   */
/******************************************************************************/
#define MAKE_SoftwareTimer_T() {MAKE_LinkedList_Node_S(NULL), TIMER_EXPIRED, {NULL, NULL, NULL}}
//! Software Timer list
typedef struct SoftwareTimerList_S
{
   //! Member to allow LinkedList_Node_S to be registered
   struct LinkedList_List_S LinkedList;
   //! Amount of time between SoftwareTimer_PeriodicTask() calls
   Time_T Period;
} SoftwareTimerList_T;
/******************************************************************************/
/*!
   \brief    Macro used to initialize a SoftwareTimerList_T
   \details  This macro is used to create a SoftwareTimerList_T.
   \param    period    Time between calls to the periodic task
   \param    priority  Ceiling priority of tasks that access the Software Timers in the list
*/
/******************************************************************************/
#define MAKE_SoftwareTimerList_T(period,priority) {MAKE_LinkedList_List_S(priority), period}
/******************************************************************************/
/*!
   \details  Initialize the Software Timer List
   \param    list     Software Timer List to initialize
*/
/******************************************************************************/
extern void SoftwareTimerList_Init(SoftwareTimerList_T *list);
/******************************************************************************/
/*!
   \details  Decrements each timer in the list by timer period until it reaches
             a value of 0.
   \param    list  List of Software Timers to decrement
*/
/******************************************************************************/
extern void SoftwareTimer_PeriodicTask(SoftwareTimerList_T *list);
/******************************************************************************/
/*!
   \brief    Register a Software Timer
   \details  Register a Software Timer to a `list`
   \param    list   List to register with
   \param    timer  timer to register
   \return   bool_t
   \retval   TRUE   Timer was successfully registered
   \retval   FALSE  Timer registration failed
*/
/******************************************************************************/
extern bool_t SoftwareTimer_Register(SoftwareTimerList_T *list, SoftwareTimer_T *timer);
/******************************************************************************/
/*!
   \brief    Unregister a Software Timer
   \details  Unregister a Software Timer from `list`
   \param    list   List to unregister timer from
   \param    timer  Timer to unregister
   \return   bool_t
   \retval   TRUE   Successfully unregistered
   \retval   FALSE  Unregistration failed
*/
/******************************************************************************/
extern bool_t SoftwareTimer_Unregister(SoftwareTimerList_T *list, SoftwareTimer_T *timer);
/******************************************************************************/
/*!
   \brief    Get the value of a timer
   \details  Get the time left on a software timer
   \param    timer  timer to read
   \return   Time_T
*/
/******************************************************************************/
extern Time_T SoftwareTimer_Get(const SoftwareTimer_T *timer);
/******************************************************************************/
/*!
   \brief    Set the value of a timer
   \details  Set the timeout of the timer
   \param    timer    Timer to set
   \param    timeout  Time until timeout
*/
/******************************************************************************/
extern void SoftwareTimer_Set(SoftwareTimer_T *timer, Time_T timeout);
/******************************************************************************/
/*!
   \brief    Determines length of string (no limit to length)
   \details  Determine the length of a C string
   \param    string   C string to determine length of
   \return   Size_T
*/
/******************************************************************************/
extern Size_T String_Length(const char *string);
/******************************************************************************/
/*!
   \brief    Determines length of string (with a maximum length)
   \details  Determine the length of a C string
   \param    string   C string to determine length of
   \param    limit    Maximum length of string
   \return   Size_T
*/
/******************************************************************************/
extern Size_T String_LimitedLength(const char *string, Size_T limit);
//! Queue of arbitrary type and size
typedef struct Queue_S
{
   //! Priority of highest priority task that accesses this queue
   Mutex_T Mutex;
   //! Index in queue array of the front item (circular queue)
   volatile Size_T Front;
   //! Number of bytes used in the queue array
   volatile Size_T Used;
   //! Size of the queue array in 8-bit bytes
   const Size_T Size;
   //! Pointer to the queue array
   CONST_PTR_TO_VAR(void, QUEUE_MEMORY_CLASS, DEFAULT_MEMORY_CLASS) Array;
} Queue_T;
/******************************************************************************/
/*!
   \brief    Create a queue array containing `size` elements of `type` (for use in a queue)
   \param    arrayname  Name of the array
   \param    type       Data type of the array elements
   \param    size       Number of elements in the array
*/
/******************************************************************************/
#define MAKE_QUEUE_ARRAY(arrayname,type,size) type arrayname[size]
/******************************************************************************/
/*!
   \brief    Create a queue object pointing to a queue array
   \details  This macro is used to create a queue object pointing to a queue
             array previously declared using the MAKE_QUEUE_ARRAY macro.
   \param    arrayname  Name of the queue array
   \param    priority   Priority level of highest priority task that accesses this queue
*/
/******************************************************************************/
#define MAKE_Queue_T(arrayname,priority) {MAKE_Mutex_T(priority), 0, 0, SIZEOF(arrayname), (CONST_PTR_TO_VAR(void, QUEUE_MEMORY_CLASS, DEFAULT_MEMORY_CLASS))arrayname}
/******************************************************************************/
/*!
   \brief    Returns number of bytes available in the queue
   \param    queue_ptr   Pointer to the queue object
*/
/******************************************************************************/
#define Queue_SpaceAvailable(queue_ptr) ((queue_ptr)->Size - (queue_ptr)->Used)
/******************************************************************************/
/*!
   \brief    Initialize the queue
   \details  Empties the `queue` to prepare it for use.
   \param    queue  Queue to initialize
*/
/******************************************************************************/
extern void Queue_Init(Queue_T *queue);
/******************************************************************************/
/*!
   \brief    Initialize the queue using priority from another mutex
   \details  Empties the `queue` to prepare it for use.
   \param    queue            Queue to initialize
   \param    copy_from_mutex  Mutex to copy priority data from
*/
/******************************************************************************/
extern void Queue_CopyInit(Queue_T *queue, const Mutex_T *copy_from_mutex);
/******************************************************************************/
/*!
   \brief    Insert element at end of queue
   \details  Insert `element` of `size` at end of `queue`
   \param    queue    Queue to insert element into
   \param    element  Pointer to element to place in queue
   \param    size     Size of the element (using SIZEOF())
   \return   bool_t
   \retval   TRUE   Element was inserted into queue
   \retval   FALSE  Element was not inserted into queue
*/
/******************************************************************************/
extern bool_t Queue_Insert(Queue_T *queue, PTR_TO_CONST(void, QUEUE_MEMORY_CLASS, DEFAULT_MEMORY_CLASS) element, Size_T size);
/******************************************************************************/
/*!
   \brief    Insert string at end of queue
   \details  Insert `string` at end of `queue`
   \param    queue    Queue to insert element into
   \param    string   C string
   \return   bool_t
   \retval   TRUE   String was inserted into queue
   \retval   FALSE  String was not inserted into queue
*/
/******************************************************************************/
extern bool_t Queue_InsertString(Queue_T *queue, const char *string);
/******************************************************************************/
/*!
   \brief    Insert string at end of queue with max string length
   \details  Insert `string` at end of `queue`, but limits the maximum number of
             characters inserted to `limit`
   \param    queue    Queue to insert element into
   \param    string   C string
   \param    limit    Maximum number of characters to insert
   \return   bool_t
   \retval   TRUE   String was inserted into queue
   \retval   FALSE  String was not inserted into queue
*/
/******************************************************************************/
extern bool_t Queue_InsertString_LimitedLength(Queue_T *queue, const char *string, Size_T limit);
/******************************************************************************/
/*!
   \brief    Get pointer to element on the front of the queue
   \details  Get pointer to `element` on the front of the `queue`
   \param    queue    Queue to get element from
   \param    element  Pointer to the element pointer
   \return   bool_t
   \retval   TRUE   Pointer to element is populated
   \retval   FALSE  Queue is empty
   \note     This function is the same as Queue_GetOffset, but with an offset
             of 0.
   \warning  This function assumes `element` is contiguous.  If the `queue` was
             not declared with the type of `element`, then you should declare a
             local variable of the correct type and use the Queue_CopyData
             function to copy the front `element` instead.
*/
/******************************************************************************/
extern bool_t Queue_GetFront(Queue_T * queue, PTR_TO_CONST(void, QUEUE_MEMORY_CLASS, DEFAULT_MEMORY_CLASS) *element);
/******************************************************************************/
/*!
   \brief    Get pointer to element at offset from the front of the queue
   \details  Get pointer to `element` at `offset` from the front of the `queue`
   \param    queue    Queue to get element from
   \param    element  Pointer to the element pointer
   \param    offset   Byte offset from front of queue
   \return   bool_t
   \retval   TRUE   Pointer to element is populated
   \retval   FALSE  Queue is empty
   \warning  This function assumes `element` is contiguous.  If the `queue` was
             not declared with the type of `element`, then you should declare a
             local variable of the correct type and use the Queue_CopyData
             function to copy the front `element` instead.
*/
/******************************************************************************/
extern bool_t Queue_GetOffset(Queue_T * queue, PTR_TO_CONST(void, QUEUE_MEMORY_CLASS, DEFAULT_MEMORY_CLASS) *element, Size_T offset);
/******************************************************************************/
/*!
   \brief    Copy data from front of queue into element
   \details  Copy `size` bytes of data from front of `queue` into `element`
   \param    queue    Queue to copy data from
   \param    element  Element to copy data to
   \param    size     SIZEOF(element)
   \return   bool_t
   \retval   TRUE   Data was copied into element
   \retval   FALSE  Queue does not contain a full element
   \note     This function is the same as Queue_CopyDataFromOffset, but with an
             offset of 0.
*/
/******************************************************************************/
extern bool_t Queue_CopyData(Queue_T * queue, PTR_TO_VAR(void, QUEUE_MEMORY_CLASS, DEFAULT_MEMORY_CLASS) element, Size_T size);
/******************************************************************************/
/*!
   \brief    Copy data from offset from front of queue into element
   \details  Copy `size` bytes of data into `element` from `offset` from front
             of `queue`
   \param    queue    Queue to copy data from
   \param    element  Element to copy data to
   \param    size     SIZEOF(element)
   \param    offset   Offset in queue to start from
   \return   bool_t
   \retval   TRUE   Data was copied into element
   \retval   FALSE  Queue does not contain a full element
*/
/******************************************************************************/
extern bool_t Queue_CopyDataFromOffset(Queue_T * queue, PTR_TO_VAR(void, QUEUE_MEMORY_CLASS, DEFAULT_MEMORY_CLASS) element, Size_T size, Size_T offset);
/******************************************************************************/
/*!
   \brief    Copy data from front of source queue into destination queue
   \details  Copy `size` bytes of data from front of 'source' queue into
             'destination' queue
   \param    source       Queue to copy data from
   \param    destination  Queue to copy data to
   \param    size         Number of bytes to copy
   \return   bool_t
   \retval   TRUE   Data was copied into destination queue
   \retval   FALSE  Data was not copied (either there isn't enough space in destination or not enough data in source)
*/
/******************************************************************************/
extern bool_t Queue_CopyDataToQueue(Queue_T * source, Queue_T * destination, Size_T size);
/******************************************************************************/
/*!
   \brief    Remove element from front of queue
   \details  Remove `size` bytes from front of `queue`
   \param    queue  Queue to remove from
   \param    size   Size of element(s) to remove
   \return   bool_t
   \retval   TRUE   Element(s) removed from buffer
   \retval   FALSE  The queue contains less bytes than you requested to remove
*/
/******************************************************************************/
extern bool_t Queue_Remove(Queue_T *queue, Size_T size);
//! Queue of arbitrary type and size
typedef struct InterruptQueue_S
{
   //! Priority of highest priority task that accesses this queue
   Mutex_T Mutex;
   //! Queue to wrap
   Queue_T Queue;
   //! Callback when first item is added
   ISOBUS_Callback_T *FirstItemCallback;
   //! Callback when queue becomes empty
   ISOBUS_Callback_T *EmptyQueueCallback;
   //! Callback when queue becomes full
   ISOBUS_Callback_T *FullQueueCallback;
} InterruptQueue_T;
/******************************************************************************/
/*!
   \brief    Create an interrupt queue object pointing to a queue array
   \details  This macro is used to create an interrupt queue object pointing to
             a queue array previously declared using the MAKE_QUEUE_ARRAY macro.
   \param    arrayname            Name of the queue array
   \param    first_item_callback  Callback to call whenever the queue becomes non-empty
   \param    empty_callback       Callback to call whenever the queue becomes empty
   \param    full_callback        Callback to call whenever the queue becomes full or an element cannot be added to the queue
   \param    priority             Priority level of highest priority task that accesses this interrupt queue
*/
/******************************************************************************/
#define MAKE_InterruptQueue_T(arrayname,first_item_callback,empty_callback,full_callback,priority) {MAKE_Mutex_T(priority), MAKE_Queue_T(arrayname, priority), first_item_callback, empty_callback, full_callback}
/******************************************************************************/
/*!
   \brief    Returns number of bytes available in the interrupt queue
   \param    interrupt_queue_ptr   Pointer to the interrupt queue object
*/
/******************************************************************************/
#define InterruptQueue_SpaceAvailable(interrupt_queue_ptr) ((interrupt_queue_ptr)->Queue.Size - (interrupt_queue_ptr)->Queue.Used)
/******************************************************************************/
/*!
   \brief    Initialize the queue
   \details  Empties the `queue` to prepare it for use.
   \param    queue  Interrupt queue to initialize
*/
/******************************************************************************/
extern void InterruptQueue_Init(InterruptQueue_T *queue);
/******************************************************************************/
/*!
   \brief    Initialize the queue using priority from another mutex
   \details  Empties the `queue` to prepare it for use.
   \param    queue            Interrupt queue to initialize
   \param    copy_from_mutex  Mutex to copy priority data from
*/
/******************************************************************************/
extern void InterruptQueue_CopyInit(InterruptQueue_T *queue, const Mutex_T *copy_from_mutex);
/******************************************************************************/
/*!
   \brief    Insert element at end of queue
   \details  Insert `element` of `size` at end of `queue`
   \param    queue    Queue to insert element into
   \param    element  Pointer to element to place in queue
   \param    size     Size of the element (using SIZEOF())
   \return   bool_t
   \retval   TRUE   Element was inserted into queue
   \retval   FALSE  Element was not inserted into queue
*/
/******************************************************************************/
extern bool_t InterruptQueue_Insert(InterruptQueue_T *queue, PTR_TO_CONST(void, QUEUE_MEMORY_CLASS, DEFAULT_MEMORY_CLASS) element, Size_T size);
/******************************************************************************/
/*!
   \brief    Get pointer to element on the front of the queue
   \details  Get pointer to `element` on the front of the `queue`
   \param    queue    Queue to get element from
   \param    element  Pointer to the element pointer
   \return   bool_t
   \retval   TRUE   Pointer to element is populated
   \retval   FALSE  Queue is empty
   \note     This function is the same as InterruptQueue_GetOffset, but with an offset
             of 0.
   \warning  This function assumes `element` is contiguous.  If the `queue` was
             not declared with the type of `element`, then you should declare a
             local variable of the correct type and use the InterruptQueue_CopyData
             function to copy the front `element` instead.
*/
/******************************************************************************/
#define InterruptQueue_GetFront(queue,element) Queue_GetFront(&(queue)->Queue, element)
/******************************************************************************/
/*!
   \details  Get pointer to `element` at `offset` from the front of the `queue`
   \param    queue    Queue to get element from
   \param    element  Pointer to the element pointer
   \param    offset   Byte offset from front of queue
   \return   bool_t
   \retval   TRUE   Pointer to element is populated
   \retval   FALSE  Queue is empty
   \warning  This function assumes `element` is contiguous.  If the `queue` was
             not declared with the type of `element`, then you should declare a
             local variable of the correct type and use the InterruptQueue_CopyData
             function to copy the front `element` instead.
*/
/******************************************************************************/
#define InterruptQueue_GetOffset(queue,element,offset) Queue_GetOffset(&(queue)->Queue,element,offset)
/******************************************************************************/
/*!
   \brief    Copy data from front of queue into element
   \details  Copy `size` bytes of data from front of `queue` into `element`
   \param    queue    Queue to copy data from
   \param    element  Element to copy data to
   \param    size     SIZEOF(element)
   \return   bool_t
   \retval   TRUE   Data was copied into element
   \retval   FALSE  Queue does not contain a full element
   \note     This function is the same as InterruptQueue_CopyDataFromOffset, but with an
             offset of 0.
*/
/******************************************************************************/
#define InterruptQueue_CopyData(queue,element,size) Queue_CopyData(&(queue)->Queue,element,size)
/******************************************************************************/
/*!
   \brief    Copy data from offset from front of queue into element
   \details  Copy `size` bytes of data into `element` from `offset` from front
             of `queue`
   \param    queue    Queue to copy data from
   \param    element  Element to copy data to
   \param    size     SIZEOF(element)
   \param    offset   Offset in queue to start from
   \return   bool_t
   \retval   TRUE   Data was copied into element
   \retval   FALSE  Queue does not contain a full element
*/
/******************************************************************************/
#define InterruptQueue_CopyDataFromOffset(queue,element,size,offset) Queue_CopyDataFromOffset(&(queue)->Queue,element,size,offset)
/******************************************************************************/
/*!
   \brief    Copy data from front of source queue into destination queue
   \details  Copy `size` bytes of data from front of 'source' queue into
             'destination' queue
   \param    source       Queue to copy data from
   \param    destination  Queue to copy data to
   \param    size         Number of bytes to copy
   \return   bool_t
   \retval   TRUE   Data was copied into destination queue
   \retval   FALSE  Data was not copied (either there isn't enough space in destination or not enough data in source)
*/
/******************************************************************************/
extern bool_t InterruptQueue_CopyDataToQueue(InterruptQueue_T * source, InterruptQueue_T * destination, Size_T size);
/******************************************************************************/
/*!
   \brief    Remove element from front of queue
   \details  Remove `size` bytes from front of `queue`
   \param    queue  Queue to remove from
   \param    size   Size of element(s) to remove
   \return   bool_t
   \retval   TRUE   Element(s) removed from buffer
   \retval   FALSE  The queue contains less bytes than you requested to remove
*/
/******************************************************************************/
extern bool_t InterruptQueue_Remove(InterruptQueue_T *queue, Size_T size);
//! Generic Pipe
typedef struct Pipe_S
{
   //! FIFO queue (acts as core of the pipe)
   Queue_T Queue;
   //! Indicates whether the read handle is open
   bool_t ReadOpen;
   //! Indicates whether the write handle is open
   bool_t WriteOpen;
} Pipe_T;
//! Type used to prevent writes to the read handle
typedef struct Pipe_ReadHandle_S
{
   //! Pointer to the pipe
   Pipe_T *Read;
} Pipe_ReadHandle_T;
//! Type used to prevent reads from the write handle
typedef struct Pipe_WriteHandle_S
{
   //! Pointer to the pipe
   Pipe_T *Write;
} Pipe_WriteHandle_T;
/******************************************************************************/
/*!
   \brief    Create a pipe array containing `size` elements of `type` (for use in a pipe)
   \param    arrayname  Name of the array
   \param    type       Data type of the array elements
   \param    size       Number of elements in the array
*/
/******************************************************************************/
#define MAKE_PIPE_ARRAY(arrayname,type,size) MAKE_QUEUE_ARRAY(arrayname,type,size)
/******************************************************************************/
/*!
   \brief    Create a pipe object pointing to a pipe array
   \details  This macro is used to create a pipe object pointing to a pipe
             array previously declared using the MAKE_PIPE_ARRAY macro.
   \param    arrayname  Name of the pipe array
   \param    priority   Priority level of highest priority task that accesses
                        this pipe
*/
/******************************************************************************/
#define MAKE_Pipe_T(arrayname,priority) { MAKE_Queue_T(arrayname,priority), FALSE, FALSE }
/******************************************************************************/
/*!
   \brief    Returns number of bytes in the pipe available to write
   \param    write_pipe   Write pipe handle
*/
/******************************************************************************/
#define Pipe_WriteSpaceAvailable(write_pipe) Queue_SpaceAvailable(&((write_pipe).Write->Queue))
/******************************************************************************/
/*!
   \brief    Returns number of bytes in the pipe available to read
   \param    read_pipe   Read pipe handle
*/
/******************************************************************************/
#define Pipe_ReadDataAvailable(read_pipe) ((read_pipe).Read->Queue.Used)
/******************************************************************************/
/*!
   \brief    Determine if the Read Handle is open on a pipe
   \param    pipe   Pointer to pipe
   \return  bool_t
   \retval  TRUE   Read handle is open
   \retval  FALSE  Read handle is closed
*/
/******************************************************************************/
#define Pipe_ReadIsOpen(pipe) ((pipe != (Pipe_T *)NULL) && (pipe->ReadOpen))
/******************************************************************************/
/*!
   \brief    Determine if the Write Handle is open on a pipe
   \param    pipe   Pointer to pipe
   \return  bool_t
   \retval  TRUE   Write handle is open
   \retval  FALSE  Write handle is closed
*/
/******************************************************************************/
#define Pipe_WriteIsOpen(pipe) ((pipe != (Pipe_T *)NULL) && (pipe->WriteOpen))
/******************************************************************************/
/*!
   \brief    Initialize the pipe
   \details  Empties the `pipe` to prepare it for use.
   \param    pipe  Pipe to initialize
*/
/******************************************************************************/
extern void Pipe_Init(Pipe_T *pipe);
/******************************************************************************/
/*!
   \brief    Initialize the pipe using priority from another mutex
   \details  Empties the `pipe` to prepare it for use.
   \param    pipe                Pipe to initialize
   \param    mutex_to_copy_from  Mutex to copy priority data from
*/
/******************************************************************************/
extern void Pipe_CopyInit(Pipe_T *pipe, const Mutex_T *mutex_to_copy_from);
/******************************************************************************/
/*!
   \brief    Open the pipe (returns read and write handle)
   \details  Open `pipe` for use
   \param    pipe          [In]  Pipe to open
   \param    write_handle  [Out] Write handle to pipe
   \param    read_handle   [Out] Read handle to pipe
   \return   bool_t
   \retval   TRUE   Pipe was opened
   \retval   FALSE  Pipe was not opened
*/
/******************************************************************************/
extern bool_t Pipe_Open(Pipe_T *pipe, Pipe_WriteHandle_T *write_handle, Pipe_ReadHandle_T *read_handle);
/******************************************************************************/
/*!
   \brief    Closes a Pipe Read handle
   \details  Close the Read Handle to the pipe
   \param    read_handle  Read handle to the pipe
   \return   bool_t
   \retval   TRUE   Handle was closed
   \retval   FALSE  Handle was not closed
   \note  The pipe is not considered closed until both the read and write
          handles are closed.
*/
/******************************************************************************/
extern void Pipe_CloseReadHandle(Pipe_ReadHandle_T *read_handle);
/******************************************************************************/
/*!
   \brief    Closes a Pipe Write handle
   \details  Close the Write Handle to the pipe
   \param    write_handle  Write handle to the pipe
   \return   bool_t
   \retval   TRUE   Handle was closed
   \retval   FALSE  Handle was not closed
   \note  The pipe is not considered closed until both the read and write
          handles are closed.
*/
/******************************************************************************/
extern void Pipe_CloseWriteHandle(Pipe_WriteHandle_T *write_handle);
//! Insert element at end of pipe
#define Pipe_Insert(pipe,element,size) Queue_Insert(&((pipe).Write->Queue), element, size)
//! Insert string at end of pipe
#define Pipe_InsertString(pipe,string) Queue_InsertString(&((pipe).Write->Queue), string)
//! Insert length-limited string at end of pipe
#define Pipe_InsertString_LimitedLength(pipe,string,limit) Queue_InsertString_LimitedLength(&((pipe).Write->Queue), string, limit)
//! Get pointer to element at the front of the pipe
#define Pipe_GetFront(pipe,element) Queue_GetFront(&((pipe).Read->Queue), element)
//! Get pointer to element at offset from the front of the pipe
#define Pipe_GetOffset(pipe,element,offset) Queue_GetOffset(&((pipe).Read->Queue), element, offset)
//! Copy data from front of pipe into element
#define Pipe_CopyData(pipe,element,size) Queue_CopyData(&((pipe).Read->Queue), element, size)
//! Copy data from offset from front of pipe into element
#define Pipe_CopyDataFromOffset(pipe,element,size,offset) Queue_CopyDataFromOffset(&((pipe).Read->Queue), element, size, offset)
//! Copy data from front of source pipe into destination pipe
#define Pipe_CopyDataToPipe(source,destination,size) Queue_CopyDataToQueue(&((source).Read->Queue), &((destination).Write->Queue), size)
//! Remove element from front of pipe
#define Pipe_Remove(pipe,size) Queue_Remove(&((pipe).Read->Queue), size)
//! Structure for storing a user-defined collection of pipes
typedef struct Pipes_S
{
   //! Mutex priority to use for pipe collection
   Mutex_T Mutex;
   //! Number of pipes in this collection
   Size_T NumberOfPipes;
   //! Collection (array) of pipes
   Pipe_T * const Collection;
} Pipes_T;
/******************************************************************************/
/*!
   \brief    Create a Pipe Collection object pointing to an array of pipes
   \details  This macro is used to create a Pipe Collection object pointing to
             a previously declared array of pipes.
   \param    pipe_arrayname  Name of the array of pipes
   \param    priority        Maximum priority task that accesses this structure
*/
/******************************************************************************/
#define MAKE_Pipes_T(pipe_arrayname,priority) { MAKE_Mutex_T(priority), sizeof(pipe_arrayname)/sizeof(Pipe_T), pipe_arrayname }
/******************************************************************************/
/*!
   \brief    Initialize the pipe collection
   \details  Initializes all pipes in the collection to empty.
   \param    pipes  Collection of pipes to initialize
*/
/******************************************************************************/
extern void Pipes_Init(Pipes_T *pipes);
/******************************************************************************/
/*!
   \brief    Open the pipe (returns read and write handle)
   \details  Open `pipe` for use
   \param    pipes         [In]  Collection of pipes to choose from
   \param    write_handle  [Out] Write handle to pipe
   \param    read_handle   [Out] Read handle to pipe
   \param    min_size      [In]  Minimum size of the pipe
   \return   bool_t
   \retval   TRUE   Pipe was opened
   \retval   FALSE  Pipe was not opened
*/
/******************************************************************************/
extern bool_t Pipes_OpenFromCollection(const Pipes_T *pipes, Pipe_WriteHandle_T *write_handle, Pipe_ReadHandle_T *read_handle, Size_T min_size);
// Generic values for 8-bit signal
//! 8-bit Parameter-specific indicator
#define SIGNAL_1_BYTE_PARAMETER_SPECIFIC_INDICATOR ((ISOBUS_PacketData_T)0xFB)
//! 8-bit Error Indicator
#define SIGNAL_1_BYTE_ERROR_INDICATOR ((ISOBUS_PacketData_T)0xFE)
//! 8-bit Not available, not installed, or not requested
#define SIGNAL_1_BYTE_NOT_AVAILABLE ((ISOBUS_PacketData_T)0xFF)
// Generic values for 16-bit signal
//! 16-bit Parameter-specific indicator
#define SIGNAL_2_BYTE_PARAMETER_SPECIFIC_INDICATOR(x) ((ISOBUS_PacketData_T)(0xFB00 | ((x) & 0xFF)))
//! 16-bit Error Indicator
#define SIGNAL_2_BYTE_ERROR_INDICATOR(x) ((ISOBUS_PacketData_T)(0xFE00 | ((x) & 0xFF)))
//! 16-bit Not available, not installed, or not requested
#define SIGNAL_2_BYTE_NOT_AVAILABLE(x) ((ISOBUS_PacketData_T)(0xFF00 | ((x) & 0xFF)))
// Generic values for 32-bit signal
//! 32-bit Parameter-specific indicator
#define SIGNAL_4_BYTE_PARAMETER_SPECIFIC_INDICATOR(x) ((ISOBUS_PacketData_T)(0xFB000000 | ((x) & 0xFFFFFF)))
//! 32-bit Error Indicator
#define SIGNAL_4_BYTE_ERROR_INDICATOR(x) ((ISOBUS_PacketData_T)(0xFE000000 | ((x) & 0xFFFFFF)))
//! 32-bit Not available, not installed, or not requested
#define SIGNAL_4_BYTE_NOT_AVAILABLE(x) ((ISOBUS_PacketData_T)(0xFF000000 | ((x) & 0xFFFFFF)))
// Generic values for ASCII signal
//! ASCII Not available, not installed, or not requested
#define SIGNAL_ASCII_NOT_AVAILABLE 0xFF
//! Type used to identify the NameTableIndex
typedef uint8_t NameTableIndex_T;
//! Type used to identify a SourceAddress
typedef uint8_t SourceAddress_T;
//! Type used for 29-bit CAN packet identifier
typedef uint32_t CAN_Identifier_T;
//! Type used for packet Priority
typedef uint8_t ISOBUS_PacketPriority_T;
//! Type used for packet/message DataPage and Parameter Group Number
typedef uint32_t ISOBUS_PGN_T;
//! Type used for packet/message Data Length Code
typedef uint32_t ISOBUS_DLC_T;
//! Type used for packet/message Data
typedef MinAddressable_T ISOBUS_PacketData_T;
//! Type used to specify a Group function (Command/Parameter)
typedef uint8_t ISOBUS_GroupFunction_T;
//! PGN value used to indicate that we want some logic to apply to every PGN
#define EVERY_PGN ((ISOBUS_PGN_T)0xFFFFFFFF)
//! This enum is used to identify whether an ISOBUS packet/message is being sent or received by the CAN hardware
typedef enum ISOBUS_Direction_E
{
   //! ISOBUS packet is received by the CAN hardware
   ISOBUS_RX,
   //! ISOBUS packet is sent by the CAN hardware
   ISOBUS_TX
} ISOBUS_Direction_T;
//! This structure defines the 29-bit identifier (with a few additional pieces of information).
typedef struct CAN_PacketHeader_S
{
   //! 29-bit Identifier
   CAN_Identifier_T Identifier;
   //! Transmitted or Received?
   ISOBUS_Direction_T Direction;
} CAN_PacketHeader_T;
//! This structure represents a single CAN packet
typedef struct CAN_Packet_S
{
   //! Packet header representing 29-bit identifier
   CAN_PacketHeader_T Header;
   //! Data Length Code - Representing the number of data bytes in the Data portion
   ISOBUS_DLC_T DLC;
   //! Up to 8 bytes of data
   ISOBUS_PacketData_T Data[8];
} CAN_Packet_T;
//! This structure defines the ISOBUS translation of the 29-bit identifier (with a few additional pieces of information).
typedef struct ISOBUS_PacketHeader_S
{
   //! Parameter Group Number
   ISOBUS_PGN_T PGN;
   //! Destination Address
   SourceAddress_T DestinationAddress;
   //! Destination Name Table Index
   NameTableIndex_T Destination;
   //! Source Address
   SourceAddress_T SourceAddress;
   //! Source Name Table Index
   NameTableIndex_T Source;
   //! Transmitted or Received?
   ISOBUS_Direction_T Direction;
   //! This is used to optimize packet transfer in a system
   ISOBUS_PacketPriority_T Priority;
} ISOBUS_PacketHeader_T;
//! This structure represents a single ISOBUS packet
typedef struct ISOBUS_Packet_S
{
   //! Packet header representing 29-bit identifier
   ISOBUS_PacketHeader_T Header;
   //! Data Length Code - Representing the number of data bytes in the Data portion
   ISOBUS_DLC_T DLC;
   //! Up to 8 bytes of data
   ISOBUS_PacketData_T Data[8];
} ISOBUS_Packet_T;
//! This structure is used for reading/writing from/to memory
typedef struct Memory_S
{
   //! Function pointer to read
   bool_t (*Read)(Pipe_WriteHandle_T destination, const MemoryPointer_T *source, Size_T size, const ISOBUS_Callback_T *callback);
   //! Function pointer to write
   bool_t (*Write)(const MemoryPointer_T *destination, Pipe_ReadHandle_T source, Size_T size, const ISOBUS_Callback_T *callback);
} Memory_T;
/******************************************************************************/
/*!
   \brief    Macro used to initialize an Memory_T structure.
   \param    read   Generic function to read arbitrary memory locations/devices
   \param    write  Generic function to write arbitrary memory locations/devices
*/
/******************************************************************************/
#define MAKE_Memory_T(read,write) {read, write}
//! Type for storing a 64-bit ISOBUS NAME
typedef ISOBUS_PacketData_T ISOBUS_Name_T[8];
//! Type for storing a manufacturer code from an ISOBUS_Name
typedef uint16_t ISOBUS_ManufacturerCode_T;
//! Type for storing the identity number from an ISOBUS_Name
typedef uint32_t ISOBUS_IdentityNumber_T;
/******************************************************************************/
/*!
   \brief    Macro used to initialize the ISOBUS_Name_T type.
   \param  self_configurable      Indicates whether a Control Function is self-configurable (1) or not (0)
   \param  industry_group         Defined and assigned by ISO, identifies NAMEs associated with industries (e.g. agricultural equipment)
   \param  device_class_instance  Indicates occurrence of a particular device class in a connected network; definition depends on industry group field contents
   \param  device_class           Defined and assigned by ISO; provides a common NAME for a group of functions within a connected network; when combined with an industry group, can be correlated to a common NAME, e.g "planter" with "agricultural equipment"
   \param  function               Defined and assigned by ISO; when value between 0 and 127, independent of any other field for definition; when > 127 but < 254, definition depends on device class; when combined with industry group and device class, can be correlated to a common NAME for specific CF, though not implying any specific capabilities
   \param  function_instance      Indicates specific occurrence of a function on a particular device system of a network
   \param  ecu_instance           Indicates which of a group of ECUs associated with a given function is referenced
   \param  manufacturer_code      Assigned by committee (see ISO 11783-1); indicates manufacturer of ECU for which the NAME is being referenced; independent of any other NAME field
   \param  identity_number        Assigned by the ECU manufacturer
*/
/******************************************************************************/
#define MAKE_ISOBUS_Name_T(self_configurable,industry_group,device_class_instance,device_class,function,function_instance,ecu_instance,manufacturer_code,identity_number) \
 { (ISOBUS_PacketData_T)(identity_number & 0xFF), \
 (ISOBUS_PacketData_T)((identity_number >> 8) & 0xFF), \
 (ISOBUS_PacketData_T)((((manufacturer_code << 5) & 0xE0) | ((identity_number >> 16) & 0x1F)) & 0xFF), \
 (ISOBUS_PacketData_T)((manufacturer_code >> 3) & 0xFF), \
 (ISOBUS_PacketData_T)((((function_instance << 3) & 0xF8) | (ecu_instance & 0x07)) & 0xFF), \
 (ISOBUS_PacketData_T)(function & 0xFF), \
 (ISOBUS_PacketData_T)((device_class << 1) & 0xFE), \
 (ISOBUS_PacketData_T)(((((self_configurable) << 7) & 0x80) | ((industry_group << 4) & 0x70) | (device_class_instance & 0x0F)) & 0xFF) \
 }
/******************************************************************************/
/*!
   \brief    Macro used to extract the `Self Configurable` field from the ISOBUS_Name_T type.
   \param  name  ISOBUS_Name_T of the Control Function
*/
/******************************************************************************/
#define ISOBUS_Name_GetSelfConfigurable(name) (((name)[7] & (ISOBUS_PacketData_T)0x80) >> (ISOBUS_PacketData_T)7)
/******************************************************************************/
/*!
   \brief    Macro used to extract the `Industry Group` field from the ISOBUS_Name_T type.
   \param  name  ISOBUS_Name_T of the Control Function
*/
/******************************************************************************/
#define ISOBUS_Name_GetIndustryGroup(name) (((name)[7] & (ISOBUS_PacketData_T)0x70) >> (ISOBUS_PacketData_T)4)
/******************************************************************************/
/*!
   \brief    Macro used to extract the `Device Class Instance` field from the ISOBUS_Name_T type.
   \param  name  ISOBUS_Name_T of the Control Function
*/
/******************************************************************************/
#define ISOBUS_Name_GetDeviceClassInstance(name) ((name)[7] & (ISOBUS_PacketData_T)0x0F)
/******************************************************************************/
/*!
   \brief    Macro used to extract the `Device Class` field from the ISOBUS_Name_T type.
   \param  name  ISOBUS_Name_T of the Control Function
*/
/******************************************************************************/
#define ISOBUS_Name_GetDeviceClass(name) (((name)[6] & (ISOBUS_PacketData_T)0xFE) >> (ISOBUS_PacketData_T)1)
/******************************************************************************/
/*!
   \brief    Macro used to extract the `Function` field from the ISOBUS_Name_T type.
   \param  name  ISOBUS_Name_T of the Control Function
*/
/******************************************************************************/
#define ISOBUS_Name_GetFunction(name) ((name)[5])
/******************************************************************************/
/*!
   \brief    Macro used to extract the `Function Instance` field from the ISOBUS_Name_T type.
   \param  name  ISOBUS_Name_T of the Control Function
*/
/******************************************************************************/
#define ISOBUS_Name_GetFunctionInstance(name) (((name)[4] & (ISOBUS_PacketData_T)0xF8) >> (ISOBUS_PacketData_T)3)
/******************************************************************************/
/*!
   \brief    Macro used to extract the `ECU Instance` field from the ISOBUS_Name_T type.
   \param  name  ISOBUS_Name_T of the Control Function
*/
/******************************************************************************/
#define ISOBUS_Name_GetEcuInstance(name) ((name)[4] & (ISOBUS_PacketData_T)0x07)
/******************************************************************************/
/*!
   \brief    Macro used to extract the `Manufacturer Code` field from the ISOBUS_Name_T type.
   \param  name  ISOBUS_Name_T of the Control Function
   \return  ISOBUS_ManufacturerCode_T
*/
/******************************************************************************/
extern ISOBUS_ManufacturerCode_T ISOBUS_Name_GetManufacturerCode(const ISOBUS_Name_T name);
/******************************************************************************/
/*!
   \brief    Macro used to extract the `Identity Number` field from the ISOBUS_Name_T type.
   \param  name  ISOBUS_Name_T of the Control Function
   \return  ISOBUS_IdentityNumber_T
*/
/******************************************************************************/
extern ISOBUS_IdentityNumber_T ISOBUS_Name_GetIdentityNumber(const ISOBUS_Name_T name);
// Include structures from header files related to Foundation Functionality
//! enum list of the Address Claim States
typedef enum AddressClaim_State_E
{
   //! Wait until claim is sent
   AddressClaim_WaitSendClaim,
   //! Wait for address contention
   AddressClaim_WaitContention,
   //! Have claimed an address with no contention
   AddressClaim_HaveAddress,
   //! Address claim has failed, can't claim an address
   AddressClaim_CannotClaim
} AddressClaim_State_T;
//! enum list of the Send Address Claim States
typedef enum AddressClaim_MessageState_E
{
   //! Wait until Pseudorandom delay has passed
   AddressClaim_PseudoRandomDelay,
   //! Queue an address claim
   AddressClaim_QueueClaim,
   //! Address claim queued -- wait until sent
   AddressClaim_ClaimQueued,
   //! Do nothing...
   AddressClaim_Idle
} AddressClaim_MessageState_T;
/******************************************************************************/
/*!
   \brief    Macro used to initialize an ISOBUS_AddressClaim_S structure
   \details  This macro is used to create an ISOBUS_AddressClaim_T data structure
   \param    sa_primary           Primary application source address
   \param    choose_sa_fn         Function pointer to choose next source address (NULL to use built-in function)
   \param    priority             Priority of calling function
*/
/******************************************************************************/
#define MAKE_ISOBUS_AddressClaim_S(sa_primary,choose_sa_fn,priority) { MAKE_Mutex_T(priority), (SourceAddress_T)sa_primary, (SourceAddress_T)sa_primary, (SourceAddress_T)sa_primary, choose_sa_fn, GLOBAL_DEST, TIMER_EXPIRED, MAKE_SoftwareTimer_T(), FALSE, AddressClaim_WaitSendClaim, AddressClaim_PseudoRandomDelay, (SourceAddress_T)GLOBAL_DA }
/******************************************************************************/
//! Type for storing ISOBUS Compliance Certification data
typedef ISOBUS_PacketData_T ISOBUS_Certification_T[8];
/******************************************************************************/
/*!
   \brief    Macro used to initialize the ISOBUS_Certification_T type.
   \param  year              Year of the compliance test protocol to which the certification test was performed
   \param  rev               Revision of the compliance test performed.  In years where there are multiple revisions of the test protocol, an alphabetic suffix is used in addition to the certification year.
   \param  lab_id            Manufacturer code of the laboratory that performed the compliance test.  In the case of a self-certified ECU, this matches the manufacturer code contained in the address claim PGN.  The value of this parameter is assigned by committee.
   \param  lab_type          Approving body for the certification laboratory (3-bits)
                                000 - Non-certified laboratory/self-certification
                                001 - European Union certified laboratory
                                010 - North American certified laboratory
                                111 - Not available (not certified)
   \param  reference_number  Certification reference number assigned by a certification laboratory.  This value can be used together with the Certification Lab ID and ECU Manufacturer ID to uniquely identify the test file of the certification laboratory.
   \param  min_ecu           Indicates whether the Minimum ECU compliance test was performed
   \param  tecu_1            Indicates whether the TECU Class 1 compliance test was performed
   \param  tecu_2            Indicates whether the TECU Class 2 compliance test was performed
   \param  tecu_3            Indicates whether the TECU Class 3 compliance test was performed
   \param  class3_ecu        Indicates whether the Class 3 ECU compliance test was performed
   \param  virtual_terminal  Indicates whether the Virtual Terminal compliance test was performed
   \param  vt_ws_master      Indicates whether the VT Working Set Master compliance test was performed
   \param  vt_ws_member      Indicates whether the VT Working Set Member compliance test was performed
   \param  task_controller   Indicates whether the Task Controller compliance test was performed
   \param  tc_ws_master      Indicates whether the TC Working Set Master compliance test was performed
   \param  tc_ws_member      Indicates whether the TC Working Set Member compliance test was performed
   \param  file_server       Indicates whether the File Server compliance test was performed
   \param  gps_receiver      Indicates whether the GPS Receiver compliance test was performed
*/
/******************************************************************************/
#define MAKE_ISOBUS_Certification_T(year,rev,lab_id,lab_type,reference_number,min_ecu,tecu_1,tecu_2,tecu_3,class3_ecu,virtual_terminal,vt_ws_master,vt_ws_member,task_controller,tc_ws_master,tc_ws_member,file_server,gps_receiver) \
 { \
 /* Byte 1 */ \
 (ISOBUS_PacketData_T)((((rev) & 0x03) << 6) | \
 (((year) & 0x3F) << 0)), \
 /* Byte 2 */ \
 (ISOBUS_PacketData_T)((((lab_id) & 0x0007) << 5) | \
 (((lab_type) & 0x07) << 1) | \
 (((rev) & 0x04) >> 2)), \
 /* Byte 3 */ \
 (ISOBUS_PacketData_T)(((lab_id) & 0x07F8) >> 3), \
 /* Byte 4 */ \
 (ISOBUS_PacketData_T)((((min_ecu) & 0x01) << 7) | \
 (((tecu_1) & 0x01) << 6) | \
 (((tecu_2) & 0x01) << 5) | \
 (((tecu_3) & 0x01) << 4) | \
 (((class3_ecu) & 0x01) << 3) | \
 (((virtual_terminal) & 0x01) << 2) | \
 (((vt_ws_master) & 0x01) << 1) | \
 (((vt_ws_member) & 0x01) << 0)), \
 /* Byte 5 */ \
 (ISOBUS_PacketData_T)((((task_controller) & 0x01) << 7) | \
 (((tc_ws_master) & 0x01) << 6) | \
 (((tc_ws_member) & 0x01) << 5) | \
 (((file_server) & 0x01) << 4) | \
 (((gps_receiver) & 0x01) << 3)), \
 /* Byte 6 */ \
 (ISOBUS_PacketData_T)(0), \
 /* Byte 7 */ \
 (ISOBUS_PacketData_T)((reference_number) & 0xFF), \
 /* Byte 8 */ \
 (ISOBUS_PacketData_T)(((reference_number) >> 8) & 0xFF) \
 }
//! NULL Source Address (used when not claimed or cannot claim)
#define NULL_SA (SourceAddress_T)0xFE
//! Source Address used when a control function cannot claim
#define CANNOT_CLAIM_SA NULL_SA
//! Global Destination address
#define GLOBAL_DA (SourceAddress_T)0xFF
//! NULL Name Index (used when a control function cannot claim)
#define NULL_SOURCE (NameTableIndex_T)0xFE
//! Global Destination name index
#define GLOBAL_DEST (NameTableIndex_T)0xFF
//! NULL index (represents unused)
#define SA_UNUSED (NameTableIndex_T)0xFF
//! NAME Table State information
typedef enum NameTable_State_E
{
   NT_INIT,
   NT_SEND_AC_REQUEST,
   NT_AC_REQUEST_SENT,
   NT_WAIT_AC,
   NT_POPULATED
} NameTable_State_T;
//! Name Table entry structure
typedef struct NameTableEntry_S
{
    //! Eight byte array to hold the CAN Name
    ISOBUS_Name_T Name;
    //! Source Address claimed by this table entry
    SourceAddress_T SA;
    //! Working Set index of this table entry
    NameTableIndex_T WS_index;
} NameTableEntry_T;
//! Type for tracking info for specific NameTable entries (Max 256 entries)
typedef uint32_t NameTableIndex_Bitfield_T;
//! Structure for tracking NameTable updates after request for address claim
typedef struct NameTable_UpdateTracker_S
{
   //! Timer to commit NameTable update
   SoftwareTimer_T Timer;
   //! Boolean flag to indicate whether this is tracking any changes
   bool_t IsTracking;
   //! Bitfield representing claimed NameTableIndices
   NameTableIndex_Bitfield_T ClaimedIndexes[8];
} NameTable_UpdateTracker_T;
//! Macro for initializing the NameTable_UpdateTracker_T structure
#define MAKE_NameTable_UpdateTracker_T() { MAKE_SoftwareTimer_T(), FALSE, { (NameTableIndex_Bitfield_T)0, (NameTableIndex_Bitfield_T)0, (NameTableIndex_Bitfield_T)0, (NameTableIndex_Bitfield_T)0, (NameTableIndex_Bitfield_T)0, (NameTableIndex_Bitfield_T)0, (NameTableIndex_Bitfield_T)0, (NameTableIndex_Bitfield_T)0 } }
//! Name Table structure
typedef struct NameTable_S
{
   //! Pointer to the SoftwareTimerList used by this NameTable
   SoftwareTimerList_T *TimerList;
   //! Boolean flag indicating whether or not the table is populated
   bool_t Populated;
   //! State information for Name Table processing
   NameTable_State_T State;
   //! Oldest Request for Address Claim being tracked for NameTable update
   NameTable_UpdateTracker_T OldestTracker;
   //! Newest Request for Address Claim being tracked for NameTable update
   NameTable_UpdateTracker_T NewestTracker;
   //! Highest priority task that accesses the this structure
   Mutex_T Mutex;
   //! Name Table timer
   SoftwareTimer_T Timer;
   //! Maximum number of entries this Name Table can hold
   NameTableIndex_T Size;
   //! Pointer to the Name Table entry array
   NameTableEntry_T *NameTableEntries;
   //! Array to translate Source Address to the Name Table index
   NameTableIndex_T SA2NameTableIndex[254];
} NameTable_T;
/******************************************************************************/
/*!
   \brief    Macro used to initialize an NameTable structure.
   \details  This macro is used to create an NameTable_T data structure.
   \param    name_table_entries  Name of array of NAME Table entries
   \param    timer_list          Name of SoftwareTimerList_T
   \param    priority            Ceiling priority of tasks using the NAME table
*/
/******************************************************************************/
#define MAKE_NameTable_T(name_table_entries,timer_list,priority) { &timer_list, FALSE, NT_INIT, MAKE_NameTable_UpdateTracker_T(), MAKE_NameTable_UpdateTracker_T(), MAKE_Mutex_T(priority), MAKE_SoftwareTimer_T(), (NameTableIndex_T)(sizeof(name_table_entries)/sizeof(NameTableEntry_T)), name_table_entries, {0} }
//! Structure for registering a packet handler with a network
typedef struct Network_PacketHandler_S
{
   //! Member for registering in linked list
   struct LinkedList_Node_S LinkedList_Node;
   //! Packet Handler
   void (*PacketHandler)(const ISOBUS_Packet_T *packet, struct Network_PacketHandler_S *handler_info);
   //! Pointer to arbitrary data for use by callback
   void *Pointer_1;
   //! Pointer to arbitrary data for use by callback
   const void *Pointer_2;
} Network_PacketHandler_T;
/******************************************************************************/
/*!
   \brief    Macro used to create a Network_PacketHandler_T
   \details  This macro is used to create a Network_PacketHandler_T structure
             used to register a packet handler.
   \param    handler  Function name of packet handler to register
*/
/******************************************************************************/
#define MAKE_Network_PacketHandler_T(handler) {MAKE_LinkedList_Node_S(NULL), handler, NULL, NULL}
/******************************************************************************/
/*!
   \brief    Macro used to create a Network_PacketHandlerList_T
   \details  This macro is used to create a Network_PacketHandlerList_T
             structure which contains a list of registered packet handlers.
   \param    priority  Priority of highest priority task that accesses this
                       list or any registered nodes
*/
/******************************************************************************/
#define MAKE_Network_PacketHandlerList_T(priority) MAKE_LinkedList_List_S(priority)
/******************************************************************************/
/*!
   \brief  Macro used to initialize a struct Foundation_PacketHandler_Node_S
   \param  queue_ptr      Pointer to optional Queue_T structure (NULL = no queue)
   \param  global_filter  Global filter applied to all packets received by this Foundation structure
   \param  priority       Highest priority of the tasks that access this structure
*/
/******************************************************************************/
#define MAKE_Foundation_PacketHandler_List_S(queue_ptr,global_filter,priority) {MAKE_Network_PacketHandler_T(NULL), MAKE_LinkedList_List_S(priority), global_filter, queue_ptr}
//! Type used to store packet numbers
typedef uint32_t ISOBUS_PacketSequence_T;
//! Type used to store packet numbers
typedef uint8_t ISOBUS_TransportRetry_T;
//! This structure represents a single ISOBUS message
typedef struct ISOBUS_Message_S
{
   //! Packet/Message header representing 29-bit identifier
   ISOBUS_PacketHeader_T Header;
   //! Data Length Code - Representing the total number of data bytes
   ISOBUS_DLC_T DLC;
   //! Message Data
   Pipe_ReadHandle_T Data;
} ISOBUS_Message_T;
//! This enumeration defines the events for the MessageEventHandler
typedef enum ISOBUS_MessageEvent_E
{
   //! The message transfer has begun and a pipe is allocated
   MESSAGE_INITIATED,
   //! The message transfer is stalled waiting for pipe space
   MESSAGE_PIPE_FULL,
   //! The message transfer is stalled waiting for data to send
   MESSAGE_PIPE_EMPTY,
   //! The message transfer has been completed
   MESSAGE_COMPLETE,
   //! The message transfer has been aborted
   MESSAGE_ABORTED
} ISOBUS_MessageEvent_T;
//! Defines the values used in byte 2 of the TP.Conn_Abort message
typedef enum ISOBUS_TransportAbortReason_E
{
   //! Already in one or more connection-managed sessions and cannot support another
   TP_CANNOT_SUPPORT_SESSION = 1,
   //! System resources were needed for another task so this connection managed session was terminated
   TP_SESSION_TERMINATED_FOR_RESOURCES = 2,
   //! A timeout occurred and this is the connection abort to close the session
   TP_TIMEOUT = 3,
   //! Parameter-specific indicator
   TP_PARAMETER_SPECIFIC_INDICATOR = 251,
   //! Error indicator
   TP_ERROR_INDICATOR = 254,
   //! Not available, not installed or not requested
   TP_NOT_AVAILABLE = 255
} ISOBUS_TransportAbortReason_T;
//! Defines the protocols implemented in the Transport layer
typedef enum ISOBUS_TransportProtocol_E
{
   // Single Packet                (    0 -           8 bytes)
   TRANSPORT_SP,
   // Transport Protocol           (    9 -       1,785 bytes)
   TRANSPORT_TP,
   // Transport Protocol Broadcast (    9 -       1,785 bytes)
   TRANSPORT_TP_BAM,
   // Extended Transport Protocol  (1,786 - 117,440,512 bytes)
   TRANSPORT_ETP
} ISOBUS_TransportProtocol_T;
//! This enumeration defines the basic states of the Transport layer
typedef enum ISOBUS_TransportState_E
{
   //! The transport session is closed.
   TRANSPORT_CLOSED,
   //! The transport session is open on the bus
   TRANSPORT_OPEN
} ISOBUS_TransportState_T;
//! This enumeration defines the sub-states of the Transport layer
typedef enum ISOBUS_TransportSubstate_E
{
   // *** Global TP sub-states ***
   // Puts TP.CM_BAM packet on the CAN hardware to send
   TRANSPORT_SEND_BAM,
   // Waiting for TP.CM_BAM packet to actually be transmitted on bus
   TRANSPORT_BAM_SENT,
   // *** DA specific ETP sub-states ***
   // Puts ETP.CM_RTS packet on the CAN hardware to send
   TRANSPORT_SEND_RTS,
   // Waiting for ETP.CM_RTS packet to actually be transmitted on bus
   TRANSPORT_RTS_SENT,
   // Waiting to receive ETP.CM_CTS packet from other node
   TRANSPORT_WAIT_CTS,
   // Puts ETP.CM_CTS packet on the CAN hardware to send
   TRANSPORT_SEND_CTS,
   // Waiting for ETP.CM_CTS packet to actually be transmitted on bus
   TRANSPORT_CTS_SENT,
   // Puts ETP.CM_DPO packet on the CAN hardware to send
   TRANSPORT_SEND_DPO,
   // Waiting for ETP.CM_DPO packet to actually be transmitted on bus
   TRANSPORT_DPO_SENT,
   // Waiting to receive ETP.DT packet from other node
   TRANSPORT_WAIT_DT,
   // Puts ETP.DT packet on the CAN hardware to send
   TRANSPORT_SEND_DT,
   // Waiting for ETP.DT packet to actually be transmitted on bus
   TRANSPORT_DT_SENT,
   // Waiting to receive ETP.CM_EndofMsgACK packet from other node
   TRANSPORT_WAIT_EOM,
   // Puts ETP.CM_EndofMsgACK packet on the CAN hardware to send
   TRANSPORT_SEND_EOM,
   // Waiting for ETP.CM_EndofMsgACK packet to actually be transmitted on bus
   TRANSPORT_EOM_SENT,
   // Puts ETP.Conn_Abort packet on the CAN hardware to send
   TRANSPORT_SEND_ABORT
} ISOBUS_TransportSubstate_T;
//! This structure is used to notify a module when a packet has been sent
typedef struct ISOBUS_MessageCallback_S
{
   //! Callback function pointer
   void (*Function)(const struct ISOBUS_MessageCallback_S *pointer, ISOBUS_MessageEvent_T event);
   //! Pointer to arbitrary data for use by callback
   void *Pointer_1;
   //! Pointer to arbitrary data for use by callback
   const void *Pointer_2;
} ISOBUS_MessageCallback_T;
//! Function pointer type for ISOBUS Message Event Handlers
typedef void (*ISOBUS_MessageEventHandler_T)(ISOBUS_Message_T *message, ISOBUS_MessageEvent_T event, void *instance);
//! Structure containing state information for a single transport session
typedef struct ISOBUS_TransportSession_S
{
   //! Message being processed
   ISOBUS_Message_T Message;
   //! Callback function (Tx messages only)
   ISOBUS_MessageCallback_T Callback;
   //! Function pointer to MessageEventHandler (Rx messages only)
   ISOBUS_MessageEventHandler_T MessageEventHandler;
   //! Pointer to the corresponding registered message/event handler
   void* MessageEventInstance;
   //! Pipe handle to write received data
   Pipe_WriteHandle_T WritePipe;
   //! Timer used for timeouts and delays (depending on state)
   SoftwareTimer_T Timer;
   //! Protocol used by this session
   ISOBUS_TransportProtocol_T Protocol;
   //! General state of this session
   ISOBUS_TransportState_T State;
   //! Specific state of this session
   ISOBUS_TransportSubstate_T Substate;
   //! Session Mutex
   Mutex_T Mutex;
   //! Max number of packets per CTS (from RTS message)
   ISOBUS_PacketSequence_T MaxPktsPerCTS;
   //! PGN to use for Connection Management
   ISOBUS_PGN_T CM_PGN;
   //! PGN to use for Data Transfer
   ISOBUS_PGN_T DT_PGN;
   //! DataPage and PGN packaged in the order used in transport messages
   ISOBUS_PacketData_T PGN[3];
   //! Next Packet number expected on bus (send or receive)
   ISOBUS_PacketSequence_T NextPacket;
   //! First packet number from last CTS
   ISOBUS_PacketSequence_T CTS_NextPacket;
   //! Last packet number removed from the pipe (send only)
   ISOBUS_PacketSequence_T LastAckedPacket;
   //! Current Data Packet Offset
   ISOBUS_PacketSequence_T DPO;
   //! Number of remaining DPO packets
   ISOBUS_PacketSequence_T RemainingDPO_Packets;
   //! Number cleared-to-send from last CTS
   ISOBUS_PacketSequence_T NumClearedToSend;
   //! Number of times this session has already been retried
   ISOBUS_TransportRetry_T NumRetries;
   //! Indicates the reason for an abort
   ISOBUS_TransportAbortReason_T AbortReason;
} ISOBUS_TransportSession_T;
//! Structure containing state information for all transport sessions
typedef struct ISOBUS_Transport_S
{
   //! Mutex containing priority used for all sessions
   Mutex_T Mutex;
   //! Maximum number of simultaneous transport session supported
   const Size_T MaxSessions;
   //! Maximum number of times to retry for dropped packets
   ISOBUS_TransportRetry_T MaxRetries;
   //! Max number of packets per CTS (from RTS message)
   ISOBUS_PacketSequence_T DefaultMaxPktsPerCTS;
   //! Pointer to array of transport sessions
   ISOBUS_TransportSession_T * const Sessions;
   //! Collection of pipes for Rx messages
   Pipes_T * const RxPipes;
   //! Linked list containing registered Message/Event handlers
   struct LinkedList_List_S MessageHandler_LinkedList;
} ISOBUS_Transport_T;
/******************************************************************************/
/*!
   \brief    Macro used to initialize an ISOBUS_Transport_T
   \details  This macro is used to create a ISOBUS_Transport_T that uses an
             array of transport sessions previously declared using the
             MAKE_TRANSPORT_SESSION macro.
   \param    priority             Maximum priority task that accesses this structure
   \param    max_retries          Maximum number of times to retry a single
                                  transport session (standard recommends 2)
   \param    max_packets_per_cts  Maximum number of data packets that can be
                                  sent in response to a single CTS (standard
                                  recommends 16).  This is also the maximum
                                  number of packets that can be re-requested.
   \param    tp_sessions          Name of the array of transport sessions
   \param    tp_pipes             Name of the pipe collection
*/
/******************************************************************************/
#define MAKE_ISOBUS_Transport_T(priority,max_retries,max_packets_per_cts,tp_sessions,tp_pipes) { MAKE_Mutex_T(priority), sizeof(tp_sessions)/sizeof(ISOBUS_TransportSession_T), (ISOBUS_TransportRetry_T)max_retries, (ISOBUS_PacketSequence_T)max_packets_per_cts, tp_sessions, &tp_pipes, MAKE_LinkedList_List_S(priority) }
/******************************************************************************/
//! This structure contains information required to register Request PGN handlers
struct Request_S
{
   //! Linked List of Request PGN handlers
   struct LinkedList_List_S LinkedList;
};
/******************************************************************************/
/*!
   \brief  Macro used to initialize a struct Request_S
   \param  priority  Highest priority of the tasks that access this structure
*/
/******************************************************************************/
#define MAKE_Request_S(priority) {MAKE_LinkedList_List_S(priority)}
//! Structure to register an Request PGN handler
struct Request_Node_S
{
   //! PGN being Requested
   ISOBUS_PGN_T PGN;
   //! Function handling the Request that passes the (DataPage, PGN, Group) filter
   void (*RequestHandler)(const ISOBUS_Packet_T *, const struct Request_Node_S *);
   //! Pointer to arbitrary data (provided by module registering the node)
   void *Pointer_1;
   //! Pointer to arbitrary const data (provided by module registering the node)
   const void *Pointer_2;
   //! Linked List node
   struct LinkedList_Node_S LinkedList_Node;
};
/******************************************************************************/
/*!
   \brief  Macro used to initialize a struct Request_Node_S
   \param  pgn              PGN of requested message to handle
   \param  handler          Function handling the request message
   \param  pointer1         Pointer to arbitrary data that is useful to handler
   \param  pointer2         Pointer to arbitrary const data that is useful to handler
*/
/******************************************************************************/
#define MAKE_Request_Node_S(pgn,handler,pointer1,pointer2) {pgn, handler, pointer1, pointer2, MAKE_LinkedList_Node_S(NULL)}
//! This enum defines an Ack, Nack, Denied, or No reply
typedef enum ISOBUS_AcknowledgeResponse_E
{
   //! send Positive Acknowledgement (ACK)
   ACKNOWLEDGE_Positive,
   //! send Negative Acknowledgement (NACK)
   ACKNOWLEDGE_Negative,
   //! send Access Denied (PGN supported but security denied access)
   ACKNOWLEDGE_Access_Denied,
   //! send Cannot Respond (PGN supported but ECU is busy and cannot respond now,
   //!  re-request the data at a later time)
   ACKNOWLEDGE_Cannot_Respond
} ISOBUS_AcknowledgeResponse_T;
//! This structure contains information required to register Acknowledge PGN handlers
struct Acknowledge_S
{
   //! Linked List of Acknowledge PGN handlers
   struct LinkedList_List_S LinkedList;
};
/******************************************************************************/
/*!
   \brief  Macro used to initialize a struct Acknowledge_S
   \param  priority  Highest priority of the tasks that access this structure
*/
/******************************************************************************/
#define MAKE_Acknowledge_S(priority) {MAKE_LinkedList_List_S(priority)}
//! Structure to register an Acknowledge PGN handler
struct Acknowledge_Node_S
{
   //! PGN being Acknowledged
   ISOBUS_PGN_T PGN;
   //! Filter by "Group Function" (TRUE=filter, FALSE=don't filter)
   bool_t FilterByGroup;
   //! Group Function being Acknowledged (if FilterByGroup == TRUE)
   ISOBUS_GroupFunction_T Group;
   //! Function handling the Acknowledge that passes the (DataPage, PGN, Group) filter
   void (*AcknowledgeHandler)(const ISOBUS_Packet_T *, const struct Acknowledge_Node_S *);
   //! Pointer to arbitrary data (provided by module registering the node)
   void *Pointer_1;
   //! Pointer to arbitrary const data (provided by module registering the node)
   const void *Pointer_2;
   //! Linked List node
   struct LinkedList_Node_S LinkedList_Node;
};
/******************************************************************************/
/*!
   \brief  Macro used to initialize a struct Acknowledge_Node_S
   \param  pgn              PGN of acknowledged message to handle
   \param  filter_by_group  Filter by Group Function (TRUE=filter, FALSE=don't filter)
   \param  group            Group Function of acknowledged message (if relevant)
   \param  handler          Function handling the acknowledge message
   \param  pointer1         Pointer to arbitrary data that is useful to handler
   \param  pointer2         Pointer to arbitrary const data that is useful to handler
*/
/******************************************************************************/
#define MAKE_Acknowledge_Node_S(pgn,filter_by_group,group,handler,pointer1,pointer2) {pgn, filter_by_group, group, handler, pointer1, pointer2, MAKE_LinkedList_Node_S(NULL)}
//! Determines whether a point or a comma will be displayed as the decimal symbol
typedef enum DecimalSymbol_E
{
   //! Decimal point is a Comma
   DecimalSymbol_Comma = 0,
   //! Decimal point is a Point
   DecimalSymbol_Point = 1,
   DecimalSymbol_Reserved = 2,
   DecimalSymbol_NoAction = 3
} DecimalSymbol_T;
//! Specifies the displayed format of the time
typedef enum TimeFormat_E
{
   //! 24-hour time format
   TimeFormat_24h = 0,
   //! 12-hour time format
   TimeFormat_12h = 1,
   TimeFormat_Reserved = 2,
   TimeFormat_NoAction = 3
} TimeFormat_T;
//! Specifies the displayed format of the data
typedef enum DateFormat_E
{
   //! Day Month Year format
   DateFormat_ddmmyyyy = 0,
   //! Day Year Month format
   DateFormat_ddyyyymm = 1,
   //! Month Year Day format
   DateFormat_mmyyyydd = 2,
   //! Month Day Year format
   DateFormat_mmddyyyy = 3,
   //! Year Month Day format
   DateFormat_yyyymmdd = 4,
   //! Year Day Month format
   DateFormat_yyyyddmm = 5
} DateFormat_T;
//! Specifies the displayed format of the data
typedef enum UnitsOfMeasure_E
{
   //! Use metric units
   Units_Metric = 0,
   //! Use imperial units
   Units_Imperial = 1,
   //! Use US units
   Units_US = 2,
   Units_NoAction = 3
} UnitsOfMeasure_T;
//! Information for fields of Language Command message
typedef struct Language_S
{
   //! Two character string country codes in accordance with ISO 639
   char LanguageCode[3];
   //! Character used for decimal
   DecimalSymbol_T DecimalSymbol;
   //! Time format
   TimeFormat_T TimeFormat;
   //! Date format
   DateFormat_T DateFormat;
   //! Units used for Distance
   UnitsOfMeasure_T DistanceUnits;
   //! Units used for Area
   UnitsOfMeasure_T AreaUnits;
   //! Units used for Volume
   UnitsOfMeasure_T VolumeUnits;
   //! Units used for Mass
   UnitsOfMeasure_T MassUnits;
   //! Units used for Temperature
   UnitsOfMeasure_T TemperatureUnits;
   //! Units used for Pressure
   UnitsOfMeasure_T PressureUnits;
   //! Units used for Force
   UnitsOfMeasure_T ForceUnits;
   //! General units system to use
   UnitsOfMeasure_T UnitsSystem;
} Language_T;
/******************************************************************************/
/*!
   \brief    Macro used to initialize the Language_T type.
   \param  language_code   Character string representing the language code (example: "en")
   \param  decimal_symbol  Value from `DecimalSymbol_T` indicating the decimal symbol
   \param  time_format     Value from `TimeFormat_T` indicating the time format
   \param  date_format     Value from `DateFormat_T` indicating the date format
   \param  distance        Value from `UnitsOfMeasure_T` indicating the units system for distance
   \param  area            Value from `UnitsOfMeasure_T` indicating the units system for area
   \param  volume          Value from `UnitsOfMeasure_T` indicating the units system for volume
   \param  mass            Value from `UnitsOfMeasure_T` indicating the units system for mass
   \param  temperature     Value from `UnitsOfMeasure_T` indicating the units system for temperature
   \param  pressure        Value from `UnitsOfMeasure_T` indicating the units system for pressure
   \param  force           Value from `UnitsOfMeasure_T` indicating the units system for force
   \param  general_units   Value from `UnitsOfMeasure_T` indicating the units system for general_units
*/
/******************************************************************************/
#define MAKE_Language_T(language_code,decimal_symbol,time_format,date_format,distance,area,volume,mass,temperature,pressure,force,general_units) {language_code, decimal_symbol, time_format, date_format, distance, area, volume, mass, temperature, pressure, force, general_units}
//! Structure for registering Language command callback
typedef struct LanguageCallback_S
{
   //! Linked List structure to make this a registerable node
   struct LinkedList_Node_S LinkedList_Node;
   //! Callback function pointer
   void (*Function)(const struct LanguageCallback_S *, const Language_T *, const NameTableIndex_T sa);
   //! Pointer to arbitrary data for use by callback
   const void *Pointer_1;
   //! Pointer to arbitrary data for use by callback
   void *Pointer_2;
} LanguageCallback_T;
/******************************************************************************/
/*!
   \brief    Macro used to initialize a LanguageCallback_T
   \details  This macro is used to create a LanguageCallback_T.
*/
/******************************************************************************/
#define MAKE_LanguageCallback_T() {MAKE_LinkedList_Node_S(NULL), NULL, NULL, NULL}
//! Language Callback list
typedef struct LanguageCallbackList_T
{
   //! Linked list for holding `LanguageCallback_T`s
   struct LinkedList_List_S LinkedList;
} LanguageCallbackList_T;
/******************************************************************************/
/*!
   \brief    Macro used to initialize a LanguageCallbackList_T
   \details  This macro is used to create a LanguageCallbackList_T.
   \param    priority  Ceiling priority of tasks that access this LanguageCallbackList_T
*/
/******************************************************************************/
#define MAKE_LanguageCallbackList_T(priority) {MAKE_LinkedList_List_S(priority)}
/******************************************************************************/
//! Information for fields of ECU ID message
typedef struct EcuIdFields_S
{
   //! The part number of the physical ECU connected to the ISO 11783 network.  This parameter is the same as SPN 2901 as defined in SAE J1939-71.
   const char *PartNumber;
   //! The serial number of the physical ECU connected to the ISO 11783 network.  This parameter is the same as SPN 2902 as defined in SAE J1939-71.
   const char *SerialNumber;
   //! The location on a tractor or implement of the physical ECU connected to the ISO 11783 network.  This parameter is the same as SPN 2903 as defined in SAE J1939-71.
   const char *Location;
   //! The type of the physical ECU connected to the ISO 11783 network.  An example of an ECU type is the classification of ECU capabilities such as I/O.  This parameter is the same as SPN 2904 as defined in J1939-71.
   const char *Type;
   //! The manufacturer name is a human-readable string that can be interpreted by a service technician.  The same text as registered with the manufacturer code can be used and may contain branding information as well.  It may contain the manufacturer's name as well as the OEM integrator.  This information aids the service technician to acquire service help.
   const char *ManufacturerName;
   //! The Hardware Version ID  provides information to describe ECU hardware versions on the ISO 11783 network.
   //! \note  This should match the AEF assigned ID in the AEF database.
   const char *HardwareVersionID;
} EcuIdFields_T;
//! ECU ID states
typedef enum EcuIdState_E
{
   ECUID_IDLE,
   ECUID_SEND_FIELD,
   ECUID_SEND_TERMINATOR,
   ECUID_WAIT_COMPLETE
} EcuIdState_T;
//! ECU ID substates
typedef enum EcuIdSubstate_E
{
   ECUID_SEND_PARTNUMBER,
   ECUID_SEND_SERIALNUMBER,
   ECUID_SEND_LOCATION,
   ECUID_SEND_TYPE,
   ECUID_SEND_MANUFACTURERNAME,
   ECUID_SEND_HARDWAREVERSIONID,
   NUM_ECUID_DELIMITERS
} EcuIdSubstate_T;
//! All information required for ECU ID
typedef struct EcuId_S
{
   //! ECU ID state information
   EcuIdState_T State;
   //! ECU ID substate information
   EcuIdSubstate_T Substate;
   //! Mutex to prevent parallel access issues
   Mutex_T Mutex;
   //! Pipe handle to write ECU ID data into
   Pipe_WriteHandle_T WritePipe;
   //! Pointer to the strings used in the ECU ID
   EcuIdFields_T *Fields;
} ISOBUS_EcuId_T;
/******************************************************************************/
/*!
   \brief    Macro used to initialize an ISOBUS_EcuId_T structure.
   \param    priority  Ceiling priority of tasks that access this structure.
   \param    fields    Name of the ECU ID fields (EcuIdFields_T) structure.
*/
/******************************************************************************/
#define MAKE_ISOBUS_EcuId_T(priority,fields) {ECUID_IDLE, ECUID_SEND_PARTNUMBER, MAKE_Mutex_T(priority), {NULL}, &fields}
/******************************************************************************/
//! Software ID states
typedef enum SoftwareIdState_E
{
   SWID_IDLE,
   SWID_SEND_COUNT,
   SWID_SEND_STRING,
   SWID_WAIT_COMPLETE
} SoftwareIdState_T;
//! This structure is used to register Software IDs
typedef struct SoftwareId_S
{
   //! Member for registering in linked list
   struct LinkedList_Node_S LinkedList_Node;
   //! Pointer to the applications software ID string
   const char *String;
   //! Size of the SW ID message (in 8-bit bytes)
   const Size_T Size;
} SoftwareId_T;
//! Information required for the Software ID list
typedef struct SoftwareIdList_S
{
   //! Member to allow LinkedList_Node_S to be registered
   struct LinkedList_List_S LinkedList;
   //! SwID_List entries
   Size_T Count;
   //! Size of all SwID message (in 8-bit bytes)
   Size_T MsgSize;
} SoftwareIdList_T;
//! All information required for Software ID
typedef struct ISOBUS_SoftwareId_S
{
   //! SwID state information
   SoftwareIdState_T State;
   //! Mutex to prevent parallel access issues
   Mutex_T Mutex;
   //! Pipe handle to write SwID data into
   Pipe_WriteHandle_T WritePipe;
   //! Pointer to last SoftwareId_T structure serviced
   struct LinkedList_Node_S *Last;
   //! Pointer to the ISOBUS_SwID_List_T structure
   SoftwareIdList_T *SwList;
} ISOBUS_SoftwareId_T;
/******************************************************************************/
/*!
   \brief    Macro used to initialize an SoftwareId_T structure.
   \details  *String initialized to pointer to a string.
             Size    initialized to size of string.
             *Next   initialized to NULL
*/
/******************************************************************************/
#define MAKE_SoftwareId_T(string) {MAKE_LinkedList_Node_S(NULL), string, (sizeof(string))-1}
/******************************************************************************/
/*!
   \brief    Macro used to initialize an ISOBUS_SoftwareId_T structure.
   \details  State      initialized to SWID_IDLE.
             Mutex      initialized to "priority".
             *WritePipe initialized to NULL.
             *Last      initialized to NULL.
             *SwList    initialized to "list" (address of SwID list structure)
   \param    priority  Ceiling priority of tasks that access this structure.
   \param    list      Address of the SwID list (SoftwareIdList_T) structure.
*/
/******************************************************************************/
#define MAKE_ISOBUS_SoftwareId_T(priority,list) {SWID_IDLE,MAKE_Mutex_T(priority),{NULL},NULL,&list}
/******************************************************************************/
//! Information for fields of Product ID message
typedef struct ProductIdFields_S
{
   //! The product ID code of the physical ECU connected to the ISO 11783 network.
   const char *Code;
   //! The product brand name of the physical ECU connected to the ISO 11783 network.
   const char *Brand;
   //! The product model number of the physical ECU connected to the ISO 11783 network.
   const char *Model;
} ProductIdFields_T;
//! Product ID states
typedef enum ProductIdState_E
{
   PRODUCTID_IDLE,
   PRODUCTID_SEND_FIELD,
   PRODUCTID_SEND_TERMINATOR,
   PRODUCTID_WAIT_COMPLETE
} ProductIdState_T;
//! Product ID substates
typedef enum ProductIdSubstate_E
{
   PRODUCTID_SEND_ID_CODE,
   PRODUCTID_SEND_ID_BRAND,
   PRODUCTID_SEND_ID_MODEL,
   NUM_PRODUCTID_DELIMITERS
} ProductIdSubstate_T;
//! All information required for Product ID
typedef struct ProductId_S
{
   //! Product ID state information
   ProductIdState_T State;
   //! Product ID substate information
   ProductIdSubstate_T Substate;
   //! Mutex to prevent parallel access issues
   Mutex_T Mutex;
   //! Pipe handle to write Product ID data into
   Pipe_WriteHandle_T WritePipe;
   //! Pointer to the strings used in the Product ID
   ProductIdFields_T *Fields;
} ISOBUS_ProductId_T;
/******************************************************************************/
/*!
   \brief    Macro used to initialize an ISOBUS_ProductId_T structure.
   \details  State      initialized to PRODUCTID_IDLE.
             Substate  initialized to PRODUCTID_SEND_PARTNUMBER.
             Mutex      initialized to "priority".
             *WritePipe initialized to NULL.
             *Fields    initialized to "fields" (address of ProductId array of strings)
   \param    priority  Ceiling priority of tasks that access this structure.
   \param    fields    Address of the ProductID list (SoftwareIdList_T) structure.
*/
/******************************************************************************/
#define MAKE_ISOBUS_ProductId_T(priority,fields) {PRODUCTID_IDLE, PRODUCTID_SEND_ID_CODE, MAKE_Mutex_T(priority), {NULL}, &fields}
/******************************************************************************/
//! ECU Diagnostic protocol identification
typedef uint8_t EcuDiagnosticProtocolId_T;
//! Supports diagnostics as specified in ISO 11783-12:2009(E)
#define ECU_DIAGNOSTICS_ISO_11783_LEVEL_1 ((EcuDiagnosticProtocolId_T) 0x00)
//! Supports J1939-73 diagnostics
#define ECU_DIAGNOSTICS_J1939_73 ((EcuDiagnosticProtocolId_T) 0x01)
//! Supports ISO 14230 diagnostics (KWP 2000 over K line)
#define ECU_DIAGNOSTICS_ISO_14230 ((EcuDiagnosticProtocolId_T) 0x02)
//! Supports ISO 15765-3 diagnostics (UDS on CAN)
#define ECU_DIAGNOSTICS_ISO_15765_3 ((EcuDiagnosticProtocolId_T) 0x04)
//! Supports additional proprietary diagnostics
#define ECU_DIAGNOSTICS_ISO_11783_LEVEL_2 ((EcuDiagnosticProtocolId_T) 0x08)
//! All information required for diagnostic service.
typedef struct Diagnostic_S
{
   //! Diagnostic Protocol state information
   EcuDiagnosticProtocolId_T Protocol;
} ISOBUS_DiagnosticProtocol_T;
/******************************************************************************/
/*!
   \brief    Macro used to initialize an ISOBUS_DiagnosticProtocol_T
   \details  This macro is used to create a ISOBUS_DiagnosticProtocol_T,
   \param    protocol  Selected ECU diagnostic protocol enumeration.
   \param    priority  Ceiling priority of tasks that access this SoftwareTimer
*/
/******************************************************************************/
#define MAKE_ISOBUS_DiagnosticProtocol_T(protocol,priority) {protocol}
//! Type used for a 3-byte representation of the SPN.FMI of a DTC.  On a little-endian CPU, this data is packed as it is represented in the DM1/DM2 message.
typedef uint32_t DTC_T;
/******************************************************************************/
/*!
   \brief    Macro used to create a DTC
   \details  This macro create the fixed portion of the DTC information.
   \param  spn  Suspect Parameter Number used for this DTC
   \param  fmi  Failure Mode Indicator used for this DTC
*/
/******************************************************************************/
#define MAKE_DTC_T(spn,fmi) ((DTC_T)(((spn) & 0xFFFF) | (((spn) & 0x070000) << 5) | ((fmi) << 16)))
//! Type used to represent the number of occurrences of a particular DTC fault mode
typedef uint8_t DTC_OccurrenceCount_T;
//! When the occurrence count is not available, it shall be set to 0x7F
#define DTC_OCCURRENCE_COUNT_NOT_AVAILABLE ((DTC_OccurrenceCount_T)0x7F)
//! This structure is used for diagnostic trouble codes (DTCs)
typedef struct DTC_Status_S
{
   //! Flag to indicate an active DTC
   bool_t IsActive;
   //! Counter for the number of times this DTC failure mode has occurred
   DTC_OccurrenceCount_T OccurrenceCount;
} DTC_Status_T;
//! Type used for the index within the DTC array
typedef uint16_t DTC_Index_T;
//! This structure is for a list of DTCs
typedef struct DTC_List_S
{
   //! Pointer to the array of SPN/FMI information
   const DTC_T *DTC_Array;
   //! Pointer to the corresponding array of active/count information
   DTC_Status_T *DTC_Status;
   //! Total number of DTCs that are tracked
   const DTC_Index_T NumberOfDTCs;
   //! Number of currently active DTCs
   DTC_Index_T NumberOfActiveDTCs;
   //! Number of previously active DTCs
   DTC_Index_T NumberOfPreviouslyActiveDTCs;
   //! Mutex for protecting the DTC list
   Mutex_T Mutex;
   //! Software timer used to periodically send DM1
   SoftwareTimer_T DM1_Timer;
} DTC_List_T;
/******************************************************************************/
/*!
   \brief    Macro used to create the DTC_List_T
   \param  dtc_array         Array name for SPN/FMI information
   \param  dtc_status_array  Array name for active/count information
   \param  priority          Maximum task priority accessing DTCs
*/
/******************************************************************************/
#define MAKE_DTC_List_T(dtc_array,dtc_status_array,priority) {dtc_array, dtc_status_array, (DTC_Index_T)(sizeof(dtc_array)/sizeof(DTC_T)), (DTC_Index_T)0, (DTC_Index_T)0, MAKE_Mutex_T(priority), MAKE_SoftwareTimer_T()}
/******************************************************************************/
//! Type identifying the Functionality
typedef enum Functionality_E
{
   //! Functionality - Minimum control function
   Functionality_MinimumControlFunction = 0,
   //! Functionality - Universal terminal (server)
   Functionality_UniversalTerminal = 1,
   //! Functionality - Universal terminal working set (client)
   Functionality_UniversalTerminal_WorkingSet = 2,
   //! Functionality - Aux-O inputs
   Functionality_Aux_O_Inputs = 3,
   //! Functionality - Aux-O functions
   Functionality_Aux_O_Functions = 4,
   //! Functionality - Aux-N inputs
   Functionality_Aux_N_Inputs = 5,
   //! Functionality - Aux-N functions
   Functionality_Aux_N_Functions = 6,
   //! Functionality - Task controller basic (server)
   Functionality_TaskController_Basic = 7,
   //! Functionality - Task controller basic working set (client)
   Functionality_TaskController_Basic_WorkingSet = 8,
   //! Functionality - Task controller geo (server)
   Functionality_TaskController_Geo = 9,
   //! Functionality - Task controller geo working set (client)
   Functionality_TaskController_Geo_WorkingSet = 10,
   //! Functionality - Task controller section control (server)
   Functionality_TaskController_SectionControl = 11,
   //! Functionality - Task controller section control working set (client)
   Functionality_TaskController_SectionControl_WorkingSet = 12,
   //! Functionality - Basic Tractor ECU (server)
   Functionality_BasicTractorEcu = 13,
   //! Functionality - Basic Tractor ECU implement set (client)
   Functionality_BasicTractorEcu_ImplementSet = 14
} Functionality_T;
//! Type for storing Functionality Generation
typedef uint8_t FunctionalityGeneration_T;
//! Type for storing Functionality options
typedef ISOBUS_PacketData_T FunctionalityOptions_T[2];
//! Functionality data item for the functionality message
typedef struct Functionalities_S
{
   //! The functionality type
   Functionality_T Functionality;
   //! The generation of this functionality
   FunctionalityGeneration_T Generation;
   //! The number of options supported for this functionality
   Size_T NumberOfOptionBytes;
   //! List of options supported for this functionality
   FunctionalityOptions_T Options;
} Functionalities_T;
/******************************************************************************/
/*!
   \brief  Initializes the Functionalities_T structure
   \param  functionality     Functionality (from Functionality_T enum)
   \param  generation        Generation of this functionality
   \param  num_option_bytes  Number of option bytes for this functionality
   \param  options_byte1     Option byte 1 for this functionality
   \param  options_byte2     Option byte 2 for this functionality
*/
/******************************************************************************/
#define MAKE_Functionalities_T(functionality,generation,num_option_bytes,options_byte1,options_byte2) { functionality, generation, num_option_bytes, { options_byte1, options_byte2 } }
/******************************************************************************/
/*!
   \brief  Initializes the Functionalities_T structure for a Minimum Control
           Function
*/
/******************************************************************************/
#define MAKE_Functionalities_T__MinimumControlFunction() MAKE_Functionalities_T ( Functionality_MinimumControlFunction, (FunctionalityGeneration_T)1, (Size_T)0, (ISOBUS_PacketData_T)0x00, (ISOBUS_PacketData_T)0x00 )
//! Stores state for Functionalities message
typedef struct ISOBUS_Functionalities_S
{
   //! Mutex to prevent parallel access issues
   Mutex_T Mutex;
   //! Number of Functionalities
   Size_T NumberOfFunctionalities;
   //! Linked list of Functionalities
   Functionalities_T const *List;
} ISOBUS_Functionalities_T;
/******************************************************************************/
/*!
   \brief    Macro used to initialize an ISOBUS_Functionalities_T structure.
   \param    priority         Ceiling priority of tasks that access this structure.
   \param    functionalities  Array of Functionalities_T
*/
/******************************************************************************/
#define MAKE_ISOBUS_Functionalities_T(priority,functionalities) {MAKE_Mutex_T(priority), sizeof(functionalities)/sizeof(Functionalities_T), functionalities}
/******************************************************************************/
/******************************************************************************/
//! Contains all Network/CAN bus information
typedef struct Network_S
{
   //! List of packet handlers for apps attached to this CAN network
   struct LinkedList_List_S PacketHandlers;
   //! NAME Table for this CAN network
   NameTable_T NameTable;
   //! Function pointer to the SendPacket function for this CAN bus
   bool_t (*SendPacket)(const CAN_Packet_T*, const ISOBUS_Callback_T *);
} Network_T;
//! Contains all Foundation Functionality information for an ISOBUS App
typedef struct Foundation_S
{
   //! Pointer to the SoftwareTimerList used by this App
   SoftwareTimerList_T *TimerList;
   //! Pointer to the Network used by this App
   Network_T *Network;
   //! Address Claim data structure
   struct ISOBUS_AddressClaim_S
   {
      /*! Mutex to ensure data integrity of this structure */
      Mutex_T Mutex;
      /*! Current Source Address */
      SourceAddress_T CurrentSA;
      /*! Initial Source Address (Last successfully claimed address) */
      SourceAddress_T InitialSA;
      /*! Primary desired Source Address */
      SourceAddress_T PrimarySA;
      /*! \brief    Find the next available Source Address */
      /*! \details  First tries the InitialSA, then the PrimarySA, then others in a proprietary order.  If left NULL, VIRTEC will provide default functionality in the range 128-247 inclusive. */
      /*! \param    foundation  Pointer to App Foundation_T structure */
      /*! \return  SourceAddress_T */
      /*! \retval  NULL_SA  No available addresses */
      SourceAddress_T (*ChooseSourceAddress)(const struct Foundation_S *foundation);
      /*! Index of entry in Name Table (Valid when State == AC_Claimed) */
      NameTableIndex_T NameIndex;
      /*! Pseudorandom delay period (to avoid collisions) */
      Time_T RTxD;
      /*! Software timer used by the send Address Claim state controller */
      SoftwareTimer_T Timer;
      /*! Boolean value indicating whether the NAME table was populated */
      bool_t WasNameTablePopulated;
      /*! Current Address Claim state */
      AddressClaim_State_T State;
      /*! Current state of the send Address Claim controller */
      AddressClaim_MessageState_T ClaimState;
      /*! Number of pending claim echoes */
      SourceAddress_T LastClaimedAddress;
   } AddressClaim; //!< Address Claim data structure used by this App
   //! 8 byte array to hold the CAN Name for this application
   ISOBUS_Name_T Name;
   //! Transport Protocol structure (including Extended TP)
   ISOBUS_Transport_T Transport;
   //! Linked list of callbacks
   LanguageCallbackList_T LanguageCallbackList;
   //! ECU ID structure
   ISOBUS_EcuId_T ECU_ID;
   //! SW ID structure
   ISOBUS_SoftwareId_T SW_ID;
   //! Product ID structure
   ISOBUS_ProductId_T Product_ID;
   //! Diagnostics services structure
   ISOBUS_DiagnosticProtocol_T Diagnostics;
   //! DTC List structure
   DTC_List_T DTCs;
   //! Functionalities services structure
   ISOBUS_Functionalities_T Functionalities;
   //! ISOBUS Compliance Certification message
   ISOBUS_Certification_T Certification;
   //! Memory function pointer structure
   Memory_T Memory;
   //! Packet Handler list
   struct Foundation_PacketHandler_List_S
   {
      /*! Node used to register a Foundation structure to receive packets from a given network */
      Network_PacketHandler_T Network_PacketHandler_Node;
      /*! Linked list holding packet handlers for this Foundation structure */
      struct LinkedList_List_S LinkedList;
      /*! Global filter applied to all packets received by this Foundation structure */
      bool_t (*GlobalFilter)(const ISOBUS_Packet_T *packet, const struct Foundation_S *foundation);
      /*! Optional queue of ISOBUS_Packet_T for buffering incoming packets */
      /*! \note Purpose is to lower packet processing priority from interrupt level to task level */
      Queue_T *Queue;
   } PacketHandlers; //!< Packet Handler list used by this App
   //! Request packet handlers
   struct Request_S Request;
   //! Acknowledgement packet handlers
   struct Acknowledge_S Acknowledge;
} Foundation_T;
/******************************************************************************/
/*!
   \brief    Macro used to initialize the Foundation_T type.
   \param  sw_timer_list           Pointer to the SoftwareTimerList used by this App
   \param  network                 Pointer to the Network used by this App
   \param  addressclaim            Address Claim data structure for this App
   \param  name                    8 byte array to hold the CAN Name for this application
   \param  transport               Transport Protocol structure (including Extended TP)
   \param  language_callbacklist   Linked list of callbacks
   \param  ecu_id                  ECU ID structure
   \param  software_id             SW ID structure
   \param  product_id              Product ID structure
   \param  diagnostics             Diagnostics services structure
   \param  dtc_list                List of DTCs
   \param  functionalities         Functionalities services structure
   \param  certification           Certification structure
   \param  memory                  Memory function pointer structure
   \param  packet_handlers         Allows registration of packet handlers
   \param  request                 Allows registration of Request handlers
   \param  acknowledge             Allows registration of Acknowledgement handlers
*/
/******************************************************************************/
#define MAKE_Foundation_T(sw_timer_list,network,addressclaim,name,transport,language_callbacklist,ecu_id,software_id,product_id,diagnostics,dtc_list,functionalities,certification,memory,packet_handlers,request,acknowledge) {sw_timer_list, network, addressclaim, name, transport, language_callbacklist, ecu_id, software_id, product_id, diagnostics, dtc_list, functionalities, certification, memory, packet_handlers, request, acknowledge}
/******************************************************************************/
// Include externs from header files related to Foundation Functionality
// *** User Interface ***
/******************************************************************************/
/*!
   \brief    API indicating whether the application has an address
   \details  Indicates that the application has claimed an address and is
             permitted to actively participate (send messages) on the bus.
   \param    foundation  Pointer to App Foundation_T structure
   \return  bool_t
   \retval  TRUE   The application may send messages
   \retval  FALSE  The application may not send messages
*/
/******************************************************************************/
extern bool_t AddressClaim_IsClaimed(const Foundation_T *foundation);
/******************************************************************************/
/*!
   \brief    Default function for choosing the next available source address to claim
   \details  First tries the InitialSA, then the PrimarySA, then the MinimumSA
             to Maximum if the NAME indicates self-configurable.
   \param    foundation  Pointer to App Foundation_T structure
   \return  SourceAddress_T
   \retval  NULL_SA  No available addresses
*/
/******************************************************************************/
extern SourceAddress_T AddressClaim_ChooseSA(const Foundation_T *foundation);
/******************************************************************************/
/*!
   \details  Initializes the Name Table
   \param    network  Network containing the NAME table
*/
/******************************************************************************/
extern void NameTable_Init(Network_T *network);
/******************************************************************************/
/*!
   \brief    Name Table state machine
   \details  Task to populate the Name Table upon starting CAN communication.
   \param    network  Network containing the NAME table
*/
/******************************************************************************/
extern void NameTable_Task(Network_T *network);
/******************************************************************************/
/*!
   \brief    Logs NameTable related information into the name table
   \details  Packet Handler to track address claim and working set messages
   \param    packet      Packet Information
   \param    network     Network containing the NAME table
*/
/******************************************************************************/
extern void NameTable_PacketHandler(const CAN_Packet_T *packet, Network_T *network);
/******************************************************************************/
/*!
   \brief    Indicate when the Address Claim process has completed
   \details  Returns whether the NAME table is populated
   \param    network  Network containing the NAME table
   \return  bool_t
   \retval  TRUE   Name Table is populated
   \retval  FALSE  Name Table is not populated
*/
/******************************************************************************/
extern bool_t NameTable_Populated(const Network_T *network);
/******************************************************************************/
/*!
   \brief    Translates a NAME to the corresponding NAME Table index
   \details  Finds the name table index for the supplied NAME
   \param    network           [in]  Network containing the NAME table
   \param    name              [in]  8-byte NAME to search for
   \param    name_table_index  [out] NameTableIndex of name
   \return  bool_t
   \retval  TRUE   The NAME is in the table (a claim was received) and the name_table_index has been updated with the index
   \retval  FALSE  The NAME is not in the table (not claimed)
*/
/******************************************************************************/
extern bool_t NameTable_NameToNameTableIndex(Network_T *network, const ISOBUS_Name_T name, NameTableIndex_T *name_table_index);
/******************************************************************************/
/*!
   \brief    Translates a NAME to a NAME Table index matching the NAME/mask
   \details  Finds the name table index for the supplied NAME
   \param    network           [in]  Network containing the NAME table
   \param    name              [in]  8-byte NAME to search for
   \param    mask              [in]  8-byte mask indicating the significant bits
                                     (1=significant, 0=ignore)
   \param    name_table_index  [out] NameTableIndex of a name/mask match
   \return  bool_t
   \retval  TRUE   A matching NAME is in the table and the name_table_index has been updated with the index (or next matching index)
   \retval  FALSE  No matching NAMEs are found in the table
*/
/******************************************************************************/
extern bool_t NameTable_NameMaskToNameTableIndex(Network_T *network, const ISOBUS_Name_T name, const ISOBUS_Name_T mask, NameTableIndex_T *name_table_index);
/******************************************************************************/
/*!
   \brief    Translates a Source Address to the corresponding NAME Table index
   \details  Finds the name table index for the supplied source address
   \param    network           [in]  Network containing the NAME table
   \param    address           [in]  Source Address to search for
   \param    name_table_index  [out] NameTableIndex of name
   \return  bool_t
   \retval  TRUE   The source address is in the table (a claim was received) and the name_table_index has been updated with the index
   \retval  FALSE  The source address is not in the table (not claimed)
*/
/******************************************************************************/
extern bool_t NameTable_AddressToNameTableIndex(Network_T *network, SourceAddress_T address, NameTableIndex_T *name_table_index);
/******************************************************************************/
/*!
   \brief    Translates a NAME Table index to the corresponding Source Address
   \details  Finds the source address for the supplied name table index
   \param    network           [in]  Network containing the NAME table
   \param    name_table_index  [in]  NameTableIndex of name
   \param    address           [out] Source Address to search for
   \return  bool_t
   \retval  TRUE   The name table index is claimed and the address has been updated with the index
   \retval  FALSE  The name table index is not claimed
*/
/******************************************************************************/
extern bool_t NameTable_NameTableIndexToAddress(Network_T *network, NameTableIndex_T name_table_index, SourceAddress_T *address);
/******************************************************************************/
/*!
   \brief    Translates a NAME Table index to the corresponding NAME
   \details  Finds the NAME for the supplied name table index
   \param    network           [in]  Network containing the NAME table
   \param    name_table_index  [in]  NameTableIndex of name
   \param    name              [out] Source Address to search for
   \return  bool_t
   \retval  TRUE   The `name` has been updated
   \retval  FALSE  The `name_table_index` is invalid
*/
/******************************************************************************/
extern bool_t NameTable_NameTableIndexToName(Network_T *network, NameTableIndex_T name_table_index, ISOBUS_Name_T name);
/******************************************************************************/
/*!
   \brief    Translates a Working Set Member NAME Table index to its Working Set Master NAME Table index
   \details  Finds the name table index of the working set master for the
             supplied working set member index.
   \param    network             [in]  Network containing the NAME table
   \param    working_set_member  [in]  NameTableIndex of working set member
   \param    working_set_master  [out] NameTableIndex of working set master
   \return  bool_t
   \retval  TRUE   The "member" is part of a working set (and master has been populated)
   \retval  FALSE  The "member" is not part of a working set (master is not populated)
*/
/******************************************************************************/
extern bool_t NameTable_MemberIndexToMasterIndex(Network_T *network, NameTableIndex_T working_set_member, NameTableIndex_T *working_set_master);
/******************************************************************************/
/*!
   \details  Converts from an ISOBUS packet to a CAN packet
   \param  iso_packet  ISOBUS Packet to convert
   \param  can_packet  CAN Packet that results
   \param  network     Network containing the NAME table
   \return  bool_t
   \retval  TRUE   The packet was converted
   \retval  FALSE  The packet could not be converted
*/
/******************************************************************************/
extern bool_t NameTable_ConvertPacket_IsoToCan(const ISOBUS_Packet_T *iso_packet, CAN_Packet_T *can_packet, Network_T *network);
/******************************************************************************/
/*!
   \details  Convert from a CAN packet to an ISOBUS packet
   \param  can_packet  CAN Packet to convert
   \param  iso_packet  ISOBUS Packet that results
   \param  network     Network containing the NAME table
   \return  bool_t
   \retval  TRUE   The packet was converted
   \retval  FALSE  The packet could not be converted
*/
/******************************************************************************/
extern bool_t NameTable_ConvertPacket_CanToIso(const CAN_Packet_T *can_packet, ISOBUS_Packet_T *iso_packet, Network_T *network);
/******************************************************************************/
/*!
   \details  Initialize the network
   \param  network  ISOBUS network to initialize
*/
/******************************************************************************/
extern void Network_Init(Network_T *network);
/******************************************************************************/
/*!
   \details  Performs all Network tasks
   \param  network  ISOBUS network to perform tasks on
*/
/******************************************************************************/
extern void Network_Task(Network_T *network);
/******************************************************************************/
/*!
   \brief    Register a packet handler
   \details  Adds handler to list of handlers for this network
   \param  network  ISOBUS network
   \param  handler  ISOBUS packet handler to add
   \return  bool_t
   \retval  TRUE   Handler successfully registered
   \retval  FALSE  Handler not registered (possibly already registered)
*/
/******************************************************************************/
extern bool_t Network_RegisterHandler(Network_T *network, Network_PacketHandler_T *handler);
/******************************************************************************/
/*!
   \brief    Unregister a packet handler
   \details  Removes handler from list of handlers for this network
   \param  network  ISOBUS network
   \param  handler  ISOBUS packet handler to remove
   \return  bool_t
   \retval  TRUE   Handler successfully unregistered
   \retval  FALSE  Handler not found (possibly not registered for this network)
*/
/******************************************************************************/
extern bool_t Network_UnregisterHandler(Network_T *network, Network_PacketHandler_T *handler);
/******************************************************************************/
/*!
   \brief    Packet handler for network
   \details  Processes CAN1 packets by passing them to correct handler.
   \param  can_packet  ISOBUS packet to process
   \param  network     ISOBUS network handling the packet
*/
/******************************************************************************/
extern void Network_PacketHandler(const CAN_Packet_T *can_packet, Network_T *network);
/******************************************************************************/
/*!
   \brief    Send packet on CAN interface and enforce Address Claim rules
   \details  Acts as a gateway to enforce the ISOBUS Polite Address Claim rules.
             Don't send any massages until the NAME Table is populated. Then send
             all AddressClaim messages, and application messages if the application
             has claimed an address, and the message is not destination spicific or
             the destination is global or the destination address has also been
             claimed.
   \param  iso_packet  ISOBUS packet to be sent on the bus
   \param  callback    Callback to be called once packet is successfully sent
   \param  foundation  Foundation layer for the sending app
   \return  bool_t
   \retval  TRUE   Packet queued to be sent
   \retval  FALSE  For some reason, packet will not be sent (at this time)
*/
/******************************************************************************/
extern bool_t Network_SendPacket(ISOBUS_Packet_T *iso_packet, const ISOBUS_Callback_T *callback, const Foundation_T *foundation);
//! Structure used for registering packet handlers for a specific Foundation structure
struct Foundation_PacketHandler_Node_S
{
   //! Parameter Group of message to handle
   ISOBUS_PGN_T PGN;
   //! Packet handler function
   void (*PacketHandler)(const ISOBUS_Packet_T *packet, struct Foundation_PacketHandler_Node_S *packet_handler);
   //! Filter function (NULL = default = Filter_GlobalOrWorkingSetOrDestinationSpecificToMe())
   bool_t (*Filter)(const ISOBUS_Packet_T *packet, const Foundation_T *foundation);
   //! Pointer to arbitrary data for use by callback
   void *Pointer_1;
   //! Pointer to arbitrary data for use by callback
   const void *Pointer_2;
   //! Linked list node for registering this Packet handler struct
   struct LinkedList_Node_S LinkedList_Node;
};
/******************************************************************************/
/*!
   \brief  Macro used to initialize a struct Foundation_PacketHandler_Node_S
   \param  pgn        Parameter Group of message to handle
   \param  handler    Message/Event handler function
   \param  filter     Filter function (NULL = default = Filter_GlobalOrWorkingSetOrDestinationSpecificToMe())
   \param  pointer1   Instance information (used by `handler`)
   \param  pointer2   Instance information (used by `handler`)
*/
/******************************************************************************/
#define MAKE_Foundation_PacketHandler_Node_S(pgn,handler,filter,pointer1,pointer2) {pgn, handler, filter, pointer1, pointer2, MAKE_LinkedList_Node_S(NULL)}
/******************************************************************************/
// User Interface:
/******************************************************************************/
/******************************************************************************/
/*!
   \brief    Register a PacketHandler with a application's Foundation structure
   \param    foundation  Pointer to the application's Foundation structure
   \param    handler     Packet handler struct to register
   \return  bool_t
   \retval  TRUE   Packet handler was successfully registered
   \retval  FALSE  Packet handler was not registered (perhaps already registered?)
*/
/******************************************************************************/
extern bool_t Foundation_PacketHandler_Register(Foundation_T *foundation, struct Foundation_PacketHandler_Node_S *handler);
/******************************************************************************/
/*!
   \brief    Unregister a PacketHandler with a application's Foundation structure
   \param    foundation  Pointer to the application's Foundation structure
   \param    handler     Packet handler struct to unregister
   \return  bool_t
   \retval  TRUE   Packet handler was successfully unregistered
   \retval  FALSE  Packet handler was not unregistered (was not registered in this list)
*/
/******************************************************************************/
extern bool_t Foundation_PacketHandler_Unregister(Foundation_T *foundation, struct Foundation_PacketHandler_Node_S *handler);
/******************************************************************************/
// Provided Filters:
/******************************************************************************/
/******************************************************************************/
/*!
   \brief    Filter packets sent only to my claimed source address
   \details  Accepts only messages sent destination specific to the source
             address claimed by the supplied `foundation` structure.  All other
             packets are rejected.
   \param    packet      Incoming packet to test
   \param    foundation  Pointer to the application's Foundation structure
   \return  bool_t
   \retval  TRUE   Packet passes the filter (process)
   \retval  FALSE  Packet failed the filter (drop)
*/
/******************************************************************************/
extern bool_t Filter_DestinationSpecificToMe(const ISOBUS_Packet_T *packet, const struct Foundation_S *foundation);
/******************************************************************************/
/*!
   \brief    Filter packets sent only to my working set master
   \details  Accepts only messages sent destination specific to the source
             address claimed by the supplied `foundation` structure.  All other
             packets are rejected.
   \param    packet      Incoming packet to test
   \param    foundation  Pointer to the application's Foundation structure
   \return  bool_t
   \retval  TRUE   Packet passes the filter (process)
   \retval  FALSE  Packet failed the filter (drop)
*/
/******************************************************************************/
extern bool_t Filter_SentToMyWorkingSet(const ISOBUS_Packet_T *packet, const struct Foundation_S *foundation);
/******************************************************************************/
/*!
   \brief    Filter packets sent to my claimed source address, globally, or to my working set master
   \details  Accepts only messages sent destination specific to the source
             address claimed by the supplied `foundation` structure, to the
             working set master address, or sent globally.  All other packets
             are rejected.
   \param    packet      Incoming packet to test
   \param    foundation  Pointer to the application's Foundation structure
   \return  bool_t
   \retval  TRUE   Packet passes the filter (process)
   \retval  FALSE  Packet failed the filter (drop)
*/
/******************************************************************************/
extern bool_t Filter_GlobalOrWorkingSetOrDestinationSpecificToMe(const ISOBUS_Packet_T *packet, const struct Foundation_S *foundation);
/******************************************************************************/
/*!
   \brief    Filter packets sent to my claimed source address, or globally
   \details  Accepts only messages sent destination specific to the source
   address claimed by the supplied `foundation` structure, or sent globally.
   All other packets
   are rejected.
   \param    packet      Incoming packet to test
   \param    foundation  Pointer to the application's Foundation structure
   \return  bool_t
   \retval  TRUE   Packet passes the filter (process)
   \retval  FALSE  Packet failed the filter (drop)
*/
/******************************************************************************/
extern bool_t Filter_GlobalOrSpecificToMe(const ISOBUS_Packet_T *packet, const struct Foundation_S *foundation);
/******************************************************************************/
/*!
   \brief    Filter packets to a member of my working set
   \details  Accepts only messages sent to a member of my working set.  All
             other packets are rejected.
   \param    packet      Incoming packet to test
   \param    foundation  Pointer to the application's Foundation structure
   \return  bool_t
   \retval  TRUE   Packet passes the filter (process)
   \retval  FALSE  Packet failed the filter (drop)
*/
/******************************************************************************/
extern bool_t Filter_SentToWorkingSetMember(const ISOBUS_Packet_T *packet, const struct Foundation_S *foundation);
/******************************************************************************/
/*!
   \brief    Filter packets sent from members of my working set
   \details  Accepts only messages sent from a member of my working set.  All
             other packets are rejected.
   \param    packet      Incoming packet to test
   \param    foundation  Pointer to the application's Foundation structure
   \return  bool_t
   \retval  TRUE   Packet passes the filter (process)
   \retval  FALSE  Packet failed the filter (drop)
*/
/******************************************************************************/
extern bool_t Filter_SentFromMyWorkingSet(const ISOBUS_Packet_T *packet, const struct Foundation_S *foundation);
//! Structure used to register a Transport Message/Event handler
struct Transport_MessageHandler_Node_S
{
   //! Function to call when Message is received
   void (*MessageEventHandler)(ISOBUS_Message_T *message, ISOBUS_MessageEvent_T event, const struct Transport_MessageHandler_Node_S *message_handler);
   //! Minimum pipe size to process a large message
   Size_T MinimumPipeSize;
   //! Arbitrary pointer
   void *Pointer_1;
   //! Arbitrary const pointer
   const void *Pointer_2;
   struct
   {
      //! Linked list node for registering this Message/Event handler struct
      struct LinkedList_Node_S MessageEventHandler_Node;
      //! Node for registering a Packet handler for the same PGN
      struct Foundation_PacketHandler_Node_S SinglePacket_Node;
   } Private; //!< Private members
};
/******************************************************************************/
/*!
   \brief  Macro used to initialize a struct Transport_MessageHandler_Node_S
   \param  pgn        Parameter Group of message to handle
   \param  handler    Message/Event handler function
   \param  filter     Filter function (NULL = default = Filter_GlobalOrWorkingSetOrDestinationSpecificToMe())
   \param  pointer1   Instance information (used by `handler`)
   \param  pointer2   Instance information (used by `handler`)
   \param  size       Minimum pipe size required to process a large message
*/
/******************************************************************************/
#define MAKE_Transport_MessageHandler_Node_S(pgn,handler,filter,pointer1,pointer2,size) {handler, size, pointer1, pointer2, {MAKE_LinkedList_Node_S(NULL), MAKE_Foundation_PacketHandler_Node_S(pgn, NULL, filter, NULL, NULL)}}
// *** User Interface ***
/******************************************************************************/
/*!
   \brief    Register a Message/Event Handler
   \param  foundation            Pointer to structure containing state
                                 information for all transport sessions.
   \param  message_handler_node  Node containing DataPage/PGN and handler to
                                 register.
   \return  bool_t
   \retval  TRUE   `message_handler_node` was successfully registered
   \retval  FALSE  `message_handler_node` was not successfully registered
*/
/******************************************************************************/
extern bool_t Transport_MessageHandler_Register(Foundation_T *foundation, struct Transport_MessageHandler_Node_S *message_handler_node);
/******************************************************************************/
/*!
   \brief    Unregister a Message/Event Handler
   \param  foundation            Pointer to structure containing state
                                 information for all transport sessions.
   \param  message_handler_node  Node to unregister.
   \return  bool_t
   \retval  TRUE   `message_handler_node` was successfully unregistered
   \retval  FALSE  `message_handler_node` was not successfully unregistered
*/
/******************************************************************************/
extern bool_t Transport_MessageHandler_Unregister(Foundation_T *foundation, struct Transport_MessageHandler_Node_S *message_handler_node);
/******************************************************************************/
/*!
   \brief    Initiate the transport of a message
   \details  Sends packet using appropriate protocol
   \param    foundation  Foundation Functionality structure for this app
   \param    message     Message to Send
   \param    callback    Contains callback information
   \return   bool_t
   \retval   TRUE   Transport session opened
   \retval   FALSE  Transport session not opened
*/
/******************************************************************************/
extern bool_t Transport_SendMessage(const Foundation_T *foundation, ISOBUS_Message_T *message, const ISOBUS_MessageCallback_T *callback);
/******************************************************************************/
/*!
   \brief    Abort a transport session (if it's still open)
   \details  Abort a Transport session
   \param    foundation  Foundation Functionality structure for this app
   \param    message     Message/session to abort
   \return   bool_t
   \retval   TRUE   Session successfully closed
   \retval   FALSE  Session not closed
*/
/******************************************************************************/
extern bool_t Transport_Abort(const Foundation_T *foundation, const ISOBUS_Message_T *message);
/******************************************************************************/
/*!
   \brief  Register a handler for an Request message
   \param  foundation  Pointer to the application's Foundation structure
   \param  request_node    Request handler node to register
   \return  bool_t
   \retval  TRUE   `request_node` was successfully registered
   \retval  FALSE  `request_node` was not successfully registered
*/
/******************************************************************************/
extern bool_t Request_Register(Foundation_T *foundation, struct Request_Node_S *request_node);
/******************************************************************************/
/*!
   \brief  Unregister a handler for an Request message
   \param  foundation  Pointer to the application's Foundation structure
   \param  request_node    Request handler node to unregister
   \return  bool_t
   \retval  TRUE   `request_node` was successfully unregistered
   \retval  FALSE  `request_node` was not successfully unregistered
*/
/******************************************************************************/
extern bool_t Request_Unregister(Foundation_T *foundation, struct Request_Node_S *request_node);
/******************************************************************************/
/*!
   \brief  Send a Request message
   \param  foundation   Pointer to the application's Foundation structure
   \param  callback     Callback to call if packet is sent (only called if return value is TRUE)
   \param  destination  Destination of the Request
   \param  pgn          PGN of the message being requested
   \return  bool_t
   \retval  TRUE   RequestPGN was successfully queued/sent
   \retval  FALSE  RequestPGN was not successfully queued/sent (try again later)
*/
/******************************************************************************/
extern bool_t Request_Send(const Foundation_T *foundation, const ISOBUS_Callback_T *callback, NameTableIndex_T destination, ISOBUS_PGN_T pgn);
/******************************************************************************/
/*!
   \details  Automatically positive acknowledge a Request PGN (parameters match those needed for the RequestHandler in Request_Node_S)
   \param  packet        Received request PGN packet
   \param  request_node  Registered Request node
*/
/******************************************************************************/
extern void Request_AutoAcknowledgePositive(const ISOBUS_Packet_T *packet, const struct Request_Node_S *request_node);
/******************************************************************************/
/*!
   \brief  Register a handler for an Acknowledge message
   \param  foundation  Pointer to the application's Foundation structure
   \param  ack_node    Acknowledge handler node to register
   \return  bool_t
   \retval  TRUE   `ack_node` was successfully registered
   \retval  FALSE  `ack_node` was not successfully registered
*/
/******************************************************************************/
extern bool_t Acknowledge_Register(Foundation_T *foundation, struct Acknowledge_Node_S *ack_node);
/******************************************************************************/
/*!
   \brief  Unregister a handler for an Acknowledge message
   \param  foundation  Pointer to the application's Foundation structure
   \param  ack_node    Acknowledge handler node to unregister
   \return  bool_t
   \retval  TRUE   `ack_node` was successfully unregistered
   \retval  FALSE  `ack_node` was not successfully unregistered
*/
/******************************************************************************/
extern bool_t Acknowledge_Unregister(Foundation_T *foundation, struct Acknowledge_Node_S *ack_node);
/******************************************************************************/
/*!
   \brief    Send an Acknowledgement response
   \param  packet      Packet to acknowledge (uses Source and Destination)
   \param  foundation  Pointer to the application's Foundation structure
   \param  group       Group Function value (use SIGNAL_1_BYTE_NOT_AVAILABLE if unknown)
   \param  ack_type    Type of acknowledgement to send
*/
/******************************************************************************/
extern void Acknowledge_SendResponse(const ISOBUS_Packet_T *packet, const Foundation_T *foundation, ISOBUS_GroupFunction_T group, ISOBUS_AcknowledgeResponse_T ack_type);
/******************************************************************************/
/*!
   \brief   Send a non-requested Acknowledgement
   \param   foundation   Pointer to the application's Foundation structure
   \param   pgn          PGN that is to be acknowledged
   \param   destination  Name Table Index of the destination
   \param   group        Group Function value (use SIGNAL_1_BYTE_NOT_AVAILABLE if unknown)
   \param   ack_type     Type of acknowledgement to send
   \param   callback     Callback to be called once packet is successfully sent
   \return  bool_t
   \retval  TRUE  Packet queued to be sent
   \retval  FALSE Unable to queue packet for some reason
*/
/******************************************************************************/
extern bool_t Acknowledge_SendNonRequestAcknowledgement(const Foundation_T *foundation, ISOBUS_PGN_T pgn, NameTableIndex_T destination, ISOBUS_GroupFunction_T group, ISOBUS_AcknowledgeResponse_T ack_type, const ISOBUS_Callback_T *callback);
// *** User Interface ***
/******************************************************************************/
/*!
   \details  Helper function for parsing the Language command
   \param    packet_data  [In]  Pointer to Language Command packet data
   \param    language     [Out] Pointer to Language structure to populate based on `packet_data`
   \return   Language_T
*/
/******************************************************************************/
extern void LanguageCommand_ParseData(const ISOBUS_PacketData_T *packet_data, Language_T *language);
/******************************************************************************/
/*!
   \details  Request the language command from another node
   \param    foundation  Foundation Functionality structure for this app
   \param    destination Name Table Index for the destination of this language request
   \return   bool_t
   \retval   TRUE   Message was successfully sent
   \retval   FALSE  Message send failed (try later)
*/
/******************************************************************************/
extern bool_t Language_SendRequest(const Foundation_T* foundation, NameTableIndex_T destination);
/******************************************************************************/
/*!
   \brief    Register a Language Callback
   \details  Register a Language callback to a `list`
   \param    list      List to register with
   \param    callback  Callback to register
   \return   bool_t
   \retval   TRUE   Callback was successfully registered
   \retval   FALSE  Callback registration failed
*/
/******************************************************************************/
extern bool_t Language_RegisterCallback(LanguageCallbackList_T *list, LanguageCallback_T *callback);
/******************************************************************************/
/*!
   \brief    Unregister a Language Callback
   \details  Unregister a Language callback from `list`
   \param    list      List to unregister callback from
   \param    callback  Callback to unregister
   \return   bool_t
   \retval   TRUE   Successfully unregistered
   \retval   FALSE  Unregistration failed
*/
/******************************************************************************/
extern bool_t Language_UnregisterCallback(LanguageCallbackList_T *list, LanguageCallback_T *callback);
// *** User Interface ***
/******************************************************************************/
/*!
   \brief    Initialize the Software ID List.
   \details  Initalize a Software ID task
   \param    list  Software ID List to initialize
*/
/******************************************************************************/
extern void SoftwareIdList_Init(SoftwareIdList_T *list);
/******************************************************************************/
/*!
   \brief    Register a SoftwareId_T structure
   \details  Register a Software ID structure
   \param    list  Software ID list with which to register
   \param    swid  pointer to the Software_ID structure to be registered
   \return   bool_t
   \retval   TRUE   Successfully registered
   \retval   FALSE  registration failed
*/
/******************************************************************************/
extern bool_t SoftwareId_Register(SoftwareIdList_T *list, SoftwareId_T *swid);
/******************************************************************************/
/*!
   \brief    Unregister a SoftwareId_T structure
   \details  Unregister a Software ID structure
   \param    list  Software ID list with which to unregister
   \param    swid  pointer to the Software_ID structure to be unregistered
   \return   bool_t
   \retval   TRUE   Successfully unregistered
   \retval   FALSE  Unregistration failed
*/
/******************************************************************************/
extern bool_t SoftwareId_Unregister(SoftwareIdList_T *list, SoftwareId_T *swid);
// *** User Interface ***
/******************************************************************************/
/*!
   \brief    Get the number of active DTCs
   \details  Returns the number of active DTCs
   \param    foundation  Structure containing App ISOBUS information
   \return  DTC_Index_T
   \retval  Number of active DTCs
*/
/******************************************************************************/
extern DTC_Index_T DTC_GetNumberOfActiveDTCs(Foundation_T *foundation);
/******************************************************************************/
/*!
   \brief    Get the number of inactive DTCs
   \details  Returns the number of inactive DTCs
   \param    foundation  Structure containing App ISOBUS information
   \return  DTC_Index_T
   \retval  Number of previously active DTCs
*/
/******************************************************************************/
extern DTC_Index_T DTC_GetNumberOfPreviouslyActiveDTCs(Foundation_T *foundation);
/******************************************************************************/
/*!
   \brief    Clears all active DTCs
   \details  Clears the active flag and occurrence counts for all active DTCs
   \param    foundation  Structure containing App ISOBUS information
*/
/******************************************************************************/
extern void DTC_ClearAllActiveDTCs(Foundation_T *foundation);
/******************************************************************************/
/*!
   \brief    Clears all inactive DTCs
   \details  Clears the occurrence count for all inactive DTCs
   \param    foundation  Structure containing App ISOBUS information
*/
/******************************************************************************/
extern void DTC_ClearAllPreviouslyActiveDTCs(Foundation_T *foundation);
/******************************************************************************/
/*!
   \brief    Determine the number of occurrences of DTC at `dtc_index`
   \details  Returns number of occurrences of this SPN/FMI combination
   \param    foundation  Structure containing App ISOBUS information
   \param    dtc_index   Index of the DTC to check
   \return  DTC_OccurrenceCount_T
   \retval  DTC_OCCURRENCE_COUNT_NOT_AVAILABLE  The occurrence count is not available (make sure `dtc_index` is valid)
*/
/******************************************************************************/
extern DTC_OccurrenceCount_T DTC_GetOccurrenceCount(Foundation_T *foundation, DTC_Index_T dtc_index);
/******************************************************************************/
/*!
   \brief    Determine if DTC at `dtc_index` is currently active
   \param    foundation  Structure containing App ISOBUS information
   \param    dtc_index   Index of the DTC to check
   \return  bool_t
   \retval  TRUE   DTC at `dtc_index` is currently active
   \retval  FALSE  DTC at `dtc_index` is not currently active (or `dtc_index` is invalid)
*/
/******************************************************************************/
extern bool_t DTC_GetIsActive(Foundation_T *foundation, DTC_Index_T dtc_index);
/******************************************************************************/
/*!
   \brief    Determine if DTC at `dtc_index` was previously active
   \param    foundation  Structure containing App ISOBUS information
   \param    dtc_index   Index of the DTC to check
   \return  bool_t
   \retval  TRUE   DTC at `dtc_index` was previously active
   \retval  FALSE  DTC at `dtc_index` is currently active or has never been active (or `dtc_index` is invalid)
*/
/******************************************************************************/
extern bool_t DTC_GetIsPreviouslyActive(Foundation_T *foundation, DTC_Index_T dtc_index);
/******************************************************************************/
/*!
   \brief    Set the DTC at index `dtc_index` to active
   \param    foundation  Structure containing App ISOBUS information
   \param    dtc_index   Index of the DTC to check
*/
/******************************************************************************/
extern void DTC_SetActive(Foundation_T *foundation, DTC_Index_T dtc_index);
/******************************************************************************/
/*!
   \brief    Set the DTC at index `dtc_index` to inactive
   \details  If the DTC at `dtc_index` is already inactive, no change will
             occur.  Otherwise, the DTC will become previously active.
   \param    foundation  Structure containing App ISOBUS information
   \param    dtc_index   Index of the DTC to check
*/
/******************************************************************************/
extern void DTC_SetInactive(Foundation_T *foundation, DTC_Index_T dtc_index);
/******************************************************************************/
/*!
   \brief    Sends Working Set master/member messages
   \details  Sends working set master/member messages to identify working set.
             Calls callback when complete
   \note     Currently hard-coded that working set consist of one master (us)
             with no other members.
   \param    foundation  Structure containing working set information
   \param    callback    Callback to call when sent
   \return  bool_t
   \retval  TRUE   Working Set Identification started
   \retval  FALSE  Working Set Identification not started
*/
/******************************************************************************/
extern bool_t WorkingSet_Identify(const Foundation_T *foundation, const ISOBUS_Callback_T *callback);
/******************************************************************************/
/*!
   \brief    Meta-task for initializing VIRTEC Foundation structure for one app
   \param    foundation  Pointer to App Foundation_T structure
*/
/******************************************************************************/
extern void Foundation_Init(Foundation_T *foundation);
/******************************************************************************/
/*!
   \brief    Meta-task for uninitializing VIRTEC Foundation structure for one app
   \param    foundation  Pointer to App Foundation_T structure
*/
/******************************************************************************/
extern void Foundation_Uninit(Foundation_T *foundation);
/******************************************************************************/
/*!
   \brief    Meta-task for processing all VIRTEC Foundation tasks for one app
   \param    foundation  Pointer to App Foundation_T structure
*/
/******************************************************************************/
extern void Foundation_Task(Foundation_T *foundation);
/******************************************************************************/
/*
   Copyright (C) 2017  DISTek Integration, Inc.  All Rights Reserved.
   Developed by:
      DISTek(R) Integration, Inc.
      6612 Chancellor Drive Suite 600
      Cedar Falls, IA 50613
      Tel: 319-859-3600
*/
/******************************************************************************/
#endif //FOUNDATION_H
