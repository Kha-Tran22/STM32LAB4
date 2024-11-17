/*
 * global.c
 *
 *  Created on: Oct 30, 2024
 *      Author: tuank
 */

#include "global.h"


int status_horizontal_traffic = INIT;
int status_vertical_traffic = INIT;

int red_duration = 5;
int	green_duration = 3;
int	yellow_duration = 2;

int red_duration_tmp = 0;
int	green_duration_tmp = 0;
int	yellow_duration_tmp = 0;

int index_buffer_horizontal = 0;
int index_buffer_vertical = 0;

int led_buffer_horizontal[2] = {0,5};
int led_buffer_vertical[2] = {0,3};

int counter_horizontal = 5;
int counter_vertical = 3;

int time_scan_7seg = 500;

int counter_scan_horizontal;
int counter_led_horizontal;
int counter_7seg_horizontal;

int counter_scan_vertical;
int counter_led_vertical;
int counter_7seg_vertical;

int counter_delay;
int counter_waiting_custom;

void set_tmp_duration()
{
    red_duration_tmp = red_duration;
	green_duration_tmp = green_duration;
	yellow_duration_tmp = yellow_duration;
}

void clear_all()
{
    clear_all_7seg();
    clear_all_led();
}

void count_down_horizontal()
{
    counter_scan_horizontal--;
	counter_led_horizontal--;
	counter_7seg_horizontal--;
}

void count_down_vertical()
{
    counter_scan_vertical--;
	counter_led_vertical--;
	counter_7seg_vertical--;
}
