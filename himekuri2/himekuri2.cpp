#define _CRT_SECURE_NO_WARNINGS
#include "all.h"

int main(void) {
    try {
        time_t now = time(nullptr);
        const tm* nowlt = localtime(&now);

        stringstream x;
        x << "R0";
        x << nowlt->tm_year - 118;
        x << ".";
        x << nowlt->tm_mon + 1;
        x << ".";
        x << nowlt->tm_mday;

        string result_r = x.str();

        stringstream y;
        y << "令和";
        y << nowlt->tm_year - 118;
        y << "年";
        y << nowlt->tm_mon + 1;
        y << "月";
        y << nowlt->tm_mday;
        y << "日";

        string result_reiwa = y.str();


        stringstream z;
        z << "20";
        z << nowlt->tm_year - 100;
        z << "年";
        z << nowlt->tm_mon + 1;
        z << "月";
        z << nowlt->tm_mday;
        z << "日" << " : ";
        z << nowlt->tm_hour;
        z << "時";
        z << nowlt->tm_min;
        z << "分";
        z << nowlt->tm_sec;
        z << "秒";

        auto result = z.str();

        // OneYear → 365 days.
        auto OneYear_Days = 365;

        auto redays = nowlt->tm_yday;
        auto redays_mini = OneYear_Days - redays;

        auto tim = "現在時刻";
        auto gantan = "来年の1月1日まであと";
        auto aisatu = " 日です";
        auto number = "日めくり数え番号";
        auto week = "曜日";

        // week Sun ~ Sat
        time_t timer;
        struct tm* t_st;
        const char* wday[] = { "日", "月", "火", "水", "木", "金", "土" };

        // Month 和風月
        const char* wmonth[] = { "睦月", "如月", "弥生", "卯月", "皐月", "水無月", "文月", "葉月", "長月", "神無月", "霜月", "師走"
        };

        time(&timer);
        t_st = localtime(&timer);

        stringstream ss;
        stringstream ssd;

        // version number
        ss << 1;
        ssd << 2;
        auto str_num = ss.str();
        auto str_dd = ssd.str();
        string comma = " : ";

        // version number comma
        auto number_comma = ".1.";

        auto himekuri = number + comma + str_num + number_comma + str_dd;

        cout << tim << comma << result << comma << wday[t_st->tm_wday] << week << comma << wmonth[t_st->tm_mon] << endl;
        cout << gantan << comma << redays_mini << aisatu << endl;
        cout << result_reiwa << comma << result_r << endl;
        cout << himekuri << endl;

        // C++ version info.
        auto cpp20 = 202002L;
        auto cpp17 = 201703L;
        auto cpp17_2 = 201709L;
        auto cpp14 = 201402L;
        auto cpp11 = 201103L;
        auto cpp98 = 199711L;

        // int type → string type changes.
        auto cpp_ver = to_string(_MSVC_LANG);

        if (cpp_ver.compare(to_string(cpp20)) == 0)
            cout << "現在の C++ : C++20" << endl;
        else if (cpp_ver.compare(to_string(cpp17)) == 0)
            cout << "現在の C++ : C++17" << endl;
        else if (cpp_ver.compare(to_string(cpp17_2)) == 0)
            cout << "現在の C++ : C++17" << endl;
        else if (cpp_ver.compare(to_string(cpp14)) == 0)
            cout << "現在の C++ : C++14" << endl;
        else if (cpp_ver.compare(to_string(cpp11)) == 0)
            cout << "現在の C++ : C++11" << endl;
        else if (cpp_ver.compare(to_string(cpp98)) == 0)
            cout << "現在の C++ : C++98" << endl;
        else
            cout << "現在の C++ : pre-standard C++" << endl;

    }
    catch (const runtime_error& e) {
        cout << "runtime_error : " << e.what() << endl;
    }
    catch (const exception& e) {
        cout << "some exception : " << e.what() << endl;
    }
    exit(0);
}