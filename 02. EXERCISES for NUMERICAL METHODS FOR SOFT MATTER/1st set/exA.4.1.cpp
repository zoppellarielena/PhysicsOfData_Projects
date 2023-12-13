#include <iostream>
#include <fstream>
#include <string>
#include <random>
#include <cmath>

using namespace std;

// Function to generate a random number between 0 and 1
double gen_random() {
    return static_cast<double>(rand()) / RAND_MAX;
}

double f(double x) {
    return exp(-pow(x, 2)) * pow(x,1);
}

double g(double x) {
    return pow(x,1);
}


int main() {
	// The user can choose:
	// 1. The method
	// 2. The number of points
    int n_points;
    int choice;
    double c;
    cout << "Welcome. With this program you can compute an integral using crude Monte Carlo (0) or importance sampling (1)" << endl;
    cout << "Make your choice: ";
    cin >> choice;
    cout << "Please insert the number of points you want to generate: ";
    cin >> n_points;
    string filename = "int_n" + to_string(n_points) + "_mode" + to_string(choice) + ".txt";
	default_random_engine generator;
	normal_distribution<double> distribution(0.0,1/sqrt(2));
    ofstream outfile(filename);
    double f_all = 0.0;

    // Sampling
    if (choice == 0)
        c = 100;
    if (choice == 1)
        c = sqrt(M_PI)/2;

    for (int i = 0; i < n_points; i++) {
        if (choice == 0) {
            double chi = c * gen_random();
            double x = f(chi);
            outfile << chi << " " << x << endl;
            f_all += x;
        }
        if (choice == 1) {
			
            double chi = abs(distribution(generator)); // Since we are considering the half gaussian distribution in [0, +inf]
			double x = g(chi);
			outfile << chi << " " << x << endl;
			f_all += x;
			
        }
    }
    double I = c * f_all / n_points;
    outfile.close();
    cout << "The integral result is: " << I << endl;
    return 0;
}
