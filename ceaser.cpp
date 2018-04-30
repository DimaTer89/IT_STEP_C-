#include <stdio.h>
#include <locale>
#include <iostream>
#define ENG 26
#define RUS 32
using namespace std;
void  encrypt(FILE* &in,FILE* &out,int n)
{
	int flag;
	char c;
	c = getc(in);
	while (!feof(in))
	{
		flag = 0; //обработан ли текущий символ
		if (c >= 'A' && c <= 'Z')
		{
			c = c + (n % ENG);
			if (c > 'Z') c = 'A' + (c - 'Z') - 1;
			fprintf(out, "%c", c);
			flag = 1;
		}
		if (c >= 'a' && c <= 'z')
		{
			c = c + (n % ENG);
			if (c > 'z') c = 'a' + (c - 'z') - 1;
			fprintf(out, "%c", c);
			flag = 1;
		}
		if (c >= 'А' && c <= 'Я')
		{
			c = c + (n % RUS);
			if (c > 'Я') c = 'А' + (c - 'Я') - 1;
			fprintf(out, "%c", c);
			flag = 1;
		}
		if (c >= 'а' && c <= 'я')
		{
			c = c + (n % RUS);
			if (c > 'я') c = 'а' + (c - 'я') - 1;
			fprintf(out, "%c", c);
			flag = 1;
		}
		if (!flag) fprintf(out, "%c", c);
		c = getc(in);
	}
	
}

void decipher(FILE* &in,FILE* &out,int n)
{
	int flag;
	char c;
	c = getc(in);
	while (!feof(in))
	{
		flag = 0;
		if (c >= 'A' && c <= 'Z')
		{
			c = c - (n % ENG);
			if (c < 'A') c = 'Z' - ('A' - c) + 1;
			fprintf(out, "%c", c);
			flag = 1;
		}
		if (c >= 'a' && c <= 'z')
		{
			c = c - (n % ENG);
			if (c < 'a') c = 'z' - ('a' - c) + 1;
			fprintf(out, "%c", c);
			flag = 1;
		}
		if (c >= 'А' && c <= 'Я')
		{
			c = c - (n % RUS);
			if (c < 'А') c = 'Я' - ('А' - c) + 1;
			fprintf(out, "%c", c);
			flag = 1;
		}
		if (c >= 'а' && c <= 'я')
		{
			c = c - (n % RUS);
			if (c < 'а') c = 'я' - ('а' - c) + 1;
			fprintf(out, "%c", c);
			flag = 1;
		}
		if (!flag) fprintf(out, "%c", c);
		c = getc(in);
	}
}
void main()
{
	setlocale(LC_ALL, "Russian");
	FILE *fp1, *fp2;
	const int N = 128;
	char filename[N], filenameRes[N];
	cout << " ВВедите имя файла ввода : ";
	gets_s(filename,N);
	cout << " ВВедите имя файла вывода : ";
	gets_s(filenameRes, N);
	fopen_s(&fp1, filename, "r");
	fopen_s(&fp2, filenameRes, "w");
	if (fp1 == NULL) {
		cout << " Неправильное имя файла ввода \n";
		system("pause");
		exit(1);
	}
	if (fp2 == NULL) {
		cout << " Неправильное имя файла вывода \n";
		system("pause");
		exit(1);
	}
	int n;
	do {
		cout<<"Введите ключ шифра : ";
		cin >> n;
		if (n < 1)cout << " Введите положительное число \n";
	} while (n < 1);
	
	char c;
	do {
		cout<<"Чтобы зашифровать текст введите a, расшифровать b: ";
		cin >> c;
		if (c < 'a' || c > 'b')cout << " Неверный ввод , введите снова \n";
	} while (c < 'a' || c > 'b');
	if (c == 'a') encrypt(fp1,fp2,n);
	if (c == 'b') decipher(fp1,fp2,n);
	fclose(fp1);
	fclose(fp2);
}
