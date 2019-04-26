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
		cout << "��ǰû�ж�����1��󷵻أ�" << endl;
		infile.close();
		Sleep(1000);
		system("cls");
		return;
	}
	order* head = load_order();
	int label = 0;
	cout << left << setw(20) << "�û���" << left << setw(20)
		<< "��Ʒ����" << left << setw(20)
		<< "��Ʒ�ͺ�" << left << setw(20)
		<< "��������" << left << setw(20)
		<< "�ܽ��" << left << setw(20)
		<< "�ͻ���ַ" << left << setw(20)
		<< "��ϵ�绰" << endl;
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
			cout << "����ǰû�ж�����" << endl;
		}
		cout << "�����������" << endl;
		_getch();
		system("cls");
		return;
	}

void user::search_goods(user &A)//�ǵû�Ҫ���ù�����
{
	fstream infile("goods.txt");
	if (infile.peek() == EOF)
	{
		cout << "��ǰû����Ʒ��1��󷵻أ�" << endl;
		infile.close();
		Sleep(1000);
		system("cls");
		return;
	}
	good *head = load_good();
		while (1)
		{
			cout << "����������Ҫ��ѯ����Ʒ����(1)���ͺ�(2):" << endl;
			cout << "���أ�3��" << endl;
			//���Ʋ�ѯ
			int choice = _getch();
			if (choice == '1')
			{
				cout << "��������Ʒ���ƣ�" << endl;
				char name[30];
				cin >> name;
				int label = 0;//�ȳ�ʼ��һ��label������ҵ���Ʒ����label=1
				cout << left << setw(20) << "��Ʒ����" << left << setw(20)
					<< "��Ʒ�ͺ�" << left << setw(20)
					<< "����" << left << setw(20)
					<< "����" << left << setw(20)
					<< "����" << left << setw(20)
					<< "���" << '\n';
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
					cout << "δ�ܲ�ѯ����Ʒ��Ϣ����������������룬��1���أ�" << endl << endl;
					choice = _getch();
					if (choice == '1')
					{
						system("cls");
						return;
					}
				}
				else
				{
					cout << "��������Ҫ������Ʒ���ͺ�" << endl;
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
				cout << "��������Ʒ�ͺţ�" << endl;
				char type[30];
				cin >> type;
				int label = 0;//�ȳ�ʼ��һ��label������ҵ���Ʒ����
				good* head = load_good();
				cout << left << setw(20) << "��Ʒ����" << left << setw(20)
					<< "��Ʒ�ͺ�" << left << setw(20)
					<< "����" << left << setw(20)
					<< "����" << left << setw(20)
					<< "����" << left << setw(20)
					<< "���" << '\n';
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
					cout << "δ�ܲ�ѯ����Ʒ��Ϣ����������������룬��1���أ�" << endl << endl;
					choice = _getch();
					if (choice == '1')
					{
						system("cls");
						return;
					}
				}
				else
				{
					cout << "��������Ҫ������Ʒ���ͺ�" << endl;
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
				cout << "��������ȷ��������" << endl;
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
		cout << "�������������ϣ�" << endl;
		cout << "�û�����" << name << endl;
		cout << "������Ʒ���ƣ�" << good_name << endl;
		cout << "��Ʒ���ۣ�" << price << endl;
		cout << "����д���������" << endl;
		cin >> buy_number;
		if (buy_number > origin_number)
		{
			cout << "��Ʒ�������㣡��������д��" << endl;
			Sleep(2000);
			system("cls");
		}
		else
		{
			cout << "����д�绰���룺" << endl;
			cin >> phone;
			cout << "����д��ַ��" << endl;
			cin >> address;
			cout << "������ɣ�" << endl;//��ʱ��ʼ������
			delete_good_number(buy_number, origin_number, type);
			outfile << name << endl
				<< good_name << endl
				<< type << endl
				<< buy_number << endl
				<< atoi(price)*(buy_number) << endl
				<<address << endl
				<<phone<<endl;
			cout << "�Ƿ��������(����1����������0����)��" << endl;
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
					cout << "��������ȷ��������" << endl;
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
	cout << "�����������룡" << endl;
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
	cout << "�޸ĳɹ���2��󷵻أ�" << endl;
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
	return head; //����ͷָ��
}
