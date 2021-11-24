#include <bits/stdc++.h>
using namespace std;

const int maxSize = 1e9;
int64_t area;

int64_t calc(int x1, int y1, int x2, int y2){
    cout << "? " << x1 << ' ' << y1 << ' ' << x2 << ' ' << y2 << '\n' << flush;
    int64_t ans; cin >> ans;
    return ans;
}

void answer(int lx, int ly, int rx, int ry){
    cout << "! " << lx << ' ' << ly << ' ' << rx << ' ' << ry << flush;
}

int binarySearch1(){
    int left = 1, right = maxSize;
    while (left < right){
        int mid = (left + right) / 2;
        if (calc(1, 1, mid, maxSize) < area) left = mid + 1;
        else right = mid;
    }
    return left;
}

int binarySearch2(){
    int left = 1, right = maxSize;
    while (left < right){
        int mid = (left + right) / 2;
        if (calc(1, 1, maxSize, mid) < area) left = mid + 1;
        else right = mid;
    }
    return left;
}

int main()
{
    area = calc(1, 1, maxSize, maxSize);
    int rx = binarySearch1(), ry = binarySearch2();
    int64_t areaOneRow = calc(rx, 1, rx, maxSize);
    int lx = rx - area/areaOneRow + 1, ly = ry - areaOneRow + 1;
    answer(lx, ly, rx, ry);
    return 0;
}
