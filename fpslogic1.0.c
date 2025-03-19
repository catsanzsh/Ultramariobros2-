#include <stdio.h>
#include <time.h>

#define FPS 60
#define FRAME_DURATION (1.0 / FPS)

// Function to calculate the time elapsed since the last frame
double getTime() {
    struct timespec ts;
    clock_gettime(CLOCK_MONOTONIC, &ts);
    return ts.tv_sec + ts.tv_nsec / 1.0e9;
}

// Main game loop with FPS control
void gameLoop() {
    double lastTime = getTime();
    double currentTime;
    double deltaTime;
    double accumulator = 0.0;

    while (1) {
        currentTime = getTime();
        deltaTime = currentTime - lastTime;
        lastTime = currentTime;

        accumulator += deltaTime;

        // Process game logic at a fixed interval
        while (accumulator >= FRAME_DURATION) {
            updateGame(); // Update game logic
            accumulator -= FRAME_DURATION;
        }

        renderGame(); // Render the frame
        synchronizeFrame(FRAME_DURATION - accumulator); // Synchronize the FPS
    }
}

// Function to update game logic
void updateGame() {
    // Game logic here (e.g., handling input, moving objects, etc.)
}

// Function to render the game
void renderGame() {
    // Rendering code here (e.g., drawing objects on the screen)
}

// Function to synchronize the frame rate
void synchronizeFrame(double timeLeft) {
    if (timeLeft > 0) {
        struct timespec ts;
        ts.tv_sec = (time_t) timeLeft;
        ts.tv_nsec = (timeLeft - ts.tv_sec) * 1.0e9;
        nanosleep(&ts, NULL); // Sleep to maintain a steady frame rate
    }
}

int main() {
    gameLoop();
    return 0;
}
// Function to render the game
void renderGame() {
    // Rendering code here (e.g., drawing objects on the screen)
}

// Function to synchronize the frame rate
void synchronizeFrame(double timeLeft) {
    if (timeLeft > 0) {
        struct timespec ts;
        ts.tv_sec = (time_t) timeLeft;
void synchronizeFrame(double timeLeft) {
    if (timeLeft > 0) {
        struct timespec ts;
        ts.tv_sec = (time_t) timeLeft;
        ts.tv_nsec = (timeLeft - ts.tv_sec) * 1.0e9;
        nanosleep(&ts, NULL); // Sleep to maintain a steady frame rate
    }
}

int main() {
    gameLoop();
        ts.tv_nsec = (timeLeft - ts.tv_sec) * 1.0e9;
    return 0;
}
    return 0;
}
