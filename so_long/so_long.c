#include "mlx_linux/minilibx-linux/mlx.h"

typedef struct s_data {
	void *img;
	char *addr;
	int bits_per_pixel;
	int line_lenght;
	int endian;
}	t_data;

void my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char *dst;

	dst = data->addr + (y * data->line_lenght + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int main(void)
{
    void	*mlx;
	void	*mlx_win;
	t_data img;
	int comprimento = 1800;
	int altura = 1000;
	int x = 0;
	int y = 0;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello World!");
	img.img = mlx_new_image(mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_lenght, &img.endian);
	
	
	
	
	
	/* while (y < altura)
	{
		my_mlx_pixel_put(&img, 0, y, 0x00FF0000); 
		my_mlx_pixel_put(&img, comprimento - 1, y, 0x00FF0000);
		y++;
	}

	while (x < comprimento)
	{
		my_mlx_pixel_put(&img, x, 0, 0x00FF0000);
		my_mlx_pixel_put(&img, x, altura - 1, 0x00FF0000);
		x++ ;
	} */
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}