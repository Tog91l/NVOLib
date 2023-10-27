#include <iostream>
#include <vector>
#include <cmath>
#include <filesystem>
#include <fstream>

namespace fs = std::filesystem;

struct Vec {
	double theta;
	double phi;
};
double randomRange(double min, double max) {
	return min + double(rand()) / (double(RAND_MAX) / (max - min));

}

std::vector<Vec> GenRandVec(int size) {
	std::vector<Vec> vectors(size);
	for (int i = 0; i < size; ++i) {
		Vec v;
		v.theta = randomRange(0.0, 2 * std::acos(-1.0));
		v.phi = randomRange(0.0, std::acos(-1.0));
		vectors[i] = v;
	}
	return vectors;
}

void createFile(const std::string& file_name, const std::vector <Vec>& vectors) {
	fs::create_directory(file_name);
	std::string file_path = file_name + "/data.txt";

	std::ofstream file(file_path);
	if (file.is_open()) {
		for (const Vec& v : vectors) {
			file << "(" << v.theta << "," << v.phi << ")" << std::endl;
		}
		file.close();
	}
	else {
		std::cerr << "File creation error" << std::endl;
	}
}

int main() {
	const int size = 10000;
	std::vector<Vec> vectors = GenRandVec(size);
	std::string file_name = "vec_data";

	createFile(file_name, vectors);
	

	return 0;
}
