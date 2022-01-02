CC = gcc
EXEC = run
CFLAGS = -Wall -Wextra -Werror -Wpedantic -fanalyzer

SRC = $(wildcard bin/*.c)
OBJ = $(SRC:.c=.o)

all: $(EXEC)

%.o: %.c
	$(CC) -o $@ -c $< -g

$(EXEC): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^ -lm

clean: 
	rm bin/*.o
	rm $(EXEC)
