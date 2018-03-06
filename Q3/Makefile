CXX = g++
CXXFLAGS = -std=c++14 -Wall -c
LXXFLAGS = -std=c++14
OBJECTS = Q3.o Queue.o
TARGET = Q3


$(TARGET): $(OBJECTS)
	$(CXX) $(LXXFLAGS) $(OBJECTS) -o $(TARGET)
Q3.o: Q3.cpp Queue.h
	$(CXX) $(CXXFLAGS) Q3.cpp 
Queue.o: Queue.cpp
	$(CXX) $(CXXFLAGS) Queue.cpp
clean:
	rm -f $(TARGET) $(OBJECTS)
