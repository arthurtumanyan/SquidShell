#ifndef PROTOTYPES_H_INCLUDED
#define PROTOTYPES_H_INCLUDED

extern ssize_t Readline(int sockd, void *vptr, size_t maxlen);
extern ssize_t Writeline(int sockd, const void *vptr, size_t n);
extern unsigned int do_command(char *cmd);
extern void initHistory();
extern void log_debug(char *);
extern void log_debug(char *log_string);
extern void saveCmd(char *cmd);
extern int is_digit(char *pDigit);
extern void initHistory();
extern void Trim();
extern void fillArgs(char *token);
extern int isValidHost(char *h);
extern int isValidPort(const char *p);
extern void set_sig_handler();
extern void Shutdown();
extern void low_string(char *str);
extern void make_connect();
extern void dialog(int sockfd);
extern void cmd_set(char **argv);
extern void cmd_show(char **argv);
extern void cmd_proxy(char **argv);
extern void cmd_connect(char **argv);
extern void cmd_benchmark(char **argv);
extern void cmd_save(char **argv);
extern void cmd_help();
extern void cmd_quit();
extern void cmd_history();
extern void cmd_shell();

#endif // PROTOTYPES_H_INCLUDED
