%option nounput
%{
#include "common.h"
#include "main.tab.h"  // yacc header
int lineno=1;
bool isfirst = true;//当在一个块注释中遇到一个*/后，该bool置为假
%}
BLOCKCOMMENT \/\*([^\*^\/]*|[\*^\/*]*|[^\**\/]*)*\*\/
LINECOMMENT \/\/[^\n]*
EOL	(\r\n|\r|\n)
WHILTESPACE [[:blank:]]

INTEGER (0|[1-9][0-9]*)
OCTALNUM 0[0-7]+
HEXNUM 0x([0-9]|[A-F]|[a-f])+

CHAR \'\\?.\'
STRING \".+\"


IDENTIFIER [[:alpha:]_][[:alpha:][:digit:]_]*

%%

{BLOCKCOMMENT}  {
    for(int i =0;i<yyleng;i++){
        if(yytext[i]=='\n')
            lineno++;
        if(yytext[i]=='*'&&yytext[i+1]=='/')
        {
            if(isfirst)
                isfirst=false;
            else
                cout<<lineno<<"行注释匹配错误！"<<endl;
        }
    }
}
{LINECOMMENT}  /*do nothing*/


"int" return T_INT;
"bool" return T_BOOL;
"char" return T_CHAR;
"void" return T_VOID;

"if" return IF;
"else" return ELSE;
"while" return WHILE;
"break" return BREAK;
"continue" return CONTINUE;
"return" return RETURN;
"for" return FOR;
"scanf" return SCANF;
"printf" return PRINTF;
"const" return CONST;

"{" return LBRACE;
"}" return RBRACE;
"(" return LBRACKET;
")" return RBRACKET;
"[" return LSB;
"]" return RSB;
"-=" return SUB_ASSIGN;
"+=" return ADD_ASSIGN;
"++" return INC;
"--" return DEC;
"=" return LOP_ASSIGN;
"+" return ADD;
"-" return SUB;
"*" return MUL;
"/" return DIV;
"%" return MOD;
"!" return NOT;
";" return  SEMICOLON;
"," return COMMA;
"||" return OR;
"&&" return AND;
"==" return LOP_EQ;
"!=" return LOP_NQ;
"<" return LT;
">" return BT;
"<=" return LTEQ;
">=" return BTEQ;
"&" return ADDR;

{HEXNUM} {
    TreeNode* node = new TreeNode(lineno, NODE_CONST);
    node->type = TYPE_INT;
    sscanf(yytext,"%x",&(node->int_val));
    node->expType = EXP_INT;
    node->isConst = true;
    yylval = node;
    return INTEGER;
}

{OCTALNUM} {
    TreeNode* node = new TreeNode(lineno, NODE_CONST);
    node->type = TYPE_INT;
    sscanf(yytext,"%o",&(node->int_val));
    node->expType = EXP_INT;
    node->isConst = true;
    yylval = node;
    return INTEGER;
}

{INTEGER} {
    TreeNode* node = new TreeNode(lineno, NODE_CONST);
    node->type = TYPE_INT;
    node->int_val = atoi(yytext);
    node->expType = EXP_INT;
    node->isConst = true;
    yylval = node;
    return INTEGER;
}

{CHAR} {
    TreeNode* node = new TreeNode(lineno, NODE_CONST);
    node->type = TYPE_CHAR;
    node->isConst = true;
    if(yytext[1]=='\\')
    {
        switch(yytext[2])
        {
            case 'a':
            {
                node->ch_val = '\a';
                break;
            }
            case 'b':
            {
                node->ch_val = '\b';
                break;
            }
            case 'f':
            {
                node->ch_val = '\f';
                break;
            }
            case 'n':
            {
                node->ch_val = '\n';
                break;
            }
            case 'r':
            {
                node->ch_val = '\r';
                break;
            }
            case 't':
            {
                node->ch_val = '\t';
                break;
            }
            case 'v':
            {
                node->ch_val = '\v';
                break;
            }
            case '\\':
            {
                node->ch_val = '\\';
                break;
            }
            case '\'':
            {
                node->ch_val = '\'';
                break;
            }
            case '\"':
            {
                node->ch_val = '\"';
                break;
            }
            case '?':
            {
                node->ch_val = '?';
                break;
            }
            case '0':
            {
                node->ch_val = '\0';
                break;
            }
            default:
            {
                cerr<<"unknown char line:"<<lineno<<endl;
                exit(-1);
            }
        }
    }
    else
        node->ch_val = yytext[1];
    node->expType = EXP_CHAR;
    yylval = node;
    return CHAR;
}

{STRING} {
    TreeNode* node = new TreeNode(lineno,NODE_CONST);
    node->type = TYPE_STRING;
    node->isConst = true;
    node->expType = EXP_STRING;
    node->str_val = yytext+1;
    node->str_val.pop_back();
    yylval = node;
    return STRING;
}
{IDENTIFIER} {
    TreeNode* node = new TreeNode(lineno, NODE_VAR);
    node->type = TYPE_INT;
    node->var_name = string(yytext);
    yylval = node;
    return IDENTIFIER;
}


{WHILTESPACE} /* do nothing */

{EOL} lineno++;

. {
    cerr << "[line "<< lineno <<" ] unknown character:" << yytext << endl;
}
%%