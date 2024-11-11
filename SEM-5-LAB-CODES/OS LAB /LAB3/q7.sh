echo "Enter the file:"
read file
echo Before Deletion
cat $file
sed -i '0~2d' $file
echo After Deletion
cat $file
