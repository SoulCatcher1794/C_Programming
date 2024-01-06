echo $0 #shows current interpreter
uname #shows operating system
history #shows history of commands
uptime #shows time since booting
date #show current date
top #shows current processes running, to get out press either q or ctrl+c
file #shows file type
which #shows where each cmd is located at in the file system
realpath #shows absolute path of a file origin
touch #creates new files if it doesn't already exist
cat #show content of file
echo "Hello World" > file.txt #this will use the output of the echo command and will save it into file.txt
less #used to open long files with useful commands
| #this is used for piping, sending the output of a command as the input of another command
rm #removes files, user argument -r for recurrent removal for directories
rm -ri #this commands deletes all files recursively but ask before deleting each file it finds
mkdir -p #lets you create folders inside folders such as /d1/d2/d3...
mv #this command moves a file, you can use it to move files, rename them or both at same time
cp #this copies a files, use -r to copy folders

#ways to unblock yourself in command promt:
#ctrl + d (sometimes twice)
#ctrl + c or letter 'q'
htop #this can be used to select the process you want to kill from the list, you will need another terminal

updatedb #updates database
located #command used to find
echo * #we can use the wildcard * to find everything or ? to autocomplete several characters
find #use to find directories or files in the file system
find . -name "filename" # used to find in the current directory the file with name: filename
find / -name "hello" 2 > /dev/null #sending 2nd return parameter of the command into null (nowhere)


