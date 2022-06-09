#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct {
    int profit;
    int duration;
    int deadline;
}job;

int compare_jobs(const void* a, const void* b)
{
    const job* a_job = a, * b_job = b;
    double a_profit_duration = (double)a_job->profit / a_job->duration,
        b_profit_duration = (double)b_job->profit / b_job->duration;

    if (a_profit_duration == b_profit_duration)
    {
        return (a_job->duration < b_job->duration) - (a_job->duration > b_job->duration);
    }

    return (a_profit_duration > b_profit_duration) - (a_profit_duration < b_profit_duration);
}

int ScheduleJobs(const job* jobs, size_t j_size)
{
    size_t presi = 0;
    bool* job_presi = calloc(j_size, sizeof(bool));
    int t = 0;
    int profit = 0;

    while (presi < j_size) {

        size_t best = 0;

        while (job_presi[best]) {
            best++;
        }

        for (size_t i = best + 1; i < j_size; ++i)
        {
            if (!job_presi[i] && compare_jobs(jobs + i, jobs + best) > 0) {
                best = i;
            }
        }

        job_presi[best] = true;
        presi++;

        if (jobs[best].deadline >= t + jobs[best].duration) {
            printf("%zu ", best);
            t += jobs[best].duration;
            profit += jobs[best].profit;
        }

    }

    return profit;
}