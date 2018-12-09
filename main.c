#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<time.h>
#include<windows.h>

#define RETURNTIME 15
//Global FILE pointers
FILE *fp,*ft,*fs;
//Global Variables
int choice;
char findbook;
char password[20] = {"Mahin"};

//list of user define function
char catagories[][15]={"Computer","Electrical","Civil","Mechanical","Architecture"};
void addbook(void);
int current_time(void);
void delay(unsigned int mseconds);
void deletebook();
void editbook(void);
int getdata();
void gotoxy(int x, int y);
void issuebook(void);
void loadanimation();
void mainmenu(void);
void PASSWORD(void);
void returnfunc(void);
void searchbook();
int verify(int ID);
void viewbooklist(void);


COORD coord = {0,0}; //set coordinates
COORD max_res, cursor_size;
void gotoxy(int x, int y)
{
    coord.X = x;
    coord.Y = y;

    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void delay(unsigned int mseconds)
{
    clock_t goal = mseconds + clock();
    while(goal > clock());
}
struct DATE
{
    int mm, dd, yy;
};
struct Books
{
    int id;
    char studentname[50];
    char bookname[50];
    char author[50];
    int quantity;
    float price;
    int count;
    int rackno;
    char *catago;
    char catagories;
    struct DATE issued;
    struct DATE retdate;
}info;

int main()
{
    PASSWORD();
    getch();

    return 0;
};
void PASSWORD(void) //password function
{
    system("COLOR FC");
    system("cls");

    char c[19]="Password Protected";
    char ch, pass[20];
    int i=0;
    int j;

    gotoxy(10,4);

    for(j=0; j<20; j++)
    {
        delay(50);
        printf("\xB2");
    }
    for(j=0; j<18; j++)
    {
        delay(50);
        printf("%c", c[j]);
    }
    for(j=0; j<20; j++)
    {
        delay(50);
        printf("\xB2");
    }

    gotoxy(15,7);
    printf("Enter Password:");

    while(ch!=13)
    {
        ch=getch();

        if(ch!=13 && ch!=8) //ASCII code 13=return carriage, 8=backspace
        {
            putch('*');
            pass[i] = ch;
            i++;
        }
    }
    pass[i] = '\0';

    if(strcmp(pass, password)==0)
    {
        gotoxy(15,9);
        printf("Password Match");
        gotoxy(15,10);
        printf("Press Any Key to Continue.........");
        getch();
        mainmenu();
    }




    else
    {
        gotoxy(15,16);
        printf("Warning! Incorrect Password!!");
        printf("\a"); //bell sound
        getch();
        PASSWORD();
    }
}

void mainmenu()
{
    loadanimation();

    system("cls");

    int i;
    info;

    gotoxy(20,3);
    printf("\xB1\xB2\xB1\xB2\xB1\xB2\xB1\xB2\xB1\xB2\xB1\xB2\xB1\xB2 MAIN MENU \xB1\xB2\xB1\xB2\xB1\xB2\xB1\xB2\xB1\xB2\xB1\xB2\xB1\xB2");

    gotoxy(20,5);
    printf("\xDB\xDB\xDB\xDB\xB2 1. Add Books");
    gotoxy(20,7);
    printf("\xDB\xDB\xDB\xDB\xB2 2. Delete Books");
    gotoxy(20,9);
    printf("\xDB\xDB\xDB\xDB\xB2 3. Search Books");
    gotoxy(20,11);
    printf("\xDB\xDB\xDB\xDB\xB2 4. View Book List");
    gotoxy(20,13);
    printf("\xDB\xDB\xDB\xDB\xB2 5. Issue Books");
    gotoxy(20,15);
    printf("\xDB\xDB\xDB\xDB\xB2 6. Edit Book's Information");
    gotoxy(20,17);
    printf("\xDB\xDB\xDB\xDB\xB2 7. Exit");
    gotoxy(20,19);
    printf("\xB1\xB2\xB1\xB2\xB1\xB2\xB1\xB2\xB1\xB2\xB1\xB2\xB1\xB2\xB1\xB2\xB1\xB2\xB1\xB2\xB1\xB2\xB1\xB2\xB1\xB2\xB1\xB2\xB1\xB2\xB1\xB2\xB1\xB2\xB1\xB2\xB1\xB2\xB1\xB2");

    gotoxy(20,20);
    current_time();

    gotoxy(20,21);
    printf("Enter Your Choice:");

    switch(getch())
    {
        case '1':
            addbook();
            break;
        case '2':
            deletebook();
            break;
        case '3':
            searchbook();
            break;
        case '4':
            viewbooklist();
            break;
        case '5':
            issuebook();
            break;
        case '6':
            editbook();
            break;
        case '7':
        {
            system("cls");

            gotoxy(16,3);
            printf("Programmers................");

            gotoxy(16,4);
            printf("1. Soarnali Islam Mukti");
            gotoxy(16,5);
            printf("ID: 171-35-1922     Email: Soarnaliislam79@gmail.com");


            exit(0);
        }
        default:
        {
            gotoxy(10,23);
            printf("Wrong Entry...Please Enter Correct Option");
            printf("\a");
            if(getch())
            {
                mainmenu();
            }
        }
    }
}

void loadanimation()
{
    int load;
    system("cls");

    gotoxy(20,10);
    printf("LOADING........");
    printf("\n\n");

    gotoxy(22,11);
    for(load=0; load<20; load++)
    {
        delay(100);
        printf("%c", 219);
    }
}

void addbook(void)
{
    system("cls");

    gotoxy(20,5);
    printf("\xB1\xB2\xB1\xB2\xB1\xB2\xB1\xB2\xB1\xB2SELECT CATEGORIES\xB1\xB2\xB1\xB2\xB1\xB2\xB1\xB2\xB1\xB2");
    gotoxy(20,7);
	printf("\xDB\xDB\xDB\xDB\xB2 1. Computer");

gotoxy(20,9);
	printf("\xDB\xDB\xDB\xDB\xB2 2. Electronics");
	gotoxy(20,11);
	printf("\xDB\xDB\xDB\xDB\xB2 3. Electrical");
	gotoxy(20,13);
	printf("\xDB\xDB\xDB\xDB\xB2 4. Civil");
	gotoxy(20,15);
	printf("\xDB\xDB\xDB\xDB\xB2 5. Mechanical");
	gotoxy(20,17);
	printf("\xDB\xDB\xDB\xDB\xB2 6. Architecture");
	gotoxy(20,19);
	printf("\xDB\xDB\xDB\xDB\xB2 7. Back to main menu");
	gotoxy(20,21);
	printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
	gotoxy(20,22);

	printf("Enter your choice:");
	scanf("%d",&choice);

	if(choice==7)
    {
        mainmenu();
    }

    system("cls");

    fp=fopen("Stock.dat","ab+");

	if(getdata()==1)
	{
        info.catago=catagories[choice-1];

        fseek(fp,0,SEEK_END);
        fwrite(&info,sizeof(info),1,fp);
        fclose(fp);

        gotoxy(21,14);
        printf("The record is sucessfully saved");
        gotoxy(21,15);
        printf("Save any more?(Y / N):");
        if(tolower(getch())=='n')
        {
            mainmenu();
        }
        else
        {
            system("cls");
            addbook();
        }
	}
}

int getdata()
{
    int ID;
	gotoxy(20,3);
	printf("Enter the Information Below");

	gotoxy(20,4);
	printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
	gotoxy(20,5);
	printf("\xB2");
	gotoxy(46,5);
	printf("\xB2");
	gotoxy(20,6);
	printf("\xB2");
	gotoxy(46,6);
	printf("\xB2");
	gotoxy(20,7);
	printf("\xB2");
	gotoxy(46,7);
	printf("\xB2");
	gotoxy(20,8);
	printf("\xB2");
	gotoxy(46,8);
	printf("\xB2");
	gotoxy(20,9);
	printf("\xB2");
	gotoxy(46,9);
	printf("\xB2");
	gotoxy(20,10);
	printf("\xB2");
	gotoxy(46,10);
	printf("\xB2");
	gotoxy(20,11);
	printf("\xB2");
	gotoxy(46,11);
	printf("\xB2");
	gotoxy(20,12);
	printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");

	gotoxy(21,5);
	printf("Category:");
	gotoxy(31,5);
	printf("%s",catagories[choice-1]);
	gotoxy(21,6);
	printf("Book ID:\t");
	gotoxy(30,6);
	scanf("%d",&ID);

	if(verify(ID) == 0)
	{
		gotoxy(21,13);
		printf("\aThe book id already exists\a");
		getch();
		mainmenu();
		return 0;
	}

	info.id=ID;
	gotoxy(21,7);
	printf("Book Name:");
	gotoxy(33,7);
	scanf("%s", &info.bookname);
	gotoxy(21,8);
	printf("Author:");
	gotoxy(30,8);
	scanf("%s", info.author);
	gotoxy(21,9);
	printf("Quantity:");
	gotoxy(31,9);
	scanf("%d", &info.quantity);
	gotoxy(21,10);
	printf("Price:");
	gotoxy(28,10);
	scanf("%f", &info.price);
	gotoxy(21,11);
	printf("Rack No:");
	gotoxy(30,11);
	scanf("%d",&info.rackno);

	return 1;
}

int verify(int ID)  //check whether the book is exist in library or not
{
	rewind(fp);
	while(fread(&info,sizeof(info),1,fp)==1)
    if(info.id == ID)
    return 0; //if book exists
        return 1; //if it not
}

void deletebook()    //function that delete items from file fp
{
    system("cls");
    int id;
    char start = 'y';
    while(start == 'y')  //infinite loop
    {
        system("cls");
        gotoxy(10,5);
        printf("Enter the Book ID to  delete:");
        scanf("%d", &id);

        fp=fopen("Stock.dat","rb+");
        rewind(fp);
        while(fread(&info,sizeof(info),1,fp)==1)
        {
            if(info.id == id)
            {
                gotoxy(10,7);
                printf("The book record is available");
                gotoxy(10,8);
                printf("Book name is %s", info.bookname);
                gotoxy(10,9);
                printf("Rack No. is %d", info.rackno);
                findbook='y';
            }
        }
        if(findbook!='y')
        {
            gotoxy(10,10);
            printf("No record is found modify the search");
            if(getch())
            {
                mainmenu();
            }
        }
        if(findbook=='y' )
        {
            gotoxy(10,9);
            printf("Do you want to delete it?(Y/N):");

            if(tolower(getch())=='y')
            {
                ft=fopen("test.dat","wb+");  //temporary file for delete
                rewind(fp);
                while(fread(&info,sizeof(info),1,fp)==1)
                {
                    if(info.id != id)
                    {
                        fseek(ft,0,SEEK_CUR);
                        fwrite(&info,sizeof(info),1,ft); //write all in tempory file except that
                    }                              //we want to delete
                }
                fclose(ft);
                fclose(fp);
                remove("Stock.dat");
                rename("test.dat","Stock.dat"); //copy all item from temporary file to fp except that
                fp=fopen("Stock.dat","rb+");    //we want to delete
                if(findbook=='y')
                {
                    gotoxy(10,10);
                    printf("The record is sucessfully deleted");
                    gotoxy(10,11);
                    printf("Delete another record?(Y/N)");
                    if(tolower(getch()) == 'y')
                    {
                        deletebook();
                    }
                    else
                    {
                        mainmenu();
                    }
                }
            }
        else
        {
            mainmenu();
            start = tolower(getch());
        }
        }
    }
    gotoxy(10,15);
    mainmenu();
}

void searchbook()
{
    system("cls");

    int id;
    printf("*****************************Search Books*********************************");
    gotoxy(20,10);
    printf("\xDB\xDB\xDB\xB2 1. Search By ID");
    gotoxy(20,14);
    printf("\xDB\xDB\xDB\xB2 2. Search By Name");


    gotoxy( 15,20);
    printf("Enter Your Choice");

    fp=fopen("Stock.dat","rb+"); //open file for reading propose
    rewind(fp);     //move pointer at the begining of file

    switch(getch())
    {
        case '1':
        {
            system("cls");
            gotoxy(25,4);
            printf("****Search Books By Id****");
            gotoxy(20,5);
            printf("Enter the book id:");
            scanf("%d", &id);
            gotoxy(20,7);
            printf("Searching........");
            while(fread(&info,sizeof(info),1,fp)==1)
            {
                if(info.id == id)
                {
                    delay(10);
                    gotoxy(20,7);
                    printf("The Book is available");
                    gotoxy(20,8);
                    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");                    gotoxy(20,9);
                    printf("\xB2 ID:%d", info.id);
                    gotoxy(47,9);
                    printf("\xB2");
                    gotoxy(20,10);
                    printf("\xB2 Name:%s", info.bookname);
                    gotoxy(47,10);
                    printf("\xB2");
                    gotoxy(20,11);
                    printf("\xB2 Author:%s ", info.author);
                    gotoxy(47,11);
                    printf("\xB2");
                    gotoxy(20,12);
                    printf("\xB2 Qantity:%d ", info.quantity);
                    gotoxy(47,12);
                    printf("\xB2");
                    gotoxy(47,11);
                    printf("\xB2");
                    gotoxy(20,13);
                    printf("\xB2 Price:Rs.%.2f", info.price);
                    gotoxy(47,13);
                    printf("\xB2");
                    gotoxy(20,14);
                    printf("\xB2 Rack No:%d ", info.rackno);
                    gotoxy(47,14);
                    printf("\xB2");
                    gotoxy(20,15);
                    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
                    findbook = 't';
                }

            }
            if(findbook!='t')  //checks whether conditiion enters inside loop or not
            {
                gotoxy(20,8);
                printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
                gotoxy(20,9);
                printf("\xB2");
                gotoxy(38,9);
                printf("\xB2");
                gotoxy(20,10);
                printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
                gotoxy(22,9);
                printf("\aNo Record Found");
            }

            gotoxy(20,17);
            printf("Try another search?(Y/N)");
            if(tolower(getch())=='y')
            {
                searchbook();
            }
            else
            {
                mainmenu();
                break;
            }
        }

        case '2':
        {
            char s[15];
            system("cls");
            gotoxy(25,4);
            printf("****Search Books By Name****");
            gotoxy(20,5);
            printf("Enter Book Name:");
            scanf("%s", s);
            int check = 0;
            while(fread(&info,sizeof(info),1,fp)==1)
            {
                if(strcmp(info.bookname,(s))==0) //checks whether a.name is equal to s or not
                {
                    gotoxy(20,7);
                    printf("The Book is available");
                    gotoxy(20,8);
                    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
                    gotoxy(20,9);
                    printf("\xB2 ID:%d", info.id);
                    gotoxy(47,9);
                    printf("\xB2");
                    gotoxy(20,10);
                    printf("\xB2 Name:%s", info.bookname);
                    gotoxy(47,10);
                    printf("\xB2");
                    gotoxy(20,11);
                    printf("\xB2 Author:%s", info.author);
                    gotoxy(47,11);
                    printf("\xB2");
                    gotoxy(20,12);
                    printf("\xB2 Quantity:%d", info.quantity);
                    gotoxy(47,12);
                    printf("\xB2");
                    gotoxy(20,13);
                    printf("\xB2 Price:Rs.%.2f", info.price);
                    gotoxy(47,13);
                    printf("\xB2");
                    gotoxy(20,14);
                    printf("\xB2 Rack No:%d ", info.rackno);
                    gotoxy(47,14);
                    printf("\xB2");
                    gotoxy(20,15);
                    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
                    check++;
                }

            }
            if(check == 0)
            {
                gotoxy(20,8);
                printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
                gotoxy(20,9);
                printf("\xB2");
                gotoxy(38,9);
                printf("\xB2");

                gotoxy(20,10);
                printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
                gotoxy(22,9);
                printf("\aNo Record Found");
            }
            gotoxy(20,17);
            printf("Try another search?(Y/N)");
            if(tolower(getch())=='y')
            {
                searchbook();
            }
            else
            {
                mainmenu();
                break;
            }
        }


        default :
        {
            getch();
            searchbook();
        }

    }
    fclose(fp);
}

void viewbooklist(void)  //show the list of book persists in library
{
    int i=0,j;
    system("cls");

    gotoxy(1,1);
    printf("*********************************Book List*****************************");
    gotoxy(2,2);
    printf(" CATEGORY     ID    BOOK NAME     AUTHOR       QTY     PRICE     RackNo ");
    j=4;

    fp=fopen("Stock.dat","rb");
    while(fread(&info,sizeof(info),1,fp)==1)
    {
        gotoxy(3,j);
        printf("%s", info.catago);
        gotoxy(16,j);
        printf("%d", info.id);
        gotoxy(22,j);
        printf("%s", info.bookname);
        gotoxy(36,j);
        printf("%s", info.author);
        gotoxy(50,j);
        printf("%d", info.quantity);
        gotoxy(57,j);
        printf("%.2f", info.price);
        gotoxy(69,j);
        printf("%d", info.rackno);
        printf("\n\n");
        j++;
        i=i+info.quantity;
    }
    gotoxy(3,25);
    printf("Total Books =%d", i);
    fclose(fp);
    gotoxy(35,25);
    returnfunc();
}

void returnfunc(void)
{

    printf(" Press ENTER to return to main menu");
    again:
    if(getch() == 13)
    {
        mainmenu();
    }
    else
    {
        goto again;
    }
}

void issuebook(void)  //function that issue books from library
{
    int ID;

    system("cls");
    printf("********************************ISSUE SECTION**************************");
    gotoxy(10,5);
    printf("\xDB\xDB\xDB\xDb\xB2 1. Issue a Book");
    gotoxy(10,7);
    printf("\xDB\xDB\xDB\xDb\xB2 2. View Issued Book");
    gotoxy(10,9);
    printf("\xDB\xDB\xDB\xDb\xB2 3. Search Issued Book");
    gotoxy(10,11);
    printf("\xDB\xDB\xDB\xDb\xB2 4. Remove Issued Book");
    gotoxy(10,14);

    printf("Enter a Choice:");
    switch(getch())
    {
        case '1':  //issue book
        {
            system("cls");
            int check = 0;
            char start='y';
            while(start == 'y')
            {
                system("cls");
                gotoxy(15,4);
                printf("***Issue Book section***");
                gotoxy(10,6);
                printf("Enter the Book Id:");
                scanf("%d", &ID);
                fp=fopen("Stock.dat","rb");
                fs=fopen("Issue.dat","ab+");
                if(verify(ID) == 0) //issues those which are present in library
                {
                    gotoxy(10,8);
                    printf("The book record is available");
                    gotoxy(10,9);
                    printf("There are %d unissued books in library ", info.quantity);
                    gotoxy(10,10);
                    printf("The name of book is %s", info.bookname);
                    gotoxy(10,11);
                    printf("Enter student name:");
                    scanf("%s", info.studentname);
			     //struct dosdate_t d; //for current date
			    // getdate(&d);
			     //a.issued.dd=d.day;
			     //a.issued.mm=d.month;
			    // a.issued.yy=d.year;
                    gotoxy(10,12);
                    printf("Issued date=%d-%d-%d", info.issued.dd, info.issued.mm, info.issued.yy);
                    gotoxy(10,13);
                    printf("The BOOK of ID %d is issued", info.id);
                    info.retdate.dd=info.issued.dd+RETURNTIME;   //for return date
                    info.retdate.mm=info.issued.mm;
                    info.retdate.yy=info.issued.yy;
                    if(info.retdate.dd > 30)
                    {
                        info.retdate.mm+=info.retdate.dd/30;
                        info.retdate.dd-=30;

                    }
                    if(info.retdate.mm > 12)
                    {
                        info.retdate.yy+=info.retdate.mm/12;
                        info.retdate.mm-=12;

                    }
                    gotoxy(10,14);

                    printf("To be return:%d-%d-%d", info.retdate.dd, info.retdate.mm, info.retdate.yy);
                    fseek(fs,sizeof(info),SEEK_END);
                    fwrite(&info,sizeof(info),1,fs);
                    fclose(fs);
                    check = 1;
                }
                if(check == 0)
                {
                    gotoxy(10,11);
                    printf("No record found");
                }
                gotoxy(10,15);
                printf("Issue any more(Y/N):");
                start = tolower(getche());
                fclose(fp);
            }

            break;
        }
        case '2':  //show issued book list
        {
            system("cls");
            int j=4;
            printf("*******************************Issued book list*******************************\n");
            gotoxy(2,2);
            printf("STUDENT NAME    CATEGORY    ID    BOOK NAME    ISSUED DATE    RETURN DATE");
            fs=fopen("Issue.dat","rb");
            while(fread(&info,sizeof(info),1,fs)==1)
            {
                gotoxy(2,j);
                printf("%s", info.studentname);
                gotoxy(18,j);

printf("%s", info.catago);
                gotoxy(30,j);
                printf("%d", info.id);
                gotoxy(36,j);
                printf("%s", info.bookname);
                gotoxy(51,j);
                printf("%d-%d-%d", info.issued.dd, info.issued.mm, info.issued.yy );
                gotoxy(65,j);
                printf("%d-%d-%d", info.retdate.dd, info.retdate.mm, info.retdate.yy);
                gotoxy(50,25);
//			    printf("Current date=%d-%d-%d",d.day,d.month,d.year);
                j++;

            }
            fclose(fs);
            gotoxy(1,25);
            returnfunc();
            break;
        }

        case '3':   //search issued books by id
        {
            system("cls");
            gotoxy(10,6);
            printf("Enter Book ID:");
            int id, check = 0;
            char start = 'y';
            while(start == 'y')
            {
                scanf("%d", &id);
                fs=fopen("Issue.dat","rb");
                while(fread(&info,sizeof(info),1,fs)==1)
                {
                    if(info.id == id)
                    {
                        issuerecord();
                        gotoxy(10,12);
                        printf("Press any key.......");
                        getch();
                        issuerecord();
                        check = 1;
                    }

                }
                fclose(fs);
                if(check == 0)
                {
                    gotoxy(10,8);
                    printf("No Record Found");
                }
                gotoxy(10,13);
                printf("Try Another Search?(Y/N)");
                start = tolower(getch());
            }
            break;
        }

        case '4':  //remove issued books from list
        {
            system("cls");
            int id;
            FILE *fg;  //declaration of temporary file for delete
            char start = 'y';
            while(start == 'y')
            {
                gotoxy(10,5);
                printf("Enter book id to remove:");
                scanf("%d", &id);
                fs=fopen("Issue.dat","rb+");
                while(fread(&info,sizeof(info),1,fs)==1)
                {
                    if(info.id == id)
                    {
                        issuerecord();
                        findbook='t';

}                    if(findbook=='t')
                    {
                        gotoxy(10,12);
                        printf("Do You Want to Remove it?(Y/N)");
                        if(tolower(getch())=='y')
                        {
                            fg=fopen("record.dat","wb+");
                            rewind(fs);
                            while(fread(&info,sizeof(info),1,fs)==1)
                            {
                                if(info.id!=id)
                                {
                                    fseek(fs,0,SEEK_CUR);
                                    fwrite(&info,sizeof(info),1,fg);
                                }
                            }
                            fclose(fs);
                            fclose(fg);
                            remove("Issue.dat");
                            rename("record.dat","Issue.dat");
                            gotoxy(10,14);
                            printf("The issued book is removed from list");

				       }

                    }
                    if(findbook!='t')
                    {
                        gotoxy(10,15);
                        printf("No Record Found");
                    }
                }
                gotoxy(10,16);
                printf("Delete any more?(Y/N)");
                start = tolower(getch());
            }

        }
        /*default:
        {
            gotoxy(10,18);
            printf("\aWrong Entry!!");
            getch();
            issuebook();
            break;
        }*/
        gotoxy(1,30);
        returnfunc();
    }
}

int issuerecord()  //display issued book's information
{
    system("cls");
    gotoxy(10,8);
    printf("The Book has taken by Mr. %s", info.studentname);
    gotoxy(10,9);
    printf("Issued Date:%d-%d-%d", info.issued.dd, info.issued.mm, info.issued.yy);
    gotoxy(10,10);
    printf("Returning Date:%d-%d-%d", info.retdate.dd, info.retdate.mm, info.retdate.yy);
}

void editbook(void)  //edit information about book
{
	system("cls");
	int check = 0;
	int id,e;
	gotoxy(20,4);
	printf("****Edit Books Section****");
	char start = 'y';
	while(start == 'y')
	{
		system("cls");
		gotoxy(15,6);
		printf("Enter Book Id to be edited:");
		scanf("%d", &id);
		fp=fopen("Stock.dat","rb+");
		while(fread(&info,sizeof(info),1,fp)==1)
		{
			if(verify(id) == 0)

{	gotoxy(15,7);
				printf("The book is availble");
				gotoxy(15,8);
				printf("The Book ID:%d", info.id);
				gotoxy(15,9);
				printf("Enter new name:");
				scanf("[^\n]%*c", info.bookname);
				gotoxy(15,10);
				printf("Enter new Author:");
				scanf("[^\n]%*c", info.author);
				gotoxy(15,11);
				printf("Enter new quantity:");
				scanf("%d", &info.quantity);
				gotoxy(15,12);
				printf("Enter new price:");
				scanf("%f", &info.price);
				gotoxy(15,13);
				printf("Enter new rackno:");
				scanf("%d", &info.rackno);
				gotoxy(15,14);
				printf("The record is modified");
				fseek(fp,ftell(fp)-sizeof(info),0);
				fwrite(&info,sizeof(info),1,fp);
				fclose(fp);
				check = 1;
			}
			if(check == 0)
			{
				gotoxy(15,9);
				printf("No record found");
			}
		}
		gotoxy(15,16);
		printf("Modify another Record?(Y/N)");
        start = tolower(getch()) ;
	}
    returnfunc();
}

int current_time(void) //for time
{
    time_t t;
    time(&t);
    printf("Date and time:%s\n", ctime(&t));

    return 0;
}



