#include<iostream>
#include<conio.h>
#include "class_struct_define.h"
#include "register.h"
#include "menu.h"
using namespace std;
int main()
{
	/********欢迎界面********/
	int choice;
	while (1)
	{
		cout << "================================================================================\n" << endl;
		cout << "================================================================================\n" << endl;
		cout << "****************************欢迎来到华工批发部**********************************\n" << endl;
		cout << "--------------------------------------------------------------------------------\n" << endl;
		cout << "********************************************************************************\n" << endl;
		cout << "================================================================================\n" << endl;
		cout << "1.用户登录" << '\t' << '\t'
			<< "2.后台管理人员登录" << '\t' << '\t'
			<< "3.退出系统" << endl;
		choice = _getch();
		switch (choice)
		{
		case '1':user_register(); break;
		case '2':staff_register(); break;
		case '3':exit(1); break;
		default:
		{
			cout << "请输入正确的操作！" << endl;
		} break;
		}
		system("cls");
	}
	system("pause");
}