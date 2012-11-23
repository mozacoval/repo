#include <signal.h>
#include <string.h>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

using namespace std;

void sighandler(int signal)
{
    perror("receive signal");
    abort();
}


int main()
{
    struct sigaction action;
    memset(&action, 0, sizeof(action));
    action.sa_handler = sighandler;
    const string &testref = "aaaaaaaaaaaaaa";
    if(sigaction(SIGINT, &action, NULL) != 0)
        perror("sigaction");
    sleep(70);
}
