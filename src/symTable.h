#ifndef SYMTABLE
#define SYMTABLE

#include<map>
#include<iostream>
#include<string>
#include<iomanip>
using std::cout;
using std::endl;
using std::string;
using std::map;
using std::pair;
using std::setw;
//定义符号表的单项包含的信息的结构体
struct symInfo {
	string Name;
	string Type;
	string Socpe;
	bool isConst;
	bool isDef;
	int scopeID;
	symInfo(string name, string type, string scope,bool isconst);
	// symInfo(string name, string type, string scope,bool isconst,bool isdef,int scopeid);
};


class symTable {
public:
	symTable(unsigned int begin);
	~symTable();
	void insert(string name, string type, string scope,bool isconst);
	void printTable();
    unsigned int nextid();
	string getType(int id);
	bool isConstVar(int id);
	bool isGlobal(int id);

private:
	map<int, symInfo*> table;
	unsigned int idCounter;
};
#endif // !1
