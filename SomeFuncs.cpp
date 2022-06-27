#include "IncludeSystem.h"
#include "IncludeCreated.h"

//int
int someadd(int x,int y)
{
	int z = x + y;
	return z;
}
//string
std::string stringtest()
{
	return "SomeFuncs";
}
std::string int_string(int num)
{
	return std::to_string(num);
}
std::string float_string(float num)
{
	return std::to_string(num);
}
//void
void theinitialization()
{
	the_elapse = 0;
}
void thetimeloop()
{
	the_start = the_end;
	the_end = std::chrono::steady_clock::now();
	the_runtime = the_end - the_start;
	the_duration = the_runtime.count();
	//the_duration_seconds = std::chrono::duration_cast<std::chrono::nanoseconds>(the_runtime).count();
	the_elapse = the_elapse + the_duration;
}
void themainloop()
{
	thetimeloop();
	stringtest2();
	wastetime();
	windowsVAR = float_string(the_elapse);
}
void wastetime()
{
	for (int x = 0; x < 1000; x++)
	{
		for (int y = 0; y < 1000; y++)
		{
			var1 = x;
			var2 = y;
			var3 = x;
			var4 = y;
			var5 = x;
			var6 = y;
		}
	}
}
void theframetime()
{

}
//chrono
