#ifndef _HOME_H
#define _HOME_H

#include "stdio.h"
// 函数 主界面
void home() {
	// 清屏函数
	system("cls");

	//通讯录主界面home 
	printf("\n\n\n\n\n");
	printf("\n\t\t\t|---------------------------CONTACTS---------------------------|");
	printf("\n\t\t\t|                WELCOME TO THE CONTACTS BETA 1.0              |");
	printf("\n\t\t\t|                      1. NEW      CONTACT                     |");
	printf("\n\t\t\t|                      2. SEARCH   CONTACT                     |");
	printf("\n\t\t\t|                      3. EDIT     CONTACT                     |");
	printf("\n\t\t\t|                      4. DELETE   CONTACT                     |");
	printf("\n\t\t\t|                      5. DISPLAY  CONTACT                     |");
	printf("\n\t\t\t|                      0. EXIT                                 |");
	printf("\n\t\t\t|--------------------------------------------------------------|");
	printf("\nPLEASE COMFIRM YOUR OPTIONS(ENTER 0-5):");
}

#endif