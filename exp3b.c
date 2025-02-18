#include<stdio.h>
#include<stdlib.h>

int eating[5] = {0, 0, 0, 0, 0}; 
int mutex = 1;
int philosopher = 5; 
int chopsticks[5] = {1, 1, 1, 1, 1}; 

void pick_chopstick(int philosopher);
void put_chopstick(int philosopher);

int main() {
    int choice;
    
    printf("\n1. pick_up\n2. put_down\n3. exit\n");
    while (1) {
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            printf("Enter the philosopher number (1-5): ");
            scanf("%d", &philosopher);
            if (philosopher < 1 || philosopher > 5) {
                printf("Invalid philosopher number!\n");
            } else {
                pick_chopstick(philosopher - 1);
            }
            break;

        case 2:
            printf("Enter the philosopher number (1-5): ");
            scanf("%d", &philosopher);
            if (philosopher < 1 || philosopher > 5) {
                printf("Invalid philosopher number!\n");
            } else {
                put_chopstick(philosopher - 1); 
            }
            break;

        case 3:
            exit(0);
            break;
        }
    }
    return 0;
}

void pick_chopstick(int philosopher) {
    --mutex; 
    
    if (eating[philosopher] == 1) {
        printf("Philosopher %d is already eating. They cannot pick up chopsticks again.\n", philosopher + 1);
    } else if (chopsticks[philosopher] == 1 && chopsticks[(philosopher + 1) % 5] == 1) {
   
        chopsticks[philosopher] = chopsticks[(philosopher + 1) % 5] = 0;
        eating[philosopher] = 1;
        printf("Philosopher %d picks up chopsticks %d and %d\n", philosopher + 1, philosopher + 1, (philosopher + 1) % 5 + 1);
        printf("Philosopher %d is now eating\n", philosopher + 1);
    } else {
        printf("Philosopher %d cannot pick up chopsticks because they are already held\n", philosopher + 1);
    }

    ++mutex; 
}

void put_chopstick(int philosopher) {
    --mutex; 

    if (eating[philosopher] == 1) { 
        
        chopsticks[philosopher] = chopsticks[(philosopher + 1) % 5] = 1;
        eating[philosopher] = 0;
        printf("Philosopher %d puts down chopsticks %d and %d\n", philosopher + 1, philosopher + 1, (philosopher + 1) % 5 + 1);
        printf("Philosopher %d is done eating\n", philosopher + 1);
    } else {
        printf("Philosopher %d cannot put down chopsticks because they are not holding any\n", philosopher + 1);
    }

    ++mutex; 
}

