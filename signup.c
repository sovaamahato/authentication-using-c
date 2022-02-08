#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

void signup(void);
void login(void);

struct{
	char password[20];
	char username[20];
}s,s1;

FILE *fp,*p;

int main()
{
	int i=0, ch;
	while(1)
	{
		

		printf("\n------------------------------Authentication page--------------------------------");

		printf("\nwelcome");
//		gotoxy(28,9);
		printf("\n1.Login");
//		gotoxy(28,11);
		printf("\n2.signup");
//		gotoxy(28,13);
		printf("\n3.Exit");
//		gotoxy(28,15);
		printf("\n---------***************---------------\n") ;
		printf("enter a option: \n");
		scanf("%d",&ch);

		switch(ch)
		{
			case 1:
				
				
				login();
		    break;
		    case 2:
		    	system("cls");

				signup();
			break;
			case 3:
				exit(0);
			break;
		}
	}
	return 0;
}

//----------------------------------------signup section--------------------------------------------------------------
void signup()
{
    int i = 0;
    char c;
    fp = fopen("try.txt", "a+");

    //	gotoxy(23,5);
    printf("\n--------------------SignUp page---------------------");
    //	gotoxy(23,7);

    printf("\nset Username : ");
    fflush(stdin);

    gets(s.username);
    fflush(stdin);

    //	gotoxy(23,9);
    printf("\nset password : ");
    gets(s.password);
    fflush(stdin);
    //	gotoxy(23,11);
    printf("\npress Enter to continue..............");
    if (getch() == 13)
    {
        fwrite(&s, sizeof(s), 1, fp);
        //		gotoxy(23,13);
        printf("\ninformation saved.............");
    }

//    fwrite(&s, sizeof(s), 1, fp);
    printf("\n\t\t\t\t\t\tYou have entered %s as password.", s.password);
    printf("\n\t\t\t\t\t\tYou have entered %s as username.", s.username);
    printf("\n\t\t\t\t\t\twritten in file successfully");
    fclose(fp);
    
    printf("please login now");
    login();
    
}


//------------------------------------------------------------------login section----------------------------------------------------------------------------
void login()

  {
	int i=0;
	char username[20];
	char pass[20];
	char c;
	char chkp;
	char chku;
	
	system("cls");           //to clear console screen 
	printf("\n-------------------------------------Login page-----------------------------");
	
	
	p=fopen("try.txt","rb");
	
	
	printf("\nEnter UserName         :");
	fflush(stdin);
	
	gets(username);
	fflush(stdin);
	
	
	
	printf("\nEnter PassWord         :");
	fflush(stdin);
    char ch1;
    
    for(i=0; i<10; i++)
    {
            ch1=getch();
            pass[i]=ch1;
      
            if(ch1!=13)      //13 is ASCII of Enter key
                printf("*");

            if(ch1 == 13)
        		break;
    }
      
    pass[i]='\0';
    fflush(stdin);
	
	fread(&s1,sizeof(s1),1,p);
	
	
	printf("\npassword=%s",s1.password);
	printf("\nusername=%s",s1.username);
	
	printf("\npassword you entered=%s",pass);
	printf("\nusername=%s",username);
	
	
	chku=strcmp(username,s1.username);
	
	chkp=strcmp(pass,s1.password);
	
	if(chku==0&&chkp!=0)
	
	{
	
		printf("Invalid password!!!!!!!!!!!!");
		
	}
	
	else if(chku!=0&&chkp==0)
	{
		printf("\n\tInvalid Username!!!!!!!!");
		
	
	}
	
	else if(chku==0&&chkp==0)
	
	{
	
		printf("\n Login successful.......................");
		printf("\n\n_Hello %s Welcome  ",s.username);
	
	
	
	
	}
	else
	return;
	fclose(fp);
	
	
	
	getch();
}
