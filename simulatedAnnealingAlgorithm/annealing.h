#pragma once

//#include <iostream>
//#include <cmath>
//#include <ctime>
//#include <vector>
//
//using namespace std;
//
//void output(vector<vector<int>> weights);
//void annealing(vector<vector<int>> weights, vector<int>& path);
//int allPath(vector<vector<int>> weights, vector<int> path);
//void rand(vector<int>& path);
//void randGraph(vector<vector<int>>& weights);
//
//int main(void)
//{
//	setlocale(LC_ALL, "ru");
//	srand(time(NULL));
//	int n;
//	cout << "Введите количество городов: ";
//	cin >> n;
//	vector<vector<int>> weights(n, vector<int>(n, 0));
//	randGraph(weights);
//	cout << "Расстояния между городами:\n";
//	output(weights);
//	vector<int> path(n);
//	cout << "Введите путь: ";
//	for (int i = 0; i < n; i++)
//	{
//		int k;
//		cin >> k;
//		path[i] = k - 1;
//		cout << " ";
//	}
//	//for (int i = 0; i < 100; i++)
//	//Введите количество итераций
//	annealing(weights, path);
//	cout << "Полученный путь: " << allPath(weights, path) << endl;
//	return 0;
//}
//
//void output(vector<vector<int>> weights)
//{
//	for (int i = 0; i < weights.size(); i++)
//	{
//		for (int j = 0; j < weights.size(); j++)
//		{
//			cout << "[" << i + 1 << "]" << "[" << j + 1 << "]" << " - " << weights[i][j] << "    ";
//		}
//		cout << endl;
//	}
//}
//void annealing(vector<vector<int>> weights, vector<int>& path)
//{
//	float t = 100.0f;
//	float alpha = 0.7f;
//	vector<int> next_path(path);
//	rand(next_path);
//	t *= alpha;
//	vector<int> high_path = next_path;
//	rand(high_path);
//	t *= alpha;
//	int l = allPath(weights, next_path);
//	int next_l = allPath(weights, high_path);
//	while (t >= 0.001f)
//	{
//		if (next_l - l <= 0)
//		{
//			next_path = high_path;
//			l = next_l;
//			rand(high_path);
//			next_l = allPath(weights, high_path);
//		}
//		else if (next_l - l > 0)
//		{
//			float p = 100 * exp(-(float(next_l) - float(l)) / t);
//			int pk = rand() % 100 + 1;
//			if (p > pk)
//			{
//				next_path = high_path;
//				l = next_l;
//				rand(high_path);
//				next_l = allPath(weights, high_path);
//			}
//			else
//			{
//				rand(high_path);
//				next_l = allPath(weights, high_path);
//			}
//		}
//		t *= alpha;
//	}
//	if (allPath(weights, path) > allPath(weights, next_path)) path = next_path;
//	if (allPath(weights, path) > allPath(weights, high_path)) path = high_path;
//}
//int allPath(vector<vector<int>> weights, vector<int> path)
//{
//	int sum = 0;
//
//	int i = 0;
//	while (i < path.size() - 1)
//	{
//		sum += weights[path[i]][path[i + 1]];
//		i++;
//	}
//	sum += weights[path[i]][path[0]];
//
//	return sum;
//}
//void rand(vector<int>& path)
//{
//	int pl1 = rand() % (path.size() - 1) + 1;
//	int pl2 = rand() % (path.size() - 1) + 1;
//	int temp = path[pl1];
//	path[pl1] = path[pl2];
//	path[pl2] = temp;
//}
//void randGraph(vector<vector<int>>& weights)
//{
//	for (int i = 0; i < weights.size(); i++)
//	{
//		for (int j = 0; j < weights.size(); j++)
//		{
//			if (j == i) weights[i][j] = 0;
//			else
//			{
//				weights[i][j] = rand() % 90 + 1;
//				weights[j][i] = weights[i][j];
//			}
//		}
//	}
//}