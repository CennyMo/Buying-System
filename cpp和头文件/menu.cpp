#include<iostream>
#include<Windows.h>
#include <stdio.h>
#include<conio.h>
#include <time.h>
#include "menu.h"
#include "class_struct_define.h"
#include "register.h"
using namespace std;
void user_options(user &A)
{
	int  choice;
	while (1)
	{
		cout << "-----------------------欢迎您！请问您需要进行什么操作？----------------------------------\n\n";
		cout << "-------------------------- 1 查询单个商品并购买------------------------------------------\n\n";
		cout << "-------------------------- 2 查询所有商品------------------------------------------\n\n";
		cout << "-------------------------- 3 查询所有订单--------------------------------------\n\n";
		cout << "-------------------------- 4 修改个人资料--------------------------------------\n\n";
		cout << "-------------------------- 5 退出登录------------------------------------------\n\n";
		choice = _getch();
		switch (choice)
		{
		case '1':A.search_goods(A); break;
		case '2':
		{
			staff a;
			a.print_all_goods(); }
		break;
		case '3':A.print_all_orders(); break;
		case '4':A.modify_user_information(); break;
		case '5':return; break;
		default:cout << "请输入正确操作数！" << endl;
		}
		system("cls");
	}
}
void staff_options(staff &A)
{
	int choice;
	while (1)
	{
		cout << "------------------------欢迎您！请问您需要进行什么操作？----------------------------------\n\n";
		cout << "-------------------------- 1 查询所有商品--------------------------------------\n\n";
		cout << "-------------------------- 2 查询所有订单--------------------------------------\n\n";
		cout << "-------------------------- 3 增加商品--------------------------------------\n\n";
		cout << "-------------------------- 4 下架商品--------------------------------------\n\n";
		cout << "-------------------------- 5 修改个人资料--------------------------------------\n\n";
		cout << "-------------------------- 6 退出登录------------------------------------------\n\n";
		choice = _getch();
		switch (choice)
		{
		case '1':A.print_all_goods(); break;
		case '2':A.print_all_order(); break;
		case '3':A.add_good(); break;
		case '4':A.delete_good(); break;
		case '5':A.modify_staff_information(); break;
		case '6':return; break;
		default:cout << "请输入正确操作数！" << endl;
		}
		system("cls");
	}
}
