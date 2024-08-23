CC = gcc
OBJS = main.o batalha_navel.o
TARGET = app.out

all: $(TARGET)
	echo "Done."

$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $(TARGET)

%.o: %.c
	$(CC) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)