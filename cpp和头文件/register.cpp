//���ļ�����ʵ���û���¼��������Ա��¼���˳���¼
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
		cout << "�������û���:" << endl;
		cin >> name;
		cout << "����������:" << endl;
		cin >> password;
		while (infile.peek() != EOF)
		{
			infile.getline(right_name, 30);
			infile.getline(right_password, 30);
			if (strcmp(name, right_name) == 0 && strcmp(password, right_password) == 0)
			{
				cout << "��¼�ɹ���2����Զ���ת!";
				Sleep(2000);
				system("cls");
				int choice = 1;
				while (choice)
				{
					user A(password, name);
					user_options(A);//�ڴ˴������жϣ����ڴ˴�
					system("cls");
					return;
				}

			}
		}
		     cout << "�û�������������������루1�����˳���¼��0��" << endl;
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
						cout << "��������ȷ��������" << endl;
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
		cout << "�������û���:" << endl;
		cin >> name;
		cout << "����������:" << endl;
		cin >> password;
		while (infile.peek() != EOF)
		{
			infile.getline(right_name, 30);
			infile.getline(right_password, 30);
			if (strcmp(name, right_name) == 0 && strcmp(password, right_password) == 0)
			{
				cout << "��¼�ɹ���2����Զ���ת!";
				Sleep(2000);
				system("cls");
				int choice = 1;
				while (choice)
				{
					staff A(password, name);
					staff_options(A);//�ڴ˴������жϣ����ڴ˴�
					system("cls");
					return;				//delete A;
				}

			}
		}
          	cout << "�û�������������������루1�����˳���¼��2��" << endl;
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
					cout << "��������ȷ��������" << endl;
				}; break;
				}
			}
	}
