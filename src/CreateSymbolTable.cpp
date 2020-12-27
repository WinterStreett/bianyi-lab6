#include"CreateSymbolTable.h"

using namespace std;

symTable symtable(0);//最后输出的大符号表，同名变量会被不同的id号所区分
socpetable* globalTable = new socpetable();//存储全局作用域里的符号，以此为基点向下扩展
socpetable* nextTable = globalTable;//方便递归，下一级作用域的指针
bool isJustOneBlock = true;
bool isDeclConst = false;
string varType;

void createSymbolTable(TreeNode* node, socpetable* table){
    if(node==nullptr)
        return ;
    switch (node->nodeType)
    {
        case NODE_FUNCPARAM:
            varType = node->child->type->getTypeInfo();
            break;
        case NODE_FUNC:
                table->insert(node->var_name, symtable.nextid());
                symtable.insert(node->var_name,node->type->getTypeInfo(),table->getsocpe(),true);
                node->child->sibling->isConst = true;//函数名对应的变量isConst属性为真
                nextTable = new socpetable(table);
                nextTable->initSocpe(node->lineno, node->var_name); 
                isJustOneBlock = false;
                TreeNode::nowFunc = node;  
                break;
        case NODE_VAR:
            if(node->isdecl)
            {
                table->insert(node->var_name, symtable.nextid());
                node->type = Type::getType(varType);
                if(!isDeclConst)
                    symtable.insert(node->var_name,node->type->getTypeInfo(),table->getsocpe(),false);
                else
                {
                    symtable.insert(node->var_name,node->type->getTypeInfo(),table->getsocpe(),true);
                    node->isConst = true;
                }
            }
            else{
                int id = table->search(node->var_name);
                node->type = Type::getType(symtable.getType(id));
                node->isConst = symtable.isConstVar(id);
            }
            break;
        case NODE_STMT:
            switch (node->stype)
            {
                case STMT_DECL:
                    varType = node->child->type->getTypeInfo();
                    break;
                case STMT_DECL_CONST:
                    varType = node->child->type->getTypeInfo();
                    isDeclConst = true;
                    break;
                case STMT_FOR_DECL:
                    varType = node->child->type->getTypeInfo();
                    goto ergodic;
                case STMT_BLOK:
                    if(isJustOneBlock){
                    nextTable = new socpetable(table);
                    nextTable->initSocpe(node->lineno, "block");
                    }
                    break;
                case STMT_FOR:
                    nextTable = new socpetable(table);
                    nextTable->initSocpe(node->lineno, "for"); 
                    isJustOneBlock = false;
                    goto ergodic;
                case STMT_WHILE:
                    nextTable = new socpetable(table);
                    nextTable->initSocpe(node->lineno, "while"); 
                    isJustOneBlock = false;
                    goto ergodic;          
                case STMT_IF:
                    nextTable = new socpetable(table);
                    nextTable->initSocpe(node->lineno, "if"); 
                    isJustOneBlock = false;
                    goto ergodic;       
                case STMT_IOFUNC:
                    TreeNode::nowFunc->isUseStack = true;
                    break;
                default:
                    break;
            }
            if(!isJustOneBlock)
                isJustOneBlock = true;
            break;
        default:
            break;
    }


ergodic:
    createSymbolTable(node->child,nextTable);
    if(nextTable != table)
    {
        delete nextTable;
        nextTable = table;
    }
    if(node->stype == STMT_DECL_CONST)
        isDeclConst = false;
    createSymbolTable(node->sibling,table);
    return;
}