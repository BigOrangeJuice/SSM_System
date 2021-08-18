#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include "Tools.h"

int i,j ;
int select ;
char id[50] ;

//添加功能
void Add(Box *box,FILE *fp){
	printf("请输入您想要添加的学生信息：\n") ;

	printf("学号(请输入12位有效数字)：") ;
	while(true){
		scanf("%s",box->students[box->size].id) ;
		if(Digits(box->students[box->size].id)){
			if(Check(box,box->students[box->size].id) != -1)	
				printf("该学号已存在，请重新输入！\n") ;
			else break ;
		}
		else{
			printf("格式有误，请按照规定重新输入--\n") ;
		}
	}

	printf("名字：") ;
	scanf("%s",box->students[box->size].name) ;

	printf("数学成绩(1~100)：") ;
	while(true){
		scanf("%lf",&box->students[box->size].scores.math) ;
		if(CheckScore(box->students[box->size].scores.math))	break ;
		else	printf("输入有误，请重新输入！\n") ;
	}

	printf("语文成绩(1~100)：") ;
	while(true){
		scanf("%lf",&box->students[box->size].scores.Chinese) ;
		if(CheckScore(box->students[box->size].scores.Chinese))	break ;
		else	printf("输入有误，请重新输入！\n") ;
	}

	printf("英语成绩(1~100)：") ;
	while(true){
		scanf("%lf",&box->students[box->size].scores.English) ;
		if(CheckScore(box->students[box->size].scores.English))	break ;
		else	printf("输入有误，请重新输入！\n") ;
	}

	box->size ++ ;
	printf("\n添加成功！\n") ;

	//写入文件
	fprintf(fp,"%d\t",box->size) ;
	fprintf(fp,"%s\t",box->students[box->size-1].id) ;
	fprintf(fp,"%s\t",box->students[box->size-1].name) ;
	fprintf(fp,"%.1lf\t",box->students[box->size-1].scores.math) ;
	fprintf(fp,"%.1lf\t",box->students[box->size-1].scores.Chinese) ;
	fprintf(fp,"%.1lf\n",box->students[box->size-1].scores.English) ;

}

//显示功能
void Show(Box *box){
	printf("序列\t学号\t\t姓名\t数学\t语文\t英语\n") ;
	for(i = 0;i < box->size;++ i){
		printf("%d\t",i+1) ;
		printf("%s\t",box->students[i].id) ;
		printf("%s\t",box->students[i].name) ;
		printf("%.1lf\t",box->students[i].scores.math) ;
		printf("%.1lf\t",box->students[i].scores.Chinese) ;
		printf("%.1lf\n",box->students[i].scores.English) ;
	}
}

//查询功能
void Query(Box *box){
	printf("请输入您想要查询的学生的对应学号：") ;
	scanf("%s",id) ;
	i = Check(box,id) ;
	if(i == -1)	printf("抱歉，暂无该生信息--\n") ;
	else{
		printf("序列\t学号\t\t姓名\t数学\t语文\t英语\n") ;
		printf("%d\t",i+1) ;
		printf("%s\t",box->students[i].id) ;
		printf("%s\t",box->students[i].name) ;
		printf("%.1lf\t",box->students[i].scores.math) ;
		printf("%.1lf\t",box->students[i].scores.Chinese) ;
		printf("%.1lf\n",box->students[i].scores.English) ;
	}
}

//编辑功能
void Modify(Box *box,FILE *fp){
	printf("请输入您想要编辑的学生的对应学号：") ;
	scanf("%s",id) ;
	i = Check(box,id) ;
	if(i == -1)	printf("抱歉，暂无该生信息--\n") ;
	else{
		printf("该操作不可逆，您是否继续--\n") ;
		printf("  1 - 继续 | 2 - 取消\n") ;
		scanf("%d",&select) ;
		switch(select){
		case 1:
			printf("学号(请输入12位有效数字)：") ;
			while(true){
				scanf("%s",id) ;
				if(!Digits(id)){
					printf("输入有误，请重新输入--\n") ;
					continue ;
				}
				for(j = 0;j < box->size;++ j){
					if(strcmp(box->students[j].id,id) == 0) break ;
				}
				if(j == box->size){
					strcpy(box->students[i].id,id) ;
					break ;
				}
				else{
					printf("该学号已存在，请重新输入--\n") ;
				}
			}
			printf("名字：") ;
			scanf("%s",box->students[i].name) ;

			printf("数学成绩(1~100)：") ;
			while(true){
				scanf("%lf",&box->students[i].scores.math) ;
				if(CheckScore(box->students[i].scores.math))	break ;
				else	printf("输入有误，请重新输入！\n") ;
			}

			printf("语文成绩(1~100)：") ;
			while(true){
				scanf("%lf",&box->students[i].scores.Chinese) ;
				if(CheckScore(box->students[i].scores.Chinese))	break ;
				else	printf("输入有误，请重新输入！\n") ;
			}

			printf("英语成绩(1~100)：") ;
			while(true){
				scanf("%lf",&box->students[i].scores.English) ;
				if(CheckScore(box->students[i].scores.English))	break ;
				else	printf("输入有误，请重新输入！\n") ;
			}
			printf("修改成功！\n") ;

			//写入文件
			fclose(fp) ;
			fp = fopen("SSM_System.txt","w") ;
			fputs("序号\t学号\t\t姓名\t数学\t语文\t英语\n",fp) ;
			for(i = 0;i < box->size;++ i){
				fprintf(fp,"%d\t",i+1) ;
				fprintf(fp,"%s\t",box->students[i].id) ;
				fprintf(fp,"%s\t",box->students[i].name) ;
				fprintf(fp,"%.1lf\t",box->students[i].scores.math) ;
				fprintf(fp,"%.1lf\t",box->students[i].scores.Chinese) ;
				fprintf(fp,"%.1lf\n",box->students[i].scores.English) ;
			}
			break ;
		case 2:
			break ;
		default:
			printf("输入有误，请重试--\n") ;
			break ;
		}
	}
}

//删除功能
void Remove(Box *box,FILE *fp){
	printf("请输入您想要删除的学生的对应学号：") ;
	scanf("%s",id) ;
	i = Check(box,id) ;
	if(i == -1)	printf("暂无该生信息--\n") ;
	else{
		printf("该操作不可逆，您是否继续--\n") ;
		printf("  1 - 继续 | 2 - 取消\n") ;
		scanf("%d",&select) ;
		switch(select){
		case 1:
			for(i;i < box->size;++ i){
				box->students[i] = box->students[i+1] ;
			}
			box->size -- ;
			printf("删除成功！") ;

			//写入文件
			fclose(fp) ;
			fp = fopen("SSM_System.txt","w") ;
			fputs("序号\t学号\t\t姓名\t数学\t语文\t英语\n",fp) ;
			for(i = 0;i < box->size;++ i){
				fprintf(fp,"%d\t",i+1) ;
				fprintf(fp,"%s\t",box->students[i].id) ;
				fprintf(fp,"%s\t",box->students[i].name) ;
				fprintf(fp,"%.1lfd\t",box->students[i].scores.math) ;
				fprintf(fp,"%.1lf\t",box->students[i].scores.Chinese) ;
				fprintf(fp,"%.1lf\n",box->students[i].scores.English) ;
			}

			break ;
		case 2:
			break ;
		default:
			printf("输入有误，请重试--\n") ;
			break ;
		}
	}
}

//清空功能
void Clear(Box *box,FILE *fp){
	printf("您是否确定要执行此操作？\n") ;
	printf("1 - 确定 | 2 - 取消\n") ;
	scanf("%d",&select) ;
	switch(select){
	case 1:
		box->size = 0 ;
		printf("清空成功！") ;

		//写入文件
		fclose(fp) ;
		fp = fopen("SSM_System.txt","w") ;
		fputs("序号\t学号\t\t姓名\t数学\t语文\t英语\n",fp) ;
			
	case 2:
		break ;
	default:
		printf("输入有误，请重试--\n") ;
		break ;
	}
}

//学号查重
int Check(Box *box,char id[50]){
	for(i = 0;i < box->size;++ i){
		if(!strcmp(box->students[i].id,id))	return i ;
	}
	return -1 ;
}

//位数检测
bool Digits(char id[50]){
	unsigned i ;
	for(i = 0;i < strlen(id);++ i){
		if(id[i] >= '0' && id[i] <= '9')	continue ;
		return false ;
	}
	return strlen(id) == 12 ;
}

//检查成绩异样
bool CheckScore(elemtype score){
	return score >= 0 ? score <= 100 ? true : false : false ;
}
