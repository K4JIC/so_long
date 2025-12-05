#include <stdlib.h>
#include "mlx.h" // minilibx.h または mlx.h に合わせてください

int main(void)
{
    void *mlx_ptr;

    // 1. MinilibXの初期化
    mlx_ptr = mlx_init();

    // 初期化に失敗したら終了
    if (mlx_ptr == NULL)
        return (1);
	
	mlx_destroy_display(mlx_ptr);
	free(mlx_ptr);
    return (0);
}