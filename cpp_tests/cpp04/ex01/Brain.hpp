/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 17:38:01 by gacalaza          #+#    #+#             */
/*   Updated: 2024/08/30 17:38:53 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <iostream>
#include <string>

class	Brain
{
	private:
		std::string	_ideas[100];

	public:
		Brain(void);
		Brain(const Brain &obj);
		Brain& operator=(const Brain &obj);
		virtual ~Brain(void);

		std::string	getIdea(int index) const;
		void		setIdea(int index, std::string idea);
};

#endif
