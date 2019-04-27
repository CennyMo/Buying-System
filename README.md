# 系统功能
![Image text](https://github.com/CennyMo/Buying-System/blob/master/img/1.png)

# 接口描述
### class_struct_define.h 
内含用户类，后台人员类以及针对用户和后台人员的成员函数，商品、订单，人员结构体的声明

### common_function.h
内含购买商品后，减去商品余量的函数声明:<br>
void delete_good_number(int,int,char*);

### load.h 
内含将文件内的商品、订单信息加载至链表的函数声明:
<br>
good* load_good(); order* load_order();

### menu.h 
内含不同的菜单显示函数声明，这些菜单显示函数是功能函数的入口点:<br>
void user_options(user&); void staff_options(staff&);
 
### register.h 
内含检验用户登录和后台人员登录的函数声明:<br>
void user_register(); void staff_register();
