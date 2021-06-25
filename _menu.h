#ifndef _MENU_H
#define _MENU_H

#include "stdio.h"
#include "string.h"
#include "conio.h"
#include "stdlib.h"
#include "_struct.h"
#include "_home.h"
#include "_new.h"
#include "_search.h"
#include "_edit.h"
#include "_delete.h"
#include "_display.h"
#include "_invalid.h"

void menu() {
	home();
	int option;
	scanf_s("%d", &option);
	while (option)
	{
		switch (option) {
		case 1: new(); break;
		case 2: search(); break;
		case 3: edit(); break;
		case 4: delete(); break;
		case 5: display(); break;
		default: invalid(); break;
		}
		system("pause>nul");  // 暂停case选项里的函数
		home();
		scanf_s("%d", &option);
	}
	if (option == 0) {
		printf("EXITED, THANKS!");
		return;
	}
	
	
}

#endif


 