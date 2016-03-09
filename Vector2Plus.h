#ifndef VECTOR2PLUS_H_INCLUDED
#define VECTOR2PLUS_H_INCLUDED

#include <SFML/System.hpp>
#include <cmath>

#define EPS 1e-7
template<class T>
using vec2 = sf::Vector2<T>;
typedef vec2<int> vec2i;
typedef vec2<float> vec2f;

template<typename T>
T operator*(const vec2<T> a, const vec2<T> b);

template<typename T>
T operator% (const vec2<T> a, const vec2<T> b);

bool operator== (const vec2f a, const vec2f b);

bool operator== (const vec2i a, const vec2i b);

template<typename T>
float mag(const vec2<T> a) {
    return hypot(a.x, a.y);
}

template<typename T>
float getRadians(const vec2<T>& a) {
    return atan2(a.y, a.x)-(acos(-1)/2.0);
}
#endif // VECTOR2PLUS_H_INCLUDED
