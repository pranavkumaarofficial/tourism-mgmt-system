#include<stdio.h>
#include<string.h>
char password[30];

int chek_pass(char password[30]);

int chek_pass(char password[30])
	{

	int a,len,Upper,Lower,Special,Num,i;
	char x;
    i=0;
    Upper=Lower=Special=Num=0;
	len=strlen(password);
		while(password[i]!='\0')
	    {
		    x=password[i];
		    if(x>='a' && x<='z')
		    	Lower=1;
		    else if(x>='A' && x<='Z')
		    	Upper=1;
		    else if(x==33 || x<=35 || x==36 || x==38  || x==64) //special symbols ascii range
		        Special=1;
		    else if(x>=48 && x<=57)//numbers range
		        Num=1;
		    i++;
		}//while

    if(Upper==0||Lower==0||Special==0||Num==0||len<8)
	{
		printf("password is not meeting requirements\nre-enter password: ");

		scanf("%s",password);
		chek_pass(password);
	}
return 0;
}

int main()
{
    char username[12];
    char password[30];

    printf("**************************************************\n");
    printf("Password should contain minimum 8 characters includes\nsmall letters, atleast one capital letter\n and one special character (#,$,@,!,&)\n");
    printf("**************************************************\n");
	printf("Password: ");
	scanf("%s", password);
	chek_pass(password);
	return 0;
}//main
