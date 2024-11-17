/*
 * global.h
 *
 *  Created on: Oct 30, 2024
 *      Author: tuank
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_

#include "main.h"
#include "software_timer.h"
#include "button.h"
#include "traffic.h"
#include "led7_segment.h"
#include "fsm_setting.h"
#include "fsm_automatic.h"
#include "scheduler.h"

#define TICK 10

#define INIT 1
#define AUTO_RED 2
#define AUTO_GREEN 3
#define AUTO_YELLOW 4

#define MAN_RED 12
#define MAN_GREEN 13
#define MAN_YELLOW 14

#define INIT_MODE 20
#define MODE1 21
#define MODE2 22
#define MODE3 23
#define MODE4 24

extern int status_horizontal_traffic;
extern int status_vertical_traffic;

extern int red_duration;
extern int green_duration;
extern int yellow_duration;

extern int red_duration_tmp;
extern int green_duration_tmp;
extern int yellow_duration_tmp;

extern int index_buffer_horizontal;
extern int index_buffer_vertical;

extern int led_buffer_horizontal[2];
extern int led_buffer_vertical[2];

extern int counter_horizontal;
extern int counter_vertical;

extern int time_scan_7seg;

extern int counter_scan_horizontal;
extern int counter_led_horizontal;
extern int counter_7seg_horizontal;

extern int counter_scan_vertical;
extern int counter_led_vertical;
extern int counter_7seg_vertical;

extern int counter_delay;
extern int counter_waiting_custom;

void set_tmp_duration();
void clear_all();

void count_down_horizontal();
void count_down_vertical();

#endif /* INC_GLOBAL_H_ */
