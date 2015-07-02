CC = g++ -std=c++0x -L/usr/local/lib/ -lpiface-1.0
CFLAGS = -g -c -Wall
LDFLAGS =
SOURCES = main.cpp tcpstream.cpp tcpconnector.cpp configfilemanager.cpp doormansystem.cpp pifacereader.cpp
INCLUDES = -I.
OBJECTS = $(SOURCES:.cpp=.o)
TARGET = client

all: $(SOURCES) $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $(INCLUDES) $< -o $@

clean:
	rm -rf $(OBJECTS) $(TARGET)
