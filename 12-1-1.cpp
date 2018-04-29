/*#include <iostream>
#include <stdio.h>
using namespace std;
void main() {
	setlocale(LC_ALL, "rus");
	char ch;
	int num = 0;
	while ((ch=getchar())!=EOF) {
		if(ch !=' '&&ch!='\n')num++;
	}
	cout << " В строке " << num << " символов \n";
}*/
#include <iostream>
#include <stdio.h>
using namespace std;
void main() {
	setlocale(LC_ALL, "rus");
	FILE *in, *out;
	freopen_s(&in, "test.txt", "r", stdin);
	freopen_s(&out, "tst.txt", "w", stdout);
	char ch;
	int num = 0;
	while ((ch = getchar()) != EOF) {
		if (ch != ' '&&ch != '\n')num++;
	}
	cout << " В строке " << num << " символов \n";
	fclose(in);
	fclose(out);
}
