#include "includes.h"
#include "global.h"
#include "functions.h"

using namespace std;

struct dataStud {		//Структура данных работы
	string variety;
	int volume;
	double rate;
	double price;
	int count;
} arrData[70];			//Массив данных работы


struct dataAu {		//Структура данных пользователя
	string log;
	string par;
	bool role;
} arrUser[70];		//Массив данных пользователя


void main () {    
	//Русская раскладка
	SetConsoleCP(1251);
    SetConsoleOutputCP(1251); 

	cout << "\n Курсовой проект Довлета: программа учёта автомобилей!\n\n";

	start_menu();		//Запуск работы


	cout << "Программа завершила свою работу!\n";
	system("pause");
}

void readAutos() {
	ifstream miFile ("auto.txt");		//Открытие файла
	string temp1;
	int i, temp2, temp5;
	double temp3, temp4;

	for (i = 0; !miFile.eof(); i++) {
		miFile >> temp1 >> temp2 >> temp3 >> temp4  >> temp5;	//Чтение из файла
		arrData[i].variety = temp1;
		arrData[i].volume = temp2;
		arrData[i].rate = temp3;
		arrData[i].price = temp4;
		arrData[i].count = temp5;

	}
	size_struct_avto = i;		//Размер таблицы
	cout << "Из файла считано " << size_struct_avto << " строк\n";
	miFile.close();		//Закрытие файла
}
void writeAutos() {
	ofstream miFile ("auto.txt");		//Открытие файла для записи
	string temp1;
	int i, temp2, temp5;
	double temp3, temp4;

	for (i = 0; i < size_struct_avto; i++) {
		temp1 = arrData[i].variety;
		temp2 = arrData[i].volume;
		temp3 = arrData[i].rate;
		temp4 = arrData[i].price;
		temp5 = arrData[i].count;

		miFile << temp1 << " " << temp2 << " " << temp3 << " " << temp4 << " " << temp5;		//Запись в файл
		if (size_struct_avto - i != 1) miFile  << "\n";
	}
	miFile.close();		//Закрытие файла
}

//Следующие 2 функции аналогичны прошлым двум
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
	cout << " В файл сохранены обнавлённые данные\n ";
	miFile.close();
}
void authorization() {
	string log, pas;	
	int id = 0;
	while (id != 1) {
		cout << "Ваш логин: ";			cin >> log;
		cout << "Ваш пароль: ";			cin >> pas;

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
		if (id == 0) cerr << "Пользователь не существует. Попробуйте сново!\n\n";
		if (id == -1) cerr << "Неверный пароль. Попробуйте сново!\n\n";
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
		cout << "\nАДМИНИСТРАТОР!\n";
		cout << "\n 1. Просмотр\n 2. Добавление\n 3. Удаление\n 4. Редактирование"
			 << "\n 5. Задание\n 6. Поиск\n 7. Сортировка"
			 << "\n 8. Просмотр\n 9. Добавление\n 10. Удаление\n 11. Редактирование\n\n 0 - ВЫХОД!\n";
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
			default: cerr << "Введён несуществующий пункт меню!\n";
		}	
	}	
}
void menu_user() {
	while (1) {
		int answer;
		cout << "\n Пользователь!\n";
		cout << "\n 1. Просмотр\n 2. Задание\n 3. Поиск\n 4. Сортировка\nКлавиша 0 - ВЫХОД!\n";

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
			default: cerr << "Введён несуществующий пункт меню!\n";
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
	cout << endl << left << setw (4) << "№"; 
	cout << " = " << setw (20) << "Вид авто";	
	cout << " = " << setw (10) << "Вместит.";	
	cout << " = " << setw (10) << "Расход";	
	cout << " = " << setw (10) << "Цена";	
	cout << " = " << setw (10) << "Кл-во" << "=\n";
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
	cout << " = " << setw (20) << "Логин";	
	cout << " = " << setw (20) << "Пароль";	
	cout << " = " <<  boolalpha << setw (6) << "Роль" << "=\n";
	for (int i = 0; i < size_struct_user; i++) { 
		cout << endl << left << setw (3) << i; 
		cout << " = " << setw (20) << arrUser[i].log;	
		cout << " = " << setw (20) << arrUser[i].par;	
		cout << " = " << setw (6) << arrUser[i].role << "=\n";
	}
}

void add() {
	cout << "Вид авто: ";			cin >> arrData[size_struct_avto].variety;	
	cout << "Вместит.: ";			cin >> arrData[size_struct_avto].volume;	
	cout << "Расход: ";				cin >> arrData[size_struct_avto].rate;	
	cout << "Цена: ";				cin >> arrData[size_struct_avto].price;	
	cout << "Кл-во: ";				cin >> arrData[size_struct_avto].count;

	size_struct_avto++;
}
void add_users() {
	cout << "Логин: ";			cin >> arrUser[size_struct_user].log;
	cout << "Пароль: ";			cin >> arrUser[size_struct_user].par;	
	cout << "Роль: ";			cin >> arrUser[size_struct_user].role;
	
	size_struct_user++;
}

void deleting(){
	view();
	int answer;
	cout << "\nКакую удалить: от 0 до " << size_struct_avto-1 << ": ";		cin >> answer;
	if (answer >= size_struct_avto) {
		cout << "Неверные данные!\n";
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
	cout << "Запись успешно удалена!\n";
}
void deleting_users(){
	view_users();
	int answer;
	cout << "\nВведите номер для удалени от 0 до " << size_struct_user-1 << ": ";		cin >> answer;
	if (answer >= size_struct_user) {
		cout << "Неверные данные!\n";
		return;
	}
         
	for (int i = answer; i < size_struct_user-1; i++) {
		arrUser[i].log = arrUser[i+1].log;
		arrUser[i].par = arrUser[i+1].par;
		arrUser[i].role = arrUser[i+1].role;

	}
	size_struct_user--;
	cout << "Удалено!\n";
}

void edit() {
	view();
	int numb, point;
	cout << "\nВведите номер записи: от 0 до " << size_struct_avto-1 << ": ";		cin >> numb;
	if (numb >= size_struct_avto) {
		cout << "Неверные данные!\n";
		return;
	}
	cout << "Введите номер поля для редактирования от 1 до 5: ";		cin >> point;	
	switch (point) {
		case 1: cout << "Вид авто: ";	cin >> arrData[numb].variety;	
				break;
		case 2: cout << "Вместит.: ";	cin >> arrData[numb].volume;	
				break;
		case 3: cout << "Расход: ";		cin >> arrData[numb].rate;	
				break;
		case 4: cout << "Цена: ";		cin >> arrData[numb].price;	
				break;
		case 5: cout << "Кл-во: ";		cin >> arrData[numb].count; 
				break;
		default: cout << "Неверные данные!\n";
	}
	
}
void edit_users() {

	view_users();
	int numb, point;
	cout << "\nВведите номер записи: от 0 до " << size_struct_user-1 << ": ";		cin >> numb;
	if (numb >= size_struct_user) {
		cout << "Неверные данные!\n";
		return;
	}
	cout << "Введите номер поля: от 1 до 3: ";		cin >> point;	
	switch (point) {
		case 1: cout << "Логин: ";					
				cin >> arrUser[numb].log;
				break;
		case 2: cout << "Пароль: ";
				cin >> arrUser[numb].par;	
				break;
		case 3: cout << "Роль: ";
				cin >> arrUser[numb].role;
				break;
		default: cout << "Неверные данные!\n";
	}
}

void assignment() {
	cout << "\n\tИДЗ\n";
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
			cout << "Стоимость всех авто вида " << arrData[i-1].variety << " - " << iPrice << endl;
			tempVar = arrData[i].variety;
			iPrice =  arrData[i].price;
		}
	}
	cout << "Стоимость всех авто вида " << arrData[size_struct_avto-1].variety << " - " << iPrice << endl;
	cout << "\nОбщая стоимость таксопарка: " << priceAll << endl;
	assignment2();
}
void assignment2() {
	int begin, end, index = 0;
	cout << "Введите начало диапазона вместительности: ";	cin >> begin;
	cout << "Введите начало диапазона вместительности: ";	cin >> end;
	cout << "Подходящие авто: \n"; 
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
	cout << "\tПо какому полю поиск:\n 1. Вид\n 2. Вместит.\n 3. Расход\n 4. Цена \n 5. Кл-во\n";
	cin  >> point; 

	switch (point) {		//Выбор поля поиска
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
		default: cout << "Неверные данные!\n";
	}
	cout << endl;
}
void searchInteger (int number) {
	int index = 0, request;
	cout << "Запрос для поиска: ";
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
	cout << "Запрос для поиска: ";
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
	cout << "Запрос для поиска: ";
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
	cout << "\tПо какому полю сортировка:\n 1. Вид\n 2. Вместит.\n 3. Расход\n 4. Цена \n 5. Кл-во\n";
	cin  >> point; 

	switch (point) {		//Выбор поля сортировки
		case 1: sorting(1);	break;
		case 2:	sorting(2);	break;
		case 3: sorting(3);	break;
		case 4: sorting(4);	break;
		case 5: sorting(5);	break;
		default: cout << "Неверные данные!\n";
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