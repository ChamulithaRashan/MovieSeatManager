#include <stdio.h>
#include <stdlib.h>
#define ROWS 5
#define COLUMNS 10
#define MOVIES 3
#define SHOWTIMES 2
#include <ctype.h>
#include <string.h>

void viewMoviesAndShowtimes();
void viewSeatMap();
void bookTickets();
void cancelBookings();
void searchBookings();
void revenueReports();
void mainMenu();
void searchbyname();
void searchbynumber();
void movieList();

char movies[3][30]=
{
    "Avengers Endgame",
    "Avatar 2",
    "John Wick 4"

};

char showtimes[2][30]=
{
    "10:00 AM",
    "7:00 PM"

};

int seats[6][ROWS][COLUMNS]= {0};
char customerName[6][ROWS][COLUMNS][30];
float ticketprice[6][ROWS][COLUMNS];

int main()
{
    mainMenu();
    return 0;
}
void mainMenu()
{
    int option=1;
    printf("==================================================\n");
    printf("              MOVIE SEAT MANAGER                  \n");
    printf("==================================================\n");
    printf("\n\n     Welcome to the Movie Ticket System        \n\n\n");
    printf("--------------------------------------------------\n\n");
    printf(" 1. View Movies & Showtimes\n");
    printf(" 2. View Seat Map\n");
    printf(" 3. Booking Tickets\n");
    printf(" 4. Cancel Booking\n");
    printf(" 5. Search Booking\n");
    printf(" 6. Revenue Report\n");
    printf(" 7. Exit\n\n");
    printf("--------------------------------------------------\n\n");
    while(option)
    {
        printf("Select an option (1-7) : ");
        scanf("%d",&option);
        printf("\n");
        switch(option)
        {
        case 1 :
            viewMoviesAndShowtimes();
            option=0;
            break;
        case 2 :
            viewSeatMap();
            option=0;
            break;
        case 3 :
            bookTickets();
            option=0;
            break;
        case 4 :
            cancelBookings();
            option=0;
            break;
        case 5 :
            searchBookings();
            option=0;
            break;
        case 6 :
            revenueReports();
            option=0;
            break;
        case 7 :
            printf("Thank You !");
            return ;
        default:
            printf("\tInvalid Input\n\n");
            option=1;
        }
    }
}

void viewMoviesAndShowtimes()
{
    system("cls");
    char choice;
    printf("============================================\n");
    printf("             MOVIE SEAT MANAGER              \n");
    printf("============================================\n");
    printf("             VIEW MOVIES & SHOWTIMES          \n");
    printf("============================================\n\n");

    movieList();

    printf("============================================\n");

    while(1)
    {
        printf("Back to main menu (Y/N): ");
        scanf(" %c", &choice);

        if (choice=='Y' || choice=='y')
        {
            system("cls");
            mainMenu();
        }
        else if (choice=='N' ||choice== 'n')
        {
            system("cls");
            printf("=========================================\n");
            printf("         GOOD BYE! HAVE A NICE DAY       \n");
            printf("=========================================\n");
            exit(0);
        }
        else
        {
            printf("\n\tInvalid choice! Please enter Y or N.\n\n");
        }
    }
}

void viewSeatMap()
{
    system("cls");
    printf("========================================================\n");
    printf("                  VIEW SEAT MAP                         \n");
    printf("========================================================\n");
    movieList();
    int option1;
    int option2;
    int screen;
    printf(" Movie : ");
    scanf("%d",&option1);
    printf(" Showtime : ");
    scanf("%d",&option2);
    screen=(option1-1)*2+(option2-1);
    printf("\n (.) = Available\n");
    printf(" (*) = Booked\n\n");
    printf(" Rows A-B : Regular (Rs.500)\n");
    printf(" Rows C-D : Premium (Rs.750)\n");
    printf(" Row  E   : VIP (Rs.1000)\n");
    printf("\n\t");

    for(int i=1; i<=10; i++)
    {
        printf("%2d ",i);
    }
    printf("\n");

    for(int i=0; i<5; i++)
    {
        printf("%c  ",'A'+i);
        printf("\t ");
        for(int j=0; j<10; j++)
        {
            if(seats[screen][i][j]==0)
            {
                printf(".  ");
            }
            else
            {
                printf("*  ");
            }
        }
        printf("\n");
    }



}

void bookTickets()
{
    system("cls");


    printf("=====================================================================\n");
    printf("                          Booking Ticket                             \n");
    printf("=====================================================================\n\n");
    movieList();
    int movie;
    printf("Select Movie:");
    scanf("%d",&movie);
    printf("\n");

    int showtimes;
    char rowChar;
    int columnChar;
    printf("Select Show Time:");
    scanf("%d",&showtimes);
    printf("\n");
    int screen=(movie-1)*2+(showtimes-1);
    char customer_name[50];
    printf("Enter Customer Name:");
    scanf("%s",&customer_name);
    printf("\n");
    printf("Select Row:");
    scanf(" %c",&rowChar);
    rowChar = toupper(rowChar);
    printf("\n");
    printf("Enter Column :");
    scanf("%d",&columnChar);

    printf("Ticket Type\n");
    printf("\n");

    printf("1.Regular \n");
    printf("2.Student (10%% Discount)\n");
    printf("3.Senior Citizen (20%%Discount)\n");

    printf("\n");

    int choice;
    printf("Enter Choice :");
    scanf("%d",&choice);
    printf("\n");

    int number_of_ticket;
    printf("Number Of Ticket :");
    scanf("%d",&number_of_ticket);
    printf("\n");

    printf("------------------------------------------------------\n");

    printf("Ticket Price  : Rs.750.00\n");
    printf("Discount      : Rs.75.00\n");
    printf("Total price   : Rs.675.00\n");

    int row=rowChar-'A';
    int column=columnChar-1;
    if(seats[screen][row][column]==1){
        printf("Seat Already Booked\n");
    }else{
        strcpy(customerName[screen][row][column],customer_name);

        seats[screen][row][column]=1;

        ticketprice[screen][row][column]=choice;

        printf("Succesfuly Booked \n");

    }
   // printf ("Confirm Booking (Y/N)");
    char choice3;
    printf("Back to main menu (Y/N): ");
    scanf(" %c", &choice3);
    if (choice3=='Y' || choice3=='y')
    {
        //system("cls");
        mainMenu();
    }
    else if (choice3=='N' ||choice3== 'n')
    {
        system("cls");
        printf("=========================================\n");
        printf("         GOOD BYE! HAVE A NICE DAY       \n");
        printf("=========================================\n");
        exit(0);
    }
    else
    {
        printf("\n\tInvalid choice! Please enter Y or N.\n\n");
    }



}

void cancelBookings()
{
    system("cls");
    char row_[20];
    int seat_num;
    char choice;

    printf("=====================================================================\n");
    printf("%37s\n","CANCEL BOOKING");
    printf("=====================================================================\n");
    printf("Enter Row (A-E): ");
    scanf("%s",row_);
    printf("Enter Seat Number (1-10): ");
    scanf("%d",&seat_num);

    printf("Back to main menu (Y/N): ");
    scanf(" %c", &choice);

    if (choice=='Y' || choice=='y')
    {
        system("cls");
        mainMenu();
    }
    else if (choice=='N' ||choice== 'n')
    {
        system("cls");
        printf("=========================================\n");
        printf("         GOOD BYE! HAVE A NICE DAY       \n");
        printf("=========================================\n");
        exit(0);
    }
    else
    {
        printf("\n\tInvalid choice! Please enter Y or N.\n\n");
    }
}

void searchBookings()
{

    system("cls");
    int choi;
    char name[30];
    printf("=====================================================================\n");
    printf("                          SEARCH BOOKING                             \n");
    printf("=====================================================================\n\n");
    printf("1.Search by Customer Name\n\n");
    printf("2.Search by Seat Number\n\n");
    while(1)
    {
        printf("Enter Choice (1,2):");
        scanf("%d",&choi);

        if (choi==1)
        {
            system("cls");
            printf("----------Search By Customer Name----------\n\n");
            printf("Enter customer Name:");
            scanf("%s",name);
            break;
            printf("---------------------------------------------------------");
            searchbyname();
            printf("---------------------------------------------------------");
        }
        else if (choi==2)
        {
            system("cls");
            printf("--------Search By Seat Number-----------\n\n");
            searchbynumber();
            break;
        }
        else
        {
            printf("\n      Invalid Input\n\n");
            choi=0;
        }
    }

}
void searchbyname() {}
void searchbynumber() {}


void revenueReports()
{
    system("cls");
    char choice;
    printf("======================================================================================\n");
    printf("%55s\n","CINEMA REVENUE REPORT");
    printf("======================================================================================\n");
    printf("%-20s %-20s %-17s %-20s\n","Movie Title","Show Time","Tickets Sold","Total Revenue(LKR)");
    printf("--------------------------------------------------------------------------------------\n");
    for(int i=0; i<MOVIES; i++)
    {
        for(int j=0; j<SHOWTIMES; j++)
        {
            printf("%-20s %-20s %-17s %-20s\n",movies[i],showtimes[j]);
        }

        printf("--------------------------------------------------------------------------------------\n");
    }
    printf("Back to main menu (Y/N): ");
    scanf(" %c", &choice);

    if (choice=='Y' || choice=='y')
    {
        system("cls");
        mainMenu();
    }
    else if (choice=='N' ||choice== 'n')
    {
        system("cls");
        printf("=========================================\n");
        printf("         GOOD BYE! HAVE A NICE DAY       \n");
        printf("=========================================\n");
        exit(0);
    }
    else
    {
        printf("\n\tInvalid choice! Please enter Y or N.\n\n");
    }
}
void movieList()
{
    for(int i=0; i<MOVIES; i++)
    {
        printf(" %d.%s\n",i+1,movies[i]);
        for(int j=0; j<SHOWTIMES; j++)
        {
            printf("\t%d.%s\n",j+1,showtimes[j]);
        }
        printf("\n");

    }
}


