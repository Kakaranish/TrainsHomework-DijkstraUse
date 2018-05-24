CPP_FLAGS=-std=c++11
RM=rm -f
OBJS=$(subst .cc,.o,$(SRCS))
SRCS=Pair.cc DataLoader.cc


all: data_loader.o
	g++ $(CPP_FLAGS) DataLoader.o Set.h main.cpp -o output.o
	./output.o


data_loader.o: Pair.h DataLoader.h DataLoader.cpp
	g++ $(CPP_FLAGS) -c Pair.h DataLoader.h DataLoader.cpp

clean:
	$(RM) *.o
	$(RM) *.h.gch