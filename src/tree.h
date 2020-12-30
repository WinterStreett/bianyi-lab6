#ifndef TREE_H
#define TREE_H

#include "pch.h"
#include "type.h"
#include "symTable.h"
extern long int current_id;
extern bool is_use_stack;
extern map<string, int> stringTable;
extern bool haveGlobalVar;
extern bool haveGlobalConst;
extern bool haveString;

enum NodeType
{
    NODE_EMPTY,//空节点，对应没有内容的节点
    NODE_CONST, 
    NODE_VAR,
    NODE_EXPR,
    NODE_TYPE,

    NODE_STMT,
    NODE_PROG,
    NODE_COMP,
    NODE_FUNC,
 
    NODE_LVAL,//左值表达式
    NODE_INITVAL,//变量声明右值
    NODE_FUNCPARAMS,
    NODE_FUNCPARAM,
    NODE_VARDEF,
    NODE_FUNCRPARAMS,//函数实参
};


enum OperatorType
{
    OP_NULL,//无符号
    OP_OPT,  // 正号
    OP_NEG,  // 负号

    OP_ADD, //加号
    OP_SUB, //减号
    OP_MUL, //乘法
    OP_DIV, //除法
    OP_MOD, //取模

    OP_LT,// <
    OP_BT,// >
    OP_LTEQ,// <=
    OP_BTEQ,// >=
    OP_EQ,  // ==
    OP_NQ, // !=

    OP_ASSG,// 赋值号 =
    OP_ADD_ASSG, // +=
    OP_SUB_ASSG,  // -=

    OP_OR, // ||
    OP_AND,// &&
    OP_NOT, // 取反

    OP_INC, //++
    OP_DEC,// --

    OP_FUNC,//函数调用
};

enum StmtType {
    STMT_SKIP,
    STMT_DECL,
    STMT_DECL_CONST,//常量声明
    // STMT_ASSG,
    STMT_EXPR,
    STMT_BLOK,
    //老大难
    STMT_IF,
    STMT_IFELSE,
    STMT_WHILE,
    STMT_FOR,

    STMT_FOR_DECL,

    STMT_BREAK,
    STMT_CONTI,
    STMT_RETURN,

    STMT_IOFUNC,

}
;

enum ExpType {//在类型检查中使用的类型
    EXP_NOTYPE,

    EXP_INT,
    EXP_CHAR,
    EXP_BOOL,
    EXP_STRING,
}
;


struct Label {//标签类型
    //布尔表达式专有
	string true_label;
	string false_label;
    //语句专有
	string begin_label;
	string next_label;
};




struct TreeNode {
public:
    int nodeID;  // 用于作业的序号输出
    int lineno;
    NodeType nodeType;


    TreeNode* child = nullptr;
    TreeNode* sibling = nullptr;

    void addChild(TreeNode*);
    void addSibling(TreeNode*);
    
    void printNodeInfo();
    void printChildrenId();

    void printAST(); // 先输出自己 + 孩子们的id；再依次让每个孩子输出AST。
    void printSpecialInfo();

    void genNodeId();


public:
    OperatorType optype;  // 如果是表达式
    Type* type;  // 变量、类型、表达式结点，有类型。
    StmtType stype;
    ExpType expType;
    int int_val;
    char ch_val;
    bool b_val;
    string str_val;
    string var_name;

    int tableid;
    bool isConst;//如果是表达式节点，标记它是不是常量类型
    bool isdecl;//标记一个标识符，说明它是要被定义的变量名
    bool isGlobal;//标记一个标识符是不是全局作用域的
    bool isMyLabelWasCout;
    bool isassg;//如果这是一个变量结点，标记它有没有处于一个赋值语句中

    int str_id;//如果结点为string常量结点，那么这个数组标记它对应的字符串在数据段的编号
    
    int paraNum;//如果结点为函数实参类型，那么它应该保存实参的个数，在生成符号表时填上
    // int tempNum;
    static int tempNUm;//说明main函数里的局部变量数目
public://类型检查
    void check(TreeNode*);
private:
    ExpType type_check(TreeNode *);

private://打标签
    static int label_seq;
    string new_label(void);
    void recursive_get_label(TreeNode* );
public:
    void get_label(TreeNode*);
    Label label;

public://代码生成
    void gen_code(TreeNode*);
    static TreeNode* nowFunc;//在遍历语法树的过程中，处于哪一个函数结点中
    
    bool isUseStack;//给函数结点的标记，说明这个函数有没有使用栈
    bool exprResult;//表达式结点的代表的式子有没有完成输出代码

private:
    void gen_header();//生成头部信息
    void recursive_gen_code(TreeNode *);//递归生成代码
    void gen_decl(TreeNode *);//给全局变量和字符串分配空间、
    void gen_decl_var(TreeNode *, bool isdeclConst);//isdeclConst：是否是给常量分配空间
    void stmt_gen_code(TreeNode *);
    void expr_gen_code(TreeNode *);
    void var_gen_code(TreeNode * , string);//专门给变量准备的输出函数
    void const_gen_code(TreeNode * , string);//专门给字面常量准备的输出函数
    void inst2string(OperatorType);//为不同的操作符，输出不同的汇编指令
    string gen_varname(TreeNode*);
    void howRelOpJmp(OperatorType op,bool ture2jmp, string label);
    string smallReg(string reg);


public:
    static string nodeType2String (NodeType type);
    static string opType2String (OperatorType type);
    static string sType2String (StmtType type);

    static TreeNode* mainNode;

public:
    TreeNode(int lineno, NodeType type);
};

#endif