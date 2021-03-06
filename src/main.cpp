#include "common.h"
#include"CreateSymbolTable.h"
#include <fstream>

extern TreeNode *root;
extern FILE *yyin;
extern int yyparse();


string filename = "who knows";

using namespace std;
int main(int argc, char *argv[])
{
    if (argc == 2)
    {
        FILE *fin = fopen(argv[1], "r");
        if (fin != nullptr)
        {
            yyin = fin;
        }
        else
        {
            cerr << "failed to open file: " << argv[1] << endl;
        }
    }
    // 获取文件名
    // string buf = argv[1];
    // int temp = buf.find_last_of('\\');
    // cout<<temp<<endl;
    // cout<<filename<<endl;
    // filename = argv[1];
    yyparse();
    // //将一些运行库函数先加入符号表
    // globalTable->insert("printf",symtable.nextid());
    // symtable.insert("printf","void","global",true);
    if(root != NULL) {
        root->genNodeId();

        createSymbolTable(root, globalTable);//建表会对声明语句中的变量的类型赋值

        root->check(root);
        root->get_label(root);
        // root->printAST();
        root->gen_code(root);
    }

    // cout<<endl;
    // symtable.printTable();
    // cout<<symtable.nextid()<<endl;
    return 0;
}