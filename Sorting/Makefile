
SRC		= $(wildcard *.cpp)
REG		= $(patsubst %.cpp, %.reg, $(SRC))
RST		= $(patsubst %.cpp, %.rst, $(SRC))


all:	app

app:	register $(SRC) util/inputoutput.cpp util/main.cpp
	$(CXX) -o $@ -std=c++17 $(SRC) util/inputoutput.cpp util/main.cpp

clean:
	$(RM) -rf $(APP) $(TST)

test: app $(RST)

.PHONY:		register register.rm register.add

register:	register.rm register.add

register.rm:
	rm -f util/sortfunctions.register

register.add: $(REG)

%.reg:
	echo "REGISTER_SORT_FUNCTION($*)" >> util/sortfunctions.register
	

%.rst:	%.tst
	@diffCount=`diff $< util/expected | wc -l`;		\
	if [[ $${diffCount} != 0 ]]; then				\
		echo "ERROR: $*";							\
		printf "Expected: "; cat util/expected;	\
		printf "Actual:   "; cat $<;				\
	fi

%.tst:	%.app
	./app --default --sort=$* > $@

	
