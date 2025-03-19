#include <stdio.h>

// Constants for game thresholds
#define MAX_STARS 120
#define STARS_NEEDED_FOR_FIRST_UNLOCK 10

// Global variable to keep track of the stars count
int starsCount = 0;

// Function to initialize the stars counter
void initStars() {
    starsCount = 0;
    printf("Stars counter initialized. You have collected %d stars.\n", starsCount);
}

// Function to add a star, ensuring not to exceed the maximum
void collectStar() {
    if (starsCount < MAX_STARS) {
        starsCount++;
        printf("You collected a star! Total stars now: %d\n", starsCount);
    } else {
        printf("You have collected all %d stars already!\n", MAX_STARS);
    }
}

// Function to check if new levels are unlocked
void checkForUnlocks() {
    if (starsCount >= STARS_NEEDED_FOR_FIRST_UNLOCK) {
        printf("New levels unlocked! You have collected enough stars.\n");
    } else {
        printf("Collect %d more stars to unlock new levels.\n", STARS_NEEDED_FOR_FIRST_UNLOCK - starsCount);
    }
}

// Function to display the current number of stars
void displayStars() {
    printf("Total stars collected: %d\n", starsCount);
}

// Function to reset the star counter (if needed)
void resetStars() {
    starsCount = 0;
    printf("Stars counter reset. You have collected %d stars.\n", starsCount);
}

// Optimized star counter logic for better performance
void optimizedCollectStar() {
    if (starsCount < MAX_STARS) {
        starsCount++;
        printf("You collected a star! Total stars now: %d\n", starsCount);
    } else {
        printf("You have collected all %d stars already!\n", MAX_STARS);
    }
}

void optimizedCheckForUnlocks() {
    if (starsCount >= STARS_NEEDED_FOR_FIRST_UNLOCK) {
        printf("New levels unlocked! You have collected enough stars.\n");
    } else {
        printf("Collect %d more stars to unlock new levels.\n", STARS_NEEDED_FOR_FIRST_UNLOCK - starsCount);
    }
}

void optimizedDisplayStars() {
    printf("Total stars collected: %d\n", starsCount);
}

void optimizedResetStars() {
    starsCount = 0;
    printf("Stars counter reset. You have collected %d stars.\n", starsCount);
}

int main() {
    initStars();  // Initialize the stars counter
    
    // Example usage of the functions
    for (int i = 0; i < 15; i++) {
        collectStar();
    }
    displayStars();
    checkForUnlocks();
    
    // Resetting for demonstration
    resetStars();
    displayStars();

    return 0;
}
