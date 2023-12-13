#include <iostream>
#include <fstream>
#include <string>
#include <random>
#include <cmath>


using namespace std;

// Function to generate a random number between 0 and 1
double gen_random() {
    return (float)rand() / RAND_MAX;
}

// Inverse CDF of s(x) normalized
double invCDF(double a, double p){
	double r=0.0;
	if (a <= (2*pow(p,2))/(2*pow(p,2)+1))
		r = ((2*pow(p,2)+1)/(2*p))*a;
	else{
		r = sqrt(pow(p,2)-log(1-a*(2*pow(p,2)+1)+2*pow(p,2)));
	}
	return r;
}

// pdf s(x) normalized
double s(double z, double p){
	double t=0.0;
	if (z <= p)
		t = (2*p)/(2*pow(p,2)+1);
	else{
		t = 2/(2*pow(p,2)+1)*z*exp(pow(p,2)-pow(z,2));
	}
	return t;
}

// original pdf g(x)
double g(double x){
	return 0.95+12/pow(M_PI,3)*(2-0.95*M_PI)*pow(x,2);
}

int main() {
	// The user can choose two parameters:
	// 1. the number of points to sample
	// 2. the power p
	int n_points;
	double p;
	cout << "Welcome. With this program you can sample points from cos(x) using importance sampling and rejection method." << endl;
	cout << "Set the value of power p: ";
	cin >> p;
	cout << "Please insert the number of points you want to generate: ";
	cin >> n_points;
	string filename1 = "imp_rej_n" + to_string(n_points) + "_p" + to_string(p)+ "_ok.txt";
	string filename2 = "imp_rej_n" + to_string(n_points) + "_p" + to_string(p)+ "_no.txt";
	cout << "Thanks. The accepted points will be saved into " << filename1 << " while the rejected ones into " << filename2 << endl;
	ofstream outfile1(filename1);
	ofstream outfile2(filename2);
 
    // sampling 
	for (int i = 0; i < n_points; i++) {
		double chi = gen_random(); // chi is in [0,1]
		double X = invCDF(chi,p);
		double chi2 = gen_random(); // chi is in [0,1]
		double c = (2*pow(p,2)+1)/(2*p)*g(0.0);
		if (chi2 < g(X)/ (c*s(X,p)))
			outfile1 << X << " " << chi2 << endl;
		else
			outfile2 << X << " " << chi2 <<endl;
	}
	outfile1.close();
	outfile2.close();
    return 0;
}
