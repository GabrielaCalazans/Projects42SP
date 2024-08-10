/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 22:56:59 by gacalaza          #+#    #+#             */
/*   Updated: 2024/08/10 13:34:30 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <string>

Zombie*	zombieHorde(int N, std::string name)
{
	if (N < 1)
		return NULL;

	Zombie* horde = new Zombie[N];

	for (int i = 0; i < N; i++) {
		horde[i].setName(name);
	}

	return horde;
}
