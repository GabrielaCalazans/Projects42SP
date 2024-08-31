/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 21:51:05 by gacalaza          #+#    #+#             */
/*   Updated: 2024/08/31 13:52:12 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main(void) {
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	

	std::cout << "--------------" << std::endl;
	std::cout << meta->getType() << std::endl;
	std::cout << j->getType() << std::endl;
	std::cout << i->getType() << std::endl;
	meta->makeSound();
	i->makeSound(); //will output the cat sound!
	j->makeSound();

	std::cout << "--------------" << std::endl;
	std::cout << "*** WrongAnimal and WrongCat Tests ***" << std::endl;

	WrongAnimal* wrongAnimal = new WrongAnimal();
	WrongAnimal* wrongCat = new WrongCat();

	// This should call WrongAnimal's makeSound, not WrongCat's
	std::cout << "** Calling makeSound() on WrongAnimal pointer **" << std::endl;
	wrongAnimal->makeSound(); // Output: Generic wrong animal sound!

	// This should also call WrongAnimal's makeSound, demonstrating non-polymorphic behavior
	std::cout << "** Calling makeSound() on WrongCat pointer, but as WrongAnimal type **" << std::endl;
	wrongCat->makeSound(); // Output: Generic wrong animal sound!


	std::cout << "--------------" << std::endl;
	delete meta;
	delete j;
	delete i;

	// Clean up memory
	delete wrongAnimal;
	delete wrongCat;

	return (0);
}
