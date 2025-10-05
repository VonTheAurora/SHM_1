#pragma once
#include<iostream>
#include<fstream>
#include<iomanip>
#include<cmath>
#include<vector>
using namespace std; 
typedef vector<double> vec;

class problem {
public:
	problem(vec& origin) : val(origin) {}

	vec val;
	virtual vec func(vec input) = 0;
};

class solver {
public:
	solver(shared_ptr<problem> prob, float h) : prob_(prob), h_(h) {}
	void step();
	void print(ofstream& ofst); 

protected:
	virtual void update() = 0;
	shared_ptr<problem> prob_;
	double h_;
};

class SHM_prob :public problem {
public:
	SHM_prob(vec& ori) : problem(ori) {}
	vec func(vec input); 
};

class euler_solver :public solver {
public:
	euler_solver(shared_ptr<problem> prob, float h) : solver(prob, h) {} 
	void update(); 
};

class adv_euler_solver : public solver {
public:
	adv_euler_solver(shared_ptr<problem> prob, float h) : solver(prob, h) {};
	void update(); 
};

class rk4_solver :public solver {
public:
	rk4_solver(shared_ptr<problem> prob, float h) : solver(prob, h) {};
	void update();
}; 

