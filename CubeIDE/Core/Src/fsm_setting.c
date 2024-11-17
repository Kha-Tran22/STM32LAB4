/*
 * fsm_setting.c
 *
 *  Created on: Nov 1, 2024
 *      Author: tuank
 */

#include "fsm_setting.h"

void fsm_setting_run()
{
	switch (status_horizontal_traffic)
	{
	case INIT_MODE:
		status_horizontal_traffic = MODE2;
		clear_all();

		counter_delay = 4;
		counter_waiting_custom = 40;
		
		set_tmp_duration();

		break;
	case MODE1:
		counter_delay--;
		counter_waiting_custom--;

		if (counter_delay <= 0)
		{
			status_horizontal_traffic = INIT;
			status_vertical_traffic = INIT;
		}
		if (isButtonPressed(1) == 1)
		{
			status_horizontal_traffic = MODE2;
			counter_waiting_custom = 40; // đợi nút 1 chuyển mode
		}
		set_tmp_duration();

		break;
	case MODE2:
		counter_waiting_custom--;
		enable_vertical(0);
		display_number_vertical(2);
		counter_horizontal = red_duration_tmp;
		update_buffer_horizontal();

		update_7seg_horizontal(index_buffer_horizontal++);
		if (index_buffer_horizontal >= 2)
			index_buffer_horizontal = 0;

		custom_red_mode();

		if (isButtonPressed(1) == 1)
		{
			status_horizontal_traffic = MODE3;
			counter_waiting_custom = 40;
		}
		if (isButtonPressed(2) == 1)
		{
			red_duration_tmp++;
			if (red_duration_tmp > 99)
				red_duration_tmp = 0;
			counter_waiting_custom = 40;
		}
		if (isButtonPressed(3) == 1)
		{
			red_duration = red_duration_tmp;
			status_horizontal_traffic = MODE1;
			clear_all();
			counter_delay = 4;
		}
		if (counter_waiting_custom <= 0)
		{
			status_horizontal_traffic = MODE1;
		}

		break;
	case MODE3:
		counter_waiting_custom--;
		enable_vertical(0);
		display_number_vertical(3);
		counter_horizontal = green_duration_tmp;
		update_buffer_horizontal();

		update_7seg_horizontal(index_buffer_horizontal++);
		if (index_buffer_horizontal >= 2)
			index_buffer_horizontal = 0;

		custom_green_mode();

		if (isButtonPressed(1) == 1)
		{
			status_horizontal_traffic = MODE4;
			counter_waiting_custom = 40;
		}
		if (isButtonPressed(2) == 1)
		{
			// Tang thoi gian green
			green_duration_tmp++;
			if (green_duration_tmp > 99)
				green_duration_tmp = 0;
		}
		if (isButtonPressed(3) == 1)
		{
			green_duration = green_duration_tmp;
			status_horizontal_traffic = MODE1;
			clear_all();
			counter_delay = 4;
		}
		if (counter_waiting_custom <= 0)
		{
			status_horizontal_traffic = MODE1;
		}

		break;
	case MODE4:
		counter_waiting_custom--;
		enable_vertical(0);
		display_number_vertical(4);
		counter_horizontal = yellow_duration_tmp;
		update_buffer_horizontal();

		update_7seg_horizontal(index_buffer_horizontal++);
		if (index_buffer_horizontal >= 2)
			index_buffer_horizontal = 0;

		custom_yellow_mode();

		if (isButtonPressed(1) == 1)
		{
			status_horizontal_traffic = MODE1;
			clear_all();
			counter_delay = 4;
		}
		if (isButtonPressed(2) == 1)
		{
			// Tang thoi gian yellow
			yellow_duration_tmp++;
			if (yellow_duration_tmp > 99)
				yellow_duration_tmp = 0;
		}
		if (isButtonPressed(3) == 1)
		{
			yellow_duration = yellow_duration_tmp;
			status_horizontal_traffic = MODE1;
			clear_all();
			counter_delay = 4;
		}
		if (counter_waiting_custom <= 0)
		{
			status_horizontal_traffic = MODE1;
		}

		break;
	default:
		break;
	}
}
