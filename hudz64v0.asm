    .data
lives_text:      .asciiz "Lives: "
stars_text:      .asciiz "Stars: "
health_text:     .asciiz "Health: "

    .text
    .globl display_hud

# Function to display the HUD in Super Mario 64
display_hud:
    # Step 1: Load Mario's lives, stars, and health from memory
    lw      $t0, mario_lives       # Load Mario's life count into $t0
    lw      $t1, mario_stars       # Load Mario's star count into $t1
    lw      $t2, mario_health      # Load Mario's health into $t2

    # Step 2: Display the "Lives" text and count
    li      $a0, 100              # X position of lives text on screen
    li      $a1, 20               # Y position of lives text on screen
    la      $a2, lives_text        # Load address of "Lives: " text
    jal     draw_text              # Call the game's text drawing function

    move    $a0, $t0               # Move lives count into argument
    jal     draw_number            # Call function to draw the number of lives

    # Step 3: Display the "Stars" text and count
    li      $a0, 100              # X position of stars text on screen
    li      $a1, 40               # Y position of stars text on screen
    la      $a2, stars_text        # Load address of "Stars: " text
    jal     draw_text              # Call text drawing function

    move    $a0, $t1               # Move stars count into argument
    jal     draw_number            # Call function to draw the number of stars

    # Step 4: Display the "Health" text and value
    li      $a0, 100              # X position of health text on screen
    li      $a1, 60               # Y position of health text on screen
    la      $a2, health_text       # Load address of "Health: " text
    jal     draw_text              # Call text drawing function

    move    $a0, $t2               # Move health value into argument
    jal     draw_health_bar        # Call function to draw Mario's health bar

    jr      $ra                    # Return from function

# Helper functions for drawing text and numbers
# These are typically part of the game engine
draw_text:
    # Arguments: $a0 = x position, $a1 = y position, $a2 = text address
    # Implement this based on game engine's text rendering
    # This function will position the text and render it to the screen
    ...
    jr      $ra                    # Return after drawing text

draw_number:
    # Arguments: $a0 = number to display
    # This function renders the number on screen at the specified coordinates
    ...
    jr      $ra                    # Return after drawing number

draw_health_bar:
    # Arguments: $a0 = health value (0-100)
    # This function draws a health bar proportional to the value of $a0
    ...
    jr      $ra                    # Return after drawing health bar

# Optimized HUD rendering logic for better performance
optimized_display_hud:
    # Step 1: Load Mario's lives, stars, and health from memory
    lw      $t0, mario_lives       # Load Mario's life count into $t0
    lw      $t1, mario_stars       # Load Mario's star count into $t1
    lw      $t2, mario_health      # Load Mario's health into $t2

    # Step 2: Display the "Lives" text and count
    li      $a0, 100              # X position of lives text on screen
    li      $a1, 20               # Y position of lives text on screen
    la      $a2, lives_text        # Load address of "Lives: " text
    jal     draw_text              # Call the game's text drawing function

    move    $a0, $t0               # Move lives count into argument
    jal     draw_number            # Call function to draw the number of lives

    # Step 3: Display the "Stars" text and count
    li      $a0, 100              # X position of stars text on screen
    li      $a1, 40               # Y position of stars text on screen
    la      $a2, stars_text        # Load address of "Stars: " text
    jal     draw_text              # Call text drawing function

    move    $a0, $t1               # Move stars count into argument
    jal     draw_number            # Call function to draw the number of stars

    # Step 4: Display the "Health" text and value
    li      $a0, 100              # X position of health text on screen
    li      $a1, 60               # Y position of health text on screen
    la      $a2, health_text       # Load address of "Health: " text
    jal     draw_text              # Call text drawing function

    move    $a0, $t2               # Move health value into argument
    jal     draw_health_bar        # Call function to draw Mario's health bar

    jr      $ra                    # Return from function
