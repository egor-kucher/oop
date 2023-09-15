#include <iostream>
#include <string>
#include <cctype>
#include <Windows.h>
#pragma once
using namespace std;
extern int check(int a);
class UIelement {
	static int counterX;
	static int counterY;
protected:
	int coordX;
	int coordY;
	string shape;
	string main_color;
public:
	void ChangeCoordinates(int x, int y);
	void ChangeColor(string color);
	void ChangeShape(string shape);
	virtual void ShowElementInfo();
	UIelement();
	UIelement(int coordx, int coordy, string shape);
	UIelement(int coordx, int coordy);
};

class Button : public virtual UIelement {
protected:
	string button_text;
	bool IsPressed;
public:
	void Push();
	void ChangeButtonText(string button_text);
	void ShowElementInfo() override;
	Button();
};
class TextBox : public virtual UIelement {
protected:
	string text;
public:
	void ChangeTextBox(string text);
	void ShowElementInfo() override;
	TextBox();
};
class CheckBox :public TextBox, public Button {
	int number_of_choices;
public:
	void SetChoices(int num);
	void ShowElementInfo() override;
	CheckBox() : number_of_choices(0) {};
};

 