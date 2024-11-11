echo $0
echo $1
echo $2
echo $#
echo $*
echo $$
echo $@
for i in "$@";do
 echo $i #loop $#times
done
for i in "$*";do
 echo $i #loop 1 times
done

