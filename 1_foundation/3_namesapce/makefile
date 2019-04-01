.PHONY:clean all
CXX=g++
CPPFLAGS=-g -Wall
BIN=main
OBJS=3_namespace_1.o game1.o game2.o

$(BIN):$(OBJS)
	$(CXX) $(CPPFLAGS) $(OBJS) -o $@
%.o:%.cpp
	$(CXX) $(CPPFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) 
