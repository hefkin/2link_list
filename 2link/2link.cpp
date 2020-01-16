#include <iostream>
#include <clocale>

using namespace std;

struct Node
{
	int d;
	Node* next;
	Node* prev;

};

void add(Node*& begin, int d);
Node* find(Node* begin, int i);
bool insert(Node*& begin, int key, int d);
void print(Node* begin);
bool remove(Node*& begin, int key);
void printend(Node* Node);


int main()
{
	int n, g, a, b, d;
	setlocale(LC_ALL, "Russian");
	Node* begin = nullptr;

	int e;
	do
	{
		cout << "Введите число: " << endl;
		cout << "1 - Заполнить и вывести двусвязный список" << endl;
		cout << "2 - Вывести" << endl;
		cout << "3 - Удалить из списка" << endl;
		cout << "4 - Добавить элемент после определенного элемента" << endl;
		cout << "5 - Вывести список в обратном порядке" << endl;
		cout << "6 - Добавить число в конец списка" << endl;
		cout << "7 - Выйти из программы" << endl;
		while (!(cin >> e) || (cin.peek() != '\n'))
		{
			cin.clear();
			cin.ignore((numeric_limits<streamsize>::max)(), '\n');
			cout << "Некоректные данные, попробуйте снова" << endl;
		}

		switch (e)
		{
		case 1:
		{
			for (int i = 1; i < 10; i++)
				add(begin, i);
			print(begin);
			cout << endl;
		}
		system("pause");
		system("cls");
		break;

		case 5:
		{
			printend(begin);
			cout << endl;
			system("pause");
			system("cls");
		}
		break;

		case 2:
		{
			print(begin);
			cout << endl;
			system("pause");
			system("cls");
		}
		break;

		case 4:
		{
			print(begin);
			cout << endl << "Введите цифру после которой хотите добавить число: ";
			while (!(cin >> a) || (cin.peek() != '\n'))
			{
				cin.clear();
				cin.ignore((numeric_limits<streamsize>::max)(), '\n');
				cout << "Некоректные данные, попробуйте снова" << endl;
			}
			cout << endl << "Введите число которое хотите добавить: ";
			while (!(cin >> b) || (cin.peek() != '\n'))
			{
				cin.clear();
				cin.ignore((numeric_limits<streamsize>::max)(), '\n');
				cout << "Некоректные данные, попробуйте снова" << endl;
			}
			insert(begin, a, b);
			print(begin);
			cout << endl;
			system("pause");
			system("cls");
		}
		break;

		case 3:
		{
			print(begin);
			cout << endl << "Введите цифру которую хоите удалить: " << endl;
			while (!(cin >> n) || (cin.peek() != '\n'))
			{
				cin.clear();
				cin.ignore((numeric_limits<streamsize>::max)(), '\n');
				cout << "Некоректные данные, попробуйте снова" << endl;
			}
			if (!remove(begin, n))cout << "Ошибка " << endl << endl;
			cout << "Обновлённй список: ";
			print(begin);
			cout << endl;
			system("pause");
			system("cls");
		}
		break;

		case 6:
		{
			cout << "Введите число которое хотите добавить в конец списка: " << endl;
			int i;
			int s;
			while (!(cin >> s) || (cin.peek() != '\n'))
			{
				cin.clear();
				cin.ignore((numeric_limits<streamsize>::max)(), '\n');
				cout << "Некоректные данные, попробуйте снова" << endl;
			}
			i = s;
			add(begin, i); print(begin);
			system("pause");
			system("cls");
		}
		break;

		case 7:
		{
			return 0;
			system("pause");
			system("cls");
		}
		break;

		default:
		{
			cout << "Введите цифру от 1 до 5: " << endl;
			system("pause");
			system("cls");
		}
		break;
		}

	}



	while (e != 8);
	system("Pause");
	return 0;
}

//поиск элемента по ключу 

Node* find(Node* begin, int d)
{
	Node* cur = begin;
	while (cur) {
		if (cur->d == d)break;
		cur = cur->next;
	}
	return cur;
}

//вставка элемента после заданного 

bool insert(Node*& begin, int key, int d) {
	Node* pkey = find(begin, key);
	if (!pkey) return false;
	Node* cur = new Node;
	cur->d = d;
	cur->next = pkey->next;
	cur->prev = pkey;
	pkey->next = cur;
	if (cur->next != nullptr) (cur->next)->prev = cur;
	return true;
}

//вывод обратного списка на экран 

void printend(Node* Node)
{
	if (Node) {
		printend(Node->next);
		cout << (Node->d) << ' ';
	}
}

//удаление элемента 

bool remove(Node*& begin, int key)
{
	{
		Node* cur = find(begin, key);
		if (!cur)return false;
		if (cur == begin) {
			begin = begin->next;
			if (begin)
				begin->prev = nullptr;
		}
		else
		{
			(cur->prev)->next = cur->next;
			if (cur->next != nullptr)(cur->next)->prev = cur->prev;
		}
		delete cur;
		return true;
	}
}

//добавление в конец списка 

void add(Node*& begin, int d)
{
	Node* cur = new Node;
	cur->d = d;
	cur->next = nullptr;
	if (!begin) { begin = cur; cur->prev = nullptr; }
	else
	{
		Node* temp = begin;
		while (temp->next)

			temp = temp->next;
		temp->next = cur;
		cur->prev = temp;


	}
}

//вывод списка на экран 

void print(Node* begin)
{
	Node* cur = begin;
	while (cur)
	{
		cout << cur->d << ' ';
		cur = cur->next;

	}
}