# compiler:
CC = gcc

# compiler flags: 
CFLAGS  = -Wall -Wextra -Werror -Wpedantic -fanalyzer

# the build target executable:
TARGET = run

# object files to build:
SRC = $(wildcard ./bin/*c)

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET)

clean:
	rm $(TARGET)