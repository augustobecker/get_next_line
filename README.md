<h1 align="center"> get_next_line - @42sp </h1>

<p align="center">:information_source: A C function that reads any valid file line by line until the end </p>

<p align="center"><a href="https://www.42sp.org.br/" target="_blank"><img src="https://img.shields.io/static/v1?label=&message=SP&color=000&style=for-the-badge&logo=42""></a></p>
<p align="center"><img src="https://user-images.githubusercontent.com/81205527/149212588-45d60d10-2e78-46c5-bf0c-0dc247464ad5.png"></p>
<p align="center"> <strong>104/100</strong> ✔️ </p>
<p align="center"><a href="https://github.com/augustobecker/get_next_line/blob/main/README-ptbr.md" target="_blank"><img src="https://img.shields.io/badge/dispon%C3%ADvel%20tamb%C3%A9m%20em-PT--BR-yellow"></a></p>

## Index

* [What is get-next-line?](#what-is-get-next-line)
* [Requirements](#requirements)
* [How does it work?](#how-does-it-work)
* [How do I use the function?](#how-do-i-use-the-function)
* [How do I test it?](#how-do-i-test-it)
* [Author](#author)

<h2 align="center" id="what-is-get-next-line"> What is get-next-line? </h2>

It's the second project at 42. A function, in C, that returns a line, read from a file descriptor. In short, it can read any valid file and does that line by line to optimize memory, since the file size is not known. It's an extremely useful function that can be used in the next school's projects.

<h2 align="center" id="requirements"> Requirements </h2>

<p  align="center"> :warning: The project must be written in accordance with the <a href="https://github.com/42School/norminette/blob/master/pdf/en.norm.pdf" target="_blank">Norm</a> </p>
The Norm  is a programming standard that defines a set of rules to follow when writing code at 42. It applies to all C projects within the Common Core by default, and
to any project where it's specified. These are some of them:

    Each function must be maximum 25 lines, not counting the function's own curly brackets.
    
    Each line must be at most 80 columns wide, comments included.
    
    A function can take 4 named parameters maximum.
    
    You can't declare more than 5 variables per function.
    
    You're not allowed to use: for , do...while , switch , case ,  goto  ,
    ternary operators such as `?' and VLAs - Variable Length Arrays.
  The norminette (as we call the norm at 42) is in python and open source.
  
  Its repository is available at https://github.com/42School/norminette.
  
  In addition to the Norm, the subject have other requirements, which are:
  
    It is forbidden to declare global variables.
   
    Your read must use the BUFFER_SIZE defined during compilation to read from
    a file or from stdin. This value will be modified during the evaluation for testing
    purposes.
    
    The program will be compiled in this way:
    gcc -Wall -Wextra -Werror -D BUFFER_SIZE=42 <files>.c.
    
    libft is not allowed for this project. You must add a get_next_line_utils.c file
    which will contain the functions that are needed for your get_next_line to work

<h2 align="center" id="how-does-it-work"> How does it work? </h2>

<p align="center">✨ For this project we were introduced to the concept of static variables ✨</p>

<p align="center">ℹ️ A static variable is allocated "statically", which means its lifetime is the entire execution of the program.</p>

The line is, by definition, a string ending in "\n" (line break) or "EOF" (to the end of the file) and which, according to the subject, must be read in a buffer of a size defined in the compilation. get_next_line runs the read function and stores what was read during the call, only then it looks for a "\n" - when it finds it we know we've reached the end of the line, if it doesn't find the "\n" but read returns 0 we know that there is nothing ahead to be read (EOF), in other cases, we simply do not reach the end of the line, what was read is stored in the line that will be returned and we continue reading the file. Most of the time, the buffer does not match the exact size of the line, and it is also not possible to read the same stretch of the line two times, which creates one of the biggest problems in the development of get_next_line:
What happens in those cases where, for example, the BUFFER_SIZE is 10 and the line ends at the 6th character?
The 4 characters remaining after the line break would be lost and reading would continue into the next 10 character buffer. To solve this, we use the static variable as a backup, to store those leftover characters. And when the function is called again, one of the first things done is to check if there is anything in the backup and if there is, start the new line from there. In general this is how it works, other details of how it works are more technical and I thought it best to leave them out of this explanation, but you can check it out by checking the <a href="https://github.com/augustobecker/get_next_line/blob/main/get_next_line.c">function</a>.
<h2 align="center" id="how-do-i-use-the-function"> How do I use the function? </h2>

It aims to create a library called libgetnextline.a from the source files.
To create this library, clone the project:

    git clone https://github.com/augustobecker/get_next_line get_next_line
Enter the repository:

    cd get_next_line

Run these commands to compile the source code to object files:
    
    clang -Wall -Werror -Wextra -c get_next_line.c -o get_next_line.o 
    clang -Wall -Werror -Wextra -c get_next_line_utils.c -o get_next_line_utils.o 

And then creating the library libgetnextline.a:
    
    ar -rcs libgetnextline.a get_next_line.o get_next_line_utils.o 

You should see a libftprintf.a file and some object files (.o).

Now to clean up (removing the .o files), run this command:

    rm -f get_next_line.o get_next_line_utils.o 
Now you just have to add this header at your .c files and use the ft_printf function or any other from the library:

	#include "get_next_line.h"
	
If you try to compile your .c files with clang using "clang example.c" you will get an undefined symbol error for libgetnextline functions.

You have to tell the file which library it's using:

	clang example.c libgetnextline.a
	
That's it. Now run it using ./a.out

<h2 align="center" id="how-do-i-test-it"> How do I test it? </h2>

To test the code we're going to be using @jgambard's gnlTester. There are some good others but I'll only be covering this one.

To test the code in this repo
Clone this repo and cd into it:

    git clone https://github.com/augustobecker/get_next_line get_next_line
     
	cd get_next_line/	
 
Now, clone @jgambard's gnlTester
    
    https://github.com/Tripouille/gnlTester Tester_get_next_line
Go into the test folder and run the mandatory test:

    cd Tester_get_next_line
    make m
    
If you did everything correctly you should see something like this:
![68747470733a2f2f692e696d6775722e636f6d2f75344c6936414d2e706e67](https://user-images.githubusercontent.com/81205527/158914684-a53f2bf1-7a7a-4155-944f-7863ddb09855.png)

    
<h2 align="center" id="author"> Author </h2>

<div>
<img height="180em" src="https://user-images.githubusercontent.com/81205527/152089472-0aa06bd9-d882-4c83-adfc-8230d1e958c1.png">
    
<strong> Augusto Becker | acesar-l | 🇧🇷👨‍🚀</strong>
    
:wave: How to reach me: 
    
  <a href="https://www.linkedin.com/in/augusto-becker/" target="_blank"><img align="center" alt="LinkedIn" height="60" src="https://user-images.githubusercontent.com/81205527/157161849-01a9df02-bf32-45be-add4-122bc40b48cf.png"></a>
<a href="https://www.instagram.com/augusto.becker/" target="_blank"><img align="center" alt="Instagram" height="60" src="https://user-images.githubusercontent.com/81205527/157161841-19ec3ab2-2c8f-4ec0-8b9d-3cd885256098.png"></a>
<a href = "mailto:augustobecker.dev@gmail.com"> <img align="center" alt="Gmail - augustobecker.dev@gmail.com" height="60" src="https://user-images.githubusercontent.com/81205527/157161831-eb9dffee-404b-4ffe-b0af-34671219f7fb.png"></a>
<a href="https://discord.gg/3kxYkBRxUy" target="_blank"><img align="center" alt="Discord - beckerzz#3614" height="60" src="https://user-images.githubusercontent.com/81205527/157161820-de88dc63-61a3-4c9f-9445-07ac98bf0bc2.png"></a>
</div>
