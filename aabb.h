#ifndef PROJECT0_AABB_H
#define PROJECT0_AABB_H

#include "rtweekend.h"

class aabb {
public:
    aabb() {}
    aabb(const vec3& a, const vec3& b) { _min = a; _max = b;}

    vec3 min() const {return _min; }
    vec3 max() const {return _max; }

    bool hit(const ray& r, double tmin, double tmax) const;

    vec3 _min;
    vec3 _max;
};

//bool aabb::hit(const ray& r, double tmin, double tmax) const {
//    for (int a = 0; a < 3; a++) {
//        auto t0 = ffmin((_min[a] - r.origin()[a]) / r.direction()[a],
//                        (_max[a] - r.origin()[a]) / r.direction()[a]);
//        auto t1 = ffmax((_min[a] - r.origin()[a]) / r.direction()[a],
//                        (_max[a] - r.origin()[a]) / r.direction()[a]);
//        tmin = ffmax(t0, tmin);
//        tmax = ffmin(t1, tmax);
//        if (tmax <= tmin)
//            return false;
//    }
//    return true;
//}

//优化后
inline bool aabb::hit(const ray& r, double tmin, double tmax) const {
    for (int a = 0; a < 3; a++) {
        auto invD = 1.0f / r.direction()[a];
        auto t0 = (min()[a] - r.origin()[a]) * invD;
        auto t1 = (max()[a] - r.origin()[a]) * invD;
        if (invD < 0.0f)
            std::swap(t0, t1);
        tmin = t0 > tmin ? t0 : tmin;
        tmax = t1 < tmax ? t1 : tmax;
        if (tmax <= tmin)
            return false;
    }
    return true;
}

aabb surrounding_box(aabb box0, aabb box1) {
    vec3 small(ffmin(box0.min().x(), box1.min().x()),
               ffmin(box0.min().y(), box1.min().y()),
               ffmin(box0.min().z(), box1.min().z()));
    vec3 big  (ffmax(box0.max().x(), box1.max().x()),
               ffmax(box0.max().y(), box1.max().y()),
               ffmax(box0.max().z(), box1.max().z()));
    return aabb(small,big);
}

#endif //PROJECT0_AABB_H
