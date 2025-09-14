/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flood_fill.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkeskin <kkeskin@student.42istanbul.com.t  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 20:23:13 by kkeskin           #+#    #+#             */
/*   Updated: 2025/08/31 20:23:14 by kkeskin          ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	fill(char **map, t_flood_fill_data data, char search, char swap)
{
	if (data.curr.x < 0 || data.curr.y < 0 || data.curr.x >= data.size.x
		|| data.curr.y >= data.size.y
		|| map[data.curr.y][data.curr.x] != search)
		return ;
	map[data.curr.y][data.curr.x] = swap;
	data.curr.x += 1;
	fill(map, data, search, swap);
	data.curr.x -= 2;
	fill(map, data, search, swap);
	data.curr.x += 1;
	data.curr.y += 1;
	fill(map, data, search, swap);
	data.curr.y -= 2;
	fill(map, data, search, swap);
}

void	ft_flood_fill(char **map, t_flood_fill_data beginning,
	char search, char swap)
{
	fill(map, beginning, search, swap);
}
/*
int main(void)
{
	const char	*src[] = {
		"11111111",
		"10001001",
		"10010001",
		"10000001",
		"11100001",
		NULL,
	};


	int height = 0;
    while (src[height]) height++;
    int width = (int)ft_strlen(src[0]);
	char **map = malloc((height + 1) * sizeof(char *));
    if (!map) return 1;
    for (int i = 0; i < height; i++)
    {
        map[i] = ft_strdup(src[i]);
        if (!map[i]) return 1;
    }
    map[height] = NULL;
	int i = 0;
	int k;
	while (map[i])
	{
		k = 0;
		while (map[i][k])
		{
			ft_putchar_fd(map[i][k], 1);
			ft_putchar_fd(' ', 1);
			k++;
		}
		ft_putchar_fd('\n', 1);
		i++;
	}
	ft_putchar_fd('\n', 1);

	t_vector2	v2_size;
	v2_size.x = 8;
	v2_size.y = 5;
	printf("X Size:%d\nY Size:%d\n", v2_size.x, v2_size.y);

	t_vector2	v2_origin;
	v2_origin.x = 0;
	v2_origin.y = 0;

	t_flood_fill_data	fill_data;
	fill_data.size = v2_size;
	fill_data.curr = v2_origin;

	ft_flood_fill(map, fill_data, '1', 'F');

	printf("\n");
	i = 0;
	while (map[i])
	{
		k = 0;
		while (map[i][k])
		{
			ft_putchar_fd(map[i][k], 1);
			ft_putchar_fd(' ', 1);
			k++;
		}
		ft_putchar_fd('\n', 1);
		i++;
	}
	ft_putchar_fd('\n', 1);

	return (0);
}
*/
