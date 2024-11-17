/*
 * fsm_automatic.c
 *
 *  Created on: Oct 30, 2024
 *      Author: tuank
 */

#include "fsm_automatic.h"


void fsm_automatic_run()
{
	switch (status_horizontal_traffic)
	{
	case INIT:
		status_horizontal_traffic = AUTO_RED; 
		counter_horizontal = red_duration - 1;
		update_buffer_horizontal();
		index_buffer_horizontal = 0;

		counter_scan_horizontal = 2;
		counter_led_horizontal = red_duration*4;
		counter_7seg_horizontal = 5;
		break;
	case AUTO_RED:
		count_down_horizontal();

		if (counter_scan_horizontal <= 0)
		{
			red_on_horizontal();
			update_7seg_horizontal(index_buffer_horizontal);
			index_buffer_horizontal++;
			if (index_buffer_horizontal >= 2)
				index_buffer_horizontal = 0;
			counter_scan_horizontal = 2;
		}

		if (counter_led_horizontal <= 0)
		{
			status_horizontal_traffic = AUTO_GREEN;
			counter_horizontal = green_duration;
			update_buffer_horizontal();
			counter_led_horizontal = green_duration*4;
		}

		if (counter_7seg_horizontal <= 0)
		{
			counter_horizontal--;
			update_buffer_horizontal();
			counter_7seg_horizontal = 4;
		}

		if (isButtonPressed(1) == 1)
		{
			status_horizontal_traffic = INIT_MODE;
			status_vertical_traffic = INIT_MODE;
		}

		break;
	case AUTO_GREEN:
		count_down_horizontal();

		if (counter_scan_horizontal <= 0)
		{
			green_on_horizontal();
			update_7seg_horizontal(index_buffer_horizontal);
			index_buffer_horizontal++;
			if (index_buffer_horizontal >= 2)
				index_buffer_horizontal = 0;
			counter_scan_horizontal = 2;
		}

		if (counter_led_horizontal <= 0)
		{
			status_horizontal_traffic = AUTO_YELLOW;
			counter_horizontal = yellow_duration;
			update_buffer_horizontal();
			counter_led_horizontal = yellow_duration*4;
		}

		if (counter_7seg_horizontal <= 0)
		{
			counter_horizontal--;
			update_buffer_horizontal();
			counter_7seg_horizontal = 4;
		}

		if (isButtonPressed(1) == 1)
		{
			status_horizontal_traffic = INIT_MODE;
			status_vertical_traffic = INIT_MODE;
		}

		break;
	case AUTO_YELLOW:
		count_down_horizontal();

		if (counter_scan_horizontal <= 0)
		{
			yellow_on_horizontal();
			update_7seg_horizontal(index_buffer_horizontal);
			index_buffer_horizontal++;
			if (index_buffer_horizontal >= 2)
				index_buffer_horizontal = 0;
			counter_scan_horizontal = 2;
		}

		if (counter_led_horizontal <= 0)
		{
			status_horizontal_traffic = AUTO_RED;
			counter_horizontal = red_duration;
			update_buffer_horizontal();
			counter_led_horizontal = red_duration*4;
		}

		if (counter_7seg_horizontal <= 0)
		{
			counter_horizontal--;
			update_buffer_horizontal();
			counter_7seg_horizontal = 4;
		}

		if (isButtonPressed(1) == 1)
		{
			status_horizontal_traffic = INIT_MODE;
			status_vertical_traffic = INIT_MODE;
		}

		break;
	default:
		break;
	}


	switch (status_vertical_traffic)
	{
	case INIT:
		status_vertical_traffic = AUTO_GREEN;
		counter_vertical = green_duration - 1;
		update_buffer_vertical();
		index_buffer_vertical = 0;

		counter_scan_vertical = 2;
		counter_led_vertical = green_duration*4;
		counter_7seg_vertical = 5;
		
		break;
	case AUTO_RED:
		count_down_vertical();

		if (counter_scan_vertical <= 0)
		{
			red_on_vertical();
			update_7seg_vertical(index_buffer_vertical++);
			if (index_buffer_vertical >= 2)
				index_buffer_vertical = 0;
			counter_scan_vertical = 2;
		}

		if (counter_led_vertical <= 0)
		{
			status_vertical_traffic = AUTO_GREEN;
			counter_vertical = green_duration;
			update_buffer_vertical();
			counter_led_vertical = green_duration*4;
		}

		if (counter_7seg_vertical <= 0)
		{
			counter_vertical--;
			update_buffer_vertical();
			counter_7seg_vertical = 4;
		}

		if (isButtonPressed(1) == 1)
		{
			status_vertical_traffic = INIT_MODE;
			status_horizontal_traffic = INIT_MODE;
		}

		break;
	case AUTO_GREEN:
		count_down_vertical();

		if (counter_scan_vertical <= 0)
		{
			green_on_vertical();
			update_7seg_vertical(index_buffer_vertical++);
			if (index_buffer_vertical >= 2)
				index_buffer_vertical = 0;
			counter_scan_vertical = 2;
		}

		if (counter_led_vertical <= 0)
		{
			status_vertical_traffic = AUTO_YELLOW;
			counter_vertical = yellow_duration;
			update_buffer_vertical();
			counter_led_vertical = yellow_duration*4;
		}

		if (counter_7seg_vertical <= 0)
		{
			counter_vertical--;
			update_buffer_vertical();
			counter_7seg_vertical = 4;
		}

		if (isButtonPressed(1) == 1)
		{
			status_vertical_traffic = INIT_MODE;
			status_horizontal_traffic = INIT_MODE;
		}

		break;
	case AUTO_YELLOW:
		count_down_vertical();

		if (counter_scan_vertical <= 0)
		{
			yellow_on_vertical();
			update_7seg_vertical(index_buffer_vertical++);
			if (index_buffer_vertical >= 2)
				index_buffer_vertical = 0;
			counter_scan_vertical = 2;
		}

		if (counter_led_vertical <= 0)
		{
			status_vertical_traffic = AUTO_RED;
			counter_vertical = red_duration;
			update_buffer_vertical();
			counter_led_vertical = red_duration*4;
		}

		if (counter_7seg_vertical <= 0)
		{
			counter_vertical--;
			update_buffer_vertical();
			counter_7seg_vertical = 4;
		}

		if (isButtonPressed(1) == 1)
		{
			status_vertical_traffic = INIT_MODE;
			status_horizontal_traffic = INIT_MODE;
		}
		
		break;
	default:
		break;
	}
}
