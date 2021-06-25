#ifndef _EDIT_H
#define _EDIT_H


// ���� �༭��ϵ��
void edit() {
	
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

	// ������༭��ϵ��
	char edit_name[20];
	printf(ENTER_NAME);
	scanf_s("%s", &edit_name, 20);
	
	// ����Ѱ�Ҵ��༭��ϵ��
	int flag = 0;
	for (int i = 0; i < count; i++) {

		// ���ִ��༭��ϵ��
		if (strcmp(edit_name, contact[i].name) == 0) {

			flag = 1;

			// ��ӡ����ϵ����Ϣ
			system("cls");
			printf(CONTACT_INFORMATON_DIRECTORY);
			printf(HORIZONTAL_RULE);
			printf(FORMAT, DATA);

			// ȷ���Ƿ�༭
			printf(FIND, "EDIT");
			char edit_confirm[100];
			scanf_s("%s", edit_confirm,100);

			// ִ�б༭
			if (strcmp(edit_confirm, "Y") == 0 || strcmp(edit_confirm, "y") == 0) {
				
				// ��¼ԭ������ϵ������
				char original_contact[20] = "\0";     
				strcpy_s(original_contact,20,  contact[i].name);

				// �޸���ϵ����Ϣ
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

				// ��ʾִ�б༭���
				printf(HORIZONTAL_RULE);
				printf(SUCCESSFULLY, original_contact, "EDITED");
				printf(HORIZONTAL_RULE);
				printf(BACK_HOME);

				// �༭��д���ļ�
				err = fopen_s(&fp, "data.txt", "w+b");
				for (int k = 0; k < count; k++) {
					fwrite(&contact[k], STRUCT_SIZE, 1, fp);   
				}
				fclose(fp);
				break;
			}

			// ��ִ�� ���� ��Чȷ��
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
	// δ���ִ��༭��ϵ��
	if (flag == 0) {
		printf(NOT_FOUND);
		printf(EXIT);
	}
}

#endif