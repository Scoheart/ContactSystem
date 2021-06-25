#ifndef _EDIT_H
#define _EDIT_H


// 函数 编辑联系人
void edit() {
	
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

	// 输入待编辑联系人
	char edit_name[20];
	printf(ENTER_NAME);
	scanf_s("%s", &edit_name, 20);
	
	// 遍历寻找待编辑联系人
	int flag = 0;
	for (int i = 0; i < count; i++) {

		// 发现待编辑联系人
		if (strcmp(edit_name, contact[i].name) == 0) {

			flag = 1;

			// 打印该联系人信息
			system("cls");
			printf(CONTACT_INFORMATON_DIRECTORY);
			printf(HORIZONTAL_RULE);
			printf(FORMAT, DATA);

			// 确认是否编辑
			printf(FIND, "EDIT");
			char edit_confirm[100];
			scanf_s("%s", edit_confirm,100);

			// 执行编辑
			if (strcmp(edit_confirm, "Y") == 0 || strcmp(edit_confirm, "y") == 0) {
				
				// 记录原来的联系人名称
				char original_contact[20] = "\0";     
				strcpy_s(original_contact,20,  contact[i].name);

				// 修改联系人信息
				printf("EDIT NAME:");
				scanf_s("%s", &contact[i].name, 30);
				printf("EDIT COMPANY:");
				scanf_s("%s", &contact[i].company, 30);
				printf("EDIT HOME_PHONE:");
				scanf_s("%s", &contact[i].home_phone, 30);
				printf("EDIT MOBILE_PHONE:");
				scanf_s("%s", &contact[i].mobile_phone, 30);
				printf("EDIT GROUPS:");
				scanf_s("%s", &contact[i].groups, 30);
				printf("EDIT EMAIL:");
				scanf_s("%s", &contact[i].email, 30);
				printf("EDIT QQ:");
				scanf_s("%s", &contact[i].qq, 30);

				// 提示执行编辑完成
				printf(HORIZONTAL_RULE);
				printf(SUCCESSFULLY, original_contact, "EDITED");
				printf(HORIZONTAL_RULE);
				printf(BACK_HOME);

				// 编辑后写入文件
				err = fopen_s(&fp, "data.txt", "w+b");
				for (int k = 0; k < count; k++) {
					fwrite(&contact[k], STRUCT_SIZE, 1, fp);   
				}
				fclose(fp);
				break;
			}

			// 不执行 或者 无效确认
			if (strcmp(edit_confirm, "N") == 0 || strcmp(edit_confirm, "n") == 0) {
				printf(CANCEL, "EDIT");
				printf(BACK_HOME);
				break;
			}
			else {
				printf(INVALID);
				printf(BACK_HOME);
				break;
			}
		}
	}
	// 未发现待编辑联系人
	if (flag == 0) {
		printf(NOT_FOUND);
		printf(EXIT);
	}
}

#endif