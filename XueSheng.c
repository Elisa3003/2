//����ѧ�����ݽṹ��
struct scorenode
{
	int number;			 //ѧ��ѧ��
	char name[10];		 //ѧ������
	float chinese;		//���ĳɼ�
	float maths;		//��ѧ�ɼ�
	float english;	//Ӣ��ɼ�
	struct scorenode *next; //��һ���ָ��
};           //ע�⣺����ṹ��ʱ��Ҫ��������������ķֺ�

#include<malloc.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define LEN sizeof(struct scorenode)      //sizeof�������������������Ҳ�����Ǳ���

typedef struct scorenode score ;     //�Զ�����������


int n=0,k;    //����ȫ�ֱ���,n���Լ�����k���ڱ��

//�˵�����
int menu(int k)
{
	int i;
	printf("\t\t\t\tѧ���ɼ�����ϵͳ\n");
	printf("\n");
	for(i=0;i<100;i++)
	printf("*");
	printf("\n1 �½�ѧ���ĳɼ�\t\t\t2 ��ʾѧ���ĳɼ�\t\t\t3 ��ѯѧ���ĳɼ�\n");
	printf("4 ���ѧ���ĳɼ�\t\t\t5 ɾ��ѧ���ĳɼ�\t\t\t6 ѧ���ɼ�����\n");
	printf("7 ����ѧ���ĳɼ�\t\t\t8 ͳ��ѧ���ĳɼ�\t\t\t9 ��ȡѧ���ĳɼ�\n");
	for(i=0;i<100;i++)
	printf("*");
	printf("\n��ӭ����ѧ���ɼ�����ϵͳ����ѡ������Ҫ�Ĳ�����ѡ��(0)�˳�����");
	scanf("%d",&k);
	getchar();
	return k;
}

//����������
score *creatlink()
{
	score *head,*p1,*p2,*p3,*max;//p1ָ������ӵĽṹ�壬p2��β���ָ�룬p3�Ǳ���ָ�루�ڸú������ڵĲ��������ظ�ѧ�ź����������������ã�
	int i,j,num;
	char t[10];
	float fen;
	n=0;
	head=p1=p2=p3=(score *)malloc(LEN);  //�����µ�Ԫ
	printf("������ѧ�����ϣ���0�˳���\n");
repeat1:                              //��ʵ��repeat1ֻ�������һ������ʱ�Żᾭ��
	printf("������ѧ��ѧ�ţ�ѧ��Ӧ����0����");                       //����ѧ��ѧ��
	scanf("%d",&p1->number);
	while(p1->number<0)
	{
		getchar();   //������һ����������ʱ�Ŀո����س���
		printf("�����������������ѧ��ѧ�ţ�");
		scanf("%d",&p1->number);
	}
	if(p1->number==0)  //������ѧ��Ϊ0ʱ��ת��ĩβ��������������
	goto end;

	printf("������ѧ��������");                                   //����ѧ������
	scanf("%s",p1->name);

	printf("���������ĳɼ���");                                  //�������ĳɼ�
	scanf("%f",&p1->chinese);
	while(p1->chinese<0||p1->chinese>100)  //���ĳɼ�Ӧ��0~100����
	{
		getchar();
		printf("��������������������ĳɼ���");
		scanf("%f",&p1->chinese);
	}

	printf("��������ѧ�ɼ���");                                  //������ѧ�ɼ�
	scanf("%f",&p1->maths);
	while(p1->maths<0||p1->maths>100)  //��ѧ�ɼ�Ӧ��0~100����
	{
		getchar();
		printf("�������������������ѧ�ɼ���");
		scanf("%f",&p1->maths);
	}

	printf("������Ӣ��ɼ���");                                  //����Ӣ��ɼ�
	scanf("%f",&p1->english);
	while(p1->english<0||p1->english>100)  //Ӣ��ɼ�Ӧ��0~100����
	{
		getchar();
		printf("�����������������Ӣ��ɼ���");
		scanf("%f",&p1->english);
	}

	head=NULL;//�൱�ڳ�ʼ��head
	while(p1->number!=0)               //������ڶ��������ġ������ṹ�壬�ͻ�ֱ�ӴӸ�whileѭ����ʼ��������ȥ������
	{
		n+=1;  //�����������ӵ�p1�������еڼ�����
		if(n==1)
		head=p1;//��p1�ǵ�һ�����ݣ���ʹhead��p1ָ��ͬһ�ṹ�壬��ʹ��ʱp1��Ϊͷ���
		else
		p2->next=p1;//��p1���ǵ�һ�����ݣ���ô��ʱ��p2����һ������ӵ�p1�����ڰ���һ��ѭ���е�p1������һ���е����һ����㣩��nextָ������ӵ�p1
		p2=p1;//ʹp2��ָ������ӵĽṹ�壨p2��β���ָ�룩
		p1=(score *)malloc(LEN);                         //ʹp1ָ���¿��ٵĵ�Ԫ
		//97~103�мȳн����ģ�97���ϵĴ��룩ͬʱ�ֿ��Դ���ڶ��������ġ����ν����whileѭ��ʱ��һ�ֺ�����ӵ�p1

		printf("������ѧ�����ϣ���0�˳���\n");
repeat2:printf("������ѧ��ѧ�ţ�ѧ��Ӧ����0����");
		scanf("%d",&p1->number);
		while(p1->number<0)
		{
			getchar();   //������һ����������ʱ�Ŀո����س���
			printf("�����������������ѧ��ѧ�ţ�");
			scanf("%d",&p1->number);
		}
		if(p1->number==0)  //������ѧ��Ϊ0ʱ��ת��ĩβ��������������
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
						printf("ѧ���ظ��������䣡\n");
						goto repeat2;
					}
				}
			}
		}//116~132�е�else�����Ų�����ӵ�ѧ��ѧ���Ƿ����������ظ�

		printf("������ѧ��������");                                   //����ѧ������
		scanf("%s",p1->name);

		printf("���������ĳɼ���");                                  //�������ĳɼ�
		scanf("%f",&p1->chinese);
		while(p1->chinese<0||p1->chinese>100)  //���ĳɼ�Ӧ��0~100����
		{
			getchar();
			printf("��������������������ĳɼ���");
			scanf("%f",&p1->chinese);
		}

		printf("��������ѧ�ɼ���");                                  //������ѧ�ɼ�
		scanf("%f",&p1->maths);
		while(p1->maths<0||p1->maths>100)  //��ѧ�ɼ�Ӧ��0~100����
		{
			getchar();
			printf("�������������������ѧ�ɼ���");
			scanf("%f",&p1->maths);
		}

		printf("������Ӣ��ɼ���");                                  //����Ӣ��ɼ�
		scanf("%f",&p1->english);
		while(p1->english<0||p1->english>100)  //Ӣ��ɼ�Ӧ��0~100����
		{
			getchar();
			printf("�����������������Ӣ��ɼ���");
			scanf("%f",&p1->english);
		}
	}//�������������95�е�while

end:p3=head;
	for(i=1;i<n;i++)  //������forѭ�����ڿ��ƽ����ȽϷ��ıȽϴ��������壺��ѭ��������������ѭ������ÿ�ֵĴ���
	{
		for(j=i+1;j<=n;j++)
		{
			max=p3;
			p3=p3->next;       //ʹmax��ǰһ����p3�Ǻ�һ��
			if(max->number>p3->number) //Ŀ�����ǽ������е�ѧ�Ŵ�С�������򣬴���һ�����������
			{
				num=max->number;  //����ѧ��
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
		p3=head;//���ڽ������ıȽ�λ�ôӵ�һ����ʼ������ÿ��Ҫ��p3����ָ��ͷ���
	}
	p2->next=NULL;  //��ȷ�ϲ�������½��ʱ�Ű�p2->nextָ��NULL
	printf("�����ѧ����λ��%d����\n",n);
	return head;
}

//�����������
void printf_(score *head)
{
	score *p;
	if(head==NULL)  //���ﲻ����n==0����������Ϊ�����ȡ�����Ǳߵ�ԭ�� 
	printf("\nû���κ�ѧ���ɼ���\n");
	else
	{
		printf("-----------------------------------------\n");
		printf("|ѧ��\t|����\t|����\t|��ѧ\t|Ӣ��\t|\n");
		printf("-----------------------------------------\n");           //�Ʊ�

		p=head;
		while(p!=NULL)
		{
			printf("|%04d\t|%s\t|%.1f\t|%.1f\t|%.1f\t|\n",p->number,p->name,p->chinese,p->maths,p->english);
			printf("-----------------------------------------\n");
			p=p->next;
		}
		printf("��%d��ѧ����Ϣ��\n",n);

	}
}

//������Һ���
score *search(score *head)
{
	score *p1;
	int num;
	if(head==NULL)
	{
		printf("\n��ǰû��ѧ���ɼ��������½�һ��ѧ���ɼ���\n");
		return (head);       //���ں�����˵�����غ���ֵ����ζ�˳���κ�����������һ�κ����ڵĲ�ͬ���п����ж��return
	}
	printf("\n������Ҫ��ѯ��ѧ��ѧ�ţ�");
	scanf("%d",&num);
	while(num!=0)
	{
		printf("-----------------------------------------\n");
		printf("|ѧ��\t|����\t|����\t|��ѧ\t|Ӣ��\t|\n");
		printf("-----------------------------------------\n");

		p1=head;
		while(p1->number!=num&&p1->next!=NULL)//����ѭ��ʱ�����һ��p1->number==num;�������p1��β�����p1->number==num;�������p1��β��㵫p1->number!=num
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
			printf("û���ҵ���ѧ�����ݣ�");
		}
		printf("������Ҫ��ѯ��ѧ��ѧ�ţ�");
		scanf("%d",&num);
	}
	return (head);
}

//������Ӻ���
score *add(score *head,score *stu)
{
	score *p0,*p1,*max;  //p0��stu�ı��ݣ�p1���ڱ���ѭ���У�max��������
	int i,j,num;
	float fen;
	char t[10];
	stu=(score *)malloc(LEN);
	printf("\n����Ҫ���ӵ�ѧ�������ϣ�");
repeat4:
	printf("������ѧ��ѧ�ţ�ѧ��Ӧ����0����");
	scanf("%d",&stu->number);
	while(stu->number<0)
	{
		getchar();
		printf("�����������������ѧ��ѧ�ţ�");
		scanf("%d",&stu->number);
	}
	if(stu->number==0)
	goto end2;
	else      //253~269�����ڼ������ӵ�ѧ���Ƿ��Ѿ�����
	{
		if(n>0)
		{
			p1=head;
			for(i=0;i<n;i++)   //��n���ƱȽϴ���
			{
				if(stu->number!=p1->number)
				p1=p1->next;
				else
				{
					printf("ѧ���ظ��������䣡\n");
					goto repeat4;
				}
			}
		}
	}
	printf("����ѧ��������");                                        //����ѧ������
	scanf("%s",stu->name);

		printf("���������ĳɼ���");                                  //�������ĳɼ�
	scanf("%f",&stu->chinese);
	while(stu->chinese<0||stu->chinese>100)  //���ĳɼ�Ӧ��0~100����
	{
		getchar();
		printf("��������������������ĳɼ���");
		scanf("%f",&stu->chinese);
	}

	printf("��������ѧ�ɼ���");                                  //������ѧ�ɼ�
	scanf("%f",&stu->maths);
	while(stu->maths<0||stu->maths>100)  //��ѧ�ɼ�Ӧ��0~100����
	{
		getchar();
		printf("�������������������ѧ�ɼ���");
		scanf("%f",&stu->maths);
	}

	printf("������Ӣ��ɼ���");                                  //����Ӣ��ɼ�
	scanf("%f",&stu->english);
	while(stu->english<0||stu->english>100)  //Ӣ��ɼ�Ӧ��0~100����
	{
		getchar();
		printf("�����������������Ӣ��ɼ���");
		scanf("%f",&stu->english);
	}

   	score *p2;                                                 //���½ڵ���ӽ�����

	if(head==NULL) //������������headʱΪ�丳��NULLֵ����������û�н��ʱhead==NULL
	{
		head=stu;
	}               //����Ϊ�յ���һ���಻��������µķ��ಢ��һ��
	else
	{
		p1=head;
		while(p1!=NULL)
		{
			p2=p1;
			p1=p1->next;
		}                //������ѭ��ʱ��p2��β��㣬p1��NULL
		p2->next=stu;
	}
	stu->next=NULL;
	n++;     //��p1==NULL����p1����һ����β���ʱ��ʹp1ָ���½�㣬ͬʱ���½���nextָ��NULL

//ע���add�����������һ����㣬�˴�δ��ѭ��

	p1=head;                                                  //������������
	for(i=1;i<n;i++)
	{
		for(j=i+1;j<=n;j++)
		{
			max=p1;
			p1=p1->next;
			if(max->number>p1->number)         //ע��ֻ�Ǹ����֮������ݽ������������֮���˳��ʹ����ģ���ÿ������nextָ��ĵ�ַ�����
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
	printf("���ڵ�ѧ����Ϊ��%d����\n",n);
	return (head);
}

//����ɾ������
score *dele(score *head)
{
	score *p1,*p2;
	int num;
	if(head==NULL)
	{
		printf("\n��ǰû���κ�ѧ�����ϣ����Ƚ���һ��ѧ���ɼ���\n");
		return (head);
	}

	printf("\n������Ҫɾ����ѧ����ѧ�ţ�");
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
				p2->next=p1->next;  //��һ�����Լ��p1��β����p1����β�����������Ϊ����whileѭ��ʱp1������β��㣬������NULL

			}
			n--;
			printf("\nѧ��%04dɾ���ɹ�������0�˳���",p1->number);
			 //ע��p2->next����ʼ��ָ��ָ�����p1������ʼ��ָ��ԭp1��ָ��ĵ�Ԫ��������Ҫʹĳָ�������p2��Ϊβ��㲻��ͨ��p1=NULLʵ�֣�������p2->next=NULL
		}
		else
		{
			printf("\nû�и�ѧ�����ϣ������䣡\n");
		}


		printf("\n������Ҫɾ����ѧ����ѧ�ţ�");
		scanf("%d",&num);
	}

 	printf("���ڵ�ѧ����Ϊ��%d����\n",n);
	return (head);
}

//����������
score* sort_data(score *head)
{
	score *p1,*max;
	int i,j,k,num;
	float fen;
	char t[10];

	if(head==NULL)
	{
		printf("\n��ǰû���κ�ѧ�����ϣ�\n");
		return (head);
	}

    for(i=0;i<100;i++)
    printf("*");
    printf("\n1 ����ѧ������\t2 ������������\t3 �������ĳɼ�����\t4 ������ѧ�ɼ�����\t5 ����Ӣ��ɼ�����\n");
    for(i=0;i<100;i++)
    printf("*");

    printf("\n��ѡ�������");
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
        default:printf("������������ԣ�\n");
    }

    return (head);
}

//�ɼ����溯��
int save(score *head)
{
    FILE *fp; //ֻҪϵͳ�õ�һ���ļ����ͻῪ��һ���ṹ�嵥Ԫ���Դ���ļ���Ϣ���������Ԫ���ñ�������ʶ������ͨ��ָ��õ�Ԫ��ָ��������ʡ����ָ����������ļ���ָ�������FILE�����ļ��ͱ����Ĺؼ��� 
    score *p1;
    char filepn[20];  //���������ļ�·�����ļ���
    printf("�������ļ�·�����ļ�����");
    scanf("%s",filepn);
    if((fp=fopen(filepn,"w+"))==NULL)  //fopen()���ļ��򿪺����������Զ�д��ʽ���ļ������ļ����ھ�ɾȥԭ�ļ������´��������� 
    {
        printf("�ļ���ʧ�ܣ�\n");
        return (0);
    }
    fprintf(fp,"            ѧ���ɼ�����ϵͳ            ");  //��ʽ����д�뺯��fprintf���ļ���ָ�룬��ʽ���ƣ�д���б� 
    fprintf(fp,"\n");
    fprintf(fp,"-----------------------------------------\n");
    fprintf(fp,"|ѧ��\t|����\t|����\t|��ѧ\t|Ӣ��\t|\n");
    fprintf(fp,"-----------------------------------------\n");
//ע��öκ������Ϊ��ʹ������û��ѧ������Ҳ���Ա���ɹ����������ͷ����665~669�У� 

    p1=head;
    while(p1!=NULL)
    {
            fprintf(fp,"|%04d\t|%s\t|%.1f\t|%.1f\t|%.1f\t|\n",p1->number,p1->name,p1->chinese,p1->maths,p1->english);
			fprintf(fp,"-----------------------------------------\n");
			p1=p1->next;
    }

    fclose(fp);  //fclose���ļ���ָ�룩Ϊ�ļ��رպ��� 
    printf("�ļ��Ѿ����棡\n");
    return 0;

}

//�ɼ�ͳ�ƺ���
score *statistics(score *head)
{
	float sum1,sum2,sum3,ave1,ave2,ave3,max,min;
	char maxname[10],minname[10];
	score *p;
	int x,y=0,i=0;  //x���ڷ��ࣻy���ڼ���
	
	printf("\n***********************************************************************\n");
	printf("1 �����ֺܷ�ƽ����\t2 ����ƽ����\t3 �ܷ���ߺ��ܷ����\t0 �˳�\n");
	printf("***********************************************************************\n");
	printf("��ѡ�������");
	scanf("%d",&x);
	getchar();
	
	p=head;
	switch(x)
	{
		case 0:break;
		case 1:                              //������ܷ���־��� 
			if(head==NULL)
			{
				printf("\nû���κ�ѧ�����ϣ�\n");
				return 0;
			} 
			
			printf("---------------------------------------------------------\n");
			printf("|ѧ��\t|����\t|����\t|��ѧ\t|Ӣ��\t|�ܷ�\t|ƽ����\t|\n");
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
		case 2:                         //�����ƽ���� 
			if(head==NULL)
			{
				printf("\nû���κ�ѧ�����ϣ�\n");
				return 0;
			} 
			
			printf("-----------------------------------------\n");
			printf("|ѧ��\t|����\t|����\t|��ѧ\t|Ӣ��\t|\n");
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
			ave1=sum1/y;  //����ʹ��y����ʹΪ�˷�ֹ����Ĳ�����n������Ӱ�쵽�����ƽ���ּ��� 
			ave2=sum2/y;
			ave3=sum3/y;
			printf("|ƽ����\t\t|%.1f\t|%.1f\t|%.1f\t|\n",ave1,ave2,ave3);
			printf("-----------------------------------------\n");
			break;
		case 3:                     //���ܷ���ߺ��ܷ����
			if(head==NULL)
			{
				printf("\nû���κ�ѧ�����ϣ�\n");
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
			printf("�ܷ���߷֣�%.1f��������%s",max,maxname);
			printf("\n");
			printf("�ܷ���ͷ֣�%.1f��������%s",min,minname);
			printf("\n");
			break;
		default:
			printf("������������ԣ�\n");
	}
	return (head);	
}

//�ɼ���ȡ����
score *load(score *head)
{
	score *p1,*p2;  //p2��β���ָ��
	int m=0;
	char filename[10];  //���������ļ���
	FILE *fp;  //����һ���ļ���ָ��
	
	printf("�������ļ�·�����ļ�����");
	scanf("%s",filename);
	if((fp=fopen(filename,"r+"))==NULL)  //�ļ��򿪺�����fopen���ļ������򿪷�ʽ��
	{
		printf("�Ҳ������ļ���\n");
		return 0;
	} 
	 
	fscanf(fp,"            ѧ���ɼ�����ϵͳ            ");  //��ʽ���ݶ�ȡ����fprintf���ļ���ָ�룬��ʽ���ƣ���ȡ�б� 
    fscanf(fp,"\n");
    fscanf(fp,"-----------------------------------------\n");
    fscanf(fp,"|ѧ��\t|����\t|����\t|��ѧ\t|Ӣ��\t|\n");
    fscanf(fp,"-----------------------------------------\n");                              //��ȡ�ļ� 
	    
    printf("            ѧ���ɼ�����ϵͳ            "); 
    printf("\n");
    printf("-----------------------------------------\n");
    printf("|ѧ��\t|����\t|����\t|��ѧ\t|Ӣ��\t|\n");
    printf("-----------------------------------------\n");                               //��ʾ�ļ�
    
    head=NULL;
    p1=(score *)malloc(LEN);
    while(!feof(fp))
    {
		p1=(score *)malloc(LEN);
		fscanf(fp,"|%d\t|%s\t|%f\t|%f\t|%f\t|\n",&p1->number,p1->name,&p1->chinese,&p1->maths,&p1->english);
		fscanf(fp,"-----------------------------------------\n");     //��ȡ�ļ� 
		printf("|%04d\t|%s\t|%.1f\t|%.1f\t|%.1f\t|\n",p1->number,p1->name,p1->chinese,p1->maths,p1->english);
		printf("-----------------------------------------\n");        //��ʾ�ļ� 
		m++; 
		
		if(m==1)
		head=p1;
		else
		p2->next=p1;
		
		p2=p1;  //ʹβ���ָ��p2��Զָ������Ҳ�����һ����� 	
	 }
	p1->next=NULL;	
	printf("��ǰ��%d��ѧ�����ݣ�\n",m);

	n=m;
	fclose(fp);
	return (head);	 
}

//

//������
int main()
{
	int k;
	score *head=0,*stu=0; //NULL�����ֵ����ָ��һ������ʹ�õĵ�ַ�������ϵͳ����0��Ϊ����ʹ�õĵ�ַ�����Կ�������д������û���д=NULL
	while (1)
	{
		k=menu(k);
		switch (k)
		{
			case 1: head=creatlink();break;  	   //���ô���������
			case 2: printf_(head); break;   		   //���������������
			case 3: head=search(head);break;   	   //����������Һ���
			case 4: head=add (head,stu);break;     //����������Ӻ���
			case 5: head=dele(head);break; 		   //��������ɾ������
			case 6: sort_data(head);break;  		   //��������������
			case 7: save(head);break;  			   //���óɼ����溯��
			case 8: head=statistics(head);break; 	   //���óɼ�ͳ�ƺ���
			case 9: head=load(head);break;  	   //���óɼ���ȡ����
			case 0: exit(0);    	      		   //�˳����򣬷���������
			default: printf("������������ԣ�\n");
		}
	}
	return 0;
}
