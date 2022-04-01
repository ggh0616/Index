#include <iostream>
#include <Windows.h>

using namespace std;

#define SIZE 50

int number = 20;

typedef struct Champ
{
	char name[20];
	int hp;
	int mp;
	int speed;
	int range;
	char position[20];
};
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
	{"���縮����", 620, 0, 350, 500, "bot"},
	{"�ú�", 530, 300, 325, 350, "bot"},
	{"�𸣰���", 500, 350, 320, 550,  "support"},
	{"�ڸ�Ű", 550, 450, 125, 330, "mid"},
	{"����", 619, 0, 350, 250, "jungle"},
	{"����Ÿ �۶�ũ", 500, 235, 330, 125, "support"},
	{"�����", 500, 340, 330, 500, "mid"},
	{"�ٵ�", 490, 300, 330, 300, "support"},
	{"�ٷ罺", 510, 250, 345, 570, "bot"},
	{"��", 620, 0, 330, 200, "top"},
	{"�ֽ�", 500, 350, 330, 500, "bot"},
	{"������", 550, 400, 325, 400, "mid"}
};

void Menu();
void search_Champ(Champ* arr, int number);
void search_Champ_R(Champ* arr, int number, char* search_Name, bool isFind);
void insert_Champ(Champ* arr, int* number);
void delete_Champ(Champ* arr, int number);
void delete_Champ_R(Champ* arr, int number, char* delete_Name, bool isFind);
void delete_Position(Champ* arr, int number);
void delete_Position_R(Champ* arr, int number, char* delete_PositionName, bool isFind);
void printAll_Champ(Champ* arr, int number);
void printAll_Champ_R(Champ* arr, int number);
void find_MaxHp(Champ* arr, int number);
void find_MaxHp_R(Champ* arr, int number, int maxHp, bool isFind);
void sort_ByHp(Champ* arr, int number);
void sort_ByHp_R(Champ* arr, int number, int sort_Number);
void Sort(Champ* x, Champ* y);

int main()
{
	Menu();
}

void Menu()
{
	system("cls");
	cout << "0 : �ý��� ����" << endl;
	cout << "1 : è�Ǿ� �˻�" << endl;
	cout << "2 : è�Ǿ� �߰�" << endl;
	cout << "3 : è�Ǿ� ����" << endl;
	cout << "4 : ������ ����" << endl;
	cout << "5 : è�Ǿ� ���" << endl;
	cout << "6 : �ִ� ü���� è�Ǿ� ���� ���" << endl;
	cout << "7 : ü�¼����� ����" << endl;
	int switch_Number;
	cout << "�Է� : ";
	rewind(stdin);
	cin >> switch_Number;
	if (cin.fail()) {
		cout << "���ڰ� �ƴ� ���ڰ� �ԷµǾ����ϴ�. �ٽ� �Է����ּ���" << endl;
		system("pause");
		cin.clear();
		rewind(stdin);
		Menu();
	}
	switch (switch_Number)
	{
	case 0:
		cout << "���α׷��� �����մϴ�." << endl;
		break;
	case 1:
		search_Champ(arr, number);
		Menu();
		break;
	case 2:
		insert_Champ(arr, &number);
		Menu();
		break;
	case 3:
		delete_Champ(arr, number);
		Menu();
		break;
	case 4:
		delete_Position(arr, number);
		Menu();
		break;
	case 5:
		printAll_Champ(arr, number);
		Menu();
		break;
	case 6:
		find_MaxHp(arr, number);
		Menu();
		break;
	case 7:
		sort_ByHp(arr, number);
		Menu();
		break;
	default:
		cout << "�߸��� ������ ���ڰ� �ԷµǾ����ϴ�. �ٽ� �Է����ּ���" << endl;
		Menu();
		break;
	}
}

void search_Champ(Champ* arr, int number)
{
	system("cls");
	char search_Name[20];
	cout << "�˻��� è�Ǿ��� �̸��� �Է��Ͻÿ� : ";
	rewind(stdin);
	cin >> search_Name;
	search_Champ_R(arr, number, search_Name, false);
	system("pause");
}

void search_Champ_R(Champ* arr, int number, char* search_Name, bool isFind)
{
	if (number == -1)
		return;
	else if (!strcmp(search_Name, arr[number - 1].name)) {
		isFind = true;
		search_Champ_R(arr, number - 1, search_Name, isFind);
		cout << "name : " << arr[number - 1].name << endl;
		cout << "hp : " << arr[number - 1].hp << endl;
		cout << "mp : " << arr[number - 1].mp << endl;
		cout << "speed : " << arr[number - 1].speed << endl;
		cout << "range : " << arr[number - 1].range << endl;
		cout << "position : " << arr[number - 1].position << endl;
	}
	else if (number == 0 && !isFind)
		cout << "�������� �ʴ� è�Ǿ��Դϴ�." << endl;
	else
		search_Champ_R(arr, number - 1, search_Name, isFind);
}

void insert_Champ(Champ* arr, int* number)
{
	system("cls");
	cout << "�߰��� è�Ǿ��� ������ �Է��Ͻÿ�" << endl;
	cout << "name : ";
	rewind(stdin);
	cin >> arr[*number].name;
	cout << "hp : ";
	rewind(stdin);
	cin >> arr[*number].hp;
	if (cin.fail()) {
		cout << "���ڰ� �ƴ� ���ڰ� �ԷµǾ����ϴ�. �ٽ� �Է����ּ���" << endl;
		system("pause");
		cin.clear();
		rewind(stdin);
		return;
	}
	cout << "mp : ";
	rewind(stdin);
	cin >> arr[*number].mp;
	if (cin.fail()) {
		cout << "���ڰ� �ƴ� ���ڰ� �ԷµǾ����ϴ�. �ٽ� �Է����ּ���" << endl;
		system("pause");
		cin.clear();
		rewind(stdin);
		return;
	}
	cout << "speed : ";
	rewind(stdin);
	cin >> arr[*number].speed;
	if (cin.fail()) {
		cout << "���ڰ� �ƴ� ���ڰ� �ԷµǾ����ϴ�. �ٽ� �Է����ּ���" << endl;
		system("pause");
		cin.clear();
		rewind(stdin);
		return;
	}
	cout << "range : ";
	rewind(stdin);
	cin >> arr[*number].range;
	if (cin.fail()) {
		cout << "���ڰ� �ƴ� ���ڰ� �ԷµǾ����ϴ�. �ٽ� �Է����ּ���" << endl;
		system("pause");
		cin.clear();
		rewind(stdin);
		return;
	}
	cout << "position : ";
	rewind(stdin);
	cin >> arr[*number].position;
	cout << arr[*number].name << " �߰� �Ϸ�" << endl;
	*number = *number + 1;
	system("pause");
}

void delete_Champ(Champ* arr, int number)
{
	system("cls");
	char delete_Name[20];
	cout << "������ è�Ǿ��� �̸��� �Է��Ͻÿ� : ";
	rewind(stdin);
	cin >> delete_Name;
	delete_Champ_R(arr, number, delete_Name, false);
	system("pause");
}

void delete_Champ_R(Champ* arr, int number, char* delete_Name, bool isFind)
{
	if (number == -1)
		return;
	else if (!strcmp(delete_Name, arr[number - 1].name)) {
		isFind = true;
		delete_Champ_R(arr, number - 1, delete_Name, isFind);
		cout << arr[number - 1].name << " ���� �Ϸ�" << endl;
		ZeroMemory(&arr[number - 1], sizeof(arr[number - 1]));
	}
	else if (number == 0 && !isFind)
		cout << "�������� �ʴ� è�Ǿ��Դϴ�." << endl;
	else
		delete_Champ_R(arr, number - 1, delete_Name, isFind);
}

void delete_Position(Champ* arr, int number)
{
	system("cls");
	char delete_PositionName[20];
	cout << "������ è�Ǿ��� �̸��� �Է��Ͻÿ� : ";
	rewind(stdin);
	cin >> delete_PositionName;
	delete_Champ_R(arr, number, delete_PositionName, false);
	system("pause");
}

void delete_Position_R(Champ* arr, int number, char* delete_PositionName, bool isFind)
{
	if (number == -1)
		return;
	else if (!strcmp(delete_PositionName, arr[number - 1].name)) {
		isFind = true;
		delete_Position_R(arr, number - 1, delete_PositionName, isFind);
		cout << arr[number - 1].name << " ���� �Ϸ�" << endl;
		ZeroMemory(&arr[number - 1], sizeof(arr[number - 1]));
	}
	else if (number == 0 && !isFind)
		cout << "�������� �ʴ� è�Ǿ��Դϴ�." << endl;
	else
		delete_Position_R(arr, number - 1, delete_PositionName, isFind);
}

void printAll_Champ(Champ* arr, int number)
{
	system("cls");
	printAll_Champ_R(arr, number);
	system("pause");
}

void printAll_Champ_R(Champ* arr, int number)
{
	if (number == -1)
		return;
	else if (arr[number - 1].hp != 0) {
		printAll_Champ_R(arr, number - 1);
		cout << "name : " << arr[number - 1].name << endl;
		cout << "hp : " << arr[number - 1].hp << endl;
		cout << "mp : " << arr[number - 1].mp << endl;
		cout << "speed : " << arr[number - 1].speed << endl;
		cout << "range : " << arr[number - 1].range << endl;
		cout << "position : " << arr[number - 1].position << endl;
	}
	else
		printAll_Champ_R(arr, number - 1);
}

void find_MaxHp(Champ* arr, int number)
{
	system("cls");
	find_MaxHp_R(arr, number, 0, false);
	system("pause");
}

void find_MaxHp_R(Champ* arr, int number, int maxHp, bool isFind)
{
	if (number == -1 && !isFind) {
		isFind = true;
		number = 20;
		find_MaxHp_R(arr, number, maxHp, isFind);
	}
	else if (number == -1 && isFind == true)
		return;
	else if (maxHp == arr[number - 1].hp && isFind == true) {
		find_MaxHp_R(arr, number - 1, maxHp, isFind);
		cout << "name : " << arr[number - 1].name << endl;
		cout << "hp : " << arr[number - 1].hp << endl;
		cout << "mp : " << arr[number - 1].mp << endl;
		cout << "speed : " << arr[number - 1].speed << endl;
		cout << "range : " << arr[number - 1].range << endl;
		cout << "position : " << arr[number - 1].position << endl;
	}
	else if (maxHp < arr[number - 1].hp) {
		maxHp = arr[number - 1].hp;
		find_MaxHp_R(arr, number - 1, maxHp, isFind);
	}
	else
		find_MaxHp_R(arr, number - 1, maxHp, isFind);
}

void sort_ByHp(Champ* arr, int number)
{
	system("cls");
	sort_ByHp_R(arr, number, number - 1);
	cout << "���� �Ϸ�" << endl;
	system("pause");
}

void sort_ByHp_R(Champ* arr, int number, int sort_Number)
{
	if (sort_Number == -1)
		sort_ByHp_R(arr, number - 1, number - 2);
	else if (number == -1)
		return;
	else if (arr[sort_Number].hp < arr[number].hp) {
		Sort(&arr[sort_Number], &arr[number]);
		sort_ByHp_R(arr, number, sort_Number - 1);
	}
	else 
		sort_ByHp_R(arr, number, sort_Number - 1);
}

void Sort(Champ* x, Champ* y)
{
	Champ temp = *x;
	*x = *y;
	*y = temp;
}

