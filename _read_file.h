#ifndef _READ_FILE_H
#define _READ_FILE_H

// ���� �½�һ��ͨѶ¼�ļ�
void read_file() {
	FILE* fp;
	errno_t err;
	if ((err = fopen_s(&fp, "data.txt", "a")) == NULL) {
		fclose(fp);
		return;
	}
}

#endif
