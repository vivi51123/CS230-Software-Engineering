CXX = g++ -std=c++11
CXXFLAGS = -g -Wall
#OBJS = leak1.o leak2.o leak3.o leak4.o leak5.o
#PROG = scc
RUNFLAG = valgrind --leak-check=full --show-leak-kinds=all --leak-check-heuristics=all


all: leak1 leak2 leak3 leak4 leak5 leak6 leak7 leak8 leak9 leak10 leak11_6 leak12_7 leak13_8 leak14_9

run: run1 run2 run3 run4 run5 run6 run7 run8 run9 run10 run11_6 run12_7 run13_8 run14_9

new: leak1 leak2 leak5 leak9 leak10 leak11_6 leak12_7 leak13_8 leak14_9

runnew: run1 run2 run5 run9 run10 run11_6 run12_7 run13_8 run14_9

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

leak6:
	$(CXX) $(CXXFLAGS) -o leak6 leak6.cpp

leak7:
	$(CXX)  $(CXXFLAGS) -o leak7 leak7.cpp

leak8:
	$(CXX)  $(CXXFLAGS) -o leak8 leak8.cpp

leak9:
	$(CXX)  $(CXXFLAGS) -o leak9 leak9.cpp

leak10:
	$(CXX)  $(CXXFLAGS) -o leak10 leak10.cpp

leak11_6:
	$(CXX)  $(CXXFLAGS) -o leak11_6 leak11_6.cpp

leak12_7:
	$(CXX)  $(CXXFLAGS) -o leak12_7 leak12_7.cpp

leak13_8:
	$(CXX)  $(CXXFLAGS) -o leak13_8 leak13_8.cpp

leak14_9:
	$(CXX)  $(CXXFLAGS) -o leak14_9 leak14_9.cpp

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

run6:
	$(RUNFLAG) ./leak6

run7:
	$(RUNFLAG) ./leak7

run8:
	$(RUNFLAG) ./leak8

run9:
	$(RUNFLAG) ./leak9

run10:
	$(RUNFLAG) ./leak10

run11_6:
	$(RUNFLAG) ./leak11_6

run12_7:
	$(RUNFLAG) ./leak12_7

run13_8:
	$(RUNFLAG) ./leak13_8

run14_9:
	$(RUNFLAG) ./leak14_9
#break:
#	@echo "";

clean:; $(RM) leak1 leak2 leak3 leak4 leak5 leak6 leak7 leak8 leak9 leak10 leak11_6 leak12_7 leak13_8 leak14_9
