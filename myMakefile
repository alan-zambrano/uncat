CC       = g++
CFLAGS   = -Wall -g
OBJFILES = uncat.o tree.o node.o
TARGET   = uncat

all: $(TARGET)

$(TARGET): $(OBJFILES)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJFILES)

clean:
	rm -f $(OBJFILES) $(TARGET)
