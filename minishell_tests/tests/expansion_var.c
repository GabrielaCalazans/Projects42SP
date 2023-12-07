/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion_var.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacalaza <gacalaza@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 13:42:48 by gacalaza          #+#    #+#             */
/*   Updated: 2023/12/05 20:17:47 by gacalaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

// ACEITA UNDERLINE INICIO E FIM
// ACEITA NUMERO SÓ DEPOIS DA PRIMEIRA LETRA 
// RETIRAR OS ESPAÇOS DO PARSE AO COLOCAR PALAVRA JUNTO DE PALAVRA COM ASPAS
char	*has_expandable_var(t_data *data, char *str)
{
	int		i;
	char	*str;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '$')
		{
			if (can_expand(data, &str[++i]))
				str = get_str_expand(str, &str[++i], get_var_value(data, &str[++i], i));
		}
		i++;
	}
	return (str);
}

char	*get_str_expand(char *str, char *var, char *value, int i)
{
	int		j;
	int		k;
	int		len;
	char	*new_str;

	k = 0;
	j = 0;
	len = ((ft_strlen(str) - ft_strlen(var)) + ft_strlen(value));
	new_str = malloc(sizeof(char) * len + 1);
	while (j < i)
		new_str[j++] = str[j];
	if (ft_strncmp(&str[i], var, ft_strlen(var) + 1) == 0)
	{
		while (value[k] != '\0')
			new_str[j++] = value[k++];
	}
	i += ft_strlen(var);
	while (str[i] && str[i] != '\0')
		new_str[j++] = str[i++];
}

char	*get_var_value(t_data *data, char *var)
{
	t_env	*tmp;

	tmp = data->env_node;
	while (tmp)
	{
		if ((ft_strncmp(tmp->var, var, ft_strlen(tmp->var) + 1)) == 0)
			return (ft_strdup(tmp->value));
		tmp = tmp->next;
	}
	return (NULL);
}

int	can_expand(t_data *data, char *var)
{
	t_env	*tmp;

	tmp = data->env_node;
	while (tmp)
	{
		if (ft_strncmp(tmp->var, var, ft_strlen(tmp->var) + 1))
			tmp = tmp->next;
		else
			return (1);
	}
	return (0);
}
