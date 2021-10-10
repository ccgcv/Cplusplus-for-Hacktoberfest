
SRC		= $(wildcard *.cpp)
APP		= $(patsubst %.cpp, %.app, $(SRC))
RST		= $(patsubst %.cpp, %.rst, $(SRC))

TARGET	= $(APP)

all: $(TARGET)

%.app:	%.cpp util/inputoutput.cpp
	$(CXX) -o $@ -std=c++17 $^

clean:
	$(RM) -rf $(APP) $(TST)

test: $(APP) $(RST)

%.rst:	%.tst
	@diffCount=`diff $< util/expected | wc -l`;		\
	if [[ $${diffCount} != 0 ]]; then				\
		echo "ERROR: $*";							\
		printf "Expected: "; cat util/expected;	\
		printf "Actual:   "; cat $<;				\
	fi

%.tst:	%.app
	./$< --default > $@

	
