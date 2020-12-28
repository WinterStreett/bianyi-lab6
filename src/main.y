%{
    #include "common.h"
    #define YYSTYPE TreeNode *  
    TreeNode* root;
    extern int lineno;
    extern bool is_use_stack;
    int yylex();
    int yyerror( char const * );
%}
%token T_CHAR T_INT T_STRING T_BOOL T_VOID

%token IF ELSE WHILE BREAK CONTINUE RETURN FOR CONST

%token SCANF PRINTF

%token SEMICOLON LBRACKET RBRACKET LBRACE RBRACE COMMA LSB RSB

%token IDENTIFIER INTEGER CHAR BOOL STRING

%left ADD SUB MUL DIV MOD LOP_EQ LOP_NQ OR AND LT BT LTEQ BTEQ ADDR

%left INC DEC 

%right NOT LOP_ASSIGN ADD_ASSIGN SUB_ASSIGN
%%

program
: compUnit {root = new TreeNode(0, NODE_PROG); root->addChild($1);}
;

compUnit
: funcDef {$$ = new TreeNode($1->lineno, NODE_COMP);$$->addChild($1);}
| decl SEMICOLON {$$ = new TreeNode($1->lineno, NODE_COMP);$$->addChild($1);}
| compUnit funcDef {
    TreeNode* node = new TreeNode($2->lineno, NODE_COMP);
    node->addChild($2);
    $$ = $1;
    $$->addSibling(node);
}
| compUnit decl SEMICOLON {
    TreeNode* node = new TreeNode($2->lineno, NODE_COMP);
    node->addChild($2);
    $$ = $1;
    $$->addSibling(node);
}
;

funcDef
: T IDENTIFIER LBRACKET funcParams RBRACKET block{
    $$ = new TreeNode($1->lineno, NODE_FUNC);
    $$->var_name = $2->var_name;
    $$->type = $1->type;
    $2->type = $1->type;
    $$->addChild($1);
    $$->addChild($2);
    $$->addChild($4);
    $$->addChild($6);
}
| T IDENTIFIER LBRACKET funcParams RBRACKET SEMICOLON{
    $$ = new TreeNode($1->lineno, NODE_FUNC);
    $$->var_name = $2->var_name;
    $2->type = $1->type;
    $$->type = $1->type;
    $$->addChild($1);
    $$->addChild($2);
    $$->addChild($4);
}
;

funcParams
: funcParam {
    $$ = new TreeNode($1->lineno, NODE_FUNCPARAMS);
    $$->addChild($1);
}
| funcParams COMMA funcParam {
    $$=$1;
    $$->addChild($3);
}
| {$$ = new TreeNode(lineno, NODE_EMPTY);}
;

funcParam
: T IDENTIFIER {
    $$ = new TreeNode($1->lineno, NODE_FUNCPARAM);
    $$->addChild($1);
    $$->addChild($2);
    $2->isdecl=true;
}
| T IDENTIFIER LSB RSB {
    $$ = new TreeNode($1->lineno, NODE_FUNCPARAM);
    $$->addChild($1);
    $$->addChild($2);  
    TreeNode* node = new TreeNode($1->lineno, NODE_EMPTY);
    $$->addChild(node);
    $2->isdecl=true;
}
| T IDENTIFIER LSB expr RSB {
    $$ = new TreeNode($1->lineno, NODE_FUNCPARAM);
    $$->addChild($1);
    $$->addChild($2);  
    $$->addChild($4);
    $2->isdecl = true;  
}
| funcParam LSB expr RSB{
    $$ = $1;
    $$->addChild($3);
}
;

statements
:  statement {$$=$1;}
|  statements statement {$$=$1; $$->addSibling($2);}
;

statement
: SEMICOLON  {$$ = new TreeNode(lineno, NODE_STMT); $$->stype = STMT_SKIP;}
| declaration SEMICOLON {$$ = $1;}
| constDeclaration SEMICOLON {$$ = $1;}
| LVal LOP_ASSIGN expr SEMICOLON {
    TreeNode* node = new TreeNode($1->lineno, NODE_STMT);
    node->stype = STMT_ASSG;
    node->optype = OP_ASSG;
    node->addChild($1);
    node->addChild($3);
    $$ = node;
}
| LVal ADD_ASSIGN expr SEMICOLON {
    TreeNode* node = new TreeNode($1->lineno, NODE_STMT);
    node->stype = STMT_ASSG;
    node->optype = OP_ADD_ASSG;
    node->addChild($1);
    node->addChild($3);
    $$ = node;
}
| LVal SUB_ASSIGN expr SEMICOLON {
    TreeNode* node = new TreeNode($1->lineno, NODE_STMT);
    node->stype = STMT_ASSG;
    node->optype = OP_SUB_ASSG;
    node->addChild($1);
    node->addChild($3);
    $$ = node;
}
| expr SEMICOLON {
    $$ = new TreeNode($1->lineno, NODE_STMT); 
    $$->stype = STMT_EXPR;
    $$->addChild($1);
}
| block {$$ = $1;}
| IF LBRACKET lOrExp RBRACKET statement {
    $$ = new TreeNode($3->lineno, NODE_STMT);
    $$->stype = STMT_IF;
    $$->addChild($3);
    $$->addChild($5);
}
| IF LBRACKET lOrExp RBRACKET statement ELSE statement {
    $$ = new TreeNode($3->lineno, NODE_STMT);
    $$->stype = STMT_IFELSE;
    $$->addChild($3);
    $$->addChild($5);
    $$->addChild($7);
}
| WHILE LBRACKET lOrExp RBRACKET statement {
    $$ = new TreeNode($3->lineno, NODE_STMT);
    $$->stype = STMT_WHILE;
    $$->addChild($3);
    $$->addChild($5);    
}
| BREAK SEMICOLON {
    $$ = new TreeNode(lineno, NODE_STMT);
    $$->stype = STMT_BREAK;
}
| CONTINUE SEMICOLON {
    $$ = new TreeNode(lineno, NODE_STMT);
    $$->stype = STMT_CONTI;   
}
| RETURN forExpr3 SEMICOLON {//return语句的返回值应该是可以不写的，这里借用for第三个表达式的形式
    $$ = new TreeNode(lineno, NODE_STMT);
    $$->stype = STMT_RETURN;  
    $$->addChild($2);     
}
| FOR LBRACKET forExpr12 SEMICOLON forExpr12 SEMICOLON forExpr3 RBRACKET statement {
    $$ = new TreeNode($3->lineno, NODE_STMT);
    $$->stype = STMT_FOR;
    $$->addChild($3);  
    $$->addChild($5);  
    $$->addChild($7);  
    $$->addChild($9);  
}
| IOFunc SEMICOLON {$$ = $1;}
;

forExpr12
: expr {$$ = $1;}
| T IDENTIFIER LOP_ASSIGN expr {
    $$ = new TreeNode($1->lineno, NODE_STMT);
    $$->stype = STMT_FOR_DECL;
    $$->addChild($1);
    $$->addChild($2);
    $$->addChild($4);
    $2->isdecl = true;
}
|{$$ = new TreeNode(lineno, NODE_EMPTY);}
;

forExpr3
: expr {$$ = $1;}
|{$$ = new TreeNode(lineno, NODE_EMPTY);}
;


IOFunc
: SCANF LBRACKET STRING COMMA scanfParams RBRACKET {
    $$ = new TreeNode($3->lineno, NODE_STMT);
    $$->stype = STMT_IOFUNC;
    $$->var_name = "scanf";
    $$->addChild($3);
    $$->addChild($6);
    is_use_stack = true;
}
| PRINTF LBRACKET STRING COMMA funcRParams RBRACKET {
    $$ = new TreeNode($3->lineno, NODE_STMT);
    $$->stype = STMT_IOFUNC;
    $$->var_name = "printf";
    $$->addChild($3);
    $$->addChild($5);
    is_use_stack = true;
}
;

scanfParams
: ADDR IDENTIFIER {
    $$ = new TreeNode($2->lineno, NODE_FUNCRPARAMS);
    $$->addChild($2);
}
| scanfParams COMMA ADDR IDENTIFIER {
    $$ = $1;
    $$->addChild($4);
}
;

block
: LBRACE RBRACE {
    $$ = new TreeNode(lineno, NODE_STMT);
    $$->stype = STMT_BLOK;     
}
| LBRACE statements RBRACE {
    $$ = new TreeNode($2->lineno, NODE_STMT);
    $$->stype = STMT_BLOK;     
    $$->addChild($2); 
}
;

decl
: declaration{$$ = $1;}
| constDeclaration {$$ = $1;}
;

declaration
:  T varDef {
    TreeNode* node = new TreeNode($1->lineno, NODE_STMT);
    node->stype = STMT_DECL;
    node->addChild($1);   
    node->addChild($2);   
    $$ = node;
}
| declaration COMMA varDef {
    $$ = $1;
    $$->addChild($3);
}
;

varDef
: LVal{
    $$ = new TreeNode($1->lineno,NODE_VARDEF);
    $$->addChild($1);
    $1->isdecl = true;
    // $1->child->isdecl = true;//数组扩展
}
| LVal LOP_ASSIGN initVal {
    $$ = new TreeNode($1->lineno,NODE_VARDEF);
    $$->addChild($1);
    $$->addChild($3);
    $1->isdecl = true;
    // $1->child->isdecl = true;//数组扩展
}
;

constDeclaration
: CONST T constDef {
    TreeNode* node = new TreeNode($2->lineno, NODE_STMT);
    node->stype = STMT_DECL_CONST;
    node->addChild($2);   
    node->addChild($3);   
    $$ = node;   
}
| constDeclaration COMMA constDef {
    $$ = $1;
    $$->addChild($3);
}
;

constDef
: LVal LOP_ASSIGN initVal {
    $$ = new TreeNode($1->lineno,NODE_VARDEF);
    $$->addChild($1);
    $$->addChild($3);
    $1->isdecl = true;
    // $1->child->isdecl = true;//数组扩展
}
;

initVal//主要是给数组赋值
: expr {$$ = $1;}
//数组扩展：
// : expr {
//     $$ = new TreeNode($1->lineno, NODE_INITVAL);
//     $$->addChild($1);   
// }
// | LBRACE RBRACE {$$ = new TreeNode(lineno, NODE_EMPTY);}
// | LBRACE exprs RBRACE {
//     $$ = new TreeNode($2->lineno, NODE_INITVAL);
//     $$->addChild($2);
// }
;

// exprs
// : expr{$$=$1;}
// | exprs COMMA expr {
//     $$ = $1;
//     $$->addSibling($3);
// }
// ;


T: T_INT {$$ = new TreeNode(lineno, NODE_TYPE); $$->type = TYPE_INT;} 
| T_CHAR {$$ = new TreeNode(lineno, NODE_TYPE); $$->type = TYPE_CHAR;}
| T_BOOL {$$ = new TreeNode(lineno, NODE_TYPE); $$->type = TYPE_BOOL;}
| T_VOID {$$ = new TreeNode(lineno, NODE_TYPE); $$->type = TYPE_VOID;}
;

expr
: addExp {$$ = $1;}//算术表达式
| lOrExp {$$ = $1;}//逻辑表达式
| IDENTIFIER LOP_ASSIGN expr {//赋值式也有返回值，也可以是表达式
    $$ = new TreeNode($1->lineno,   NODE_EXPR);
    $$->optype = OP_ASSG;
    $$->type = $3->type;
    $$->addChild($1);
    $$->addChild($3);
}
| IDENTIFIER ADD_ASSIGN expr {//赋值式也有返回值，也可以是表达式
    $$ = new TreeNode($1->lineno,   NODE_EXPR);
    $$->optype = OP_ADD_ASSG;
    $$->type = $3->type;
    $$->addChild($1);
    $$->addChild($3);
}
| IDENTIFIER SUB_ASSIGN expr {//赋值式也有返回值，也可以是表达式
    $$ = new TreeNode($1->lineno,   NODE_EXPR);
    $$->optype = OP_SUB_ASSG;
    $$->type = $3->type;
    $$->addChild($1);
    $$->addChild($3);
}
;

lOrExp
: lAndExp {$$ = $1;}
| lOrExp OR lAndExp {
    TreeNode* node = new TreeNode($1->lineno, NODE_EXPR);
    node->optype = OP_OR;
    node->type = TYPE_BOOL;
    node->addChild($1);
    node->addChild($3);
    $$ = node;
}
;

lAndExp
: eqExp {$$ = $1;}
| lAndExp AND eqExp {
    TreeNode* node = new TreeNode($1->lineno, NODE_EXPR);
    node->optype = OP_AND;
    node->type = TYPE_BOOL;
    node->addChild($1);
    node->addChild($3);
    $$ = node;   
}
;

eqExp
: relExp {$$ = $1;}
| eqExp LOP_EQ relExp {
    TreeNode* node = new TreeNode($1->lineno, NODE_EXPR);
    node->optype = OP_EQ;
    node->type = TYPE_BOOL;
    node->addChild($1);
    node->addChild($3);
    $$ = node;       
}
| eqExp LOP_NQ relExp {
    TreeNode* node = new TreeNode($1->lineno, NODE_EXPR);
    node->optype = OP_NQ;
    node->type = TYPE_BOOL;
    node->addChild($1);
    node->addChild($3);
    $$ = node;         
}
;

relExp
: addExp {$$ = $1;}
| relExp LT addExp {
    TreeNode* node = new TreeNode($1->lineno, NODE_EXPR);
    node->optype = OP_LT;
    node->type = TYPE_BOOL;
    node->addChild($1);
    node->addChild($3);
    $$ = node;          
}
| relExp BT addExp {
    TreeNode* node = new TreeNode($1->lineno, NODE_EXPR);
    node->optype = OP_BT;
    node->type = TYPE_BOOL;
    node->addChild($1);
    node->addChild($3);
    $$ = node;          
}
| relExp LTEQ addExp {
    TreeNode* node = new TreeNode($1->lineno, NODE_EXPR);
    node->optype = OP_LTEQ;
    node->type = TYPE_BOOL;
    node->addChild($1);
    node->addChild($3);
    $$ = node;          
}
| relExp BTEQ addExp {
    TreeNode* node = new TreeNode($1->lineno, NODE_EXPR);
    node->optype = OP_BTEQ;
    node->type = TYPE_BOOL;
    node->addChild($1);
    node->addChild($3);
    $$ = node;          
}
;


addExp
: mulExp {$$ = $1;}
| addExp ADD mulExp {
    TreeNode* node = new TreeNode($1->lineno, NODE_EXPR);
    node->optype = OP_ADD;
    node->type = TYPE_INT; 
    node->addChild($1);
    node->addChild($3);
    $$ = node;
}
| addExp SUB mulExp {
    TreeNode* node = new TreeNode($1->lineno, NODE_EXPR);
    node->optype = OP_SUB;
    node->type = TYPE_INT; 
    node->addChild($1);
    node->addChild($3);
    $$ = node;   
}
;

mulExp
: unaryExp {$$ = $1;}
| mulExp MUL unaryExp {
    TreeNode* node = new TreeNode($1->lineno, NODE_EXPR);
    node->optype = OP_MUL;
    node->type = TYPE_INT; 
    node->addChild($1);
    node->addChild($3);
    $$ = node;   
}
| mulExp DIV unaryExp {
    TreeNode* node = new TreeNode($1->lineno, NODE_EXPR);
    node->optype = OP_DIV;
    node->type = TYPE_INT; 
    node->addChild($1);
    node->addChild($3);
    $$ = node;    
}
| mulExp MOD unaryExp {
    TreeNode* node = new TreeNode($1->lineno, NODE_EXPR);
    node->optype = OP_MOD;
    node->type = TYPE_INT; 
    node->addChild($1);
    node->addChild($3);
    $$ = node;   
}
;

unaryExp
: primaryExp {$$ = $1;}
| ADD unaryExp %prec NOT {
    TreeNode* node = new TreeNode($2->lineno, NODE_EXPR);
    node->optype = OP_OPT;
    node->type = TYPE_INT; 
    node->addChild($2);
    $$ = node;
}
| SUB unaryExp %prec NOT {
    TreeNode* node = new TreeNode($2->lineno, NODE_EXPR);
    node->optype = OP_NEG;
    node->type = TYPE_INT; 
    node->addChild($2);
    $$ = node;
}
| NOT unaryExp {
    TreeNode* node = new TreeNode($2->lineno, NODE_EXPR);
    node->optype = OP_NOT;
    node->type = TYPE_BOOL; 
    node->addChild($2);
    $$ = node;
} 
| IDENTIFIER LBRACKET funcRParams RBRACKET {//函数调用语句
    $$ = new TreeNode($1->lineno, NODE_EXPR);
    $$->optype = OP_FUNC;
    $$->type = $1->type;
    $$->addChild($1);
    $$->addChild($3);
}
;

funcRParams
: {$$ = new TreeNode(lineno, NODE_EMPTY);}
| expr {$$ = new TreeNode($1->lineno,NODE_FUNCRPARAMS);
    $$->addChild($1);
}
| funcRParams COMMA expr {
    $$ = $1;
    $$->addChild($3);
}
;

primaryExp
: LBRACKET expr RBRACKET {$$ = $2;}
| LVal {
    $$=$1;
    $$->optype = OP_NULL;
}
| INC IDENTIFIER %prec NOT  {
    TreeNode* node = new TreeNode($2->lineno, NODE_EXPR);
    node->optype = OP_INC;
    node->type = TYPE_INT; 
    node->addChild($2);
    $$ = node;
}
| DEC IDENTIFIER %prec NOT  {
    TreeNode* node = new TreeNode($2->lineno, NODE_EXPR);
    node->optype = OP_DEC;
    node->type = TYPE_INT; 
    node->addChild($2);
    $$ = node;
}
| IDENTIFIER INC {
    TreeNode* node = new TreeNode($1->lineno, NODE_EXPR);
    node->optype = OP_INC;
    node->type = TYPE_INT; 
    node->addChild($1);
    $$ = node;
}
| IDENTIFIER DEC {
    TreeNode* node = new TreeNode($1->lineno, NODE_EXPR);
    node->optype = OP_DEC;
    node->type = TYPE_INT; 
    node->addChild($1);
    $$ = node;
}
| INTEGER {
    $$=$1; 
    $$->optype = OP_NULL;
}
| CHAR {
    $$=$1; 
    $$->optype = OP_NULL;
} 
| STRING {
    $$=$1; 
    $$->optype = OP_NULL;
}
;

LVal //左值表达式，主要是实现变量的数组形式 
: IDENTIFIER {$$ = $1;}
// :IDENTIFIER{
//     TreeNode* node = new TreeNode($1->lineno, NODE_LVAL);
//     node->type = TYPE_INT; 
//     node->addChild($1);
//     $$ = node;
// }
// | LVal LSB addExp RSB {//我希望这一块的语法树尽量扁平，不要有太多的嵌套 后面不方便的话，再改成嵌套结构
//     $$ = $1;
//     $$->addChild($3);
// }
;



%%

int yyerror(char const* message)
{
  cout << message << " at line " << lineno << endl;
  return -1;
}