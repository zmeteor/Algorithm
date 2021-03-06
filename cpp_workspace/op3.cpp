/*************************************************************************
	> File Name: op3.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年03月31日 星期六 21时09分22秒
 ************************************************************************/

#include <iostream>

using namespace std;

int main()
{
    int a =9;
    int b =10;

    (a<b?a:b) = 0; //c++中三目运算符返回的是变量本身，可以做左值
    //(a>b?1:b) = 0; //error 若返回值中有常量则不可以

    cout<<"a = "<<a<<" b = "<<b<<endl;
    return 0;
}

/*c++ 中三目运算符之可以作为左值是因为编译器帮我们取了变量的地址返回变量本身*/

/*
总结：
C语言返回变量的值 C++语言是返回变量本身
C语言中的三目运算符返回的是变量值，不能作为左值使用
C++中的三目运算符可直接返回变量本身，因此可以出现在程序的任何地方
注意：三目运算符可能返回的值中如果有一个是常量值，则不能作为左值使用
(a < b ? 1 : b )= 30;
*/

