#include "tree.h"
long int current_id = 0;
TreeNode* TreeNode::nowFunc = nullptr;
int TreeNode::label_seq = 0;
bool is_use_stack = false;
map<string, int> stringTable;
TreeNode* TreeNode::mainNode = nullptr;
int TreeNode::tempNUm=0;
extern symTable symtable;
int mainStackSize;
bool haveGlobalVar = false;
bool haveGlobalConst = false;
bool haveString = false;

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
    this->isUseStack = false;
    this->isGlobal = false;
    this->exprResult = false;
    this->isMyLabelWasCout = false;
    this->isassg = false;
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
            cout<<setw(16)<<"varname: "<<this->var_name<<setw(16)<<"type: "<<this->type->getTypeInfo()<<" id: "<<this->tableid;
            break;
        case NODE_EXPR:
            cout<<setw(16)<<"operator: "<<opType2String(this->optype)<<setw(16)<<"type: "<<this->type->getTypeInfo();
            break;
        case NODE_STMT:
            cout<<setw(16)<<"stmt: "<<sType2String(this->stype);
            // if(this->stype == STMT_ASSG){
            //     cout<<"   assg_type: "<<opType2String(this->optype);
            // }
            if(this->stype == STMT_IOFUNC){
                cout<<"   name: "<<this->var_name<<"  paramNum: "<<this->paraNum;
            }
            break;
        case NODE_TYPE:
            cout<<setw(16)<<" type: "<<this->type->getTypeInfo();
            break;
        case NODE_FUNC:
        {
            cout<<setw(16)<<"func_name: "<<this->var_name<<setw(16)<<"return_type: "<<this->type->getTypeInfo();
            TreeNode* temp = this->child->sibling->sibling;
            cout<<"  paraNum: "<<temp->paraNum;
            // cout<<setw(16)<<"use_stack: ";
            // if(this->isUseStack)
            //     cout<<"True";
            // else
            //     cout<<"False";
            break;
        }
        case NODE_LVAL:
            cout<<setw(16)<<"type: "<<this->type->getTypeInfo();
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
    // case STMT_ASSG:
    //     return "assgin";
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
            //类型可以转换的：char 
                TreeNode *child1=node->child, *child2=node->child->sibling;
                if(node->child->expType==EXP_NOTYPE||node->child->sibling->expType==EXP_NOTYPE){
                    cerr<< "undefine type at line:"<<node->lineno<<" "<< opType2String(op) << endl;
                }
                else if(child1->expType!=child2->expType){
                    if(child1->expType==EXP_STRING||child2->expType==EXP_STRING||child1->expType==EXP_CHAR||child2->expType==EXP_CHAR)
                    {
                        cerr<<"Operands type match fault! at line: "<<node->lineno<<" "<< opType2String(op) << endl;
                    }
                    else{
                        cerr<<"Operator wants int but get other, and we turn it to int at line:"<<node->lineno<<" "<< opType2String(op) << endl;
                    }
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
                    if(child2==EXP_STRING||child2==EXP_BOOL){
                        cerr<< "Operands type match fault！at line: "<<node->lineno<<" "<< opType2String(op) << endl;
                        exit(-1);
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
                case STMT_IF:
                {
                    if(node->child->expType!=EXP_BOOL){
                        cerr<< "If statement don't get a bool cond, but we fix it. line: "<<node->lineno << endl;  
                    }
                    break;
                }
                case STMT_IFELSE:
                {
                    if(node->child->expType!=EXP_BOOL){
                        cerr<< "If statement don't get a bool cond, but we fix it. line: "<<node->lineno << endl;  
                    }
                    break;
                }   
                case STMT_WHILE:
                {
                    if(node->child->expType!=EXP_BOOL){
                        cerr<< "If statement don't get a bool cond, but we fix it. line: "<<node->lineno << endl;  
                    }
                    break;
                }   
                case STMT_FOR:
                {
                    if(node->child->sibling->expType!=EXP_BOOL&&node->child->sibling->nodeType!=NODE_EMPTY){
                        cerr<< "For statement don't get a bool or null cond, but we fix it. line: "<<node->lineno << endl;  
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
                // case STMT_IOFUNC:
                // {
                //     TreeNode* para = node->child->sibling;
                //     if(para->nodeType == NODE_EMPTY)
                //     {
                //         cerr<<"para of IOfunc cant be empty! at line: "<<node->lineno<<endl;
                //         exit(-1);
                //     }
                // }
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

	sprintf(tmp, ".L%d", TreeNode::label_seq);
	TreeNode::label_seq++;
	return tmp;
}

void TreeNode::get_label(TreeNode* node){//递归的外层函数
    node->label.begin_label = "main";
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
                    if(node->label.true_label=="")
                        node->label.true_label = new_label();
                    if(node->label.false_label=="")
                        node->label.false_label = new_label();
                    
                    child1->label.true_label = new_label();
                    
                    child1->label.false_label= child2->label.false_label = node->label.false_label;
                    child2->label.true_label = node->label.true_label;
                    break;
                }
                case OP_OR:
                {
                    if(node->label.true_label=="")
                        node->label.true_label = new_label();
                    if(node->label.false_label=="")
                        node->label.false_label = new_label();
                    TreeNode* child1 = node->child,*child2 = node->child->sibling;

                    child1->label.false_label = new_label();

                    child1->label.true_label = child2->label.true_label = node->label.true_label;
                    child2->label.false_label = node->label.false_label;
                    break;
                }
                case OP_NOT:
                {
                    if(node->label.true_label=="")
                        node->label.true_label = new_label();
                    if(node->label.false_label=="")
                        node->label.false_label = new_label();
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
    assert(node!=nullptr);
    gen_header();
    gen_decl(node);
    //由于还没有实现函数，所以手动输出main函数的声明
    string func_name = "main";
    //默认nowFunc指针指向main函数结点
    cout<<"\t.text"<<endl;
	cout<<"\t.globl "<<func_name<<endl;
	cout<<"\t.type  "<<func_name<<", @function"<<endl;
    cout<<func_name<<":"<<endl;
    if(is_use_stack)//这个全局布尔变量说明main函数有没有使用栈，自定义函数可以使用结点自带的isUseStack代替
    {
        cout<<"\tleal\t4(%esp), %ecx"<<endl;
        cout<<"\tandl\t$-16, %esp"<<endl;
        cout<<"\tpushl\t-4(%ecx)"<<endl;
        cout<<"\tpushl\t%ebp"<<endl;
        cout<<"\tmovl\t%esp, %ebp"<<endl;
        cout<<"\tpushl\t%ecx"<<endl;
        cout<<"\tsubl\t$4, %esp"<<endl;

    }
    else{
        cout<<"\tpushl\t%ebp"<<endl;
        cout<<"\tmovl\t%esp, %ebp"<<endl;
    }
    if(TreeNode::tempNUm!=0)
    {
        cout<<"\tsubl\t$";
        mainStackSize = (TreeNode::tempNUm/4+1)*16;
        cout<<mainStackSize<<", %esp"<<endl;
    }
    
    recursive_gen_code(mainNode);
    //如果函数实现了，上面的几行可以删除

    cout<<"\t"<<R"(.section  .note.GNU-stack,"",@progbits)";
}

void TreeNode::gen_header(){
    cout<<"\t.file\t"<< '"' <<filename<< '"' <<endl;

}

void TreeNode::gen_decl(TreeNode * node){//只关心全局变量和常量
    if(haveGlobalVar)
    {
        cout<<"\t.data"<<endl;//全局变量存在data段里
        gen_decl_var(node, false);//
        cout<<endl;
    }
    if(haveGlobalConst)
    {
        cout<<"\t.section\t.rodata"<<endl;//全局常量存在rodata里
        gen_decl_var(node, true);
    }
    if(haveString&&!haveGlobalConst)
    {    //把string存在rodata段里
        cout<<"\t.section\t.rodata"<<endl;
        for(auto iter=stringTable.begin();iter!=stringTable.end();iter++){
        cout<<"STR"<<iter->second<<":"<<endl;
        cout<<"\t.string "<<'"'<<iter->first<<'"'<<endl;
        }
    }
    else if(haveString)
    {    //把string存在rodata段里
        for(auto iter=stringTable.begin();iter!=stringTable.end();iter++){
        cout<<"STR"<<iter->second<<":"<<endl;
        cout<<"\t.string "<<'"'<<iter->first<<'"'<<endl;
        }
    }

    
}

void TreeNode::gen_decl_var(TreeNode *node, bool isdeclConst)
{
    //由语法限制，从根节点出发，只能碰到函数声明结点和变量声明结点
    if(!isdeclConst){
        if(node->nodeType == NODE_FUNC)//函数之内的全是局部变量，这里不管，直接返回
            goto goSibling;
        if((node->nodeType == NODE_STMT)&&(node->stype == STMT_DECL_CONST))
            goto goSibling;//不管常量声明
    }
    else{
        if((node->nodeType == NODE_STMT)&&(node->stype == STMT_DECL))
            goto goSibling;//不管变量声明
    }

    if(node->nodeType == NODE_VARDEF){
        TreeNode* child1 = node->child, *child2 = node->child->sibling;
        //声明全局变量
        symtable.setDef(child1->tableid);
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

void TreeNode::recursive_gen_code(TreeNode * node){
    if(node->nodeType == NODE_STMT)
    {
        stmt_gen_code(node);
        if(node->sibling)
            recursive_gen_code(node->sibling);
    }
    else if(node->nodeType == NODE_EXPR)
    {
        expr_gen_code(node);
        if(node->sibling)
            recursive_gen_code(node->sibling);
    }
    else if(node->nodeType == NODE_VARDEF)
    {
        if(node->optype!=OP_NULL)
        {
            expr_gen_code(node);
        }
        if(node->sibling)
            recursive_gen_code(node->sibling);
    }
    else{
        if(node->child)
            recursive_gen_code(node->child);
        if(node->sibling)
            recursive_gen_code(node->sibling);
    }
}

void TreeNode::stmt_gen_code(TreeNode * node){  
    //每个语句在开始时，输出它的begin标签
    //那么每个语句就不需要输出自己的end标签
    // if(node->label.begin_label!="")
    //     cout<<node->label.begin_label<<':'<<endl;

    switch(node->stype){
        case STMT_EXPR:
        {
            TreeNode * child = node->child;
            expr_gen_code(child);

            if(child->optype==OP_OR||child->optype==OP_AND||child->optype==OP_NOT)
            {
                cout<<child->label.false_label<<':'<<endl;
                cout<<child->label.true_label<<':'<<endl;
            }
            return;
        }
        case STMT_IOFUNC://实参一定是表达式，不可能为空
        {   //参数可能只有一个字符串
            
            TreeNode* str = node->child;
            TreeNode* paras = node->child->sibling;
            int paranum = node->paraNum+1;//加上字符串
            int space = ((paranum/4)+1)*16;
            int empty = space - paranum*4;
            cout<<"\tsubl\t$"<<empty<<", %esp"<<endl;
            TreeNode* temp;
            for(int i=paranum-1;i>0;i--){
                temp =  paras->child;
                for(int j =1;j<i;j++)
                {
                    temp = temp->sibling;
                }
                if(node->var_name == "printf")
                {
                    expr_gen_code(temp);
                    cout<<"\tpushl\t%eax"<<endl;
                }
                else
                {
                    temp->isassg = true;
                    symtable.setDef(temp->tableid);
                    if(temp->isGlobal)
                        cout<<"\tpushl\t$"<<gen_varname(temp)<<endl;
                    else
                    {
                        cout<<"\tleal\t"<<gen_varname(temp)<<", %ebx"<<endl;
                        cout<<"\tpushl\t%ebx"<<endl;
                    }
                    
                }
            }
            cout<<"\tpushl\t$"<<"STR"<<str->str_id<<endl;
            cout<<"\tcall\t"<<node->var_name<<endl;
            cout<<"\taddl\t$"<<space<<", %esp"<<endl;
            return;
        }
        case STMT_RETURN:
        {
            TreeNode* child1 = node->child;
            expr_gen_code(child1);
            if(nowFunc->isUseStack)
            {
                cout<<"\tmovl\t-4(%ebp), %ecx"<<endl;
                cout<<"\tleave"<<endl;
                cout<<"\tleal\t-4(%ecx), %esp"<<endl;
                cout<<"\tret"<<endl;
            }
            else{
                cout<<"\tpopl\t%ebp"<<endl;
                cout<<"\tret"<<endl;
            }
            return;
        }
        case STMT_IF:
        {
            TreeNode *cond = node->child, *code = node->child->sibling;
            OperatorType op = cond->optype;
            expr_gen_code(cond);
            if(op==OP_EQ||op==OP_NQ||op==OP_LT||op==OP_BT||op==OP_LTEQ||op==OP_BTEQ)
            {
                howRelOpJmp(op,false,cond->label.false_label);
            }
            else if(cond->expType!=EXP_BOOL)
            {
                cout<<"\tcmpl\t$0, %eax"<<endl;//eax-0
                cout<<"\tje\t"<<cond->label.false_label<<endl;//相等跳转
            }
            cout<<cond->label.true_label<<':'<<endl;
            stmt_gen_code(code);
            cout<<node->label.next_label<<':'<<endl;
            if(node->sibling)
                node->sibling->isMyLabelWasCout = true;
            return;
        }
        case STMT_IFELSE:
        {
            TreeNode *cond = node->child, *code1 = node->child->sibling, *code2 = node->child->sibling->sibling;
            OperatorType op = cond->optype;
            expr_gen_code(cond);
            if(op==OP_EQ||op==OP_NQ||op==OP_LT||op==OP_BT||op==OP_LTEQ||op==OP_BTEQ)
            {
                howRelOpJmp(op,false,cond->label.false_label);
            }
            else if(cond->expType!=EXP_BOOL)
            {
                cout<<"\tcmpl\t$0, %eax"<<endl;//eax-0
                cout<<"\tje\t"<<cond->label.false_label<<endl;//相等跳转
            }
            cout<<cond->label.true_label<<':'<<endl;
            stmt_gen_code(code1);
            cout<<"\tjmp\t"<<node->label.next_label<<endl;
            cout<<cond->label.false_label<<':'<<endl;
            stmt_gen_code(code2);
            cout<<node->label.next_label<<':'<<endl;
            if(node->sibling)
                node->sibling->isMyLabelWasCout = true;
            return;
        }
        case STMT_WHILE:
        {
            TreeNode *cond = node->child, *code = node->child->sibling;
            OperatorType op = cond->optype;
            if(!node->isMyLabelWasCout)
                cout<<node->label.begin_label<<':'<<endl;
            expr_gen_code(cond);
            if(op==OP_EQ||op==OP_NQ||op==OP_LT||op==OP_BT||op==OP_LTEQ||op==OP_BTEQ)
            {
                howRelOpJmp(op,false,cond->label.false_label);
            }
            else if(cond->expType!=EXP_BOOL)
            {
                cout<<"\tcmpl\t$0, %eax"<<endl;//eax-0
                cout<<"\tje\t"<<cond->label.false_label<<endl;//相等跳转
            }
            cout<<cond->label.true_label<<':'<<endl;
            stmt_gen_code(code);
            cout<<"\tjmp\t"<<node->label.begin_label<<endl;
            cout<<node->label.next_label<<':'<<endl;
            if(node->sibling)
                node->sibling->isMyLabelWasCout = true;
            return;
        }
        case STMT_FOR_DECL:
        {
            TreeNode *child1 = node->child->sibling, *child2=node->child->sibling->sibling;
            expr_gen_code(child2);
            //结果保存在寄存器里
            cout<<"\tmovl\t%eax, ";
            cout<<gen_varname(child1)<<endl;
            symtable.setDef(child1->tableid);
            return;
        }
        case STMT_FOR:
        {
            TreeNode *exp1, *exp2, *exp3, *code;
            
            exp1=node->child;
            exp2=exp1->sibling;
            exp3=exp2->sibling;
            code=exp3->sibling;
            //必须实现局部变量的分配了
            if(exp1->nodeType != NODE_EMPTY)
            {
                if(exp1->stype == STMT_FOR_DECL)
                    stmt_gen_code(exp1);
                else
                {
                    expr_gen_code(exp1);
                }
            }
            cout<<exp1->label.next_label<<':'<<endl;
            if(exp2->nodeType != NODE_EMPTY)
            {
                OperatorType op = exp2->optype;
                expr_gen_code(exp2);
                if(op==OP_EQ||op==OP_NQ||op==OP_LT||op==OP_BT||op==OP_LTEQ||op==OP_BTEQ)
                {
                    howRelOpJmp(op,false,node->label.next_label);
                }
                else if(exp2->expType!=EXP_BOOL)
                {
                    cout<<"\tcmpl\t$0, %eax"<<endl;//eax-0
                    cout<<"\tje\t"<<node->label.next_label<<endl;//相等跳转
                }
            }
            
            stmt_gen_code(code);
            if(exp3->nodeType!=NODE_EMPTY)
                expr_gen_code(exp3);
            cout<<"\tjmp\t"<<exp1->label.next_label<<endl;
            cout<<node->label.next_label<<':'<<endl;
            if(node->sibling)
                node->sibling->isMyLabelWasCout = true;
            return;
        }
        case STMT_DECL:
        {
            recursive_gen_code(node->child->sibling);
            return;
        }
        case STMT_DECL_CONST:
        {
            recursive_gen_code(node->child->sibling);
            return;
        }
        default:
        {
            if(node->child)
                recursive_gen_code(node->child);
            // if(node->sibling)
            //     recursive_gen_code(node->sibling);
            return;
        }    
    }
}
void TreeNode::expr_gen_code(TreeNode * node){
    OperatorType op = node->optype;
    if(op==OP_ADD||op==OP_SUB||op==OP_MUL||op==OP_DIV||op==OP_MOD||op==OP_EQ||op==OP_NQ||op==OP_LT||op==OP_BT||op==OP_LTEQ||op==OP_BTEQ){
        TreeNode *child1 = node->child, *child2 = node->child->sibling;
        //任何情况下，一定要保证左孩子结点的结果保存在eax，而右孩子的结点结果保存在ecx
        if(child1->optype != OP_NULL)
            expr_gen_code(child1);
        else
        {
            if(child1->nodeType == NODE_CONST)
                const_gen_code(child1, "eax");
            else if(child1->nodeType == NODE_VAR)
                var_gen_code(child1,"eax");
            else{
                cerr<<"Operands type wrong! at line: "<<child1->lineno<<endl;
                exit(-1);
            }
        }
        
        if(child2->optype != OP_NULL)
        {
            cout<<"\tpushl\t%eax"<<endl;
            expr_gen_code(child2);
            cout<<"\tmovl\t%eax, %ecx"<<endl;
            cout<<"\tpopl\t%eax"<<endl;
        }
        else{//右子树为叶节点
            if(child2->nodeType == NODE_CONST)
                const_gen_code(child2, "ecx");
            else if(child2->nodeType == NODE_VAR)
                var_gen_code(child2,"ecx");
            else{
                cerr<<"Operands type wrong! at line: "<<child2->lineno<<endl;
                exit(-1);
            }
        }
        inst2string(op);//根据不同的操作符，输出不同的汇编指令
        return;
    }
    else if(op==OP_OPT||op==OP_NEG){
        TreeNode* child = node->child;
        if(child->optype != OP_NULL)
            expr_gen_code(child);
        else{
            if(child->nodeType == NODE_CONST)
                const_gen_code(child, "eax");
            else if(child->nodeType == NODE_VAR)
                var_gen_code(child,"eax");
            else{
                cerr<<"Operands type wrong! at line: "<<child->lineno<<endl;
                exit(-1);
            }
        }
        inst2string(op);
        return;
    }
    else if(op==OP_OR||op==OP_AND||op==OP_NOT){
        TreeNode* child1 = node->child, *child2;
        if(child1->optype != OP_NULL)
            expr_gen_code(child1);
        else{
            if(child1->nodeType == NODE_CONST)
                const_gen_code(child1, "eax");
            else if(child1->nodeType == NODE_VAR)
                var_gen_code(child1,"eax");
            else{
                cerr<<"Operands type wrong! at line: "<<child1->lineno<<endl;
                exit(-1);
            }
        }

        if(op==OP_OR||op==OP_NOT){
            howRelOpJmp(child1->optype,true,child1->label.true_label);
            if(op==OP_NOT){

                return;
            }
            else{//op==OP_OR
            if(child1->expType==EXP_BOOL)
                cout<<child1->label.false_label<<':'<<endl;
            }
        }
        else /*if(op==OP_AND)*/
        {
            howRelOpJmp(child1->optype,false,child1->label.false_label);
            if(child1->expType==EXP_BOOL)
                cout<<child1->label.true_label<<':'<<endl;
        }

        child2 = node->child->sibling;
        if(child2->optype != OP_NULL)
            expr_gen_code(child2);
        else{
            if(child2->nodeType == NODE_CONST)
                const_gen_code(child2, "eax");
            else if(child2->nodeType == NODE_VAR)
            {
                var_gen_code(child2,"eax");
            }
                
            else{
                cerr<<"Operands type wrong! at line: "<<child2->lineno<<endl;
                exit(-1);
            }
        }
        howRelOpJmp(child2->optype,false,child2->label.false_label);

    }
    else if(op==OP_ASSG||op==OP_ADD_ASSG||op==OP_SUB_ASSG)
    {
        TreeNode* child1=node->child,*child2=node->child->sibling;
        //child1一定是一个变量，child2一定是一个表达式
        symtable.setDef(child1->tableid);
        var_gen_code(child1,"eax");
        if(child2->optype != OP_NULL)
        {
            cout<<"\tpushl\t%eax"<<endl;
            expr_gen_code(child2);
            cout<<"\tmovl\t%eax, %ecx"<<endl;
            cout<<"\tpopl\t%eax"<<endl;
        }
        else{//右子树为叶节点
            if(child2->nodeType == NODE_CONST)
                const_gen_code(child2, "ecx");
            else if(child2->nodeType == NODE_VAR)
                var_gen_code(child2,"ecx");
            else{
                cerr<<"Operands type wrong! at line: "<<child2->lineno<<endl;
                exit(-1);
            }
        }
        if(op==OP_ASSG)
        {
            if(child1->type->getTypeInfo()=="char")
            {
                // cout<<"\tmovb\t%ecx, %cl"<<endl;
                cout<<"\tmovb\t%cl, "<<gen_varname(child1)<<endl;
                cout<<"\tmovsbl\t%cl, %eax"<<endl;
            }
            else
            {
                cout<<"\tmovl\t%ecx, "<<gen_varname(child1)<<endl;
                cout<<"\tmovl\t%ecx, %eax"<<endl;
            }
            
        }
        else if(op==OP_ADD_ASSG)
        {
            if(child1->type->getTypeInfo()=="char")
            {
                cout<<"\taddl\t%ecx, %eax"<<endl;
                cout<<"\tmovb\t%al, "<<gen_varname(child1)<<endl;
            }
            else
            {
                cout<<"\taddl\t%ecx, %eax"<<endl;
                cout<<"\tmovl\t%eax, "<<gen_varname(child1)<<endl;
            }
            
        }
        else
        {
            if(child1->type->getTypeInfo()=="char")
            {
                cout<<"\tsubl\t%ecx, %eax"<<endl;
                cout<<"\tmovb\t%al, "<<gen_varname(child1)<<endl;
            }
            else
            {
                cout<<"\tsubl\t%ecx, %eax"<<endl;
                cout<<"\tmovl\t%eax, "<<gen_varname(child1)<<endl;
            }
            
        }
        return;
    }
    else if(op==OP_NULL){
        if(node->nodeType == NODE_CONST)
            const_gen_code(node, "eax");
        else if(node->nodeType == NODE_VAR)
        {
            var_gen_code(node,"eax");

        }
        else{
            cerr<<"Operands type wrong! at line: "<<node->lineno<<endl;
            exit(-1);
        }
    }
    else{
        // if(node->child)
        //     expr_gen_code(node->child);
        // if(node->sibling)
        //     expr_gen_code(node->sibling); 
        cerr<<"expr optype wrong at line: "<<node->lineno<<endl;
        exit(-1);
    }

}

void TreeNode::var_gen_code(TreeNode * node, string reg){
    if(!symtable.isDefed(node->tableid))
    {
        cout<<node->var_name<<" 没有初始值！"<<endl;
        exit(-1);
    }
    if(node->type->getTypeInfo()=="char")
    {
        cout<<"\tmovb\t"<<gen_varname(node)<<", %"<<smallReg(reg)<<endl;
        cout<<"\tmovsbl\t%"<<smallReg(reg)<<", %"<<reg<<endl;
    }
    else
        cout<<"\tmovl\t"<<gen_varname(node)<<", %"<<reg<<endl;
    return;
}

string TreeNode::smallReg(string reg){
    if(reg=="eax")
        return "al";
    else if(reg=="ebx")
        return "bl";
    else if(reg=="edx")
        return "dl";
    else if(reg=="ecx")
        return "cl";
    return "al";
}

string TreeNode::gen_varname(TreeNode * node)
{
    if(node->isGlobal)
    {
        return node->var_name;
    }
    else
    {
        //局部变量的处理
        int id = symtable.getScopeID(node->tableid);
        int offset = 4*id;
        string result;
        if(nowFunc->isUseStack)
            result ="-"+to_string(offset+8)+"(%ebp)";
        else 
            result = "-"+to_string(offset)+"(%ebp)";
        return result;
    }
    
}

void TreeNode::const_gen_code(TreeNode * node, string reg){
    switch(node->expType){
        case EXP_INT:
        {
            cout<<"\tmovl\t$"<<node->int_val<<", %"<<reg<<endl;
            break;
        }
        case EXP_CHAR:
        {
            cout<<"\tmovl\t$"<<int(node->ch_val)<<", %"<<reg<<endl;
            break;
        }
        case EXP_STRING:
        {
            cout<<"\tmovl\t$"<<"STR"<<node->str_id<<", %"<<reg<<endl;
            break;
        }
        default:
        {
            cerr<<"Operands type wrong! at line: "<<node->lineno<<endl;
            exit(-1);
        }
    }
}

void TreeNode::inst2string(OperatorType op){
    //根据不同的操作符，输出不同的汇编指令
    switch(op){
        case OP_ADD:
        {
            cout<<"\taddl\t%ecx, %eax"<<endl;
            break;
        }
        case OP_SUB:
        {
            cout<<"\tsubl\t%ecx, %eax"<<endl;
            break;
        }
        case OP_MUL:
        {
            cout<<"\timull\t%ecx, %eax"<<endl;
            break;
        }
        case OP_DIV:
        {
            cout<<"\tcltd"<<endl;
            cout<<"\tidivl\t%ecx"<<endl;
            break;
        }
        case OP_MOD:
        {
            cout<<"\tcltd"<<endl;
            cout<<"\tidivl\t%ecx"<<endl;
            cout<<"\tmovl\t%edx, %eax"<<endl;
            break;
        }
        case OP_NEG:
        {
            cout<<"\tnegl\t%eax"<<endl;
            break;
        }
        default:
        {
            if(op==OP_LT||op==OP_BT||op==OP_LTEQ||op==OP_BTEQ||op==OP_EQ||op==OP_NQ)
                cout<<"\tcmpl\t%ecx, %eax"<<endl;//eax-ecx
            break;
        }
    }
}

void TreeNode::howRelOpJmp(OperatorType op, bool true2jmp, string label)
{
    if(!true2jmp)//条件为假时跳转
    {
        switch(op)
        {
            case OP_LT:
            {
                cout<<"\tjge\t"<<label<<endl;
                break;
            }
            case OP_BT:
            {
                cout<<"\tjle\t"<<label<<endl;
                break;
            }
            case OP_LTEQ:
            {
                cout<<"\tjg\t"<<label<<endl;
                break;
            }
            case OP_BTEQ:
            {
                cout<<"\tjl\t"<<label<<endl;
                break;
            }
            case OP_EQ:
            {
                cout<<"\tjne\t"<<label<<endl;
                break;
            }
            case OP_NQ:
            {
                cout<<"\tje\t"<<label<<endl;
                break;
            }
            case OP_AND:
            {
                break;
            }
            case OP_OR:
            {
                break;
            }
            case OP_NOT:
            {
                break;
            }
            default:{
                cout<<"\tcmpl\t$0, %eax"<<endl;//eax-0
                cout<<"\tje\t"<<label<<endl;//相等跳转
                break;
            }
        }
    }
    else//条件为真时跳转
    {
        switch(op){
            case OP_LT:
            {
                cout<<"\tjl\t"<<label<<endl;
                break;
            }
            case OP_BT:
            {
                cout<<"\tjg\t"<<label<<endl;
                break;
            }
            case OP_LTEQ:
            {
                cout<<"\tjle\t"<<label<<endl;
                break;  
            }
            case OP_BTEQ:
            {
                cout<<"\tjge\t"<<label<<endl;
                break;
            }
            case OP_EQ:
            {
                cout<<"\tje\t"<<label<<endl;
                break;
            }
            case OP_NQ:
            {
                cout<<"\tjne\t"<<label<<endl;
                break;
            }
            case OP_AND:
            {
                break;
            }
            case OP_OR:
            {
                break;
            }
            case OP_NOT:
            {
                break;
            }
            default:
            {
                cout<<"\tcmpl\t$0, %eax"<<endl;//eax-0
                cout<<"\tjne\t"<<label<<endl;//不相等跳转
                break;
            }
        }
    }
    
}