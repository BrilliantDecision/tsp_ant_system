#pragma once
#include <algorithm>
#include <vector>
#include <omp.h>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <set> 

using namespace std;

public ref class graph
{
private:
	int n;
	double max_standard;
	double max_modify;
	vector<int>* path;
	vector<int>* antPathStandard;
	vector<int>* antPathModify;
	vector<vector<int>>* points;
	vector<vector<double>>* distances;

public:
	graph();
	~graph();

	//алгоритм колонии муравьёв (стандартный)
	void ant_algorithm(int it, int a, int b, double minPher, int q, double p, int ant_squad, System::Windows::Forms::ProgressBar^ progressBar1);

	//алгоритм колонии муравьёв (модифицированный)
	void ant_algorithm(int it, int a, int b, double minPher, int q, double p, int ant_squad, int elite_ants, double maxPher, System::Windows::Forms::ProgressBar^ progressBar1);

	//функция расставляет начальные феромоны на точках
	vector<vector<double>> initial_pheromone(double minPhen);

	//функция расставляет элитных муравьёв на точках
	vector<int> initial_elite_ants(int eliteAnt, int ant_squad);

	vector<int> getPath(int i);
	void randPath(vector<int>& path);
	void addVertex(vector<int> point);
	vector<int> getPoint(int i);
	vector<vector<int>> getPoints();
	vector<vector<double>> getDistances();
	double allPath(vector<int> path);
	void setDistances();
	int getSizePoints();
	void setPoints(vector<vector<int>> points);
	void setAllPaths(vector<int> path);
	void setRandomGraph();
	void setN(int n);
	void sortPointsByPath(vector<int> path);
	void clearAllPath();
	void clearAll();
	void clearPoints();
	void clearDistances();
	void clearMax();
	double get_max(int i);
};
