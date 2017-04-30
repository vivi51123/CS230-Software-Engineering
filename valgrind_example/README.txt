# Installing Valgrind and Running the test program "memLeak.cpp"

Run the following:
MAC
1.) brew install valgrind
2.) g++ -g -Wall -o memLeak memLeak.cpp
3.) valgrind --leak-check=yes ./memLeak

Ubuntu
1.) sudo apt-get install valgrind
2.) g++ -g -Wall -o memLeak memLeak.cpp
3.) valgrind --leak-check=yes ./memLeak

You can comment out line 40 in memLeak.cpp, recompile and run Step 3 to see the different valgrind output.  Commenting out line 40 will cause valgrind to report a mem leak
