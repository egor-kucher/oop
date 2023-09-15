#include "header.h"


int main(){
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	Button but[3];
	for (int i = 0; i < 3; i++) {
		if (i % 3 == 0) {
			but[i].Push();
		}
		but[i].ShowElementInfo();
	}
	TextBox textb[5];
	for (int i = 0; i < 5; i++) {
		if (i % 4 == 0) {
			textb[i].ChangeTextBox("Cool info");
		}
		textb[i].ShowElementInfo();
	}
	CheckBox checkb[3];
	for (int i = 0; i < 3; i++) {
		
		if (i % 2 == 0) {
			checkb[i].Push();
		}
		checkb[i].ShowElementInfo();
	}
	int choice = 0;
	UIelement* ptr = nullptr;
	while (1) {
		cout << "Выберите, характеристики какого элемента вы хотите изменить" << endl;
		cout << "1. Кнопки" << endl;
		cout << "2. Текстбокса" << endl;
		cout << "3. Чекбокса" << endl;
		cout << "4. Выйти из программы" << endl;
		choice = check(choice);
		switch (choice) {
		case 1:;
			break;
		case 2:break; 
		case 3:break;
		case 4:return 0;
			break;
		default:cout << "Неверный ввод, попробуйте снова" << endl;
			break;
		}
	}
	return 0;
}