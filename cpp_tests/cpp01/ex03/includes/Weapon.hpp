/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 17:56:16 by gacalaza          #+#    #+#             */
/*   Updated: 2024/08/23 18:02:23 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <string>


class Weapon {
private:
	std::string	_type;

public:
	Weapon(void);
	Weapon(std::string name);
	~Weapon();

	std::string	getType(void) const;
	void		setType(std::string type);
};


#endif