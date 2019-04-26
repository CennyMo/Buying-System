#include <iostream>
#include <fstream>
#include "class_struct_define.h"
using namespace std;

good* load_good()
{

	fstream infile;
	infile.open("goods.txt");
	good *head = new good;
	head->next = NULL;
	good *p = new good;
	good *last;
	char line[30];
	char number[30];//此处由于要将number换成int型，故先设置一个char*类型的变量存储txt中的number，再用atoi函数转换成int型
	while (infile.peek() != EOF)
	{
		if (head->next == NULL)
		{
			infile.getline(line, 50);
			strcpy_s(head->name, line);
			infile.getline(line, 50);
			strcpy_s(head->type, line);
			infile.getline(line, 50);
			strcpy_s(head->origin, line);
			infile.getline(line, 50);
			strcpy_s(number, line);
			head->number = atoi(number);
			infile.getline(line, 50);
			strcpy_s(head->price, line);
			infile.getline(line, 50);
			strcpy_s(head->ID, line);
			head->next = p;
			p->next = NULL;
		}
		else
		{
			infile.getline(line, 50);
			strcpy_s(p->name, line);
			infile.getline(line, 50);
			strcpy_s(p->type, line);
			infile.getline(line, 50);
			strcpy_s(p->origin, line);
			infile.getline(line, 50);
			strcpy_s(number, line);
			p->number = atoi(number);
			infile.getline(line, 50);
			strcpy_s(p->price, line);
			infile.getline(line, 50);
			strcpy_s(p->ID, line);
			if (infile.peek() != EOF)
			{
				last = p;
				p = new good;
				last->next = p;
			}
			p->next = NULL;
		}
	}
	infile.close();
	return head; //返回头指针
}

order* load_order()
{
	fstream infile;
	infile.open("order.txt");
	order *head = new order;
	head->next = NULL;
	order *p = new order;
	order *last;
	char line[30];
	char number[30];//此处由于要将number换成int型，故先设置一个char*类型的变量存储txt中的number，再用atoi函数转换成int型
	char money[30];
	while (infile.peek() != EOF)
	{
		if (head->next == NULL)
		{
			infile.getline(line, 50);
			strcpy_s(head->client_name, line);
			infile.getline(line, 50);
			strcpy_s(head->good_name, line);
			infile.getline(line, 50);
			strcpy_s(head->good_type, line);
			infile.getline(line, 50);
			strcpy_s(number, line);
			head->good_number = atoi(number);
			infile.getline(line, 50);
			strcpy_s(money, line);
			head->amount_money = atoi(money);
			infile.getline(line, 50);
			strcpy_s(head->address, line);
			infile.getline(line, 50);
			strcpy_s(head->phone, line);
			head->next = p;
			p->next = NULL;
		}
		else
		{
			infile.getline(line, 50);
			strcpy_s(p->client_name, line);
			infile.getline(line, 50);
			strcpy_s(p->good_name, line);
			infile.getline(line, 50);
			strcpy_s(p->good_type, line);
			infile.getline(line, 50);
			strcpy_s(number, line);
			p->good_number = atoi(number);
			infile.getline(line, 50);
			strcpy_s(money, line);
			p->amount_money = atoi(money);
			infile.getline(line, 50);
			strcpy_s(p->address, line);
			infile.getline(line, 50);
			strcpy_s(p->phone, line);
			if (infile.peek() != EOF)
			{
				last = p;
				p = new order;
				last->next = p;
			}
			p->next = NULL;
		}
	}
	infile.close();
	return head; //返回头指针
}
