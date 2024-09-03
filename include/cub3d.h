/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vipalaci <vipalaci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 16:04:33 by vini              #+#    #+#             */
/*   Updated: 2024/08/22 18:10:36 by vipalaci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <errno.h>
# include <math.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <limits.h>
# include "../libft/include/libft.h"
# include "../libft/include/get_next_line.h"
# include "../libft/include/ft_printf.h"
# include "../mlx/mlx.h"
# include <X11/keysym.h>
# include <X11/X.h>

# define PI 3.14159264

// CHANGE THESE VALUES IF YOU USE OTHER TEXTURES OR SCREEN RATIO!
# define WIDTH 1280
# define HEIGHT 720
# define TEXTURE_WIDTH 32
# define TEXTURE_HEIGHT 32
// YOU HAVE BEEN WARNED!

# define KEY_ESC		65307
# define KEY_W			119
# define KEY_A			97
# define KEY_S			115
# define KEY_D			100
# define SPACE			32

# define KEY_UP			65362
# define KEY_DOWN		65364
# define KEY_L			65361
# define KEY_R			65363

# define SPEED			0.09
# define ROTATION		0.09

# ifndef O_DIRECTORY
#  define O_DIRECTORY 00200000
# endif

typedef struct s_intvector
{
	int	x;
	int	y;
}	t_intvector;

typedef struct s_vector
{
	double	x;
	double	y;
}	t_vector;

typedef struct s_ray
{
	int			side;
	int			line_start;
	int			line_end;
	double		cam_x;
	double		perpwalldist;
	double		wall_x;
	double		tex_pos;
	double		tex_step;
	t_intvector	pos;
	t_intvector	step;
	t_intvector	tex;
	t_vector	dir;
	t_vector	delta_dist;
	t_vector	side_dist;
}	t_ray;

typedef struct s_img
{
	void	*mlx_img;
	void	*ptr;
	int		w;
	int		h;
	int		bpp;
	int		stride;
	int		endian;
}	t_img;

typedef struct s_player
{
	char		point;
	float		fov;
	t_vector	pos;
	t_vector	dir;
	t_vector	plane;
}	t_player;

typedef struct s_texturedata
{
	char	*n;
	char	*s;
	char	*e;
	char	*w;
	char	**f;
	char	**c;
}	t_texturedata;

typedef struct s_filedata
{
	int		lines;
	int		fd;
	char	**file_cpy;
}	t_filedata;

typedef struct s_data
{
	int				map_height;
	void			*mlx;
	void			*win;
	char			**map;
	char			**dmap;
	t_filedata		file_data;
	t_texturedata	tex;
	t_player		pc;
	t_img			img[5];
	t_ray			ray;
}	t_data;

int			parse(t_data *data, char **argv);
int			count_lines(char *file);
int			count_map_height(char **file, int i);
int			map_validity(t_data *data);
int			info_validity(t_texturedata textures);
int			render(t_data *data);
int			number_to_hex(char **number);
int			key_event(int key_code, t_data *data);
int			close_window(t_data *data);
void		init_data(t_data *data);
void		init_player(t_data *data);
void		init_cameraplane(t_data *data);
void		init_img(t_data *data);
void		copy_colors(t_data *data, char *line, int j);
void		copy_textures(t_data *data, char *line, int j);
void		copy_info(t_data *data, char *line, int j);
void		copy_map(t_data *data, char **file, int i);
void		fill_copy(t_data *data);
void		print_info(t_data *data);
void		print_array(char **array);
void		free_info(t_data *data);
void		free_array(char **array);
void		floodfill(char **map_dup, int x, int y);
void		duplicate_map(t_data *data);
void		raycasting(t_data *data);
void		draw_vline(t_data *data, int x);
void		put_pixel(t_data *data, int x, int y, int color);
void		clean_game(t_data *data);
void		destroy_images(t_data *data);
void		game_error(t_data *data, char *error);
char		*ft_strdup_no_nl(char *str);

#endif