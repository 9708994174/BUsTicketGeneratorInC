#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUSES 10
#define MAX_SEATS 40

int busIds[MAX_BUSES];
char sources[MAX_BUSES][20];
char destinations[MAX_BUSES][20];
float fares[MAX_BUSES];
int seats[MAX_BUSES][MAX_SEATS];
int numBuses = 0;

void displayBuses() {
    if (numBuses == 0) {
        printf("No buses available.\n");
        return;
    }
    
    printf("Available buses:\n");
    int i, j, count;
    for (i = 0; i < numBuses; i++) {
        count = 0;
        for (j = 0; j < MAX_SEATS; j++) {
            if (seats[i][j] == 0) {
                count++;
            }
        }
        printf("%d. %s to %s, fare: %.2f, seats available: %d\n", 
            busIds[i], sources[i], destinations[i], fares[i], count);
    }
}

void addBus() {
    if (numBuses == MAX_BUSES) {
        printf("Cannot add more buses.\n");
        return;
    }
    int newBusId = numBuses + 1;
    printf("Enter source: ");
    scanf("%s", sources[numBuses]);
    printf("Enter destination: ");
    scanf("%s", destinations[numBuses]);
    printf("Enter fare: ");
    scanf("%f", &fares[numBuses]);
    memset(seats[numBuses], 0, MAX_SEATS * sizeof(int));
    busIds[numBuses] = newBusId;
    numBuses++;
}

void bookSeat() {
    int busId, seatNum;
    printf("Enter bus ID: ");
    scanf("%d", &busId);
    if (busId < 1 || busId > numBuses) {
        printf("Invalid bus ID.\n");
        return;
    }
    printf("Enter seat number: ");
    scanf("%d", &seatNum);
    if (seatNum < 1 || seatNum > MAX_SEATS) {
        printf("Invalid seat number.\n");
        return;
    }
    if (seats[busId-1][seatNum-1] != 0) {
        printf("Seat already booked.\n");
        return;
    }
    seats[busId-1][seatNum-1] = 1;
    printf("Seat booked successfully.\n");
}

void cancelSeat() {
    int busId, seatNum;
    printf("Enter bus ID: ");
    scanf("%d", &busId);
    if (busId < 1 || busId > numBuses) {
        printf("Invalid bus ID.\n");
        return;
    }
    printf("Enter seat number: ");
    scanf("%d", &seatNum);
    if (seatNum < 1 || seatNum > MAX_SEATS) {
        printf("Invalid seat number.\n");
        return;
    }
    if (seats[busId-1][seatNum-1] == 0) {
        printf("Seat not booked.\n");
        return;
    }
    seats[busId-1][seatNum-1] = 0;
    printf("Seat cancelled successfully.\n");
}

void deleteOrUpdateBus() {
    int busId;
    printf("Enter bus ID: ");
    scanf("%d", &busId);
    if (busId < 1 || busId > numBuses
) {
printf("Invalid bus ID.\n");
return;
}
printf("What would you like to do?\n");
printf("1. Delete bus\n");
printf("2. Update bus details\n");
int choice;
scanf("%d", &choice);
if (choice == 1) {
int i, j;
for (i = busId - 1; i < numBuses - 1; i++) {
busIds[i] = busIds[i+1];
strcpy(sources[i], sources[i+1]);
strcpy(destinations[i], destinations[i+1]);
fares[i] = fares[i+1];
for (j = 0; j < MAX_SEATS; j++) {
seats[i][j] = seats[i+1][j];
}
}
numBuses--;
printf("Bus deleted successfully.\n");
} else if (choice == 2) {
printf("Enter new source: ");
scanf("%s", sources[busId-1]);
printf("Enter new destination: ");
scanf("%s", destinations[busId-1]);
printf("Enter new fare: ");
scanf("%f", &fares[busId-1]);
printf("Bus details updated successfully.\n");
} else {
printf("Invalid choice.\n");
}
}

int main() {
int choice;
while (1) {
printf("\nWelcome to the Electronic Bus Ticket Generator!\n");
printf("1. Display available buses for a route\n");
printf("2. Add new bus\n");
printf("3. Book seat\n");
printf("4. Cancel seat\n");
printf("5. Delete/Update a particular bus details\n");
printf("6. Exit\n");
printf("Enter your choice: ");
scanf("%d", &choice);
switch(choice) {
case 1: displayBuses(); break;
case 2: addBus(); break;
case 3: bookSeat(); break;
case 4: cancelSeat(); break;
case 5: deleteOrUpdateBus(); break;
case 6: exit(0);
default: printf("Invalid choice.\n");
}
}
return 0;
}




