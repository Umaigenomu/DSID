
#include <sys/signal.h>
#include <stdio.h>
#include <unistd.h>
int count = 0; /* counter for the number of ^C events handled */
int main(void)
/*
** Listing3.3.c -Tratando o sinal ativado pelo keyboard atraves de ctrl+c (^C)
*/
{
void control_C();
/* initialize ^C handler */
signal(SIGINT, control_C);
while(count < 3) {
/* tell interactive user what to do */
printf("\n\tInsira um ^C (ctrl+c) quando quiser...");
fflush(stdout);
pause();
printf("Evento #%d tratado.\n", count);
}
printf("\nTres eventos foram tratados. Tchau!\n\n");
return 0;
}

void control_C()
{
/* reestablish handler */
signal(SIGINT, control_C);
/* count ^Cs */
count++;
}