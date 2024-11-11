function_add() {
    a=$1
    b=$2
    c=$((a + b))
    return "$c"
}

# Capture the function output
function_add 3 5
b=$?
echo "The sum is ${b}"

