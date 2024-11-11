echo "Enter the path to the file or the dirctory"
read path
if [ -d "$path" ]; then
	echo "This is a directory"
elif [ -f "$path" ]; then
	echo "This is a file"
else
	echo "Path doesn't exist"
fi
