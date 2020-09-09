#include "includes.h"
#include "global.h"
#include "functions.h"

using namespace std;

struct dataStud {		//��������� ������ ������
	string variety;
	int volume;
	double rate;
	double price;
	int count;
} arrData[70];			//������ ������ ������


struct dataAu {		//��������� ������ ������������
	string log;
	string par;
	bool role;
} arrUser[70];		//������ ������ ������������


void main () {    
	//������� ���������
	SetConsoleCP(1251);
    SetConsoleOutputCP(1251); 

	cout << "\n �������� ������ �������: ��������� ����� �����������!\n\n";

	start_menu();		//������ ������


	cout << "��������� ��������� ���� ������!\n";
	system("pause");
}

void readAutos() {
	ifstream miFile ("auto.txt");		//�������� �����
	string temp1;
	int i, temp2, temp5;
	double temp3, temp4;

	for (i = 0; !miFile.eof(); i++) {
		miFile >> temp1 >> temp2 >> temp3 >> temp4  >> temp5;	//������ �� �����
		arrData[i].variety = temp1;
		arrData[i].volume = temp2;
		arrData[i].rate = temp3;
		arrData[i].price = temp4;
		arrData[i].count = temp5;

	}
	size_struct_avto = i;		//������ �������
	cout << "�� ����� ������� " << size_struct_avto << " �����\n";
	miFile.close();		//�������� �����
}
void writeAutos() {
	ofstream miFile ("auto.txt");		//�������� ����� ��� ������
	string temp1;
	int i, temp2, temp5;
	double temp3, temp4;

	for (i = 0; i < size_struct_avto; i++) {
		temp1 = arrData[i].variety;
		temp2 = arrData[i].volume;
		temp3 = arrData[i].rate;
		temp4 = arrData[i].price;
		temp5 = arrData[i].count;

		miFile << temp1 << " " << temp2 << " " << temp3 << " " << temp4 << " " << temp5;		//������ � ����
		if (size_struct_avto - i != 1) miFile  << "\n";
	}
	miFile.close();		//�������� �����
}

//��������� 2 ������� ���������� ������� ����
void readUsers() {
	ifstream miFile ("users.txt");
	int i;
	string temp1, temp2;
	bool temp3;

	for (i = 0; !miFile.eof(); i++) {
		miFile >> temp1 >> temp2 >> temp3;
		arrUser[i].log = temp1;
		arrUser[i].par = temp2;
		arrUser[i].role = temp3;
	}
	size_struct_user = i; 
	miFile.close();
}
void writeUsers() {

	ofstream miFile ("users.txt");
	int i;
	string temp1, temp2;
	bool temp3;

	for (i = 0; i < size_struct_user; i++) {
		temp1 = arrUser[i].log;
		temp2 = arrUser[i].par;
		temp3 = arrUser[i].role;

		miFile << temp1 << " " << temp2 << " " << temp3;
		if (size_struct_user - i != 1)	miFile  << "\n";

	}
	cout << " � ���� ��������� ���������� ������\n ";
	miFile.close();
}
void authorization() {
	string log, pas;	
	int id = 0;
	while (id != 1) {
		cout << "��� �����: ";			cin >> log;
		cout << "��� ������: ";			cin >> pas;

		for (int i = 0; i < size_struct_user; i++) {

			if(arrUser[i].log == log) {
				id = -1;
				if(arrUser[i].par == pas) {
					id = 1;
					status = arrUser[i].role;
					break;
				}
			}

		}
		if (id == 0) cerr << "������������ �� ����������. ���������� �����!\n\n";
		if (id == -1) cerr << "�������� ������. ���������� �����!\n\n";
	} 
}

void start_menu() {

	readAutos();
	readUsers();
	authorization();

	if (status == 1) {
		menu_admin();
	}
	else {
		menu_user();
	}

	writeAutos();
	writeUsers();
}
void menu_admin() {
	while (true) {
		int answer;
		cout << "\n�������������!\n";
		cout << "\n 1. ��������\n 2. ����������\n 3. ��������\n 4. ��������������"
			 << "\n 5. �������\n 6. �����\n 7. ����������"
			 << "\n 8. ��������\n 9. ����������\n 10. ��������\n 11. ��������������\n\n 0 - �����!\n";
		cin >> answer;
		switch(answer) {
			case 1: 
				view();   break;
			case 2: 
				add();    break;
			case 3:
				deleting();    break;
			case 4: 
				edit(); break;
			case 5:
				assignment();    break;
			case 6: 
				search(); break;
			case 7: 
				menu_sorting();   break;
			case 8: 
				view_users(); break;
			case 9: 
				add_users();  break;
			case 10:
				deleting_users();  break;
			case 11:
				edit_users();  break;
			case 0: return;
			default: cerr << "����� �������������� ����� ����!\n";
		}	
	}	
}
void menu_user() {
	while (1) {
		int answer;
		cout << "\n ������������!\n";
		cout << "\n 1. ��������\n 2. �������\n 3. �����\n 4. ����������\n������� 0 - �����!\n";

		cin >> answer;
		switch(answer) {
			case 1: 
				view();   break;
			case 2: 
				assignment();    break;
			case 3:
				search(); break;
			case 4: 
				menu_sorting();  view(); break;
			case 0: return;
			default: cerr << "����� �������������� ����� ����!\n";
		}
		 
	}	
}

void view() {
	viewHeader();
	for (int i = 0; i < size_struct_avto; i++) {
		viewI (arrData[i], i);
	}
}
void viewHeader () {
	cout << endl << left << setw (4) << "�"; 
	cout << " = " << setw (20) << "��� ����";	
	cout << " = " << setw (10) << "�������.";	
	cout << " = " << setw (10) << "������";	
	cout << " = " << setw (10) << "����";	
	cout << " = " << setw (10) << "��-��" << "=\n";
}
void viewI (struct dataStud tempStud, int i) {
	cout << endl << left << setw (4) << i; 
	cout << " = " << setw (20) << tempStud.variety;	
	cout << " = " << setw (10) << tempStud.volume;	
	cout << " = " << setw (10) << tempStud.rate;	
	cout << " = " << setw (10) << tempStud.price;	
	cout << " = " << setw (10) << tempStud.count << "=\n";
}
void view_users() {
	cout << endl << left << setw (3) << "id:"; 
	cout << " = " << setw (20) << "�����";	
	cout << " = " << setw (20) << "������";	
	cout << " = " <<  boolalpha << setw (6) << "����" << "=\n";
	for (int i = 0; i < size_struct_user; i++) { 
		cout << endl << left << setw (3) << i; 
		cout << " = " << setw (20) << arrUser[i].log;	
		cout << " = " << setw (20) << arrUser[i].par;	
		cout << " = " << setw (6) << arrUser[i].role << "=\n";
	}
}

void add() {
	cout << "��� ����: ";			cin >> arrData[size_struct_avto].variety;	
	cout << "�������.: ";			cin >> arrData[size_struct_avto].volume;	
	cout << "������: ";				cin >> arrData[size_struct_avto].rate;	
	cout << "����: ";				cin >> arrData[size_struct_avto].price;	
	cout << "��-��: ";				cin >> arrData[size_struct_avto].count;

	size_struct_avto++;
}
void add_users() {
	cout << "�����: ";			cin >> arrUser[size_struct_user].log;
	cout << "������: ";			cin >> arrUser[size_struct_user].par;	
	cout << "����: ";			cin >> arrUser[size_struct_user].role;
	
	size_struct_user++;
}

void deleting(){
	view();
	int answer;
	cout << "\n����� �������: �� 0 �� " << size_struct_avto-1 << ": ";		cin >> answer;
	if (answer >= size_struct_avto) {
		cout << "�������� ������!\n";
		return;
	}

	for (int i = answer; i < size_struct_avto-1; i++) {
		arrData[i].volume = arrData[i+1].volume;
		arrData[i].variety = arrData[i+1].variety;
		arrData[i].rate= arrData[i+1].rate;
		arrData[i].price = arrData[i+1].price;	
		arrData[i].count = arrData[i+1].count;
	}
	size_struct_avto--;
	cout << "������ ������� �������!\n";
}
void deleting_users(){
	view_users();
	int answer;
	cout << "\n������� ����� ��� ������� �� 0 �� " << size_struct_user-1 << ": ";		cin >> answer;
	if (answer >= size_struct_user) {
		cout << "�������� ������!\n";
		return;
	}
         
	for (int i = answer; i < size_struct_user-1; i++) {
		arrUser[i].log = arrUser[i+1].log;
		arrUser[i].par = arrUser[i+1].par;
		arrUser[i].role = arrUser[i+1].role;

	}
	size_struct_user--;
	cout << "�������!\n";
}

void edit() {
	view();
	int numb, point;
	cout << "\n������� ����� ������: �� 0 �� " << size_struct_avto-1 << ": ";		cin >> numb;
	if (numb >= size_struct_avto) {
		cout << "�������� ������!\n";
		return;
	}
	cout << "������� ����� ���� ��� �������������� �� 1 �� 5: ";		cin >> point;	
	switch (point) {
		case 1: cout << "��� ����: ";	cin >> arrData[numb].variety;	
				break;
		case 2: cout << "�������.: ";	cin >> arrData[numb].volume;	
				break;
		case 3: cout << "������: ";		cin >> arrData[numb].rate;	
				break;
		case 4: cout << "����: ";		cin >> arrData[numb].price;	
				break;
		case 5: cout << "��-��: ";		cin >> arrData[numb].count; 
				break;
		default: cout << "�������� ������!\n";
	}
	
}
void edit_users() {

	view_users();
	int numb, point;
	cout << "\n������� ����� ������: �� 0 �� " << size_struct_user-1 << ": ";		cin >> numb;
	if (numb >= size_struct_user) {
		cout << "�������� ������!\n";
		return;
	}
	cout << "������� ����� ����: �� 1 �� 3: ";		cin >> point;	
	switch (point) {
		case 1: cout << "�����: ";					
				cin >> arrUser[numb].log;
				break;
		case 2: cout << "������: ";
				cin >> arrUser[numb].par;	
				break;
		case 3: cout << "����: ";
				cin >> arrUser[numb].role;
				break;
		default: cout << "�������� ������!\n";
	}
}

void assignment() {
	cout << "\n\t���\n";
	string tempVar;
	double priceAll = 0, iPrice = 0;

	sorting (1);
	tempVar = arrData[0].variety; 
	for (int i = 0; i < size_struct_avto; i++) {
		priceAll += arrData[i].price;
		if (tempVar == arrData[i].variety) {
			iPrice += arrData[i].price;
		}
		else if (tempVar != arrData[i].variety) {
			cout << "��������� ���� ���� ���� " << arrData[i-1].variety << " - " << iPrice << endl;
			tempVar = arrData[i].variety;
			iPrice =  arrData[i].price;
		}
	}
	cout << "��������� ���� ���� ���� " << arrData[size_struct_avto-1].variety << " - " << iPrice << endl;
	cout << "\n����� ��������� ����������: " << priceAll << endl;
	assignment2();
}
void assignment2() {
	int begin, end, index = 0;
	cout << "������� ������ ��������� ���������������: ";	cin >> begin;
	cout << "������� ������ ��������� ���������������: ";	cin >> end;
	cout << "���������� ����: \n"; 
	viewHeader();
	for (int i = 0; i < size_struct_avto; i++) {
		if (arrData[i].volume >= begin && arrData[i].volume <= end) {
			viewI(arrData[i], index);
			index++;
		}

	}

}

void search() {

	int point;
	cout << "\t�� ������ ���� �����:\n 1. ���\n 2. �������.\n 3. ������\n 4. ���� \n 5. ��-��\n";
	cin  >> point; 

	switch (point) {		//����� ���� ������
		case 1: 
			searchString(1);	break;
		case 2:	
			searchInteger(1);		break;
		case 3: 
			searchFloat(1);	break;
		case 4: 
			searchFloat(2);	break;
		case 5: 
			searchInteger(2);		break;
		default: cout << "�������� ������!\n";
	}
	cout << endl;
}
void searchInteger (int number) {
	int index = 0, request;
	cout << "������ ��� ������: ";
	cin >> request;
	viewHeader();
	for (int i = 0; i < size_struct_avto; i++) {
		switch (number) {
		case 1:
			if(arrData[i].volume == request) {
				viewI(arrData[i], index);
				index++;
			}
			break;
		case 2:
			if(arrData[i].count == request) {
				viewI(arrData[i], index);
				index++;
			}
			break;
		}
	}
}
void searchFloat(int number) {
	int index = 0;
	double request;
	cout << "������ ��� ������: ";
	cin >> request;
	viewHeader();
	for (int i = 0; i < size_struct_avto; i++) {
		switch (number) {
		case 1:
			if(arrData[i].rate == request) {
				viewI(arrData[i], index);
				index++;
			}
			break;
		case 2:
			if(arrData[i].price == request) {
				viewI(arrData[i], index);
				index++;
			}
			break;
		}
	}
}
void searchString(int number) {
	int index = 0;
	string request;
	cout << "������ ��� ������: ";
	cin >> request;
	viewHeader();
	for (int i = 0; i < size_struct_avto; i++) {
		switch (number) {
		case 1:
			if(arrData[i].variety == request) {
				viewI(arrData[i], index);
				index++;
			}
			break;
		}

	}
}

void menu_sorting() {
	int point;
	cout << "\t�� ������ ���� ����������:\n 1. ���\n 2. �������.\n 3. ������\n 4. ���� \n 5. ��-��\n";
	cin  >> point; 

	switch (point) {		//����� ���� ����������
		case 1: sorting(1);	break;
		case 2:	sorting(2);	break;
		case 3: sorting(3);	break;
		case 4: sorting(4);	break;
		case 5: sorting(5);	break;
		default: cout << "�������� ������!\n";
	}
	view();
}
void sorting (int param) {
	dataStud tmp;
	for(int i = 0; i < size_struct_avto; i++) {
		for(int j = (size_struct_avto - 1); j>=(i+1); j--) {
			if(comparison(param, j)) {
				tmp = arrData[j];
				arrData[j]=arrData[j-1];
				arrData[j-1] = tmp;
			}
		}
	}
}
bool comparison (int param, int j) {
	switch(param) {
		case 1: 
			return arrData[j].variety < arrData[j-1].variety;
			break;
		case 2: 
			return arrData[j].volume < arrData[j-1].volume;
			break;
		case 3:
			return arrData[j].rate < arrData[j-1].rate;
			break;
		case 4: 
			return arrData[j].price < arrData[j-1].price;
			break;
		case 5: 
			return arrData[j].count < arrData[j-1].count;
			break;
	}
}