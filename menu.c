/**************************************************************************************************/
/* Copyright (C) 1434005644@qq.com, sse@USTC, 2014-2015                                           */
/*                                                                                                */
/*  FILE NAME             :  menu.c                                                               */
/*  PRINCIPAL AUTHOR      :  xinguosheng                                                          */
/*  SUBSYSTEM NAME        :  menu                                                                 */
/*  MODULE NAME           :  menu                                                                 */
/*  LANGUAGE              :  C                                                                    */
/*  TARGET ENVIRONMENT    :  DEV-C++                                                              */
/*  DATE OF FIRST RELEASE :  2014/09/15                                                           */
/*  DESCRIPTION           :  This is a menu program                                               */
/**************************************************************************************************/

/*
 * Revision log:
 *
 * Created by xinguosheng, 2014/09/15
 *
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DESC_LEN    1024
#define CMD_LEN     128

typedef struct DataNode
{
    char*   cmd;
    char*   desc;
    struct  DataNode *next;
} DataNode;

/*this is definition of putMenuList*/
void putMenuList(DataNode *x)
{
    while(x != NULL)
    {
        printf("%s - %s\n", x->cmd, x->desc);
        x = x->next;
    } 
}

/*this is definition of putListOne*/
void putListOne(DataNode *y , DataNode *z)
{
    while(1)
    {
        char cmd[CMD_LEN];
        printf("Input a cmd > ");
        scanf("%s", cmd);
        y = z;
        while(y != NULL)
        {
            if(!strcmp(y->cmd , cmd))
            {
                printf("%s - %s\n", y->cmd, y->desc);
                break;
		    }
            y = y->next;
        }
        if(y == NULL)
        {
            printf("This is a wrong cmd !\n ");
        }
    }
}

void main()
{   
    static DataNode head[] =
    {
        {"help","this is help cmd.",&head[1]},
        {"xml","this is xml cmd.",&head[2]},
        {"html","this is html cmd.",&head[3]},
        {"version","menu progrram v2.0",NULL}
    };
    DataNode * p = head;
    printf("menu list : \n");
    putMenuList(p);
    putListOne(p , head);   
}


