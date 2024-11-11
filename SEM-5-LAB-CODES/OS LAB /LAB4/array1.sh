arr=(a b c d)
echo ${arr[2]}
echo ${arr[@]}
read -a inputArrayOfNumbers
echo -n "Entered Input is :"
for i in ${inputArrayOfNumbers[@]};do
echo -n "${i} " 
done
