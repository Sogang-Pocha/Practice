#define _USE_MATH_DEFINES

#include <iostream>
#include <cmath>
#include <vector>
#include <cassert>
#include <algorithm>

using namespace std;

#define EPSILON 0.000000001
#define all(v) (v).begin(),(v).end()

class vector2d {

public:
	double x, y;

	vector2d(double _x, double _y) : x(_x), y(_y) {}
	vector2d() : x(0), y(0) {}

	bool operator==(const vector2d& rhs) const {
		return x == rhs.x && y == rhs.y;
	}

	bool operator<(const vector2d& rhs) const {
		if (x == rhs.x)
			return y < rhs.y;
		return x < rhs.x;
	}

	vector2d operator+(const vector2d& rhs) const {
		return vector2d(x + rhs.x, y + rhs.y);
	}

	vector2d operator-(const vector2d& rhs) const {
		return vector2d(x - rhs.x, y - rhs.y);
	}

	vector2d operator*(const double time) const {
		return vector2d(x * time, y * time);
	}

	double length() const {
		return hypot(x, y);
	}

	vector2d unit() const {
		return vector2d(x / length(), y / length());
	}

	vector2d norm() const {
		return vector2d(-y, x);
	}

	double polar() const {
		return fmod(atan2(y, x) + 2 * M_PI, 2 * M_PI);
	}

	double dot(const vector2d& rhs) const {
		return x * rhs.x + y * rhs.y;
	}

	double cross(const vector2d& rhs) const {
		return x * rhs.y - y * rhs.x;
	}

	//현재 벡터를 rhs에 사영
	vector2d project(const vector2d& rhs) const {
		vector2d r = rhs.unit();
		return r * r.dot(*this);
	}
};

// 원점 기준 b가 a의 반시계면 + 시계면 - 평행 0
double ccw(vector2d a, vector2d b) {
	return a.cross(b);
}

//점 p기준
double ccw(vector2d p, vector2d a, vector2d b) {
	return ccw(a - p, b - p);
}

//직선 교점
bool lineIntersection(vector2d a, vector2d b, vector2d c, vector2d d, vector2d& p) {
	double det = (b - a).cross(d - c);
	if (fabs(det) < EPSILON) return false;
	p = a + (b - a) * ((c - a).cross(d - c) / det);
	return true;
}

bool parallelSegment(vector2d a, vector2d b, vector2d c, vector2d d, vector2d& p) {
	if (b < a) swap(a, b);
	if (d < b) swap(c, d);

	if (ccw(a, b, c) != 0 || b < c || d < a) return false;

	if (a < c) p = c; else p = a;
	return true;
}

bool inBoundRectangle(vector2d p, vector2d a, vector2d b) {
	if (b < a) swap(a, b);
	return p == a || p == b || (a < p && p < b);
}

bool segmentIntersection(vector2d a, vector2d b, vector2d c, vector2d d, vector2d& p) {
	if (!lineIntersection(a, b, c, d, p))
		return parallelSegment(a, b, c, d, p);

	return inBoundRectangle(p, a, b) && inBoundRectangle(p, c, d);
}

bool segmentIntersection(vector2d a, vector2d b, vector2d c, vector2d d) {
	double ab = ccw(a, b, c) * ccw(a, b, d);
	double cd = ccw(c, d, a) * ccw(c, d, b);

	if (ab == 0 && cd == 0) {
		if (b < a) swap(a, b);
		if (d < c) swap(c, d);
		return !(b < c || d < a);
	}
	return ab <= 0 && cd <= 0;
}

vector2d foot(vector2d p, vector2d a, vector2d b) {
	return a + (p - a).project(b - a);
}

double pointToLine(vector2d p, vector2d a, vector2d b) {
	return (p - foot(p, a, b)).length();
}

typedef vector<vector2d> polygon;

double area(const polygon& p) {
	double ret = 0.;
	for (int i = 0; i < p.size(); i++) {
		int j = (i + 1) % p.size();
		ret += p[i].cross(p[j]);
	}
	return fabs(ret) / 2.0;
}

bool isInside(vector2d q, const polygon& p) {
	int crosses = 0;
	for (int i = 0; i < p.size(); i++) {
		int j = (i + 1) % p.size();
		if ((p[i].y > q.y) != (p[j].y > q.y)) {
			double atX = (p[j].x - p[i].x) * (q.y - p[i].y) /
				(p[j].y - p[i].y) + p[i].x;

			if (q.x < atX) crosses++;
		}
	}
	return crosses % 2;
}

polygon cutPoly(const polygon& p, const vector2d& a, const vector2d& b) {
	int n = p.size();
	vector<bool> inside(n);

	for (int i = 0; i < n; i++)
		inside[i] = ccw(a, b, p[i]) >= 0;

	polygon ret;

	for (int i = 0; i < n; i++) {
		int j = (i + 1) % n;
		if (inside[i]) ret.push_back(p[i]);

		if (inside[i] != inside[j]) {
			vector2d cross;
			assert(lineIntersection(p[i], p[j], a, b, cross));
			ret.push_back(cross);
		}
	}
	return ret;
}

/*
//볼록 껍질 구하기 O(nlogn)
//polygon points 전역 선언 해야함
polygon points;
bool cmp(vector2d& a, vector2d& b) {
	double d = ccw(points[0], a, b);
	if (d > 0. || d < 0.)
		return d > 0.;

	return a.x - points[0].x < b.x - points[0].x;
}

vector<int> grahamScan() {
	int n = points.size();
	vector<int> ret;

	swap(points[0], *min_element(all(points)));
	sort(points.begin() + 1, points.end(), cmp);
	ret.push_back(0); ret.push_back(1);

	for (int i = 2; i < n; i++) {
		while (ret.size() >= 2) {
			int p2 = ret.back(); ret.pop_back();
			int p1 = ret.back();
			if (ccw(points[p1], points[p2], points[i]) > 0.) {
				ret.push_back(p2);
				break;
			}
		}
		ret.push_back(i);
	}

	return ret;
}
*/

//O(n^2)
polygon giftWrap(const polygon& points) {
	int n = points.size();
	polygon ret;

	vector2d pivot = *min_element(all(points));
	ret.push_back(pivot);

	while (true) {
		vector2d ph = ret.back(), nxt = points[0];
		for (int i = 1; i < n; i++) {
			double cross = ccw(ph, nxt, points[i]);
			double dist = (nxt - ph).length() - (points[i] - ph).length();
			if (cross > 0 || (cross == 0 && dist < 0))
				nxt = points[i];
		}
		if (nxt == pivot) break;
		ret.push_back(nxt);
	}
	return ret;
}

//볼록 다각형의 지름 O(nlogn)
double diameter(const polygon& p) {
	int n = p.size();

	int left = min_element(all(p)) - p.begin();
	int right = max_element(all(p)) - p.begin();

	vector2d calipersA(0, 1);
	double ret = (p[right] - p[left]).length();

	polygon nxt(n);

	for (int i = 0; i < n; i++)
		nxt[i] = (p[(i + 1) % n] - p[i]).unit();

	int a = left, b = right;
	while (a != right || b != left) {
		double cosA = calipersA.dot(nxt[a]);
		double cosB = -calipersA.dot(nxt[b]);

		if (cosA > cosB) {
			calipersA = nxt[a];
			a = (a + 1) % n;
		}
		else {
			calipersA = nxt[b] * -1;
			b = (b + 1) % n;
		}
		ret = max(ret, (p[a] - p[b]).length());
	}
	return ret;
}