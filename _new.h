#ifndef _NEW_H
#define _NEW_H


// 函数 新建联系人
void new(){

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
	}



	// 确认是否新建
	printf("NEW CONTACT? (ENTER Y/N):");
	char new_contact_confirm[100];
	scanf_s("%s", &new_contact_confirm,100);

	
	
	// 执行新建
	
	if (strcmp(new_contact_confirm, "Y") == 0 || strcmp(new_contact_confirm, "y") == 0) {

		int new_contact_count = 0;
		do
		{
			// 输入联系人信息
			system("cls");
			printf("-------------------------------------------------------NEW CONTACT------------------------------------------------------\n");
			printf("ADD NAME:");

			char contact_name[20] = "\0";
			scanf_s("%s", &contact_name, 20);

			// 判断联系人是否已存在
			for (int i = 0; i < count; i++) {
				if (strcmp(contact[i].name, contact_name) == 0) {   // 存在则退出
					printf(ALREADY_EXISTS);
					printf(BACK_HOME);
					return;
				}
			}

			// 未存在则继续输入信息
			strcpy_s(contact[new_contact_count].name,20, contact_name);
			printf("ADD COMPANY:");
			scanf_s("%s", &contact[new_contact_count].company, 30);
			printf("ADD HOME_PHONE:");
			scanf_s("%s", &contact[new_contact_count].home_phone, 30);
			printf("ADD MOBILE_PHONE:");
			scanf_s("%s", &contact[new_contact_count].mobile_phone, 30);
			printf("ADD GROUPS:");
			scanf_s("%s", &contact[new_contact_count].groups, 30);
			printf("ADD EMAIL:");
			scanf_s("%s", &contact[new_contact_count].email, 30);
			printf("ADD QQ:");
			scanf_s("%s", &contact[new_contact_count].qq, 30);

			// 新增后写入文件
			err = fopen_s(&fp, "data.txt", "a+b");
			fwrite(&contact[new_contact_count], STRUCT_SIZE, 1, fp);
			printf(HORIZONTAL_RULE);
			printf(SUCCESSFULLY, contact[new_contact_count].name, "ADDED");
			printf(HORIZONTAL_RULE);
			fclose(fp);

			err = fopen_s(&fp, "data.txt", "rb");
			count = 0;
			while (feof(fp) == 0) {
				if (fread(&contact[count], STRUCT_SIZE, 1, fp) == 1)
					count++;
			}
			fclose(fp);

			// 确认是否继续新建
			printf("CONTINUE TO ADD CONTACTS? (ENTER Y/N):");
			scanf_s("%s", new_contact_confirm, 100);
		} while (strcmp(new_contact_confirm, "Y") == 0 || strcmp(new_contact_confirm, "y") == 0);

		if (strcmp(new_contact_confirm, "N") == 0 || strcmp(new_contact_confirm, "n") == 0) {
			printf(CANCEL, "NEW CONTACT");
		}
		else {
			printf(INVALID);
		}

		printf(BACK_HOME);
		return;
	}

	// 不执行 或者 无效确认
	if (strcmp(new_contact_confirm, "N") == 0 || strcmp(new_contact_confirm, "n") == 0) {
		printf(CANCEL, "NEW CONTACT");
		printf(EXIT);
	}
	else {
		printf(INVALID);
		printf(EXIT);
	}
	
}

#endif