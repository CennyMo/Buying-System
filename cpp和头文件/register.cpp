//此文件用于实现用户登录，工作人员登录，退出登录
#include <iostream>
#include <fstream>
#include <Windows.h>
#include<conio.h>
#include "register.h"
#include "menu.h"
#include "class_struct_define.h"
using namespace std;

void user_register()
{
	char password[30];
	char name[30];
	char right_name[30];
	char right_password[30];
	while (1)
	{
		ifstream infile("user.txt");
		cout << "请输入用户名:" << endl;
		cin >> name;
		cout << "请输入密码:" << endl;
		cin >> password;
		while (infile.peek() != EOF)
		{
			infile.getline(right_name, 30);
			infile.getline(right_password, 30);
			if (strcmp(name, right_name) == 0 && strcmp(password, right_password) == 0)
			{
				cout << "登录成功，2秒后自动跳转!";
				Sleep(2000);
				system("cls");
				int choice = 1;
				while (choice)
				{
					user A(password, name);
					user_options(A);//在此处设置判断，若在此处
					system("cls");
					return;
				}

			}
		}
		     cout << "用户名或密码错误！重新输入（1）或退出登录（0）" << endl;
			 int choice;
			 choice = _getch();
		         switch (choice)
			   {
				 case '1': {}; break;
				 case '0':
					{
						return;
					}; break;
				default:
					{
						cout << "请输入正确操作数！" << endl;
					}; break;
					}
				}
			}
		
	
	


void staff_register()
{
	char password[30];
	char name[30];
	char right_name[30];
	char right_password[30];
	char line[30];
	while (1)
	{
		ifstream infile("staff.txt");
		cout << "请输入用户名:" << endl;
		cin >> name;
		cout << "请输入密码:" << endl;
		cin >> password;
		while (infile.peek() != EOF)
		{
			infile.getline(right_name, 30);
			infile.getline(right_password, 30);
			if (strcmp(name, right_name) == 0 && strcmp(password, right_password) == 0)
			{
				cout << "登录成功，2秒后自动跳转!";
				Sleep(2000);
				system("cls");
				int choice = 1;
				while (choice)
				{
					staff A(password, name);
					staff_options(A);//在此处设置判断，若在此处
					system("cls");
					return;				//delete A;
				}

			}
		}
          	cout << "用户名或密码错误！重新输入（1）或退出登录（2）" << endl;
				int  choice;
				choice = _getch();
				switch (choice)
				{
				case '1': {}; break;
				case '0':
				{
					return;
				}; break;
				default:
				{
					cout << "请输入正确操作数！" << endl;
				}; break;
				}
			}
	}
