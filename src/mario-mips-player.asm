    .data
prompt:         .asciiz "Enter command (a: left, d: right, j: jump): "
newline:        .asciiz "\n"
marioPosXText:  .asciiz "Mario X position: "
marioPosYText:  .asciiz "Mario Y position: "

# Mario's attributes
marioPosX:      .float 0.0    # Mario's X position
marioPosY:      .float 0.0    # Mario's Y position
velocityX:      .float 0.0    # Horizontal velocity
velocityY:      .float 0.0    # Vertical velocity
onGround:       .word 1       # Boolean flag (1 if on ground, 0 if in the air)

    .text
    .globl main

# Main function
main:
    # Initialize Mario's position and velocity
    li      $t0, 0                # Set Mario's initial positions
    sw      $t0, marioPosX        # Mario's X position = 0.0
    sw      $t0, marioPosY        # Mario's Y position = 0.0
    sw      $t0, velocityX        # velocityX = 0.0
    sw      $t0, velocityY        # velocityY = 0.0
    li      $t1, 1                # onGround = true
    sw      $t1, onGround

game_loop:
    # Prompt user for input
    la      $a0, prompt           # Load the prompt string address
    li      $v0, 4                # Syscall for printing a string
    syscall

    # Read user input (one character)
    li      $v0, 12               # Syscall for reading a character
    syscall
    move    $t2, $v0              # Store the input in $t2

    # Handle input: a = left, d = right, j = jump
    li      $t3, 'a'
    beq     $t2, $t3, move_left
    li      $t3, 'd'
    beq     $t2, $t3, move_right
    li      $t3, 'j'
    beq     $t2, $t3, jump
    j       stop_movement

# Movement to the left
move_left:
    li.s    $f0, -1.0             # Load float -1.0 into $f0
    s.s     $f0, velocityX        # Set velocityX to -1.0
    j       continue_loop

# Movement to the right
move_right:
    li.s    $f0, 1.0              # Load float 1.0 into $f0
    s.s     $f0, velocityX        # Set velocityX to 1.0
    j       continue_loop

# Jump logic
jump:
    lw      $t4, onGround         # Check if Mario is on the ground
    beq     $t4, $zero, continue_loop  # If not on the ground, skip jump

    # Apply jump: set velocityY = 5.0 and onGround = false
    li.s    $f1, 5.0              # Load float 5.0 into $f1
    s.s     $f1, velocityY        # Set velocityY to 5.0
    li      $t4, 0                # onGround = false
    sw      $t4, onGround
    j       continue_loop

# Stop horizontal movement
stop_movement:
    li.s    $f0, 0.0              # Load float 0.0 into $f0
    s.s     $f0, velocityX        # Set velocityX to 0.0

# Continue the game loop
continue_loop:
    # Update Mario's X position: X += velocityX
    l.s     $f2, marioPosX        # Load current X position into $f2
    l.s     $f4, velocityX        # Load velocityX into $f4
    add.s   $f2, $f2, $f4         # marioPosX += velocityX
    s.s     $f2, marioPosX        # Store updated X position

    # Update Mario's Y position: apply gravity
    l.s     $f3, marioPosY        # Load current Y position into $f3
    l.s     $f5, velocityY        # Load velocityY into $f5
    sub.s   $f3, $f3, $f5         # marioPosY -= velocityY
    s.s     $f3, marioPosY        # Store updated Y position

    # Apply gravity: velocityY -= 0.1
    li.s    $f6, 0.1              # Load gravity (0.1) into $f6
    sub.s   $f5, $f5, $f6         # velocityY -= 0.1
    s.s     $f5, velocityY        # Store updated velocityY

    # Check if Mario lands on the ground (if Y <= 0)
    li.s    $f7, 0.0              # Load ground level (0.0) into $f7
    c.le.s  $f3, $f7              # Check if marioPosY <= 0.0
    bc1t    land_on_ground         # If true, land on ground

    j       print_status           # Print Mario's current status

# Mario lands on the ground
land_on_ground:
    li.s    $f3, 0.0              # Set marioPosY to 0.0
    s.s     $f3, marioPosY
    li      $t4, 1                # Set onGround = true
    sw      $t4, onGround

    li.s    $f5, 0.0              # Reset velocityY to 0.0
    s.s     $f5, velocityY

# Print Mario's current position
print_status:
    # Print Mario's X position
    la      $a0, marioPosXText     # Load "Mario X position" string
    li      $v0, 4                # Syscall to print string
    syscall

    l.s     $f12, marioPosX        # Load marioPosX into $f12 for printing
    li      $v0, 2                # Syscall to print float
    syscall

    # Print newline
    la      $a0, newline
    li      $v0, 4
    syscall

    # Print Mario's Y position
    la      $a0, marioPosYText     # Load "Mario Y position" string
    li      $v0, 4                # Syscall to print string
    syscall

    l.s     $f12, marioPosY        # Load marioPosY into $f12 for printing
    li      $v0, 2                # Syscall to print float
    syscall

    # Print newline
    la      $a0, newline
    li      $v0, 4
    syscall

    j       game_loop              # Repeat the game loop
