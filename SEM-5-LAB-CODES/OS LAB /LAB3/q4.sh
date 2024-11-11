echo "Enter the Basics value:"
read basics
echo "Enter the TA value:"
read TA
GS=$(echo "$basics+$TA+$basics*0.1" | bc -l)
echo "GS value  is: $GS"
