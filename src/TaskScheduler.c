/******************************************************************************/
/*!
   \file
      This file implements task management for WIN32

   \copyright
      Copyright (C) 2012  DISTek Integration, Inc.  All Rights Reserved.

   \author
      Chris Thatcher
*/
/******************************************************************************/


#include "VIRTEC_STW.h"
#include "Solution.h"

//! Extern init routines
#define INIT(fn)                   extern void fn(void);
//! Extern init routines
#define TASK(fn,period,priority)   extern void fn(void);
//! Extern init routines
#define EXIT(fn)                   extern void fn(void);
#include "ScheduleTasksHere.h"
#undef INIT
#undef TASK
#undef EXIT

static struct SchedulerTask_S ListOfTasks[] =
{
   //! Define list of tasks
   #define TASK(fn,period,priority)                 MAKE_SchedluleTask_S(fn,NULL,NULL,period),
   #define LIBRARY_TASK(fn,state,period,priority)   MAKE_SchedluleTask_S(NULL,fn,state,period),
   #include "ScheduleTasksHere.h"
   #undef LIBRARY_TASK
   #undef TASK
};


/******************************************************************************/
/*!
   \brief    Initialize the solution

   \details  Calls all init tasks to initialize the solution
*/
/******************************************************************************/
void TaskScheduler_Init(void)
{
   uint16_t i;

   //! Run the init routines
   #define INIT(fn)  fn();
   #define LIBRARY_INIT(fn,state)  fn(state);
   #include "ScheduleTasksHere.h"
   #undef INIT
   #undef LIBRARY_INIT

   //! init scheduler
   Scheduler_Init();

   //! register tasks
   for (i = 0; i < sizeof(ListOfTasks)/(sizeof(ListOfTasks[0])); i++)
   {
      Register_Scheduler_Task(&ListOfTasks[i]);
   }
}

/******************************************************************************/
/*!
   \brief    Runs the solution

   \details  Calls all registered tasks on the defined period
*/
/******************************************************************************/
void TaskScheduler_Run(void)
{
   Scheduler_Run();
}

/******************************************************************************/
/*!
   \brief    Runs any exit tasks for the solution

   \details  Calls all exit tasks
*/
/******************************************************************************/
void TaskScheduler_Exit(void)
{
   #define EXIT(fn)  fn();
   #define LIBRARY_EXIT(fn,state)  fn(state);
   #include "ScheduleTasksHere.h"
   #undef EXIT
   #undef LIBRARY_EXIT
}


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
