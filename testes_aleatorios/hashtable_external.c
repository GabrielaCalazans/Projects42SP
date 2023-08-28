/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashtable_external.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 17:17:12 by gacalaza          #+#    #+#             */
/*   Updated: 2023/08/28 15:54:08 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>

// const represent the size of hashtable
#define MAX_NAME 256
#define TABLE_SIZE 10

typedef struct s_person
{
	int		age;
	char	name[MAX_NAME];
	struct	s_person *next;
}			t_person;

t_person	*hash_table[TABLE_SIZE];

unsigned int	hash(char *name)
{
	int	length = strnlen(name, MAX_NAME);
	unsigned int hash_value = 0;
	for (int i=0; i < length; i++)
	{
		hash_value += name[i];
		hash_value = (hash_value * name[i]) % TABLE_SIZE;
	}
	return (hash_value);
}

void	init_hashtable()
{
	for (int i = 0; i < TABLE_SIZE; i++)
	{
		hash_table[i] = NULL;
	}
	//table is empty
}

void	print_table()
{
	printf("Start\n");
	for (int i = 0; i < TABLE_SIZE; i++)
	{
		if (hash_table[i] == NULL)
			printf("\t%i\t---\n", i);
		else
		{
			printf("\t%i\t", i);
			t_person	*tmp = hash_table[i];
			while (tmp != NULL)
			{
				printf("%s - ", tmp->name);
				tmp = tmp->next;
			}
			printf("\n");
			
		}
	}
	printf("End\n");
}

bool	hashtable_insert(t_person *p)
{
	if (p == NULL)
		return false;
	int	index = hash(p->name);
	p->next = hash_table[index];
	hash_table[index] = p;
	return true;
}

// find a person in the table by their name
t_person	*hashtable_lookup (char *name)
{
	int	index = hash(name);
	t_person	*tmp = hash_table[index];
	while (tmp != NULL && strncmp(tmp->name, name, MAX_NAME) != 0)
	{
		tmp = tmp->next;
	}
	return tmp;
}

t_person *hashtable_delete(char *name)
{
	int	index = hash(name);
	t_person	*tmp = hash_table[index];
	t_person	*prev = NULL;
	while (tmp != NULL && strncmp(tmp->name, name, MAX_NAME) != 0)
	{
		tmp = tmp->next;
	}
	if (tmp != NULL)
		return NULL;
	if (prev == NULL)
	{
		//deleting the head
		hash_table[index] = tmp->next;
	}
	else
		prev->next = tmp->next;
	return tmp;
}


int	main ()
{
	init_hashtable();
	// print_table();


	t_person	jacob = {.name = "Jacob", .age=25};
	t_person	kate = {.name = "Kate", .age=27};
	t_person	mpho = {.name = "Mpho", .age=14};
	t_person	sarah = {.name = "Sarah", .age=54};
	t_person	edna = {.name = "Edna", .age=15};
	t_person	maren = {.name = "Maren", .age=25};
	t_person	eliza = {.name = "Eliza", .age=34};
	t_person	robert = {.name = "Robert", .age=1};
	t_person	jane = {.name = "Jane", .age=5};

	hashtable_insert(&jacob);
	hashtable_insert(&kate);
	hashtable_insert(&mpho);
	hashtable_insert(&sarah);
	hashtable_insert(&edna);
	hashtable_insert(&maren);
	hashtable_insert(&eliza);
	hashtable_insert(&robert);
	hashtable_insert(&jane);
	print_table();

	t_person	*tmp = hashtable_lookup("Mpho");
	if (tmp == NULL)
	{
		printf("Not found!\n");
	}
	else
	{
		printf("Found %s\n", tmp->name);
	}

	tmp = hashtable_lookup("George");
	if (tmp == NULL)
	{
		printf("Not found!\n");
	}
	else
	{
		printf("Found %s\n", tmp->name);
	}
	hashtable_delete("Mpho");
	tmp = hashtable_lookup("Mpho");
	if (tmp == NULL)
	{
		printf("Not found!\n");
	}
	else
	{
		printf("Found %s\n", tmp->name);
	}
	print_table();
	
	return 0;
}