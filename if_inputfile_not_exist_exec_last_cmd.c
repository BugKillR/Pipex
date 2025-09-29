/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   if_inputfile_not_exist_exec_last_cmd.c             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkeskin <kkeskin@student.42istanbul.com.t  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 15:55:31 by kkeskin           #+#    #+#             */
/*   Updated: 2025/09/21 15:55:32 by kkeskin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	if_inputfile_not_exist_exec_last_cmd(int argc, int index, char *argv[])
{
	if (access(argv[1], F_OK) != 0)
		return (argc - 2);
	return (index);
}
