/*
 * scheduler.c
 *
 *  Created on: Nov 14, 2024
 *      Author: tuank
 */

#include "scheduler.h"

sTasks SCH_tasks_G[SCH_MAX_TASKS];
uint8_t current_index_task = 0;

void SCH_Init(void)
{
    current_index_task = 0;
}

void SCH_Add_Task(void (*pFunction)(), uint32_t DELAY, uint32_t PERIOD) // Similar to setTimer
{
    if (current_index_task < SCH_MAX_TASKS)
    {
        SCH_tasks_G[current_index_task].pTask = pFunction;
        SCH_tasks_G[current_index_task].Delay = DELAY / 10;
        SCH_tasks_G[current_index_task].Period = PERIOD / 10;
        SCH_tasks_G[current_index_task].RunMe = 0;
        SCH_tasks_G[current_index_task].TaskID = current_index_task;

        current_index_task++;
    }
}

void SCH_Update(void) // similar to timerRun
{
    for (int i = 0; i < current_index_task; i++)
    {
        if (SCH_tasks_G[i].Delay > 0)
        {
            SCH_tasks_G[i].Delay--;
        }
        else
        {
            SCH_tasks_G[i].Delay = SCH_tasks_G[i].Period;
            SCH_tasks_G[i].RunMe += 1;
        }
    }
}

void SCH_Dispatch_Tasks(void) // similar to timer_flag
{
    for (int i = 0; i < SCH_MAX_TASKS; i++)
    {
        if (SCH_tasks_G[i].RunMe > 0)
        {
            SCH_tasks_G[i].RunMe--;
            (*SCH_tasks_G[i].pTask)();
        }
    }
}

// void SCH_Delete(uint32_t ID){
// 	if(ID < 0 || ID >= current_index_task) return;
// 	for(int i = 0; i < current_index_task; i++){
// 		if(ID == i){
// 			SCH_tasks_G[i].Delay = 0;
// 			SCH_tasks_G[i].Period = 0;
// 			SCH_tasks_G[i].RunMe = 0;
// 			current_index_task--;
// 			for(int j = i; j < current_index_task; j++){
// 				SCH_tasks_G[j] = SCH_tasks_G[j+1];
// 			}
// 			break;
// 		}
// 	}
// }


void SCH_Delete(uint32_t ID)
{
    if(ID < 0 || ID >= current_index_task) return;
    SCH_tasks_G[ID].pTask = 0x0000;
    SCH_tasks_G[ID].Delay = 0;
    SCH_tasks_G[ID].Period = 0;
    SCH_tasks_G[ID].RunMe = 0;
    for (uint32_t i = ID; i < current_index_task - 1; i++)
    {
        SCH_tasks_G[i] = SCH_tasks_G[i+1];
    }
    current_index_task--;
}