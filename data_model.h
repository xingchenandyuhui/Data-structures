//����ϵͳ�����ݽṹ
//��¼ע�� --���ݣ��û�
#ifndef _DATA_MODEL_H
#define _DATA_MODEL_H
//��һЩ������ͷ�ļ��������
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//�û�������Ϣ���û���������
struct User{
	char name[20];
	char password[20];
}; 
//�û������ݴ洢�ṹ�� ���Ա� 
struct UserSeq{
	//�洢������
	struct User users[200]; 
	//����
	int length; 
}; 
//����һ��������������ʼ��˳���--����һ��˳���
struct UserSeq* initSeq(){
	struct UserSeq* seq = (struct UserSeq*)malloc(sizeof(struct UserSeq));
	seq->length = 0;
	
	//��ȡ�洢�û����ݵ��ļ������ļ��д洢���û�����
	//���ص������ɹ���˳�����
	FILE* fp = fopen("users.txt","r"); 
	char name[20];
	char password[20];
	//һ��ֻ�ܶ�ȡһ������ 
	int num = fscanf(fp,"%s %s\n",&name,&password);
	while(num > 0){
		//��Ҫ����ȡ������ÿһ�е��û�����������뵽����
		//��˳����� 
		strcpy(seq->users[seq->length].name,name);
		strcpy(seq->users[seq->length].password,password);
		seq->length++;
		//��ǰһ�����ݼӵ�˳���֮�󣬶�ȡ��һ������ 
		num = fscanf(fp,"%s %s\n",&name,&password);
	} 
	fclose(fp);
	printf("�û���Ϣ��ʼ����ɣ��ɹ�������%d���û���Ϣ\n",seq->length);
	return seq;
}
 
#endif
 
