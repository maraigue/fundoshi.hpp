GCCFLAGS = -Wall -I.
#GCCFLAGS = -Wall -Wsign-conversion -I.
.SUFFIXES: .bin $(SUFFIXES)

default:
	# Usage:
	# $ sample    # run the sample
	# $ test      # run the unit tests (Boost required)
	# 
	# Note:
	# 'Boost' is a C++ library contains many features.
	# See http://www.boost.org/ for details

sample: sample.bin
	chmod u+x $<
	./$<

test: fundoshi_test

fundoshi_test: fundoshi_test.bin
	chmod u+x $<
	./$<

fundoshi_test.bin: fundoshi_test.o
	$(CXX) $(GCCFLAGS) $< -o $@

sample.bin: sample.o
	$(CXX) $(GCCFLAGS) $< -o $@

.cpp.o:
	$(CXX) $(GCCFLAGS) -c $< -o $@

sample.o: fundoshi.hpp
fundoshi_test.o: fundoshi.hpp

clean:
	rm -f *.o *.bin
