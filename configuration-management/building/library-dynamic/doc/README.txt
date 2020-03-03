How to create a dynamic library?
-------------------------------------------------------------------------------
First, we compile the c files into object files (*.o files). These object files
are then packaged into a dynamic library file (lib*.so file):
    
    $ gcc -std=c99 -fPIC -g -Wall -o build/linked_list_user.o -c src/linked_list_user.c
    
    $ gcc -shared -o build/liblist.so build/*.o
    
Usually, we put many *.o files into a library to be useful.
        
Second, we install the shared library to a location in the file system:

    $ mkdir libs
    $ mv build/liblist.so libs/

Before we can run an executable, we have to set the search path for
dynamic loaded libraries:

    export LD_LIBRARY_PATH=./libs:$LD_LIBRARY_PATH

The environment variable LD_LIBRARY_PATH is a colon-separated set of 
directories where libraries should be searched for first, before the 
standard set of directories; this is useful when debugging a new library 
or using a nonstandard library for special purposes.


How to use a dynamic library?
-------------------------------------------------------------------------------

    $ gcc -std=c99 -Wall -fPIC -o build/main src/main.c -I include -L./lib -llist
    
Now, we can execute our program:

    $ build/main


References
-------------------------------------------------------------------------------
http://www.tldp.org/HOWTO/Program-Library-HOWTO/shared-libraries.html


