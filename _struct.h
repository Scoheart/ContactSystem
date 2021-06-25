#ifndef _STRUCT_H
#define _STRUCT_H

// 结构体成员 字符数组的大小及总大小
#define NAME_SIZE 30
#define COMPANY_SIZE 30
#define HOME_PHONE_SIZE 30
#define MOBILE_PHONE_SIZE 30
#define GROUPS_SIZE 30
#define EMAIL_SIZE 30
#define QQ_SIZE 30
#define CONTACT_SIZE 100
#define STRUCT_SIZE sizeof(struct contacts)

// 一些打印省略
#define ALREADY_EXISTS "THE CONTACT ALREADY EXISTS!\n"
#define BLANK_RECORD "NO CONTACT RECORD!\n"
#define BACK_HOME "\nPRESS ANY KEY TO BACK HOME!"
#define BACK_SEARCH_HONE "\nPRESS ANY KEY TO BACK SEARCH HOME!"
#define CANCEL "CANCEL %s!\n"
#define CONTACT_INFORMATON_DIRECTORY "NUM |NAME          |COMPANY       |HOME_PHONE    |MOBILE_PHONE  |GROUPS        |EMAIL                   |QQ            |\n"
#define DATA i+1, contact[i].name, contact[i].company, contact[i].home_phone, contact[i].mobile_phone, contact[i].groups, contact[i].email, contact[i].qq  
#define EXIT "\nPRESS ANY KEY TO EXIT!"
#define ENTER "PLEASE ENTER A CONTACT %s:"
#define ENTER_NAME "PLEASE ENTER A CONTACT NAME:"
#define FIND "FIND THE CONTACT, %s？(Y/N):"
#define FORMAT "%3d. %-15s%-15s%-15s%-15s%-15s%-25s%-15s\n"
#define HORIZONTAL_RULE              "------------------------------------------------------------------------------------------------------------------------\n"
#define INVALID "INVALID ENTER!\n"
#define NOT_FOUND "SORRY, NOT FOUND!\n"
#define PAGE "-------------------------------------------------------PAGE %d-----------------------------------------------------------\n"
#define SUCCESSFULLY "\"%s\" %s SUCCESSFULLY!\n"

// 结构体定义
struct contacts {
	char name[NAME_SIZE];
	char company[COMPANY_SIZE];
	char home_phone[HOME_PHONE_SIZE];
	char mobile_phone[MOBILE_PHONE_SIZE];
	char groups[GROUPS_SIZE];
	char email[EMAIL_SIZE];
	char qq[QQ_SIZE];
} contact[CONTACT_SIZE];

#endif