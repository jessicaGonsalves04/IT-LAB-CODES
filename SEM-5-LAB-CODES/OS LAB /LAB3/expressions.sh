echo "enter a"
read a 
a=`expr $a + 1`
echo "$a"
echo "enter p and q"
read p q
result=$[ $p == $q ]
echo "$result"
