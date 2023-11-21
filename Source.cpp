#include <fstream>
#include <iostream>
#include <string>
#include <iomanip>
#include <typeinfo>
#include <Windows.h>
#include <process.h>
using namespace std;
const int MAXSOFT = 100;
void gotoxy(int x, int y) {
	COORD coord;
	coord.X = x;
	coord.Y = y;
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(handle, coord);
}
void setzabor(int x, int y, int length, int width) {
	gotoxy(x, y);
	for (int i = 0; i < length; i++) {
		cout << "-";
	}
	y++;
	for (int i = 1; i < width; i++) {
		gotoxy(x, y);
		cout << "*";
		gotoxy(x + length, y++);
		cout << "*";
	}
	gotoxy(x, y);
	for (int i = 0; i < length; i++) {
		cout << "-";
	}
}
template <typename T>
void check(T& a) {
	while (!cin.eof()) {
		cin >> a;
		if (cin.eof()) {
			cin.clear();
			cin.ignore(1024, '\n');
			a = NULL;
			break;
		}
		else if (cin.get() != '\n') {
			system("cls");
			cout << "���������� ��� ���, �������� ����." << endl;
			cin.clear();
			cin.ignore(1024, '\n');
			throw(1);
		}
		else {
			if (cin.fail()) {
				system("cls");
				cout << "���������� ��� ���, �������� ����." << endl;
				cin.clear();
				cin.ignore(1024, '\n');
				throw(1);
			}
			else if (cin.good()) break;
		}

	}
};
enum SoftwareType {os,application,utilities,drivers };
class Software {
protected:
	string name;
	float size;
	string developer;
	float version;
	static int curSoft;
	static Software* downloaded[];
public:
	Software() {
		name = "missing";
		size = 0;
		developer = "None";
		version = 1.0;	
	}
	virtual void getData() {
		system("cls");
		setzabor(50, 7, 100, 12);
		gotoxy(60, 9);
		cout << "������� �������� ��: " << endl;
		gotoxy(82, 9);
		getline(cin, name);
		gotoxy(60, 10);
		cout << "������� ������ �����(� ��): " << endl;
		try {
			gotoxy(90, 10);
			check(size);
		}
		catch (...) {
			system("pause");
			this->getData();
			return;
		}
		gotoxy(60, 11);
		cout << "������� ��� ������������ ��" << endl;
		gotoxy(90, 11);
		getline(cin, developer);
		gotoxy(60, 12);
		cout << "������� ������ ��" << endl;
		try {
			gotoxy(87, 12);
			check(version);
		}
		catch (...) {
			system("pause");
			this->getData();
			return;
		}
	}
	virtual void putData() {
		cout << setw(50) << left << " " << "��������: " << name << endl;
		cout << setw(50) << left << " " << "������: " << size << " MB" << endl;
		cout << setw(50) << left << " " << "�����������: " << developer << endl;
		cout << setw(50) << left << " " << "������ ��: " << version << endl;
	}
	static void add();
	static void display();
	static void read();
	static void write(int option);
	static void del(int num);
	static void select();
	virtual void print(ostream& o) {
		o << name << endl;
		o << size << " " << developer << endl;
		o << version << endl;
	}
	virtual void input(istream& i) {
		i.ignore(1024, '\n');
		getline(i, name);
		i >> size;
		i.ignore(1);
		getline(i, developer);
		i >> version;
	}
	friend ostream& operator<< (ostream & o, Software *soft);
	friend istream& operator>> (istream& i, Software* soft);
};
int Software::curSoft;
Software* Software::downloaded[MAXSOFT];
ostream& operator<< (ostream& o, Software* soft) {
	soft->print(o);
	return o;
}
istream& operator>> (istream& i, Software* soft) {
	soft->input(i);
	return i;
}
class OS : public Software {
private:
	string type;
	string tech_requirements;
public:
	OS() : Software() {
		type = "none";
		tech_requirements = "none";
	}
	void getData() override{
		system("cls");
		setzabor(50, 7, 100, 12);
		gotoxy(60, 9);
		cout << "������� �������� ��: " << endl;
		gotoxy(82, 9);
		getline(cin, name);
		gotoxy(60, 10);
		cout << "������� ������ �����(� ��): " << endl;
		try {
			gotoxy(90, 10);
			check(size);
		}
		catch (...) {
			system("pause");
			this->getData();
			return;
		}
		gotoxy(60, 11);
		cout << "������� ��� ������������ ��" << endl;
		gotoxy(90, 11);
		getline(cin, developer);
		gotoxy(60, 12);
		cout << "������� ������ ��" << endl;
		try {
			gotoxy(87, 12);
			check(version);
		}
		catch (...) {
			system("pause");
			this->getData();
			return;
		}
		gotoxy(60, 13);
		cout << "������� ��� ��: " << endl;
		gotoxy(79, 13);
		getline(cin, type);
		gotoxy(60, 14);
		cout << "������� ����������� ���������� ��� ������ ��: " << endl;
		gotoxy(120, 14);
		getline(cin, tech_requirements);
	}
	void putData() {
		Software::putData();
		cout << setw(50) << left << " " << "��� ��: " << type << endl;
		cout << setw(50) << left << " " << "����������� ����������: " << tech_requirements << endl;
	}
	void print(ostream& o) override{
		Software::print(o);
		o << type << endl;
		o << tech_requirements << endl;
	}
	void input(istream& i) override {
		Software::input(i);
		i.ignore(1024, '\n');
		getline(i, type);
		getline(i,tech_requirements);
	}
};
class Application : public Software {
private:
	string Apptype;
	string category;
	bool license;
public:
	Application() : Software() {
		Apptype = "none";
		category = "none";
		license = false;
	}
	void getData() {
		system("cls");
		setzabor(50, 7, 100, 12);
		gotoxy(60, 9);
		cout << "������� �������� ��: " << endl;
		gotoxy(82, 9);
		getline(cin, name);
		gotoxy(60, 10);
		cout << "������� ������ �����(� ��): " << endl;
		try {
			gotoxy(90, 10);
			check(size);
		}
		catch (...) {
			system("pause");
			this->getData();
			return;
		}
		gotoxy(60, 11);
		cout << "������� ��� ������������ ��" << endl;
		gotoxy(90, 11);
		getline(cin, developer);
		gotoxy(60, 12);
		cout << "������� ������ ��" << endl;
		try {
			gotoxy(87, 12);
			check(version);
		}
		catch (...) {
			system("pause");
			this->getData();
			return;
		}
		gotoxy(60, 13);
		cout << "������� ��� ����������: " << endl;
		gotoxy(85, 13);
		getline(cin, Apptype);
		gotoxy(60, 14);
		cout << "������� ��������� ����������: " << endl;
		gotoxy(93, 14);
		getline(cin, category);
		gotoxy(60, 15);
		cout << "����� �� �������� ��� ����������?"; 
		gotoxy(63, 16);
		cout << "1. - ��";
		gotoxy(63, 17);
		cout << "0. - ���" << endl;
		try{
			gotoxy(60, 18);
			check(license);
		}
		catch (...) {
			system("pause");
			this->getData();
			return;
		}
	}
	void putData() {
		Software::putData();
		cout << setw(50) << left << " " << "��� ����������: " << Apptype << endl;
		cout << setw(50) << left << " " << "���������: " << category<< endl;
		cout.setf(ios::boolalpha);
		cout << setw(50) << left << " " << "������� ������������ ������: " << license << endl;
		cout.unsetf(ios::boolalpha);
	}
	void print(ostream& o) override {
		Software::print(o);
		o << Apptype << endl;
		o << category << endl;
		o << license << endl;
	}
	void input(istream& i) override {
		Software::input(i);
		i.ignore(1024, '\n');
		getline(i, Apptype);
		getline(i, category);
		i >> license;
	}
};
class Utility : public Software {
private:
	string purpose;
	bool updated;
public:
	Utility() : Software() {
		purpose = "none";
		updated = false;
	}
	void getData() {
		system("cls");
		setzabor(50, 7, 100, 12);
		gotoxy(60, 9);
		cout << "������� �������� ��: " << endl;
		gotoxy(82, 9);
		getline(cin, name);
		gotoxy(60, 10);
		cout << "������� ������ �����(� ��): " << endl;
		try {
			gotoxy(90, 10);
			check(size);
		}
		catch (...) {
			system("pause");
			this->getData();
			return;
		}
		gotoxy(60, 11);
		cout << "������� ��� ������������ ��" << endl;
		gotoxy(90, 11);
		getline(cin, developer);
		gotoxy(60, 12);
		cout << "������� ������ ��" << endl;
		try {
			gotoxy(87, 12);
			check(version);
		}
		catch (...) {
			system("pause");
			this->getData();
			return;
		}
		gotoxy(60, 13);
		cout << "������� ��� �������: " << endl;
		gotoxy(85, 13);
		getline(cin, purpose);
		gotoxy(60, 14);
		cout << "����� �� ���������� ��� �������?";
		gotoxy(63, 15);
		cout << "1. - ��";
		gotoxy(63, 16);
		cout << "0. - ���" << endl;
		try {
			gotoxy(60, 17);
			check(updated);
		}
		catch (...) {
			system("pause");
			this->getData();
			return;
		}
	}
	void putData() {
		Software::putData();
		cout << setw(50) << left << " " << "��� ����������: " << purpose << endl;
		cout.setf(ios::boolalpha);
		cout <<setw(50)<<left<<" "<< "���������: " << updated << endl;
		cout.unsetf(ios::boolalpha);
	}
	void print(ostream& o) override {
		Software::print(o);
		o << purpose << endl;
		o << updated << endl;
	}
	void input(istream& i) override {
		Software::input(i);
		i.ignore(1024, '\n');
		getline(i, purpose);
		i >> updated;
	}
};
class Driver : public Software {
private:
	string compatible;
	bool license;
public:
	Driver() : Software() {
		compatible = "none";
		license = false;
	}
	void getData() {
		system("cls");
		setzabor(50, 7, 100, 12);
		gotoxy(60, 9);
		cout << "������� �������� ��: " << endl;
		gotoxy(82, 9);
		getline(cin, name);
		gotoxy(60, 10);
		cout << "������� ������ �����(� ��): " << endl;
		try {
			gotoxy(90, 10);
			check(size);
		}
		catch (...) {
			system("pause");
			this->getData();
			return;
		}
		gotoxy(60, 11);
		cout << "������� ��� ������������ ��" << endl;
		gotoxy(90, 11);
		getline(cin, developer);
		gotoxy(60, 12);
		cout << "������� ������ ��" << endl;
		try {
			gotoxy(87, 12);
			check(version);
		}
		catch (...) {
			system("pause");
			this->getData();
			return;
		}
		gotoxy(60, 13);
		cout << "������� ������������� ��������: " << endl;
		gotoxy(95, 13);
		getline(cin, compatible);
		gotoxy(60, 14);
		cout << "����� �� �������� ��� ����������?";
		gotoxy(63, 15);
		cout << "1. - ��";
		gotoxy(63, 16);
		cout << "0. - ���" << endl;
		try {
			gotoxy(60, 17);
			check(license);
		}
		catch (...) {
			system("pause");
			this->getData();
			return;
		}
	}
	void putData() {
		Software::putData();
		cout << setw(50) << left << " " << "�������������: " << compatible << endl;
		cout.setf(ios::boolalpha);
		cout << setw(50) << left << " " << "������� ������������ ������: " << license << endl;
		cout.unsetf(ios::boolalpha);
	}
	void print(ostream& o) override {
		Software::print(o);
		o << compatible << endl;
		o << license << endl;
	}
	void input(istream& i) override {
		Software::input(i);
		i.ignore(1024, '\n');
		getline(i, compatible);
		i >> license;
	}
};
SoftwareType getType(Software* x) {
	if (typeid (*x) == typeid(OS))
		return SoftwareType::os;
	else if (typeid(*x) == typeid(Driver))
		return SoftwareType::drivers;
	else if (typeid(*x) == typeid(Application))
		return SoftwareType::application;
	else if (typeid(*x) == typeid(Utility))
		return SoftwareType::utilities;
	else {
		cerr << "\n������������ ��� ���������";
		exit(1);
	}
	return SoftwareType::application;
}
void Software::add() {
	int choice;
	system("cls");
	gotoxy(60, 9);
	cout << "��� �� ������ ��������?" << endl;
	gotoxy(60, 10);
	cout << "1. ������������ �������" << endl;
	gotoxy(60, 11);
	cout << "2. �������" << endl;
	gotoxy(60, 12);
	cout << "3. �������" << endl;
	gotoxy(60, 13);
	cout << "4. ����������" << endl;
	setzabor(50, 7, 100, 12);
	gotoxy(60, 14);
	cout << "��� �����: " << endl;
	gotoxy(71, 14);
	try {
		check(choice);
	}
	catch (...) {
		system("pause");
		Software::add();
		return;
	}
	system("cls");
	switch (choice) {
	case 1:
		downloaded[curSoft] = new OS;
		break;
	case 2:
		downloaded[curSoft] = new Utility;
		break;
	case 3:
		downloaded[curSoft] = new Driver;
		break;
	case 4:
		downloaded[curSoft] = new Application;
		break;
	default: cout << "������������ ����" << endl;
		system("pause");
		return;
	}
	downloaded[curSoft++]->getData();
	system("cls");
	cout << "������� ���������" << endl;
	system("pause");
}
void Software::display() {
	if (curSoft == 0) {
		system("cls");
		cout << "��� �� ���� ������� �� ������ ��" << endl;
		return;
	}
	gotoxy(0,12);
	for (int j = 0; j < curSoft; j++) {
		cout << setw(50)<< left << " " << (j + 1);
		SoftwareType softype;
		softype = getType(downloaded[j]);
		switch (softype) {
		case SoftwareType::os:
			cout << ". ���: ������������ �������" << endl;
			break;
		case SoftwareType::application:
			cout << ". ���: ����������" << endl;
			break;
		case SoftwareType::utilities:
			cout << ". ���: �������" << endl;
			break;
		case SoftwareType::drivers:
			cout << ". ���: �������" << endl;
			break;
		default: cout << ". ����������� ���" << endl;
		}
		downloaded[j]->putData();
		if (j != curSoft - 1) {
			cout << setw(40) << left << " " << "---------------------------------------------------------------------------------------------------" << endl;
		}
		cout << endl;
	}
	setzabor(40, 10, 100, 10 * curSoft);
	cout << endl;
}
void Software::write(int option) {
	int size = 0;
	ofstream ouf;
	SoftwareType softype;
	switch (option) {
	case 1:
		ouf.open("SOFT.txt", ios::app);
		break;
	case 2:
		ouf.open("SOFT.txt", ios::trunc);
		break;
	}
	if (!ouf) {
		cout << "\n���������� ������� ����\n";
		ouf.close();
		return;
	}
	for (int j = 0; j < curSoft; j++) {
		softype = getType(downloaded[j]);
		ouf << softype << endl;
		ouf << downloaded[j];
		if (!ouf) {
			cout << "\n������ � ���� ����������\n";
			ouf.close();
			return;
		}
	}
	ouf.close();
}
void Software::del(int num) {
	if (curSoft < num) {
		cout << "������� �� ��� �� ���������" << endl;
	}
	else {
		int size = 0;
		ofstream ouf;
		SoftwareType softype;
		ouf.open("../x64", ios::trunc);
		if (!ouf.is_open()) {
			cout << "\n���������� ������� ����\n";
			return;
		}
		for (int j = 0; j < curSoft; j++) {
			if (j != num - 1) {
				softype = getType(downloaded[j]);
				ouf << softype << endl;
				ouf << downloaded[j];
				if (!ouf) {
					cout << "\n������ � ���� ����������\n";
					return;
				}
			}
		}
		Software::read();
		system("cls");
		cout << "������� �������" << endl;
	}
}
void Software::select() {
	int choice;
	int kol = 0;
	system("cls");
	gotoxy(60, 3);
	cout << "����� �� �� ������ ������� �� �����?" << endl;
	gotoxy(60, 4);
	cout << "1. ������������ �������" << endl;
	gotoxy(60, 5);
	cout << "2. �������" << endl;
	gotoxy(60, 6);
	cout << "3. �������" << endl;
	gotoxy(60, 7);
	cout << "4. ����������" << endl;
	gotoxy(60, 8);
	cout << "��� �����: " << endl;
	gotoxy(71, 8);
	try {
		check(choice);
	}
	catch (...) {
		system("cls");
		cout << "������������ ����" << endl;
		system("pause");
		return;
	}
	cout << endl;
	cout << endl;
	switch (choice) {
	case 1:
		for (int j = 0; j < curSoft; j++) {
			SoftwareType softype;
			softype = getType(downloaded[j]);
			if (softype == os)
			{
				if (kol != 0) {
					cout << setw(40) << left << " " << "---------------------------------------------------------------------------------------------------" << endl;
				}
				cout << endl;
				kol++;
				cout << setw(50) << left << " " << (j + 1) << ". ���: ������������ �������" << endl;
				downloaded[j]->putData();
			}
		}
		break;
	case 2:
		for (int j = 0; j < curSoft; j++) {
		SoftwareType softype;
		softype = getType(downloaded[j]);
		if (softype == utilities)
		{
			if (kol != 0) {
				cout << setw(40) << left << " " << "---------------------------------------------------------------------------------------------------" << endl;
			}
			cout << endl;
			kol++;
			cout << setw(50) << left << " " << (j + 1) << ". ���: �������" << endl;
			downloaded[j]->putData(); 
		}
	}
		break;
	case 3:
		for (int j = 0; j < curSoft; j++) {
		SoftwareType softype;
		softype = getType(downloaded[j]);
		if (softype == drivers)
		{
			if (kol != 0) {
				cout << setw(40) << left << " " << "---------------------------------------------------------------------------------------------------" << endl;
			}
			cout << endl;
			kol++;
			cout << setw(50) << left << " " << (j + 1) << ". ���: ��������" << endl;
			downloaded[j]->putData();
		}
	}
		break;
	case 4:
		for (int j = 0; j < curSoft; j++) {
		SoftwareType softype;
		softype = getType(downloaded[j]);
		if (softype == application)
		{
			if (kol != 0) {
				cout << setw(40) << left << " " << "---------------------------------------------------------------------------------------------------" << endl;
			}
			cout << endl;
			kol++;
			cout << setw(50) << left << " " << (j + 1) << ". ���: ����������" << endl;
			downloaded[j]->putData();
		}
	}
		break;
	default:
		system("cls");
		cout << "������ ���� � ����� ���" << endl;
		break;
	}
	if (kol == 0) {
		system("cls");
		cout << "��� ������ ��" << endl;
	}
	else
	setzabor(40, 10, 100, 10 * kol);
	system("pause");
}
void Software::read() {
	int size;
	SoftwareType softype;
	ifstream inf;
	inf.open("SOFT.txt");
	if (!inf) {
		cout << "\n���������� ������� ����\n";
		return;
	}	
	curSoft = 0;
	while (true) {
		inf >> size;
		softype = static_cast<SoftwareType>(size);
		if (inf.eof()) {
			inf.close();
			break;
		}
		if (!inf) {
			cout << "\n���������� ������ ����\n";
			return;
		}
		switch (softype) {
		case SoftwareType::os:
			downloaded[curSoft] = new OS;
			break;
		case SoftwareType::application:
			downloaded[curSoft] = new Application;
			break;
		case SoftwareType::drivers:
			downloaded[curSoft] = new Driver;
			break;
		case SoftwareType::utilities:
			downloaded[curSoft] = new Utility;
			break;
		default: cout << "\n����������� ��� � �����\n";
			return;
		}
		inf >> downloaded[curSoft];
		if (!inf) {
			cout << "\n������ ������ �� ����� ����������\n";
			return;
		}
		curSoft++;
	}
	cout << "��������� " << curSoft << " ��" << endl;
}
int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	keybd_event(VK_MENU, 0x38, 0, 0);
	keybd_event(VK_RETURN, 0x1c, 0, 0);
	keybd_event(VK_RETURN, 0x1c, KEYEVENTF_KEYUP, 0);
	keybd_event(VK_MENU, 0x38, KEYEVENTF_KEYUP, 0);
	int choice;
	while (true) {
		system("cls");
		gotoxy(60, 9);
		cout << "1 - ���������� �������� � ��" << endl;
		gotoxy(60, 10);
		cout << "2 - ������� �������� ��� ���� ��" << endl;
		gotoxy(60, 11);
		cout << "3 - �������� ��� ������ � ����" << endl;
		gotoxy(60, 12);
		cout << "4 - ������������ ��� ������ � ����" << endl;
		gotoxy(60, 13);
		cout << "5 - ��������� ��� ������ �� �����" << endl;
		gotoxy(60, 14);
		cout << "6 - ������� ��" << endl;
		gotoxy(60, 15);
		cout << "7 - ������� �������� �� ������ �� ���� �� �� �����" << endl;
		gotoxy(60,16);
		cout << "8 - �����" << endl;
		gotoxy(60, 17);
		cout << "��� �����: " << endl;
		setzabor(50,7,100,12);
		gotoxy(71, 17);
		try {
			check(choice);
		}
		catch (...) {
			system("pause");
			continue;
		}
		system("cls");
		switch (choice) {
		case 1:
			Software::add();
			system("cls");
			break;
		case 2:
			Software::display(); 
			system("pause");
			break;
		case 3:
			Software::write(1);
			break;
		case 4:
			Software::write(2);
			break;
		case 5:
			Software::read(); 
			system("pause");
			break;
		case 6: Software::read();
			system("cls");
			gotoxy(60, 3);
			cout << "������� �����, ������� �� ������ �������" << endl;
			Software::display();
			check(choice);
			Software::del(choice);
			system("pause");
			break;
		case 7:Software::read();
			Software::select();
			cout << endl;
			break;
		case 8: return 0;
			break;
		default: cout << "����������� �������" << endl;
			break;
		}
	}
	
	return 0;
}