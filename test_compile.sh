# Variables for common configuration
CC := gcc
CFLAGS := -Wall -O2
SRCDIR := src
BINDIR := bin

# Target-specific variables for different regions
US_VERSION := $(BINDIR)/sm64_us.z64
JP_VERSION := $(BINDIR)/sm64_jp.z64
EU_VERSION := $(BINDIR)/sm64_eu.z64

SRC := $(wildcard $(SRCDIR)/*.c)

# Default target (builds all versions)
all: us jp eu

# Build the US version
us: $(SRC)
	@mkdir -p $(BINDIR)
	$(CC) $(CFLAGS) -DREGION_US -o $(US_VERSION) $(SRC)
	@echo "US version built successfully!"

# Build the Japanese version
jp: $(SRC)
	@mkdir -p $(BINDIR)
	$(CC) $(CFLAGS) -DREGION_JP -o $(JP_VERSION) $(SRC)
	@echo "Japanese version built successfully!"

# Build the EU version
eu: $(SRC)
	@mkdir -p $(BINDIR)
	$(CC) $(CFLAGS) -DREGION_EU -o $(EU_VERSION) $(SRC)
	@echo "EU version built successfully!"

# Clean up all built files
clean:
	rm -rf $(BINDIR)
	@echo "Cleaned all built files."

# Phony targets
.PHONY: all us jp eu clean
