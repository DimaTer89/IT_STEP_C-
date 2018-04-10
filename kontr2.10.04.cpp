#include <iostream>
using namespace std;
void mycat(char *&str, char *ptr, char*endptr) {
	while (ptr < endptr) {
		*str++ = *ptr++;
	}
}
void main() {
	setlocale(LC_ALL, "rus");
	const int N = 30;
	char phone[N];
	char* kod;
	cout << " Введите номер : ";
	gets_s(phone);
	cout << phone << endl;
	char*buf;
	char*ptr = strtok_s(phone, "( )", &buf);
	kod = ptr;
	int code;
	code = atoi(kod);
	cout << " Код региона = "<< code << endl;
	char *number[3];
	char*tmp = strtok_s(NULL, "-", &buf);
	int i = 0;
	while (tmp != NULL) {
		number[i++] = tmp;
		tmp = strtok_s(NULL, "-", &buf);
		
	}
	char tele[N];
	char* temp=tele;
	for (int i = 0; i < 3; i++) {
		char * pPtr = number[i];
		char *len =number[i] + strlen(number[i])-1;
		mycat(temp, pPtr, (len + 1));
	}
	*temp = '\0';
	long teleNum;
	teleNum = atol(tele);
	cout << " Семизначный номер = " <<teleNum << endl;
	system("pause");
}
