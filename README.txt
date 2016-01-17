README for source code distribution of examples from "Professional C++, Third
Edition" by Marc Gregoire.

Unless otherwise noted, examples adhere to the C++ standard, so they should
run with any standards-conforming compiler on any platform.

Examples have been tested with GCC 4.8 on Fedora 20, and Microsoft Visual
C++ 2013 on Windows 8.1.

Readme files in certain folders mention if an example uses a C++14 feature
not yet supported by Visual C++ or GCC.


Compiling with GCC on Linux
---------------------------

Create your source code files with any text editor you prefer and save them to
a directory. To compile your code, open a terminal and run the following
command, specifying all your .cpp files that you want to compile:

> gcc -lstdc++ -std=c++1y -o <executable_name> <source1.cpp> [source2.cpp ...]

The -std=c++1y is required to tell GCC to enable C++14 support.

For example, you can compile the AirlineTicket example from Chapter 1 by
changing to the directory containing the code and running:

> gcc –lstdc++ -std=c++1y -o AirlineTicket AirlineTicket.cpp AirlineTicketTest.cpp

When it compiles without errors you can run it as follows:

> ./AirlineTicket


Compiling with Visual Studio
----------------------------

First, you need to create a project. Start VC++ and click on File > New >
Project. In the project template tree on the left, select Visual C++ >
Win32. Then select the Win32 Console Application template in the list in
the middle of the window. At the bottom specify a name for the project, a
location where to save it, and click OK. A wizard opens. Click Next, select
Console application and Empty Project, and click Finish.

Once your new project is loaded, you can see a list of project files in the
Solution Explorer. If this docking window is not visible, go to View > Solution
Explorer. You can add new files or existing files to a project by clicking
right on the project name in the Solution Explorer and then Add > New Item
or Add > Existing Item.

Use Build > Build Solution to compile your code. When it compiles without
errors you can run it with Debug > Start Debugging.

If your program exits before you have a chance to view the output, use
Debug > Start without Debugging. It will add a pause to the end of the program
so you can view the output.
