#include "./ft_fdf.h"

int main()
{
    t_app app;

    app.init = mlx_init();

    app.win= mlx_new_window(app.init, 500, 300, "Fils de Fer");
    mlx_key_hook(app.win, ft_get_keycode, &app);
	ft_trace_line(&app, 0, 0, 500, 300);
    mlx_hook(app.win, 17, 0, ft_close_program, &app);
    mlx_loop(app.init);
    return (0);
}