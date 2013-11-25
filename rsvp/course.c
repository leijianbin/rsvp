//
//  course.c
//  rsvp
//
//  Created by *** on 11/21/13.
//  Copyright (c) 2013 Alberto. All rights reserved.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "course.h"

int size = 0;
int count = 100;
int *CRNs = NULL;
char **subject = NULL, **courseNum = NULL;

void read_courses(FILE *fp)
{
    //initialize the arrays
    initialize(&CRNs, &subject, &courseNum);
    
    char line[30], *p ; //the line size is 80
    
    while(fgets(line, 30, fp))
    {
        if(line[0]>'0' && line[0]<'9')
        {
            p = strtok(line, "\t");
            int num = atoi(p);
            
            if(num < 10000 || num > 99999) continue;  //if not five digit, break out the loop, go to next line
            
            int itr = 0;
            while(itr < 3) {
                if(itr == 0){
                    CRNs[size] = num;
                    itr++;
                }
                else if(itr == 1){
                    if(strcmp(p,"^") == 0)
                        p = strtok(NULL, "\t");
                    strcpy(subject[size], p);
                    itr++;
                }
                else {
                    strcpy(courseNum[size], p);
                    itr++;
                }
                p = strtok(NULL, "\t");
            }
            //printf("%d %s %s \n",CRNs[size],subject[size],courseNum[size]);
            size++;
            
            if(size == (count - 1))
            {
                count *= 2;
                resize(&CRNs, &subject, &courseNum, count);
            }
        }
    }
    
    
    fclose(fp);
    //read_file
}


void find_CRN(int CRN)
{
    int i;
    int flag = 0;
    for(i = 0; i < size; i++)
    {
        if(CRNs[i] == CRN)
        {
            printf("%d %s %s \n",CRNs[i],subject[i],courseNum[i]);
            flag = 1;
        }
    }
    
    if(flag == 0)
    {
        printf("CRN %d not found \n",CRN);
    }
}

void find_subject(char *sub)
{
    int i;
    int flag = 0;
    for(i = 0; i < size; i++)
    {
        if(strcmp(sub, subject[i]) == 0)
        {
            printf("%d %s %s \n",CRNs[i],subject[i],courseNum[i]);
            flag = 1;
        }
    }
    
    if(flag == 0)
    {
        printf("Subject %s not found \n",sub);
    }
}

