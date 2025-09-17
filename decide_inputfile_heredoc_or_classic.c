/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decide_inputfile_heredoc_or_classic.c              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkeskin <kkeskin@student.42istanbul.com.t  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 04:56:05 by kkeskin           #+#    #+#             */
/*   Updated: 2025/09/17 04:56:05 by kkeskin          ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	decide_inputfile_heredoc_or_classic(int index, char *argv[])
{
	int	inputfile;

	if (index == 3)
		inputfile = h_inputfile_to_pipe(argv);
	else if (index == 2)
		inputfile = c_inputfile_to_pipe(argv);
	return (inputfile);
}
