已实现的特性：
1. int和char类型变量的声明和初始化
2. 算术表达式
3. 逻辑表达式
4. if-else语句 while循环 for循环 return 语句 
5. 赋值语句
6. 语句块
7. printf和scanf两个IO函数
8. 常量声明，类型检查
9. 变量列表
10. 符号表构造与输出
11. 注释，多行注释，保证行号正确
12. 临时变量在栈上分配

备忘录：
1. 所有的表达式节点的type都是int，如果是单个变量组成的表达式，也是int类型
2. 所有产生式没有考虑数组
3. 算术表达式和逻辑表达式地位是等同的
4. 条件和循环语句的条件语句可以写逻辑表达式也可以写算术表达式
5. for循环第一个表达式可以是变量声明+初始化,三个表达式都可以为空
6. 函数节点没有设计任何属性，也没有实现形参和实参列表，返回值可以是T中的所有类型，一个程序可以有多个函数
7. scanf函数的第二个参数必须要有&开头
8. 符号表里是不包含常量的
9. 目前数组的方括号里是可以是变量的，主要看后面的类型检查的难度，决定要不要改
10. 全局变量声明时，初始值必须为字面常量，不能是表达式
11. 想要将局部变量声明为全局变量，只需要将tree.h中681行和682行注释掉就可以了