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

// Define the functions f(x, T), rho(x), and g(x, a)
double f(double x, double T) {
    return (x >= T) ? 1.0 : 0.0;
}

double rho(double x) {
    return exp(-x);
}

double g(double x, double a) {
    return a * exp(-a * x);
}

int main() {
    // The user can choose:
	// 1. T value
	// 2. The number of points to sample
    int num_samples;
	int T;
	cout << "Welcome. Through this program you can sample from f using importance sampling using measures e^(-x) and a*e^(-ax)."<< endl;
	cout << "Please insert the value of T: ";
	cin >> T;
	cout << "Please insert the number of points to sample: ";
	cin >> num_samples;
	
	string filename1 = "imps_r_T"+to_string(T)+"_n"+to_string(num_samples)+".txt";
	string filename2 = "imps_g_T"+to_string(T)+"_n"+to_string(num_samples)+".txt";
	cout << "Thanks. The sampled points using e^(-x) will be saved into " << filename1 << ", while the sampled points using a*e^(-a*x) will be saved into " << filename2<< endl;
	ofstream outfile1(filename1);
	ofstream outfile2(filename2);
	
	
	double a_s = (T+1-pow((pow(T,2)+1),0.5)) /T; // a* minimazing variance 
	double int_rho = 0.0;
    double int_g = 0.0;

	for (int i = 0; i < num_samples; ++i) {
		double chi1 = -log(gen_random()); //sample from rho
		double value_f = f(chi1, T);
		int_rho += value_f;
		outfile1 << chi1 << " " << value_f << endl;
		
		double chi2 = -log(gen_random()) / a_s; //sample from g
		double value_F = f(chi2, T) * rho(chi2) / g(chi2, a_s); //value of F
		int_g += value_F;
		outfile2 << chi2 << " " << value_F <<endl;
	}
	outfile1.close();
	outfile2.close();

    int_rho / num_samples;
	int_g / num_samples;
	cout << "integral_estimate_rho for T = "+to_string(T)+" : "  << int_rho << "\n";
	cout << "integral_estimate_g for T = "+to_string(T)+" : " << int_g << "\n";
	
    return 0;
}
