/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsambing <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 11:01:16 by rsambing          #+#    #+#             */
/*   Updated: 2024/07/12 11:01:18 by rsambing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_exec(char *arg[])
{
	char	*pathname;
	pid_t	pid;

	pathname = ft_strjoin("/bin/", arg[0]);
	if (!pathname)
		return (-1);
	pid = fork();
	if (pid == -1)
	{
		free(pathname);
		return (-1);
	}
	if (pid == 0)
	{
		if (execve(pathname, arg, NULL) == -1)
		{
			free(pathname);
			return (-1);
		}
	}
	waitpid(pid, NULL, 0);
	free(pathname);
	return (1);
}
