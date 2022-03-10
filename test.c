/*
Sign IN
Sign UP


#Sign IN - existing user:
    enter name and password
    then it should show account details and receipt
#Sign UP - new user:
    Asks to enter name and new unique password
    A file is created in the directory with the password as the file name
    then list of places shown

*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
//SIGN UP Part

int main()
{
    /*
  long long int random_number;
  long long int lower=1000000000,upper=9999999999;
  srand(time(NULL));
  random_number=(rand()%(upper-lower+1))+lower;


  char name[50];
  int n;

   FILE *fptr;
   char acnum[20];

   itoa(random_number,acnum,10); //itoa used to convert

   //acnum has string value of the account number
   //printf("String value = %s\n", acnum);

   char a[100]="C:\\Users\\Pranav\\Desktop\\PSWC Project\\"; //acc num added to this
   strcat(a,acnum);//cat a and acnum
   char d[100]=".txt";
   strcat(a,d);

   fptr = (fopen(a,"a")); //I need a unique file with the acc num as file name

   if(fptr == NULL)
   {
       printf("Error!");
       exit(1);
   }

   else
   {
     int k;
     printf("=====*****Welcome to BookMYTour*****===== \n");
     printf("Enter 1 for NEW USER \n");
     printf("Enter 2 for EXISTING USER \n");
     printf("Enter your choice:::");
     scanf("%d",&k);

     switch(k)
     {
       case 1:
         //char t1[100]="=====*****Welcome to BookMYTour*****=====";
         //fprintf(fptr,"%s",t1,"\n");

         printf("Enter Full name : ");
         gets(name);
         fprintf(fptr,"%s",name,"\n");
         printf("Your unique Account number is :: %d \n",random_number);//acc number
         fprintf(fptr,"%d",random_number,"\n"); //random number is written to file
         break;

         //contents of the excel sheet displayed
         // printf //enter your choice
        default:
          printf("Incorrect");
          break;
     }
   }
   fclose(fptr);
   return 0;
   */
    printf("=====*****Welcome to BookMYTour*****===== \n");
    printf("Enter 1 for NEW USER \n");
    printf("Enter 2 for EXISTING USER \n");
    int choice;
    scanf("%d",&choice);
    long long int random_number;
    long long int lower=1000000000,upper=9999999999;
    srand(time(NULL));
    random_number=(rand()%(upper-lower+1))+lower;
    //random number is created
    FILE *fptr;

    switch(choice)
      {

        case 1:
        {
            //int n;
            //FILE *fptr;
            //char acnum[20];
            FILE *f1;
            char acnum[20];
            itoa(random_number,acnum,10); //itoa used to convert

            //acnum has string value of the account number
            //printf("String value = %s\n", acnum);
           char a[100]="C:\\Users\\Pranav\\Desktop\\PSWC Project\\";    //acc num added to this
           strcat(a,acnum);//cat a and acnum
           char d[100]=".txt";
           strcat(a,d);

           f1 = (fopen(a,"a")); //I need a unique file with the acc num as file name

           if(f1==NULL)
              printf("File not found\n");
           else
            {
              char name[50];
              printf("Enter Full name : ");
              gets(name);
              fprintf(f1,"%s",name,"\n");
              printf("Your unique Account number is :: %d \n",random_number);//acc number
              fprintf(f1,"%d",random_number,"\n"); //random number is written to file


            }break;fclose(fptr);
        }

        case 2:
        {
            FILE *f2;
            printf("EXISTING USER");
            long long int acc;
            char acnum[100];
            printf("Enter your ACCOUNT NUMBER");
            scanf("%lld",%acc);
            itoa(acc,acnum,10); //itoa used to convert lmaoooooooooooooo
            //acnum has string value of the account number
            //printf("String value = %s\n", acnum);

            char a[100]="C:\\Users\\Pranav\\Desktop\\PSWC Project\\"; //acc num added to this
            strcat(a,acnum);//cat a and acnum
            char d[100]=".txt";
            strcat(a,d);
            f2 = (fopen(a,"r"));
            break;fclose(fptr);
        }



    }
}
