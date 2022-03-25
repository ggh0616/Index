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
	{"가렌", 620, 0, 340, 175, "top"},
	{"갈리오", 562, 500, 335, 125, "mid"},
	{"베인", 515, 231, 330, 550, "bot"},
	{"티모", 528, 267, 330, 500, "top"},
	{"소라카", 535, 425, 325, 550, "support"},
	{"녹턴", 585, 275, 345, 125, "jungle"},
	{"블리츠크랭크", 582, 267, 325, 125, "support"},
	{"퀸", 532, 268, 335, 525, "top"},
	{"장지웅", 620, 0, 350, 500, "bot"},
	{"시비르", 530, 300, 325, 350, "bot"},
	{"모르가나", 500, 350, 320, 550, "support"},
	{"코르키", 550, 450, 125, 330, "mid"},
	{"리신", 619, 0, 350, 250, "jungle"},
	{"레나타 글라스크", 500, 235, 330, 125, "support"},
	{"코르키", 500, 340, 330, 500, "mid"},
	{"바드", 490, 300, 330, 300, "support"},
	{"바루스", 510, 250, 345, 570, "bot"},
	{"쉔", 620, 0, 330, 200, "top"},
	{"애쉬", 500, 350, 330, 500, "bot"},
	{"라이즈", 550, 400, 325, 400, "mid"}
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
		cout << "0 : 종료" << endl;
		cout << "1 : 챔피언 검색" << endl;
		cout << "2 : 챔피언 추가" << endl;
		cout << "3 : 챔피언 삭제" << endl;
		cout << "4 : 포지션 삭제" << endl;
		cout << "5 : 챔피언 출력" << endl;
		cout << "6 : 최대 체력 출력" << endl;
		cout << "7 : 체력 순으로 정렬" << endl;
		int insert_Number;
		cout << "입력 : ";
		rewind(stdin);
		cin >> insert_Number;
		if (cin.fail()) {
			cout << "잘못된 문자가 입력되었습니다. 다시 입력해주세요" << endl;
			system("pause");
			cin.clear();
			rewind(stdin);
			continue;
		}
		switch (insert_Number)
		{
		case 0:
			end = false;
			cout << "프로그램을 종료합니다." << endl;
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
			cout << "잘못된 숫자가 입력되었습니다." << endl;
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
		cout << "검색할 챔피언의 이름을 입력하시오 : ";
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
				cout << "없는 챔피언 입니다." << endl;
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
		cout << "추가할 챔피언의 정보를 입력하시오" << endl;
		cout << "name : ";
		cin >> arr[*number].name;
		cout << "hp : ";
		cin >> arr[*number].hp;
		if (cin.fail()) {
			cout << "숫자가 아닌 문자가 입력되었습니다. 다시 입력해주세요" << endl;
			system("pause");
			cin.clear();
			rewind(stdin);
			continue;
		}
		cout << "mp : ";
		cin >> arr[*number].mp;
		if (cin.fail()) {
			cout << "숫자가 아닌 문자가 입력되었습니다. 다시 입력해주세요" << endl;
			system("pause");
			cin.clear();
			rewind(stdin);
			continue;
		}
		cout << "speed : ";
		cin >> arr[*number].speed;
		if (cin.fail()) {
			cout << "숫자가 아닌 문자가 입력되었습니다. 다시 입력해주세요" << endl;
			system("pause");
			cin.clear();
			rewind(stdin);
			continue;
		}
		cout << "range : ";
		cin >> arr[*number].range;
		if (cin.fail()) {
			cout << "숫자가 아닌 문자가 입력되었습니다. 다시 입력해주세요" << endl;
			system("pause");
			cin.clear();
			rewind(stdin);
			continue;
		}
		cout << "position : ";
		cin >> arr[*number].position;
		cout << arr[*number].name << " 추가 완료" << endl;
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
		cout << "삭제할 챔피언의 이름을 입력하시오 : ";
		rewind(stdin);
		cin >> delete_Name;
		for (int i = 0; i < *number; ++i)
		{
			if (!strcmp(delete_Name, arr[i].name)) {
				end = false;
				isFind = true;
				cout << arr[i].name << " 삭제 완료" << endl;
				ZeroMemory(&arr[i], sizeof(arr[i]));
				*number = *number - 1;
			}
			else if (i == *number - 1 && !isFind) {
				cout << "존재하지 않는 챔피언입니다." << endl;
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
		cout << "삭제할 포지션의 이름을 입력하시오 : ";
		rewind(stdin);
		cin >> delete_PositionName;
		for (int i = 0; i < *number; ++i)
		{
			if (!strcmp(delete_PositionName, arr[i].position)) {
				end = false;
				isFind = true;
				cout << arr[i].position << " 삭제 완료" << endl;
				ZeroMemory(&arr[i], sizeof(arr[i]));
			}
			else if (i == *number - 1 && !isFind) {
				cout << "존재하지 않는 포지션 입니다. 다시 입력해주세요" << endl;
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
	cout << "정렬 완료" << endl;
	system("pause");
}
