#include "socpeTable.h"

socpetable::socpetable() {
	upper = nullptr;
	socpe = "global";
}

socpetable::socpetable(socpetable* upper) {
	this->upper = upper;
}

void socpetable::insert(string sym,unsigned int id) {
	if (table.find(sym) != table.end()) {//这个符号已经定义过了
		cerr << sym << "重定义！" << endl;//后面可以添加行号
		exit(0);
	}
	table.insert(pair<string, unsigned int>(sym, id));
}

unsigned int socpetable::search(string sym) {
	map<string, unsigned int>::iterator iter = table.find(sym);
	if (iter == table.end())
	{
		if (upper == nullptr) {
			cerr << sym << "未定义！" << endl;
			exit(0);
		}
		return upper->search(sym);
	}
	return iter->second;
}

void socpetable::makebuddy(socpetable* buddy) {
	buddy->upper = this->upper;
}

void socpetable::initSocpe(int lineno, string stype) {
	if (upper != nullptr) {
		socpe = upper->getsocpe();
		socpe += "->"+to_string(lineno) + stype;
	}
}

string socpetable::getsocpe() {
	return socpe;
}
