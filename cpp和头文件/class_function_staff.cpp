#include<iostream>
#include<fstream>
#include<Windows.h>
#include<iomanip>
#include<conio.h>
#include"menu.h"
#include"class_struct_define.h"
#include"load.h"
#include"common_function.h"
using namespace std;

staff::staff(char* A, char* B)
{
	strcpy_s(password, A);
	strcpy_s(name, B);
}
void staff::print_all_order()
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
	cout << left << setw(20) << "用户名" << left << setw(20)
		<< "商品名称" << left << setw(20)
		<< "商品型号" << left << setw(20)
		<< "订购数量" << left << setw(20)
		<< "总金额" << left << setw(20)
		<< "送货地址" << left << setw(20)
		<< "联系电话" << endl;
		while (head!= NULL)
		{
			cout << left << setw(20) << head->client_name << left << setw(20)
				<< head->good_name << left << setw(20)
				<< head->good_type << left << setw(20)
				<< head->good_number << left << setw(20)
				<< head->amount_money << left << setw(20)
				<< head->address << left << setw(20)
				<< head->phone << endl;
			order*p = head;
			head = head->next;
			delete p;
		}
		cout << "按任意键返回" << endl;
		_getch();
		system("cls");
		return;
	}


void staff::print_all_goods()
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
	good* head = load_good();
	cout << left << setw(20) << "商品名称" << left << setw(20)
		<< "商品型号" << left << setw(20)
		<< "产地" << left << setw(20)
		<< "余量" << left << setw(20)
		<< "单价" << left << setw(20)
		<< "编号" << '\n';
	while (head!= NULL)
	{
		cout << left << setw(20) << head->name << left << setw(20)
			<< head->type << left << setw(20)
			<< head->origin << left << setw(20)
			<< head->number << left << setw(20)
			<< head->price << left << setw(20)
			<< head->ID << '\n';
			good*p = head;
			head = head->next;
			delete p;
	}
	cout << "按任意键返回" << endl;
	_getch();
	system("cls");
	return;
}

void staff::add_good()
{
	char name[30];
	int number;
	char ID[30];
	char type[30];
	char price[30];
	char origin[30];
	ofstream outfile("goods.txt",ios::app);
	cout << "请输入商品名称：" << endl;
	cin >> name;
	outfile<< name << endl;//在文件尾追加换行
	cout << "请输入商品型号：" << endl;
	cin >> type;
	outfile << type<< endl;
	cout << "请输入产地：" << endl;
	cin >> origin;
	outfile << origin << endl;
	cout << "请输入余量：" << endl;
	cin >> number;
	outfile << number << endl;
	cout << "请输入单价：" << endl;
	cin >> price;
	outfile << price << endl;
	cout << "请输入编号：" << endl;
	cin >> ID;
	outfile << ID << endl;
	cout << "录入成功！2秒后返回" << endl;
	Sleep(2000);
	system("cls");
	return;
}
void staff::delete_good()
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
	good* head = load_good();
	good *left;
	good *right;
	good *p=head;
	char ID[30];
	int label = 0;
	cout << "请输入您要删除的商品编号" << endl;
	cin >> ID;
	if (strcmp(ID, head->ID) == 0)
	{
		p = head->next;//存储下一个节点
		delete head;
		label = 1;
	}
	else
	{
		left = head;
		head = head->next;
		right = head->next;	
		while (head!= NULL)
		{	
			if (strcmp(ID, head->ID) == 0)
			{
				left->next = right;
				delete head;
				label = 1;
				break;
			}
			if (head->next != NULL)
			{
				left = head;
				head = head->next;
				right = head->next;
			}
		}
	}
	if (label == 0)
	{
		cout << "无法找到此商品！2秒后返回！" << endl;
	}
	else
	{
		ofstream outfile("goods.txt");
		while (p!= NULL)
		{
			good* a = p;
			outfile << p->name << endl
				<< p->type << endl
				<< p->origin << endl
				<< p->number << endl
				<< p->price << endl
				<< p->ID << endl;
			p = p->next;
			delete a;
		}
		outfile.close();
		cout << "删除成功！2秒后返回！" << endl;
	}
	Sleep(2000);
	system("cls");
	return;
	
}
person* staff::load_staff()
{
	fstream infile;
	infile.open("staff.txt");
	person *head = new person;
	head->next = NULL;
	person *p = new person;
	person *last;
	char line[30];
	while (infile.peek() != EOF)
	{
		if (head->next == NULL)
		{
			infile.getline(line, 50);
			strcpy_s(head->name, line);
			infile.getline(line, 50);
			strcpy_s(head->password, line);	
			head->next = p;
			p->next = NULL;
		}
		else
		{
			infile.getline(line, 50);
			strcpy_s(p->name, line);
			infile.getline(line, 50);
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
void staff::modify_staff_information()
{
	staff B;
	person *head = B.load_staff();
	person* sub;
	sub = head;
	char new_password[30];
	cout << "请输入新密码！" << endl;
	cin >> new_password;
	while (sub!=NULL)
	{
		if (strcmp(name, sub->name) == 0)
		{
			strcpy_s(sub->password, new_password);
		}
		sub = sub->next;
	}
	ofstream outfile("staff.txt",ios::beg);
	while (head!= NULL)
	{
		person*p = head;
		outfile << p->name <<endl
			<< p->password << endl;
		head = head->next;
		delete p;
	}
	outfile.close();
	strcpy_s(password, new_password);
	cout << "修改成功！2秒后返回！" << endl;
	Sleep(2000);
	system("cls");
	return;
}

