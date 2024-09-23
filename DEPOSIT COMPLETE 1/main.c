#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>



int num1,num2,num3,num4,num5,age,num[20],i=0,w=0,b=0,s=0,found,PIN;
char nic[20];
char name[100],line[100],fille[100],acc[20],acc2[50],count[100],ttr[30],acc1[30],dates[200],pin[30];
float money,num6,balnce;
void Acc();
void balance();
FILE *account;
FILE *acc_balance;
FILE *yes;
FILE*acc_no;

void fun1()
{

                printf(" \n\n\n\n\n\n\n\n\n\n\n\n\n");
    F2:         printf("                                   DO YOU HAVE A BANK ACCOUNT\n ");
                printf("                                           1-Yes,2-No\n");
                scanf("%d",&num1);
                if (num1==1)
                {
                    system("cls");

                    fun2();
                }

                else if(num1==2)
                {
                    system("cls");

                    fun3();
                }

                else
                {
                    system("cls");
                    printf(" \n\n\n\n\n\n\n\n\n\n\n\n\n");

                    printf("                                   INVALID INPUT!!!\n");
                    printf("                         PLEASE CHECK AND ENTER A VALIDE NUMBER\n");

                    sleep(3);

                    system("cls");

                    goto F2;

    }

}
void fun2()  //ask-What do you want to do
{

        printf(" \n\n\n\n\n\n\n\n\n\n\n\n\n");
F3:     printf("                                ------MENU-----\n");
        printf("                                   1)DEPOSIT\n");
        printf("                                   2)WITHDROWAL\n");
        printf("                                   3)CHECK YOR ACCOUNT BALANCE\n");
        printf("                                   4)GET BANK STATEMENT\n");
        printf("                                   5)EXIT\n");

        scanf("%d",&num2);

        switch (num2)
        {
        case 1:
            system("cls");
            deposit();
            break;

        case 2:
            system("cls");
            withdrowal();
            break;

        case 3:
            system("cls");
            balance();
            break;

        case 4:
            system("cls");
            statment();
            break;

        case 5:
            system("cls");
            finally();
            break;

        default:
            system("cls");

            printf(" \n\n\n\n\n\n\n\n\n\n\n\n\n");
            printf("                                   INVALID NUMBER!!!\n");
            printf("                           PLEASE CHECK AND ENTER A VALIDE NUMBER\n");

            sleep(3);

            system("cls");

            goto F3;

        }
}
void fun3()//ask- Do you want create a account?
{

                    printf(" \n\n\n\n\n\n\n\n\n\n\n\n\n");
        F1:         printf("                                   DO YOU WANT CREATE AN ACCOUNT?\n ");
                    printf("                                          1-Yes,2-No\n");
                    scanf("%d",&num3);

                    if(num3==1)
                        {
                            system("cls");
                            Acc();
                        }

                    else if(num3==2)
                        {
                           system("cls");
                           finally();

                        }

                    else
                        {
                                system("cls");

                                printf(" \n\n\n\n\n\n\n\n\n\n\n\n\n");
                                printf("                                   INVALID NUMBER!!!\n");
                                printf("                           PLEASE CHECK AND ENTER A VALIDE NUMBER\n");

                                sleep(3);

                                system("cls");

                                goto F1;
                        }
}
void Acc()// create account function
{
        //GET INFORMATION
                            printf("ENTER YOUR NAME-:\n");
                            scanf(" %[^\n]%*c",name);
                            printf("ENTER YOUR AGE-:\n");
                            scanf("%ld",&age);
                            printf("ENTER YOUR ID NUMBER-:\n");
                            scanf("%s",&nic);
                            printf("ENTER YOUR PIN NUMBER-:\n");
                            scanf("%d",&PIN);
                            system("cls");
            //waiting

                            for(int j=0;j<3;j++)
                            {
                                printf(" \n\n\n\n\n\n\n\n\n");
                                printf("                                         LOADING.....\n");
                                sleep(1);
                                system("cls");
                                sleep(1);
                            }

        // DISPLAY ACCOUNT DETAILS

                            printf(" \n\n\n\n\n\n\n\n\n");
                            printf("                                   ACCOUNT CREATE SUCCESSFULLY\n");
                            printf("                                     YOUR ACCOUT NUMBER IS\n");
                            printf("                                            %s",nic);

         //OPEN USER'S ACCOUNT FILE & WRITE DETAILS

                            sprintf(fille,"%s.txt",nic);
                            account=fopen(fille,"w");

                            fprintf(account,"\n\n\t\t\tBANK STATMENT\n");
                            fprintf(account,"\n\n\n\n   # NAME        =   %s\n",name);
                            fprintf(account,"   # Age         =   %d\n",age);
                            fprintf(account,"   # NIC         =   %s\n",nic);
                            fprintf(account,"   # ACCOUNT NO  =   %s\n\n\n\n\n\n",nic);

                            fprintf(account," -----------------------------------------------------------------------------------------\n");
                            fprintf(account," |   DATE   \t|\t    NOTE    \t|\t   AMOUNT  \t|\t   BALANCE\t|\n");
                            fprintf(account," -----------------------------------------------------------------------------------------\n");

                            fclose(account);

         //OPEN ACC_NUMBER FILL AND ADD NEW ACCOUNT NUMBER

                            acc_no=fopen("account_number.txt","a");
                            fprintf(acc_no,"%s %d %s, \n",nic,PIN,name);

                            fclose(acc_no);

        //OPEN NEW FILE FOR NOTE THE BALANCE

                            sprintf(fille,"B%s.txt",nic);
                            account=fopen(fille,"w");
                            fprintf(account,"0");
                            fclose(account);

                            ask();




}


void deposit()//deposit function
{
   while (i<3)
        {
            i++;
            printf("ENTER YOUR ACCOUNT NUMBER-:\n");
            scanf(" %s",&acc);
            printf("ENTER YOUR PIN NUMBER-:\n");
            scanf(" %s",&pin);
            acc_no=fopen("account_number.txt","r");

            //wait
            for(int j=0;j<3;j++)
                            {
                                printf(" \n\n\n\n\n\n\n\n\n");
                                printf("                                             LOADING.....\n");
                                sleep(1);
                                system("cls");
                                sleep(1);
                            }


             while (fgets(line, sizeof(line),acc_no) != NULL)

                {

                    char *token=strtok(line," ");

                    char*token1=strtok(NULL," ");


                        if (strcmp(token,acc) == 0 && strcmp(token1,pin) == 0)

                            {
                                char *token2=strtok(NULL,",");
                               // printf("####NAME = %s\n",token2);
                                system("cls");

                                printf("                                        YOUR NAME= %s\n",token2);
                                printf("                                       YOUR ACCOUNT NUMBER = %s\n",acc);


            //READ BALANCE FROM BALANCE FILE
                                sprintf(count,"B%s.txt",acc);
                                acc_balance=fopen(count,"r");

                                fscanf(acc_balance,"%s",&ttr);
                                //printf("###balance = %s\n",ttr);
                                fclose(acc_balance);

            //CONVERT STRING TO INT

                                char *value;
                                num6=strtof(ttr,&value);


            //GET AMOUNT OF MONEY

                                printf(" \n\n");
                                printf("  # ENTER AMOUT OF MONEY #\n");
                                scanf("                              %f",&money);
                                //printf("###MONEY = %f",money);


                    //CALCULATION

                                balnce=num6+money;
                                //printf("### TOTALE BALANCE = %.2f\n",balnce);


        //RE WRITE ACCOUNT IN "BALANCE" FILE

                                sprintf(count,"B%s.txt",acc);
                                acc_balance=fopen(count,"w");

                                fprintf(acc_balance,"%f",balnce);
                                fclose(acc_balance);


        //OPEN USER FILE AND WRITE DEPOSIT DETAILS

                                sprintf(fille,"%s.txt",acc);
                                account=fopen(fille,"a");
                                fprintf(account," |%10s\t|\t   DEPOSIT  \t|\t%10.2f\t|\t%11.2f\t|\n",dates,money,balnce);
                                fclose(account);


                //FINALE PART

                                system("cls");
                                printf(" \n\n\n\n\n\n\n\n\n");
                                printf("                                           DROP YOUR MONEY HERE\n");
                                sleep(3);
                                system("cls");

                                    //waiting

                            for(int j=0;j<4;j++)
                            {
                                printf(" \n\n\n\n\n\n\n\n\n");
                                printf("                                             LOADING.....\n");
                                sleep(1);
                                system("cls");
                                sleep(1);
                            }
                                printf(" \n\n\n\n\n\n\n\n\n");
                                printf("                                    Your Deposit is Successfully\n");
                                sleep(4);

                                system("cls");
                                i=0;


                                found=1;            //THIS ONE FOR BREAK 2ND WHILE LOOP , LOOK AT LINE: 2272
                                break;


                            }


                            else
                            {
                                continue;
                            }
                }

                                if(found==1)
                                     {
                                         ask();
                                         i=0;
                                         break;                 //THIS ONE FOR BREAK 2ND WHILE LOOP
                                     }

                    //IF ACCOUT NUMBER IS INVALIDE THIS PART WILL ACTIVE
                            {
                                 system("cls");
                                 printf(" \n\n\n\n\n\n\n\n\n");
                                 printf("                                           INVALID ACCOUNT NUMBER\n");

                                 sleep(3);
                                 system("cls");

            D1:                  printf("                                           DO YOU WANT TRY AGAIN?\n");
                                 printf("                                                  1-YES,2-NO \n");
                                 scanf(" %d",&num4);
                                 system("cls");
                                     if(num4==1)
                                         {

                                             continue;;         //BREAK 1ST WHILE LOOP

                                         }
                                     else if(num4==2)
                                         {
                                             ask();
                                             break;

                                         }
                                     else
                                     {
                                        system("cls");

                                         printf(" \n\n\n\n\n\n\n\n\n");
                                        printf("                                   INVALID NUMBER!!!\n");
                                        printf("                           PLEASE CHECK AND ENTER A VALIDE NUMBER\n");

                                        sleep(3);

                                        system("cls");

                                        goto D1;
                                     }

                            }
                     if(i=3)
                        {
                                 system("cls");
                                 printf(" \n\n\n\n\n\n\n\n\n");
                                 printf("                                             SORRY YOU TRIED MANY ATTEMPTS!!!\n");
                                 printf("                                                   TRY AGAIN LATER!!!\n");

                                 sleep(3);
                                 system("cls");


                                 finally();

                        }






        }


}


void withdrowal()
{
   while (w<3)
        {
            w++;
            printf("ENTER YOUR ACCOUNT NUMBER-:\n");
            scanf(" %s",&acc);
            printf("ENTER YOUR PIN NUMBER-:\n");
            scanf(" %s",&pin);
            acc_no=fopen("account_number.txt","r");

            //wait
            for(int j=0;j<2;j++)
                            {
                                printf(" \n\n\n\n\n\n\n\n\n");
                                printf("                                             LOADING.....\n");
                                sleep(1);
                                system("cls");
                                sleep(1);
                            }


             while (fgets(line, sizeof(line),acc_no) != NULL)

                {

                    char *token=strtok(line," ");
                   // printf("####ACC NO = %s\n",token);
                   char*token1=strtok(NULL," ");
                   // printf("####PIN NO = %s\n",token1);


                        if (strcmp(token,acc) == 0 && strcmp(token1,pin) == 0)
                            {
                                char *token2=strtok(NULL,",");
                               // printf("####NAME = %s\n",token2);
                                system("cls");

                                printf("                                        YOUR NAME= %s\n",token2);
                                printf("                                       YOUR ACCOUNT NUMBER = %s\n",acc);


            //READ BALANCE FROM BALANCE FILE
                                sprintf(count,"B%s.txt",acc);
                                acc_balance=fopen(count,"r");

                                fscanf(acc_balance,"%s",&ttr);
                                //printf("###balance = %s\n",ttr);
                                fclose(acc_balance);

            //CONVERT STRING TO INT

                                char *value;
                                num6=strtof(ttr,&value);
                                //printf("### INT BALANCE = %.2f\n",num6);


            //GET AMOUNT OF MONEY

                                printf(" \n\n");
                                printf("  # ENTER AMOUT OF MONEY #\n");
                                scanf("                              %f",&money);
                                system("cls");
                                //printf("###MONEY = %f",money);



                                if(num6<money || num6<500)
                                {
                                    printf(" \n\n\n\n\n\n\n\n\n");
                                    printf("                                             YOU HAVEN'T ENOUGH ACCOUNT BALANCE ");
                                    sleep(3);
                                    system("cls");
                                    ask();
                                    found=1;            //THIS ONE FOR BREAK 2ND WHILE LOOP , LOOK AT LINE: 2272
                                    break;
                                }


                    //CALCULATION
                                else
                                {

                                    balnce=num6-money;
                                    //printf("### TOTALE BALANCE = %.2f\n",balnce);


            //RE WRITE ACCOUNT IN "BALANCE" FILE

                                    sprintf(count,"B%s.txt",acc);
                                    acc_balance=fopen(count,"w");

                                    fprintf(acc_balance,"%f",balnce);
                                    fclose(acc_balance);


            //OPEN USER FILE AND WRITE WITHDROWAL DETAILS

                                    sprintf(fille,"%s.txt",acc);
                                    account=fopen(fille,"a");
                                    fprintf(account," |%10s\t|\t  Withdrawal\t|\t%10.2f\t|\t%11.2f\t|\n",dates,money,balnce);
                                    fclose(account);


                             //WAIT

                                     for(int j=0;j<2;j++)
                                {
                                    printf(" \n\n\n\n\n\n\n\n\n");
                                    printf("                                             LOADING.....\n");
                                    sleep(1);
                                    system("cls");
                                    sleep(1);
                                }

                    //FINALE PART
                                    system("cls");
                                    printf(" \n\n\n\n\n\n\n\n\n");
                                    printf("                                           TAKE YOUR MONEY HERE\n");
                                    sleep(3);
                                    system("cls");




                                    printf(" \n\n\n\n\n\n\n\n\n");
                                    printf("                                    YOUR WITHDROWAL IS SUCCESSFULLY\n");
                                    sleep(4);

                                    system("cls");

                                    w=0;


                                    found=1;            //THIS ONE FOR BREAK 2ND WHILE LOOP , LOOK AT LINE: 2272
                                    break;
                                }

                            }

                       else
                            {
                                continue;
                            }
                }

                         if(found==1)
                             {

                                 ask();
                                 break;                 //THIS ONE FOR BREAK 2ND WHILE LOOP
                             }


                    //IF ACCOUT NUMBER IS INVALIDE THIS PART WILL ACTIVE
                            {
                                 system("cls");
                                 printf(" \n\n\n\n\n\n\n\n\n");
                                 printf("                                           INVALID ACCOUNT NUMBER\n");

                                 sleep(3);
                                 system("cls");

            W1:                  printf("                                           DO YOU WANT TRY AGAIN?\n");
                                 printf("                                                  1-YES,2-NO \n");
                                 scanf(" %d",&num4);
                                 system("cls");
                                     if(num4==1)
                                         {

                                             continue;;         //BREAK 1ST WHILE LOOP

                                         }
                                     else if(num4==2)
                                         {
                                             ask();
                                             break;

                                         }
                                     else
                                     {
                                        system("cls");

                                         printf(" \n\n\n\n\n\n\n\n\n");
                                        printf("                                   INVALID NUMBER!!!\n");
                                        printf("                           PLEASE CHECK AND ENTER A VALIDE NUMBER\n");

                                        sleep(3);

                                        system("cls");

                                        goto W1;
                                     }

                            }

                if(w=3)
            {
                     system("cls");
                     printf(" \n\n\n\n\n\n\n\n\n");
                     printf("                                             SORRY YOU TRIED MANY ATTEMPTS!!!\n");
                     printf("                                                   TRY AGAIN LATER!!!\n");

                     sleep(3);
                     system("cls");


                     finally();

                 }




        }


}


void balance()
{
      while (b<3)
        {
            b++;
            printf("ENTER YOUR ACCOUNT NUMBER-:\n");
            scanf(" %s",&acc);
            printf("ENTER YOUR PIN NUMBER-:\n");
            scanf(" %s",&pin);
            acc_no=fopen("account_number.txt","r");

            //wait
            for(int j=0;j<2;j++)
                            {
                                printf(" \n\n\n\n\n\n\n\n\n");
                                printf("                                             LOADING.....\n");
                                sleep(1);
                                system("cls");
                                sleep(1);
                            }


             while (fgets(line, sizeof(line),acc_no) != NULL)

                {

                    char *token=strtok(line," ");
                   // printf("####ACC NO = %s\n",token);
                   char*token1=strtok(NULL," ");
                   // printf("####PIN NO = %s\n",token1);


                        if (strcmp(token,acc) == 0 && strcmp(token1,pin) == 0)
                            {
                                char *token2=strtok(NULL," ");
                               // printf("####NAME = %s\n",token2);
                                system("cls");

                                printf("                                    *).YOUR NAME= %s\n",token2);
                                printf("                                    *).YOUR ACCOUNT NUMBER = %s\n",acc);
                                printf("                                    *).DATE -: %s\n",dates);



            //READ BALANCE FROM BALANCE FILE
                                sprintf(count,"B%s.txt",acc);
                                acc_balance=fopen(count,"r");

                                fscanf(acc_balance,"%s",&ttr);
                                //printf("###balance = %s\n",ttr);
                                fclose(acc_balance);

            //CONVERT STRING TO INT

                                char *value;
                                num6=strtof(ttr,&value);

                                printf(" \n\n\n\n");
                                printf("                                        **YOUR CURRENT ACCOUNT BALANCE IS**\n" );
                                printf("                                                     %.2f\n",num6);

                                b=0;



                                found=1;            //THIS ONE FOR BREAK 2ND WHILE LOOP
                                break;


                            }





                      else
                            {
                                continue;
                            }
                }

                         if(found==1)
                             {
                                 ask();
                                 break;                 //THIS ONE FOR BREAK 2ND WHILE LOOP
                             }

                    //IF ACCOUT NUMBER IS INVALIDE THIS PART WILL ACTIVE
                            {
                                 system("cls");
                                 printf(" \n\n\n\n\n\n\n\n\n");
                                 printf("                                           INVALID ACCOUNT NUMBER\n");

                                 sleep(3);
                                 system("cls");

            B1:                  printf("                                           DO YOU WANT TRY AGAIN?\n");
                                 printf("                                                  1-YES,2-NO \n");
                                 scanf(" %d",&num4);

                                 system("cls");

                                     if(num4==1)
                                         {

                                             continue;;         //BREAK 1ST WHILE LOOP

                                         }
                                     else if(num4==2)
                                         {
                                             ask();
                                             break;

                                         }
                                     else
                                     {
                                        system("cls");

                                         printf(" \n\n\n\n\n\n\n\n\n");
                                        printf("                                   INVALID NUMBER!!!\n");
                                        printf("                           PLEASE CHECK AND ENTER A VALIDE NUMBER\n");

                                        sleep(3);

                                        system("cls");

                                        goto B1;
                                     }

                            }

                         if(b=3)
                    {
                             system("cls");
                             printf(" \n\n\n\n\n\n\n\n\n");
                             printf("                                             SORRY YOU TRIED MANY ATTEMPTS!!!\n");
                             printf("                                                   TRY AGAIN LATER!!!\n");

                             sleep(3);
                             system("cls");


                             finally();

                         }





        }



}
void statment()
{
          while (s<3)
        {
            s++;
            printf("ENTER YOUR ACCOUNT NUMBER-:\n");
            scanf(" %s",&acc);
            printf("ENTER YOUR PIN NUMBER-:\n");
            scanf(" %s",&pin);
            acc_no=fopen("account_number.txt","r");

            //wait
            for(int j=0;j<2;j++)
                            {
                                printf(" \n\n\n\n\n\n\n\n\n");
                                printf("                                             LOADING.....\n");
                                sleep(1);
                                system("cls");
                                sleep(1);
                            }


             while (fgets(line, sizeof(line),acc_no) != NULL)

                {

                    char *token=strtok(line," ");
                   // printf("####ACC NO = %s\n",token);
                   char*token1=strtok(NULL," ");
                   // printf("####PIN NO = %s\n",token1);


                        if (strcmp(token,acc) == 0 && strcmp(token1,pin) == 0)
                            {


            //READ DATA FROM USER'S FILE
                                sprintf(count,"%s.txt",acc);
                                account=fopen(count,"r");
                                system("cls");

                //WAIT

                                 for(int j=0;j<2;j++)
                            {
                                printf(" \n\n\n\n\n\n\n\n\n");
                                printf("                                             LOADING.....\n");
                                sleep(1);
                                system("cls");
                                sleep(1);
                            }

                                while (fgets(line, sizeof(line),account) != NULL)
                                {
                                    printf("                      %s",line);
                                }


                                fclose(account);

                                s=0;


                                ask();
                                found=1;            //THIS ONE FOR BREAK 2ND WHILE LOOP
                                break;


                            }



else
                            {
                                continue;
                            }
                }

                    //IF ACCOUT NUMBER IS INVALIDE THIS PART WILL ACTIVE
                            {
                                 system("cls");
                                 printf(" \n\n\n\n\n\n\n\n\n");
                                 printf("                                           INVALID ACCOUNT NUMBER\n");

                                 sleep(3);
                                 system("cls");

            S1:                  printf("                                           DO YOU WANT TRY AGAIN?\n");
                                 printf("                                                  1-YES,2-NO \n");
                                 scanf(" %d",&num4);
                                 system("cls");
                                     if(num4==1)
                                         {

                                             continue;;         //BREAK 1ST WHILE LOOP

                                         }
                                     else if(num4==2)
                                         {
                                             ask();
                                             break;

                                         }
                                     else
                                     {
                                        system("cls");

                                         printf(" \n\n\n\n\n\n\n\n\n");
                                        printf("                                   INVALID NUMBER!!!\n");
                                        printf("                           PLEASE CHECK AND ENTER A VALIDE NUMBER\n");

                                        sleep(3);

                                        system("cls");

                                        goto S1;
                                     }

                            }

            if(s=3)
                        {
                                 system("cls");
                                 printf(" \n\n\n\n\n\n\n\n\n");
                                 printf("                                             SORRY YOU TRIED MANY ATTEMPTS!!!\n");
                                 printf("                                                   TRY AGAIN LATER!!!\n");

                                 sleep(3);
                                 system("cls");


                                 finally();

                             }




        }



}


void ask()
{
                        printf(" \n\n\n\n\n\n\n");
      A1:               printf("                                 DO YOU WANT TO DO ANY OTHER TRANCE ACTION? \n");
                        printf("                                                 1-YES,2-NO\n ");
                        scanf(" %d",&num3);
                        system("cls");

                        if(num3==1)
                                {

                                    fun2();
                                }

                            else if(num3==2)
                                {

                                   finally();

                                }

                            else
                                {
                                    printf(" \n\n\n\n\n\n\n");
                                    printf("                                    INVALID NUMBER!!!\n ");
                                    printf("                                   PLEASE TRY AGAIN!!\n");
                                    system("cls");
                                    goto A1;
                                }

}

void finally()
{

    printf(" \n\n\n\n\n\n\n\n\n");
    printf("                                   THANK YOU!!!\n ");
    printf("                                HAVE A NICE DAY!!!\n ");

}
int main()
{

    time_t t= time(NULL);
    struct tm date=*localtime(&t);
    strftime(dates,200,"%Y-%m-%d",&date);

    fun1();



    return 0;
}
