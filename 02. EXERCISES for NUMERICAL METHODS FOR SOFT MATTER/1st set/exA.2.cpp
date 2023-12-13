#include <iostream>
#include <fstream>
#include <string>
#include <random>
#include <cmath>

using namespace std;

// Inverse CDF
double invCDF(double chi, double n, int a) {
	double u = chi * pow(a, (n+1));
    return pow(u, (1.0 / (n+1)));
}

// Function to generate a random number between 0 and 1
double gen_random() {
    return (float)rand() / RAND_MAX;
}

int main() {
	// The user can choose the following parameters:
	// 1. the number of throws
	// 2. the power n of the pdf x^n
	// 3. the value a of interval [0,a] where data are sampled
	int n_points;
	int n;
	int a;
	cout << "Welcome. With this program you can sample points from n power pdf using inverse sampling." << endl;
	cout << "Please insert the desidered n power: ";
	cin >> n;
	cout << "Data are in range [0,a]. Insert the desired a: ";
	cin >> a;
	cout << "Please insert the number of points you want to generate: ";
	cin >> n_points;
	string filename = "inv_sampling_n" + to_string(n) + "_" + to_string(n_points) + "_" + to_string(a) + ".txt";
	cout << "Thanks. The samples will be saved into " << filename << endl;
	ofstream outfile(filename);
  
    // inverse sampling 
	for (int i = 0; i < n_points; i++) {
		double chi = gen_random();
		double x = invCDF(chi, n, a);
		outfile << x << endl;
	}
	outfile.close();
    return 0;
}
