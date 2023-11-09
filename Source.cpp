#include <iostream>
#include <string>
#include <cctype>
#include <Windows.h>
#include <conio.h>
#include <iomanip>
using namespace std;
void setcoordinates(int x, int y) {
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
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
			cout << "���������� ��� ���, �������� ����." << endl;
			cout << "���� ������� ��������� ������ Ctrl+Z, ����� ��������� �������" << endl;
			cin.clear();
			cin.ignore(1024, '\n');
		}
		else {
			if (cin.fail()) {
				cout << "���������� ��� ���, �������� ����." << endl;
				cout << "���� ������� ��������� ������ Ctrl+Z, ����� ��������� �������" << endl;
				cin.clear();
				cin.ignore(1024, '\n');
			}
			else if (cin.good()) break;
		}
		
	}
};
class Program {
	string filename;
	float filesize;
	string bytes;
public:
	Program() {
		filename = "changelog.dll";
		filesize = 0.45;
		bytes = "��";
	}
	string getname() {
		return filename;
	}
	void makefiledata(string filename, float filesize, string bytes) {
		this->filename = filename;
		this->bytes = bytes;
		this->filesize = filesize;
	}
	Program getprogram() {
		return *this;
	}
	friend ostream& operator<< (ostream& out, Program program);
};
ostream& operator<<(ostream& out, Program program) {
	out.setf(ios::hex, ios::basefield);
	out << setw(20) << " " << "|" << setw(45) << right << program.filename << setw(20) << right << program.filesize << " " << program.bytes << setw(13) << "|"<< "\n";
	out.unsetf(ios::hex);
	return out;
}
class Software {
protected:
	Program* programs;
	string name;
	int numofprograms;
	bool system;
public:
	Software() {
		name = "���������";
		programs = new Program[1];
		numofprograms = 1;
		system = true;
	}
	void setName(string name) {
		this->name = name;
	}
	string getName() {
		return name;
	}
	int getnumofprograms() {
		return numofprograms;
	}
	void setSoft(string name, int numofprograms, bool system) {
		this->name = name; 
		this->numofprograms = numofprograms;
		delete[] programs;
		programs = new Program[numofprograms];
		this->system = system;
	}
	void AddFiles(string filename,float size) {
		numofprograms++;
		Program* temp = new Program[numofprograms];
		for (int i = 0; i < numofprograms - 1; i++) {
			temp[i] = programs[i].getprogram();
		}
		temp[numofprograms - 1].makefiledata(filename, size, "M�");
		this->programs = temp;
	}
	void DelFiles(string filename) {
		int k = 0;
		for (int i = 0; i < numofprograms; i++) {
			if (programs[i].getname() == filename) {
				k++;
			}
			if (k > 0) {
				programs[i] = programs[i + 1];
			}
		}
		if (k > 0) numofprograms--;
	}
	Software(const Software& other) {
		numofprograms = other.numofprograms;
		programs = new Program[numofprograms];
		for (int i = 0; i < numofprograms; i++) {
			programs[i] = other.programs[i];
		}
		name = other.name;
		system = other.system;
	}
	friend ostream& operator<< (ostream& out, Software st);
};
ostream& operator<<(ostream& out, Software st) {
	out.setf(ios::showpos|ios::boolalpha);
	out << "\n\n\n" << setw(20) << right << " " << "-------------------------------------------------------------------------------" << "\n";
	out << setw(20) << " " << "|" << setw(45) << right << st.name << setw(33) << "|" << "\n";
	out << setw(20) << " " << "|" << setw(10) << right << " " << "���������:" << setw(25) << right << st.system << setw(33) << "|" << "\n";
	out << setw(20) << " " << "|" << setw(10) << right << " " << "���������� ����������:" << setw(12) << right << st.numofprograms << setw(34) << "|" << "\n";
	if (st.numofprograms != 0) out << setw(20) << right << " " << "-------------------------------------------------------------------------------" << "\n";
	out.unsetf(ios::boolalpha|ios::showpos);
	return out;
}
class OS : public Software {
	string version;
	string type;
public:
	OS() {
		version = "1.0";
		type = "Windows";
	}
	void setType(string type) {
		if (type != "Windows" && type != "macOS" && type != "Linux") {
			this->type = "Windows";
			cout << "����� ������������ ������� �� ����������!\n����������� ����������� �� WIndows" << endl;
		}
		else this->type = type;
		
	}
	string getType() {
		return type;
	}
	string getName() {
		return name;
	}
	string getVersion() {
		return version;
	}
};
class Computer {
	string model;
	string dateofcreation;
	Software* soft;
	OS type;
	int numofsoft;
public:
	void addprogram(string filename, float bytes, int num) {
		soft[num - 1].AddFiles(filename, bytes);
	}
	void printSoft(string soft) {
		int count = 0;
		for (int i = 0; i < numofsoft; i++) {
			if (soft == this->soft[i].getName()) {
				cout << this->soft[i];
				count++;
				break;
			}
		}
		if (count == 0) cout << "������ ����� � �� ���" << endl;
	}
	Computer() {
		model = "Asus";
		soft = new Software[1];
		dateofcreation = "12.12.2004";
		numofsoft = 1;
		type.setType("Windows");
	}
	Computer(string model, string OStype) {
		this->model = model;
		soft = new Software[1];
		numofsoft = 1;
		dateofcreation = "12.12.2004";
		try {
			type.setType(OStype);
		}
		catch (int) {
			cout << "������������ ����, ������ ���� �� �� ����������" << endl;
		}
	}
	Computer(const Computer& other) {
		numofsoft = other.numofsoft;
		soft = new Software[numofsoft];
		for (int i = 0; i < numofsoft; i++) {
			soft[i] = other.soft[i];
		}
		dateofcreation = other.dateofcreation;
		model = other.model;
		type = other.type;
	}
	void setnumofsoft(int num) {
		this->numofsoft = num;
	}
	int getNumofsoft() {
		return numofsoft;
	}
	void setModel(string model) {
		this->model = model;
	}
	string getModel() {
		return model;
	}
	void setDate(string date) {
		int k = 0;
		if (date.find_first_not_of("1234567890.") != date.npos || date.length() != 10) throw "�������� ����";
		for (int i = 0; i < date.length(); i++) {
			if (date[i] == '.' && (i == 2 || i == 5)) k++;
		}
		if (k != 2) throw "�������� ����";
		else this->dateofcreation = date;
	}
	void MakeSoft(string* new_obj) {
		delete[] soft;
		try {
			soft = new Software[numofsoft];
			for (int i = 0; i < numofsoft; i++) {
				soft[i].setName(new_obj[i]);
			}
		}
		catch (const bad_alloc& ex) {
			cout << "�� ���������� �� ������� ������" << endl;
		}
	}
	void addSoft(string name,int numofprograms) {
		numofsoft++;
		Software* temp = new Software[numofsoft];
		for (int i = 0; i < numofsoft - 1; i++) {
			temp[i].setSoft(this->soft[i].getName(), this->soft[i].getnumofprograms(), false);
		}
		temp[numofsoft - 1].setSoft(name, numofprograms, false);
		this->soft = temp;
	}
	void sort() {
		
	}
	void deleteSoft(int soft) {
		for (int i = 0; i < numofsoft - 1; i++) {
			if (i + 1 == soft) {
				this->soft[i].setName(this->soft[i + 1].getName());
			}
		}
		if (soft <= numofsoft) numofsoft--;
		else throw "������� �� ��� ���";
	}
	void setOS(string new_os) {
		try {
			type.setType(new_os);
		}
		catch (int) {
			cout << "������������ ����, ������ ���� �� �� ����������" << endl;
		}
	}
	friend ostream& operator<< (ostream& out, Computer PC);
};
ostream& operator<<(ostream& out, Computer PC) {
	out << "\n\n\n" << setw(20) << right << " " << "-------------------------------------------------------------------------------" << "\n";
	out << setw(20) << " " << "|" << setw(45) << right << PC.model << setw(33) << "|" << "\n";
	out << setw(20) << " " << "|" << setw(10) << right << " " << "���� ������:" << setw(35) << right << PC.dateofcreation << setw(21) << "|" << "\n";
	out << setw(20) << " " << "|" << setw(10) << right << " " << "������������ �������:" << setw(25) << right << PC.type.getType() << setw(22) << "|" << "\n";
	out << setw(20) << " " << "|" << setw(10) << right << " " << "����������� �����������:" << setw(22) << right << PC.numofsoft << setw(22) << "|" << "\n";
	out << setw(20) << right << " " << "-------------------------------------------------------------------------------" << "\n";
	for (int i = 0; i < PC.numofsoft; i++) {
		out << setw(20) << " " << "|" << setw(10) << right << " " << "���������� " << i + 1 << " :" << setw(25) << right << PC.soft[i].getName() << setw(29) << "|" << "\n";
	}
	if (PC.numofsoft != 0) out << setw(20) << right << " " << "-------------------------------------------------------------------------------" << "\n";
	return out;
}
int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int choice = 0;
	Computer MyPC;
	MyPC.addSoft("Microsoft Visual Studio", 4);
	MyPC.addprogram("iisresolver.dll", 0.025, MyPC.getNumofsoft());
	MyPC.addprogram("EntityFramework.dll", 5, MyPC.getNumofsoft());
	MyPC.addprogram("MSTest.exe", 0.020, MyPC.getNumofsoft());	
	MyPC.addprogram("PublisizeResources.dll", 0.020, MyPC.getNumofsoft());
	MyPC.addSoft("Microsoft Office", 2);
	MyPC.addprogram("file.doc", 0.0025, MyPC.getNumofsoft());
	MyPC.addprogram("operations.xml", 20, MyPC.getNumofsoft());
	string model,date,os,purpose,name;
	string* soft;
	float size=0;
	while (1) {
		string x = "";
		system("cls");
		setcoordinates(68, 2);
		cout << "��������� ��������� ������������ ����������� ����������" << endl;
		setcoordinates(70, 3);
		cout << "��������, ��� �� ������ �������" << endl;
		cout << "1. ������� ������ �� ��������� �� ����������" << endl;
		cout << "2. �������� ����� �� � ���������" << endl;
		cout << "3. ������� �� �� ����������" << endl;
		cout << "4. �������� �������������� ����������" << endl;
		cout << "5. ����� �� �� �������� � ������� ��� ��������������" << endl;
		cout << "6. ����������� �� �������� ��" << endl;
		cout << "7. �������� ��������� � ��" << endl;
		cout << "8. ����� �� ����������" << endl;
		check(choice);
		switch (choice) {
		case 0: return 0;
		case 1: cout << MyPC;
			system("pause");
			break;
		case 2: cout << "������� �������� ������ ��" << endl;
			getline(cin, model);
			cout << "������� ���������� �������� � ����� ��" << endl;
			check(choice);
			MyPC.addSoft(model, choice);
			for (int i = 0; i < choice; i++) {
				cout << "������� �������� " << i + 1 << " ���������" << endl;
				getline(cin, name);
				cout << "������� �� ������ (� ��)" << endl;
				check(size);
				MyPC.addprogram(name, size, MyPC.getNumofsoft());
			}
			cout << "�� ������� ���������" << endl;
			system("pause");
			break;
		case 3:
			cout << "������� ����� ���������� ��" << endl;
			while (1) 
			{
				if (!(cin >> choice) || cin.get() != '\n');
				else break;
			}
				MyPC.deleteSoft(choice);
				cout << "�� ������� �������" << endl;
			system("pause");
			break;
		case 4:cout << "������� ������ ������ ����������" << endl;
			getline(cin, model);
			cout << "������� ���� ������ ���������� ��/��/����" << endl;
			getline(cin, date);
			cout << "������� ���� ��" << endl;
			getline(cin, os);
			cout << "������� ���������� ������ ��" << endl;
			while (1) 
			{
				if (!(cin >> choice) || cin.get() != '\n');
				else break;
			}
			if (choice > 100) throw (bad_alloc());
			soft = new string[choice];
			for (int i = 0; i < choice; i++) {
				cout << "������� �������� " << i + 1 << " ��" << endl;
				getline(cin, soft[i]);
			}
			MyPC.setModel(model);
			MyPC.setOS(os);
			MyPC.setDate(date);
			MyPC.setnumofsoft(choice);
			MyPC.MakeSoft(soft);
			delete[] soft;
			system("pause");
			break;
		case 5:
			cout << "������� �������� ��, ���������� � ������� �� ������ ������� �� �����" << endl;
			cin >> noskipws;
			char ch;
			while (cin >> ch && ch!='\n') {
				x += ch;
			}
			MyPC.printSoft(x);
			system("pause");
			break;
		case 6:
			MyPC.sort();
			break;
		
		case 7:break;
		case 8:return 0;
			break;
		}
	}
}