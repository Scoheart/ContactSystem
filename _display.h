#ifndef _DISPLAY_H
#define _DISPLAY_H


// ���� ��ʾ��ϵ��
void display() {

	// �Զ��ķ�ʽ���ļ�//
	FILE* fp;
	errno_t err = fopen_s(&fp, "data.txt", "rb");

	// ��ȡ���Ҽ�¼��ϵ������
	int count = 0;
	while (feof(fp) == 0) {
		if (fread(&contact[count], STRUCT_SIZE, 1, fp) == 1)
			count++;
	}
	fclose(fp);

	// �жϵ�ǰͨѶ¼�Ƿ�Ϊ��//
	if (count == 0) {
		printf(BLANK_RECORD);
		printf(EXIT);
		return;
	}

	// ��ʾȫ����ϵ��
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