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
void showSeats(int);

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
    char choice;
    printf("========================================================\n");
    printf("                  VIEW SEAT MAP                         \n");
    printf("========================================================\n");
    movieList();
    int option1;
    int option2;
    int screen;
    while (1)
    {
        printf(" Movie(1/2/3) : ");
        if(scanf("%d",&option1) == 1 && (option1 >= 1 && option1 <= 3))
        {
            break;
        }
        else
        {
            printf("\n\tInvalid movie selection !\n\n");
            while (getchar() !='\n');
        }
    }
    while (1)
    {
        printf(" Showtime(1/2) : ");
        if(scanf("%d",&option2) == 1 && (option2 == 1 || option2 == 2))
        {
            break;
        }
        else
        {
            printf("\n\tInvalid showtime selection !\n\n");
            while (getchar() !='\n');
        }
    }
    screen=(option1-1)*2+(option2-1);
    showSeats(screen);
}

void bookTickets()
{
    system("cls");


    printf("=====================================================================\n");
    printf("                          Booking Ticket                             \n");
    printf("=====================================================================\n\n");

    movieList();

    int movie;
    int showtime;
    char rowChar;
    int columnChar;
    while (1)
    {
        printf(" Select Movie(1/2/3) : ");
        if(scanf("%d",&movie) == 1 && (movie >= 1 && movie <= 3))
        {
            break;
        }
        else
        {
            printf("\n\tInvalid movie selection !\n\n");
            while (getchar() !='\n');
        }
    }
    while (1)
    {
        printf(" Showtime(1/2) : ");
        if(scanf("%d",&showtime) == 1 && (showtime == 1 || showtime == 2))
        {
            break;
        }
        else
        {
            printf("\n\tInvalid showtime selection !\n\n");
            while (getchar() !='\n');
        }
    }

    int screen=(movie-1)*2+(showtime-1);

    printf("=============Seat Map=============\n");
    showSeats(screen);
    printf("\n");

    char customer_name[50];
    printf(" \nEnter Customer Name : ");
    scanf("%49s",customer_name);

    int number_of_ticket;
    printf("\nNumber Of Ticket :");
    scanf("%d",&number_of_ticket);

    printf("\n");
    float pricePerTicket=1000.0;
    float total=0;
    for(int i=0; i<number_of_ticket; i++)
    {
        printf("======================================================\n");
        printf("        Ticket %d of %d\n", i + 1, number_of_ticket);
        printf("======================================================\n");
        int choice;

        printf("\nTicket Type\n\n");
        printf("1. Regular\n\n");
        printf("2. Student (10%% Discount)\n\n");
        printf("3. Senior Citizen (20%% Discount)\n\n");

        printf("Enter Ticket Type : ");
        scanf("%d", &choice);

        while(choice < 1 || choice > 3)
        {
            printf("Invalid choice! Enter again: ");
            scanf("%d", &choice);
        }

        printf("\n Select Row(A-E) :");
        scanf(" %c",&rowChar);
        rowChar = toupper(rowChar);
        printf("\n");

        printf(" Enter Column(1-10) : ");
        scanf("%d",&columnChar);

        int row=rowChar-'A';
        int column=columnChar-1;
        if(row<0||row>=ROWS||column<0||column>=COLUMNS)
        {
            printf("Invalid Seat!\n");
            i--;
            continue;
        }
        if(seats[screen][row][column]==1)
        {
            printf("Seat Already Booked\n");
            i--;
            continue;
        }


        strcpy(customerName[screen][row][column],customer_name);

        seats[screen][row][column]=1;

        float ticketPrice=pricePerTicket;

        if(choice==2)
            ticketPrice*=0.90;
        else if(choice==3)
            ticketPrice*=0.80;
        ticketprice[screen][row][column]=ticketPrice;
        total+=ticketPrice;
        printf("Seat %c%d Booked Successfully!\n",rowChar,columnChar);
    }
    float discount=0;

    float originalTotal = pricePerTicket * number_of_ticket;
    discount = originalTotal - total;

    printf("\n=====================================\n");
    printf("           Booking Summary\n");
    printf("=====================================\n");

    printf("Original Price : Rs. %.2f\n", originalTotal);
    printf("Discount       : Rs. %.2f\n", discount);
    printf("Total Price    : Rs. %.2f\n", total);

    printf("\nBooked Tickets\n");
    printf("-------------------------------------\n");

    for(int r = 0; r < ROWS; r++)
    {
        for(int c = 0; c < COLUMNS; c++)
        {
            if(strcmp(customerName[screen][r][c], customer_name) == 0)
            {
                printf("Seat : %c%d\n", 'A'+r, c+1);
                printf("Price: Rs. %.2f\n", ticketprice[screen][r][c]);
                printf("-------------------------------------\n");
            }
        }
    }
    char choice3;
    printf("Back to main menu (Y/N): ");
    scanf(" %c",&choice3);
    if (choice3=='Y' || choice3=='y')
    {
        system("cls");
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

void cancelBookings()
{
    system("cls");
    int movie, showtime;
    char rowChar;
    int colNum;
    char choice;

    printf("=====================================================================\n");
    printf("%40s\n","CANCEL BOOKING");
    printf("=====================================================================\n\n");

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
void showSeats(int screen)
{
    printf("\n (.) = Available\n");
    printf(" (X) = Booked\n\n");
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
                printf("X  ");
            }


            grandTotalTickets+=ticketsSold;
            grandTotalRevenue+=showtimeRevenue;


            printf("%-20s %-15s %-15d Rs.%-17.2f\n",movies[i],showtimes[j],ticketsSold,showtimeRevenue);
        }
        printf("\n");
    }
}


