#ifndef _COMPANY_SEARCH_H
#define _COMPANY_SEARCH_H

// ���� ������ϵ��
void company_search() {

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

	// �����������ϵ�˹�˾
	char company_search[20];
	printf(ENTER, "COMPANY");
	scanf_s("%s", &company_search, 20);

	// ����Ѱ�Ҵ�������ϵ��
	int flag = 0;
	for (int i = 0; i < count; i++) {

		// ���ִ�������ϵ��
		if (strcmp(company_search, contact[i].company) == 0) {

			flag = 1;

			//ȷ���Ƿ���ʾ
			printf(FIND, "DISPLAY");
			char display_confirm[100];
			scanf_s("%s", display_confirm, 100);

			// ִ����ʾ
			if (strcmp(display_confirm, "Y") == 0 || strcmp(display_confirm, "y") == 0) {
				system("cls");
				printf(CONTACT_INFORMATON_DIRECTORY);
				printf(HORIZONTAL_RULE);
				printf(FORMAT, DATA);
				printf(BACK_SEARCH_HONE);
				break;
			}

			// ��ִ�� ���� ��Чȷ��
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
	// δ���ִ�������ϵ��
	if (flag == 0) {
		printf(NOT_FOUND);
		printf(EXIT);
	}
}

#endif