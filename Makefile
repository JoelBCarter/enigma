CXX=g++
CXXFLAGS=-std=c++17 -Wall

all: Enigma

Enigma: main.cpp Enigma.cpp
	$(CXX) $(CXXFLAGS) -o Enigma main.cpp Enigma.cpp

clean:
	rm -f Enigma
