/*
 * scheduler.h
 *
 *  Created on: Nov 14, 2024
 *      Author: tuank
 */

#ifndef INC_SCHEDULER_H_
#define INC_SCHEDULER_H_

#include "global.h"
#include "stdint.h"

typedef struct
{
	void (*pTask)(void);
	uint32_t Delay;
	uint32_t Period;
	uint8_t RunMe;
	uint32_t TaskID;
}sTasks;

#define SCH_MAX_TASKS 40
#define NO_TASK_ID 0

void SCH_Init(void);

void SCH_Add_Task(void (*pFunction)(), uint32_t DELAY, uint32_t PERIOD); //Similar to setTimer

void SCH_Update(void); //similar to timerRun

void SCH_Dispatch_Tasks(void); // similar to timer_flag

void SCH_Delete(uint32_t ID);

#endif /* INC_SCHEDULER_H_ */
