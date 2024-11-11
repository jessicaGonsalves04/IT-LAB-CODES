# Remove OS directory and create a new one
rm -rf OS
mkdir OS
cd OS

# Create some .txt files
touch a.txt b.txt c.txt

# Navigate back to parent directory
cd ..

# Find and rename .txt files to .text
echo "Q3: Replacing .txt with .text"
result=$(find . -depth -name '*.txt')
for i in $result
do
    echo "Renaming $i"
    mv "$i" "${i%.txt}.text"
done

echo "All files renamed"

