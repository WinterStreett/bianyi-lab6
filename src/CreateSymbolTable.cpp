#include"CreateSymbolTable.h"

using namespace std;

symTable symtable(0);//最后输出的大符号表，同名变量会被不同的id号所区分
socpetable* globalTable = new socpetable();//存储全局作用域里的符号，以此为基点向下扩展
socpetable* nextTable = globalTable;//方便递归，下一级作用域的指针
bool isJustOneBlock = true;
bool isDeclConst = false;


string varType;
extern map<string, int> stringTable;
int str_num = 0;
int socpeVarCount = 0;//记录一个函数作用域内的所有变量的顺序ID



void createSymbolTable(TreeNode* node, socpetable* table){
    if(node==nullptr)
        return ;
    switch (node->nodeType)
    {
        case NODE_FUNCPARAMS:
        {          
            TreeNode* temp = node->child;
            int num = 0;
            while(temp!=nullptr){
                num++;
                temp = temp->sibling;
            }
            TreeNode::nowFunc->paraNum = num;
            
            break;
        }
        case NODE_FUNCPARAM:
            varType = node->child->type->getTypeInfo();
            node->child->sibling->isassg = true;
            break;
        case NODE_CONST://将程序中出现的所有string插入stingTable中
        {
            if(node->type->getTypeInfo() == "string"){
                haveString = true;
                if(stringTable.find(node->str_val) == stringTable.end()){//字符串不在表中
                    stringTable.insert(pair<string,int>(node->str_val,str_num));
                    node->str_id = str_num++;
                }
                else{//字符串已在表中
                    node->str_id = stringTable.find(node->str_val)->second;
                }
            }
            break;
        }
        case NODE_FUNC:
                if(node->var_name=="main")
                {
                    TreeNode* temp = node->child;
                    while(temp->sibling!=nullptr){
                        temp=temp->sibling;
                    }
                    TreeNode::mainNode = temp;
                }
                table->insert(node->var_name, symtable.nextid());
 
                socpeVarCount = 0;
                symtable.insert(node->var_name,node->type->getTypeInfo(),table->getsocpe(),true,true,socpeVarCount);
                node->child->sibling->isConst = true;//函数名对应的变量isConst属性为真
                nextTable = new socpetable(table);
                nextTable->initSocpe(node->lineno, node->var_name); 
                isJustOneBlock = false;
                TreeNode::nowFunc = node;  
                break;
        case NODE_VAR:
            if(node->isdecl)
            {
                if(table == globalTable)
                {
                    node->isGlobal = true;
                    haveGlobalVar = true;
                }
                table->insert(node->var_name, symtable.nextid());
                node->tableid = symtable.nextid();
                node->type = Type::getType(varType);
                if(!isDeclConst)
                    symtable.insert(node->var_name,node->type->getTypeInfo(),table->getsocpe(),false,false,++socpeVarCount);
                else
                {
                    symtable.insert(node->var_name,node->type->getTypeInfo(),table->getsocpe(),true,false,++socpeVarCount);
                    node->isConst = true;
                    if(node->isGlobal)
                        haveGlobalConst = true;
                }
                
                TreeNode::tempNUm = socpeVarCount;
            }
            else{
                int id = table->search(node->var_name);
                node->type = Type::getType(symtable.getType(id));
                node->isConst = symtable.isConstVar(id);
                node->isGlobal = symtable.isGlobal(id);
                node->tableid = id;
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
                {
                    TreeNode::nowFunc->isUseStack = true;
                    if(node->child->sibling)
                    {
                        TreeNode* temp = node->child->sibling->child;//实参表
                        int num = 0;
                        while(temp!=nullptr){
                            num++;
                        temp = temp->sibling;
                        }
                        node->paraNum = num;
                    }
                    else
                    {
                        node->paraNum = 0;
                    }
                    
                    
                    break;
                }
                    
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