#include"symTable.h"

symInfo::symInfo(string name, string type, string scope, bool isconst,bool isdef,int scopeid) {
	this->Name = name;
	this->Type = type;
	this->Socpe = scope;
	this->isConst = isconst;
	this->isDef = isdef;
	this->scopeID = scopeid;
}

symTable::symTable(unsigned int begin) {
	idCounter = begin;
}

symTable::~symTable() {
	for (auto iter = table.begin(); iter != table.end(); iter++) {
		delete iter->second;
}
}

void symTable::insert(string name, string type, string scope, bool isconst,bool isdef,int scopeid) {
	symInfo* node = new symInfo(name, type, scope, isconst, isdef, scopeid);
	table.insert(pair<int, symInfo*>(idCounter++, node));
}

void symTable::printTable() {
	cout <<  "symbol_id" << "   |   " << "name" << "   |   " << "type" << "   |   "<< "scope"<<"   |   " <<"isConst";
	cout<<"   |   " <<"isDef"<<"   |   " <<"scopeID"<<endl;
	for (auto iter = table.begin(); iter != table.end(); iter++) {
		cout<< "   |   "  <<  iter->first << "   |   "  << iter->second->Name <<"   |   " << iter->second->Type <<"   |   " << iter->second->Socpe<<"   |   ";
		if(iter->second->isConst){
			cout<<"true";
		}
		else{
			cout<<"false";
		}
		cout<< "   |   ";
		if(iter->second->isDef){
			cout<<"true";
		}
		else{
			cout<<"false";
		}
		cout<< "   |   ";
		cout<<iter->second->scopeID<<endl;
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

bool symTable::isDefed(int id){
	return table.find(id)->second->isDef;
}

int symTable::getScopeID(int id){
	return table.find(id)->second->scopeID;
}

void symTable::setDef(int id){
	table.find(id)->second->isDef = true;
	return;
}