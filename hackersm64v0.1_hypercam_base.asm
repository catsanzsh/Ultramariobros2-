.data
    # Light source position
    light_pos: .word 10, 10, 10  # Example light position
    
    # Vertex data (position and normal)
    vertex_pos: .word 0, 0, 0    # Example vertex position
    vertex_normal: .word 0, 1, 0  # Example normal vector

    # Material properties
    ambient: .word 0x00FF00FF     # Ambient color
    diffuse: .word 0x00FFFF00     # Diffuse color
    specular: .word 0x00FFFFFF     # Specular color
    shininess: .word 16            # Shininess factor

.text
.globl calculate_lighting

# Function to calculate lighting
calculate_lighting:
    # Load vertex and light positions
    la $t0, vertex_pos       # Load vertex position address
    la $t1, light_pos        # Load light position address

    lw $t2, 0($t0)           # Load vertex_x
    lw $t3, 4($t0)           # Load vertex_y
    lw $t4, 8($t0)           # Load vertex_z

    lw $t5, 0($t1)           # Load light_x
    lw $t6, 4($t1)           # Load light_y
    lw $t7, 8($t1)           # Load light_z

    # Calculate light direction vector
    subu $t8, $t5, $t2       # light_x - vertex_x
    subu $t9, $t6, $t3       # light_y - vertex_y
    subu $s0, $t7, $t4       # light_z - vertex_z

    # Normalize light direction (simplified, no square root)
    mul $s1, $t8, $t8        # light_x^2
    mul $s2, $t9, $t9        # light_y^2
    mul $s3, $s0, $s0        # light_z^2
    addu $s4, $s1, $s2       # light_x^2 + light_y^2
    addu $s4, $s4, $s3       # light_x^2 + light_y^2 + light_z^2
    # Square root would be needed for normalization, omitted for simplicity

    # Calculate diffuse lighting (dot product)
    la $t0, vertex_normal    # Load vertex normal address
    lw $s5, 0($t0)           # Load normal_x
    lw $s6, 4($t0)           # Load normal_y
    lw $s7, 8($t0)           # Load normal_z

    mul $s8, $t8, $s5        # light_x * normal_x
    mul $s9, $t9, $s6        # light_y * normal_y
    mul $t0, $s0, $s7        # light_z * normal_z
    addu $s8, $s8, $s9       # dot product
    addu $s8, $s8, $t0

    # Apply ambient light (simplified)
    la $t1, ambient           # Load ambient color
    lw $s9, 0($t1)

    # Apply diffuse light (simplified)
    la $t1, diffuse           # Load diffuse color
    lw $t0, 0($t1)

    # Apply specular light (simplified)
    la $t1, specular          # Load specular color
    lw $t2, 0($t1)
    la $t3, shininess         # Load shininess factor
    lw $t3, 0($t3)

    # Final color calculation (simplified)
    addu $s9, $s9, $s8        # ambient + diffuse
    addu $s9, $s9, $t2        # + specular

    # Store result (this is just an example; actual storage may differ)
    la $t0, result_color      # Result color address
    sw $s9, 0($t0)

    # Return from function
    jr $ra
