#include <iostream>
#include <random>
#include <cmath>
#include <fstream>

using namespace std;

// Function to generate a random number between a and b
double gen_random(double a, double b) {
    return a+(float)rand() / RAND_MAX*(b-a);
}

int main() {
	// The user can choose the following parameters:
	// 1. Calculate the area of a rectangle (0) or a circle (1)
	// 2. The number of throws
    int n_throws;
	int choice;
	double a;
	double b;
	double c;
	double d;
	double r;
	double alpha;
	double beta;
	cout << "Welcome. With this program you can calculate the area of a rectangle or a circle using Monte Carlo method." << endl;
	cout << "Digit 0 for the rectangle or 1 for the circle: ";
	cin >> choice;
	if (choice != 0 && choice != 1){
		cerr << "You should instert either 0 or 1" << endl;
		return 1;
	}
	cout << "Please insert the parameters values." << endl;
	// The parameters are a,b,c,d for the rectangle while alpha, beta, r for the circle 
	if (choice == 0){
		cout << "Insert a: ";
		cin >> a;
		cout << "Insert b: ";
		cin >> b;
		if (a > b) {
			cerr << "a should be smaller than b!" << endl;
			return 1;
		}
		cout << "Insert c: ";
		cin >> c;
		cout << "Insert d: ";
		cin >> d;
		if (c > d) {
			cerr << "c should be smaller than d!" << endl;
			return 1;
		}
	}
	if (choice == 1){
		cout << "Insert alpha: ";
		cin >> alpha;
		cout << "Insert beta: ";
		cin >> beta;
		cout << "Insert the radius: ";
		cin >> r;
		if (r < 0) {
			cerr << "r should be positive!" << endl;
			return 1;
		}
	}
    cout << "Enter the number of throws: ";
    cin >> n_throws;
    if (n_throws <= 0) {
        cerr << "Number of throws must be a positive integer." << endl;
        return 1;
    }
	string filein = "type" + to_string(choice) + "_in" + to_string(n_throws) + ".txt";
	string fileout = "type" + to_string(choice) + "_out" + to_string(n_throws) + ".txt";
	cout << "Thanks. The hit points will be saved into " << filein << " while the missed ones into " << fileout << endl;
	
	// Open files for writing
    ofstream outputin(filein);
	ofstream outputout(fileout);

    int n_hits = 0;
	double exp_area = 0.0;
	double th_area = 0.0;
	// Monte Carlo for the area of a Rectangle 
	if (choice == 0){
		for (int i = 0; i < n_throws; i++) {
			double x = gen_random(a, b);
			double y = gen_random(c, d);

			if (x >= a && x <= b && y >= c && y <= d) {
				n_hits++;
				outputin << x << " " << y << endl;
			}
			else {
				outputout << x << " " << y << endl;
			}
    }
		double ratio = static_cast<double>(n_hits) / n_throws;
		exp_area = (b - a) * (d - c) * ratio;
		th_area = (b - a) * (d - c);
	}
	// Monte Carlo for the area of a Circle 
	if (choice == 1) {
		for (int i = 0; i < n_throws; i++) {
			a = alpha - r; 
			c = beta - r;
			b = alpha + r; 
			d = beta + r;
			double x = gen_random(a,b);
			double y = gen_random(c,d);

			if (sqrt(pow((x-alpha),2)+pow((y-beta),2)) <= r) {
				n_hits++;
				outputin << x << " " << y << endl;
			}
			else {
				outputout << x << " " << y << endl;
			}
		}
		double ratio = static_cast<double>(n_hits) / n_throws;
		exp_area = (b - a) * (d - c) * ratio;
		th_area = pow(r,2) * M_PI;
	}
	outputin.close();
	outputout.close();

    cout << "Estimated Area: " << exp_area << endl;
    cout << "Analytic Area: " << th_area << endl;
    cout << "% Error: " << abs(exp_area - th_area)/th_area * 100 << endl;

    return 0;
}

