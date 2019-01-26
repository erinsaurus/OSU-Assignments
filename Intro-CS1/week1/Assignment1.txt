In this assignment you'll get some practice with some of the tools we'll be using throughout the course.  These instructions will assume that you have followed the tutorials in the "Tools You Will Need" page.
Use a terminal emulator to log into the school server (flip).  Type ls to list the contents of the directory you're in.  Type ls -l for more information about each file.  Create a new directory called "week1" by typing mkdir week1.  Go into that directory by typing cd week1 (you can get back out of it by typing cd .. which moves you up one level from your current directory).  Use vim (or emacs or nano) to make a file named animal.cpp.  Type the following code into the file:
#include <iostream>
#include <string>


// a simple example program
int main()
{
        std::string faveAnimal;
        std::cout << "Please enter your favorite animal." << std::endl;
        std::cin >> faveAnimal;
        std::cout << "Your favorite animal is the " << faveAnimal;
        std::cout << "." << std::endl;    
    
        return 0;
}
Add a comment block at the top as discussed in the Code Style Guidelines.  Now save the file.  Type ls to verify that this directory now contains a file named animal.cpp.  Next type g++ animal.cpp -o animal.  This will compile your source file and create an executable file named "animal".  The -o flag lets you choose a name for the executable file.  If you instead just type g++ animal.cpp, the name of the executable file will be "a.out".  It is important that you do not accidentally give your executable file the same name as the source file.  If you do that, then your executable file will replace your source file and your source file will be gone (and you will be sad).  Now type in ./animal.  The program should now ask you to enter the name of your favorite animal, and after you do, it will print out "Your favorite animal is the <whatever you typed>."  Notice that this program only reads the first word of the input, so if the animal name contains any spaces, the full name won't be printed out.
Once you have verified that your program compiles and runs correctly, you need to transfer your source file, "animal.cpp", from the school server to your home computer using FileZilla (or scp).
Now open up the TEACH website, find submission "week1" for your section of the course, and submit your source file there.
Lastly, create a pdf document that gives the following 4 pieces of information: your name, your onid username, your TA's name and your TA's email address.  Submit your pdf here in Canvas by clicking the "Submit Assignment" link and selecting it for upload.