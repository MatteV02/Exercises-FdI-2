#include <stdlib.h>

typedef struct {
    int profit;
    int duration;
    int deadline;
}job;

extern int ScheduleJobs(const job* jobs, size_t j_size);

int main(void)
{
    job jobs[] = { {80,2,4},{100,5,6},{30,1,3} };

    int profit = ScheduleJobs(jobs, sizeof(jobs) / sizeof(*jobs));

	return 0;
}