#include <stdio.h>

int pressButtons(int buttons[], int len)
{
    int res = 0;
    for (int i = 0; i < len; i++)
    {
        printf("Before: %d %d\n", res, buttons[i]);
        res ^= buttons[i];
        printf("After: %d\n\n", res);
    }
    return res;
}

int main(void)
{
    int buttons[20] = {0};
    buttons[3] = 8;
    buttons[5] = 32;
    buttons[9] = 512;
    int len = 20;
    int res = pressButtons(buttons, len);
    printf("%d", res);
    return 0;
}
