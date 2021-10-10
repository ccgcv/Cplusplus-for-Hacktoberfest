
HEAD	= $(wildcard *.h)
REG		= $(patsubst %.h, %.reg, $(HEAD))
RST		= $(patsubst %.h, %.rst, $(HEAD))

.INTERMEDIATE:		register


all:	app

app:	register util/inputoutput.cpp util/main.cpp
	$(CXX) -o $@ -std=c++17 util/inputoutput.cpp util/main.cpp

clean:
	$(RM) -rf $(APP) $(TST)

test: app $(RST)

register:	util/sortfunctions.register

util/sortfunctions.register:	$(HEAD)
	@echo "Registering Sort Functions"
	@rm -f util/sortfunctions.register
	@rm -f util/sortfunctions.allheaders.h
	@make $(REG)

%.reg:
	@echo "		Register: $*"
	@echo 'REGISTER_SORT_FUNCTION($*)' >> util/sortfunctions.register
	@echo '#include "../$*.h"'         >> util/sortfunctions.allheaders.h

%.rst:	%.tst
	@diffCount=`diff $< util/expected | wc -l`;		\
	if [[ $${diffCount} != 0 ]]; then				\
		echo "ERROR: $*";							\
		printf "Expected: "; cat util/expected;	\
		printf "Actual:   "; cat $<;				\
	fi

%.tst:	app
	./app --default --sort=$* > $@

	
