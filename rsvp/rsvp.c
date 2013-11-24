//
//  main.c
//  rsvp
//
//  Created by Jianbin Lei on 11/21/13.
//  Copyright (c) 2013 Alberto. All rights reserved.
//

#include "rsvp.h"
#include "course.h"

int main(int argc, const char * argv[])
{
    
    //printf("%s \n",argv[1]);
    
    FILE* fp = fopen(argv[1], "r");
    
    if (fp == NULL)
    {
        fclose(fp);
        perror("Error");
        exit(1);
    }
    
    //
    read_courses(fp);
    display_info();
    
    return 0;
}


void display_info()
{
    int choice = get_choice();
    if(choice < 0 || choice > 2)
    {
        printf("Your choice is outside the acceptable range. Please try again. \n");
        display_info();
    }
    if(choice == 0)
    {
        exit(0);
    }
    if(choice == 1)
    {
        int crn;
        printf("Please enter a CRN: ");
        scanf("%d",&crn);
        find_CRN(crn);
        //printf("1 \n");
        display_info();
    }
    if(choice == 2)
    {
        char sub[4];
        printf("Please enter a subject: ");
        scanf("%s",sub);
        find_subject(sub);
        //printf("2 \n");
        display_info();
    }
}

int get_choice()
{
    int choice;
    printf("\n");
    printf("RSVP Menu \n");
    printf("0. Done. \n");
    printf("1. Find by CRN. \n");
    printf("2. Find by subject. \n");
    printf("Your choice (0 - 2): ");
    scanf("%d",&choice);
    return choice;
}
