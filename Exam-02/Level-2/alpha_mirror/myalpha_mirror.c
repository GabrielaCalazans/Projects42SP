/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   myalpha_mirror.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 17:05:26 by gacalaza          #+#    #+#             */
/*   Updated: 2023/04/28 17:14:30 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	main(int argc, char *argv[])
{
	int		i = 0;
	char	*str;

	if (argc == 2)
	{
		str = argv[1];
		while (str[i] != '\0')
		{
			if ((str[i] >= 'a' && <= 'z') || (str[i] >= 'A' && <= 'Z'))
			{
				
			}
			
			ft_putchar('\n');
		}
	}
	ft_putchar('\n');

}