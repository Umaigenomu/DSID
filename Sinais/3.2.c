#include <stdio.h>
#include <unistd.h>
// Bibliotecas acrescentadas
#include <stdlib.h> // para exit
#include <sys/wait.h> // para waitpid

int main(void)
/*
** Listing3.2a.c- Subtasking utilizando fork() e execl(): modulo do pai 
*/
{
int pid; /* child task’s process id */
/* Parent task sends a process id message to the screen */
printf("\nParent task active as process %d.\n", getpid());
/* fork() creates an identical copy of the parent task */
if((pid = fork()) == 0)
{
/* This block is ONLY executed by the subtask */
/* Child task replaces itself with disk image of child */
execl("/cygdrive/c/users/Arthur Duram Um/Programming/C/DSID/Sinais/3.2execl.exe", NULL);
printf("A successful execl() call will never return!\n");
exit(-1);
}
/* Parent awaits child task exit */
waitpid(pid,NULL, WUNTRACED);
return 0;
}