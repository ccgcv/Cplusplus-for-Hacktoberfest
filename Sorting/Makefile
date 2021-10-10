
SRC		= $(wildcard *.cpp)
APP		= $(patsubst %.cpp, %.app, $(SRC))
TST		= $(patsubst %.cpp, %.tst, $(SRC))

TARGET	= $(APP)

all: $(TARGET)

%.app:	%.cpp util/inputoutput.cpp
	$(CXX) -o $@ -std=c++17 $^

clean:
	$(RM) -rf $(APP) $(TST)

test: $(TST)

%.tst:	%.app
	./$< --default > $@

	
