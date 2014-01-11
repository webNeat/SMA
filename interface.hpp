#ifndef INTERFACE_H
#define INTERFACE_H 1

#include <fstream>
#include <map>
#include "lib.hpp"

enum GraphicItemType {
	LABEL,
	MENU,
	FORM,
	WINDOW,
	MENU_ITEM,
	TEXT_FIELD,
	UNKNOWN,
	EMPTY
};

class GraphicItem {
protected:
	GraphicItemType type_;
public:
	GraphicItem(){};
	virtual void display() = 0;
	GraphicItemType getType(){ return type_;};
	~GraphicItem(){};
};

class Label : public GraphicItem {
private:
	string value_;
public:
	Label();
	void setValue(string);
	void display();
	~Label(){};
};

struct MenuItem {
	string value; // the text value
	string target; // the title of the window to go to 
};

class Menu : public GraphicItem {
private:
	map<char, MenuItem> items_;
public:
	Menu();
	void addItem(char, string, string);
	void display();
	string getTarget(char key);
	~Menu(){};
};

struct TextField {
	string label;
	string name;
	string value;	
};

class Form : public GraphicItem {
private:
	vector<TextField> inputs_;
	string target_;
public:
	Form();
	void setTarget(string);
	void display();
	void addField(string, string);
	map<string, string> getInputValues();
	~Form(){};
};

class Window : public GraphicItem {
private:
	string name_;
	string title_;
	vector<Label> labels_;
	vector<Menu> menus_;
	vector<Form> forms_;
	vector<GraphicItem *> items_;
public:
	Window();
	void setName(string);
	string getName();
	void setTitle(string);
	void display();
	void addItem(GraphicItem *);
	map<string, string> getInputValues();
	~Window(){};
};

class Interface{
private:
	vector<Window> windows_;
public:
	Interface(){};
	bool parse(string);
	void addWindow(Window&);
	void displayWindow(string);
	void displayWindows();
};

class Parser{
private:
	static ifstream input_;
	static vector<string> parametres_;
	static GraphicItemType token_;
	static Interface* interface_;
public:
	static Interface makeInterfaceFromFile(string);
	static bool readLine();
	static bool parseWindow();
	static bool parseLabel(Window&);
	static bool parseMenu(Window&);
	static bool parseMenuItem(Menu&);
	static bool parseForm(Window&);
	static bool parseTextField(Form&);
};


#endif