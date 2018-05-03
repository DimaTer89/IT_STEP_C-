/*Задача частичного копирования файла. Программа запрашивает имена входного  и выходного текстовых файлов, а также начальный и конечный номера строк в исходном файле.
Нужно создать выходной файл и переписать в него указанные строки из входного файла. 
При некорректном вводе данных программа должна выдавать соответствующие сообщения и заканчивать работу.*/
#include <iostream>
using namespace std;
void main() {
	setlocale(LC_ALL, "rus");
	FILE*in, *out;
	const int M = 256;
	const int N = 20;
	char filename1[N], filename2[N];
	cout << " Введите имя файла ввода :";
	cin >> filename1;
	cout << " Введите имя файла вывода : ";
	cin >> filename2;
	if (fopen_s(&in, filename1, "r") != 0) {
		cout << " Не удалось открыть файл для чтения \n";
		system("pause");
		return;
	}
	if (fopen_s(&out, filename2, "w") != 0) {
		cout << " Не удалось открыть файл для записи \n";
		system("pause");
		return;
	}
	int kol = 0;
	char ch;
	char bufer[M];
	while (fgets(bufer, sizeof(bufer), in) != NULL) {
			kol++;
	}
	fseek(in, 0L, SEEK_SET);
	cout << " Количество строк в файле = " << kol << endl;
	cout << " Введите c какой строки копировать и до какой через пробел : ";
	int num[2];
	for (int i = 0; i < 2; i++) {
		cin >> num[i];
	}
	if (num[0]<1 ) {
		cout << " Неверно введённые данные \n";
		system("pause");
		return;
	}
	if (num[1]>kol) {
		cout << " Неверно введённые данные \n";
		system("pause");
		return;
	}
	if (num[0]>num[1]) {
		cout << " Неверно введённые данные \n";
		system("pause");
		return;
	}
	int score = 1;
	while (fgets(bufer,M,in) != NULL) {
		if(score>=num[0]&&score<=num[1])fputs(bufer, out);
		score++;
	}
	fclose(in);
	fclose(out);
	system("pause");
}
