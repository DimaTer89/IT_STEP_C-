/*Дано число n.Вывести YES, если n является точной степенью двойки, NO – в противном случае.Операцию возведения в степень нельзя использовать!*/
#include <iostream>
using namespace std;
bool vyvod(int *a) {
	if (*a % 2 == 0) {
		if (*a / 2 == 1) 
		return true;
		*a /= 2;
		vyvod(a);
		
	}
	else
		return false;
}
	
void main() {
	setlocale(LC_ALL, "rus");
	int num;
	cout << " Введите число :";
	cin >> num;
	int step = vyvod(&num);
	if (step)cout << " Yes ";
	else cout << " No ";
	cout << endl;
	system("pause");
}
