#include <stdio.h>

// Define constants for coin rewards
#define COINS_FOR_EXTRA_LIFE 100

// Global variable to keep track of coins
int coinsCount = 0;
int lives = 3; // Assuming a player starts with 3 lives

// Function to initialize the coin counter
void initCoins() {
    coinsCount = 0;
    printf("Coin counter initialized. You have collected %d coins.\n", coinsCount);
}

// Function to add coins and check for rewards
void collectCoin() {
    coinsCount++;
    printf("Coin collected! Total coins: %d\n", coinsCount);

    // Check if the player earns an extra life every 100 coins
    if (coinsCount % COINS_FOR_EXTRA_LIFE == 0) {
        lives++;
        printf("Congratulations! You've earned an extra life. Total lives: %d\n", lives);
    }
}

// Function to display the current number of coins and lives
void displayCoins() {
    printf("Total coins collected: %d\n", coinsCount);
    printf("Total lives: %d\n", lives);
}

// Function to reset the coin counter (if needed, such as at the start of a new level or new game)
void resetCoins() {
    coinsCount = 0;
    printf("Coin counter reset. You have collected %d coins.\n", coinsCount);
}

int main() {
    initCoins();  // Initialize the coin counter

    // Example usage of the functions
    for (int i = 0; i < 150; i++) {  // Collect 150 coins as a test
        collectCoin();
    }
    displayCoins();

    // Resetting for demonstration purposes
    resetCoins();
    displayCoins();

    return 0;
}
