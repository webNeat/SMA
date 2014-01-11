#include <iostream>
#include "interface.hpp"
// Graphic Items
// Label
Label::Label(){
	type_ = LABEL;
}
void Label::setValue(string value){
	value_ = value;
}
void Label::display(){
	cout << value_ << endl;
}

// Menu
Menu::Menu(){
	type_ = MENU;
}
void Menu::addItem(char key, string value, string target){
	MenuItem i;
	i.value = value;
	i.target = target;
	items_.insert( pair<char, MenuItem>(key, i) );
}
void Menu::display(){
	map<char, MenuItem>::iterator it = items_.begin();
	cout << endl;
	while(it != items_.end()){
		cout << "\t" << it->first << ": " << (it->second).value << endl;
		it ++;
	}
}
string Menu::getTarget(char key){
	map<char, MenuItem>::iterator it = items_.find(key);
	if(it != items_.end()){
		return (it->second).target;
	}else{
		return "";
	}
}

// Form
Form::Form(){
	type_ = FORM;
}
void Form::setTarget(string target){
	target_ = target;
}
void Form::addField(string label, string name){
	TextField text;
	text.label = label;
	text.name = name;
	inputs_.push_back(text);
}
void Form::display(){
	// TODO
}
map<string, string> Form::getInputValues(){
	// TODO
	return map<string, string>();
}

// Window
Window::Window(){
	type_ = WINDOW;
}
void Window::setTitle(string title){
	title_ = title;
}
void Window::setName(string name){
	name_ = name;
}
string Window::getName(){
	return name_;
}
void Window::addItem(GraphicItem * item){
	GraphicItem * pointer;
	switch(item->getType()){
		case LABEL:
			labels_.push_back(*((Label*)item));
			pointer = &labels_.back();
		break;
		case MENU:
			menus_.push_back(*((Menu*)item));
			pointer = &menus_.back();
		break;
		case FORM:
			forms_.push_back(*((Form*)item));
			pointer = &forms_.back();
		break;
	}
	items_.push_back(pointer);
}
map<string, string> Window::getInputValues(){
	// TODO ...
	return map<string, string>();
}
void Window::display(){
	vector<GraphicItem *>::iterator it = items_.begin();
	while(it != items_.end()){
		cout << "showing !" << endl;
		(*it)->display();
		it ++;
	}
}

// Parser
ifstream Parser::input_;
vector<string> Parser::parametres_;
GraphicItemType Parser::token_;
Interface* Parser::interface_;

bool Parser::readLine(){
	cout << "readLine begin !" << endl;
	string line;
	getline(input_, line);
	trim(line);
	while((line.size() == 0 || line.at(0) == '#') && !input_.eof()){
		getline(input_, line);
		trim(line);
	}
	if(input_.eof()){
		token_ = EMPTY;
		return false;
	}
	parametres_ = splitString(line, ':');
	char c = parametres_.at(0).at(0);
	switch(c){
		case 'W':
			token_ = WINDOW;
			cout << "WINDOW" << endl;
		break;
		case 'L':
			token_ = LABEL;
			cout << "LABEL" << endl;
		break;
		case 'M':
			token_ = MENU;
			cout << "MENU" << endl;
		break;
		case 'I':
			token_ = MENU_ITEM;
			cout << "MENU_ITEM" << endl;
		break;
		case 'F':
			token_ = FORM;
			cout << "FORM" << endl;
		break;
		case 'T':
			token_ = TEXT_FIELD;
			cout << "TEXT_FIELD" << endl;
		break;
		default:
			token_ = UNKNOWN;
			cout << "UNKNOWN" << endl;
			return false;
	}
	return true;
}
// bool Parser::parseInterface(Interface* interface, string filePath){
// 	cout << "parseInterface begin !" << endl;
// 	bool error = false;
// 	input_.open(filePath.c_str());
// 	interface_ = interface;
// 	while(!error && readLine()){
// 		if(token_ == EMPTY) 
// 			break;
// 		if(token_ == WINDOW){
// 			if(!parseWindow()){
// 				error = true;
// 			}
// 		}else{
// 			error = true;
// 		}
// 	}
// 	return !error;
// }

bool Parser::parseWindow(){
	cout << "parseWindow begin !" << endl;
	Window window;
	if(parametres_.size() == 4){
		window.setName(parametres_.at(1));
		window.setTitle(parametres_.at(2));
		// int size = strToInt(parametres_.at(3));
		int size = 1;
		cout << "size : " << size << endl;
		int i = 0;
		bool error = false;
		while(i < size && !error){
			if(readLine()){
				if(token_ == LABEL || token_ == MENU || token_ == FORM){
					if((token_ == LABEL && !parseLabel(window))
						|| (token_ == MENU && !parseMenu(window))
						|| (token_ == FORM && !parseForm(window))
					){
						cout << "error 1 !" << endl;
						error = true;
					}
				}else{
					cout << "error 2 !" << endl;
					error = true;
				}
			}else{
				cout << "error 3 !" << endl;
				error = true;
			}
			i++;
		}
		if(!error || token_ == EMPTY){
			interface_->addWindow(window);
			cout << "addWindow Finished !" << endl;
			return true;
		}else{
			cout << "error 4 !" << endl;
			return false;	
		}
	}else{
		cout << "error 5 !" << endl;		
		return false;
	}
}
bool Parser::parseLabel(Window& window){
	cout << "parseLabel begin !" << endl;
	if(parametres_.size() == 2){
		Label label;
		label.setValue(parametres_.at(1));
		window.addItem(&label);
		return true;
	}
	cout << "error !" << endl;
	return false;
}
bool Parser::parseMenu(Window& window){
	cout << "parseMenu begin !" << endl;
	if(parametres_.size() == 2){
		Menu menu;
		int nbItems = strToInt(parametres_.at(1));
		int i = 0;
		bool error = false;
		while(i < nbItems && !error){
			if(readLine()){
				if(token_ != MENU_ITEM || (token_ == MENU_ITEM && !parseMenuItem(menu))){
					error = true;
					cout << "error !" << endl;
				}
			}else{
				cout << "error !" << endl;
				error = true;
			}
			i++;
		}
		if(!error){
			window.addItem(&menu);
		}
		return !error;
	}
	cout << "error !" << endl;
	return false;
}
bool Parser::parseMenuItem(Menu& menu){
	cout << "parseMenuItem begin !" << endl;
	if(parametres_.size() == 4){
		menu.addItem(parametres_.at(1).at(1), parametres_.at(2), parametres_.at(3));
		return true;
	}
	cout << "error !" << endl;	
	return false;
}
bool Parser::parseForm(Window& window){
	cout << "parseForm begin !" << endl;
	if(parametres_.size() == 3){
		Form form;
		form.setTarget(parametres_.at(1));
		int nbItems = strToInt(parametres_.at(2));
		int i = 0;
		bool error = false;
		while(i < nbItems && !error){
			if(readLine()){
				if(token_ != TEXT_FIELD || (token_ == TEXT_FIELD && !parseTextField(form))){
					cout << "error !" << endl;
					error = true;
				}
			}else{
				cout << "error !" << endl;
				error = true;
			}
			i++;
		}
		if(!error){
			window.addItem(&form);
		}
		return !error;
	}
	cout << "error !" << endl;	
	return false;
}
bool Parser::parseTextField(Form& form){
	cout << "parseTextField begin !" << endl;
	if(parametres_.size() == 3){
		form.addField(parametres_.at(1), parametres_.at(2));
		return true;
	}
	cout << "error !" << endl;
	return false;
}

// Interface
// bool Interface::parse(string filePath){
// 	return Parser::parseInterface(this, filePath);
// }

bool Interface::parse(string filePath){
	return true;
}

void Interface::displayWindow(string name){
	// TODO ...
}

void Interface::addWindow(Window& window){
	cout << "addWindow begin" << endl;
	cout << "name : " << window.getName() << endl;
	Window win = window;
	windows_.push_back(window);
}

void Interface::displayWindows(){
	vector<Window>::iterator it = windows_.begin();
	while(it != windows_.end()){
		cout << "****************" << endl;
		it->display();
		it++;
	}
}