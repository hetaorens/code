
#include <iostream>  
#include <string>
#include <getopt.h>
using namespace std;  
int count=0;//链表的个数 
typedef struct node  
{  
    string number;  
    struct node *pre;  
    struct node *next;  
}node;  
node *pend; //头 
node *phead; //尾 
  
void Create_List()//创建链表；  
{
    node *ps=new node;  
    ps->next=NULL;  
    ps->pre=NULL;  
    cout<<"请输入船上的人,以零结束"<<endl;  
    cin>>ps->number;
    while(ps->number!="END")  
    {  
        if(!phead)//空表的插入；  
        {  
            phead=ps;  
            pend=ps;  
        }  
        else  
        {  
            pend->next=ps;  
            ps->pre=pend;  
            pend=ps;  
        }  
        ps=new node;
        ps->next=NULL;  
        ps->pre=NULL;  
        cin>>ps->number;
        count++;
    }
    pend->next=phead;//连接表头表尾；  
    phead->pre=pend;  
}  
void throw_list(int Cwise,int aCwise,int start,int die_num)
{
	int d=0;
	node *p=new node;
	p=phead;
	for(int i=1;i<start;i++)
	{
		p=phead->next;
	}
	while(d!=die_num)//扔人 
	{
		for(int i=1;i<Cwise;i++)
		{
			p=p->next;
		}
		if(phead->number==p->number)//保证头 
		phead=phead->next;
		else if(pend->number==p->number)
		pend=pend->pre;
		cout<<p->number<<" 死亡"<<endl;
		p->next->pre=p->pre;
		p->pre->next=p->next;
		p=p->next;
		d++;
		if(d==die_num)
		break;
		for(int i=1;i<aCwise;i++)
		{
			p=p->pre;
		}
		if(phead->number==p->number)//保证头 
		phead=phead->next;
		else if(pend->number==p->number)
		pend=pend->pre;
		cout<<p->number<<" 死亡"<<endl;
		p->next->pre=p->pre;
		p->pre->next=p->next;
		p=p->pre;
		d++;
		if(d==die_num)
		break;
	}
	cout<<"幸存者名单 "<<" ";//活的人 
	p=phead;
	for(int i=1;i<=count-d;i++)
	{
		cout<<p->number<<" ";
		p=p->next;
	}
	cout<<endl;
}
int main(int argc, char *argv[])
{

      int c;
    int digit_optind = 0;
                 
   while (1) {
        int this_option_optind = optind ? optind : 1;
        int option_index = 0;
        static struct option long_options[] = {
            {"add",     required_argument, 0,  0 },
            {"append",  no_argument,       0,  0 },
            {"delete",  required_argument, 0,  0 },
            {"verbose", no_argument,       0,  0 },
            {"create",  required_argument, 0, 'c'},
            {"file",    required_argument, 0,  0 },
            {0,         0,                 0,  0 }
        };
 
       c = getopt_long(argc, argv, "abc:d:012",
                 long_options, &option_index);
        if (c == -1)
            break;
 


 
       switch (c) {
        case 0:
            printf("option %s", long_options[option_index].name);
            if (optarg)
                printf(" with arg %s", optarg);
            printf("\n");
            break;
 
       case '0':
       case '1':
       case '2':
            if (digit_optind != 0 && digit_optind != this_option_optind)
              printf("digits occur in two different argv-elements.\n");
            digit_optind = this_option_optind;
            printf("option %c\n", c);
            break;
 
       case 'a':
            printf("option a\n");
            break;
 
       case 'b':
            printf("option b\n");
            break;
 
       case 'c':
            printf("option c with value '%s'\n", optarg);
            break;
 
       case 'd':
            printf("option d with value '%s'\n", optarg);
            break;
 
       case '?':
            break;
 
       default:
            printf("?? getopt returned character code 0%o ??\n", c);
        }
    }
 
   if (optind < argc) {
        printf("non-option ARGV-elements: ");
        while (optind < argc)
            printf("%s ", argv[optind++]);
        printf("\n");
    }
	int p_num,Cwise,aCwise,start,die_num;
	Create_List();
	cout<<"游戏开始"<<endl;
	cout<<"顺时针扔第几个 ";
	cin>>Cwise;
	cout<<"逆时针扔第几个 ";
	cin>>aCwise;
	cout<<"从谁开始扔 ";
	cin>>start;
	cout<<"扔几个 ";
	cin>>die_num;
	throw_list(Cwise,aCwise,start,die_num);
 }
