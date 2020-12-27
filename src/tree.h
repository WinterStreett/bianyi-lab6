#ifndef TREE_H
#define TREE_H

#include "pch.h"
#include "type.h"
extern long int current_id;
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
    OP_NOT, // 取反
    OP_INC, //++
    OP_DEC,// --

    OP_ADD, //加号
    OP_SUB, //减号
    OP_MUL, //乘法
    OP_DIV, //除法
    OP_MOD, //取模
    OP_OR, // ||
    OP_AND,// &&
    OP_LT,// <
    OP_BT,// >
    OP_LTEQ,// <=
    OP_BTEQ,// >=
    OP_EQ,  // ==
    OP_NQ, // !=
    OP_ASSG,// 赋值号 =
 
    OP_ADD_ASSG, // +=
    OP_SUB_ASSG,  // -=

    OP_FUNC,//函数调用
};

enum StmtType {
    STMT_SKIP,
    STMT_DECL,
    STMT_DECL_CONST,//常量声明
    STMT_ASSG,
    STMT_EXPR,
    STMT_BLOK,
    STMT_IF,
    STMT_IFELSE,
    STMT_WHILE,
    STMT_BREAK,
    STMT_CONTI,
    STMT_RETURN,
    STMT_FOR,
    STMT_IOFUNC,
    STMT_FOR_DECL,
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

    bool isConst;//如果是表达式节点，标记它是不是常量类型
    bool isdecl;//标记一个标识符，说明它是要被定义的变量名

public:
    void check(TreeNode*);
private:
    ExpType type_check(TreeNode *);

private:
    static int label_seq;
    string new_label(void);
    void recursive_get_label(TreeNode* );
public:
    void get_label(TreeNode*);
    Label label;

public:
    static string nodeType2String (NodeType type);
    static string opType2String (OperatorType type);
    static string sType2String (StmtType type);

public:
    TreeNode(int lineno, NodeType type);
};

#endif