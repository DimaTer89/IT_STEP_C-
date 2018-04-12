/*Разработать набор функций для работы с очередью (создание очереди (добавление одного первого элемента),
добавление в конец очереди, извлечение из начала очереди,
проверка пустоты очереди, печать содержимого очереди, подсчет количества элементов в очереди, очистка очереди).
Проиллюстрировать их работу на примере.*/
#include <iostream>
using namespace std;
struct Node {
	int data;
	Node* next;
};
void addQueue(int data, Node* &Head, Node* &Tail) {
	Node *elem = new Node;
	elem->data = data;
	elem->next = NULL;
	Head = elem;
	Tail = elem;
}
void showQueue(Node* Head) {
	Node*tmp = Head;
	cout << " Содержание очереди : ";
	while (tmp != NULL) {
		cout << " " << tmp->data;
		tmp = tmp->next;
	}
	cout << endl;
}
void DobElem(int data, Node* &Tail) {
	Node*elem = new Node;
	elem->data = data;
	elem->next = NULL;
	Tail->next = elem;
	Tail = elem;
}
int UdalElem(Node* &Head) {
	if (!Head)return 0;
	int data = Head->data;
	Node*tmp = Head;
	Head = Head->next;
	delete tmp;
	return data;
}
void clearQueue(Node*&Head) {
	Node *Next;
	while (Head) {
		Next = Head->next;
		delete Head;
		Head = Next;
	}
}
int count(Node*Head) {
	if (Head == NULL)return 0;
	Node* tmp = Head;
	int kol = 0;
	while (tmp != NULL) {
		kol++;
		tmp = tmp->next;
	}
	return kol;
}
void main() {
	setlocale(LC_ALL, "rus");
	int menu;
	Node *Head = NULL;
	Node *Tail;
	do {
		cout << " Выберите номер операции \n";
		cout << " 1 - создание очереди \n";
		cout << " 2 - добавление в конец очереди \n";
		cout << " 3 - извлечение из начала очереди \n";
		cout << " 4 - проверка пустоты очереди \n";
		cout << " 5 - печать содержимого очереди \n";
		cout << " 6 - подсчёт количества элементов очереди \n";
		cout << " 7 - очистка очереди \n";
		cout << " 0 - выход \n";
		cin >> menu;
		switch (menu) {
		case 1:
			if (Head != NULL) {
				cout << " Очередь создана !\n";
				break;
			}
			int elem;
			cout << " Введите элемент : ";
			cin >> elem;
			addQueue(elem, Head, Tail);
			cout << " Успешно выполнено \n";
			break;
		case 2:
			if (Head == NULL) {
				cout << " Очередь не создана \n";
				break;
			}
			int num;
			cout << " Введите элемент : ";
			cin >> num;
			DobElem(num, Tail);
			break;
		case 3:
			UdalElem(Head);
			cout << " Успешно выполнено \n";
			break;
		case 4:
			if (Head != NULL)cout << " Очередь не пуста \n";
			else cout << " Очередь пуста \n";
			break;
		case 5:
			if (Head == NULL) {
				cout << " Очередь пуста \n";
				break;
			}
			showQueue(Head);
			break;
		case 6:
			cout << " В очереди " << count(Head) << " элемента \n";
			break;
		case 7:
			clearQueue(Head);
			cout << " Очередь очищена .\n";
			break;
		case 0:
			clearQueue(Head);
			cout << " Очередь очищена.\n";
			break;
		}
	} while (menu != 0);
	system("pause");
}
