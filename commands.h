#ifndef COMMANDS_H_INCLUDED
#define COMMANDS_H_INCLUDED

#define CMD_COUNT 11
#define MAX_ARGC 5

#include "SquidShell.h"
#include "prototypes.h"

const char *histFile = ".sqsh_history";
char hline[MAXLINE];

struct cmd_p * parseCmd(char *cmd);


struct hElement{
    unsigned int no[HIST_MAX];
    char cmd[HIST_MAX][MAXLINE];
    }*he;


struct cmd{
    char *cmd_name;
    void (*func)();
    const char desc[MAXLINE];
};

struct cmd_p {
    char cmd[255];
    char args[MAX_ARGC][MAXLINE];
    }*rv;

struct cmd cmd_table[CMD_COUNT] = {
    {
        "set",(&cmd_set),"Set/change various variables defined in squid configuration files"
    },
    {
        "show",(&cmd_show),"Show values of variables defined in squid configuration files"
    },
    {
        "dummy",(&cmd_proxy),""
    },
    {
        "connect",(&cmd_connect),"Connect to the proxy server using given credentials"
    },
    {
        "benchmark",(&cmd_benchmark),"Various tests for proxy server (Note: you must be connected)"
    },
    {
        "help",(&cmd_help),"This help message"
    },
    {
        "quit",(&cmd_quit),"Exit the program"
    },
    {
        "bye",(&cmd_quit),"Alias to 'quit'"
    },
    {
        "exit",(&cmd_quit),"Alias to 'quit'"
    },
    {
        "history",(&cmd_history),"Show commands history (enter command number to repeat command execution)"
    },
    {
        "shell",(&cmd_shell),"Call unix shell"
    }

};


#endif // COMMANDS_H_INCLUDED
