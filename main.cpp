#include <stdio.h>
#include <stdlib.h>//标准库头文件
#include <string.h>

struct student//学生结构体
{
    char name[60];//学生姓名
    char ID[7];//学生学号
    int score;//学生分数
};

int dq(struct student st[]);//文件操作
void xianshi();//主菜单
void bc(struct student st[]);//保存
void add(); //添加学生成绩
void select();//查看学生成绩
void zz();//关于作者
void chazhao();//查找
void xhcz();//查找学号
void xmcz();//查找姓名
void del();//删除
void xmsc();//删除姓名
void xhsc();//删除学号
void tj();//统计成绩
void bjg();//不及格人数
void xg();//修改
void xhxg(); //学号修改
void xmxg();//姓名修改
void bca();//保存
void fh();//返回
struct student st[300]; //定义结构体变量
int Number=0; //信息总数
void main()
{
    int choose=0;//选择数字
    FILE *fp;
    char yesorno;
	
    if((fp=fopen("student.dat","rb"))==NULL)//新建student.dat
    {
        printf("\n=========>提示：文件不存在，是否要创建一个?(y/n)\n");
        scanf("%c",&yesorno);
        if(yesorno=='y'||yesorno=='Y')
        { 
            fp=fopen("student.dat","wb");
            fclose(fp);//关闭文件保存
        }
        else
            exit(0);//正常退出
    }
    else
    {
        Number=dq(st); 
    }
    system("cls");//清屏
    while(1) 
    { 
        xianshi();
        printf("\t\t====>请选择：");
        scanf("%d",&choose);
        system("cls");
        switch(choose)
        {
		case 0: exit(0);fh();break; 
		case 1: add();fh();break;
		case 2: select();fh();break;
		case 3: chazhao();fh();break;
		case 4: del();fh();break;
		case 5: tj();fh();break;
		case 6: bjg();fh();break;
		case 7: xg();fh();break; 
		case 8:zz();fh();break;
		case 9:bca();break;
		default:break;        
        }
        fflush(stdin);//清空输入缓冲区
        getchar();//直到用户按回车为止
        system("cls");
    }
}



void bca()
{
    printf("\t=====程序在运行时已自动保存.....\n");
}

void fh()
{
    printf("\t===>按Enter键返回主菜单\n");
}

void xg() 
{
    int way=0;//选择数字
    printf("请选择修改查找方式\n");
    printf("1 按姓名查找修改\n"); 
    printf("2 按学号查找修改\n"); 
    scanf("%d",&way);
    switch(way)
    {
	case 1: xmxg();break;
	case 2: xhxg();break;
	default: printf("输入有误，结束!\n");break;    
    } 
}


void xmxg() 
{
    FILE *fp=NULL;
    char name[60];
    int i=0;
    int changeIndex=0;
    int index=0;
    printf("请输入要修改的学生姓名：");
    scanf("%s",name);
    for (i=0;i<Number;i++)
    {
        if (strcmp(name,st[i].name))
		{
			changeIndex=i; //修改索引
		}
        break;
    }
    printf("\t姓名\t学号\t成绩\n");
    printf("\t%s\t%s\t%d\n\n",st[changeIndex].name,st[changeIndex].ID,st[changeIndex].score);//输出要修改的信息
    printf("请重新输入该学生信息");
	//输入新信息
    printf("姓名：");
    scanf("%s",st[changeIndex].name);
    printf("学号：");
    scanf("%s",st[changeIndex].ID);
    printf("成绩：");
    scanf("%d",&st[changeIndex].score);
	
	
    fp=fopen("C://student.dat","wb");
    for (i=0;i<Number;i++)
    {
        fwrite(&st[i],sizeof(struct student),1,fp);
    }
    fclose(fp);
}


void xhxg()
{
    FILE *fp=NULL;
    char id[60];
    int i=0;
    int changeIndex=0;
    int index=0;
    printf("请输入要修改的学生学号：");
    scanf("%s",id);
    for (i=0;i<Number;i++)
    {
        if (strcmp(id,st[i].ID))
        {
            changeIndex=i; 
        }
        break;
    }
    printf("\t姓名\t学号\t成绩\n");
    printf("\t%s\t%s\t%d\n\n",st[changeIndex].name,st[changeIndex].ID,st[changeIndex].score);
    printf("请重新输入该学生信息");
    printf("姓名：");
    scanf("%s",st[changeIndex].name);
    printf("学号：");
    scanf("%s",st[changeIndex].ID);
    printf("成绩：");
    scanf("%d",&st[changeIndex].score);
	
	
    fp=fopen("C://student.dat","wb");
    for (i=0;i<Number;i++)
    {
        fwrite(&st[i],sizeof(struct student),1,fp);
    }
    fclose(fp);
    printf("\t=======>修改成功\n");
}

void bjg()  
{
    int i=0;
    printf("以下是不及格:\n");
    printf("\t姓名\t学号\t成绩\n");
    for (i=0;i<Number;i++)
    {
        if (st[i].score<60)
        {
            printf("\t%s\t%s\t%d\n",st[i].name,st[i].ID,st[i].score);
        }
    }
}
void tj()
{
	int i=0;
	double sum=0.0;
	for(i=0;i<Number;i++)
	{
		sum+=st[i].score;//总分
	}
	printf("全班总分为：%f\n",sum);
	printf("平均分为：%f\n",sum/Number); 
} 


void del()
{
    int n=0;
    printf("1 按姓名删除\n");
    printf("2 按学号删除\n");
    scanf("%d",&n);
    switch(n)
    {
	case 1: xmsc();break;
	case 2: xhsc();break;
    }
}


void xmsc() 
{
    FILE *fp=NULL;
    char name[60];
    int i=0;
    int j=0;
    printf("请输入要删除的学生姓名：");
    scanf("%s",name);
    for(i=0;i<Number;i++)
    {
        if(strcmp(name,st[i].name)==0) 
        {
            for (j=i;j<Number-1;j++)
            {
                st[j]=st[j+1];//删除某信息
            }
            Number--;
        }
    }
    fp=fopen("C://student.dat","wb");
    for (i=0;i<Number;i++)
    {
        fwrite(&st[i],sizeof(struct student),1,fp);
    }
    fclose(fp);
    printf("删除成功;\n");
}

void xhsc() 
{
    FILE *fp=NULL;
    char id[60];
    int i=0;
    int j=0;
    printf("请输入要删除的学生学号：");
    scanf("%s",id);
    for(i=0;i<Number;i++)
    {
        if (strcmp(id,st[i].ID)==0) 
        {
            for (j=i;j<Number-1;j++)
            {
                st[j]=st[j+1];
            }
            Number--;
        }
    }
    fp=fopen("C://student.dat","wb");
    for (i=0;i<Number;i++)
    {
        fwrite(&st[i],sizeof(struct student),1,fp);
    }
    fclose(fp);
    printf("删除成功;\n");
}

void chazhao()
{
    int n=0;
    printf("1 按姓名查找\n");
    printf("2 按学号查找\n"); 
    scanf("%d",&n);
    switch(n)
    {
    case 1: xmcz();break;
    case 2: xhcz();break;
    default: printf("输入有误，结束!\n");
		break;
    } 
}

void xhcz() 
{
    char id[7];
    int i=0;
    printf("请输入要查找学生学号:");
    scanf("%s",id);
    system("cls");
    printf("\t姓名\t学号\t成绩\n");
    for(i=0;i<Number;i++)
    {
        if (strcmp(id,st[i].ID)==0)//若二者相等
        {
            printf("\t%s\t%s\t%d\n",st[i].name,st[i].ID,st[i].score); 
        }
    }
}


void xmcz()
{ 
    char name[7];
    int i=0;
    printf("请输入要查找学生姓名:");
    scanf("%s",name);
    system("cls");
    printf("\t姓名\t学号\t成绩\n");
    for (i=0;i<Number;i++)
    {
        if (strcmp(name,st[i].name)==0)
        {
            printf("\t%s\t%s\t%d\n",st[i].name,st[i].ID,st[i].score);
        }
    }
}


void zz()
{
    printf("\t**********************************************************\n\n");
    printf("\t^^^^^^^^^        《学生成绩管理系统》           ^^^^^^^^^^\n\n");
    printf("\t^^^^^^^^^          江苏南京程序猿               ^^^^^^^^^^\n\n");
    printf("\t^^^^^^^^^            熊猫小分队				  ^^^^^^^^^^\n\n");
    printf("\t^^^^^^^^^            小熊猫修改                 ^^^^^^^^^^\n\n");
    printf("\t**********************************************************\n\n");
}


void select()
{
    int i=0;
    printf("以下是全部学生成绩\n");
    printf("\t姓名\t学号\t成绩\n");
    for(i=0;i<Number;i++)
    {
        printf("\t%s\t%s\t%d\n",st[i].name,st[i].ID,st[i].score);
    }
}


void add()
{
    int numberTemp=0;//增加学生的个数
    int i=0;
    struct student temp; 
    printf("请输入要增加学生成绩个数：");
    scanf("%d",&numberTemp);
    for(i=0;i<numberTemp;i++)
    {
        printf("输入第%d个同学信息\n",i+1);
		//输入新信息
        printf("姓名：");
        scanf("%s",temp.name);
        printf("学号：");
        scanf("%s",temp.ID);
        printf("成绩：");
        scanf("%d",&temp.score);
        st[Number++]=temp; 
        bc(&temp);
    }
    printf("添加成功\n");
}


void bc(struct student *st)
{
    FILE *fp=NULL;
    fp=fopen("student.dat","ab+");
    fwrite(st,sizeof(struct student),1,fp);
    fclose(fp);
}


int dq(struct student st[])
{
    FILE *fp=NULL;
    int i=0;
    fp=fopen("student.dat","rb");
    while(fread(&st[i],sizeof(struct student),1,fp))
		i++;
    fclose(fp);
    return i;
}


void xianshi()
{
    printf("\t*****************************************************************\n");
    printf("\t* *\n");
    printf("\t* 学生成绩管理系统 *\n");
    printf("\t* *\n");
    printf("\t* [1] 增加学生成绩          [2] 查看学生成绩      *\n");
    printf("\t* [3] 查找学生成绩          [4] 删除学生成绩      *\n");
    printf("\t* [5] 统计（总成绩和平均分）[6] 输出不及格人数    *\n");
    printf("\t* [7] 修改学生信息          [8] 关于作者          *\n");
    printf("\t* [9] 保存数据              [0] 退出系统          *\n");
    printf("\t*****************************************************************\n");
}