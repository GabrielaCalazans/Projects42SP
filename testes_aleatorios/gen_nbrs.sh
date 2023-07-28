ARG=$(seq 2000 | shuf -n 50); ./push_swap $ARG


ARG=$(seq 2000 | shuf -n 100); ./insertion_sort $ARG

ARG=$(seq 2000 | shuf -n 1000); ./insertion_sort $ARG

ARG=$(seq -50 49 | shuf); ./push_swap $ARG | ./checker_linux

ARG=$(seq -100 99 | shuf); ./push_swap $ARG