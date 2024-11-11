echo "Search File"
echo "Enter file name to be searched"
read string 
echo "Enter path"
read path
echo "Matched files"
ls $path/*$string*
