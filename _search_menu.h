#ifndef _SEARCH_MENU_H
#define _SEARCH_MENU_H

#include "stdio.h"
#include "string.h"
#include "conio.h"
#include "_struct.h"
#include "_search_home.h"
#include "_name_search.h"
#include "_company_search.h"
#include "_home_phone_search.h"
#include "_mobile_phone_search.h"
#include "_groups_search.h"
#include "_email_search.h"
#include "_qq_search.h"
#include "_invalid.h"

void search_menu() {
	search_home();
	int option;
	scanf_s("%d", &option);
	if (option == 0) {
		printf(CANCEL, "SEARCH");
		printf(BACK_HOME);
		return;
	}
	while (option)
	{
		switch (option)
		{
		case 1: name_search(); break;
		case 2: company_search(); break;
		case 3: home_phone_search(); break;
		case 4: mobile_phone_search(); break;
		case 5: groups_search(); break;
		case 6: email_search(); break;
		case 7: qq_search(); break;
		default: invalid(); break;
		}
		system("pause>nul");  // 暂停case选项里的函数
		search_home();
		scanf_s("%d", &option);
	}
}

#endif