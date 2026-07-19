#include <stdio.h>
#include <stdlib.h>
#define ROWS 5
#define COLUMNS 10
void viewMoviesAndShowtimes();
void viewSeatMap();
void bookTickets();
void cancelBookings();
void searchBookings();
void revenueReports();
void mainMenu();

char movies[3][30]={
    "Avengers Endgame",
    "Avatar 2",
    "John Wick 4"

};

char showtimes[2][30]={
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
        case 7 :printf("Thank You !");
            return ;
        default:
            printf("\tInvalid Input\n\n");
            option=1;
        }
    }
}

void viewMoviesAndShowtimes()
{

}

void viewSeatMap()
{
}

void bookTickets()
{
}

void cancelBookings()
{
}

void searchBookings()
{
}

void revenueReports()
{
}


