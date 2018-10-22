#include<bits/stdc++.h>
#include<conio.h>
#include<windows.h>
using namespace std;
class library
{
	char title[50];
	char a_name[50];
	char name[50];
	char number[11];
	char choice;
	char f1[500];
	char f2[500];
	int stock; //,
	int edition;
	string isbn;
	int age;
	int validity;
	int code;
	int payment;
	int cheque_num;

	public:
	       //Methods of the class

		void header();
		void add_books();
		void menu();
		int password();
		void add_member();
		void issue();
		void deposit();
		void members_ac();
		void members_count();
		void book_stock();
		void remove_book();
		void remove_member();
		void list_issue();
		void update_issue();
		void editpassword();
};

/*****************************
	Main function
******************************/

int main()
{
    int ch;
     system("color 5E");
	library x;

	x.header();
	ch=x.password();
	if(!ch)
    {
        x.menu();
    }
	getch();
	return 0;

}

/****************************
*       Header Function     *
*****************************/

void library :: header()
{
	system("cls");

	long t = time(NULL);
	char *str;
	str = ctime(&t);
	cout<<str;

	cout<<"\n\n\n\t\t******************** JSS MAHAVIDYAPEETHA LIBRARY ********************"<<endl;
	cout<<"\t\t              Campus Roads, University of Mysore Campus\n\t\t\t\t\tMysuru, Karnataka"<<endl;
	cout<<"\t\t\t            MOBILE NO: +919449489864 "<<endl;
	cout<<"\t\t\t               PIN CODE :- 570006"<<endl;
	cout<<"\t\t**********************************************************************"<<endl;
}

/*************************
*     Menu Function      *
**************************/


void library :: menu()
{
	int choice;

	point2:

	header();

	cout<<"\t        1. Add new books"<<endl;
	cout<<"\t        2. Add new members"<<endl;
	cout<<"\t        3. Remove a book"<<endl;
	cout<<"\t        4. Remove a member"<<endl;
	cout<<"\t        5. Issue a book"<<endl;
	cout<<"\t        6. Deposite a book"<<endl;
	cout<<"\t        7. View members account"<<endl;
	cout<<"\t        8. View stock"<<endl;
	cout<<"\t        9. List of books issued"<<endl;
	cout<<"\t        10. Edit password"<<endl;
	cout<<"\t        11. Exit"<<endl<<endl;
	cout<<"\t	Enter your choice : ";
	cin>>choice;

	if(choice==11)
	{
			  cout<<"\n\n\t\t!  THANK YOU FOR USING THE SOFTWARE BY:SANGAM PRASAD";
                            for(int i=0;i<18;i++)
                            {
                                printf(".");
                                Sleep(200);
                            }
                            exit(0);
	}

	if(choice<0 || choice>11)
	{
		cout<<"\n\t        ! Invalid input ! Please try again....";
		getch();
		cout<<endl<<endl;
		goto point2;
	}

	else
	{
		if(choice==1)
		{
			add_books();
		}
		if(choice==2)
		{
			add_member();
		}
		if(choice==3)
		{
			system("cls");
			remove_book();
		}
		if(choice==4)
		{
			system("cls");
			remove_member();
		}
		if(choice==5)
		{
			issue();
		}
		if(choice==6)
		{
			deposit();
		}
		if(choice==7)
		{
			members_ac();
		}
		if(choice==8)
		{
			book_stock();
		}
		if(choice==9)
		{
			list_issue();
		}
		if(choice==10)
		{
           editpassword();
		}
	}
}

/***********************************
*      Add New Books Function      *
************************************/

void library :: add_books()
{


		point :

		header();

		cout<<endl;

		ofstream outf;
		outf.open("books.txt",ios::app);

		cout<<"\t\t Enter the ISBN number of the book : ";
		cin>>isbn;
		cout<<"\t\t Enter the title of the book : ";
		cin>>title;
		cout<<"\t\t Enter the author name of the book : ";
		cin>>a_name;
		cout<<"\t\t Enter the edition of the book : ";
		cin>>edition;
		cout<<"\t\t Enter the quantity of the book : ";
		cin>>stock;

		outf<<isbn<<"\n"<<title<<"\t\t"<<a_name<<"\t"<<edition<<"\t"<<stock<<endl;

		cout<<"\n\n\t\t ! book is added succesfully !"<<endl<<endl;

		outf.close();

		point1:

		cout<<"\t\t Press 'y' to continue , press 'm' to go to menu , press 'n' to exit : ";
		cin>>choice;

		if(choice=='y')
		{
			goto point;
		}

		if(choice=='m')
		{
			menu();
		}

		if(choice=='n')
		{
			cout<<"\n\t\t ! The program will be terminated............";
			getch();

			abort();
		}

		else
		{
			cout<<"\n\n\t\t ! invalid input ! try again !"<<endl<<endl;
			goto point1;
		}

}

/*************************
*  Password Function     *
**************************/
int  library ::password()
{
        char pass[20]={0},check[20]={0},ch;
        FILE *fpp;
        int i=0,j;

        printf("\t--------------FOR SECURITY PURPOSE ONLY THREE TRIALS ARE ALLOWED--------------");

        for(j=1;j<=3;j++)
        {
                        i=0;
                /*---------------- passward from user------------------*/
                        printf("\n\n\tENTER THE PASSWORD:");
                        pass[0]=getch();
                        while(pass[i]!='\r')
                        {
                            if(pass[i]=='\b')
                            {
                                i--;
                                printf("\b \b");
                                pass[i]=getch();
                            }
                            else
                            {
                                printf("X");
                                i++;
                                pass[i]=getch();
                            }
                        }
                        pass[i]='\0';
                    /*--------------reading from file is here------------*/
                        fpp=fopen("SE","r");
                        if (fpp==NULL)
                        {
                            printf("\nERROR WITH THE SYSTEM FILE...[FILE MISSING]\n");
                            getch();
                            return 1;
                        }
                        else
                        i=0;

                        while(1)
                        {
                            ch=fgetc(fpp);
                            if(ch==EOF)
                            {
                                check[i]='\0';
                                break;
                            }
                            check[i]=ch-5;
                            i++;
                        }
                 /*----------------------checking----------------------*/
                        if(strcmp(pass,check)==0)
                        {
                            printf("\n\n\tACCESS GRANTED...\n");
                            return 0;
                        }
                        else
                        {
                            printf("\n\n\tWRONG PASSWORD..\n\n\tACCESS DENIED...\n");
                            cout<<"\t\t ! you have "<<3-j<<" chance to enter right password !"<<endl<<endl;
                        }
        }
        cout<<"\n\t\t ! You have exceed the limit to enter the right password !"<<endl;
        cout<<"\t\t ! The program will be terminated............";
        exit(0);
        getch();
        return 1;
}

void library ::editpassword()
{
    //system("cls");
    printf("\n");
    char pass[20]={0},confirm[20]={0},ch;
    int choice,i,check;
    FILE *fp;
    fp=fopen("SE","rb");
    if(fp==NULL)
    {
        fp=fopen("SE","wb");
        if(fp==NULL)
        {
            printf("SYSTEM ERROR...");
            getch();
            return ;
        }
        fclose(fp);
        printf("\nSYSTEM RESTORED...\nYOUR PASSWORD IS 'ENTER'\n PRESS ENTER TO CHANGE PASSWORD\n\n");
        getch();
    }
        fclose(fp);
        check=password();
    if(check==1)
    {
        return ;
    }
    do
    {
        system("cls");
        if(check==0)
                    {
                        i=0;
                        choice=0;
                        printf("\n\n\tENTER THE NEW PASSWORD:");
                        fflush(stdin);
                        pass[0]=getch();
                        while(pass[i]!='\r')
                        {
                            if(pass[i]=='\b')
                            {
                                i--;
                                printf("\b \b");
                                pass[i]=getch();
                            }
                            else
                            {
                                printf("X");
                                i++;
                                pass[i]=getch();
                            }
                        }
                        pass[i]='\0';
                        i=0;
                        printf("\n\tCONFIRM PASSWORD:");
                        confirm[0]=getch();
                        while(confirm[i]!='\r')
                        {
                            if(confirm[i]=='\b')
                            {
                                i--;
                                printf("\b \b");
                                confirm[i]=getch();
                            }
                            else
                            {
                                printf("X");
                                i++;
                                confirm[i]=getch();
                            }
                        }
                        confirm[i]='\0';
                        if(strcmp(pass,confirm)==0)
                        {
                            fp=fopen("SE","wb");
                            if(fp==NULL)
                            {
                                printf("\n\t\tSYSTEM ERROR");
                                getch();
                                return ;
                            }
                            i=0;
                            while(pass[i]!='\0')
                            {
                                ch=pass[i]+5;
                                putc(ch,fp);
                                i++;
                            }
                            putc(EOF,fp);
                            fclose(fp);
                        }
                        else
                        {
                            printf("\n\tTHE NEW PASSWORD DOES NOT MATCH.");
                            choice=1;
                        }
                    }
}while(choice==1);

    printf("\n\n\tPASSWORD CHANGED...\n\n\tPRESS ANY KEY TO GO BACK...");
    getch();
    menu();
}

/****************************
*  Add New Members Function *
*****************************/


void library :: add_member()
{
	system("cls");

	po9 :

	header();

	ofstream outf;
	outf.open("members.txt", ios :: app);

	cout<<"\n\t\t Enter the name : ";
	cin>>name;
	cout<<"\t\t Enter the age : ";
	cin>>age;
	cout<<"\t\t Enter the validity in years : ";
	cin>>validity;
	cout<<"\t\t Enetr the telephone number : ";
	cin>>number;
	cout<<"\t\t Enter the code of members : ";
	cin>>code;

	outf<<code<<"\n"<<name<<"\t"<<number<<"\t"<<age<<"\t"<<validity<<endl;

	cout<<"\n\n\t\t The member is entered successfully !"<<endl<<endl;

	outf.close();

	po:

	cout<<"\t\t Press 'y' to continue , press 'm' to go to menu , press 'n' to exit : ";
	cin>>choice;

	if(choice=='y')
	{
		goto po9;
	}

	if(choice=='m')
	{
		system("cls");
		menu();
	}

	if(choice=='n')
	{
		cout<<"\n\t\t ! The program will be terminated............";
		getch();
		abort();
	}

	else
	{
		cout<<"\n\n\t\t ! invalid input ! try again !"<<endl<<endl;
		goto po;
	}

}

/**************************
*  Issue Books Function   *
***************************/


void library :: issue()
{
	int flag=1,flag2=1;
	char is[50],isb[50],c[50],co[50],cod[50],sh[50];

	issu:

	header();

	cout<<endl;

	ifstream inf;

	inf.open("books.txt");

	cout<<"\n\t\t enter the isbn number of the book : ";
	cin>>isb;

	while(!inf.eof())
	{
		inf.getline(is,50);
		if(!strcmp(is,isb))
		{
			cout<<"\n\t\t ! Book is found !"<<endl<<endl;
			cout<<"\n\t\t isbn\tname of book\tauthor\t\tedition\tquantity\n";
			inf.getline(sh,50);
			cout<<"\n\t\t "<<is<<"\t"<<sh<<endl<<endl<<endl;
			flag=0;
			break;
		}
	}

	inf.close();

	if(flag == 1 || flag == -1)
	{
			cout<<"\n\t\t Book is not found !"<<endl<<endl;

			pre :

			cout<<"\t\t Press 'y' to continue , press 'm' to go to menu , press 'n' to exit : ";
			cin>>choice;

			if(choice=='y')
			{
				goto issu;
			}

			if(choice=='m')
			{
				system("cls");
				menu();
			}

			if(choice=='n')
			{
				cout<<"\n\t\t! The program will be terminated............";
				getch();

				abort();
			}
			else
			{
				cout<<"\n\n\t\t ! invalid input ! try again !"<<endl<<endl;
				goto pre;
			}
	}

	inf.open("members.txt");

	cout<<"\t\t Enter the code of member : ";
	cin>>co;

	while(!inf.eof())
	{
		inf.getline(c,50);
		if(!strcmp(c,co))
		{
			cout<<"\n\t\t name\t\tnumber\t\tage\tvalidity\n";
			inf.getline(cod,50);
			flag2=0;
			cout<<"\n\t\t "<<cod<<endl<<endl;
			break;
		}
	}

	if(flag2 != 0)
	{
		cout<<"\n\t\t ! invalid code of member !"<<endl<<endl;

		back :

		cout<<"\t\t Press 'y' to continue , press 'm' to go to menu , press 'n' to exit : ";
		cin>>choice;

		if(choice=='y')
		{
			goto issu;
		}

		if(choice=='m')
		{
			system("cls");
			menu();
		}

		if(choice=='n')
		{
			cout<<"\n\t\t! The program will be terminated............";
			getch();

			abort();
		}

		else
		{
			cout<<"\n\n\t\t ! invalid input ! try again !"<<endl<<endl;
			goto back;
		}
	}

	if(flag2==0)
	{
		ofstream out;

		out.open("issue.txt",ios::app);
		out<<co<<"\n"<<isb<<endl;
		cout<<"\n\t\t ! Book is issued succesfully !"<<endl<<endl;
		out.close();
		poi :

		cout<<"\t\t Press 'y' to continue , press 'm' to go to menu , press 'n' to exit : ";
		cin>>choice;

		if(choice=='y')
		{
			goto issu;
		}

		if(choice=='m')
		{
			system("cls");
			menu();
		}

		if(choice=='n')
		{
			cout<<"\n\t\t! The program will be terminated............";
			getch();

			abort();
		}

		else
		{
			cout<<"\n\n\t\t ! invalid input ! try again !"<<endl<<endl;
			goto poi;
		}
	}

	inf.close();
 }

 /*****************************************
 *   Display Members Information Function *
 ******************************************/


 void library :: members_ac()
 {
	memb :

	int select,flag=1,count=0;
	char m[50];

	header();

	cout<<"\n\t\t 1.All members.\n\t\t 2.Search member.";
	cout<<"\n\t\t Enter your choice : ";
	cin>>select;

	ifstream inf;

	if(select == 1)
	{
		header();

		char st[50],str[50];

		inf.open("members.txt");

		while(!inf.eof())
		{
			inf.getline(m,50);
			count++;
		}

		inf.close();

		cout<<"\t\t code\t\tname\t\tnumber\t\tage\tvalidity\n";

		inf.open("members.txt");

		while(!inf.eof())
		{
			inf.getline(st,50);
			inf.getline(str,50);

			cout<<"\n\t\t "<<st<<"\t\t"<<str<<endl;
		}

		cout<<"\t\t Total members = "<<count/2<<endl;

		inf.close();

		 poin :

		cout<<"\n\t\t Press 'y' to continue , press 'm' to go to menu , press 'n' to exit : ";
		cin>>choice;

		if(choice=='y')
		{
			goto memb;
		}

		if(choice=='m')
		{
			system("cls");
			menu();
		}

		if(choice=='n')
		{
			cout<<"\n\t\t! The program will be terminated............";
			getch();

			abort();
		}

		else
		{
			cout<<"\n\n\t\t ! invalid input ! try again !"<<endl<<endl;
			goto poin;
		}
	}

	if(select == 2)
	{
		char s[50];
		char st[50];
		char str[50];

		inf.open("members.txt");

		cout<<"\n\t\t Enter the code of the member : ";
		cin>>s;

		while(!inf.eof())
		{
			inf.getline(st,50);

			if(!strcmp(s,st))
			{
			 inf.getline(str,50);

			 cout<<"\n\t\t code\t\tname\t\tnumber\t\tage\tvalidity\n";
			 cout<<"\n\t\t "<<st<<"\t\t"<<str<<endl;
			 flag=0;
			 break;
			}
		}

		inf.close();

		if(flag == 0)
		{
			bac :

			cout<<"\n\t\t Press 'y' to continue , press 'm' to go to menu , press 'n' to exit : ";
			cin>>choice;

			if(choice=='y')
			{
				goto memb;
			}

			if(choice=='m')
			{
				system("cls");
				menu();
			}

			if(choice=='n')
			{
				cout<<"\n\t\t! The program will be terminated............";
				getch();

				abort();
			}

			else
			{
				cout<<"\n\n\t\t ! invalid input ! try again !"<<endl<<endl;
				goto bac;
			}
		}

		if(flag==1 || flag == -1)
		{
			cout<<"\n\t\t ! invalid code of member !"<<endl;
			po1 :
			cout<<"\n\t\t Press 'y' to continue , press 'm' to go to menu , press 'n' to exit : ";
			cin>>choice;

			if(choice=='y')
			{
				goto memb;
			}

			if(choice=='m')
			{
				system("cls");
				menu();
			}

			if(choice=='n')
			{
				cout<<"\n\t\t! The program will be terminated............";
				getch();

				abort();
			}
			else
			{
				cout<<"\n\n\t\t ! invalid input ! try again !"<<endl<<endl;
				goto po1;
			}
		}
	}
 }

 /*******************************************
 *  Display All Books In The Stock Function *
 ********************************************/


 void library :: book_stock()
 {
	int ch,book_count=0;
	char b[50],i[50];

	sb :

	header();

	cout<<"\n\t\t 1.All books.\n\t\t 2.search a book\n\t\t Enter your choice : ";
	cin>>ch;

	if(ch==1)
	{       header();
		ifstream inf;
		inf.open("books.txt");

		cout<<"\t\t ISBN\ttital\t\tauthor\t\tedition\tquantity"<<endl;

		 while(!inf.eof())
		{
			inf.getline(b,50);
			inf.getline(i,50);
			cout<<"\n\t\t "<<b<<"\t"<<i<<endl;
			book_count++;
		}

		cout<<"\t\t Total number of books : "<<book_count-1<<endl;

		inf.close();

			po2 :

			cout<<"\n\t\t Press 'y' to continue , press 'm' to go to menu , press 'n' to exit : ";
			cin>>choice;

			if(choice=='y')
			{
				goto sb;
			}

			if(choice=='m')
			{
				system("cls");
				menu();
			}

			if(choice=='n')
			{
				cout<<"\n\t\t! The program will be terminated............";
				getch();

				abort();
			}
			else
			{
				cout<<"\n\n\t\t ! invalid input ! try again !"<<endl<<endl;
				goto po2;
			}
	}

	if(ch==2)
	{
		char isb[40],bn[50],mb[50];
		int f=0;

		ifstream inf;

		inf.open("books.txt");

		cout<<"\n\t\t Enter the isbn number of the book : ";
		cin>>isb;

		while(!inf.eof())
		{
			inf.getline(bn,50);
			inf.getline(mb,50);

			if(!strcmp(bn,isb))
			{
				cout<<"\n\t\t isbn\tname of book\tauthor\t\tedition\tquantity\n";
				cout<<"\n\t\t "<<bn<<"\t"<<mb<<endl;
				f=1;
			}
		}

		if(f==1)
		{
			po3 :

			cout<<"\n\t\t Press 'y' to continue , press 'm' to go to menu , press 'n' to exit : ";
			cin>>choice;

			if(choice=='y')
			{
				goto sb;
			}

			if(choice=='m')
			{
				system("cls");
				menu();
			}

			if(choice=='n')
			{
				cout<<"\n\t\t! The program will be terminated............";
				getch();

				abort();
			}
			else
			{
				cout<<"\n\n\t\t ! invalid input ! try again !"<<endl<<endl;
				goto po3;
			}
		}

		if(f==0)
		{
			cout<<"\n\t\t ! Book  not found !"<<endl;

			po4 :

			cout<<"\n\t\t Press 'y' to continue , press 'm' to go to menu , press 'n' to exit : ";
			cin>>choice;

			if(choice=='y')
			{
				goto sb;
			}

			if(choice=='m')
			{
				system("cls");
				menu();
			}

			if(choice=='n')
			{
				cout<<"\n\t\t! The program will be terminated............";
				getch();

				exit(0);
			}
			else
			{
				cout<<"\n\n\t\t ! invalid input ! try again !"<<endl<<endl;
				goto po4;
			}
		}
	}
 }

 /*************************
 * Deposit Books Function *
 **************************/

 void library :: deposit()
 {
	depo :

	header();
	char memb[100];
	char c[100];
	char c1[100];
	int flagd = 0;

	cout<<"\n\n\t\t Enter the code of member : ";
	cin>>memb;

	ifstream inf;
	inf.open("issue.txt");

	while(!inf.eof())
	{
	    inf.getline(c,100);


	    if(!strcmp(c,memb))
	    {
		cout<<"\n\n\t\t Member is found......"<<endl<<endl;
		inf.getline(c1,100);

		strcpy(f1,c);
		strcpy(f2,c1);

		cout<<"\t\t ISBN number of the books issued is : "<<c1<<endl;

		update_issue();

		cout<<"\n\n\t\t The book is deposited successfully......."<<endl<<endl;
		flagd = 1;

		po5 :

		cout<<"\n\t\t Press 'y' to continue , press 'm' to go to menu , press 'n' to exit : ";
		cin>>choice;

		if(choice=='y')
		{
			goto depo;
		}

		if(choice=='m')
		{
			system("cls");
			menu();
		}

		if(choice=='n')
		{
			cout<<"\n\t\t! The program will be terminated............";
			getch();

			abort();
		}
		else
		{
			cout<<"\n\n\t\t ! invalid input ! try again !"<<endl<<endl;
			goto po5;
		}
	    }
	}

	    inf.close();

	    if(flagd == 0)
	    {
		cout<<"\n\n\t\t ! Member is not found !";

		cout<<"\n\n\t\t Press 'y' to continue , press 'm' to go to menu , press 'n' to exit : ";
		cin>>choice;

		if(choice=='y')
		{
			goto depo;
		}

		if(choice=='m')
		{
			system("cls");
			menu();
		}

		if(choice=='n')
		{
			cout<<"\n\t\t! The program will be terminated............";
			getch();

			abort();
		}
		else
		{
			cout<<"\n\n\t\t ! invalid input ! try again !"<<endl<<endl;
			goto po5;
		}
	    }
 }

 /***************************
 *     Remove book function *
 ****************************/

 void library :: remove_book()
 {
	pop :

	header();

	char remov[500];
	char k[500];
	int km,mm;
	char m[500];

	cout<<"\n\n\t\t Enter the ISBN number of the book : ";
	cin>>remov;

	ifstream inf;
	inf.open("books.txt");

	ofstream outf;
	outf.open("temp.txt");

	while(!inf.eof())
	{
		inf.getline(k,500);

		/* Convert character array k to string
		 * ex.: string tempString = string(k);
		 * Remove last character of k string
		 * ex.: string tempString1 = tempString.substr(0,tempString.size()-1);
		 * Convert character array remov to string
		 * ex.: string tempString2 = string(remov);
		 * in c++ you can compare string as if(string1 == string2)
		 */

		int b = strcmp(remov,k);

		if(b==0)
		{
			inf.getline(k,500);
			km=1;
		}
		else
		{
			outf<<k<<endl;
		}
	}
	if(km==1)
	{
		cout<<"\n\n\t\t Book has been successfully removed.....";
		remove("books.txt");
		outf.close();
		inf.close();

		rename("temp.txt","books.txt");

		gop :

		cout<<"\n\n\t\t Press 'y' to continue , press 'm' to go to menu , press 'n' to exit : ";
		cin>>choice;

		if(choice=='y')
		{
			goto pop;
		}

		if(choice=='m')
		{
			system("cls");
			menu();
		}

		if(choice=='n')
		{
			cout<<"\n\t\t! The program will be terminated............";
			getch();

			abort();
		}
		else
		{
			cout<<"\n\n\t\t ! invalid input ! try again !"<<endl<<endl;
			goto gop;
		}
	}

	else
	{
		cout<<"\n\n\t\t ! ISBN number wrong !";

		pom :

		cout<<"\n\n\t\t Press 'y' to continue , press 'm' to go to menu , press 'n' to exit : ";
		cin>>choice;

		if(choice=='y')
		{
			goto pop;
		}

		if(choice=='m')
		{
			system("cls");
			menu();
		}

		if(choice=='n')
		{
			cout<<"\n\t\t! The program will be terminated............";
			getch();

			abort();
		}
		else
		{
			cout<<"\n\n\t\t ! invalid input ! try again !"<<endl<<endl;
			goto pom;
		}
	}
 }

 /******************
 * Remove a member *
 *******************/


 void library :: remove_member()
 {
	mom :

	header();

	char r[500],b[500];
	int c;

	cout<<"\n\n\t\t Enter the code of the member : ";
	cin>>r;

	ifstream inf;
	inf.open("members.txt");
	ofstream outf;
	outf.open("temp.txt");

	while(!inf.eof())
	{
		inf.getline(b,500);

		if(!strcmp(b,r))
		{
			c=1;
			inf.getline(b,500);
		}
		else
		{
			outf<<b<<endl;
		}
	}

	if(c==1)
	{
		cout<<"\n\n\t\t Member has been successfully removed....";
		inf.close();
		outf.close();
		remove("members.txt");
		rename("temp.txt","members.txt");

		mop :

		cout<<"\n\n\t\t Press 'y' to continue , press 'm' to go to menu , press 'n' to exit : ";
		cin>>choice;

		if(choice=='y')
		{
			goto mom;
		}

		if(choice=='m')
		{
			system("cls");
			menu();
		}

		if(choice=='n')
		{
			cout<<"\n\t\t! The program will be terminated............";
			getch();

			abort();
		}
		else
		{
			cout<<"\n\n\t\t ! invalid input ! try again !"<<endl<<endl;
			goto mop;
		}
	}

	else
	{
		cout<<"\n\n\t\t ! Invalid code of member !";

		job :

		cout<<"\n\n\t\t Press 'y' to continue , press 'm' to go to menu , press 'n' to exit : ";
		cin>>choice;

		if(choice=='y')
		{
			goto mom;
		}

		if(choice=='m')
		{
			system("cls");
			menu();
		}

		if(choice=='n')
		{
			cout<<"\n\t\t! The program will be terminated............";
			getch();

			abort();
		}
		else
		{
			cout<<"\n\n\t\t ! invalid input ! try again !"<<endl<<endl;
			goto job;
		}
	}

 }

 /*******************************
 * List of books issued function*
 ********************************/

 void library :: list_issue()
 {
	header();

	char l[500],m[500];

	ifstream inf("issue.txt");

	cout<<"\t\t Code of member\t\tISBN number of book";

	while(!inf.eof())
	{
		inf.getline(l,500);
		inf.getline(m,500);

		cout<<"\n\n\t\t\t "<<l<<"\t\t\t"<<m<<endl;
	}

	boj :

	cout<<"\t\t press 'm' to go to menu , press 'n' to exit : ";
	cin>>choice;

	if(choice=='m')
	{
		system("cls");
		menu();
	}

	if(choice=='n')
	{
		cout<<"\n\t\t! The program will be terminated............";
		getch();

		abort();
	}
	else
	{
		cout<<"\n\n\t\t ! invalid input ! try again !"<<endl<<endl;
		goto boj;
	}
 }

 /*************************
 * Update books issue list*
 **************************/

 void library :: update_issue()
 {
	char buf[500];

	ofstream outf("temp.txt");
	ifstream inf("issue.txt");

	while(!inf.eof())
	{
		inf.getline(buf,500);

		if(!strcmp(buf,f1))
		{
			inf.getline(buf,500);
			inf.getline(buf,500);
		}

		outf<<buf<<endl;
	}

	inf.close();
	outf.close();

	remove("issue.txt");
	rename("temp.txt","issue.txt");
 }
