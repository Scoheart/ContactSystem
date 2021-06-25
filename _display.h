#ifndef _DISPLAY_H
#define _DISPLAY_H


// 函数 显示联系人
void display() {

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

	// 显示全部联系人
	system("cls");    
	printf("THAT IS ALL YOUR CONTACTS:\n");  
	printf(PAGE, 1);
	printf(CONTACT_INFORMATON_DIRECTORY);
	printf(HORIZONTAL_RULE);

	for (int i = 0; i < count; i++) {
		printf(FORMAT, DATA);
		if ((i+1) % 10 == 0) {
			printf("\nPRESS ANY KEY TO NXET PAGE!");
			system("pause>nul");
			system("cls");
			
			printf("THAT IS ALL YOUR CONTACTS:\n");
			printf(PAGE, (i + 1) / 10 + 1);
			printf(CONTACT_INFORMATON_DIRECTORY);
			printf(HORIZONTAL_RULE);
		}

	}
	printf(BACK_HOME);

}

#endif