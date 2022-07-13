#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>

struct customer
{
  char name[20];
  int age;
  char DOB[15];
  char nationality[20];
  char address[50];
  char bank_name[35];
  char account_type[25];
  char card_no[13];
  long int contact_no;
  float avail_bal;
  long int accno;
  int pin;
};

typedef struct customer CUSTOMER;
CUSTOMER c[10] = {{"Sharan",17,"17/11/2003","Indian","Attur Layout","Bank Of Baroda","Saving Account"},
                  {"Harshith",25,"20/01/1997","Indian","Vidyaranyapura","Canara Bank","Saving Account"},
                  {"Aneesh",19,"23/01/2002","Indian","Yeshwanthpur","Indian Bank","Savings Account"}};

float acc_bal(int i)
{
  float balance;
  balance = c[i].avail_bal;
  return(balance);
}

void withdraw(int i)
{
  float balance,amount;
  int choice;
  for(;;)
  {
   printf("Enter the amount to be withdrawn : ");
   scanf("%f",&amount);
   printf("\n");
   balance = acc_bal(i);

   if(amount > balance-1000)
   {
    printf("Insufficient balance. Minimum balance must be 1000\n");
    printf("Available balance = %f\n",balance);
   }
  /* if(amount%100!=0)
    {
      printf("Money can be withdrawn only in denominations of 100.\n");
    }*/

    else
   {
     if(amount > 10000)
     printf("Maximum amount that can be withdrawn at a time = 10000\n");
     else
    {
     balance = balance - amount;
     c[i].avail_bal=balance;
     return;
    }
   }
    printf("Press 1 to continue with withdrawal or 0 to return to menu : ");
    scanf("%d",&choice);
    printf("\n");

    if(choice == 1)
      continue;
    else
      return;
    }
}

void deposit(int i)
{
  float balance,amount;
  int choice;
  for(;;)
 {
   printf("Enter the amount to be deposited : ");
   scanf("%f",&amount);
   printf("\n");
   balance = acc_bal(i);

   if(amount>30000)
      printf("Maximum amount that can be deposited at a time = 30000\n");
   else
  {
     balance = balance + amount;
     c[i].avail_bal = balance;
     return;
  }


     printf("Press 1 to continue with deposit or 0 to return to menu : ");
     scanf("%d",&choice);
     printf("\n");

     if(choice==1)
       continue;
     else
       return;
  }
}


void user(int var)
{
  char pinconfirm[5],pin[5],password[5],cno[13],cno1[] = {"765490123288"};
  int i=0,n,loop=1,p=0,val,finalpin;

  start:
    printf("Welcome to the ATM\n 1.New User \n 2.Existing User \n");
    scanf("%d",&n);

  if(n == 1)
 {
   printf("Thank You for taking our services \n Please provide the following detail to give a PIN to your card\n");
   printf("Enter your Card number= ");
   scanf("%s",cno);
   val=strcmp(cno1,cno);

   if(val==0)
  {
     printf("Enter your pin = ");
     printf("Please set 4 digit pin code: ");
     printf("password:\n");

    do
    {
      password[p]=getch();
      if(password[p]!='\r')
      {
         printf("*");
      }
      p++;
    }while(password[p-1]!='\r');

     password[p-1]='\0';
     printf("\nYou have entered %s as password.",password);
     finalpin = atoi(password);
     c[var].pin=finalpin;
   }

   else
  {
     printf("Try again ");
     goto start ;
  }
 }
}


void customer_details(long int accno)
{
  int i;
  for(i=0; i<3; i++)
  {
     if(accno == c[i].accno)
    {
      printf("\nNAME: %s",c[i].name);
      printf("\nAGE: %d",c[i].age);
      printf("\nDOB(DD/MM/YYYY): %s",c[i].DOB);
      printf("\nNATIONALITY: %s",c[i].nationality);
      printf("\nADDRESS: %s",c[i].address);
      printf("\nBANK NAME: %s",c[i].bank_name);
      printf("\nACCOUNT TYPE: %s",c[i].account_type);
      printf("\nCARD NUMBER: %ld",c[i].card_no);
      printf("\nBALANCE:Rs. %f",c[i].avail_bal);
      break;
    }
  }
}

struct info
{
  int balance;
  int credited;
  int debited;
  char date[20];
  char time[20];
};

struct info trans[5]={
     {10000,4000,2000,"1/1/2020","9:28:23am"},
     {23000,300,260,"2/5/2020","2:33:01pm"},
     {19000,200,830,"6/5/2020","6:00:45pm"},
     {10000,800,100,"16/6/2020","10:00:59pm"},
     {14030,377,20,"20/9/2020","1:00:10pm"}
};

struct info trans1[3]= {
     {10220,5400,3330,"1/1/2020","7:48:36pm"},
     {23110,999,1600,"24/2/2020","1:53:19am"},
     {11000,200,830,"16/6/2020","9:00:49am"}
};

void display(struct info trans[5])
{
  int i,len=5;
  for(i=0;i<len;i++)
 {
   printf("Balance:%d\n",trans[i].balance);
   printf("Credited:%d\n",trans[i].credited);
   printf("Debited:%d\n",trans[i].debited);
   printf("Date:%s\n",trans[i].date);
   printf("Time:%s\n",trans[i].time);
   printf("\n");
 }
}

 /*void display1(struct info trans1[3])
  {
    int j,len1=3;
    for(j=0;j<len1;j++)
   {
     printf("Balance:%d\n",trans1[j].balance1);
     printf("Credited:%d\n",trans1[j].credited1);
     printf("Debited:%d\n",trans1[j].debited1);
     printf("Date:%s\n",trans1[j].date1);
     printf("Time:%s\n",trans1[j].time1);
     printf("\n");
   }
  }*/

void feedback()
{
    char ch[10],time[10],c[10],rush[10],choice,notes[10]; int cho, sml=1, i,k;
    printf("Are you satisfied with the service [Yes/No] ?");
    scanf("%s",ch);
    fflush(stdin);
    printf("Do u wish to continue\n");
    scanf("%c",&choice);
    fflush(stdin);

    if(choice=='n'||choice=='N')
   {
      for(i=0; i<5; i++)
      printf("%c ",sml);
      printf("Have nice day");
      exit(0);
   }

   else
  {
     printf("How long you had to wait for the transaction operation ?");
     scanf("%s",time);
     printf("Is the ATM room neat and hygenic ?");
     scanf("%s",c);
     printf("Was there any crowd formed near ATM ?");
     scanf("%s",rush);
     printf("Did you receive any torn notes / old notes / demonitized notes ?");
     scanf("%s",notes);
     printf("How would you rate our service \n 1.Best \n 2.Good \n 3.Average \n 4.Bad \n 5.Very Bad\n");
     scanf("%d",&cho);

     switch(cho)
    {
      case 1:
               for(i=0; i<5; i++)
                  printf("%c ",sml);
               printf("Have nice day");
               break;

     case 2:
               for(i=0; i<5; i++)
                 printf("%c ",sml);
               printf("Have nice day");
               break;

    case 3:
              for(i=0; i<5; i++)
                printf("%c ",sml);
              printf("Have nice day");
              break;

    case 4:
             for(i=0; i<5; i++)
               printf("%c ",sml);
             printf("Have nice day");
             break;

    case 5:
            for(i=0; i<5; i++)
               printf("%c ",sml);
            printf("Have nice day");
            break;

    default: printf("Have nice day");
   }
  }
}

void main()
{
   char card_num[13];
   int var1=-1,pin,i,j,choice;
   float balance;

   label:

   for(;;)
  {
     printf("\n\n\n*************Welcome to our ATM*************\n\n\n");
     printf("Enter your card number : ");
     scanf("%s",card_num);
     printf("\n");

     for(i=0;i<3;i++)
    {
      if(strcmp(c[i].card_no,card_num)==0)
      {
        var1=i;
        break;
      }
    }

     if(var1==-1)
    {
      printf("Invalid card number\n");
      goto label;
    }

   else
  {
    for(j=1;j<=3;j++)
   {
      printf("Enter your PIN : ");
      scanf("%d",&pin);
      printf("\n");

      if(pin == c[var1].pin)
         break;
      else
        printf("Invalid PIN\n");
   }
  }

  if(j == 4)
 {
    printf("You have made three unsuccessful attempts to enter PIN.\nHave a nice day.\n");
    goto label;
 }

 else
{
   for(;;)
  {
    printf("Our ATM provides a wide range of options.\n");
    printf("Please select the option according to the transaction you wish to perform..");
    printf("Your options are :\n");
    printf("1.Withdrawal of Money\n2.Deposit of Money\n3.Check Account Balance\n");
    printf("4.Check your Account Details\n5.Check Transaction History\n6.Generation of pin for new users\n7.Customer Feedback\n8.End ATM transaction\n");
    printf("Enter your choice : ");
    scanf("%d",&choice);

    printf("\n");

    switch(choice)
   {
      case 1 : withdraw(var1);
               break;

      case 2 : deposit(var1);
               break;

      case 3 : balance=acc_bal(var1);
               printf("Your remaining account balance : %f\n",balance);
               break;

      case 4 : customer_details(c[var1].accno);
               break;

      case 5 : if(var1 == 0)
                 display(trans);

               else if(var1==1)
                 display(trans1);

              else if(var1==2)
                printf("Transaction History : Empty\n");
              break;

     case 6 : user(var1);
              break;

     case 7 : feedback();
              break;

     case 8 : goto label;
     default : printf("Invalid choice\n");

    }
   }
  }
 }
}


