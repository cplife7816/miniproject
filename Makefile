CC = gcc
CFLAGS = -W 
TARGET = product
DTARGET = product_debug
OBJECTS = main.c product.o manager.o
DOBJECTS = main.c product.c manager.c
all : $(TARGET)
$(TARGET) : $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^

$(DTARGET) : $(DOBJECTS)
	$(CC) $(CFLAGS) -DDEBUG -o $@ $^

clean :
	rm *.o 
	rm product product_debug 
