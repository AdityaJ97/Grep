**** DSA Mini-Project ****<br>
**** GREP **** <br>
**** Aditya Jadhav ****<br>
**** 111503002 ****<br>
# Grep
<b>The Grep command in Linux.</b><br>
Usage: ./project [OPTION] PATTERN [FILE]...<br>
Search for PATTERN in each file. <br>
For help : ./project -h <br>
For standard input : ./project PATTERN <br>
For standard input with options : ./project [OPTION] PATTERN <br>
*****************************************************
The Program uses mystrtok and mystrstr functions to find the pattern and print the lines containing the pattern.
mystrtok divides the file content into single lines and seearches for the pattern.
mystrstr searches for the pattern and then prints the line if the pattern is found.
Various options implemented are shown in ./project -h. 
-r option which traverses through directories. It is implemented in dir.c. dirent.h is used to do so.
mystrstrcase function ignores case to search pattern.
