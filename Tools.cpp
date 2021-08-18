#define MAX 1000
typedef double elemtype ;

typedef struct Scores{
	elemtype math ;
	elemtype Chinese ;
	elemtype English ;
}Scores ;

typedef struct Student{
	char id[50] ;
	char name[50] ;
	Scores scores ;
}Student ;

typedef struct Box{
	Student students[MAX] ;
	int size ;
}Box ;

void Add(Box *box,FILE *fp) ;//添加功能
void Show(Box *box) ;//显示功能
void Query(Box *box) ;//查询功能
void Modify(Box *box,FILE *fp) ;//编辑功能
void Remove(Box *box,FILE *fp) ;//删除功能
void Clear(Box *box,FILE *fp) ;//清空功能

int Check(Box *box,char id[50]) ;//检查学号
bool Digits(char id[50]) ;//位数检测
bool CheckScore(elemtype score) ;//检查成绩异样
