//定义学生数据结构体
struct scorenode
{
	int number;			 //学生学号
	char name[10];		 //学生姓名
	float chinese;		//语文成绩
	float maths;		//数学成绩
	float english;	//英语成绩
	struct scorenode *next; //下一结点指针
};           //注意：定义结构体时不要忘了最后大括号外的分号

#include<malloc.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define LEN sizeof(struct scorenode)      //sizeof括号里可以是数据类型也可以是变量

typedef struct scorenode score ;     //自定义数据类型


int n=0,k;    //定义全局变量,n用以计数，k用于标记

//菜单函数
int menu(int k)
{
	int i;
	printf("\t\t\t\t学生成绩管理系统\n");
	printf("\n");
	for(i=0;i<100;i++)
	printf("*");
	printf("\n1 新建学生的成绩\t\t\t2 显示学生的成绩\t\t\t3 查询学生的成绩\n");
	printf("4 添加学生的成绩\t\t\t5 删除学生的成绩\t\t\t6 学生成绩排序\n");
	printf("7 保存学生的成绩\t\t\t8 统计学生的成绩\t\t\t9 读取学生的成绩\n");
	for(i=0;i<100;i++)
	printf("*");
	printf("\n欢迎进入学生成绩管理系统，请选择您所要的操作（选择(0)退出）：");
	scanf("%d",&k);
	getchar();
	return k;
}

//链表创建函数
score *creatlink()
{
	score *head,*p1,*p2,*p3,*max;//p1指向新添加的结构体，p2是尾结点指针，p3是备用指针（在该函数体内的查找有无重复学号和排序函数段中起作用）
	int i,j,num;
	char t[10];
	float fen;
	n=0;
	head=p1=p2=p3=(score *)malloc(LEN);  //开辟新单元
	printf("请输入学生资料，输0退出！\n");
repeat1:                              //事实上repeat1只有输入第一个数据时才会经过
	printf("请输入学生学号（学号应大于0）：");                       //输入学生学号
	scanf("%d",&p1->number);
	while(p1->number<0)
	{
		getchar();   //吸收上一步输入数字时的空格符或回车符
		printf("输入错误，请重新输入学生学号：");
		scanf("%d",&p1->number);
	}
	if(p1->number==0)  //当输入学号为0时，转到末尾，结束创建链表
	goto end;

	printf("请输入学生姓名：");                                   //输入学生姓名
	scanf("%s",p1->name);

	printf("请输入语文成绩：");                                  //输入语文成绩
	scanf("%f",&p1->chinese);
	while(p1->chinese<0||p1->chinese>100)  //语文成绩应在0~100以内
	{
		getchar();
		printf("输入错误，请重新输入语文成绩：");
		scanf("%f",&p1->chinese);
	}

	printf("请输入数学成绩：");                                  //输入数学成绩
	scanf("%f",&p1->maths);
	while(p1->maths<0||p1->maths>100)  //数学成绩应在0~100以内
	{
		getchar();
		printf("输入错误，请重新输入数学成绩：");
		scanf("%f",&p1->maths);
	}

	printf("请输入英语成绩：");                                  //输入英语成绩
	scanf("%f",&p1->english);
	while(p1->english<0||p1->english>100)  //英语成绩应在0~100以内
	{
		getchar();
		printf("输入错误，请重新输入英语成绩：");
		scanf("%f",&p1->english);
	}

	head=NULL;//相当于初始化head
	while(p1->number!=0)               //若输入第二、三、四、…个结构体，就会直接从该while循环开始，不会再去到上面
	{
		n+=1;  //用来标记新添加的p1是链表中第几个数
		if(n==1)
		head=p1;//若p1是第一个数据，则使head、p1指向同一结构体，即使此时p1成为头结点
		else
		p2->next=p1;//若p1不是第一个数据，那么此时的p2是上一轮中添加的p1，现在把上一轮循环中的p1（即上一轮中的最后一个结点）的next指向新添加的p1
		p2=p1;//使p2总指向新添加的结构体（p2是尾结点指针）
		p1=(score *)malloc(LEN);                         //使p1指向新开辟的单元
		//97~103行既承接上文（97以上的代码）同时又可以处理第二、三、四、…次进入此while循环时上一轮后半段添加的p1

		printf("请输入学生资料，输0退出！\n");
repeat2:printf("请输入学生学号（学号应大于0）：");
		scanf("%d",&p1->number);
		while(p1->number<0)
		{
			getchar();   //吸收上一步输入数字时的空格符或回车符
			printf("输入错误，请重新输入学生学号：");
			scanf("%d",&p1->number);
		}
		if(p1->number==0)  //当输入学号为0时，转到末尾，结束创建链表
		goto end;
		else
		{
			p3=head;
			if(n>0)
			{
				for(i=0;i<n;i++)
				{
					if(p1->number!=p3->number)
					p3=p3->next;
					else
					{
						printf("学号重复，请重输！\n");
						goto repeat2;
					}
				}
			}
		}//116~132行的else用于排查新添加的学生学号是否与以往有重复

		printf("请输入学生姓名：");                                   //输入学生姓名
		scanf("%s",p1->name);

		printf("请输入语文成绩：");                                  //输入语文成绩
		scanf("%f",&p1->chinese);
		while(p1->chinese<0||p1->chinese>100)  //语文成绩应在0~100以内
		{
			getchar();
			printf("输入错误，请重新输入语文成绩：");
			scanf("%f",&p1->chinese);
		}

		printf("请输入数学成绩：");                                  //输入数学成绩
		scanf("%f",&p1->maths);
		while(p1->maths<0||p1->maths>100)  //数学成绩应在0~100以内
		{
			getchar();
			printf("输入错误，请重新输入数学成绩：");
			scanf("%f",&p1->maths);
		}

		printf("请输入英语成绩：");                                  //输入英语成绩
		scanf("%f",&p1->english);
		while(p1->english<0||p1->english>100)  //英语成绩应在0~100以内
		{
			getchar();
			printf("输入错误，请重新输入英语成绩：");
			scanf("%f",&p1->english);
		}
	}//这个大括号属于95行的while

end:p3=head;
	for(i=1;i<n;i++)  //这两个for循环用于控制交换比较法的比较次数，具体：外循环控制轮数，内循环控制每轮的次数
	{
		for(j=i+1;j<=n;j++)
		{
			max=p3;
			p3=p3->next;       //使max是前一个，p3是后一个
			if(max->number>p3->number) //目的则是将链表中的学号从小到大排序，创建一个有序的链表
			{
				num=max->number;  //交换学号
				max->number=p3->number;
				p3->number=num;

				strcpy(t,max->name);
				strcpy(max->name,p3->name);
				strcpy(p3->name,t);

				fen=max->chinese;
				max->chinese=p3->chinese;
				p3->chinese=fen;

				fen=max->maths;
				max->maths=p3->maths;
				p3->maths=fen;

				fen=max->english;
				max->english=p3->english;
				p3->english=fen;
			}
		}
		p3=head;//由于交换法的比较位置从第一个开始，所以每轮要是p3重新指向头结点
	}
	p2->next=NULL;  //在确认不再添加新结点时才把p2->next指向NULL
	printf("输入的学生数位：%d个！\n",n);
	return head;
}

//链表输出函数
void printf_(score *head)
{
	score *p;
	if(head==NULL)  //这里不能用n==0作条件，因为链表读取函数那边的原因 
	printf("\n没有任何学生成绩！\n");
	else
	{
		printf("-----------------------------------------\n");
		printf("|学号\t|姓名\t|语文\t|数学\t|英语\t|\n");
		printf("-----------------------------------------\n");           //制表

		p=head;
		while(p!=NULL)
		{
			printf("|%04d\t|%s\t|%.1f\t|%.1f\t|%.1f\t|\n",p->number,p->name,p->chinese,p->maths,p->english);
			printf("-----------------------------------------\n");
			p=p->next;
		}
		printf("共%d个学生信息。\n",n);

	}
}

//链表查找函数
score *search(score *head)
{
	score *p1;
	int num;
	if(head==NULL)
	{
		printf("\n当前没有学生成绩！请先新建一个学生成绩表！\n");
		return (head);       //对于函数来说，返回函数值即意味退出这段函数，所以在一段函数内的不同层中可以有多个return
	}
	printf("\n请输入要查询的学生学号：");
	scanf("%d",&num);
	while(num!=0)
	{
		printf("-----------------------------------------\n");
		printf("|学号\t|姓名\t|语文\t|数学\t|英语\t|\n");
		printf("-----------------------------------------\n");

		p1=head;
		while(p1->number!=num&&p1->next!=NULL)//跳出循环时：情况一：p1->number==num;情况二：p1是尾结点且p1->number==num;情况三：p1是尾结点但p1->number!=num
		{
			p1=p1->next;
		}
		if(p1->number==num)
		{
			printf("|%04d\t|%s\t|%.1f\t|%.1f\t|%.1f\t|\n",p1->number,p1->name,p1->chinese,p1->maths,p1->english);
			printf("-----------------------------------------\n");
		}
		else
		{
			printf("没有找到该学生数据！");
		}
		printf("请输入要查询的学生学号：");
		scanf("%d",&num);
	}
	return (head);
}

//链表添加函数
score *add(score *head,score *stu)
{
	score *p0,*p1,*max;  //p0是stu的备份，p1用于遍历循环中，max用于排序
	int i,j,num;
	float fen;
	char t[10];
	stu=(score *)malloc(LEN);
	printf("\n输入要增加的学生的资料！");
repeat4:
	printf("请输入学生学号（学号应大于0）：");
	scanf("%d",&stu->number);
	while(stu->number<0)
	{
		getchar();
		printf("输入错误，请重新输入学生学号：");
		scanf("%d",&stu->number);
	}
	if(stu->number==0)
	goto end2;
	else      //253~269行用于检测新添加的学号是否已经存在
	{
		if(n>0)
		{
			p1=head;
			for(i=0;i<n;i++)   //用n控制比较次数
			{
				if(stu->number!=p1->number)
				p1=p1->next;
				else
				{
					printf("学号重复，请重输！\n");
					goto repeat4;
				}
			}
		}
	}
	printf("输入学生姓名：");                                        //输入学生姓名
	scanf("%s",stu->name);

		printf("请输入语文成绩：");                                  //输入语文成绩
	scanf("%f",&stu->chinese);
	while(stu->chinese<0||stu->chinese>100)  //语文成绩应在0~100以内
	{
		getchar();
		printf("输入错误，请重新输入语文成绩：");
		scanf("%f",&stu->chinese);
	}

	printf("请输入数学成绩：");                                  //输入数学成绩
	scanf("%f",&stu->maths);
	while(stu->maths<0||stu->maths>100)  //数学成绩应在0~100以内
	{
		getchar();
		printf("输入错误，请重新输入数学成绩：");
		scanf("%f",&stu->maths);
	}

	printf("请输入英语成绩：");                                  //输入英语成绩
	scanf("%f",&stu->english);
	while(stu->english<0||stu->english>100)  //英语成绩应在0~100以内
	{
		getchar();
		printf("输入错误，请重新输入英语成绩：");
		scanf("%f",&stu->english);
	}

   	score *p2;                                                 //把新节点添加进链表

	if(head==NULL) //在主函数定义head时为其赋了NULL值，所以链表没有结点时head==NULL
	{
		head=stu;
	}               //链表为空的这一分类不可以与底下的分类并作一段
	else
	{
		p1=head;
		while(p1!=NULL)
		{
			p2=p1;
			p1=p1->next;
		}                //当跳出循环时，p2是尾结点，p1是NULL
		p2->next=stu;
	}
	stu->next=NULL;
	n++;     //当p1==NULL、即p1的上一个是尾结点时，使p1指向新结点，同时将新结点的next指向NULL

//注意此add函数仅能添加一个结点，此处未设循环

	p1=head;                                                  //重新排序链表
	for(i=1;i<n;i++)
	{
		for(j=i+1;j<=n;j++)
		{
			max=p1;
			p1=p1->next;
			if(max->number>p1->number)         //注意只是各结点之间的数据交换，但各结点之间的顺序使不变的，即每个结点的next指向的地址不会变
			{
				num=p1->number;
				p1->number=max->number;
				max->number=num;

				strcpy(t,p1->name);
				strcpy(p1->name,max->name);
				strcpy(max->name,t);

				fen=max->chinese;
				max->chinese=p1->chinese;
				p1->chinese=fen;

				fen=max->maths;
				max->maths=p1->maths;
				p1->maths=fen;

				fen=max->english;
				max->english=p1->english;
				p1->english=fen;

			}
		}
		p1=head;
	}

end2:
	printf("现在的学生数为：%d个！\n",n);
	return (head);
}

//链表删除函数
score *dele(score *head)
{
	score *p1,*p2;
	int num;
	if(head==NULL)
	{
		printf("\n当前没有任何学生资料！请先建立一个学生成绩表！\n");
		return (head);
	}

	printf("\n请输入要删除的学生的学号：");
	scanf("%d",&num);
	while(num!=0)
	{
		p1=head;
		while(p1->number!=num&&p1->next!=NULL)
		{
			p2=p1;
			p1=p1->next;
		}
		if(p1->number==num)
		{
			if(p1==head)
			{
				head=p1->next;
			}
			else
			{
				p2->next=p1->next;  //这一条可以兼顾p1是尾结点和p1不是尾结点的情况，因为跳出while循环时p1至多是尾结点，不会是NULL

			}
			n--;
			printf("\n学生%04d删除成功！输入0退出！",p1->number);
			 //注意p2->next不是始终指向指针变量p1，而是始终指向原p1所指向的单元；所以若要使某指针变量如p2成为尾结点不能通过p1=NULL实现，必须用p2->next=NULL
		}
		else
		{
			printf("\n没有该学生资料！请重输！\n");
		}


		printf("\n请输入要删除的学生的学号：");
		scanf("%d",&num);
	}

 	printf("现在的学生数为：%d个！\n",n);
	return (head);
}

//链表排序函数
score* sort_data(score *head)
{
	score *p1,*max;
	int i,j,k,num;
	float fen;
	char t[10];

	if(head==NULL)
	{
		printf("\n当前没有任何学生资料！\n");
		return (head);
	}

    for(i=0;i<100;i++)
    printf("*");
    printf("\n1 按照学号排序\t2 按照姓名排序\t3 按照语文成绩排序\t4 按照数学成绩排序\t5 按照英语成绩排序\n");
    for(i=0;i<100;i++)
    printf("*");

    printf("\n请选择操作：");
    scanf("%d",&k);
    getchar();
    switch(k)
    {
        case 0: return (head);
        case 1:
                p1=head;
                for(i=1;i<n;i++)
                {
                            for(j=i+1;j<=n;j++)
                            {
                                max=p1;
                                p1=p1->next;
                                if(max->number>p1->number)
                                {
                                    num=p1->number;
                                        p1->number=max->number;
                                    max->number=num;

                                    strcpy(t,p1->name);
                                    strcpy(p1->name,max->name);
                                    strcpy(max->name,t);

                                    fen=max->chinese;
                                    max->chinese=p1->chinese;
                                    p1->chinese=fen;

                                    fen=max->maths;
                                    max->maths=p1->maths;
                                    p1->maths=fen;

                                    fen=max->english;
                                    max->english=p1->english;
                                    p1->english=fen;

                                }
                            }
                            p1=head;
                        }
                printf_(head);
                break;
        case 2:
                p1=head;
                for(i=1;i<n;i++)
                {
                            for(j=i+1;j<=n;j++)
                            {
                                max=p1;
                                p1=p1->next;
                                if(strcmp(max->name,p1->name)>0)
                                {
                                    num=p1->number;
                                    p1->number=max->number;
                                    max->number=num;

                                    strcpy(t,p1->name);
                                    strcpy(p1->name,max->name);
                                    strcpy(max->name,t);

                                    fen=max->chinese;
                                    max->chinese=p1->chinese;
                                    p1->chinese=fen;

                                    fen=max->maths;
                                    max->maths=p1->maths;
                                    p1->maths=fen;

                                    fen=max->english;
                                    max->english=p1->english;
                                    p1->english=fen;
                                }
                            }
                            p1=head;
                        }
                printf_(head);
                break;
        case 3:
                p1=head;
                for(i=1;i<n;i++)
                {
                            for(j=i+1;j<=n;j++)
                            {
                                max=p1;
                                p1=p1->next;
                                if(max->chinese>p1->chinese)
                                {
                                    num=p1->number;
                                    p1->number=max->number;
                                    max->number=num;

                                    strcpy(t,p1->name);
                                    strcpy(p1->name,max->name);
                                    strcpy(max->name,t);

                                    fen=max->chinese;
                                    max->chinese=p1->chinese;
                                    p1->chinese=fen;

                                    fen=max->maths;
                                    max->maths=p1->maths;
                                    p1->maths=fen;

                                    fen=max->english;
                                    max->english=p1->english;
                                    p1->english=fen;
                                }
                            }
                            p1=head;
                        }
                printf_(head);
                break;
        case 4:
                p1=head;
                for(i=1;i<n;i++)
                {
                            for(j=i+1;j<=n;j++)
                            {
                                max=p1;
                                p1=p1->next;
                                if(max->maths>p1->maths)
                                {
                                    num=p1->number;
                                    p1->number=max->number;
                                    max->number=num;

                                    strcpy(t,p1->name);
                                    strcpy(p1->name,max->name);
                                    strcpy(max->name,t);

                                    fen=max->chinese;
                                    max->chinese=p1->chinese;
                                    p1->chinese=fen;

                                    fen=max->maths;
                                    max->maths=p1->maths;
                                    p1->maths=fen;

                                    fen=max->english;
                                    max->english=p1->english;
                                    p1->english=fen;
                                }
                            }
                            p1=head;
                        }
                printf_(head);
                break;
        case 5:
                p1=head;
                for(i=1;i<n;i++)
                {
                            for(j=i+1;j<=n;j++)
                            {
                                max=p1;
                                p1=p1->next;
                                if(max->english>p1->english)
                                {
                                    num=p1->number;
                                    p1->number=max->number;
                                    max->number=num;

                                    strcpy(t,p1->name);
                                    strcpy(p1->name,max->name);
                                    strcpy(max->name,t);

                                    fen=max->chinese;
                                    max->chinese=p1->chinese;
                                    p1->chinese=fen;

                                    fen=max->maths;
                                    max->maths=p1->maths;
                                    p1->maths=fen;

                                    fen=max->english;
                                    max->english=p1->english;
                                    p1->english=fen;
                                }
                            }
                            p1=head;
                        }
                printf_(head);
                break;
        default:printf("输入错误！请重试！\n");
    }

    return (head);
}

//成绩保存函数
int save(score *head)
{
    FILE *fp; //只要系统用到一个文件，就会开辟一个结构体单元用以存放文件信息；而这个单元不用变量名标识，而是通过指向该单元的指针变量访问。这个指针变量叫做文件型指针变量。FILE就是文件型变量的关键字 
    score *p1;
    char filepn[20];  //用来储存文件路径及文件名
    printf("请输入文件路径及文件名：");
    scanf("%s",filepn);
    if((fp=fopen(filepn,"w+"))==NULL)  //fopen()是文件打开函数；这里以读写方式打开文件，若文件存在就删去原文件，重新创建并保存 
    {
        printf("文件打开失败！\n");
        return (0);
    }
    fprintf(fp,"            学生成绩管理系统            ");  //格式数据写入函数fprintf（文件型指针，格式控制，写入列表） 
    fprintf(fp,"\n");
    fprintf(fp,"-----------------------------------------\n");
    fprintf(fp,"|学号\t|姓名\t|语文\t|数学\t|英语\t|\n");
    fprintf(fp,"-----------------------------------------\n");
//注意该段函数设计为即使链表中没有学生资料也可以保存成功（仅保存表头，即665~669行） 

    p1=head;
    while(p1!=NULL)
    {
            fprintf(fp,"|%04d\t|%s\t|%.1f\t|%.1f\t|%.1f\t|\n",p1->number,p1->name,p1->chinese,p1->maths,p1->english);
			fprintf(fp,"-----------------------------------------\n");
			p1=p1->next;
    }

    fclose(fp);  //fclose（文件型指针）为文件关闭函数 
    printf("文件已经保存！\n");
    return 0;

}

//成绩统计函数
score *statistics(score *head)
{
	float sum1,sum2,sum3,ave1,ave2,ave3,max,min;
	char maxname[10],minname[10];
	score *p;
	int x,y=0,i=0;  //x用于分类；y用于计数
	
	printf("\n***********************************************************************\n");
	printf("1 个人总分和平均分\t2 单科平均分\t3 总分最高和总分最低\t0 退出\n");
	printf("***********************************************************************\n");
	printf("请选择操作：");
	scanf("%d",&x);
	getchar();
	
	p=head;
	switch(x)
	{
		case 0:break;
		case 1:                              //求个人总分与分均分 
			if(head==NULL)
			{
				printf("\n没有任何学生资料！\n");
				return 0;
			} 
			
			printf("---------------------------------------------------------\n");
			printf("|学号\t|姓名\t|语文\t|数学\t|英语\t|总分\t|平均分\t|\n");
			printf("---------------------------------------------------------\n");
			
			while(p!=NULL)
			{
				sum1=p->chinese+p->maths+p->english;
				ave1=sum1/3;
				printf("|%04d\t|%s\t|%.1f\t|%.1f\t|%.1f\t|%.1f\t|%.1f\t|\n",p->number,p->name,p->chinese,p->maths,p->english,sum1,ave1);
				printf("---------------------------------------------------------\n");
				p=p->next;
			}
			break;
		case 2:                         //求各科平均分 
			if(head==NULL)
			{
				printf("\n没有任何学生资料！\n");
				return 0;
			} 
			
			printf("-----------------------------------------\n");
			printf("|学号\t|姓名\t|语文\t|数学\t|英语\t|\n");
			printf("-----------------------------------------\n");
			
			while(p!=NULL)
			{
				sum1+=p->chinese;
				sum2+=p->maths;
				sum3+=p->english;
				y++;
				printf("|%04d\t|%s\t|%.1f\t|%.1f\t|%.1f\t|\n",p->number,p->name,p->chinese,p->maths,p->english);
				printf("-----------------------------------------\n");
				p=p->next;
			}
			ave1=sum1/y;  //这里使用y计数使为了防止若别的部分中n出错不会影响到这里的平均分计算 
			ave2=sum2/y;
			ave3=sum3/y;
			printf("|平均分\t\t|%.1f\t|%.1f\t|%.1f\t|\n",ave1,ave2,ave3);
			printf("-----------------------------------------\n");
			break;
		case 3:                     //求总分最高和总分最低
			if(head==NULL)
			{
				printf("\n没有任何学生资料！\n");
				return 0;
			} 
			
			max=min=p->chinese+p->maths+p->english;
			for(i=1;i<n;i++)
			{
				sum1=p->chinese+p->maths+p->english;
				if(max<sum1)
				{
					max=sum1;
					strcpy(maxname,p->name);
				}
				if(min>sum1)
				{
					min=sum1;
					strcpy(minname,p->name);
				}
				p=p->next;	
			} 
			printf("总分最高分：%.1f，姓名：%s",max,maxname);
			printf("\n");
			printf("总分最低分：%.1f，姓名：%s",min,minname);
			printf("\n");
			break;
		default:
			printf("输入错误，请重试！\n");
	}
	return (head);	
}

//成绩读取函数
score *load(score *head)
{
	score *p1,*p2;  //p2是尾结点指针
	int m=0;
	char filename[10];  //用来储存文件名
	FILE *fp;  //定义一个文件型指针
	
	printf("请输入文件路径及文件名：");
	scanf("%s",filename);
	if((fp=fopen(filename,"r+"))==NULL)  //文件打开函数：fopen（文件名，打开方式）
	{
		printf("找不到该文件！\n");
		return 0;
	} 
	 
	fscanf(fp,"            学生成绩管理系统            ");  //格式数据读取函数fprintf（文件型指针，格式控制，读取列表） 
    fscanf(fp,"\n");
    fscanf(fp,"-----------------------------------------\n");
    fscanf(fp,"|学号\t|姓名\t|语文\t|数学\t|英语\t|\n");
    fscanf(fp,"-----------------------------------------\n");                              //读取文件 
	    
    printf("            学生成绩管理系统            "); 
    printf("\n");
    printf("-----------------------------------------\n");
    printf("|学号\t|姓名\t|语文\t|数学\t|英语\t|\n");
    printf("-----------------------------------------\n");                               //显示文件
    
    head=NULL;
    p1=(score *)malloc(LEN);
    while(!feof(fp))
    {
		p1=(score *)malloc(LEN);
		fscanf(fp,"|%d\t|%s\t|%f\t|%f\t|%f\t|\n",&p1->number,p1->name,&p1->chinese,&p1->maths,&p1->english);
		fscanf(fp,"-----------------------------------------\n");     //读取文件 
		printf("|%04d\t|%s\t|%.1f\t|%.1f\t|%.1f\t|\n",p1->number,p1->name,p1->chinese,p1->maths,p1->english);
		printf("-----------------------------------------\n");        //显示文件 
		m++; 
		
		if(m==1)
		head=p1;
		else
		p2->next=p1;
		
		p2=p1;  //使尾结点指针p2永远指向最新也是最后一个结点 	
	 }
	p1->next=NULL;	
	printf("当前共%d个学生数据！\n",m);

	n=m;
	fclose(fp);
	return (head);	 
}

//

//主函数
int main()
{
	int k;
	score *head=0,*stu=0; //NULL代表空值，即指向一个不被使用的地址，大多数系统都将0作为不被使用的地址，所以可以这样写。但最好还是写=NULL
	while (1)
	{
		k=menu(k);
		switch (k)
		{
			case 1: head=creatlink();break;  	   //调用创建链表函数
			case 2: printf_(head); break;   		   //调用链表输出函数
			case 3: head=search(head);break;   	   //调用链表查找函数
			case 4: head=add (head,stu);break;     //调用链表添加函数
			case 5: head=dele(head);break; 		   //调用链表删除函数
			case 6: sort_data(head);break;  		   //调用链表排序函数
			case 7: save(head);break;  			   //调用成绩保存函数
			case 8: head=statistics(head);break; 	   //调用成绩统计函数
			case 9: head=load(head);break;  	   //调用成绩读取函数
			case 0: exit(0);    	      		   //退出程序，返回主界面
			default: printf("输入错误，请重试！\n");
		}
	}
	return 0;
}
