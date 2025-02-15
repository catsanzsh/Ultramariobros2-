; test.asm

.data
bootStart:
    .word 0x10000000  ; Start address
    .word entryPoint  ; Entry point

.text
entryPoint:
    lui $gp, 0x0000   ; Load upper immediate
    lui $sp, 0x8000   ; Initialize stack pointer

    # Initialize video mode
    lui $a0, 0xA430
    addiu $a0, $a0, 0x0040
    li $a1, 0x0003  ; Video mode: 320x240, 16-bit color
    sw $a1, 0($a0)

    # Set up frame buffer
    lui $a0, 0xA800
    addiu $a0, $a0, 0x0000
    lui $a1, 0x0000
    sw $a1, 0($a0)

    # Initialize display list
    lui $a0, 0xA400
    addiu $a0, $a0, 0x0000
    lui $a1, 0x0000
    sw $a1, 0($a0)

    # Initialize game state
    li $t0, 0         ; Player X position
    li $t1, 0         ; Player Y position
    li $t2, 1         ; Game running flag

    # Infinite loop
mainLoop:
    beqz $t2, end_game
    jal handle_input
    jal update_game_logic
    jal render_graphics
    j mainLoop

end_game:
    nop

handle_input:
    # Read controller input
    lui $a0, 0xA480  ; Controller port address
    lw $a1, 0($a0)   ; Read input data

    # Check joystick movement
    andi $a2, $a1, 0x00FF  ; Extract joystick X axis
    blt joystick_left
    bgt joystick_right

joystick_left:
    # Move player left
    lw $t3, PLAYER_X
    addi $t3, $t3, -1
    sw $t3, PLAYER_X
    j handle_input_end

joystick_right:
    # Move player right
    lw $t3, PLAYER_X
    addi $t3, $t3, 1
    sw $t3, PLAYER_X

handle_input_end:
    jr $ra

render_graphics:
    # Set up vertices
    lui $a0, 0xA400  ; Display list address
    addiu $a0, $a0, 0x0000
    li $a1, 0x01000000  ; Vertex command
    sw $a1, 0($a0)

    # Vertex 1
    li $a1, 0x00010000  ; X1, Y1, Z1
    sw $a1, 4($a0)
    li $a1, 0x000000FF  ; Color (R,G,B,A)
    sw $a1, 8($a0)

    # Vertex 2
    li $a1, 0x00100000  ; X2, Y2, Z2
    sw $a1, 12($a0)
    li $a1, 0x00FF0000  ; Color (R,G,B,A)
    sw $a1, 16($a0)

    # Vertex 3
    li $a1, 0x0000FF00  ; X3, Y3, Z3
    sw $a1, 20($a0)
    li $a1, 0x0000FF00  ; Color (R,G,B,A)
    sw $a1, 24($a0)

    # End display list
    li $a1, 0xBF000000
    sw $a1, 28($a0)

    jr $ra

update_game_logic:
    # Update player position
    lw $t3, PLAYER_X
    addi $t3, $t3, 1   ; Move right every frame for simplicity
    sw $t3, PLAYER_X

    # Check collision with screen boundaries
    li $t4, SCREEN_WIDTH
    bge $t3, $t4, game_over

    jr $ra

game_over:
    li $t2, 0    ; Set game running flag to 0
    jr $ra
