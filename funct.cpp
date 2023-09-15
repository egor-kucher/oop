#include "header.h"
extern int check(int a) {
	while (!(cin >> a)) {
		cin.clear();
		cin.ignore(1025, '\n');
		cout << "�� ����� �������� ��������" << endl;
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
	cout << "���������� x �������� : " << this->coordX << endl;
	cout << "���������� y �������� : " << this->coordY << endl;
	cout << "��� �������� : " << this->shape << endl;
	cout << "���� �������� : " << this->main_color << endl;
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
	shape = "�������";
	main_color = "�����";
}
void Button::Push() {
	this->IsPressed = true;
}
void Button::ChangeButtonText(string button_text) {
	this->button_text = button_text;
}
void Button::ShowElementInfo(){
	cout << "���������� x ������ : " << this->coordX << endl;
	cout << "���������� y ������ : " << this->coordY << endl;
	cout << "��� ������ : " << this->shape << endl;
	cout << "���� ������ : " << this->main_color << endl;
	cout << "����� �� ������ : " << this->button_text << endl;
	cout << "��������� ������ : ";
	this->IsPressed == true ? (cout << "������" << endl) : (cout << "�� ������" << endl);
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
	cout << "���������� x ���������� : " << this->coordX << endl;
	cout << "���������� y ���������� : " << this->coordY << endl;
	cout << "��� ���������� : " << this->shape << endl;
	cout << "���� ���������� : " << this->main_color << endl;
	cout << "����� � ����������: " << this->text << endl;
	cout << endl;
}
TextBox::TextBox() {
	text = "Once upon a time...";
}
void CheckBox::SetChoices(int num) {
	this->number_of_choices = num;
}
void CheckBox::ShowElementInfo() {
	cout << "���������� x �������� : " << this->coordX << endl;
	cout << "���������� y �������� : " << this->coordY << endl;
	cout << "��� �������� : " << this->shape << endl;
	cout << "���� �������� : " << this->main_color << endl;
	cout << "����� � ��������: " << this->text << endl;
	cout << "���� ������ : " << this->main_color << endl;
	cout << "����� �� ������ : " << this->button_text << endl;
	cout << "��������� ������ : ";
	this->IsPressed == true ? (cout << "������" << endl) : (cout << "�� ������" << endl);
	cout << "���������� ��������� ��������: " << this->number_of_choices << endl;
	cout << endl;
}