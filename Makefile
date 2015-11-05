test_pai:test_pai.o
	rm -rf $@
	g++ -g -o $@ $^
	rm -rf $^
test_pai.o:test_pai.cpp
	g++ -g -c $^
clean:
	rm -rf *.o
