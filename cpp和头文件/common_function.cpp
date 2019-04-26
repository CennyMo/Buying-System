
#include<iostream>
#include<fstream>
#include "common_function.h"
#include"load.h"
#include"class_struct_define.h"
using namespace std;
void delete_good_number(int buy_number,int origin_number, char* type)
{
	origin_number = origin_number - buy_number;
	good *head = load_good();
	good*sub=head;
	while (sub->next != NULL)
	{
		if (strcmp(type, sub->type) == 0)
		{
			sub->number = origin_number;
		}
		sub = sub->next;
	}
	ofstream outfile("goods.txt");
	while (head!= NULL)
	{
		outfile << head->name << endl
			<< head->type << endl
			<< head->origin << endl
			<< head->number << endl
			<< head->price << endl
			<< head->ID << endl;
		good*p = head;
		head = head->next;
		delete p;
	}
	outfile.close();
	return;
}
