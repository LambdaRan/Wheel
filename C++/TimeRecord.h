
// 打印代码运行时间

#ifndef TIMERECORD_H
#define TIMERECORD_H

#include <sys/time.h> // gettimeofday();
#include <stdio.h>
#include <stdint.h>

// 其他相关函数　clock()、times()、clock_gettime()

// struct timeval {
//     time_t      tv_sec;     /* seconds */
//     suseconds_t tv_usec;    /* microseconds */
// };

class TimeRecord 
{
public: 
    TimeRecord()
        : time_(0)
    {}
    ~TimeRecord() {}

    
    void start()
    {
        struct timeval startTime;
        gettimeofday(&startTime, NULL);
        time_ = static_cast<int64_t>(startTime.tv_sec) * kMicroSecondsPerSecond + startTime.tv_usec;
    }

    void stop()
    {
        struct timeval endTime;
        gettimeofday(&endTime, NULL);
        int64_t et = static_cast<int64_t>(endTime.tv_sec) * kMicroSecondsPerSecond + endTime.tv_usec;
        int64_t cus = et - time_;
        //fprintf(stderr, "start: %ld us\n", time_);
        //fprintf(stderr, "end: %ld us\n", et);
        fprintf(stderr, "cost: %ld us\n", cus);
        fprintf(stderr, "cost: %f ms\n", static_cast<double>(cus) / 1000);
    }

private: // 阻止拷贝
  TimeRecord(const TimeRecord&) = delete;
  void operator=(const TimeRecord&) = delete;

private:
    static const int kMicroSecondsPerSecond = 1000 * 1000;
    int64_t time_;
};
#endif // !TIMERECORD_H
