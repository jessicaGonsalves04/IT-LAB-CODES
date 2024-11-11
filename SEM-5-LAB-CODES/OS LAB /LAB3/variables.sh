#!/bin/sh

var="I am global"

showvar() {
    local local="I am local"
    echo "$var"
    echo "$local"
}

showvar
echo "$var"
# echo "$local" # This line would be commented out or removed, as $local is not accessible here

