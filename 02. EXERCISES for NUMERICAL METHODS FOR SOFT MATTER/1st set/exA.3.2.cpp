#include <iostream>
#include <fstream>
#include <string>
#include <random>
#include <cmath>

using namespace std;

// Function to generate a random number between a and b
double gen_random(double a, double b) {
    return a+(float)rand() / RAND_MAX*(b-a);
}

// Inverse sampling for Box-Muller
double invCDF(double a){
	return - log(1-a);
}

int main() {
	// The user can choose the following parameters:
	// 1. The number of points to sample
	// 2. The mean values mu_x = mu_y = mu of the 2D gaussian
	// 3. The standard deviation sigma_x = sigma_y = sigma of the 2D gaussian
	int n_points;
	double mu;
	double sigma;
	cout << "Welcome. With this program you can sample points from a 2D Gaussian using Box-Muller transformation." << endl;
	cout << "Set the value of mu: ";
	cin >> mu;
	cout << "Set the value of sigma: ";
	cin >> sigma;
	cout << "Please insert the number of points you want to generate: ";
	cin >> n_points;
	string filename = "box-muller_n" + to_string(n_points) + "_mu" + to_string(mu)+ "_sigma" + to_string(sigma) +".txt";
	cout << "Thanks. The sampled (x,y) coordinates will be saved into " << filename << endl;
	ofstream outfile(filename);

    // sampling 
	for (int i = 0; i < n_points; i++) {
		double theta = gen_random(0, 2* M_PI); // theta is in range [0, 2pi]
		double s = invCDF(gen_random(0, 1)); // s is in range [0,1]
		double x = sigma * sqrt(2*s) * cos(theta)+mu;
		double y = sigma * sqrt(2*s) * sin(theta)+mu;
		outfile << x << " " << y << endl;
	}
	outfile.close();
    return 0;
}
