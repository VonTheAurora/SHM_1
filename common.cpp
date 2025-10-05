#include "common.h"


void solver::step()
{
	update(); 
//	++iter; 
//	x_ += h_; 
}

void solver::print(ofstream& ofst)
{
//	cout << x_ << " | "; 
	if (prob_ != nullptr) {
		ofst << setw(16) << prob_->val[0] << ' '; 
	}
}


vec SHM_prob::func(vec input)
{
	vec f(3);
	f[0] = input[1]; 
	f[1] = -input[0] * input[2] * input[2]; 
	f[2] = 0; 
	return f; 
}

void euler_solver::update()
{
	vec k = prob_->func(prob_->val);
	for (int i = 0; i < k.size();++i) {
		prob_->val[i] = prob_->val[i] + h_ * k[i]; 
	}
}

void rk4_solver::update()
{
	vec k1 = prob_->func(prob_->val);
	vec k2 = prob_->val;
	for (int i = 0; i < prob_->val.size(); ++i)
		k2[i] += k1[i] * h_ / 2;
	k2 = prob_->func(k2);
	vec k3 = prob_->val;
	for (int i = 0; i < prob_->val.size(); ++i)
		k3[i] += k2[i] * h_ / 2;
	k3 = prob_->func(k3);
	vec k4 = prob_->val;
	for (int i = 0; i < prob_->val.size(); ++i)
		k4[i] += k3[i] * h_; 
	k4 = prob_->func(k4);
	for (int i = 0; i < prob_->val.size(); ++i)
		prob_->val[i] = prob_->val[i] + h_ * (k1[i] + 2 * k2[i] + 2 * k3[i] + k4[i]) / 6; 
//	cout << k1[0] << ' ' << k2[0] << ' ' << k3[0] << ' ' << k4[0] << endl; 
}

void adv_euler_solver::update()
{
	vector<double> k1 = prob_->func(prob_->val);
	vector<double> k2 = prob_->val; 
	for (int i = 0; i < k2.size(); ++i) {
		k2[i] += h_ * k1[i]; 
	}
	k2 = prob_->func(k2);
	for (int i = 0; i < k2.size(); ++i) {
		prob_->val[i] = prob_->val[i] + h_ * (k1[i] + k2[i]) / 2; 
	}
}
