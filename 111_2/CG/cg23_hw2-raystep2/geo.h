#ifndef GEOH
#define GEOH
#include "ray.h"
#include <algorithm>
#include <iostream>

using namespace std;

class material;

typedef struct hit_record {
	float t;
	vec3 p;
	vec3 nv;
} hit_record;

//geometry parent class
class hitable { 
public:
	virtual bool hit(const ray &r, float tmin, float tmax, hit_record &rec) const = 0;
};

class sphere : public hitable {
public:
	sphere() {}
	sphere(vec3 c, float r,vec3 _kd=vec3(1.0,1.0,1.0), float w_ri = 0.0f, float w_ti = 0.0f) : 
		center(c), radius(r), kd(_kd), w_r(w_ri), w_t(w_ti) {};
	virtual bool hit(const ray& r, float tmin, float tmax, hit_record& rec) const;
	
	vec3 center;
	float radius;
	vec3 kd;
	float w_r;//reflected
	float w_t;//transmitted
};

bool sphere::hit(const ray &r, float tmin, float tmax, hit_record & rec) const {
	/*
	To-do:
		compute whether the ray intersect the sphere
	*/
	vec3 oc = r.origin() - center;
    float a = dot(r.direction(), r.direction());
    float b = 2 * dot(oc, unit_vector(r.direction()));
    float c = dot(oc, oc) - radius*radius;
    float discriminant = b*b - 4*c;
    if (discriminant > 0) {
        float temp = (-b - sqrt(discriminant))/2;
        if (temp < tmax && temp > tmin) {
            rec.t = temp;
            rec.p = r.point_at_parameter(rec.t);
            rec.nv = unit_vector(rec.p - center);
            return true;
        }
        temp = (-b + sqrt(discriminant)) / 2;
        if (temp < tmax && temp > tmin) {
            rec.t = temp;
            rec.p = r.point_at_parameter(rec.t);
            rec.nv = unit_vector(rec.p - center);
            return true;
        }
    }
    return false;
}

vec3 reflect(const vec3 &d, const vec3 &nv) {
	//compute the reflect direction
	//To-do
	return d - 2*dot(d, nv)*nv;

	//return vec3(0, 0, 0);
}

vec3 refract(const vec3& v, const vec3& N, float r) {
	//compute the refracted direction
	//To-do
	//float cosi = clamp(-1, 1, dot(v, N));
    float cosi = dot(v,N);
	if(dot(v, N) > 1){
		cosi = 1;
	}
	else if(dot(v,N) < -1){
		cosi = -1;
	}

	float etai = 1, etat = r;
    vec3 n = N;
    if (cosi < 0){ cosi = -cosi; } else { std::swap(etai, etat); n= -N; }
    float eta = etai / etat;
    float k = 1 - eta * eta * (1 - cosi * cosi);
    
	if(k<0){
		return vec3(0,0,0);
	}
	return eta * v + (eta * cosi - sqrtf(k)) * n;
}

#endif
