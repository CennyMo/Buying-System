#include<iostream>
#include<fstream>
#include<Windows.h>
#include<conio.h>
#include <iomanip>
#include"class_struct_define.h"
#include"load.h"
#include "common_function.h"
using namespace std;
user::user(char* A, char* B) 
{
	strcpy_s(password, A);
	strcpy_s(name, B);
}
void user::print_all_orders()
{
	fstream infile("order.txt");
	if (infile.peek() == EOF)
	{
		cout << "当前没有订单！1秒后返回！" << endl;
		infile.close();
		Sleep(1000);
		system("cls");
		return;
	}
	order* head = load_order();
	int label = 0;
	cout << left << setw(20) << "用户名" << left << setw(20)
		<< "商品名称" << left << setw(20)
		<< "商品型号" << left << setw(20)
		<< "订购数量" << left << setw(20)
		<< "总金额" << left << setw(20)
		<< "送货地址" << left << setw(20)
		<< "联系电话" << endl;
		while (head!= NULL)
		{
			if (strcmp(head->client_name,name)==0)
			{
				cout << left << setw(20) << head->client_name << left << setw(20)
					<< head->good_name << left << setw(20)
					<< head->good_type << left << setw(20)
					<< head->good_number << left << setw(20)
					<< head->amount_money << left << setw(20)
					<< head->address << left << setw(20)
					<< head->phone << endl;
				label = 1;
			}
			order*p = head;
			head = head->next;
			delete p;
		}
		if (label == 0)
		{
			cout << "您当前没有订单！" << endl;
		}
		cout << "按任意键返回" << endl;
		_getch();
		system("cls");
		return;
	}

void user::search_goods(user &A)//记得还要调用购买函数
{
	fstream infile("goods.txt");
	if (infile.peek() == EOF)
	{
		cout << "当前没有商品！1秒后返回！" << endl;
		infile.close();
		Sleep(1000);
		system("cls");
		return;
	}
	good *head = load_good();
		while (1)
		{
			cout << "请输入你需要查询的物品名称(1)或型号(2):" << endl;
			cout << "返回（3）" << endl;
			//名称查询
			int choice = _getch();
			if (choice == '1')
			{
				cout << "请输入商品名称：" << endl;
				char name[30];
				cin >> name;
				int label = 0;//先初始化一个label，如果找到商品，则label=1
				cout << left << setw(20) << "商品名称" << left << setw(20)
					<< "商品型号" << left << setw(20)
					<< "产地" << left << setw(20)
					<< "余量" << left << setw(20)
					<< "单价" << left << setw(20)
					<< "编号" << '\n';
				while (head!= NULL)
				{
					if (strcmp(name, head->name) == 0)
					{
						cout << left << setw(20) << head->name << left << setw(20)
							<< head->type << left << setw(20)
							<< head->origin << left << setw(20)
							<< head->number << left << setw(20)
							<< head->price << left << setw(20)
							<< head->ID << '\n';
						label = 1;
					}
					good*p = head;
					head = head->next;
					delete p;
				}
				if (label == 0)
				{
					cout << "未能查询到商品信息！按任意键重新输入，按1返回！" << endl << endl;
					choice = _getch();
					if (choice == '1')
					{
						system("cls");
						return;
					}
				}
				else
				{
					cout << "请输入您要购买商品的型号" << endl;
					char type[30];
					int choice;
					cin >> type;
					choice = A.buy(type);
					if (!choice)
					{
						return;
					}
				}
			}
			else if (choice == '2')
			{
				cout << "请输入商品型号：" << endl;
				char type[30];
				cin >> type;
				int label = 0;//先初始化一个label，如果找到商品，则
				good* head = load_good();
				cout << left << setw(20) << "商品名称" << left << setw(20)
					<< "商品型号" << left << setw(20)
					<< "产地" << left << setw(20)
					<< "余量" << left << setw(20)
					<< "单价" << left << setw(20)
					<< "编号" << '\n';
				while (head!= NULL)
				{
					if (strcmp(type, head->type) == 0)
					{
						cout << left << setw(20) << head->name << left << setw(20)
							<< head->type << left << setw(20)
							<< head->origin << left << setw(20)
							<< head->number << left << setw(20)
							<< head->price << left << setw(20)
							<< head->ID << '\n';
						label = 1;
					}
					good*p = head;
					head = head->next;
					delete p;
				}
				if (label == 0)
				{
					cout << "未能查询到商品信息！按任意键重新输入，按1返回！" << endl << endl;
					choice = _getch();
					if (choice == '1')
					{
						system("cls");
						return;
					}
				}
				else
				{
					cout << "请输入您要购买商品的型号" << endl;
					char type[30];
					int choice;
					cin >> type;
					choice = A.buy(type);
					if (!choice)
					{
						return;
					}
				}
			}
			else if (choice == '3')
			{
				system("cls");
				return;
			}
			else
			{
				cout << "请输入正确操作数！" << endl;
			}
		}
	}

int user::buy(char* type)
{
	char address[30];
	char phone[30];
	char good_name[30];
	char price[30];
	int buy_number;
	int origin_number;
	good *head = load_good();
	while (head!= NULL)
	{
		if (strcmp(type, head->type) == 0)
		{
			strcpy_s(good_name, head->name);
			strcpy_s(price, head->price);
			origin_number = head->number;
		}
		good*p = head;
		head = head->next;
		delete p;
	}
	ofstream outfile("order.txt", ios::app);
	while (1)
	{
		cout << "请完善您的资料：" << endl;
		cout << "用户名：" << name << endl;
		cout << "购买商品名称：" << good_name << endl;
		cout << "商品单价：" << price << endl;
		cout << "请填写购买个数：" << endl;
		cin >> buy_number;
		if (buy_number > origin_number)
		{
			cout << "商品余量不足！请重新填写！" << endl;
			Sleep(2000);
			system("cls");
		}
		else
		{
			cout << "请填写电话号码：" << endl;
			cin >> phone;
			cout << "请填写地址：" << endl;
			cin >> address;
			cout << "购买完成！" << endl;//这时候开始处理订单
			delete_good_number(buy_number, origin_number, type);
			outfile << name << endl
				<< good_name << endl
				<< type << endl
				<< buy_number << endl
				<< atoi(price)*(buy_number) << endl
				<<address << endl
				<<phone<<endl;
			cout << "是否继续购买(输入1继续，输入0返回)？" << endl;
			while (1)
			{
				int choice = _getch();
				if (choice == '1')
				{
					return 1;
				}
				else if (choice == '0')
				{
					return 0;
				}
				else
				{
					cout << "请输入正确操作数！" << endl;
				}
			}
		}
	}
	outfile.close();
}
void user::modify_user_information()
{
	user B;
	person *head = B.load_user();
	person* sub;
	sub = head;
	char new_password[30];
	cout << "请输入新密码！" << endl;
	cin >> new_password;
	while (sub != NULL)
	{
		if (strcmp(name, sub->name) == 0)
		{
			strcpy_s(sub->password, new_password);
		}
		sub = sub->next;
	}
	ofstream outfile("user.txt", ios::beg);
	while (head != NULL)
	{
		person*p = head;
		outfile << p->name << endl
			<< p->password << endl;
		head = head->next;
		delete p;
	}
	outfile.close();
	cout << "修改成功！2秒后返回！" << endl;
	strcpy_s(password, new_password);
	Sleep(2000);
	system("cls");
	return;
}
person* user:: load_user()
{
	fstream infile;
	infile.open("user.txt");
	person *head = new person;
	head->next = NULL;
	person *p = new person;
	person *last;
	char line[30];
	while (infile.peek() != EOF)
	{
		if (head->next == NULL)
		{
			infile.getline(line, 30);
			strcpy_s(head->name, line);
			infile.getline(line, 30);
			strcpy_s(head->password, line);
			head->next = p;
		}
		else
		{
			infile.getline(line, 30);
			strcpy_s(p->name, line);
			infile.getline(line, 30);
			strcpy_s(p->password, line);
			if (infile.peek() != EOF)
			{
				last = p;
				p = new person;
				last->next = p;
			}
			p->next = NULL;
		}
	}
	infile.close();
	return head; //返回头指针
}
