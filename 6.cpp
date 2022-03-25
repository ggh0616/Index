#include <iostream>
#include <Windows.h>

using namespace std;

#define SIZE 50

typedef struct Champ
{
	char name[20];
	int hp;
	int mp;
	int speed;
	int range;
	char position[20];
}Champ;

Champ arr[SIZE]
{
	{"����", 620, 0, 340, 175, "top"},
	{"������", 562, 500, 335, 125, "mid"},
	{"����", 515, 231, 330, 550, "bot"},
	{"Ƽ��", 528, 267, 330, 500, "top"},
	{"�Ҷ�ī", 535, 425, 325, 550, "support"},
	{"����", 585, 275, 345, 125, "jungle"},
	{"����ũ��ũ", 582, 267, 325, 125, "support"},
	{"��", 532, 268, 335, 525, "top"},
	{"������", 620, 0, 350, 500, "bot"},
	{"�ú�", 530, 300, 325, 350, "bot"},
	{"�𸣰���", 500, 350, 320, 550, "support"},
	{"�ڸ�Ű", 550, 450, 125, 330, "mid"},
	{"����", 619, 0, 350, 250, "jungle"},
	{"����Ÿ �۶�ũ", 500, 235, 330, 125, "support"},
	{"�ڸ�Ű", 500, 340, 330, 500, "mid"},
	{"�ٵ�", 490, 300, 330, 300, "support"},
	{"�ٷ罺", 510, 250, 345, 570, "bot"},
	{"��", 620, 0, 330, 200, "top"},
	{"�ֽ�", 500, 350, 330, 500, "bot"},
	{"������", 550, 400, 325, 400, "mid"}
};

void Menu();
void search_Champ(Champ* arr, int number, bool end, bool isFind);
void insert_Champ(Champ* arr, int* number, bool end);
void delete_Champ(Champ* arr, int* number, bool end, bool isFind);
void delete_Position(Champ* arr, int* number, bool end, bool isFind);
void printAll_Champ(Champ* arr, int number);
void print_MaxHp(Champ* arr, int number);
void sortByHp(Champ* arr, int number);

int main()
{
	Menu();
}

void Menu()
{
	int number = 20;
	bool end = true;
	bool isFind = false;
	while (end)
	{
		system("cls");
		cout << "0 : ����" << endl;
		cout << "1 : è�Ǿ� �˻�" << endl;
		cout << "2 : è�Ǿ� �߰�" << endl;
		cout << "3 : è�Ǿ� ����" << endl;
		cout << "4 : ������ ����" << endl;
		cout << "5 : è�Ǿ� ���" << endl;
		cout << "6 : �ִ� ü�� ���" << endl;
		cout << "7 : ü�� ������ ����" << endl;
		int insert_Number;
		cout << "�Է� : ";
		rewind(stdin);
		cin >> insert_Number;
		if (cin.fail()) {
			cout << "�߸��� ���ڰ� �ԷµǾ����ϴ�. �ٽ� �Է����ּ���" << endl;
			system("pause");
			cin.clear();
			rewind(stdin);
			continue;
		}
		switch (insert_Number)
		{
		case 0:
			end = false;
			cout << "���α׷��� �����մϴ�." << endl;
			break;
		case 1:
			search_Champ(arr, number, end, isFind);
			break;
		case 2:
			insert_Champ(arr, &number, end);
			break;
		case 3:
			delete_Champ(arr, &number, end, isFind);
			break;
		case 4:
			delete_Position(arr, &number, end, isFind);
			break;
		case 5:
			printAll_Champ(arr, number);
			break;
		case 6:
			print_MaxHp(arr, number);
			break;
		case 7:
			sortByHp(arr, number);
			break;
		default:
			cout << "�߸��� ���ڰ� �ԷµǾ����ϴ�." << endl;
			system("pause");
			continue;
		}
	}
}

void search_Champ(Champ* arr, int number, bool end, bool isFind)
{
	char search_Name[20];
	while (end) {
		system("cls");
		cout << "�˻��� è�Ǿ��� �̸��� �Է��Ͻÿ� : ";
		rewind(stdin);
		cin >> search_Name;
		for (int i = 0; i < number; ++i)
		{
			if (!strcmp(search_Name, arr[i].name)) {
				end = false;
				isFind = true;
				cout << "name : " << arr[i].name << endl;
				cout << "hp : " << arr[i].hp << endl;
				cout << "mp : " << arr[i].mp << endl;
				cout << "speed : " << arr[i].speed << endl;
				cout << "range : " << arr[i].range << endl;
				cout << "position : " << arr[i].position << endl;
			}
			else if (i == number - 1 && !isFind) {
				cout << "���� è�Ǿ� �Դϴ�." << endl;
			}
		}
		system("pause");
		if (!end)
			break;
	}
}

void insert_Champ(Champ* arr, int* number, bool end)
{
	while (end) {
		system("cls");
		cout << "�߰��� è�Ǿ��� ������ �Է��Ͻÿ�" << endl;
		cout << "name : ";
		cin >> arr[*number].name;
		cout << "hp : ";
		cin >> arr[*number].hp;
		if (cin.fail()) {
			cout << "���ڰ� �ƴ� ���ڰ� �ԷµǾ����ϴ�. �ٽ� �Է����ּ���" << endl;
			system("pause");
			cin.clear();
			rewind(stdin);
			continue;
		}
		cout << "mp : ";
		cin >> arr[*number].mp;
		if (cin.fail()) {
			cout << "���ڰ� �ƴ� ���ڰ� �ԷµǾ����ϴ�. �ٽ� �Է����ּ���" << endl;
			system("pause");
			cin.clear();
			rewind(stdin);
			continue;
		}
		cout << "speed : ";
		cin >> arr[*number].speed;
		if (cin.fail()) {
			cout << "���ڰ� �ƴ� ���ڰ� �ԷµǾ����ϴ�. �ٽ� �Է����ּ���" << endl;
			system("pause");
			cin.clear();
			rewind(stdin);
			continue;
		}
		cout << "range : ";
		cin >> arr[*number].range;
		if (cin.fail()) {
			cout << "���ڰ� �ƴ� ���ڰ� �ԷµǾ����ϴ�. �ٽ� �Է����ּ���" << endl;
			system("pause");
			cin.clear();
			rewind(stdin);
			continue;
		}
		cout << "position : ";
		cin >> arr[*number].position;
		cout << arr[*number].name << " �߰� �Ϸ�" << endl;
		*number = *number + 1;
		end = false;
		system("pause");
		if (!end)
			break;
	}
}

void delete_Champ(Champ* arr, int* number, bool end, bool isFind)
{
	char delete_Name[20];
	while (end)
	{
		system("cls");
		cout << "������ è�Ǿ��� �̸��� �Է��Ͻÿ� : ";
		rewind(stdin);
		cin >> delete_Name;
		for (int i = 0; i < *number; ++i)
		{
			if (!strcmp(delete_Name, arr[i].name)) {
				end = false;
				isFind = true;
				cout << arr[i].name << " ���� �Ϸ�" << endl;
				ZeroMemory(&arr[i], sizeof(arr[i]));
				*number = *number - 1;
			}
			else if (i == *number - 1 && !isFind) {
				cout << "�������� �ʴ� è�Ǿ��Դϴ�." << endl;
			}
		}
		system("pause");
		if (!end)
			break;
	}
}

void delete_Position(Champ* arr, int* number, bool end, bool isFind)
{
	char delete_PositionName[20];
	while (end)
	{
		system("cls");
		cout << "������ �������� �̸��� �Է��Ͻÿ� : ";
		rewind(stdin);
		cin >> delete_PositionName;
		for (int i = 0; i < *number; ++i)
		{
			if (!strcmp(delete_PositionName, arr[i].position)) {
				end = false;
				isFind = true;
				cout << arr[i].position << " ���� �Ϸ�" << endl;
				ZeroMemory(&arr[i], sizeof(arr[i]));
			}
			else if (i == *number - 1 && !isFind) {
				cout << "�������� �ʴ� ������ �Դϴ�. �ٽ� �Է����ּ���" << endl;
			}
		}
		system("pause");
		if (!end)
			break;
	}
}

void printAll_Champ(Champ* arr, int number)
{
	system("cls");
	for (int i = 0; i < number; ++i)
	{
		if (arr[i].hp != 0) {
			cout << "name : " << arr[i].name << endl;
			cout << "hp : " << arr[i].hp << endl;
			cout << "mp : " << arr[i].mp << endl;
			cout << "speed : " << arr[i].speed << endl;
			cout << "range : " << arr[i].range << endl;
			cout << "position : " << arr[i].position << endl;
		}
	}
	system("pause");
}

void print_MaxHp(Champ* arr, int number)
{
	system("cls");
	int maxHp = 0;
	for (int i = 0; i < number; ++i)
	{
		if (maxHp < arr[i].hp) {
			maxHp = arr[i].hp;
		}
	}
	cout << "maxHp : " << maxHp << endl;
	for (int j = 0; j < number; ++j)
	{
		if (arr[j].hp == maxHp) {
			cout << "hp : " << arr[j].name << endl;
		}
	}
	system("pause");
}

void sortByHp(Champ* arr, int number)
{
	system("cls");
	Champ temp;
	for (int i = 0; i < number - 1; ++i)
	{
		for (int j = i; j < number; ++j)
		{
			if (arr[i].hp < arr[j].hp) {
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}	
	cout << "���� �Ϸ�" << endl;
	system("pause");
}
