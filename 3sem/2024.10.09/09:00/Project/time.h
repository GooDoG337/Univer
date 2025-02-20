#ifndef TIME_H
#define TIME_H
namespace chron {
	class Time {
	private:
		int hours = 0;
		int minutes = 0;
		int seconds = 0;
		void normalise();
	public:
		Time() = default;
		Time(int h, int m, int s);
		Time(int s):Time(0,0,s) { };
		int GetHours() const;
		int GetMinutes() const;
		int GetSeconds() const;
		void AddSeconds(int s);
	};
}
#endif //TIME_H
