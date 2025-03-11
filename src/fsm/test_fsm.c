#include "fsm.h"
#include <stdio.h>

enum
{
    RED,
    YELLOW,
    GREEN
};

enum
{
    TIMER_EXPIRED
};

void handle_red(void *data)
{
    printf("RED\n");
}

void handle_yellow(void *data)
{
    printf("YELLOW\n");
}

void handle_green(void *data)
{
    printf("GREEN\n");
}

int main(int argc, char const *argv[])
{
    StateTransition traffic_light_transitions[] = {
        {RED, TIMER_EXPIRED, GREEN, handle_red},
        {GREEN, TIMER_EXPIRED, YELLOW, handle_green},
        {YELLOW, TIMER_EXPIRED, RED, handle_yellow}};

    StateMachine traffic_light;
    initalize_fsm(&traffic_light, RED, traffic_light_transitions, 3);

    for (int i = 0; i < 10; i++)
    {
        printf("current state: %d\n", traffic_light.currentState);
        process_event(&traffic_light, TIMER_EXPIRED, "");
    }

    return 0;
}
