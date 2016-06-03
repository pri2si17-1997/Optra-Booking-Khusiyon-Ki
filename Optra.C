#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<dos.h>
#include<alloc.h>
#include<stdlib.h>

struct user
{
    char user_name[100];
    char user_id[100];
    char mobile_no[100];
    char email_id[100];
    char pwd[256];
    char re_pwd[256];
    struct user *next;
};
struct user *head = NULL, *present = NULL, *ptr;
void display(struct user *);
void search(struct user *);

struct venue
	{
		char name[10];
		int time1;
		int time2;
		struct venue *ptr;
	}*x,*start=NULL,*end=NULL,*current;

struct venue_sports
{
	     char name[10];
	     int time1;
	    // int time2;
	     struct venue *ptr;
}*y,*stt=NULL,*en_d=NULL,*curr;

struct venue_festivals
{
	     char name[10];
	     int time1;
	    // int time2;
	     struct venue *ptr;
}*z,*star=NULL,*nd=NULL,*curent;

struct node
{
    int row, col, val;
    struct node *right, *down;
};

  /* structure of column head */
struct col_head
{
    int col;
    struct col_head *next;
    struct node *down;
};

  /* structure of row head */
struct row_head
{
    int row;
    struct row_head *next;
    struct node *right;
};

  /* structure of additional head */
struct sparse_head
{
    int row_count, col_count;
    struct row_head *frow;
    struct col_head *fcol;
};

  /* main node */
struct sparse
{
    int row, *data;
    struct node *nodePtr;
    struct sparse_head *smatrix;
    struct row_head **rowPtr;
    struct col_head **colPtr;
};

int count = 0;

  /* Establish row and column links */
void initialize(struct sparse *sPtr, int row, int col)
{
    int i;
    sPtr->rowPtr = (struct row_head **) calloc(1, (sizeof (struct row_head) * row));
    sPtr->colPtr = (struct col_head **) calloc(1, (sizeof (struct col_head) * col));
    for (i = 0; i < row; i++)
	sPtr->rowPtr[i] = (struct row_head *) calloc(1, sizeof (struct row_head));

    for (i = 0; i < row - 1; i++)
    {
	sPtr->rowPtr[i]->row = i;
	sPtr->rowPtr[i]->next = sPtr->rowPtr[i + 1];
    }

    for (i = 0; i < col; i++)
	sPtr->colPtr[i] = (struct col_head *) calloc(1, sizeof (struct col_head));

    for (i = 0; i < col - 1; i++)
    {
	sPtr->colPtr[i]->col = i;
	sPtr->colPtr[i]->next = sPtr->colPtr[i + 1];
    }

	/* update additional head information  */
    sPtr->smatrix = (struct sparse_head *) calloc(1, sizeof (struct sparse_head));
    sPtr->smatrix->row_count = row;
    sPtr->smatrix->col_count = col;
    sPtr->smatrix->frow = sPtr->rowPtr[0];
    sPtr->smatrix->fcol = sPtr->colPtr[0];
    return;
}

   /* input sparse matrix */
void inputMatrix(struct sparse *sPtr, int row, int col)
{
    int i, n, x = 0, y = 0;
    n = row * col;
    sPtr->data = (int *) malloc(sizeof (int) * n);
    for (i = 0; i < n; i++)
    {
	if (y != 0 && y % col == 0)
	{
	    x++;
	    y = 0;
	}
	sPtr->data[i]=0;
	if (sPtr->data[i])
	    count++;
	y++;
    }
    return;
}

  /* display sparse matrix */
void displayInputMatrix(struct sparse s, int row, int col)
{
    FILE *fp;
    int i;
    fp = fopen("BOOKING.txt", "w");
    for (i = 0; i < row * col; i++)
    {
	if (i % col == 0)
	    printf("\n");
	printf("      %d", s.data[i]);
	fprintf(fp,"%d ", s.data[i]);
	if(i%10 == 0 && i != 0)
	{
	    fprintf(fp, "\n");
	}
    }
    printf("\n");
    return;
}

void end_page()
{
	int gd=DETECT,gm;
	int x=10,y=200,x1=675,y1=380;
	int stangle=35,endangle=140,radius=90;

	initgraph(&gd,&gm,"c:\\TC\\bgi");
	// kbhit is a function  which ends only if the person presses any key
	while(!kbhit())
	{
		cleardevice();
		setbkcolor(RED);
			  outtextxy(100,100,"ENJOY YOUR SHOW !!!");
			  outtextxy(200,250,"THANK YOU FOR CHOOSING OPTRA ");

			  settextstyle(3,HORIZ_DIR,3);
		if(x<640)
		{
			x+=5;
			y+=1;
			arc(x,y,stangle,endangle+35,radius);
			arc(x,y-110,190,323,radius+2);
			circle(x+40,y-60,5);
			line(x-90,y-90,x-90,y-8);
		}
		else
		{
			x1-=5;
			y1-=1;
			arc(x1,y1,stangle-30,endangle+4,radius);
			arc(x1,y1-110,217,350,radius+2);
			circle(x1-40,y1-60,5);
			line(x1+90,y1-90,x1+90,y1-10);
		}
		setcolor(YELLOW);
		delay(90);
	}
	closegraph();

}

void credit_card();

void net_banking();

void SBI();

void CITI();

void ICICI();

void foodfest();

void kitefest();

void puma();

void ipl();

void piku();

void f7();

void avengers2();

void gabbar();

int i=1,j=1,r=1;
char m;
int d,e;
char ch;


void payment()
{
    int ch;
    printf("\n Select payment method : ");
    printf("\n 1. Credit/Debit Card.\n 2. Net Banking.\n");
    scanf("%d", &ch);
    switch(ch)
    {
        case 1 : credit_card();
                 break;

        case 2 : net_banking();
                 break;

        default : printf("\n Enter a valid payment method....");
    }
}

void credit_card()
{
    struct card_details
    {
	char card_no[100];
	char cvv_no[10];
	char expiry[20];
	char name[100];
    };
    struct card_details c_d;
    char cvv[256] = {0};
    char c;
    int position = 0;
    int len_card, len_cvv, len_exp, ch, pos = 0, key;
    do
    {
	printf("\n CARD NUMBER : ");
	gets(c_d.card_no);
	len_card = strlen(c_d.card_no);
	if(len_card != 19)
	{
	    printf("\n Please Enter a valid card.");
	}
	else
	    break;
    }while(1);

    do
    {
	printf("\n EXPIRY : ");
	gets(c_d.expiry);
	len_exp = strlen(c_d.expiry);
	if(len_exp != 10)
	{
	    printf("\n Invalid date..");
	}
	else
	    break;
    }while(1);

    printf("\n CVV : ");
    do
    {
	c = getch();
	if(isprint(c))
	{
	    cvv[position++] = c;
	    printf("%c", '*');
	}
	else if( c == 8 && position)
	{
	    cvv[position--] = '\0';
	    printf("%s", "\b \b");
	}
    }while(c != 13);
    len_cvv = strlen(cvv);
    if(len_cvv != 3)
    {
	    printf("\n Invalid card details..");
    }

    printf("\n NAME ON THE CARD : ");
    gets(c_d. name);
    printf("\n\n\n\t\t Press 1 to continue.....\n\n\n\t\t\t");
    scanf("%d", &ch);
    printf("\n\n\t\t Waiting for transaction.....Please do not press any key...");
    delay(750);
    printf("\n\t\t Waiting for bank to confirm....");
    delay(750);
    printf("\n\t\t Payment Successful....press any key to return to home......or you will be automativally directed.");
    delay(1000);
    end_page();
}

void net_banking()
{
    int ch;
    printf("\n Select Your Bank : ");
    printf("\n 1. State Bank Of India.");
    printf("\n 2. Citi Bank.");
    printf("\n 3. ICICI Bank.\n");
    scanf("%d", &ch);
    switch(ch)
    {
	case 1 : SBI();
		 break;

	case 2 : CITI();
		 break;

	case 3 : ICICI();
		 break;

	default : printf("\n Enter valid bank........");
    }
}

void SBI()
{
    FILE *fp;
    struct user
    {
	char user_id[100];
	char login_pwd[100];
	char tran_pwd[100];
    };
    struct user u[10];
    int i, l = 1, flag = 0, j, indicator = 0, key;
    char u_i[100] = {0};
    char u_i_t[100] = {0};
    char log_pd[100];
    char tra_pd[100];
    char c, d, e;
    int k, q, a, b;
    int pos = 0, position = 0;
    fp = fopen("SBI.txt", "r");
    while(1)
    {
	c = fgetc(fp);
	if(c == EOF)
	    break;
	if(c == '\n')
	    l++;
    }
    rewind(fp);
    for(i =0; i<(l/3); i++)
    {
	fseek(fp, 0, SEEK_CUR);
	fgets(u[i].user_id, 100, fp);
	//puts(u[i].user_id);
	fgets(u[i].login_pwd, 100, fp);
	//puts(u[i].login_pwd);
	fgets(u[i].tran_pwd, 100, fp);
	//puts(u[i].tran_pwd);
    }
    printf("\n");
    printf("\n User Id : ");
    scanf("%s", u_i);
    printf("\n Login Password : ");
    do
    {
	d = getch();
	if(isprint(d))
	{
	    log_pd[pos++] = d;
	    printf("%c", '*');
	}
	else if( d == 8 && pos)
	{
	    log_pd[pos--] = '\0';
	    printf("%s", "\b \b");
	}
    }while(d != 13);
    for(i = 0; i<2; i++)
    {
	k = strcmp(u_i, u[i].user_id);
	q = strcmp(log_pd, u[i].login_pwd);
	if(k != 0 && q != 0)
	{
	    flag = 1;
	}
	else
	{
	    flag = 0;
	}
    }
    if(flag == 1)
    {
	printf("\n Waiting for bank response.....");
	delay(750);
	printf("\n User Id : ");
	scanf("%s", u_i_t);
	printf("\n Transaction Password : ");
	do
	{
	    e = getch();
	    if(isprint(e))
	    {
		tra_pd[position++] = d;
		printf("%c", '*');
	    }
	    else if( d == 8 && pos)
	    {
		tra_pd[position--] = '\0';
		printf("%s", "\b \b");
	    }
	}while(e != 13);
	for(j = 0; j<2; j++)
	{
	    a = strcmp(u_i_t, u[i].user_id);
	    b = strcmp(tra_pd, u[i].tran_pwd);
	    if(a != 0 && b != 0)
	    {
		indicator = 1;
	    }
	    else
	    {
		indicator = 0;
	    }
	}
	if(indicator == 1)
	{
	    printf("\n Request is being processd.......");
	    delay(10000);
	    printf("\n Payment Successfull....");
	    delay(750);
	    printf("\n \t\t Press any key to return to home.... or you will be automatically directed...");
	    delay(1000);
	    end_page();
	}
    }
}

void CITI()
{
    FILE *fp;
    struct user
    {
	char user_id[100];
	char login_pwd[100];
	char tran_pwd[100];
    };
    struct user u[10];
    int i, l = 1, flag = 0, j, indicator = 0, key;
    char u_i[100] = {0};
    char u_i_t[100] = {0};
    char log_pd[100];
    char tra_pd[100];
    char c, d, e;
    int k, q, a, b;
    int pos = 0, position = 0;
    fp = fopen("CITI.txt", "r");
    while(1)
    {
	c = fgetc(fp);
	if(c == EOF)
	    break;
	if(c == '\n')
	    l++;
    }
    rewind(fp);
    for(i =0; i<(l/3); i++)
    {
	fseek(fp, 0, SEEK_CUR);
	fgets(u[i].user_id, 100, fp);
	//puts(u[i].user_id);
	fgets(u[i].login_pwd, 100, fp);
	//puts(u[i].login_pwd);
	fgets(u[i].tran_pwd, 100, fp);
	//puts(u[i].tran_pwd);
    }
    printf("\n");
    printf("\n User Id : ");
    scanf("%s", u_i);
    printf("\n Login Password : ");
    do
    {
	d = getch();
	if(isprint(d))
	{
	    log_pd[pos++] = d;
	    printf("%c", '*');
	}
	else if( d == 8 && pos)
	{
	    log_pd[pos--] = '\0';
	    printf("%s", "\b \b");
	}
    }while(d != 13);
    for(i = 0; i<2; i++)
    {
	k = strcmp(u_i, u[i].user_id);
	q = strcmp(log_pd, u[i].login_pwd);
	if(k != 0 && q != 0)
	{
	    flag = 1;
	}
	else
	{
	    flag = 0;
	}
    }
    if(flag == 1)
    {
	printf("\n Waiting for bank response.....");
	delay(750);
	printf("\n User Id : ");
	scanf("%s", u_i_t);
	printf("\n Transaction Password : ");
	do
	{
	    e = getch();
	    if(isprint(e))
	    {
		tra_pd[position++] = d;
		printf("%c", '*');
	    }
	    else if( d == 8 && pos)
	    {
		tra_pd[position--] = '\0';
		printf("%s", "\b \b");
	    }
	}while(e != 13);
	for(j = 0; j<2; j++)
	{
	    a = strcmp(u_i_t, u[i].user_id);
	    b = strcmp(tra_pd, u[i].tran_pwd);
	    if(a != 0 && b != 0)
	    {
		indicator = 1;
	    }
	    else
	    {
		indicator = 0;
	    }
	}
	if(indicator == 1)
	{
	    printf("\n Request is being processd.......");
	    delay(10000);
	    printf("\n Payment Successfull....");
	    delay(750);
	    printf("\n \t\t Press any key to return to home....or you will be automatically directed..");
	    delay(1000);
	    end_page();
	}
    }
}

void ICICI()
{
    FILE *fp;
    struct user
    {
	char user_id[100];
	char login_pwd[100];
	char tran_pwd[100];
    };
    struct user u[10];
    int i, l = 1, flag = 0, j, indicator = 0, key;
    char u_i[100] = {0};
    char u_i_t[100] = {0};
    char log_pd[100];
    char tra_pd[100];
    char c, d, e;
    int k, q, a, b;
    int pos = 0, position = 0;
    fp = fopen("ICICI.txt", "r");
    while(1)
    {
	c = fgetc(fp);
	if(c == EOF)
	    break;
	if(c == '\n')
	    l++;
    }
    rewind(fp);
    for(i =0; i<(l/3); i++)
    {
	fseek(fp, 0, SEEK_CUR);
	fgets(u[i].user_id, 100, fp);
	//puts(u[i].user_id);
	fgets(u[i].login_pwd, 100, fp);
	//puts(u[i].login_pwd);
	fgets(u[i].tran_pwd, 100, fp);
	//puts(u[i].tran_pwd);
    }
    printf("\n");
    printf("\n User Id : ");
    scanf("%s", u_i);
    printf("\n Login Password : ");
    do
    {
	d = getch();
	if(isprint(d))
	{
	    log_pd[pos++] = d;
	    printf("%c", '*');
	}
	else if( d == 8 && pos)
	{
	    log_pd[pos--] = '\0';
	    printf("%s", "\b \b");
	}
    }while(d != 13);
    for(i = 0; i<2; i++)
    {
	k = strcmp(u_i, u[i].user_id);
	q = strcmp(log_pd, u[i].login_pwd);
	if(k != 0 && q != 0)
	{
	    flag = 1;
	}
	else
	{
	    flag = 0;
	}
    }
    if(flag == 1)
    {
	printf("\n Waiting for bank response.....");
	delay(750);
	printf("\n User Id : ");
	scanf("%s", u_i_t);
	printf("\n Transaction Password : ");
	do
	{
	    e = getch();
	    if(isprint(e))
	    {
		tra_pd[position++] = d;
		printf("%c", '*');
	    }
	    else if( d == 8 && pos)
	    {
		tra_pd[position--] = '\0';
		printf("%s", "\b \b");
	    }
	}while(e != 13);
	for(j = 0; j<2; j++)
	{
	    a = strcmp(u_i_t, u[i].user_id);
	    b = strcmp(tra_pd, u[i].tran_pwd);
	    if(a != 0 && b != 0)
	    {
		indicator = 1;
	    }
	    else
	    {
		indicator = 0;
	    }
	}
	if(indicator == 1)
	{
	    printf("\n Request is being processd.......");
	    delay(10000);
	    printf("\n Payment Successfull....");
	    delay(750);
	    printf("\n \t\t Press any key to return to home....or you will be automatically directed..");
	    delay(1000);
	    end_page();
	}
    }
}

void ticket_booking()
{
    struct sparse input, output;
    int row, col;
    int n, i;
    int book_row, book_col;
    initialize(&input, 10, 10);
    initialize(&output, 10, 10);
    inputMatrix(&input, 10, 10);
    //printf("Given Sparse Matrix has %d non-zero elements\n", count);
    printf("\t\t\tPick Your Seats...\n");
    displayInputMatrix(input, 10, 10);
    printf("\n\n");
    printf("\n Enter no. of seats you want to book : ");
    scanf("%d", &n);
    printf("\n Enter row where you want your seats : ");
    scanf("%d", &book_row);
    printf("\n Following seat number belongs to you in row %d.", book_row);
    for(i = 0; i<n; i++)
    {
	printf("%d   ", i);
    }
}

void events()
{
  printf("a.) FOOD FESTIVAL\n");
  printf("\tb.) KITE FLYING FESTIVAL \n\n");

  printf("Enter Your Choice : ");
  scanf("%c",&m);


  switch(m)
  {

  case 'a':
  case 'A':

  foodfest();

  break;

  case 'b':
  case 'B':

  kitefest();

  break;

  default:

  printf("\n");
  printf("wrong choice");
  }

}
void sports()
{
  printf("a.) PUMA URBAN STAMPEDE\n");
  printf("\tb.) IPL\n\n");

  printf("Enter your choice : ");
  scanf("%c",&m);


  switch(m)
  {

  case 'a':
  case 'A':

  puma();

  break;

  case 'b':
  case 'B':

  ipl();

  break;

  default:

  printf("\n");
  printf("wrong choice");
}
}

void foodfest()
  {

    while(i<3)
    {


      z=(struct venue*)malloc(sizeof(struct venue_festivals));
      z->ptr=NULL;

      if(star==NULL)
      {

	star=nd=z;
      }
      else
      {

	nd->ptr=z;
	nd=z;

      }

      if(i==1)
      {
	fflush(stdin);
	strcpy(nd->name,"1. DELHI");
	fflush(stdin);
	z->time1=1000;

      }

      if(i==2)
      {
	fflush(stdin);
	strcpy(nd->name,"2. MUMBAI");
	fflush(stdin);
	z->time1=1200;

      }


      i++;

  }


  curent=star;

  while(curent!=NULL)
  {
    flushall();

    printf("\n");
    puts(curent->name);
    printf("\n\t\t");

    printf("%d",curent->time1);
    curent=curent->ptr;
    printf("\n");

  }

  printf("Enter Your Location : ");
  fflush(stdin);
  scanf("%d",&d);

  curent=star;

  while(r<d)
  {
    curent=curent->ptr;
    r++;
  }
   printf("\n");

  printf("THE FOOD FESTIVAL ");
  printf("\n");

  printf("DATE : 16/05/2015");
  printf("\n");

  printf("You opted for %s and the time you enter is %d",curent->name,curent->time1);
  printf("\n Press any key to make payment...");
getch();
payment();


//  strcpy(ch,current->name);



}


  void kitefest()
  {


    while(i<3)
    {


      z=(struct venue*)malloc(sizeof(struct venue_festivals));
      z->ptr=NULL;

      if(star==NULL)
      {

	star=nd=z;
      }
      else
      {

	nd->ptr=z;
	nd=z;

      }

      if(i==1)
      {
	fflush(stdin);
	strcpy(nd->name,"1. CHENNAI");
	fflush(stdin);
	z->time1=1600;

      }

      if(i==2)
      {
	fflush(stdin);
	strcpy(nd->name,"2. KOLKATA");
	fflush(stdin);
	z->time1=1900;

      }


      i++;

  }


  curent=star;

  while(curent!=NULL)
  {
    flushall();

    printf("\n");
    puts(curent->name);
    printf("\n\t\t");

    printf("%d",curent->time1);
    curent=curent->ptr;
    printf("\n");

  }

  printf("Enter Your Location : ");
  fflush(stdin);
  scanf("%d",&d);

  curent=star;

  while(r<d)
  {
    curent=curent->ptr;
    r++;
  }
   printf("\n");

  printf("FESTIVALS : THE KITE FLYING FESTIVAL");
  printf("\n");

  printf("DATE : 13/08/2015");
  printf("\n");

  printf("You opted for %s and the time of you enter is %d",curent->name,curent->time1);
printf("\n Press any key to make payment...");
getch();
payment();


//  strcpy(ch,current->name);

}


 void puma()
  {

    while(i<3)
    {


      y=(struct venue*)malloc(sizeof(struct venue_sports));
      y->ptr=NULL;

      if(stt==NULL)
      {

	stt=en_d=y;
      }
      else
      {

	en_d->ptr=y;
	en_d=y;

      }

      if(i==1)
      {
	fflush(stdin);
	strcpy(en_d->name,"1. DELHI");
	fflush(stdin);
	y->time1=1000;

      }

      if(i==2)
      {
	fflush(stdin);
	strcpy(en_d->name,"2. MUMBAI");
	fflush(stdin);
	y->time1=1200;

      }


      i++;

  }


  curr=stt;

  while(curr!=NULL)
  {
    flushall();

    printf("\n");
    puts(curr->name);
    printf("\n\t\t");

    printf("%d",curr->time1);
    curr=curr->ptr;
    printf("\n");

  }

  printf(" Enter Your Location : ");
  fflush(stdin);
  scanf("%d",&d);

  curr=stt;

  while(r<d)
  {
    curr=curr->ptr;
    r++;
  }
   printf("\n");

  printf("SPORTS : THE URBAN STAMPEDE RACE BY PUMA ");
  printf("\n");

  printf("DATE : 16/05/2015");
  printf("\n");

  printf("You opted for %s and the time of your race is %d",curr->name,curr->time1);
printf("\n Press any key to make payment...");
getch();
payment();


//  strcpy(ch,current->name);



}


  void ipl()
  {


    while(i<3)
    {


       y =(struct venue*)malloc(sizeof(struct venue_sports));
      y ->ptr=NULL;

      if(stt==NULL)
      {

	stt=en_d=y;
      }
      else
      {

	en_d->ptr=y;
	en_d=y;

      }

      if(i==1)
      {
	fflush(stdin);
	strcpy(en_d->name,"1. CHENNAI");
	fflush(stdin);
	y->time1=1600;

      }

      if(i==2)
      {
	fflush(stdin);
	strcpy(en_d->name,"2. KOLKATA");
	fflush(stdin);
	y->time1=1900;

      }


      i++;

  }


  curr=stt;

  while(curr!=NULL)
  {
    flushall();

    printf("\n");
    puts(curr->name);
    printf("\n\t\t");

    printf("%d",curr->time1);
    curr=curr->ptr;
    printf("\n");

  }

  printf("Enter your Location : ");
  fflush(stdin);
  scanf("%d",&d);

  curr=stt;

  while(r<d)
  {
    curr=curr->ptr;
    r++;
  }
   printf("\n");

  printf("SPORTS : CHENNAI V/S KOLKATA");
  printf("\n");

  printf("DATE : 16/05/2015");
  printf("\n");

  printf("You opted for %s and the time of your event is %d",curr->name,curr->time1);
printf("\n Press any key to make payment...");
getch();
payment();


//  strcpy(ch,current->name);

}


void movies()
{
	printf("\ta.) PIKU.\n");
	printf("\tb.) F&F7.\n");
	printf("\tc.) AVENGERS2.\n");
	printf("\td.) GABBAR IS BACK.\n");

	printf("Enter Your Movie : ");
	scanf("%c",&m);
	switch(m)
	{
		case 'a':
		case 'A':
			piku();
			break;

		case 'b':
		case 'B':
			  f7();
			  break;

		case 'c':
		case 'C':
			avengers2();
			break;

		case 'd':
		case 'D':
			gabbar();
			break;

		default:
			printf("Wrong choice");
	}
	getche();
}

void piku()
{
    int ch;
    while(i<5)
    {


      x=(struct venue*)malloc(sizeof(struct venue));
      x->ptr=NULL;

      if(start==NULL)
      {

	start=end=x;
      }
      else
      {

	end->ptr=x;
	end=x;

      }

      if(i==1)
      {
	fflush(stdin);
	strcpy(end->name,"1. PACIFIC.");
	fflush(stdin);
	x->time1=1000;
	fflush(stdin);
	x->time2=1200;

      }

      if(i==2)
      {
	fflush(stdin);
	strcpy(end->name,"2. GIP.");
	fflush(stdin);
	x->time1=1300;
	fflush(stdin);
	x->time2=1500;

      }

      if(i==3)
      {
	fflush(stdin);
	strcpy(end->name,"3. AMBIENCE.");
	fflush(stdin);
	x->time1=1400;
	fflush(stdin);
	x->time2=1600;
      }

      if(i==4)
      {
       fflush(stdin);
       strcpy(end->name,"4. MAHAGUN.");
       fflush(stdin);
       x->time1=1700;
       fflush(stdin);
       x->time2=1900;
      }
      i++;

  }


  current=start;

  while(current!=NULL)
  {
    flushall();

    printf("\n");
    puts(current->name);
    printf("\n\t\t");

    printf("%d\n\t\t%d",current->time1,current->time2);
    current=current->ptr;
    printf("\n");

  }

  printf("Enter Your Location : ");
  fflush(stdin);
  scanf("%d",&d);

  printf("Enter Your Time (24 HRS Format) : ");
  scanf("%d",&e);

  current=start;

  while(r<d)
  {
    current=current->ptr;
    r++;
  }
   printf("\n");

  printf("MOVIE : PIKU");
  printf("\n");

  printf("DATE : 16/05/2015");
  printf("\n");

  printf("You opted for %s and the time of your show is %d",current->name,e);
  printf("\n Proceed to book your seats.");
  delay(500);
  ticket_booking();
printf("\n Press any key to make payment...");
getch();
payment();
  strcpy(ch,current->name);
}


    void f7()
    {

    int ch;
    while(i<5)
    {


      x=(struct venue*)malloc(sizeof(struct venue));
      x->ptr=NULL;

      if(start==NULL)
      {

	start=end=x;
      }
      else
      {

	end->ptr=x;
	end=x;

      }

      if(i==1)
      {
	fflush(stdin);
	strcpy(end->name,"1. DT SAKET.");
	fflush(stdin);
	x->time1=1100;
	fflush(stdin);
	x->time2=1330;

      }

      if(i==2)
      {
	fflush(stdin);
	strcpy(end->name,"2. V3S.");
	fflush(stdin);
	x->time1=1530;
	fflush(stdin);
	x->time2=1800;

      }

      if(i==3)
      {
	fflush(stdin);
	strcpy(end->name,"3. CRM.");
	fflush(stdin);
	x->time1=1400;
	fflush(stdin);
	x->time2=1600;
      }

      if(i==4)
      {
       fflush(stdin);
       strcpy(end->name,"4. SHIPRA.");
       fflush(stdin);
       x->time1=1750;
       fflush(stdin);
       x->time2=1200;
      }
      i++;

  }


  current=start;

  while(current!=NULL)
  {
    flushall();
    puts(current->name);
    printf("\n\t\t");

    printf("%d\n\t\t%d",current->time1,current->time2);
    current=current->ptr;
    printf("\n");

  }

  printf("Enter Your Location : ");
  fflush(stdin);
  scanf("%d",&d);

  printf("Enter Your Time (24 HRS FORMAT) : ");
  scanf("%d",&e);

  current=start;

  while(r<d)
  {
    current=current->ptr;
    r++;
  }

     printf("\n");
  printf("MOVIE : FAST AND FURIOUS 7\n");
  printf("\n");

  printf("DATE : 16/05/2015");
  printf("\n");

  printf("You opted for %s and the time of your show is %d",current->name,e);
  printf("\n Proceed to book your seats.....");
  delay(500);
  ticket_booking();
printf("\n Press any key to make payment...");
getch();
payment();
  strcpy(ch,current->name);

 }



 void avengers2()
 {

    int ch;
    while(i<5)
    {


      x=(struct venue*)malloc(sizeof(struct venue));
      x->ptr=NULL;

      if(start==NULL)
      {

	start=end=x;
      }
      else
      {

	end->ptr=x;
	end=x;

      }

      if(i==1)
      {
	fflush(stdin);
	strcpy(end->name,"1. SATYAM");
	fflush(stdin);
	x->time1=1345;
	fflush(stdin);
	x->time2=1640;

      }

      if(i==2)
      {
	fflush(stdin);
	strcpy(end->name,"2. DELIGHT");
	fflush(stdin);
	x->time1=1315;
	fflush(stdin);
	x->time2=1900;

      }

      if(i==3)
      {
	fflush(stdin);
	strcpy(end->name,"3. MCINEMAS");
	fflush(stdin);
	x->time1=1430;
	fflush(stdin);
	x->time2=1000;
      }

      if(i==4)
      {
       fflush(stdin);
       strcpy(end->name,"4. ADITYA");
       fflush(stdin);
       x->time1=1720;
       fflush(stdin);
       x->time2=1150;
      }
      i++;

  }


  current=start;

  while(current!=NULL)
  {
    flushall();
    puts(current->name);
    printf("\n\t\t");

    printf("%d\n\t\t%d",current->time1,current->time2);
    current=current->ptr;
    printf("\n");

  }

  printf("Enter Your Location. ");
  fflush(stdin);
  scanf("%d",&d);

  printf("Enter Your Time (24 HRS FORMAT) : ");
  scanf("%d",&e);

  current=start;

  while(r<d)
  {
    current=current->ptr;
    r++;
  }

  printf("\n");
  printf("MOVIE : AVENGERS2");
  printf("\n");

  printf("DATE : 16/05/2015");
  printf("\n");

  printf("You opted for %s and the time of your show is %d",current->name,e);
  printf("\n Proceed to book your seats....");
  delay(500);
  ticket_booking();
printf("\n Press any key to make payment...");
getch();
payment();
  strcpy(ch,current->name);

 }

 void gabbar()
 {

    int ch;
    while(i<5)
    {


      x=(struct venue*)malloc(sizeof(struct venue));
      x->ptr=NULL;

      if(start==NULL)
      {

	start=end=x;
      }
      else
      {

	end->ptr=x;
	end=x;

      }

      if(i==1)
      {
	fflush(stdin);
	strcpy(end->name,"1. WAVE");
	fflush(stdin);
	x->time1=1025;
	fflush(stdin);
	x->time2=1500;

      }

      if(i==2)
      {
	fflush(stdin);
	strcpy(end->name,"2. QCINEMAS");
	fflush(stdin);
	x->time1=1300;
	fflush(stdin);
	x->time2=1550;

      }

      if(i==3)
      {
	fflush(stdin);
	strcpy(end->name,"3. EROSONE");
	fflush(stdin);
	x->time1=1410;
	fflush(stdin);
	x->time2=1655;
      }

      if(i==4)
      {
       fflush(stdin);
       strcpy(end->name,"4. M2K");
       fflush(stdin);
       x->time1=1740;
       fflush(stdin);
       x->time2=2000;
      }
      i++;

  }


  current=start;

  while(current!=NULL)
  {
    flushall();
    puts(current->name);
    printf("\n\t\t");

    printf("%d\n\t\t%d",current->time1,current->time2);
    current=current->ptr;
    printf("\n");

  }

  printf("Enter Your Location : ");
  fflush(stdin);
  scanf("%d",&d);
  printf("\n");
  printf("Enter Your Time (24 HRS FORMAT) : ");
  scanf("%d",&e);

  current=start;

  while(r<d)
  {
    current=current->ptr;
    r++;
  }
	       printf("\n");

  printf("MOVIE : GABBAR");
  printf("\n");

  printf("DATE : 16/05/2015");
  printf("\n");

  printf("You opted for %s and the time of your show is %d",current->name,e);
  printf("\n Proceed to book your seats...");
  delay(500);
  ticket_booking();
printf("\n Press any key to make payment...");
getch();
payment();
  strcpy(ch,current->name);
}

void choices()
{
  int gd=DETECT,gm;
  int i=0;

  clrscr();
  initgraph(&gd,&gm,"C:\\TC\\BGI");

  setbkcolor(RED);


  for(i=0;i<175;i=i+5)
  {


  settextstyle(10,HORIZ_DIR,2);

  outtextxy(145,10,"CHOOSE YOUR OPTION");


  line(10,90,630,90);          //line divider top1
  line(10,87,630,87);         //line divider top2

  line(230,90,230,480);      //line divider left
  line(420,90,420,480);      //line divider right

  rectangle(5,5,635,475);
  rectangle(10,10,630,470);

  circle(100,150,8);         //spectcles
  circle(125,150,8);
  line (108,150,117,150);

  line(93,150,100,135);     //left spectacles
  line(100,135,102,139);

  line(133,150,140,135);    //right spectacles
  line(140,135,142,139);

  line(170,135,176,160);    //glass(pepsi)
  line(170,135,194,135);
  line(176,160,188,160);
  line(194,135,188,160);   //

  line(182,135,185,120);   //straw left
  line(184,135,187,120);         //right

   settextstyle(4,HORIZ_DIR,4);

  outtextxy(70,200,"MOVIES");



  line(330,200,300,300);     //bat left
  line(360,210,330,310);           //right
				     //top
  line(330,200,360,210);                //bottom
  line(300,300,330,310);

  line(344,205,352,180); //handle left
  line(349,205,357,182);    //handle right
  line(352,180,357,182); //handle top

  circle(360,300,5);      //ball

  circle(320,340,13);    //men
  line(320,353,320,410);

  line(320,365,310,375); //hand left
  line(320,365,330,375);       //hand right

  line(320,400,310,410);  //leg left
  line(320,400,330,410);          //leg right

  circle(315,338,2);   //eye left
  circle(324,338,2);         //eye right

  line(320,342,320,346);  //nose

  line(316,349,323,349);   //mouth
  line(316,349,314,347);
  line(323,349,325,347);


  outtextxy(270,130,"SPORTS");


  rectangle(520,350,530,400);
  rectangle(515,400,535,407);

  line(524,350-i,524,340-i);

  line(526,350-i,526,340-i);


  delay (50);

  }

    cleardevice();

  settextstyle(10,HORIZ_DIR,2);

  outtextxy(145,10,"CHOOSE YOUR OPTION");


  line(10,90,630,90);          //line divider top1
  line(10,87,630,87);         //line divider top2

  line(230,90,230,480);      //line divider left
  line(420,90,420,480);      //line divider right

  rectangle(5,5,635,475);
  rectangle(10,10,630,470);

  circle(100,150,8);         //spectcles
  circle(125,150,8);
  line (108,150,117,150);

  line(93,150,100,135);     //left spectacles
  line(100,135,102,139);

  line(133,150,140,135);    //right spectacles
  line(140,135,142,139);

  line(170,135,176,160);    //glass(pepsi)
  line(170,135,194,135);
  line(176,160,188,160);
  line(194,135,188,160);   //

  line(182,135,185,120);   //straw left
  line(184,135,187,120);         //right

   settextstyle(4,HORIZ_DIR,4);

  outtextxy(70,200,"MOVIES");



  line(330,200,300,300);     //bat left
  line(360,210,330,310);           //right
				     //top
  line(330,200,360,210);                //bottom
  line(300,300,330,310);

  line(344,205,352,180); //handle left
  line(349,205,357,182);    //handle right
  line(352,180,357,182); //handle top

  circle(360,300,5);      //ball

  circle(320,340,13);    //men
  line(320,353,320,410);

  line(320,365,310,375); //hand left
  line(320,365,330,375);       //hand right

  line(320,400,310,410);  //leg left
  line(320,400,330,410);          //leg right

  circle(315,338,2);   //eye left
  circle(324,338,2);         //eye right

  line(320,342,320,346);  //nose

  line(316,349,323,349);   //mouth
  line(316,349,314,347);
  line(323,349,325,347);


  outtextxy(270,130,"SPORTS");

 // for(i=0;i<150;i=i+5)
 // {
  rectangle(520,350,530,400);
  rectangle(515,400,535,407);

  //line(524,350-i,524,340-i);

 // line(526,350-i,526,340-i);

   line(524,175,524,165);
   line(526,175,526,165);

   circle(525,170,1);

   circle(517,175,1);  circle(514,178,1);  circle(526,175,1);   circle(529,178,1);
   circle(514,172,1);  circle(511,181,1);  circle(529,172,1);   circle(532,181,1);
   circle(511,169,1);                      circle(532,169,1);

   circle(524,175,1);  circle(522,178,1);  circle(535,175,1);   circle(538,172,1);
   circle(522,172,1);  circle(520,181,1);  circle(537,178,1);   circle(540,169,1);
   circle(520,169,1);                      circle(539,181,1);

   circle(525,167,1);
   circle(523,164,1);
   circle(521,161,1);

   circle(527,164,1);
   circle(529,161,1);

   outtextxy(428,250,"FESTIVALS");
}

void login()
{
    FILE *fp;
    char user_identity[100];
    char security_key[100];
    struct user_details
    {
	char user_name[100];
	char user_id[100];
	char mobile_no[100];
	char email_id[100];
	char pwd[100];
	char re_pwd[100];
    };
    struct user_details u_d[10];
    int l = 0, i;
    char c;
    fp = fopen("SIGNUP.TXT", "r");
    printf("\n\n\t\t\t\tLogin\n\n");
    while(1)
    {
	c = fgetc(fp);
	if(c == EOF)
	    break;

	if(c == '\n')
	    l++;
    }
    //printf("\n %d", l);
    rewind(fp);
    i = 0;
    while(i<l/6)
    {
	    fseek(fp, 0, SEEK_CUR);
	    fgets(u_d[i].user_name, 100, fp);
	    //printf("\n");
	    //puts(u_d[i].user_name);
	    fseek(fp, 0, SEEK_CUR);
	    fgets(u_d[i].user_id, 100, fp);
	    //puts(u_d[i].user_id);
	    fseek(fp, 0, SEEK_CUR);
	    fgets(u_d[i].mobile_no, 100, fp);
	    //puts(u_d[i].mobile_no);
	    fseek(fp, 0, SEEK_CUR);
	    fgets(u_d[i].email_id, 100, fp);
	    //puts(u_d[i].email_id);
	    fseek(fp, 0, SEEK_CUR);
	    fgets(u_d[i].pwd, 100, fp);
	    //puts(u_d[i].pwd);
	    fseek(fp, 0, SEEK_CUR);
	    fgets(u_d[i].re_pwd, 100, fp);
	    //puts(u_d[i].re_pwd);
	    i++;
    }
    fclose(fp);
    /*for(i =0; i<l/6; i++)
    {
	printf("\n User = %d \n", i+1);
	puts(u_d[i].user_name);
	puts(u_d[i].user_id);
	puts(u_d[i].mobile_no);
	puts(u_d[i].email_id);
	puts(u_d[i].pwd);
	puts(u_d[i].re_pwd);
    }*/

    i = 0;
    while(i<l/6)
    {
	ptr = (struct user *)malloc(sizeof(struct user));
	strcpy(ptr -> user_name, u_d[i].user_name);
	strcpy(ptr -> user_id, u_d[i].user_id);
	strcpy(ptr -> mobile_no, u_d[i].mobile_no);
	strcpy(ptr -> email_id, u_d[i].email_id);
	strcpy(ptr -> pwd, u_d[i].pwd);
	strcpy(ptr -> re_pwd, u_d[i].re_pwd);
	ptr -> next = NULL;
	if(head == NULL)
	{
	    head = ptr;
	    present = ptr;
	}
	else
	{
	    present -> next = ptr;
	    present = ptr;
	}
	i++;
    }
    //display(start);
    search(head);
}

void display(struct user *head_ref)
{
    int count = 1;
    int i = 0;
    present = head_ref;
    while(current != NULL)
    {
	printf("\n Node = %d, user_name = %s", count, present->user_name);
	printf("\n Node = %d, user_id = %s", count, present->user_id);
	printf("\n Node = %d, mobile_no = %s", count, present->mobile_no);
	printf("\n Node = %d, email_id = %s", count, present->email_id);
	printf("\n Node = %d, pwd = %s", count, present->pwd);
	printf("\n Node = %d, re_pwd = %s", count, present->re_pwd);
	present = present->next;
	count++;
    }
}

void search(struct user *head_ref)
{
    char mobile_no[100];
    char password[100];
    int a, b;
    char c;
    int flag = 0, pos = 0;;
    printf("\n Mobile No : ");
    gets(mobile_no);
    printf("\n Password : ");
    do
    {
	c = getch();
	if(isprint(c))
	{
	    password[pos++] = c;
	    printf("%c", '*');
	}
	else if( c == 8 && pos)
	{
	    password[pos--] = '\0';
	    printf("%s", "\b \b");
	}
    }while(c != 13);
    present = head_ref;
    while(present != NULL)
    {
	a = strcmp(present -> mobile_no, mobile_no);
	b = strcmp(present -> pwd, password);
	//printf("\n %d %d", a, b);
	if(a != 0 && b != 0)
	{
	    flag = 1;
	}
	else
	{
	    flag = 0;
	}
	if(flag == 1)
	{
	    printf("\n Welcome ");
	    puts(present -> user_name);
	}
	present = present -> next;
    }
}

void signup()
{
    FILE *fp;
    char user_name[20];
    char name[20];
    char mob_no[10];
    char pwd[256] = {0};
    char re_pwd[256] = {0};
    char email_id[100] = {0};
    char c, d;
    int position = 0, pos = 0;
    char btn;
    fflush(stdin);
    fp = fopen("SIGNUP.txt", "a");
    printf("\n\n\t\t\t\tSIGNUP\n\n");
    printf("\n Name : ");
    gets(name);
    fputs(name, fp);
    fprintf(fp, "\n");
    printf("\n User Name : ");
    gets(user_name);
    fputs(user_name, fp);
    fprintf(fp, "\n");
    printf("\n Mobile No : ");
    gets(mob_no);
    fputs(mob_no, fp);
    fprintf(fp, "\n");
    printf("\n Email Id : ");
    gets(email_id);
    fputs(email_id, fp);
    fprintf(fp, "\n");
    printf("\n Password : ");
    do
    {
	c = getch();
	if(isprint(c))
	{
	    pwd[position++] = c;
	    printf("%c", '*');
	}
	else if( c == 8 && position)
	{
	    pwd[position--] = '\0';
	    printf("%s", "\b \b");
	}
    }while(c != 13);
    fputs(pwd, fp);
    fprintf(fp, "\n");
    printf("\n Re Enter Password : ");
    do
    {
	d = getch();
	if(isprint(d))
	{
	    re_pwd[pos++] = d;
	    printf("%c", '*');
	}
	else if( d == 8 && pos)
	{
	    re_pwd[pos--] = '\0';
	    printf("%s", "\b \b");
	}
    }while(d != 13);
    pos = 0;
    if(!strcmp(pwd, re_pwd))
    {
	printf("\n SUCEESFULLY REGISTERD........");
	fputs(re_pwd, fp);
    }
    else
    {
	printf("\n PASSWORD DOES NOT MATCH...... Please re Enter Password..");
	printf("\n Re Enter Password : ");
	do
	{
	    d = getch();
	    if(isprint(d))
	    {
		re_pwd[pos++] = d;
		printf("%c", '*');
	    }
	    else if( d == 8 && pos)
	    {
		re_pwd[pos--] = '\0';
		printf("%s", "\b \b");
	    }
	}while(d != 13);
	if(!strcmp(pwd, re_pwd))
	{
	    printf("\n SUCEESFULLY REGISTERD........");
	    fputs(re_pwd, fp);
	}
    }
    fprintf(fp, "\n");
    fclose(fp);
    position = 0;
    pos = 0;
}

void main()
{
  int gd=DETECT,gm;
  int i,j;
  char ch, key;

  initgraph(&gd,&gm,"C:\\TC\\bgi");

  setbkcolor(RED);

  settextstyle(7,HORIZ_DIR,7);

  outtextxy(180,200,"O");
  delay(200);

  outtextxy(205,200,"P");
  delay(200);

  outtextxy(253,200,"T");
  delay(200);

  outtextxy(280,200,"R");
  delay(200);

  outtextxy(325,200,"A");
  delay(400);


  settextstyle(3,HORIZ_DIR,3);
  outtextxy(350,270,"Booking khushiyon ki...");

  getch();
  cleardevice();
  settextstyle(2,HORIZ_DIR,9);
  setbkcolor(RED);

  outtextxy(60, 50, "_____________________________");
  outtextxy(60,50,"SIGN IN TO ENJOY THE SERVICES!");
  setcolor(WHITE);
  rectangle(150,150,350,350);
  rectangle(148, 152, 348, 352);

  settextstyle(2,HORIZ_DIR,4);
  outtextxy(170,190,"USERNAME");

  rectangle(220,190,340,205);
  rectangle(222, 192, 342, 207);

  outtextxy(170,240,"PASSWORD");

  rectangle(220,238,340,253);
  rectangle(222, 240, 342, 255);

  rectangle(215,300,250,315);
  outtextxy(220,300,"Login");

  rectangle(217, 321, 332, 337);
  outtextxy(220,320,"New user | Sign Up");

  gotoxy(220, 300);
  printf("\n Press 1 to login and 2 for signup...");
  ch = getch();

  if(ch == '1')
  {
	cleardevice();
	login();
	printf("\n Press any key to continue.....");
	getch();
	cleardevice();
	choices();
	printf("\n Press 1 for movie, 2 for sports, 3 for festivals..");
	key = getch();

	if(key == '1')
	{
		cleardevice();
		setbkcolor(RED);
		movies();
	}

	if(key == '2')
	{
		cleardevice();
		setbkcolor(RED);
		sports();
	}

	if(key == '3')
	{
		cleardevice();
		setbkcolor(RED);
		events();
	}

  }
  if(ch == '2')
  {
	cleardevice();
	signup();
  }
  getch();

}

