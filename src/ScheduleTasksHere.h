/******************************************************************************/
/*!
   \file
      Holds a list of the tasks that are to be scheduled.

   \copyright
      Copyright (C) 2012  DISTek Integration, Inc.  All Rights Reserved.

   \author
      Chris Thatcher
*/
/******************************************************************************/


#ifndef INIT
//! Used for scheduling a function to run before any TASK
#define INIT(fn)
#define UNDEF_INIT
#endif //INIT

#ifndef TASK
//! Used for scheduling a function to execute periodically
#define TASK(fn,period,priority)
#define UNDEF_TASK
#endif //TASK

#ifndef EXIT
//! Used for scheduling tasks to run at shutdown
#define EXIT(fn)
#define UNDEF_EXIT
#endif //EXIT

#ifndef LIBRARY_INIT
//! Used for scheduling a function to run before any TASK
#define LIBRARY_INIT(fn,state)  INIT(Solution_##fn)
#define UNDEF_LIBRARY_INIT
#endif //LIBRARY_INIT

#ifndef LIBRARY_TASK
//! Used for scheduling a function to execute periodically
#define LIBRARY_TASK(fn,state,period,priority)  TASK(Solution_##fn,period,priority)
#define UNDEF_LIBRARY_TASK
#endif //LIBRARY_TASK

#ifndef LIBRARY_EXIT
//! Used for scheduling tasks to run at shutdown
#define LIBRARY_EXIT(fn,state)  EXIT(Solution_##fn)
#define UNDEF_LIBRARY_EXIT
#endif //LIBRARY_EXIT



/******************************************************************************/
// BEGIN:  Task Scheduling
/******************************************************************************/
//! \cond  SKIP

//   Init function
INIT(Timers_Init)               // foundation task, 1st to initalize
INIT(Solution_SoftwareId_Init)  // foundation task, 2nd to initalize
INIT(Memory_Init)
LIBRARY_INIT(CAN_Init, &SolutionCAN)

//   Task function,  period (ms),  priority
TASK(Timers_Task,             10,      PL_8)  // foundation task
TASK(Memory_Task,             10,      PL_5)

LIBRARY_TASK(CAN_Task, &SolutionCAN,                10,      PL_2)

//   Exit function
LIBRARY_EXIT(CAN_Close, &SolutionCAN)

#ifdef UNDEF_LIBRARY_INIT
#undef LIBRARY_INIT
#undef UNDEF_LIBRARY_INIT
#endif
#ifdef UNDEF_LIBRARY_TASK
#undef LIBRARY_TASK
#undef UNDEF_LIBRARY_TASK
#endif
#ifdef UNDEF_LIBRARY_EXIT
#undef LIBRARY_EXIT
#undef UNDEF_LIBRARY_EXIT
#endif

#include "schedule_tasks_here.h"

//! \endcond
/******************************************************************************/
// END:    Task Scheduling
/******************************************************************************/



#ifdef UNDEF_INIT
  #undef INIT
  #undef UNDEF_INIT
#endif

#ifdef UNDEF_TASK
  #undef TASK
  #undef UNDEF_TASK
#endif

#ifdef UNDEF_EXIT
  #undef EXIT
  #undef UNDEF_EXIT
#endif


/******************************************************************************/
/*
   Copyright (C) 2012  DISTek Integration, Inc.  All Rights Reserved.

   Developed by:
      DISTek(R) Integration, Inc.
      6612 Chancellor Drive Suite 600
      Cedar Falls, IA 50613
      Tel: 319-859-3600
*/
/******************************************************************************/
