#Compiler
CC = gcc

#Compiler Flags
# -Wall and -Wextra for catching bugs
# -g for debug info
CFLAGS = -Wall -Wextra -g

#Executable Name
TARGET = my_rpg
SRCS = $(wildcard *.c)

#Converts .c list into .o list
OBJS = $(SRCS:.c=.o)

all: $(TARGET)
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)
