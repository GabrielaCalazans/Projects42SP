# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    gabtests.sh                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gacalaza <gacalaza@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/04 14:10:56 by gacalaza          #+#    #+#              #
#    Updated: 2023/08/04 14:23:20 by gacalaza         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/bin/bash

echo "100:"
ARG=$(seq -50 49 | shuf); echo $ARG > test100.txt | ./push_swap $ARG | wc -l

echo "200:"
ARG=$(seq -100 99 | shuf); echo $ARG > test200.txt | ./push_swap $ARG | wc -l

echo "500:"
ARG=$(seq -250 249 | shuf); echo $ARG > test500.txt | ./push_swap $ARG | wc -l
