void readUsers();			//Чтение таблицы пользователей
void writeUsers();			//Запись в файл таблицы пользователей

void readAutos();			//Чтение таблицы автомобилей
void writeAutos();			///Запись в файл таблицы автомобилей

void authorization();		//Прохождение авторизации

void start_menu();			//Запуск меню
void menu_admin();			//Меню администратора
void menu_user();			//Меню пользователя
			
void view();							//Просмотр данных авто
void viewHeader();						//Просмотр шапки таблицы
void viewI (struct dataStud, int);		//Просмотр одной строки таблцы

void add();								//Добавление авто
void deleting();						//Удаление авто
void edit();							//Редактирование авто

void view_users();				//Просмотр таблицы пользователей
void add_users();				//Добавление пользователя
void deleting_users();			//Удаление пользователя
void edit_users();				//Редактирование пользователя

void assignment();					//Функция ИДЗ номер 1
void assignment2();					//Функция ИДЗ номер 2

void search();					//Функция поиска авто
void searchInteger(int);		//Поиск для целочисленных полей
void searchFloat(int);			//Поиск для вещественных полей
void searchString(int);			//Поиск для строковых

void menu_sorting();			//Меню выбора сортировки
void sorting (int);				//Пузырьковая сортировка
bool comparison (int , int);	//Сравниние j -того и j-1 -го элементов