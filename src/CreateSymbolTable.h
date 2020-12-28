#include"common.h"
#include"symTable.h"
#include"socpeTable.h"
using namespace std;

extern symTable symtable;//最后输出的大符号表，同名变量会被不同的id号所区分
extern socpetable* globalTable;//存储全局作用域里的符号，以此为基点向下扩展
extern socpetable* nextTable;//方便递归，下一级作用域的指针
extern bool isJustOneBlock;
extern bool isDeclConst;
extern string varType;


void createSymbolTable(TreeNode* node, socpetable* table);//创建符号表的函数，递归遍历语法树一次，建立完整的符号表