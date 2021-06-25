#ifndef _DELETE_H
#define _DELETE_H


// ���� ɾ����ϵ��
void delete() {

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

	// �����ɾ����ϵ������
	char delete_name[20];
	printf(ENTER_NAME);
	scanf_s("%s", &delete_name, 20);

	// ����Ѱ�Ҵ�ɾ����ϵ��
	int flag = 0;
	for (int i = 0; i < count; i++) {

		// ���ִ�ɾ����ϵ��
		if (strcmp(delete_name, contact[i].name) == 0) {

			flag = 1;

			// ��ӡ����ϵ����Ϣ
			system("cls");
			printf(CONTACT_INFORMATON_DIRECTORY);
			printf(HORIZONTAL_RULE);
			printf(FORMAT, DATA);

			// ȷ���Ƿ�ɾ��
			printf(FIND, "DELETE");
			char delete_confirm[100];
			scanf_s("%s", delete_confirm, 100);

			// ִ��ɾ��
			if (strcmp(delete_confirm, "Y") == 0 || strcmp(delete_confirm, "y") == 0) {

				//��ʾִ��ɾ�����
				printf(HORIZONTAL_RULE);
				printf(SUCCESSFULLY, contact[i].name, "DELETED");  // �ź�����ɾ������ ��ʾ����ȷ
				printf(HORIZONTAL_RULE);
				printf(BACK_HOME);

				// ɾ����ϵ����Ϣ
				for (int j = i; j < count; j++) {
					contact[j] = contact[j + 1]; // �ѽṹ��Ӷ�λ�ĵط���ǰ��һλ
				}
				count--;

				
				// ɾ����д���ļ�
			    err = fopen_s(&fp, "data.txt", "w+b");
				for (int j = 0; j < count; j++) {
					fwrite(&contact[j], STRUCT_SIZE, 1, fp); 
				}
				fclose(fp);
				break;

			}

			// ��ִ�� ���� ��Чȷ��
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
	// δ���ִ�ɾ����ϵ��
	if (flag == 0) {
		printf(NOT_FOUND);
		printf(EXIT);
	}
}
#endif