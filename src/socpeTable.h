#ifndef SOCPETABLE
#define SOCPETABLE

#include<map>
#include<iostream>
#include<string>
using std::cout;
using std::endl;
using std::string;
using std::map;
using std::pair;
using std::to_string;
using std::cerr;

class socpetable {
public:
	socpetable();
	socpetable(socpetable* upper);
	void insert(string sym, unsigned int id);
	unsigned int search(string sym);
	void makebuddy(socpetable* buddy);
	void initSocpe(int lineno, string stype);
	string getsocpe();
private:
	map<string, unsigned int> table;
	socpetable* upper;
	string socpe;
};

#endif // !SOCPETABLE
