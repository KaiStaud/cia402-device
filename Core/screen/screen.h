/*
 * screen.h
 *
 *  Created on: Jan 11, 2025
 *      Author: kai
 */

#ifndef SCREEN_SCREEN_H_
#define SCREEN_SCREEN_H_

enum screens{
	csv, // constant synchronous velocity
	cst, // constant synchronous torque
	csp, // constant synchronous position
	info,
	empty,
};
void screen_info(void);
void screen_init(void);
void screen_cvp(void);
void screen_csp(int target_position, int act_position);
void select_screen();
#endif /* SCREEN_SCREEN_H_ */
