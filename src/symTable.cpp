#include"symTable.h"

symInfo::symInfo(string name, string type, string scope, bool isconst) {
	this->Name = name;
	this->Type = type;
	this->Socpe = scope;
	this->isConst = isconst;
}

symTable::symTable(unsigned int begin) {
	idCounter = begin;
}

symTable::~symTable() {
	for (auto iter = table.begin(); iter != table.end(); iter++) {
		delete iter->second;
}
}

void symTable::insert(string name, string type, string scope, bool isconst) {
	symInfo* node = new symInfo(name, type, scope, isconst);
	table.insert(pair<int, symInfo*>(idCounter++, node));
}

void symTable::printTable() {
	cout <<  "symbol_id" << "   |   " << "name" << "   |   " << "type" << "   |   "<< "scope"<<"   |   " <<"isConst"<< endl;
	for (auto iter = table.begin(); iter != table.end(); iter++) {
		cout<< "   |   "  <<  iter->first << "   |   "  << iter->second->Name <<"   |   " << iter->second->Type <<"   |   " << iter->second->Socpe<<"   |   ";
		if(iter->second->isConst){
			cout<<"true"<<endl;
		}
		else{
			cout<<"false"<<endl;
		}
	}
}

// void symTable::printTable() {
// 	cout << setw(32) << "symbol_id" << setw(20) << "name" << setw(32) << "type" << setw(32) << "scope" << endl;
// 	for (auto iter = table.begin(); iter != table.end(); iter++) {
// 		cout<< setw(32)  <<  iter->first << setw(32) << iter->second->Name << setw(32) << iter->second->Type <<setw(32)<< iter->second->Socpe << endl;
// 	}
// }

unsigned int symTable::nextid() {
	return idCounter;
}

string symTable::getType(int id){
	return table.find(id)->second->Type;
}

bool symTable::isConstVar(int id){
	return table.find(id)->second->isConst;
}

bool symTable::isGlobal(int id){
	return ((table.find(id)->second->Socpe)=="global");
}
