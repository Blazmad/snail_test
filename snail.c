#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void display_maze(char * const *src)
{
    for (int i = 0; src[i] != 0; i++)
        printf("%s\n", src[i]);
    printf("\n");
}

char **create_maze(int width, int height)
{
    char **way = malloc(sizeof(char *) * (height + 1));
    int i = 0;
    int j = 0;

    while (i < height) {
        way[i] = malloc(sizeof(char) * (width + 1));
        j = 0;
        while (j < width) {
            way[i][j] = 'X';
            j++;
        }
        way[i][j] = '\0';
        i++;
    }
    way[i] = NULL;
    return way;
}

char **snail(char **way, int height, int width)
{
    int index = 1;
    int row = 0;
    int column = -1;

    display_maze(way);
    for (int loop = 0; loop < height; loop++) {
        for (int val = 0; val < (height - loop); val++) {
            column += index;
            way[row][column] = 'V';
            display_maze(way);
        }
        for (int val = 1; val < (height - loop); val++) {
            row += index;
            way[row][column] = 'V';
            display_maze(way);
        }
        index = -index;
    }
}

int main(int ac, char **av)
{
    int height = atoi(av[1]);
    int width = atoi(av[2]);
    char **way = create_maze(width, height);

    snail(way, height, width);
    return 0;
}