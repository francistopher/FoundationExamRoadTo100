#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include "../leak_detector_c.h"

#define MONTH_NAME 10

typedef struct Month
{
    struct Month* next;
    int index;
    char* name;
    int lastday;
} Month;

Month* getMonth(char name[MONTH_NAME], int index)
{
    Month* month = (Month*)malloc(sizeof(Month));
    month->index = index;
    month->name = (char*)malloc(sizeof(char) * MONTH_NAME);
    strcpy(month->name, name);        
    month->next = NULL;
    month->lastday = 0;
    return month;
}

Month* getMonthInfo()
{
    Month* monthInfo = NULL;
    Month* monthTemp = NULL;
    printf("Hello, World!\n");
    FILE* fp = fopen("lastdays.txt", "r");
    char month[MONTH_NAME];
    int lastDate = 0;
    for (int i = 0; i < 24; i++)
    {
        if (i % 2 == 0)
        {
            fscanf(fp, "%s", month);
            if (i == 0)
            {
                monthInfo = getMonth(month, i / 2);
                monthTemp = monthInfo;
            }
            else
            {
                monthTemp->next = getMonth(month, i / 2);
                monthTemp = monthTemp->next;
            }
            printf("%s\n", month);
        }
        else
        {
            fscanf(fp, "%d", &lastDate);
            monthTemp->lastday = lastDate;
            printf("%d\n", lastDate);
        }
    }
    fclose(fp);
    return monthInfo;
}

void printMonthInfo(Month* monthInfo)
{
    while (monthInfo)
    {
        printf("%s %d %d\n", monthInfo->name, monthInfo->index, monthInfo->lastday);
        monthInfo = monthInfo->next;
    }
}

void freeMonthInfo(Month* monthInfo)
{
    if (monthInfo->next) {
        freeMonthInfo(monthInfo->next);
    } 
    free(monthInfo->name);
    free(monthInfo);

}

int main(void)
{
    atexit(report_mem_leak);
    Month* monthInfo = getMonthInfo();

    printMonthInfo(monthInfo);
    freeMonthInfo(monthInfo);
    return 0;
}
