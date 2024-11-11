echo "Q5: Move files to a given directory"
echo "Enter the file extension to be moved:"
read extension
echo "Enter the folder where the files will be moved to:"
read folder

# Find files with the specified extension
result=$(find ./ -maxdepth 1 -type f -name "*.$extension")

# Create the target directory if it does not exist
mkdir -p "$folder"

# Move each file to the target directory
for i in $result
do
    mv "$i" "$folder"
done

echo "All files moved"

