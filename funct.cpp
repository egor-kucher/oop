#include "header.h"
extern int check(int a) {
	while (!(cin >> a)) {
		cin.clear();
		cin.ignore(1025, '\n');
		cout << "Вы ввели неверное значение" << endl;
	}
	return a;
}
void UIelement::ChangeCoordinates(int x, int y) {
	this->coordX = x;
	this->coordY = y;
}
void UIelement::ChangeColor(string color) {
	this->main_color = color;
}
void UIelement::ChangeShape(string shape) {
	this->shape = shape;
}
void UIelement::ShowElementInfo() {
	cout << "Координата x элемента : " << this->coordX << endl;
	cout << "Координата y элемента : " << this->coordY << endl;
	cout << "Вид элемента : " << this->shape << endl;
	cout << "Цвет элемента : " << this->main_color << endl;
	cout << endl;
}
UIelement::UIelement(int coordx, int coordy) :coordX(coordx), coordY(coordy) {};
UIelement::UIelement(int coordx, int coordy, string shape) : coordX(coordx), coordY(coordy), shape(shape) {};
int UIelement::counterX = 0;
int UIelement::counterY = 1;
UIelement::UIelement() {
	counterX++;
	if (counterX < 10) {
		coordX = counterX;
		coordY = counterY;
	}
	else {
		counterY++;
		counterX = 1;
		coordX = counterX;
		coordY = counterY;
	}
	shape = "Квадрат";
	main_color = "Белый";
}
void Button::Push() {
	this->IsPressed = true;
}
void Button::ChangeButtonText(string button_text) {
	this->button_text = button_text;
}
void Button::ShowElementInfo(){
	cout << "Координата x кнопки : " << this->coordX << endl;
	cout << "Координата y кнопки : " << this->coordY << endl;
	cout << "Вид кнопки : " << this->shape << endl;
	cout << "Цвет кнопки : " << this->main_color << endl;
	cout << "Текст на кнопке : " << this->button_text << endl;
	cout << "Состояние кнопки : ";
	this->IsPressed == true ? (cout << "Нажата" << endl) : (cout << "Не нажата" << endl);
	cout << endl;
}
Button::Button() {
	button_text = "Click!";
	IsPressed = false;
}
void TextBox:: ChangeTextBox(string text) {
	this->text = text;
}
void TextBox::ShowElementInfo() {
	cout << "Координата x текстбокса : " << this->coordX << endl;
	cout << "Координата y текстбокса : " << this->coordY << endl;
	cout << "Вид текстбокса : " << this->shape << endl;
	cout << "Цвет текстбокса : " << this->main_color << endl;
	cout << "Текст в текстбоксе: " << this->text << endl;
	cout << endl;
}
TextBox::TextBox() {
	text = "Once upon a time...";
}
void CheckBox::SetChoices(int num) {
	this->number_of_choices = num;
}
void CheckBox::ShowElementInfo() {
	cout << "Координата x чекбокса : " << this->coordX << endl;
	cout << "Координата y чекбокса : " << this->coordY << endl;
	cout << "Вид чекбокса : " << this->shape << endl;
	cout << "Цвет чекбокса : " << this->main_color << endl;
	cout << "Текст в чекбоксе: " << this->text << endl;
	cout << "Цвет кнопки : " << this->main_color << endl;
	cout << "Текст на кнопке : " << this->button_text << endl;
	cout << "Состояние кнопки : ";
	this->IsPressed == true ? (cout << "Нажата" << endl) : (cout << "Не нажата" << endl);
	cout << "Количество вариантов чекбокса: " << this->number_of_choices << endl;
	cout << endl;
}