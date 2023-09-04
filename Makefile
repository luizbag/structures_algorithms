# Declaration of variables
CC = gcc
CC_FLAGS = -w -Werror -Wall

# File names
# "program" will be the name of the output produced from the make process
EXEC = program
#Incorporates all the files with .c extension
SOURCES = $(wildcard *.c)
OBJECTS = $(SOURCES:.c=.o)

# Main target
$(EXEC): $(OBJECTS)
	$(CC) $(OBJECTS) -o $(EXEC)

# To obtain object files
%.o: %.c
	$(CC) -c $(CC_FLAGS) $< -o $@

# To remove generated files
clean:
	rm -f $(EXEC) $(OBJECTS)
