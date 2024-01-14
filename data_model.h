//定义系统的数据结构
//登录注册 --数据：用户
#ifndef _DATA_MODEL_H
#define _DATA_MODEL_H
//把一些常见的头文件引入进来
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//用户主体信息：用户名、密码
struct User{
	char name[20];
	char password[20];
}; 
//用户的数据存储结构了 线性表 
struct UserSeq{
	//存储的数据
	struct User users[200]; 
	//长度
	int length; 
}; 
//定义一个函数，用来初始化顺序表--返回一个顺序表
struct UserSeq* initSeq(){
	struct UserSeq* seq = (struct UserSeq*)malloc(sizeof(struct UserSeq));
	seq->length = 0;
	
	//读取存储用户数据的文件，将文件中存储的用户数据
	//加载到创建成功的顺序表中
	FILE* fp = fopen("users.txt","r"); 
	char name[20];
	char password[20];
	//一次只能读取一行数据 
	int num = fscanf(fp,"%s %s\n",&name,&password);
	while(num > 0){
		//需要将读取回来的每一行的用户名和密码加入到创建
		//的顺序表中 
		strcpy(seq->users[seq->length].name,name);
		strcpy(seq->users[seq->length].password,password);
		seq->length++;
		//将前一行数据加到顺序表之后，读取下一行数据 
		num = fscanf(fp,"%s %s\n",&name,&password);
	} 
	fclose(fp);
	printf("用户信息初始化完成，成功加载了%d个用户信息\n",seq->length);
	return seq;
}
 
#endif
 
