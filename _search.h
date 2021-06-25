#ifndef _SEARCH_H
#define _SEARCH_H

#include "_search_menu.h"

void search() {

	// 以读的方式打开文件//
	FILE* fp;
	errno_t err = fopen_s(&fp, "data.txt", "rb");

	// 读取并且记录联系人数量
	int count = 0;
	while (feof(fp) == 0) {
		if (fread(&contact[count], STRUCT_SIZE, 1, fp) == 1)
			count++;
	}
	fclose(fp);

	// 判断当前通讯录是否为空//
	if (count == 0) {
		printf(BLANK_RECORD);
		printf(EXIT);
		return;
	}

	search_menu();
}




#endif