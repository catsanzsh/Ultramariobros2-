#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILES 3
#define FILENAME_LENGTH 20

typedef struct {
    char name[FILENAME_LENGTH];
    int isUsed; // 1 if the file is used, 0 if empty
} SaveFile;

// Function to display the file select menu
void displayFileSelect(SaveFile saveFiles[], int count) {
    printf("Select a save file:\n");
    for (int i = 0; i < count; i++) {
        if (saveFiles[i].isUsed) {
            printf("%d: %s\n", i + 1, saveFiles[i].name);
        } else {
            printf("%d: [Empty]\n", i + 1);
        }
    }
}

// Function to load a save file
void loadSaveFile(SaveFile saveFiles[], int index) {
    if (saveFiles[index].isUsed) {
        printf("Loading game from %s...\n", saveFiles[index].name);
        // Logic to load the game state can be added here
    } else {
        printf("This save file is empty.\n");
    }
}

int main() {
    SaveFile saveFiles[MAX_FILES] = {
        {"File1.sav", 1},
        {"File2.sav", 1},
        {"File3.sav", 0}
    };

    int choice;

    while (1) {
        displayFileSelect(saveFiles, MAX_FILES);
        printf("Enter the file number to load (or 0 to exit): ");
        scanf("%d", &choice);

        if (choice == 0) {
            break; // Exit the file select screen
        } else if (choice > 0 && choice <= MAX_FILES) {
            loadSaveFile(saveFiles, choice - 1);
        } else {
            printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
