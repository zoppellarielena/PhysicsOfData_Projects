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

int main() {
	// The user can choose the following parameters:
	// 1. the number of throws
	// 2. the mode: 0 for the uncorrect version (sampling from a non constant pdf f(r)=r) or 1 for the correct version (sampling uniformly)
	int n_points;
	int choice;
	cout << "Welcome. With this program you can sample points uniformly within a unitary disk." << endl;
	cout << "Do you want to run the wrong (0) or correct (1) version? ";
	cin >> choice;
	cout << "Please insert the number of points you want to generate: ";
	cin >> n_points;
	string filename = "unit_disk" + to_string(n_points) + "_" +  to_string(choice) + ".txt";
	cout << "Thanks. The sampled (x,y) coordinates will be saved into " << filename << endl;
	ofstream outfile(filename);
    // sampling 
	for (int i = 0; i < n_points; i++) {
		double r = 0.0;
		if (choice == 0)
			r = gen_random(); // radius randomly generated between 0 and 1
		if (choice == 1)
			r = sqrt(gen_random()); // correct radius
		double chi = gen_random();
		double theta = 2*M_PI*chi;
		double x = r * cos(theta);
		double y = r * sin(theta);
		outfile << x << " " << y << endl;
	}
	outfile.close();
    return 0;
}
