README

Dear user please read the following instructions to see where each project is stored and 
how to build the programs

This folder contains:

2 CLion projects called:
Membership_Program
Race_Results_Program

1 other folder:
data-set-one //contians the files members.txt, handicap.txt and race.txt

1 word document (justifies file structures and explains mistakes made),
one screencast (shows how to run the code) and this file README
---------------------------------------------------------
Membership_Program
This folder contains the following files:
main.c //this is the main C file where you run the program from
membership.c
membership.h
print.c
search_members.c
CMakeLists
.idea //may not be visible on your OS by default
cmake-build-debug 
members //DO NOT DELETE THIS FOLDER as it contains the file members.txt which is
used to parse in data for the members list

This uses the most up-to-date version of the standard C libraries

----------------------------------------------------------
Race_Results_Program
This folder contains the following files:
main.c //this is the main C file where you run the program from
handicap.c
members.c
race_results.c
race_results.h
.idea //may not be visible on youe OS by default
cmake-build-debug 
files //DO NOT DELETE THIS FOLDER as it contains the files members.txt,
handicap.txt and race.txt

This uses the most up-to-date version of the standard C libraries

--------------------------------------------------------
To open these projects please open CLion and navigate to File -> open... and find the 
folder directory. Then press Build -> Clean and then Run -> Run'program-name' 