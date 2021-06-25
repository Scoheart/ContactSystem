#ifndef _COMPANY_SEARCH_H
#define _COMPANY_SEARCH_H

// 函数 搜索联系人
void company_search() {

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

	// 输入待搜索联系人公司
	char company_search[20];
	printf(ENTER, "COMPANY");
	scanf_s("%s", &company_search, 20);

	// 遍历寻找待搜索联系人
	int flag = 0;
	for (int i = 0; i < count; i++) {

		// 发现待搜索联系人
		if (strcmp(company_search, contact[i].company) == 0) {

			flag = 1;

			//确认是否显示
			printf(FIND, "DISPLAY");
			char display_confirm[100];
			scanf_s("%s", display_confirm, 100);

			// 执行显示
			if (strcmp(display_confirm, "Y") == 0 || strcmp(display_confirm, "y") == 0) {
				system("cls");
				printf(CONTACT_INFORMATON_DIRECTORY);
				printf(HORIZONTAL_RULE);
				printf(FORMAT, DATA);
				printf(BACK_SEARCH_HONE);
				break;
			}

			// 不执行 或者 无效确认
			if (strcmp(display_confirm, "N") == 0 || strcmp(display_confirm, "n") == 0) {
				printf(CANCEL, "DISPlAY");
				printf(EXIT);
				break;
			}
			else {
				printf(INVALID);
				printf(EXIT);
				break;
			}

		}
	}
	// 未发现待搜索联系人
	if (flag == 0) {
		printf(NOT_FOUND);
		printf(EXIT);
	}
}

#endif