# configuration for Number Conversion System (NCS)

CC = gcc
CFLAGS = -std=c99 -Wall -Wextra -O2

TARGET = ncs_app

# Source modules
SRCS = main.c convert.c io_helper.c
OBJS = $(SRCS:.c=.o)

.PHONY: all clean debug reset

# Default build
all: $(TARGET)

# Link final program
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(TARGET)

# Compile each C file
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Debug mode
debug: CFLAGS = -std=c99 -Wall -Wextra -g -O0
debug: clean $(TARGET)

# Clean build files
clean:
	rm -f $(OBJS) $(TARGET)

# Fresh build
reset: clean all
