#ifndef _CLASS_STRUCT_DEFINE_H
#define _CLASS_STRUCT_DEFINE_H
#include <iostream>
/*******此文件用于定义用户和后台人员类，以及商品和订单结构体，并在class_function_user,class_function_staff.cpp中实现********/
using namespace std;
struct person
{
	char name[30] = { '\0' };
	char password[30] = { '\0' };
	person *next;
};
struct good
{
	char name[30] = { '\0' };
	int number;
	char ID[30] = { '\0' };
	char type[30] = { '\0' };
	char price[30] = { '\0' };
	char origin[30] = { '\0' };
	good *next;
};

struct order
{
	char good_name[30] = { '\0' };
	char good_type[30] = { '\0' };
	int good_number;
	int amount_money;
	char client_name[30] = { '\0' };
	char address[30] = { '\0' };
	char phone[30];
	order *next;
};
class user_staff
{
public:
	user_staff() {};
	~user_staff() {};
protected:
	char name[30];
	char password[30];
};
//用户类
class user: public user_staff
{
public:
	user() {};
	user (char*A, char*B);
	~user() {};
	void search_goods(user &);
	void print_all_orders();
	void modify_user_information();
	person* load_user();
	int buy(char *);
};
//工作人员类
class staff : public user_staff
{
public:
	staff() {};
	staff(char*A, char*B) ;
	~staff() {};
	void print_all_goods();
	void print_all_order();
	void add_good();
	void delete_good();
	void modify_staff_information();
	person* load_staff();
};



#endif // !_COMMON_FUN_AND_CLASS_H

