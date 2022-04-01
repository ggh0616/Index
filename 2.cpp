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
	{"가렌", 620, 0, 340, 175, "top"},
	{"갈리오", 562, 500, 335, 125, "mid"},
	{"베인", 515, 231, 330, 550, "bot"},
	{"티모", 528, 267, 330, 500, "top"},
	{"소라카", 535, 425, 325, 550, "support"},
	{"녹턴", 585, 275, 345, 125, "jungle"},
	{"블리츠크랭크", 582, 267, 325, 125, "support"},
	{"퀸", 532, 268, 335, 525, "top"},
	{"아펠리오스", 620, 0, 350, 500, "bot"},
	{"시비르", 530, 300, 325, 350, "bot"},
	{"모르가나", 500, 350, 320, 550,  "support"},
	{"코르키", 550, 450, 125, 330, "mid"},
	{"리신", 619, 0, 350, 250, "jungle"},
	{"레나타 글라스크", 500, 235, 330, 125, "support"},
	{"르블랑", 500, 340, 330, 500, "mid"},
	{"바드", 490, 300, 330, 300, "support"},
	{"바루스", 510, 250, 345, 570, "bot"},
	{"쉔", 620, 0, 330, 200, "top"},
	{"애쉬", 500, 350, 330, 500, "bot"},
	{"라이즈", 550, 400, 325, 400, "mid"}
};

void Menu();
void search_Champ(Champ* arr, int number);
void search_Champ_R(Champ* arr, int number, char *search_Name, bool isFind);
void insert_Champ(Champ* arr, int* number);
void delete_Champ(Champ* arr, int number);
void delete_Champ_R(Champ* arr, int number, char* delete_Name, bool isFind);
void delete_Position(Champ* arr, int number);
void delete_Position_R(Champ* arr, int number, char* delete_PositionName, bool isFind);
void printAll_Champ(Champ* arr, int number);
void printAll_Champ_R(Champ* arr, int number);
void find_MaxHp(Champ* arr, int number);
void find_MaxHp_R(Champ* arr, int number, int maxHp, bool isFind);
void sortByHp(Champ* arr, int number);
void sortByHp_R(Champ* arr, int number, int sort_Num);
void Swap(Champ* x, Champ* y);

int main()
{
	Menu();
}

void Menu()
{
	system("cls");
	cout << "0 : 시스템 종료" << endl;
	cout << "1 : 챔피언 검색" << endl;
	cout << "2 : 챔피언 추가" << endl;
	cout << "3 : 챔피언 삭제" << endl;
	cout << "4 : 포지션 삭제" << endl;
	cout << "5 : 챔피언 출력" << endl;
	cout << "6 : 최대 체력인 챔피언 출력" << endl;
	cout << "7 : 체력순으로 정렬" << endl;
	int switch_Number;
	cout << "검색 : ";
	rewind(stdin);
	cin >> switch_Number;
	if (cin.fail()) {
		cout << "숫자가 아닌 문자가 입력되었습니다." << endl;
		system("pause");
		cin.clear();
		rewind(stdin);		
		Menu();
	}
	switch (switch_Number)
	{
	case 0:
		cout << "프로그램을 종료합니다." << endl;
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
		sortByHp(arr, number);
		Menu();
		break;
	default:
		cout << "잘못된 범위의 숫자가 입력되었습니다. 다시 입력해주세요" << endl;
		Menu();
		break;
	}
}

void search_Champ(Champ* arr, int number)
{
	system("cls");
	char search_Name[20];
	cout << "검색할 챔피언의 이름을 입력하시오 : ";
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
		cout << "name : " << arr[number-1].name << endl;
		cout << "hp : " << arr[number - 1].hp << endl;
		cout << "mp : " << arr[number - 1].mp << endl;
		cout << "speed : " << arr[number - 1].speed << endl;
		cout << "range : " << arr[number - 1].range << endl;
		cout << "position : " << arr[number - 1].position << endl;
	}
	else if (number == 0 && !isFind)
		cout << "없는 챔피언입니다. 다시 입력해주세요" << endl;
	else
		search_Champ_R(arr, number - 1, search_Name, isFind);
}

void insert_Champ(Champ* arr, int* number)
{
	system("cls");
	cout << "추가할 챔피언의 정보를 입력하시오" << endl;
	cout << "name : ";
	rewind(stdin);
	cin >> arr[*number].name;
	cout << "hp : ";
	rewind(stdin);
	cin >> arr[*number].hp;
	if (cin.fail()) {
		cout << "숫자가 아닌 문자가 입력되었습니다." << endl;
		system("pause");
		cin.clear();
		rewind(stdin);
		return;
	}
	cout << "mp : ";
	rewind(stdin);
	cin >> arr[*number].mp;
	if (cin.fail()) {
		cout << "숫자가 아닌 문자가 입력되었습니다." << endl;
		system("pause");
		cin.clear();
		rewind(stdin);
		return;
	}
	cout << "speed : ";
	rewind(stdin);
	cin >> arr[*number].speed;
	if (cin.fail()) {
		cout << "숫자가 아닌 문자가 입력되었습니다." << endl;
		system("pause");
		cin.clear();
		rewind(stdin);
		return;
	}
	cout << "range : ";
	rewind(stdin);
	cin >> arr[*number].range;
	if (cin.fail()) {
		cout << "숫자가 아닌 문자가 입력되었습니다." << endl;
		system("pause");
		cin.clear();
		rewind(stdin);
		return;
	}
	cout << "position : ";
	rewind(stdin);
	cin >> arr[*number].position;
	cout << *number << " 입력 완료" << endl;
	system("pause");
	*number = *number - 1;
}

void delete_Champ(Champ* arr, int number)
{
	system("cls");
	char delete_Name[20];
	cout << "삭제할 챔피언의 이름을 입력하시오 : ";
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
		cout << arr[number - 1].name << " 삭제 완료" << endl;
		ZeroMemory(&arr[number - 1], sizeof(arr[number - 1]));		
	}
	else if (number == 0 && !isFind)
		cout << "없는 챔피언입니다. 다시 입력해주세요" << endl;
	else
		delete_Champ_R(arr, number - 1, delete_Name, isFind);
}

void delete_Position(Champ* arr, int number)
{
	system("cls");
	char delete_PositionName[20];
	cout << "삭제할 포지션의 이름을 입력하시오 : ";
	rewind(stdin);
	cin >> delete_PositionName;
	delete_Position_R(arr, number, delete_PositionName, false);
	system("pause");
}

void delete_Position_R(Champ* arr, int number, char* delete_PositionName, bool isFind)
{
	if (number == -1)
		return;
	else if (!strcmp(delete_PositionName, arr[number - 1].position)) {
		isFind = true;
		delete_Position_R(arr, number - 1, delete_PositionName, isFind);		
		cout << arr[number - 1].name << " 삭제 완료" << endl;
		ZeroMemory(&arr[number-1], sizeof(arr[number-1]));				
	}
	else if (number == 0 && !isFind)
		cout << "없는 포지션입니다. 다시 입력해주세요" << endl;
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
	if (number == -1) {
		return;
	}
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
		number = 20;
		isFind = true;		
		find_MaxHp_R(arr, number, maxHp, isFind);
	}
	else if (number == -1 && isFind == true)
		return;
	else if (maxHp < arr[number - 1].hp) {
		maxHp = arr[number - 1].hp;
		find_MaxHp_R(arr, number - 1, maxHp, isFind);
	}
	else if (maxHp == arr[number - 1].hp && isFind == true) {
		find_MaxHp_R(arr, number - 1, maxHp, isFind);
		cout << "name : " << arr[number - 1].name << endl;
		cout << "hp : " << arr[number - 1].hp << endl;
		cout << "mp : " << arr[number - 1].mp << endl;
		cout << "speed : " << arr[number - 1].speed << endl;
		cout << "range : " << arr[number - 1].range << endl;
		cout << "position : " << arr[number - 1].position << endl;
	}
	else
		find_MaxHp_R(arr, number - 1, maxHp, isFind);
}

void sortByHp(Champ* arr, int number)
{
	system("cls");
	sortByHp_R(arr, number - 1, number - 2);
	cout << "정렬완료" << endl;
	system("pause");
}


void sortByHp_R(Champ* arr, int number, int sort_Num)
{	
	if (number == -1)
		return;
	else if (sort_Num == -1) 
		sortByHp_R(arr, number - 1, number - 2);
	else if (arr[sort_Num].hp < arr[number].hp) {
		Swap(&arr[sort_Num], &arr[number]);
		sortByHp_R(arr, number, sort_Num - 1);
	}
	else
		sortByHp_R(arr, number, sort_Num - 1);
}

void Swap(Champ* x, Champ* y)
{
	Champ temp = *x;
	*x = *y;
	*y = temp;
}
