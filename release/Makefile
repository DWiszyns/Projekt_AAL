CXX ?=g++
OBJS1 =main.o


all: Projekt_AAL

Projekt_AAL: $(OBJS1)
	$(CXX) -o Projekt_AAL $(CFLAGS) $(OBJS1) 

$(OBJS1) : %.o : %.cpp 
	$(CXX) -c $(CFLAGS) $< -o $@


clean:
	rm -f Projekt_AAL *.o

