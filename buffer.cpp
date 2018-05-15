#include "buffer.h"

Buffer::Buffer()
{
    samples.push_back(0);
    samplesD.push_back(0);
    bWrited = false;
}

Buffer::Buffer(int SampleRate, double duration, int channels)
    : duration(duration)
{
    int size = SampleRate * duration * channels;
    samples.resize(size);
    samplesD.resize(size);
    bWrited = false;
    timeStart = QTime::currentTime();
}

bool Buffer::checkExpired()
{
    double sec = timeStart.msecsTo(QTime::currentTime()) / 1000.;
    if( sec > duration)
        bWrited = true;
    return bWrited;
}
