/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 21:51:05 by gacalaza          #+#    #+#             */
/*   Updated: 2024/08/31 16:00:52 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"

int	main(void)
{
	// Test object construction and destruction
	std::cout << std::endl << "**** Object Construction and Destruction Tests ****" << std::endl;
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	delete j; // Should call Dog destructor, then Animal destructor
	delete i; // Should call Cat destructor, then Animal destructor
	std::cout << std::endl << "-----------------------------------------" << std::endl << std::endl;

	// Test array of objects and polymorphism
	std::cout << "**** Polymorphism with Animal Array ****" << std::endl;
	const Animal* meta[4];
	for (int i = 0; i < 4; i++) {
		if (i % 2 == 0)
			meta[i] = new Dog();
		else
			meta[i] = new Cat();
	}

	for (int i = 0; i < 4; i++) {
		std::cout << "Animal at index " << i << ": " << meta[i]->getType() << " -> ";
		meta[i]->makeSound();
	}

	for (int i = 3; i >= 0; i--) {
		delete meta[i]; // Should call the appropriate destructor for each object type
	}

	std::cout << std::endl << "-----------------------------------------" << std::endl << std::endl;

	// Test manipulation of Brain ideas for Cat
	std::cout << "**** Brain Manipulation Tests for Cat ****" << std::endl;
	Cat cat;
	cat.setBrainIdea(0, "I want Whiskas!");
	cat.setBrainIdea(1, "I want to sleep!");

	std::cout << "** Cat's Brain Ideas **" << std::endl;
	std::cout << "Idea 0: " << cat.getBrainIdea(0) << std::endl;
	std::cout << "Idea 1: " << cat.getBrainIdea(1) << std::endl;
	std::cout << std::endl << "-----------------------------------------" << std::endl << std::endl;

	// Test deep copy with assignment operator
	std::cout << "**** Copy and Assignment Tests for Cat ****" << std::endl;
	Cat tom;
	tom = cat; // Test assignment operator

	std::cout << std::endl << "** Tom's Brain Ideas after assignment **" << std::endl;
	std::cout << "Idea 0: " << tom.getBrainIdea(0) << std::endl;
	std::cout << "Idea 1: " << tom.getBrainIdea(1) << std::endl;

	tom.setBrainIdea(0, "I don't want Whiskas anymore!");
	std::cout << "** Tom's Brain Ideas after changing the idea **" << std::endl;
	std::cout << "Idea 0: " << tom.getBrainIdea(0) << std::endl;
	std::cout << "Idea 1: " << tom.getBrainIdea(1) << std::endl;
	
	std::cout << "** Cat's Brain Ideas (Should not be changed) **" << std::endl;
	std::cout << "Idea 0: " << cat.getBrainIdea(0) << std::endl;
	std::cout << "Idea 1: " << cat.getBrainIdea(1) << std::endl;
	std::cout << std::endl << "-----------------------------------------" << std::endl << std::endl;

	// Test deep copy with copy constructor
	std::cout << "**** Copy Constructor Test for Cat ****" << std::endl;
	Cat Penelope(tom);
	std::cout << "Penelope's Brain Ideas after copy construction:" << std::endl;
	std::cout << "Idea 0: " << Penelope.getBrainIdea(0) << std::endl;
	std::cout << "Idea 1: " << Penelope.getBrainIdea(1) << std::endl;

	Penelope.setBrainIdea(0, "I prefer chasing mice now!");
	std::cout << std::endl << "Penelope's Brain Ideas after change:" << std::endl;
	std::cout << "Idea 0: " << Penelope.getBrainIdea(0) << std::endl;
	std::cout << "Idea 1: " << Penelope.getBrainIdea(1) << std::endl;

	std::cout << std::endl << "Tom's Brain Ideas (Should not be changed):" << std::endl;
	std::cout << "Idea 0: " << tom.getBrainIdea(0) << std::endl;
	std::cout << "Idea 1: " << tom.getBrainIdea(1) << std::endl;

	// Test deep copy for Dog
	std::cout << std::endl << "**** Deep Copy Test for Dog ****" << std::endl;
	Dog basic;
	{
		Dog tmp = basic;
	} // tmp is destroyed here; should not affect basic's Brain

	std::cout << std::endl << "-----------------------------------------" << std::endl << std::endl;


	return (0);
}
