/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decide_outputfile_settings.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkeskin <kkeskin@student.42istanbul.com.t  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 00:36:29 by kkeskin           #+#    #+#             */
/*   Updated: 2025/09/18 00:36:30 by kkeskin          ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	decide_outputfile_settings(int argc, char *argv[], int index)
{
	int	outputfile;

	outputfile = 0;
	if (index == 3)
		outputfile = open(argv[argc - 1], O_CREAT | O_WRONLY | O_APPEND, 0644);
	else if (index == 2)
		outputfile = open(argv[argc - 1], O_CREAT | O_WRONLY | O_TRUNC, 0644);
	return (outputfile);
}
