#ifndef FM_H
#define FM_H

#include "syntezer.h"

struct FmParams
{
    FmParams()
    {
        for(int i=0; i<7;i++)
        {
            out[i] = 0;
            d[i] = 0;
            f[i] = 1;
        }
        for(int i=0; i<4;i++)
        {
            rate[i] = 1;
            level[i] = 1;
        }
    }
    double f_oc;
    double A;
    double f[7];
    double I[7];
    double d[7];
    double rate[4];
    double level[5];
    double out[7];
};

class FMSynth : public Syntezer
{
    Q_OBJECT
public:

    FMSynth();
    FmParams  gui_params;
    int n_test;
    double algo1(FmParams* p, double t);
    double algo17(FmParams* p, double t);
    double algo19(FmParams* p, double t, int n);
    Buffer* play_note(char note, double duration, double velocity);

    double* Test1(double f_oc, double SampleRate, double time, int* N);
    double* Test2(double f_oc, double SampleRate, double time, int* N);
    void TestEvenlope();
    double Evenlope(FmParams* params, double t);
};
#endif // FM_H