#include <stdio.h>
#include <unistd.h>
// Bibliotecas acrescentadas
#include <stdlib.h> // para exit
#include <sys/wait.h> // para waitpid

int main(void)
/*
** Listing3.1.c - Subtasking utilizando fork() dentro de um modulo
*/
{
int pid; /* child task’s process id */
/* Parent task sends a process id message to the screen */
printf("\nParent task active as process %d.\n", getpid());
/* fork() creates an identical copy of the parent task */
if((pid = fork()) == 0)
{
/* This block is ONLY executed by the subtask */
/* Child task sends a process id message to the screen */
printf("Child task active as process %d.\n", getpid());
/* Child task exits normally */
exit(0);
}
/* Parent awaits child task exit */
waitpid(pid, NULL,WUNTRACED);
return 0;   
}