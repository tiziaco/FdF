# FdF
Realise a program able to display a 3D wireframe map

Install minilibX
	https://achedeuzot.me/2014/12/20/installer-la-minilibx/

Compile the program:
	gcc -I /usr/X11/include -g -L /usr/X11/lib -lX11 -lmlx -lXext main.c
	cc main.c libft.a

Check memory leaks MacOS:
	leaks --atExit -- ./a.out test_map/42.fdf