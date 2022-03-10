//PSWC project Group M4
//BookMYTour
//Drafted - Code with comments







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

typedef struct date
{
	int year;
	int month;
	int day;
}date_t;
#include<stdio.h>
#include<string.h>
int days_on_month[12] = {31,28,31,30,31,30,31,31,30,31,30,31}; //Respectively correspond to the number of days from January to December, a[0] is empty

int days_date(struct date d)     //Based on 0000-00-00, calculate how many days have passed
{
	int sum=0;                      //Statistics days
	int i,k;
	for(i = 1; i < d.year; i++)      //years
	{
		if (d.year % 4 == 0 && d.year % 100 != 0 || d.year % 400 == 0)   //Determine if it is a leap year
			sum += 366;
		else sum += 365;
	}

	for (k = 0; k < d.month; k++)    //month
		sum += days_on_month[k];

	return sum+d.day;      //Add the number of days
}

int diff(struct date d1, struct date d2)
{
	return days_date(d1)-days_date(d2);
}

int main()
{
    printf("=====*****Welcome to BookMYTour*****===== \n");
    printf("Enter 1 for NEW USER \n");
    printf("Enter 2 for EXISTING USER \n");
    int choice;
    scanf("%d",&choice);
    long long int random_number;
    long long int lower=1000000000,upper=9999999999;
    srand(time(NULL));
    random_number=(rand()%(upper-lower+1))+lower;
    char username[50];
    //random number is created
    //FILE *fptr;

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

           f1 = (fopen(a,"a")); //unique file with the acc num as file name

           if(f1==NULL)
              printf("File not found\n");
           else
            {
              //char name[50];
              printf("Welcome \n");
              printf("Enter Full name : ");
              scanf("%s",&username);
              printf("Welcome ");
              puts(username);
              printf("Your unique Account number is :: %lld \n",random_number);//acc number
              fprintf(f1,"******Welcome to BookMyTour****** \n");
              fprintf(f1,"Customer details \n");

              fprintf(f1,"Name :: %s",username);
              fprintf(f1,"\n");
              fprintf(f1,"Account number :: %lld",random_number);
              fprintf(f1,"\n"); //random number is written to file

//CODE SEGMENT 2
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

              printf("YOU'VE SUCCESSFULLY LOGGED IN\n");
              printf("Do you want to travel National or International?\nClick 1 for National and 2 for International\n");
              int choice;
              scanf("%d",&choice);
              switch(choice)
                {

                  case 1:printf("You've choosen National\n");
                    fprintf(f1,"National Travel");
                    fprintf(f1,"\n");
                    FILE *fp=fopen("tour.csv","r");
                    if(fp==NULL)
                      printf("File not found\n");
                    else
                    {
                      char places[1000];
                      fgets(places,1000,fp);
                      while(fgets(places,1000,fp)!=NULL)
                      {
                        char* place=strtok(places,",");
                        char* price=strtok(NULL,",");
                        fputs(place,stdout);printf("\t");
                        fputs(price,stdout);
                        printf("\n");

                      }
                    printf("\nEnter the destination\n");
                    char dest[100];

                    scanf("%s",dest);
                    fprintf(f1,"Destination :: %s",dest);
                    fprintf(f1,"\n");

                    rewind(fp);
                    fgets(places,1000,fp);
                      while(fgets(places,1000,fp)!=NULL)
                      {
                        char* place=strtok(places,",");
                        char* price=strtok(NULL,",");
                        if(!(strcmp(dest,place)))
                          printf("You've entered %s \n Price for one room per night is %s",dest,price);
                      }
                      char confirmation[3];printf("Do you want to go ahead? (yes/no)\n");
                      scanf("%s",confirmation);
                      if((!strcmp(confirmation,"no"))||(!strcmp(confirmation,"No")))
                        exit(0);

                      date_t d1,d2;
                      printf("Enter the departure date(dd/mm/yyyy)\n");
                      scanf("%d/%d/%d",&d1.day,&d1.month,&d1.year);
                      fprintf(f1,"departure date : %d/%d/%d ",d1.day,d1.month,d1.year);
                      fprintf(f1,"\n");
                      printf("Enter the arrival date(dd/mm/yyyy)\n");
                      scanf("%d/%d/%d",&d2.day,&d2.month,&d2.year);
                      fprintf(f1,"Arrival date : %d/%d/%d ",d2.day,d2.month,d2.year);
                      fprintf(f1,"\n");
                      printf("Number of days of stay: %d\n", diff( d2,d1));
                      fprintf(f1,"Number of days of stay :: %d",diff( d2,d1));
                      fprintf(f1,"\n");
                      printf("Enter the total number of people travelling\n");
                      int num_people;
                      scanf("%d",&num_people);
                      fprintf(f1,"Number of people travelling : %d",num_people);
                      fprintf(f1,"\n");
                      printf("Enter the total number rooms required\n");
                    	int num_rooms;
                    	scanf("%d",&num_rooms);
                      fprintf(f1,"Total rooms: %d",num_rooms);
                      fprintf(f1,"\n");


                      printf("You'll now be taken to the payments page\n");//put in messages like thank you book again etc etc.

                      //Payments BLOCK Pooshpal work

                    break;fclose(fp);
                    }

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
                  case 2:printf("You've choosen International\n");
                    fprintf(f1,"International Travel");
                    fprintf(f1,"\n");
                    FILE *fp1=fopen("tour1.csv","r");
                    if(fp1==NULL)
                      printf("File not found\n");
                    else
                    {
                    char countries[1000];
                    fgets(countries,1000,fp1);//to discard the header row.
                    while(fgets(countries,1000,fp1)!=NULL)
                    {
                      char * country=strtok(countries,",");
                      fputs(country,stdout);
                      printf("\t");
                      char* cities=strtok(NULL,",");
                      fputs(cities,stdout);
                      printf("\t\n");
                      char *cost=strtok(NULL,",");
                      fputs(cost,stdout);
                      printf("\n");

                    }
                    printf("\nEnter the destination\n");
                    char dest1[100];
                    scanf("%s",dest1);
                    fprintf(f1,"Destination :: %s",dest1);
                    fprintf(f1,"\n");
                    rewind(fp1);
                    fgets(countries,1000,fp1);
                      while(fgets(countries,1000,fp1)!=NULL)
                      {
                        char* country=strtok(countries,",");
                        char* cities=strtok(NULL,",");
                        char* cost=strtok(NULL,",");
                        if(!(strcmp(dest1,cities)))
                          printf("You've entered %s\nCost for one room per night is %s",dest1,cost);


                      }
                      char confirmation[3];printf("Do you want to go ahead? (yes/no)\n");
                      scanf("%s",confirmation);
                      if((!strcmp(confirmation,"no"))||(!strcmp(confirmation,"No")))
                        exit(0);
                      date_t d1,d2;
                      printf("Enter the departure date(dd/mm/yyyy)\n");
                      scanf("%d/%d/%d",&d1.day,&d1.month,&d1.year);
                      fprintf(f1,"departure date : %d/%d/%d ",d1.day,d1.month,d1.year);
                      fprintf(f1,"\n");
                      printf("Enter the arrival date(dd/mm/yyyy)\n");
                      scanf("%d/%d/%d",&d2.day,&d2.month,&d2.year);
                      fprintf(f1,"Arrival date : %d/%d/%d ",d2.day,d2.month,d2.year);
                      fprintf(f1,"\n");
                      printf("Number of days of stay: %d\n", diff( d2,d1));
                      fprintf(f1,"Number of days of stay :: %d",diff( d2,d1));
                      fprintf(f1,"\n");
                      printf("Enter the total number of people travelling\n");
                      int num_people;
                      scanf("%d",&num_people);
                      fprintf(f1,"Number of people travelling : %d",num_people);
                      fprintf(f1,"\n");
                      printf("Enter the total number rooms required\n");
                    	int num_rooms;
                    	scanf("%d",&num_rooms);
                      fprintf(f1,"Total rooms: %d",num_rooms);
                      fprintf(f1,"\n");




                      printf("You'll now be taken to the payments page\n");//put in messages like thank you book again etc etc.
                      //payments BLOCK - pooshpal work

                    break;fclose(fp);
                    }




                }
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

              /*
              fprintf(f1,"Name :: %s",name,"\n");
              printf("Your unique Account number is :: %lld \n",random_number);//acc number
              fprintf(f1,"%lld",random_number,"\n"); //random number is written to file
              */
            }
            break; fclose(f1);
        }

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

        case 2:
        {

            printf("EXISTING USER \n");
            long long int acc;
            char acnum[100];
            printf("Enter your ACCOUNT NUMBER :::: ");
            scanf("%lld",&acc);
            itoa(acc,acnum,10); //itoa used to convert lmaoooooooooooooo
            //acnum has string value of the account number
            //printf("String value = %s\n", acnum);

            char a[100]="C:\\Users\\Pranav\\Desktop\\PSWC Project\\"; //acc num added to this
            strcat(a,acnum);//cat a and acnum
            char d[100]=".txt";
            strcat(a,d);

          	FILE *fptr;

          	char c;
          	// Open file
          	fptr = fopen(a, "r");
          	if (fptr == NULL)
          	{
          		printf("Cannot open file \n");
          		exit(0);
          	}

          	// Read contents from file
          	c = fgetc(fptr);
          	while (c != EOF)
          	{
          		printf ("%c", c);
          		c = fgetc(fptr);
          	}

          	fclose(fptr);
    }
    return 0;
  }
}
