CC = g++
CFLAGS = $(shell xml2-config --cflags)
LIBS = $(shell xml2-config --libs)

XMLParser: main.cpp
	$(CC) -o XMLParser main.cpp $(CFLAGS) $(LIBS)

clean:
	rm -f XMLParser
