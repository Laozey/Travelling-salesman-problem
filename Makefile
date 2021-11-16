CC = gcc
EXEC = run
CFLAGS = -Wall -Wextra -Werror -Wpedantic -fanalyzer

SRC = $(wildcard bin/*.c)
OBJ = $(SRC:.c=.o)

all: $(EXEC)

%.o: %.c
	$(CC) -o $@ -c $<

$(EXEC): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

clean: 
	rm $(EXEC)
	rm bin/*.o
