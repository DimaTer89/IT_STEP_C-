/*Напишите функцию, которая принимает массив и количество элементов и возвращает среднее арифметическое всех элементов массива.
Используйте шаблон, чтобы обеспечить работу как с целыми, так и с вещественными массивами. Аналогично напишите функцию для печати массивов разных типов.*/
#include <iostream>
#include <time.h>
#define N 9
using namespace std;
template <typename myT>
void randArr(myT *a, int size) {
	for (int i = 0; i < size; i++, a++) {
		*a = rand() % 21-10;
	}
}
template <typename myT>
void printArr(myT *a, int size) {
	for (int i = 0; i < size; i++, a++) {
		cout <<" "<< *a;
	}
}
template <typename mT>
double middle(mT *a, int size) {
	double sum = 0;
	for(int i=0;i<size;i++,a++){
		sum += *a;
	}
	return (double)sum / size;
}
void main() {
	setlocale(LC_ALL, "rus");
	srand(time(0));
	int arr[N];
	double dArr[N];
	cout << " Массив целых чисел \n";
	randArr(arr, N);
	printArr(arr, N);
	cout << endl;
	printf(" Среднее арифметическое массива = %.2f \n",middle(arr, N));
	cout << " Массив вещественных чисел \n";
	randArr(dArr, N);
	printArr(dArr, N);
	cout << endl;
	printf (" Среднее арифметическое массива = %.2f\n",middle(dArr, N));
	system("pause");
}
