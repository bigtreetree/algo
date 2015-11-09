test_pai:test_pai.o
	rm -rf $@
	g++ -g -o $@ $^
	rm -rf $^
test_pai.o:test_pai.cpp
	g++ -g -c $^
btree:btree.o
	rm -rf $@
	g++ -g -o $@ $^
	rm -rf $^
btree.o:btree.cpp
	g++ -g -c $^
test_binary_tree:test_binary_tree.o
	rm -rf $@
	g++ -g -o $@ $^
	rm -rf $^
test_binary_tree.o:test_binary_tree.cpp
	g++ -g -c $^
binary_tree.o:binary_tree.cpp
	g++ -g -c $^
clean:
	rm -rf *.o
