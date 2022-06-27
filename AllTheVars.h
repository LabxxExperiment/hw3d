#pragma once

/////////////////////////////////////////////////////////////VARIABLES/////////////////////////////////////////////////////////////////////////////////////
//int fuckery
extern int inttest;
extern int var1;
extern int var2;
extern int var3;
extern int var4;
extern int var5;
extern int var6;
//float fuckery
extern float the_duration;
extern float the_duration_seconds;
extern float the_elapse;
//string fuckery
extern std::string failtest;
extern std::string windowsVAR;
//chrono fuckery
extern std::ratio<1, 10> test_ratio; //num den
extern std::chrono::system_clock first_time;

extern std::chrono::steady_clock::time_point the_start;
extern std::chrono::steady_clock::time_point the_end;

extern std::chrono::duration<float> the_runtime;

extern std::chrono::seconds time_in_sec;
/////////////////////////////////////////////////////////////FUNCTIONS/////////////////////////////////////////////////////////////////////////////////////
