CXX = g++
CXXFLAGS = -g -Wall
#OBJS = leak1.o leak2.o leak3.o leak4.o leak5.o
#PROG = scc
RUNFLAG = valgrind --leak-check=full


all: leak1 leak2 leak3 leak4 leak5

run: run1 run2 run3 run4 run5


#$(PROG): $(OBJS)
#$(CXX) -o ($PROG) $(OBJS)

leak1:
	$(CXX) $(CXXFLAGS) -o leak1 leak1.cpp

leak2:
	$(CXX) $(CXXFLAGS) -o leak2 leak2.cpp

leak3:
	$(CXX)  $(CXXFLAGS) -o leak3 leak3.cpp

leak4:
	$(CXX)  $(CXXFLAGS) -o leak4 leak4.cpp

leak5:
	$(CXX)  $(CXXFLAGS) -o leak5 leak5.cpp

run1:
	$(RUNFLAG) ./leak1

run2:
	$(RUNFLAG) ./leak2

run3:
	$(RUNFLAG) ./leak3

run4:
	$(RUNFLAG) ./leak4

run5:
	$(RUNFLAG) ./leak5

#break:
#	@echo "";

cleanall:; $(RM)  leak1 leak2 leak3 leak4 leak5
