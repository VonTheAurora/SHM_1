#include"common.h"
using namespace std; 

double theta_0, omiga_0, mu, h;

double SHM_val(double t) {
	double fi = atan(theta_0 * mu / omiga_0); 
	if (sin(fi) != 0)
		return sin(mu * t + fi) * theta_0 / sin(fi); 
	else
		return sin(mu * t + fi) * omiga_0 / cos(fi) / mu;
}

void SHM_solve() {
	ofstream ofst; 
	ofst.open("output.res"); 
	cin >> theta_0 >> omiga_0 >> mu >> h; 
	vector<double> ori = { theta_0,omiga_0,mu }; 
	shared_ptr<problem> prob1(new SHM_prob(ori)); 
	shared_ptr<problem> prob2(new SHM_prob(ori)); 
	shared_ptr<problem> prob3(new SHM_prob(ori));

	euler_solver es(prob1, h); 
	rk4_solver rs(prob2, h); 
	adv_euler_solver aes(prob3, h); 
	

	int n; 
	cin >> n; 
	for (int i = 0; i < n; ++i) {
		//cout << "Iteration " << i << " t: " << i * h << endl; 
		ofst << i * h << " "; 
		es.print(ofst); 
		rs.print(ofst); 
		aes.print(ofst); 
		ofst << setw(16) << SHM_val(i * h) << endl;
		es.step(); 
		rs.step(); 
		aes.step(); 
	}
}

int main() {
	SHM_solve(); 
	return 0; 
}