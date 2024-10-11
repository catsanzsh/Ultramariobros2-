#include <stdio.h>

typedef enum {
    STEREO,
    MONO
} AudioMode;

// Function to display audio mode selection
void displayAudioSelect() {
    printf("Select Audio Mode:\n");
    printf("1: Stereo\n");
    printf("2: Mono\n");
}

// Function to set the audio mode based on user choice
AudioMode selectAudioMode() {
    int choice;
    while (1) {
        displayAudioSelect();
        printf("Enter your choice (1 or 2): ");
        scanf("%d", &choice);
        
        if (choice == 1) {
            return STEREO;
        } else if (choice == 2) {
            return MONO;
        } else {
            printf("Invalid choice. Please try again.\n");
        }
    }
}

int main() {
    AudioMode audioMode = selectAudioMode();
    
    if (audioMode == STEREO) {
        printf("Audio mode set to Stereo.\n");
    } else {
        printf("Audio mode set to Mono.\n");
    }

    // Additional game logic can go here

    return 0;
}
