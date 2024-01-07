gcc -Wall -Weror -v -L'location' -l'library' -o exec_name file.c
# -o specifies the name of the executable
# -Wall prints all warnings
# -Werror converts warnings into errors
# -v provides a verbose output from gcc
# -l'library' links shared library, for example shared library pthread would be '-lpthread'
# -L'location gives the location of the library file

gcc -E file.c > precompiled.i
# -E redirects the output (preprocessed only) into prerpocessed code file

gcc -S file.c > assembled.s
# -S redirects the output (preprocessed and assembled) into an assembly file

gcc -C file.c -o compiled
# -C created a compiled file (unlinked) from a source file

gcc -o program file1.c file2.c
# links those 2 files into a single executable

gcc -o program -L. -llibrary_name file.c
# creates an exectutable from code file file.c and links an static library (already compiled) 
# named library_name in location .(current directory)

ar rcs library.a binary_1.o binary_2.o
#creates a static library filed from object file(s)

