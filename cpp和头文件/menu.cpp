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
		cout << "-----------------------��ӭ������������Ҫ����ʲô������----------------------------------\n\n";
		cout << "-------------------------- 1 ��ѯ������Ʒ������------------------------------------------\n\n";
		cout << "-------------------------- 2 ��ѯ������Ʒ------------------------------------------\n\n";
		cout << "-------------------------- 3 ��ѯ���ж���--------------------------------------\n\n";
		cout << "-------------------------- 4 �޸ĸ�������--------------------------------------\n\n";
		cout << "-------------------------- 5 �˳���¼------------------------------------------\n\n";
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
		default:cout << "��������ȷ��������" << endl;
		}
		system("cls");
	}
}
void staff_options(staff &A)
{
	int choice;
	while (1)
	{
		cout << "------------------------��ӭ������������Ҫ����ʲô������----------------------------------\n\n";
		cout << "-------------------------- 1 ��ѯ������Ʒ--------------------------------------\n\n";
		cout << "-------------------------- 2 ��ѯ���ж���--------------------------------------\n\n";
		cout << "-------------------------- 3 ������Ʒ--------------------------------------\n\n";
		cout << "-------------------------- 4 �¼���Ʒ--------------------------------------\n\n";
		cout << "-------------------------- 5 �޸ĸ�������--------------------------------------\n\n";
		cout << "-------------------------- 6 �˳���¼------------------------------------------\n\n";
		choice = _getch();
		switch (choice)
		{
		case '1':A.print_all_goods(); break;
		case '2':A.print_all_order(); break;
		case '3':A.add_good(); break;
		case '4':A.delete_good(); break;
		case '5':A.modify_staff_information(); break;
		case '6':return; break;
		default:cout << "��������ȷ��������" << endl;
		}
		system("cls");
	}
}
