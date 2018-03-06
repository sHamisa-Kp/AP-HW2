CXX = g++
CXXFLAGS = -std=c++14 -Wall -c
LXXFLAGS = -std=c++14
OBJECTS = Q4.o
TARGET = Q4


$(TARGET): $(OBJECTS)
	$(CXX) $(LXXFLAGS) $(OBJECTS) -o $(TARGET)
Q4.o: Q4.cpp
	$(CXX) $(CXXFLAGS) Q4.cpp
clean:
	rm -f $(TARGET) $(OBJECTS)
