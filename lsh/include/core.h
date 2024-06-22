#ifndef CORE_H
#define CORE_H

char *lsh_read_line(void);
char **lsh_split_line(char *line);
int lsh_launch(char **args);
int lsh_execute(char **args);
void lsh_loop(void);

#endif  // CORE_H
