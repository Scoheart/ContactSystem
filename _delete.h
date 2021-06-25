#ifndef _DELETE_H
#define _DELETE_H


// 函数 删除联系人
void delete() {

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

	// 输入待删除联系人姓名
	char delete_name[20];
	printf(ENTER_NAME);
	scanf_s("%s", &delete_name, 20);

	// 遍历寻找待删除联系人
	int flag = 0;
	for (int i = 0; i < count; i++) {

		// 发现待删除联系人
		if (strcmp(delete_name, contact[i].name) == 0) {

			flag = 1;

			// 打印该联系人信息
			system("cls");
			printf(CONTACT_INFORMATON_DIRECTORY);
			printf(HORIZONTAL_RULE);
			printf(FORMAT, DATA);

			// 确认是否删除
			printf(FIND, "DELETE");
			char delete_confirm[100];
			scanf_s("%s", delete_confirm, 100);

			// 执行删除
			if (strcmp(delete_confirm, "Y") == 0 || strcmp(delete_confirm, "y") == 0) {

				//提示执行删除完成
				printf(HORIZONTAL_RULE);
				printf(SUCCESSFULLY, contact[i].name, "DELETED");  // 放后面是删除的了 提示不正确
				printf(HORIZONTAL_RULE);
				printf(BACK_HOME);

				// 删除联系人信息
				for (int j = i; j < count; j++) {
					contact[j] = contact[j + 1]; // 把结构体从定位的地方往前移一位
				}
				count--;

				
				// 删除后写入文件
			    err = fopen_s(&fp, "data.txt", "w+b");
				for (int j = 0; j < count; j++) {
					fwrite(&contact[j], STRUCT_SIZE, 1, fp); 
				}
				fclose(fp);
				break;

			}

			// 不执行 或者 无效确认
			if (strcmp(delete_confirm, "N") == 0 || strcmp(delete_confirm, "n") == 0) {
				printf(CANCEL, "DELETE");
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
	// 未发现待删除联系人
	if (flag == 0) {
		printf(NOT_FOUND);
		printf(EXIT);
	}
}
#endif