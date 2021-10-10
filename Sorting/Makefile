
SRC		= $(wildcard *.cpp)
APP		= $(patsubst %.cpp, %.app, $(SRC))

TARGET	= $(APP)

all: $(TARGET)

%.app:	%.cpp util/inputoutput.cpp
	$(CXX) -o $@ -std=c++17 $?
