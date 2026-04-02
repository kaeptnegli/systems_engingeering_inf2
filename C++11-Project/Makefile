CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra -pedantic

TARGET = lab
SOURCES = Area.cpp CanvasTerminal.cpp Direction.cpp Hoover.cpp Input.cpp Position.cpp Random.cpp State.cpp StrategyRandomAngle.cpp StrategyUpDown.cpp Timing.cpp Utilities.cpp main.cpp
OBJECTS = $(SOURCES:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS) $(TARGET)
