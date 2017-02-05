#include <string.h>

{
};

void main()
{
    FILE *fp;
    char yesorno;
	
    {
        scanf("%c",&yesorno);
        if(yesorno=='y'||yesorno=='Y')
        { 
            fp=fopen("student.dat","wb");
        }
        else
    }
    else
    {
        Number=dq(st); 
    }
    while(1) 
    { 
        xianshi();
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
        system("cls");
    }
}



void bca()
{
}

void fh()
{
}

void xg() 
{
    scanf("%d",&way);
    switch(way)
    {
	case 1: xmxg();break;
	case 2: xhxg();break;
    } 
}


void xmxg() 
{
    FILE *fp=NULL;
    char name[60];
    int i=0;
    int changeIndex=0;
    int index=0;
    scanf("%s",name);
    for (i=0;i<Number;i++)
    {
        if (strcmp(name,st[i].name))
		{
		}
        break;
    }
    scanf("%s",st[changeIndex].name);
    scanf("%s",st[changeIndex].ID);
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
    scanf("%s",id);
    for (i=0;i<Number;i++)
    {
        if (strcmp(id,st[i].ID))
        {
            changeIndex=i; 
        }
        break;
    }
    printf("\t%s\t%s\t%d\n\n",st[changeIndex].name,st[changeIndex].ID,st[changeIndex].score);
    scanf("%s",st[changeIndex].name);
    scanf("%s",st[changeIndex].ID);
    scanf("%d",&st[changeIndex].score);
	
	
    fp=fopen("C://student.dat","wb");
    for (i=0;i<Number;i++)
    {
        fwrite(&st[i],sizeof(struct student),1,fp);
    }
    fclose(fp);
}

void bjg()  
{
    int i=0;
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
	}
} 


void del()
{
    int n=0;
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
    scanf("%s",name);
    for(i=0;i<Number;i++)
    {
        if(strcmp(name,st[i].name)==0) 
        {
            for (j=i;j<Number-1;j++)
            {
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
}

void xhsc() 
{
    FILE *fp=NULL;
    char id[60];
    int i=0;
    int j=0;
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
}

void chazhao()
{
    int n=0;
    scanf("%d",&n);
    switch(n)
    {
    case 1: xmcz();break;
    case 2: xhcz();break;
		break;
    } 
}

void xhcz() 
{
    char id[7];
    int i=0;
    scanf("%s",id);
    system("cls");
    for(i=0;i<Number;i++)
    {
        {
            printf("\t%s\t%s\t%d\n",st[i].name,st[i].ID,st[i].score); 
        }
    }
}


void xmcz()
{ 
    char name[7];
    int i=0;
    scanf("%s",name);
    system("cls");
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
    printf("\t**********************************************************\n\n");
}


void select()
{
    int i=0;
    for(i=0;i<Number;i++)
    {
        printf("\t%s\t%s\t%d\n",st[i].name,st[i].ID,st[i].score);
    }
}


void add()
{
    int i=0;
    struct student temp; 
    scanf("%d",&numberTemp);
    for(i=0;i<numberTemp;i++)
    {
        scanf("%s",temp.name);
        scanf("%s",temp.ID);
        scanf("%d",&temp.score);
        st[Number++]=temp; 
        bc(&temp);
    }
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
    printf("\t* *\n");
    printf("\t*****************************************************************\n");
}
