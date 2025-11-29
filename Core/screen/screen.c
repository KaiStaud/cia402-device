/*
 * screen.c
 *
 *  Created on: Jan 11, 2025
 *      Author: kai
 */
#include "screen.h"
#include "lcd.h"
#define DEFAULT_FONT FONT_arial_12X15

#define HeaderY 5
#define StringStartX 10
#define LINE1Y 40
#define LINE2Y 75
#define LINE3Y 110
#define LINE4Y 145
#define LINE5Y 175

enum screens active_screen = csv;

void screen_init(void)
{
	LCD_init();
	UG_FillScreen(C_WHITE);
	UG_Update();
}
void screen_info(void){
	LCD_PutStr(StringStartX, HeaderY, " System Info ", FONT_arial_25X28, C_WHITE, C_BLACK);
	LCD_PutStr(StringStartX, LINE1Y, "Lely Core v2.3.2", FONT_arial_25X28, C_BLACK, C_WHITE);
	LCD_PutStr(StringStartX, LINE2Y, "uGUI vX.Y.Z", FONT_arial_25X28, C_BLACK, C_WHITE);
	LCD_PutStr(StringStartX, LINE3Y, "TX Frames", FONT_arial_25X28, C_BLACK, C_WHITE);
	LCD_PutStr(StringStartX, LINE4Y, "RX Frames", FONT_arial_25X28, C_BLACK, C_WHITE);
	LCD_PutStr(StringStartX, LINE5Y, "Error Frames", FONT_arial_25X28, C_BLACK, C_WHITE);
	UG_Update();
}

void screen_cvp(void)
{

}

void screen_csp(int target_position, int act_position)
{
	char buf[50];
	LCD_PutStr(StringStartX, HeaderY, " Lely CiA402 Demo ", FONT_arial_25X28, C_WHITE, C_BLACK);
	sprintf(buf,"Tar. Position: %d",target_position);
	LCD_PutStr(StringStartX, LINE1Y, buf, FONT_arial_25X28, C_BLACK, C_WHITE);
	sprintf(buf,"Tar. Position: %d",act_position);
	LCD_PutStr(StringStartX, LINE2Y, buf, FONT_arial_25X28, C_BLACK, C_WHITE);
	LCD_PutStr(StringStartX, LINE3Y, "Controlword", FONT_arial_25X28, C_BLACK, C_WHITE);
	LCD_PutStr(StringStartX, LINE4Y, "Statusword", FONT_arial_25X28, C_BLACK, C_WHITE);
	LCD_PutStr(StringStartX, LINE5Y, "System-Error", FONT_arial_25X28, C_BLACK, C_WHITE);
	UG_Update();

}

void select_screen()
{
	active_screen++;
	switch(active_screen)
	{
	case csv:
		break;
	case csp:
		screen_csp(0,0);
		break;
	case info:
		screen_info();
		break;
	case empty:
		active_screen = csv;
		break;
	default:
		break;
	}
}
