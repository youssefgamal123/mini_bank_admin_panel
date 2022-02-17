#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <windows.h>

// defualt credintials
 char def_usrename[]="admin";
int def_password=12345;
int i ;
int main_exit;
struct date{
    int month,day,year;

    };

struct {

    char name[60];
    int acc_no,age;
    char address[60];
    char citizenship[15];
    double phone;
    char acc_type[10];
    float amt;
    struct date dob;
    struct date deposit;
    struct date withdraw;

  }add,check,upd,transaction,rem;



int login();
void fordelay(int j);
void erase();
void new_acc();
void menu(void);
void edit();
void transact();
void reset_password();


void main(){


login();

}






int login (){


char username[25];
int password;
printf("Enter Username :");
scanf("%25s",&username);
fflush(stdin);
printf("Enter Pssword : ");
scanf("%d",&password);


if (strcmp(username,def_usrename)==0 && password==def_password){


          printf("\n\nPassword Match!\nLOADING");
        for(i=0;i<=6;i++)
        {
            fordelay(100000000);
            printf(".");
        }
                system("cls");
                menu();

}

  else
      {   printf("\n\nWrong password!!\a\a\a");
          login_try:
          printf("\nEnter 1 to try again and 0 to exit:");
          fflush(stdin);
          scanf("%d",&main_exit);
          if (main_exit==1)
                  {

                      system("cls");
                      main();
                  }

          else if (main_exit==0)
                  {
                  system("cls");
                  exit(1);}
          else
                  {printf("\nInvalid!");
                  fordelay(1000000000);
                  system("cls");
                  goto login_try;}

      }
      return 0;






}
void fordelay(int j)
{   int i,k;
    for(i=0;i<j;i++)
         k=i;
}

void menu(void)
{   int choice;
    system("cls");
    system("color 9");
    printf("\n\n\t\t\tCUSTOMER ACCOUNT BANKING MANAGEMENT SYSTEM");
    printf("\n\n\n\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2 WELCOME TO THE MAIN MENU \xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    printf("\n\n\t\t1.Create new account\n\t\t2.Update information of existing account\n\t\t3.For transactions\n\t\t4.Removing existing account\n\t\t5.Exit\n\t\t6.Reset Password\n\n\t\n\t Enter your choice:");
    scanf("%d",&choice);

    system("cls");
    switch(choice)
    {
        case 1:new_acc();
        break;
        case 2:edit();
        break;
        case 3:transact();
        break;
        case 4:erase();
        break;
        case 5:exit(1);
        case 6:reset_password();
        break;

    }



}

  void new_acc()

  {
      int choice;
      FILE *ptr;

      ptr=fopen("record.dat","a+");
      account_no:
      system("cls");
      printf(" ADD RECORD  ");
      printf("\n\n\nEnter today's date(mm/dd/yyyy):");
      scanf("%d/%d/%d",&add.deposit.month,&add.deposit.day,&add.deposit.year);
      printf("\nEnter the account number:");
      scanf("%d",&check.acc_no);
      while(fscanf(ptr,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",&add.acc_no,add.name,&add.dob.month,&add.dob.day,&add.dob.year,&add.age,add.address,add.citizenship,&add.phone,add.acc_type,&add.amt,&add.deposit.month,&add.deposit.day,&add.deposit.year)!=EOF)
      {
          if (check.acc_no==add.acc_no)
              {printf("Account no. already in use!");
              fordelay(1000000000);
                  goto account_no;

              }
      }
      add.acc_no=check.acc_no;
          printf("\nEnter the name:");
      scanf("%s",add.name);
      printf("\nEnter the date of birth(mm/dd/yyyy):");
      scanf("%d/%d/%d",&add.dob.month,&add.dob.day,&add.dob.year);
      printf("\nEnter the age:");
      scanf("%d",&add.age);
      printf("\nEnter the address:");
      scanf("%s",add.address);
      printf("\nEnter the citizenship number:");
      scanf("%s",add.citizenship);
      printf("\nEnter the phone number: ");
      scanf("%lf",&add.phone);
      printf("\nEnter the amount to deposit:$");
      scanf("%f",&add.amt);
      printf("\nType of account:\n\t#Saving\n\t#Current\n\t#Fixed1(for 1 year)\n\t#Fixed2(for 2 years)\n\t#Fixed3(for 3 years)\n\n\tEnter your choice:");
      scanf("%s",add.acc_type);

          fprintf(ptr,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",add.acc_no,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,add.address,add.citizenship,add.phone,add.acc_type,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);


      fclose(ptr);
      printf("\nAccount created successfully!");
      add_invalid:
      printf("\n\n\n\t\tEnter 1 to go to the main menu and 0 to exit:");
      scanf("%d",&main_exit);
      system("cls");
      if (main_exit==1)
          menu();
      else if(main_exit==0)
              close(1);
      else
          {
              printf("\nInvalid!\a");
              goto add_invalid;
          }
  }









  void edit(void)
  {
      int choice,test=0;
      FILE *old,*newrec;
      old=fopen("record.dat","r");
      newrec=fopen("new.dat","w");

      printf("\nEnter the account no. of the customer whose info you want to change:");
      scanf("%d",&upd.acc_no);
      while(fscanf(old,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d",&add.acc_no,add.name,&add.dob.month,&add.dob.day,&add.dob.year,&add.age,add.address,add.citizenship,&add.phone,add.acc_type,&add.amt,&add.deposit.month,&add.deposit.day,&add.deposit.year)!=EOF)
      {
          if (add.acc_no==upd.acc_no)
          {   test=1;
              printf("\nWhich information do you want to change?\n1.Address\n2.Phone\n\nEnter your choice(1 for address and 2 for phone):");
              scanf("%d",&choice);
              system("cls");
              if(choice==1)
                  {printf("Enter the new address:");
                  scanf("%s",upd.address);
                  fprintf(newrec,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",add.acc_no,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,upd.address,add.citizenship,add.phone,add.acc_type,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);
                  system("cls");
                  printf("Changes saved!");
                  }
              else if(choice==2)
                  {
                      printf("Enter the new phone number:");
                  scanf("%lf",&upd.phone);
                  fprintf(newrec,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",add.acc_no,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,add.address,add.citizenship,upd.phone,add.acc_type,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);
                  system("cls");
                  printf("Changes saved!");
                  }

          }
          else
              fprintf(newrec,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",add.acc_no,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,add.address,add.citizenship,add.phone,add.acc_type,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);
      }
      fclose(old);
      fclose(newrec);
      remove("record.dat");
      rename("new.dat","record.dat");

  if(test!=1)
          {   system("cls");
              printf("\nRecord not found!!\a\a\a");
              edit_invalid:
                printf("\nEnter 0 to try again,1 to return to main menu and 2 to exit:");
                scanf("%d",&main_exit);
                system("cls");
                   if (main_exit==1)

                      menu();
                  else if (main_exit==2)
                      close(1);
                  else if(main_exit==0)
                      edit();
                  else
                      {printf("\nInvalid!\a");
                      goto edit_invalid;}
          }
      else
          {printf("\n\n\nEnter 1 to go to the main menu and 0 to exit:");
          scanf("%d",&main_exit);
          system("cls");
          if (main_exit==1)
              menu();
          else
              close(1);
          }
  }
void erase(){
  FILE *old,*newrec;
  int test=0;
  old=fopen("record.dat","r");
  newrec=fopen("new.dat","w");
  printf("Enter the account no. of the customer you want to delete:");
  scanf("%d",&rem.acc_no);
  while (fscanf(old,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d",&add.acc_no,add.name,&add.dob.month,&add.dob.day,&add.dob.year,&add.age,add.address,add.citizenship,&add.phone,add.acc_type,&add.amt,&add.deposit.month,&add.deposit.day,&add.deposit.year)!=EOF)
  {
      if(add.acc_no!=rem.acc_no)
          fprintf(newrec,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",add.acc_no,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,add.address,add.citizenship,add.phone,add.acc_type,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);

      else
          {test++;
          printf("\nRecord deleted successfully!\n");
          }
  }
  fclose(old);
  fclose(newrec);
  remove("record.dat");
  rename("new.dat","record.dat");
  if(test==0)
      {
          printf("\nRecord not found!!\a\a\a");
          erase_invalid:
            printf("\nEnter 0 to try again,1 to return to main menu and 2 to exit:");
            scanf("%d",&main_exit);

               if (main_exit==1)
                  menu();
              else if (main_exit==2)
                  close(1);
              else if(main_exit==0)
                  erase();
              else
                  {printf("\nInvalid!\a");
                  goto erase_invalid;}
      }
  else
      {printf("\nEnter 1 to go to the main menu and 0 to exit:");
      scanf("%d",&main_exit);
      system("cls");
      if (main_exit==1)
          menu();
      else
          close(1);
      }

  }



void transact(void)
{   int choice,test=0;
    FILE *old,*newrec;
    old=fopen("record.dat","r");
    newrec=fopen("new.dat","w");

        printf("Enter the account no. of the customer:");
    scanf("%d",&transaction.acc_no);
    while (fscanf(old,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d",&add.acc_no,add.name,&add.dob.month,&add.dob.day,&add.dob.year,&add.age,add.address,add.citizenship,&add.phone,add.acc_type,&add.amt,&add.deposit.month,&add.deposit.day,&add.deposit.year)!=EOF)
   {

            if(add.acc_no==transaction.acc_no)
            {   test=1;
                if(strcmpi(add.acc_type,"fixed1")==0||strcmpi(add.acc_type,"fixed2")==0||strcmpi(add.acc_type,"fixed3")==0)
                {
                    printf("\a\a\a\n\nYOU CANNOT DEPOSIT OR WITHDRAW CASH IN FIXED ACCOUNTS!!!!!");
                    fordelay(1000000000);
                    system("cls");
                    menu();

                }
                printf("\n\nDo you want to\n1.Deposit\n2.Withdraw?\n\nEnter your choice(1 for deposit and 2 for withdraw):");
                scanf("%d",&choice);
                if (choice==1)
                {
                    printf("Enter the amount you want to deposit:$ ");
                    scanf("%f",&transaction.amt);
                    add.amt+=transaction.amt;
                    fprintf(newrec,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",add.acc_no,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,add.address,add.citizenship,add.phone,add.acc_type,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);
                    printf("\n\nDeposited successfully!");
                }
                else
                {
                    printf("Enter the amount you want to withdraw:$ ");
                    scanf("%f",&transaction.amt);
                    add.amt-=transaction.amt;
                    fprintf(newrec,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",add.acc_no,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,add.address,add.citizenship,add.phone,add.acc_type,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);
                    printf("\n\nWithdrawn successfully!");
                }

            }
            else
            {
               fprintf(newrec,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",add.acc_no,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,add.address,add.citizenship,add.phone,add.acc_type,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);
            }
   }
   fclose(old);
   fclose(newrec);
   remove("record.dat");
   rename("new.dat","record.dat");
   if(test!=1)
   {
       printf("\n\nRecord not found!!");
       transact_invalid:
      printf("\n\n\nEnter 0 to try again,1 to return to main menu and 2 to exit:");
      scanf("%d",&main_exit);
      system("cls");
      if (main_exit==0)
        transact();
    else if (main_exit==1)
        menu();
    else if (main_exit==2)
        close(1);
    else
    {
        printf("\nInvalid!");
        goto transact_invalid;
    }

   }
   else
   {
       printf("\nEnter 1 to go to the main menu and 0 to exit:");
        scanf("%d",&main_exit);
        system("cls");
        if (main_exit==1)
            menu();
        else
            close(1);
   }
 }

void reset_password(){
system("cls");
int c;
int usr_old_password;
int usr_new_password;
printf("Enter Old password : ");
scanf("%5d",&usr_old_password);

if (usr_old_password!=def_password){
  printf("Password Incorrect \n");
  printf("Enter 1 to try again or 0 to exit \n");
  printf("Enter Choice : ");
  fflush(stdin);
  scanf("%d",&c);
switch (c) {
  case 1: reset_password();
  case 2: exit(1);
}


}
else {
printf("Enter New Password : ");
scanf("%d",&usr_new_password);
def_password=usr_new_password;
printf("Enter 1 to login or 0 to exit \n");
printf("Enter Choice : ");
scanf("%d",&c);
switch (c) {
  case 1:login();
  case 0:exit(1);
}



}



}
