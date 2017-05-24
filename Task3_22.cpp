
#include <iostream>
#include <vector>

 class Date {
    public:
        int day;
        int month;
        int year;
        Date(): day(0), month(0), year(0) {};
        Date(int _day, int _month, int _year): day(_day), month(_month), year(_year) {};
        Date(const Date &_date) { day = _date.day; month = _date.month; year = _date.year; }
};

bool isBigger(const Date &date1, const Date &date2) {
    if (date1.year > date2.year) return true;
    if (date1.year < date2.year) return false;
    if (date1.month > date2.month) return true;
    if (date1.month < date2.month) return false;
    return date1.day > date2.day;
}

void decriment(Date &date) {
    if (date.day == 1) {
        if (date.month == 1) {
            date.year--;
            date.month = 12;
            date.day = 30;
        }
        else {
            date.month--;
            date.day = 30;
        }
    }
    else
        date.day--;
}

bool newBorders(Date &birth, Date &death) {
    Date tmp(birth.day, birth.month, birth.year + 18);
    if (!isBigger(death, tmp)) return false;
    birth.year += 18;

    tmp.year += 62;
    if (isBigger(death, tmp)) {
        death.year = tmp.year;
        death.month = tmp.month;
        death.day = tmp.day;
    }
    decriment(death);
    return true;
}

class Point {
    public:
        Date date;
        int indicator;
        Point(): date(), indicator(0) {};
        Point(Date _date, int _indicator): date(_date), indicator(_indicator) {};
        Point(const Point &_point) { date = _point.date; indicator = _point.indicator; }
};

bool isBigger_point(const Point &p1, const Point &p2) {
    return isBigger(p1.date, p2.date);
}

template <class T>
void SiftDown(T *arr, int size, int i, bool (comparer)(const T&, const T&)) {
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    int largest = i;
    if (left < size && comparer(arr[left], arr[i])) largest = left;
    if (right < size && comparer(arr[right], arr[largest])) largest = right;
    if (largest != i) {
        std::swap(arr[i], arr[largest]);
        SiftDown(arr, size, largest, comparer);
    }
}

template <class T>
void BuildHeap(T *arr, int size, bool (comparer)(const T&, const T&)) {
    for (int i = size / 2 - 1; i >=0; i--) {
        SiftDown(arr, size, i, comparer);
    }
}

template <class T>
void HeapSort(T *arr, int heapSize, bool (comparer)(const T&, const T&)) {
    BuildHeap(arr, heapSize, comparer);
    while (heapSize > 1) {
        std::swap(arr[0], arr[heapSize - 1] );
        heapSize--;
        SiftDown(arr, heapSize, 0, comparer);
    }
}

int count(Point *arr, int size) {
    int result = 0, cur_max = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i].indicator > 0) cur_max++;
        else cur_max--;
        if (cur_max > result) result = cur_max;
    }
    return result;
}

int main() {
    int n = 0;
    std::cin >> n;
    std::vector<Point> array;
    for (int i = 0; i < n; i++) {
        int day = 0, month = 0, year = 0;
        std::cin >> day >> month >> year;
        Date birth(day, month, year);
        std::cin >> day >> month >> year;
        Date death(day, month, year);
        if (newBorders(birth, death)) {
            Point p1(birth, 1), p2(death, -1);
            array.push_back(p1);
            array.push_back(p2);
        }
    }
    HeapSort(&array[0], array.size(), isBigger_point);
    std::cout << count(&array[0], array.size());
    return 0;
}