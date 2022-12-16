#include <iostream>
#include <iomanip>

using namespace std;

class Time
{
	unsigned seconds;
	unsigned minutes;
	unsigned hours;
	const unsigned maxSecMin = 60;
	const unsigned maxHours = 24;
	void SecToOther()
	{
		minutes += seconds / maxSecMin;
		hours += minutes / maxSecMin;
		seconds %= maxSecMin;
		minutes %= maxSecMin;
		hours %= maxHours;
	}
public:
	Time() : seconds(0), minutes(0), hours(0) {}
	Time(unsigned hours, unsigned minutes, unsigned sec)
	{
		if (hours < 0 || maxHours <= hours)
			this->hours = 0;
		else
			this->hours = hours;
		if (minutes < 0 || maxSecMin <= minutes)
			this->minutes = 0;
		else
			this->minutes = minutes;
		if (sec < 0 || maxSecMin <= sec)
			this->seconds = 0;
		else
			this->seconds = sec;
	}
	explicit Time(unsigned long sec)
	{
		seconds = sec;
		SecToOther();
	}

	void Print() const { cout << setfill('0') << setw(2) << hours << ':' << setfill('0') << setw(2) << minutes << ':' << setfill('0') << setw(2) << seconds << endl; }
	void AddSec()
	{
		++seconds;
		SecToOther();
	}

	friend Time operator+(const Time& t1, const Time& t2)
	{
		Time diff;
		int tot1, tot2;
		tot1 = t1.seconds + t1.minutes * t1.maxSecMin + t1.hours * t1.maxSecMin * t1.maxSecMin;
		tot2 = t2.seconds + t2.minutes * t2.maxSecMin + t2.hours * t2.maxSecMin * t2.maxSecMin;
		diff.seconds = tot1 + tot2;
		diff.SecToOther();
		return diff;
	}
	friend Time operator+(const Time& t1, unsigned value)
	{
		if (!value)
			return t1;
		Time diff;
		diff.seconds = t1.seconds + t1.minutes * t1.maxSecMin + t1.hours * t1.maxSecMin * t1.maxSecMin + value;
		diff.SecToOther();
		return diff;
	}
	friend Time operator+(unsigned value, const Time& t)
	{
		return t + value;
	}

	friend Time operator-(const Time& t1, const Time& t2)
	{
		Time diff;
		unsigned tot1, tot2;
		tot1 = t1.seconds + t1.minutes * t1.maxSecMin + t1.hours * t1.maxSecMin * t1.maxSecMin;
		tot2 = t2.seconds + t2.minutes * t2.maxSecMin + t2.hours * t2.maxSecMin * t2.maxSecMin;
		diff.seconds = tot1 - tot2;
		diff.SecToOther();
		return diff;
	}
	friend Time operator-(const Time& t1, unsigned value)
	{
		Time diff;
		diff.seconds = t1.seconds + t1.minutes * t1.maxSecMin + t1.hours * t1.maxSecMin * t1.maxSecMin - value;
		diff.SecToOther();
		return diff;
	}

	friend Time operator*(const Time& t1, const Time& t2)
	{
		Time diff;
		diff.seconds = t1.seconds * t2.seconds % diff.maxSecMin;
		diff.minutes = t1.minutes * t2.minutes % diff.maxSecMin;
		diff.hours = t1.hours * t2.hours % diff.maxHours;
		return diff;
	}
	friend Time operator*(const Time& t1, unsigned value)
	{
		Time diff;
		diff.seconds = t1.seconds * value % diff.maxSecMin;
		diff.minutes = t1.minutes * value % diff.maxSecMin;
		diff.hours = t1.hours * value % diff.maxHours;
		return diff;
	}
	friend Time operator*(unsigned value, const Time& t)
	{
		return t * value;
	}

	friend Time operator/(const Time& t1, const Time& t2)
	{
		Time diff;
		if (!t1.seconds || !t2.seconds)
			diff.seconds = 0;
		else
			diff.seconds = t1.seconds / t2.seconds % diff.maxSecMin;
		if (!t1.minutes || !t2.minutes)
			diff.minutes = 0;
		else
			diff.minutes = t1.minutes / t2.minutes % diff.maxSecMin;
		if (!t1.hours || !t2.hours)
			diff.hours = 0;
		else
			diff.hours = t1.hours / t2.hours % diff.maxHours;
		return diff;
	}
	friend Time operator/(const Time& t1, unsigned value)
	{
		Time diff;
		diff.seconds = t1.seconds / value % diff.maxSecMin;
		diff.minutes = t1.minutes / value % diff.maxSecMin;
		diff.hours = t1.hours / value % diff.maxHours;
		return diff;
	}

	friend bool operator== (const Time& t1, const Time& t2)
	{
		return (t1.seconds == t2.seconds && t1.minutes == t2.minutes && t1.hours == t2.hours);
	}
	friend bool operator!= (const Time& t1, const Time& t2)
	{
		return !(t1 == t2);
	}

	friend bool operator> (const Time& t1, const Time& t2)
	{
		if (t1.hours > t2.hours)
			return true;
		else if (t1.hours == t2.hours && t1.minutes > t2.minutes)
			return true;
		else if (t1.minutes == t2.minutes && t1.seconds > t2.seconds)
			return true;
		else
			return false;
	}
	friend bool operator<= (const Time& t1, const Time& t2)
	{
		return !(t1 > t2);
	}
	friend bool operator< (const Time& t1, const Time& t2)
	{
		if (t1.hours < t2.hours)
			return true;
		else if (t1.hours == t2.hours && t1.minutes < t2.minutes)
			return true;
		else if (t1.minutes == t2.minutes && t1.seconds < t2.seconds)
			return true;
		else
			return false;
	}
	friend bool operator>= (const Time& t1, const Time& t2)
	{
		return !(t1 < t2);
	}
	Time& operator= (const Time& t)
	{
		seconds = t.seconds;
		minutes = t.minutes;
		hours = t.hours;
		return *this;
	}
};


int main()
{
	Time London(9479);
	cout << "\nLondon:\n";
	London.Print();
	London.AddSec();
	London.Print();

	cout << "\nKyiv:\n";
	Time Kyiv(11, 20, 12);
	Kyiv.Print();

	cout << "\nTotal (Kyiv + London) = ";
	Time Total(Kyiv + London);
	Total.Print();

	cout << "\nTotal2 = Kyiv - Total = ";
	Time Total2(Kyiv - Total);
	Total2.Print();
	cout << "\nKyiv = Kyiv - 4 = ";
	Kyiv = Kyiv - 4;
	Kyiv.Print();

	cout << "\nKyiv * London = ";
	(Kyiv * London).Print();

	cout << "\nKyiv * 5 = ";
	(Kyiv * 5).Print();

	cout << "\nKyiv / London = ";
	(Kyiv / London).Print();

	cout << "\nKyiv / 5 = ";
	(Kyiv / 5).Print();

	cout << "\nKyiv < London? " << (Kyiv < London) << endl;
	cout << "\nKyiv > London? " << (Kyiv > London) << endl;
	cout << "\Total == London? " << (Total == London) << endl;
	cout << "\nKyiv== Kyiv? " << (Kyiv == Kyiv) << endl;
}