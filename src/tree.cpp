#include "tree.h"
long int current_id = 0;

int TreeNode::label_seq = 0;
int TreeNode::str_num = 0;

void TreeNode::addChild(TreeNode* child) {
    if(this->child == NULL)
    {//如果本节点的孩子指针为空，直接将参数赋给这个孩子指针
        this->child = child;
    }
    else//如果本节点已经有了孩子
    {
        TreeNode* trace = this->child;
        trace->addSibling(child);//给孩子节点加兄弟
    }
    
}

void TreeNode::addSibling(TreeNode* sibling){
    assert(this!=NULL);
    TreeNode* trace = this;
    while(trace->sibling != NULL)
    {
        trace = trace->sibling;
    }
    trace->sibling = sibling;
}

TreeNode::TreeNode(int lineno, NodeType type) {
    this->lineno = lineno;
    this->nodeType = type;
    this->isdecl = false;
    this->isConst = false;
}

void TreeNode::genNodeId() {
//按照result.txt的输出规律，这个函数应该要实现给语法树的每个节点的nodeID赋值，赋值顺序和输出时的顺序是一致的
//应该是递归实现的，先照顾孩子，再考虑兄弟
//在调用genNodeId函数时，才nodeid会赋值
//因为我们根本没有办法在语法分析结束之前，给语法树编号
        this->nodeID = current_id++;
        if(this->child!=nullptr)
            this->child->genNodeId();
        if(this->sibling!=nullptr)
            this->sibling->genNodeId();
}

void TreeNode::printNodeInfo() {
//根据result.txt来设定输出的格式
        cout<<"lno@"<<this->lineno<<setw(8)<<'@'<<this->nodeID<<setw(16)<<nodeType2String(this->nodeType);
        this->printChildrenId();
        this->printSpecialInfo();
        cout<<endl;
}

void TreeNode::printChildrenId() {
        if(this->child != NULL)
        {
            cout<<setw(16)<<"children: [";
            TreeNode* trace = this->child;
            do{
                cout<<'@'<<trace->nodeID<<' ';
                trace = trace->sibling;
            }while(trace != NULL);
            cout<<"]";
        }
}

void TreeNode::printAST() {
        this->printNodeInfo();
        if(this->child!=nullptr)
            this->child->printAST();
        if(this->sibling!=nullptr)
            this->sibling->printAST();
}


// You can output more info...
void TreeNode::printSpecialInfo() {
    switch(this->nodeType){
        case NODE_CONST:
            switch (this->type->type)
            {
            case VALUE_INT:
                cout<<setw(16)<<" type: "<<this->type->getTypeInfo()<<setw(16)<<" value: "<<this->int_val;
                break;
            case VALUE_CHAR:
                cout<<setw(16)<<" type: "<<this->type->getTypeInfo()<<setw(16)<<" value: "<<this->ch_val;
                break;
            case VALUE_BOOL:
                cout<<setw(16)<<" type: "<<this->type->getTypeInfo()<<setw(16)<<" value: "<<this->b_val;
                break;
            case VALUE_STRING:
                cout<<setw(16)<<" type: "<<this->type->getTypeInfo()<<setw(16)<<" value: "<<this->str_val;
                break;
            default:
                break;
            }
            break;
        case NODE_VAR:
            cout<<setw(16)<<" varname: "<<this->var_name<<setw(16)<<"type: "<<this->type->getTypeInfo();
            break;
        case NODE_EXPR:
            cout<<setw(16)<<" operator: "<<opType2String(this->optype)<<setw(16)<<" type: "<<this->type->getTypeInfo();
            break;
        case NODE_STMT:
            cout<<setw(16)<<" stmt: "<<sType2String(this->stype);
            if(this->stype == STMT_ASSG){
                cout<<"   assg_type: "<<opType2String(this->optype);
            }
            break;
        case NODE_TYPE:
            cout<<setw(16)<<" type: "<<this->type->getTypeInfo();
            break;
        case NODE_FUNC:
            cout<<setw(16)<<" func_name: "<<this->var_name<<setw(16)<<" type: "<<this->type->getTypeInfo();
            break;
        case NODE_LVAL:
            cout<<setw(16)<<" type: "<<this->type->getTypeInfo();
            break;
        default:
            break;
    }
    // cout<<setw(16)<<this->expType;//for test
}

string TreeNode::sType2String(StmtType type) {
    switch (type)
    {
    case STMT_SKIP:
        return "skip";
    case STMT_DECL:
        return "decl";
    case STMT_ASSG:
        return "assgin";
    case STMT_EXPR:
        return "expression";
    case STMT_BLOK:
        return "block";
    case STMT_IF:
        return "if";
    case STMT_IFELSE:
        return "if-else";
    case STMT_WHILE:
        return "while";
    case STMT_BREAK:
        return "break";
    case STMT_CONTI:
        return "continue";
    case STMT_RETURN:
        return "return";
    case STMT_FOR:
        return "for";
    case STMT_FOR_DECL:
        return "decl";
    case STMT_IOFUNC:
        return "IO function";
    case STMT_DECL_CONST:
        return "decl_const_var";
    default:
        break;
    }
    return "?";
}


string TreeNode::nodeType2String (NodeType type){
    switch (type)
    {
    case NODE_CONST:
        return "const";
    case NODE_VAR:
        return "variable";
    case NODE_EXPR:
        return "expression";
    case NODE_TYPE:
        return "type";
    case NODE_STMT:
        return "statement";
    case NODE_PROG:
        return "program";
    case NODE_COMP:
        return "compUnit";
    case NODE_FUNC:
        return "function";
    case NODE_EMPTY:
        return "empty";
    case NODE_LVAL:
        return "lval";
    case NODE_INITVAL:
        return "initValue";
    case NODE_FUNCPARAMS:
        return "funcParams";
    case NODE_FUNCPARAM:
        return "funcParam";
    case NODE_VARDEF:
        return "varDef";
    case NODE_FUNCRPARAMS:
        return "funcRParams";
    default:
        break;
    }
    return "<>";
}

string TreeNode::opType2String (OperatorType type){
    switch (type)
    {
    case OP_OPT:
        return "Plus sign";
    case OP_NEG:
        return "minus sign";
    case OP_NOT:
        return "Negation";
    case OP_ADD:
        return "add";
    case OP_SUB:
        return "sub";
    case OP_MUL:
        return "mul";
    case OP_DIV:
        return "div";
    case OP_MOD:
        return "mould";
    case OP_OR:
        return "or";
    case OP_AND:
        return "and";
    case OP_LT:
        return "<";
    case OP_BT:
        return ">";
    case OP_LTEQ:
        return "<=";
    case OP_BTEQ:
        return ">=";
    case OP_EQ:
        return "==";
    case OP_NQ:
        return "!=";
    case OP_ASSG:
        return "=";
    case OP_ADD_ASSG:
        return "+=";
    case OP_SUB_ASSG:
        return "-=";
    case OP_INC:
        return "++";
    case OP_DEC:
        return "--";
    case OP_FUNC:
        return "call_function";
    default:
        break;
    }
    return "?";
}

void TreeNode::check(TreeNode* node){
    if(node != nullptr){
        if(node->child != nullptr)
            check(node->child);
        node->expType = type_check(node);
        if(node->sibling!=nullptr)
            check(node->sibling);
    }
}

ExpType TreeNode::type_check(TreeNode* node){//鲁棒性！！！
    // 根据节点的结点类型，执行不同的动作
    switch (node->nodeType)
    {
        case NODE_LVAL://先不考虑数组左值，默认左值是变量
            return node->child->expType;
        case NODE_INITVAL://先不考虑数组形式，默认右值就是一个常规表达式
            return node->child->expType;
        case NODE_CONST:
            return node->expType;
        case NODE_VAR:
            switch (node->type->type)
            {
            case VALUE_BOOL:
                return EXP_BOOL;
            case VALUE_INT:
                return EXP_INT;
            case VALUE_CHAR:
                return EXP_CHAR;
            case VALUE_STRING:
                return EXP_STRING;
            //扩展位置：
            
            default:
                return EXP_NOTYPE;
            }

        case NODE_EXPR:
        {
            // 首先判断表达式是不是常量表达式，只要孩子节点出现变量，就将父结点的isConst置为false
            TreeNode* trace = node->child;
            node->isConst = true;
            while(trace!=nullptr){
                if(!trace->isConst){
                    node->isConst = false;
                    break;
                }
                trace = trace->sibling;
            }
            // 根据不同的操作符，进行不同方式的类型检查
            OperatorType op = node->optype;
            if(op==OP_NEG){
                //单目运算符，作用对象可以是常量，因为不改变值
                //作用对象的类型可以是除了字符串类型的其他三种变量和数值常量
                //返回类型应该为整数

                if(node->child->expType==EXP_STRING){
                    cerr<< "Operands should not be string: line" << node->lineno<<" "<< opType2String(op) << endl;
                }
                else if(node->child->expType==EXP_NOTYPE){
                    cerr<< "undefine type at line:"<<node->lineno<<" "<< opType2String(op) << endl;
                }
                return EXP_INT;//经过负号操作的对象类型都会是整数
            }
            else if(op==OP_OPT){//正号不改变运算对象的类型
                if(node->child->expType==EXP_NOTYPE){
                    cerr<< "undefine type at line:"<<node->lineno<<" "<< opType2String(op) << endl;
                }
                return node->child->expType;
            }
            else if(op==OP_NOT){//取反,操作数可以是布尔，整数，字符和字符串
                if(node->child->expType==EXP_NOTYPE){
                    cerr<< "undefine type at line:"<<node->lineno<<" "<< opType2String(op) << endl;
                }
                else if(node->child->expType!=EXP_BOOL){
                    cerr<< "Operator wants bool but get other, and we turn it to bool at line:"<<node->lineno<<" "<< opType2String(op) << endl;
                }
                return EXP_BOOL;//返回是布尔类型
            }
            else if(op==OP_INC||op==OP_DEC){//自增一操作，不能操作常量，返回类型应该为整数，但是可以接收其他类型操作数
                if(node->child->expType==EXP_NOTYPE){
                    cerr<< "undefine type at line:"<<node->lineno<<" "<< opType2String(op) << endl;
                }
                else if(node->nodeType == NODE_CONST||node->child->isConst){
                    cerr<< "Operands of the INC or DEC cant be const! line:"<<node->lineno<<" "<< opType2String(op) << endl;
                }
                else if(node->child->expType!=EXP_INT){
                    cerr<< "Operator wants int but get other, and we turn it to int at line:"<<node->lineno<<" "<< opType2String(op) << endl;
                }
                return EXP_INT;
            }
            else if(op==OP_ADD||op==OP_SUB||op==OP_MUL||op==OP_DIV||op==OP_MOD){//广义加法，两个操作数应该都是整数，返回类型也是整数
            //类型可以转换的：char bool
                if(node->child->expType==EXP_NOTYPE||node->child->sibling->expType==EXP_NOTYPE){
                    cerr<< "undefine type at line:"<<node->lineno<<" "<< opType2String(op) << endl;
                }
                else if(node->child->expType==EXP_STRING||node->child->sibling->expType==EXP_STRING)
                {
                    cerr<< "Operands cant be string! line:"<<node->lineno<<" "<< opType2String(op) << endl;
                }
                else if(node->child->expType!=EXP_INT||node->child->sibling->expType!=EXP_INT){
                    cerr<<"Operator wants int but get other, and we turn it to int at line:"<<node->lineno<<" "<< opType2String(op) << endl;
                }
                return EXP_INT;
            }
            else if(op==OP_OR||op==OP_AND){//双目逻辑运算符，操作数可以是四种基本类型
                if(node->child->expType==EXP_NOTYPE||node->child->sibling->expType==EXP_NOTYPE){
                    cerr<< "undefine type at line:"<<node->lineno<<" "<< opType2String(op) << endl;
                }
                else if(node->child->expType!=EXP_BOOL||node->child->sibling->expType!=EXP_BOOL){
                    cerr<<"Operator wants bool but get other, and we turn it to bool at line:"<<node->lineno<<" "<< opType2String(op) << endl;
                }
                return EXP_BOOL;
            }
            else if(op==OP_LT||op==OP_BT||op==OP_LTEQ||op==OP_BTEQ||op==OP_EQ||op==OP_NQ){
                //关系运算符，返回类型为bool，操作数类型要匹配
                if(node->child->expType==EXP_NOTYPE||node->child->sibling->expType==EXP_NOTYPE){
                    cerr<< "undefine type at line:"<<node->lineno<<" "<< opType2String(op) << endl;
                }
                else if(node->child->expType!=node->child->sibling->expType){
                    cerr<< "Operands of relational operators not match at line:"<<node->lineno<<" "<< opType2String(op) << endl;
                }
                return EXP_BOOL;
            }
            else if(op==OP_ASSG||op==OP_ADD_ASSG||op==OP_SUB_ASSG){
                ExpType child1 = node->child->expType,child2 = node->child->sibling->expType;
                if(child1==EXP_NOTYPE||child2==EXP_NOTYPE){
                    cerr<< "undefine type at line:"<<node->lineno<<" "<< opType2String(op) << endl;
                }
                else if(node->child->isConst){
                    cerr<< "First operand cant be const variable! line:"<<node->lineno<<" "<< opType2String(op) << endl;
                }
                else if(child1!=child2){
                    if(child2==EXP_STRING){
                        cerr<< "Operands cant be string line: "<<node->lineno<<" "<< opType2String(op) << endl;
                    }
                    else{
                        cerr<< "type transform at line: "<<node->lineno<<" "<< opType2String(op) << endl;
                    }
                }     
                return child1;      
            }
            break;
        }
        case NODE_VARDEF:
        {
            if(node->child->sibling!=nullptr){//声明语句初始化了
                if(node->child->expType==EXP_NOTYPE||node->child->sibling->expType==EXP_NOTYPE){
                    cerr<< "undefine type at line: "<<node->lineno << endl;     
                }
                else if(node->child->isConst&&!node->child->sibling->isConst){
                    cerr<< "Variable values cannot be assigned to constants! line: "<<node->lineno << endl;  
                }
                else if(node->child->expType!=node->child->sibling->expType){
                    if((node->child->expType!=EXP_BOOL)&&(node->child->sibling->expType==EXP_STRING))
                        cerr<< "Declaration statement type match fault! line: "<<node->lineno << endl;
                    else{
                        cerr<< "Declaration statement type do not match but we fix it! line: "<<node->lineno << endl;
                    }  
                }
            }
            break;
        }
        case NODE_STMT:
        {
            switch (node->stype)
            {
                case STMT_ASSG:
                {
                    TreeNode* child1 = node->child,*child2 = node->child->sibling;
                    if(child1->expType==EXP_NOTYPE||child2->expType==EXP_NOTYPE){
                        cerr<< "undefine type at line: "<<node->lineno << endl;     
                    }
                    else if(child1->isConst){
                        cerr<< "Const var cant be redefined! line: "<<node->lineno << endl;  
                    }
                    else if(child1->expType!=child2->expType){
                        cerr<< "Declaration statement type match fault! line: "<<node->lineno << endl;  
                    }                   
                    break;
                }
                case STMT_IF:
                {
                    if(node->child->expType!=EXP_BOOL){
                        cerr<< "If statement don't get a bool cond, but we fix it. line: "<<node->lineno << endl;  
                        node->child->expType = EXP_BOOL;
                    }
                    break;
                }
                case STMT_IFELSE:
                {
                    if(node->child->expType!=EXP_BOOL){
                        cerr<< "If statement don't get a bool cond, but we fix it. line: "<<node->lineno << endl;  
                        node->child->expType = EXP_BOOL;
                    }
                    break;
                }   
                case STMT_WHILE:
                {
                    if(node->child->expType!=EXP_BOOL){
                        cerr<< "If statement don't get a bool cond, but we fix it. line: "<<node->lineno << endl;  
                        node->child->expType = EXP_BOOL;
                    }
                    break;
                }   
                case STMT_FOR:
                {
                    if(node->child->sibling->expType!=EXP_BOOL&&node->child->sibling->nodeType!=NODE_EMPTY){
                        cerr<< "For statement don't get a bool or null cond, but we fix it. line: "<<node->lineno << endl;  
                        node->child->sibling->expType = EXP_BOOL;
                    }
                    break;
                }
                case STMT_FOR_DECL:
                {
                    if(node->child->sibling->expType!=node->child->sibling->sibling->expType){
                        cerr<< "decl in for type match fault! line: "<<node->lineno << endl;  
                    }
                    break;
                }
                default:
                    break;
            }
            break;
        }
        default:
            return EXP_NOTYPE;
    }
    return EXP_NOTYPE;
}

string TreeNode::new_label(){
    char tmp[20];

	sprintf(tmp, "@%d", TreeNode::label_seq);
	TreeNode::label_seq++;
	return tmp;
}

void TreeNode::get_label(TreeNode* node){//递归的外层函数
    node->label.begin_label = "_start";
    recursive_get_label(node);
}

void TreeNode::recursive_get_label(TreeNode* node){
    switch (node->nodeType)
    {
        case NODE_STMT:
        {
            switch (node->stype)
            {
                case STMT_IF:
                {
                    TreeNode *cond = node->child, *code = node->child->sibling;
                    if(node->label.next_label == "")
                        node->label.next_label = new_label();
                    cond->label.true_label = code->label.begin_label = new_label();
                    cond->label.false_label = code->label.next_label = node->label.next_label;
                    if(node->sibling)
                        node->sibling->label.begin_label = node->label.next_label;
                    break;
                }
                case STMT_IFELSE:
                {
                    TreeNode *cond = node->child, *code1 = node->child->sibling, *code2 = node->child->sibling->sibling;
                    if(node->label.next_label == "")
                        node->label.next_label = new_label();
                    cond->label.true_label = code1->label.begin_label = new_label();
                    cond->label.false_label = code2->label.begin_label = new_label();
                    code1->label.next_label = code2->label.next_label = node->label.next_label;
                    if(node->sibling)
                        node->sibling->label.begin_label = node->label.next_label;
                    break;                    
                }
                case STMT_WHILE:
                {
                    TreeNode *cond = node->child, *code = node->child->sibling;
                    if(node->label.begin_label == "")
                        node->label.begin_label = new_label();
                    if(node->label.next_label == "")
                        node->label.next_label = new_label();
                    cond->label.true_label = code->label.begin_label = new_label();
                    cond->label.false_label = node->label.next_label;
                    code->label.next_label = node->label.begin_label;
                    if(node->sibling)
                        node->sibling->label.begin_label = node->label.next_label;
                    break;                      
                }
                case STMT_FOR:
                {
                    TreeNode *expr1 = node->child, *expr2 = node->child->sibling, *expr3 = node->child->sibling->sibling, *code = node->child->sibling->sibling->sibling;
                    if(node->label.begin_label == "")
                        node->label.begin_label = new_label();
                    if(node->label.next_label == "")
                        node->label.next_label = new_label();      
                    expr1->label.begin_label = node->label.begin_label;
                    expr1->label.next_label = expr3->label.next_label = new_label();
                    expr2->label.true_label = code->label.begin_label = new_label();
                    expr2->label.false_label = node->label.next_label;
                    // expr3->label.begin_label = code->label.next_label = new_label();
                    if(node->sibling)
                        node->sibling->label.begin_label = node->label.next_label;
                    break;                                          
                }
                
                default:
                    break;
            }

            break;
        }
        case NODE_EXPR://给表达式打标签就是为了给布尔表达式打标签
        //给布尔表达式打标签，就是为了让and和or连接的语句能遵循短路原则
        //实现对布尔表达式运算过程的控制
        {
            if(node->expType!=EXP_BOOL)
                break;
            switch(node->optype)
            {
                case OP_AND:
                {
                    TreeNode* child1 = node->child,*child2 = node->child->sibling;
                    child1->label.true_label = new_label();
                    child1->label.false_label= child2->label.false_label = node->label.false_label;
                    child2->label.true_label = node->label.true_label;
                    break;
                }
                case OP_OR:
                {
                    TreeNode* child1 = node->child,*child2 = node->child->sibling;
                    child1->label.false_label = new_label();
                    child1->label.true_label = child2->label.true_label = node->label.true_label;
                    child2->label.false_label = node->label.false_label;
                    break;
                }
                case OP_NOT:
                {
                    TreeNode* child = node->child;
                    child->label.true_label = node->label.false_label;
                    child->label.false_label = node->label.true_label;
                    break;
                }
                default:
                    break;
            }
            break;
        }
        
        default:
            break;
    }
    if(node->child)
        recursive_get_label(node->child);
    if(node->sibling)
        recursive_get_label(node->sibling);
}

void TreeNode::gen_code(TreeNode* node){
    gen_header();
    gen_decl(node);
}

void TreeNode::gen_header(){
    cout<<"\t.file\t"<< '"' <<filename<< '"' <<endl;
    cout<<"\t.text"<<endl;
}

void TreeNode::recursive_gen_code(TreeNode * node){
    return;
}

void TreeNode::gen_decl(TreeNode * node){//只关心全局变量和常量
    cout<<"\t.data"<<endl;//全局变量存在data段里
    gen_decl_var(node, false);//
    cout<<endl;
    cout<<"\t.rodata"<<endl;//全局常量存在rodata里
    gen_decl_var(node, true);
}

void TreeNode::gen_decl_var(TreeNode *node, bool isdeclConst)
{
    //由语法限制，从根节点出发，只能碰到函数声明结点和变量声明结点
    if(!isdeclConst){
        if(node->nodeType == NODE_FUNC)
        //函数之内的全是局部变量，这里不管，直接返回
            goto goSibling;
        if((node->nodeType == NODE_STMT)&&(node->stype == STMT_DECL_CONST))
            goto goSibling;//不管常量声明
    }
    else{
        if((node->nodeType == NODE_STMT)&&(node->stype == STMT_DECL))
            goto goSibling;//不管变量声明
        if(node->nodeType == NODE_CONST){
            if(node->expType == EXP_STRING){
                cout<<"STR"<<TreeNode::str_num++<<":"<<endl;
                cout<<"\t.string "<<'"'<<node->str_val<<'"'<<endl;
            if(node->sibling)
                gen_decl_var(node->sibling, isdeclConst);
            goto goSibling;
            }
        }
    }

    if(node->nodeType == NODE_VARDEF){
        TreeNode* child1 = node->child, *child2 = node->child->sibling;
        //声明全局变量
        string type1 = child1->type->getTypeInfo(), type2;
        cout<<"\t.globl\t"<<child1->var_name<<endl;
        //默认变量只能为int或char类型
        if(type1 == "int"){
            //int类型变量
            cout<<"\t.align 4"<<endl<<"\t.type\t"<<child1->var_name<<", @object"<<endl;
            cout<<"\t.size\t"<<child1->var_name<<", 4"<<endl;
            cout<<child1->var_name<<":"<<endl;
            cout<<"\t.long\t";
        }
        else if(type1 == "char"){
            cout<<"\t.type\t"<<child1->var_name<<", @object"<<endl;
            cout<<"\t.size\t"<<child1->var_name<<", 1"<<endl;
            cout<<child1->var_name<<":"<<endl;
            cout<<"\t.byte\t";
        }
        else{
            cout<<"var shouldn't be "<<type1<<" type! at line: "<<child1->lineno<<endl;
            exit(-1);
        }
        if(child2)//如果声明语句中有初始值,这个初始值一定是一个字面常量
        {
            assert(child2->nodeType == NODE_CONST);
            type2 = child2->type->getTypeInfo();
            //这里需要考虑一种情况，即用int给char赋值，由于int可能会超出char的范围
            //所以int给char赋值要取模
            if(type1=="char"){
                if(type2=="int"){
                    cout<<(child2->int_val%0x100)<<endl;
                }
                else if(type2=="char"){
                    cout<<int(child2->ch_val)<<endl;
                }
                else{
                    cout<<"initValue shouldn't be "<<type2<<" type! at line: "<<child2->lineno<<endl;
                    exit(-1);
                }
            }
            else if(type1=="int"){
                if(type2=="int"){
                    cout<<child2->int_val<<endl;
                }
                else if(type2=="char"){
                    cout<<int(child2->ch_val)<<endl;
                }
                else{
                    cout<<"initValue shouldn't be "<<type2<<" type! at line: "<<child2->lineno<<endl;
                    exit(-1);
                }
            }
            else{
                    cout<<"var shouldn't be "<<type1<<" type! at line: "<<child1->lineno<<endl;
                    exit(-1);               
            }
        }
        else{//没有初始值的话，所有变量的初始值设为0
            cout<<"0"<<endl;
        }

        goto goSibling;
    }
    if(node->child)
        gen_decl_var(node->child, isdeclConst);
goSibling:
    if(node->sibling)
        gen_decl_var(node->sibling, isdeclConst);
}