# FdF
Realise a program able to display a 3D wireframe map

Install minilibX
	https://achedeuzot.me/2014/12/20/installer-la-minilibx/

Compile the program on MacOS:
	gcc -I /usr/X11/include -g -L /usr/X11/lib -lX11 -lmlx -lXext src/main.c
	cc main.c libft.a

Compile the program on Linux:
	gcc src/map.c src/lst_utils.c -Llib/mlx_linux -lmlx_Linux -L/usr/lib -Llib/libft -lft -Ilib/mlx_linux -lXext -lX11 -lm -lz

Check memory leaks MacOS:
	leaks --atExit -- ./a.out test_map/42.fdf