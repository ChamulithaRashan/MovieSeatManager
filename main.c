#include <stdio.h>
#include <stdlib.h>
#define ROWS 5
#define COLUMNS 10
#define MOVIES 3
#define SHOWTIMES 2
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

int seats[6][ROWS][COLUMNS];

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
    printf(" 3. Book Tickets\n");
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
    int option1;
    int option2;
    printf(" Movie : ");
    scanf("%d",&option1);
    printf(" Showtime : ");
    scanf("%d",&option2);
    printf("\n (.) = Available\n");
    printf(" (X) = Booked\n\n");
    printf(" Rows A-B : Regular (Rs.500)\n");
    printf(" Rows C-D : Premium (Rs.750)\n");
    printf(" Row  E   : VIP (Rs.1000)\n");



}

void bookTickets()
{
}

void cancelBookings()
{
}

void searchBookings()
{

    system("cls");
    int choi;
    char name;
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


