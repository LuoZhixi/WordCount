#include<stdio.h>
#include<string.h>
int main(int argc, char* argv[]) {
	int word = 0;
	char ch;
	FILE* file;
	errno_t err = fopen_s(&file,argv[2], "r");
	if (err == 0) {
		if (!strcmp(argv[1], "-c") || !strcmp(argv[1], "-C")) {
			while ((ch = fgetc(file)) != EOF) {
				if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')) {
					word++;
				}
				else if (ch == ' ' || ch == '\t') {
					word++;
				}
			}
			printf("字符数为:%d", word);
		}
		else if (!strcmp(argv[1],"-w") || !strcmp(argv[1], "-W")) {
			int flag = 0;
			while ((ch = fgetc(file)) != EOF) {
				if (ch == ',' || ch == ' ') {
					if (flag == 0) {
						word++;
						flag = 1;
					}
				}
				else {
					flag = 0;
				}
			}
			printf("单词数:%d", word);
		}
		if (file != NULL) {
			fclose(file);
		}
	}
}