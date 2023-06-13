ARG=$(seq 2000 | shuf -n 50); ./push_swap $ARG


ARG=$(seq 2000 | shuf -n 100); ./insertion_sort $ARG

ARG=$(seq 2000 | shuf -n 1000); ./insertion_sort $ARG