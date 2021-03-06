#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <Windows.h>
#include "Menu.h"
#include "Tools.h"

int main(){

	//初始化
	Box box ;
	box.size = 0 ;

	//随时写入文档
	FILE *fp ;
	if((fp = fopen("SSM_System.txt","w")) == NULL){
		printf("cannot open file\n") ;
		exit(0) ;
	}
	fputs("序号\t学号\t\t姓名\t数学\t语文\t英语\n",fp) ;
	//主界面
	ShowMenu() ;
	//选择
	int key ;
	while(true){
		printf("请输入您要进行对应操作的序号：") ;
		scanf("%d",&key) ;
		switch(key){
		case 1://添加功能
			Add(&box,fp) ;
			system("pause") ;
			system("cls") ;
			ShowMenu() ;
			break ;
		case 2://显示功能
			Show(&box) ;
			system("pause") ;
			system("cls") ;
			ShowMenu() ;
			break ;
		case 3://查询功能
			Query(&box) ;
			system("pause") ;
			system("cls") ;
			ShowMenu() ;
			break ;
		case 4://编辑功能
			Modify(&box,fp) ;
			system("pause") ;
			system("cls") ;
			ShowMenu() ;
			break ;
		case 5://删除功能
			Remove(&box,fp) ;
			system("pause") ;
			system("cls") ;
			ShowMenu() ;
			break ;
		case 6://清空功能
			Clear(&box,fp) ;
			system("pause") ;
			system("cls") ;
			ShowMenu() ;
			break ;
		case 0://退出系统
			printf("感谢您的使用，再见！\n") ;
			return 0 ;
			break ;
		default:
			printf("您的输入有误，请按照规定重新输入！\n") ;
			break ;
		}
	}
	fclose(fp) ;
	return 0 ;
}
