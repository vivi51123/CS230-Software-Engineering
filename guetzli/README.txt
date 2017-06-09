Installing Guetzli

Install dependancies:
$ sudo apt-get install libpng-dev.
$ sudo apt-get install libimage-exiftool-perl libjpeg-progs dcraw
$ sudo apt-get install netpbm

Get the git:
$ git clone https://github.com/google/guetzli.git

Passive injection. (One would normally just run make at this point but we want memory leaks)
Find the guetzli.cc source file
$ cd guetzli/guetzli 

Use your favorite text editor to open guetzli.cc
$ nano guetzli.cc 

Comment out the 4 instances of “png_destroy_read_struct” on lines 57, 63, 147 and 150

Run make and expect the binary to be created in bin/Release/guetzli.:
$ /root/guetzli
$ make

It should be ready to run at this point. To do a quick test:
$ cd /root/guetzli/bin/Release
$ guetzli -h 

You should get the help menu (its not a complete tests but if it doesn’t work you definitely did something wrong)

Now run the valgrind test
valgrind --leak-check=full --show-leak-kinds=all --leak-check-heuristics=all --time-stamp=yes ./guetzli --verbose ../../tests/bees.png ../../tests/bees2.png
