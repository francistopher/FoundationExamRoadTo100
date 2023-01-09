#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include "../../leak_detector_c.h"

#define MONTH_NAME 10
#define HOROSCOPE_NAME 15

typedef struct Month
{
    struct Month* next;
    int index;
    char* name;
    int lastday;
} Month;

typedef struct Horoscope
{
    struct Horoscope* next;
    char* name;
    int index;
    int startMonth;
    int startDate;
    int endMonth;
    int endDate;
} Horoscope;

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

Horoscope* getHoroscope(char name[HOROSCOPE_NAME], int index)
{
    Horoscope* horoscope = (Horoscope*)malloc(sizeof(Horoscope));
    horoscope->name = (char*)malloc(sizeof(char) * HOROSCOPE_NAME);
    strcpy(horoscope->name, name);
    horoscope->index = index;
    horoscope->startMonth = 0;
    horoscope->startDate = 0;
    horoscope->endMonth = 0;
    horoscope->endDate = 0;
    horoscope->next = NULL;
    return horoscope;
}

Month* getMonthInfo()
{
    Month* monthInfo = NULL;
    Month* monthTemp = NULL;
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
        }
        else
        {
            fscanf(fp, "%d", &lastDate);
            monthTemp->lastday = lastDate;
        }
    }
    fclose(fp);
    return monthInfo;
}

Horoscope* getHoroscopeInfo()
{
    
    Horoscope* horoscopeInfo = NULL;
    Horoscope* horoscopeTemp = NULL;
    FILE* fp = fopen("ranges.txt", "r");
    char horoscope[HOROSCOPE_NAME];
    int startMonth = 0;
    int startDate = 0;
    int endMonth = 0;
    int endDate = 0;
    for (int i = 0; i < 36; i++)
    {
        if (i % 3 == 0)
        {
            fscanf(fp, "%s", horoscope);
         
            if (i == 0)
            {
                horoscopeInfo = getHoroscope(horoscope, i / 3);
                horoscopeTemp = horoscopeInfo;
            }
            else{
                horoscopeTemp->next = getHoroscope(horoscope, i / 3);
                horoscopeTemp = horoscopeTemp->next;
            }
            
        }
        else if (i % 3 == 1)
        {
            
            fscanf(fp, "%d%d", &startMonth, &startDate);
            horoscopeTemp->startMonth = startMonth;
            horoscopeTemp->startDate = startDate;
            
        }
        else if (i % 3 == 2)
        {
            
            fscanf(fp, "%d%d", &endMonth, &endDate);
            horoscopeTemp->endMonth = endMonth;
            horoscopeTemp->endDate = endDate;
            
        }
    }
    fclose(fp);
    return horoscopeInfo;

}

void printMonthInfo(Month* monthInfo)
{
    while (monthInfo)
    {
        printf("%s %d %d\n", monthInfo->name, monthInfo->index, monthInfo->lastday);
        monthInfo = monthInfo->next;
    }
}

void printHoroscopeInfo(Horoscope* h)
{
    while (h)
    {
        printf("%s %d %d %d %d\n", h->name, h->startMonth, h->startDate, h->endMonth, h->endDate);
        h = h->next;
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

void freeHoroscopeInfo(Horoscope* h)
{
    if (h->next)
    {
        freeHoroscopeInfo(h->next);
    }
    free(h->name);
    free(h);
}

int main(void)
{
    atexit(report_mem_leak);
    Month* monthInfo = getMonthInfo();
    Horoscope* horoscopeInfo = getHoroscopeInfo();

    printMonthInfo(monthInfo);
    printHoroscopeInfo(horoscopeInfo);
    freeMonthInfo(monthInfo);
    freeHoroscopeInfo(horoscopeInfo);
    return 0;
}
