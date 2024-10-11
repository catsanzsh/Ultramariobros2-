# Compiler
CC = gcc

# Compiler flags
CFLAGS = -std=c++17 -Iinclude

# Source files
SRCS = src/60fps.asm \
       src/b3313_2.0_lightning.c \
       src/b3313_render_ft.c \
       src/compilev0.c \
       src/file_menu.c \
       src/hackersm64v0.1_hypercam_base.asm \
       src/mermaid-testnpc.c \
       src/program.c \
       src/texture.cpp \
       src/texture_api.cpp

# Object files
OBJS = $(SRCS:.c=.o)

# Executable name
EXEC = UltraMarioBros2

# Default target
all: $(EXEC)

# Link object files to create executable
$(EXEC): $(OBJS)
	$(CC) $(OBJS) -o $(EXEC)

# Compile source files into object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean up build files
clean:
	rm -f $(OBJS) $(EXEC)

# Phony targets
.PHONY: all clean
