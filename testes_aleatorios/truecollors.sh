#!/bin/bash
if (( $(tput colors 2>/dev/null) > 256 )); then
    echo "What a beautiful rainbow!!!"
else
    echo "Back to the 80's VGA era anyone?"
fi

printf "\x1b[${bg};2;${red};${green};${blue}m\n"
