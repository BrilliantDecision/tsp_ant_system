#include "graph.h"

//Инициализация объекта
graph::graph()
{
	path = new vector<int>(); //путь
	antPathStandard = new vector<int>(); // путь алгоритма колонии муравьёв
	antPathModify = new vector<int>(); // путь алгоритма градиентного спуска
	points = new vector<vector<int>>(); //массив точек, какая с какой связана
	distances = new vector<vector<double>>(); //массив расстояний между точками
	srand(time(NULL)); //инициализация генератора псевдослучайных чисел
	max_standard = 0;
	max_modify = 0;
}

//Удаление объекта
graph::~graph()
{
	
}

//Алгоритм колонии муравьёв (стандартный)
void graph::ant_algorithm(int it, int a, int b, double minPher, int q, double p, int ant_squad, System::Windows::Forms::ProgressBar^ progressBar1)
{
	vector<vector<double>> pheromone = initial_pheromone(minPher); //феромоны
	vector<int> minimal_path(*path); //задаём начальный путь, это будет самый минимальный путь
	vector<int> minimal_ant_path(*path); // задаём начальный путь для муравьёв
	double minimal_length = allPath(minimal_path); // начальная длина минимального пути
	double minimal_ant_length = allPath(minimal_ant_path); // начальная длина муравьиного пути
	vector<int> last_route(ant_squad); //вектор крайних городов поколений муравьёв
	int i = 0;
	while (i < ant_squad) {
		int j = rand() % n;
		if (std::find(last_route.begin(), last_route.end(), j) != last_route.end()) {
			/* v contains x */
		}
		else {
			/* v does not contain x */
			last_route[i] = j;
			i++;
		}
	}

	for (int i = 0; i < it; i++) {
		for (int ant = 0; ant < ant_squad; ant++) {
			vector<int> allowed_cities(*path); // множество непосещённых вершин
			int j = last_route[ant];
			vector<int> ant_path;
			ant_path.push_back(j);
			// идём по доступным вершинам графа
			for (int j1 = 0; j1 < n - 2; j1++) {
				allowed_cities.erase(std::remove(allowed_cities.begin(), allowed_cities.end(), j), allowed_cities.end());
				vector<double> values;
				double sum = 0.0;
				//вычисляем сумму по формуле
				for (auto s = allowed_cities.begin(); s != allowed_cities.end(); ++s) {
					double value = pow(1.0 / (*distances)[j][*s], b) * pow(pheromone[j][*s], a);
					sum += value;
					values.push_back(value);
				}
				vector<double> begin_v;
				vector<double> end_v;
				double c = 0.0;
				int i = 0;
				for (auto s = allowed_cities.begin(); s != allowed_cities.end(); ++s) {
					begin_v.push_back(c);
					c += values[i] / sum;
					end_v.push_back(c);
					i++;
				}
				bool o = true;
				double vera = rand() % 100;
				vera /= 101.0;
				i = 0;
				while (o && i != allowed_cities.size())
				{
					if (begin_v[i] <= vera && end_v[i] >= vera)
					{
						j = allowed_cities[i];
						o = false;
					}
					i++;
				}
				ant_path.push_back(j);
			}
			allowed_cities.erase(std::remove(allowed_cities.begin(), allowed_cities.end(), j), allowed_cities.end());
			ant_path.push_back(allowed_cities[0]);
			last_route[ant] = ant_path[n - 1];

			//сравниваем пути
			if (allPath(ant_path) < minimal_ant_length) {
				minimal_ant_path = vector<int>(ant_path);
				minimal_ant_length = allPath(ant_path);
			}

			//обновляем феромоны
			double l0 = allPath(ant_path);
			double d_tao = q / l0;
			vector<int>::iterator s = ant_path.begin();
			while (s != ant_path.end() - 1)
			{
				pheromone[*s][*(s + 1)] += q / l0;
				pheromone[*(s + 1)][*s] += q / l0;
				++s;
			}
			pheromone[*s][ant_path[0]] += q / l0;
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (i != j) {
					if (pheromone[i][j] > 0.000000000000001 || pheromone[j][i] > 0.000000000000001)
					{
						pheromone[i][j] *= (1 - p);
						pheromone[j][i] *= (1 - p);
					}
				}
			}
		}

		if (minimal_ant_length < minimal_length) {
			minimal_path = vector<int>(minimal_ant_path);
			minimal_length = minimal_ant_length;
		}
		progressBar1->Value += progressBar1->Step;
	}
	(*antPathStandard) = minimal_path;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (pheromone[i][j] > max_standard && i != j) max_standard = pheromone[i][j];
		}
	}
}

//Алгоритм колонии муравьёв (модифицированный)
void graph::ant_algorithm(int it, int a, int b, double minPher, int q, double p, int ant_squad, int elite_ants, double maxPher, System::Windows::Forms::ProgressBar^ progressBar1)
{
	vector<int> elite_list = initial_elite_ants(elite_ants, ant_squad);
	vector<vector<double>> pheromone = initial_pheromone(minPher); //феромоны
	vector<int> minimal_ant_path(*path); // задаём начальный путь для муравьёв
	double minimal_ant_length = allPath(minimal_ant_path); // начальная длина муравьиного пути
	vector<int> last_route(ant_squad); //вектор крайних городов поколений муравьёв
	int i = 0;
	while (i < ant_squad) {
		int j = rand() % n;
		if (std::find(last_route.begin(), last_route.end(), j) != last_route.end()) {
			/* v contains x */
		}
		else {
			/* v does not contain x */
			last_route[i] = j;
			i++;
		}
	}

	for (int i = 0; i < it; i++) {
		for (int ant = 0; ant < ant_squad; ant++) {
			vector<int> allowed_cities(*path); // множество непосещённых вершин
			int j = last_route[ant];
			vector<int> ant_path;
			ant_path.push_back(j);
			bool o = true;
			if (elite_list[ant] == 1) o = false;
			// идём по доступным вершинам графа
			for (int j1 = 0; j1 < n - 2; j1++) {
				allowed_cities.erase(std::remove(allowed_cities.begin(), allowed_cities.end(), j), allowed_cities.end());
				vector<double> values;
				double sum = 0.0;
				//вычисляем сумму по формуле
				for (auto s = allowed_cities.begin(); s != allowed_cities.end(); ++s) {
					double value = pow(1.0 / (*distances)[j][*s], b) * pow(pheromone[j][*s], a);
					sum += value;
					values.push_back(value);
				}
				vector<double> begin_v;
				vector<double> end_v;
				double c = 0.0;
				int i = 0;
				for (auto s = allowed_cities.begin(); s != allowed_cities.end(); ++s) {
					begin_v.push_back(c);
					c += values[i] / sum;
					end_v.push_back(c);
					i++;
				}
				bool o = true;
				double vera = rand() % 100;
				vera /= 101.0;
				i = 0;
				while (o && i != allowed_cities.size())
				{
					if (begin_v[i] <= vera && end_v[i] >= vera)
					{
						j = allowed_cities[i];
						o = false;
					}
					i++;
				}
				ant_path.push_back(j);
			}
			allowed_cities.erase(std::remove(allowed_cities.begin(), allowed_cities.end(), j), allowed_cities.end());
			ant_path.push_back(allowed_cities[0]);
			last_route[ant] = ant_path[n - 1];

			//сравниваем пути
			if (allPath(ant_path) < minimal_ant_length) {
				minimal_ant_path = vector<int>(ant_path);
				minimal_ant_length = allPath(ant_path);
			}

			//обновляем феромоны
			double l0;
			double d_tao;
			vector<int> destiny_path(n);

			if (!o) destiny_path = vector<int>(minimal_ant_path);
			else destiny_path = vector<int>(ant_path);

			l0 = allPath(destiny_path);
			d_tao = q / l0;

			vector<int>::iterator s = destiny_path.begin();
			while (s != destiny_path.end() - 1)
			{
				if (pheromone[*s][*(s + 1)] < maxPher || pheromone[*(s + 1)][*s] < maxPher)
				{
					pheromone[*s][*(s + 1)] += q / l0;
					pheromone[*(s + 1)][*s] += q / l0;
				}
				++s;
			}
			if (pheromone[*s][destiny_path[0]] < maxPher || pheromone[destiny_path[0]][*s] < maxPher)
			{
				if (!o) pheromone[*s][destiny_path[0]] += q / l0;
				else pheromone[*s][destiny_path[0]] += q / l0;
			}

		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (i != j) {
					if (pheromone[i][j] <= minPher || pheromone[j][i] <= minPher)
					{
						pheromone[i][j] = minPher;
						pheromone[j][i] = minPher;
					}
					else 
					{
						pheromone[i][j] *= (1 - p);
						pheromone[j][i] *= (1 - p);
					}
				}
			}
		}
		progressBar1->Value += progressBar1->Step;
	}
	(*antPathModify) = minimal_ant_path;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (pheromone[i][j] > max_modify && i != j) max_modify = pheromone[i][j];
		}
	}
}



//функция расставляет начальные феромоны на точках
vector<vector<double>> graph::initial_pheromone(double minPhen)
{
	vector<vector<double>> pheromone(n, vector<double>(n));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i != j) {
				pheromone[i][j] = minPhen;
			}
		}
	}
	return pheromone;
}

//функция расставляет элитных муравьёв на точках
vector<int> graph::initial_elite_ants(int eliteAnt, int ant_squad) {
	vector<int> eliteAnts(ant_squad);
	int i = 0;
	while (i < eliteAnt) {
		int j = rand() % ant_squad;
		if (eliteAnts[j] == 0) {
			eliteAnts[j] = 1;
			i++;
		}
	}
	return eliteAnts;
}

void graph::randPath(vector<int>& path)
{
	int pl1 = rand() % n;
	int pl2 = rand() % n;
	vector<int> helper;
	auto itpl1 = find(path.begin(), path.end(), pl1);
	auto itpl2 = find(path.begin(), path.end(), pl2);
	if (itpl1 > itpl2)
	{
		for (auto i = itpl2; i < itpl1 + 1; ++i)
		{
			helper.push_back(*i);
		}
		reverse(helper.begin(), helper.end());
		int j = 0;
		for (auto i = itpl2; i < itpl1 + 1; ++i)
		{
			*i = helper[j];
			j++;
		}
	}
	else if (itpl2 > itpl1)
	{
		for (auto i = itpl1; i < itpl2 + 1; ++i)
		{
			helper.push_back(*i);
		}
		reverse(helper.begin(), helper.end());
		int j = 0;
		for (auto i = itpl1; i < itpl2 + 1; ++i)
		{
			*i = helper[j];
			j++;
		}
	}
}


//Добавляет вершину
void graph::addVertex(vector<int> point)
{
	(*points).push_back(point);
}

vector<int> graph::getPath(int i)
{
	if (i == 0) return *antPathStandard;
	else if (i == 1) return *antPathModify;
}

void graph::setDistances()
{
	int n = points->size();
	for (int i = 0; i < n; i++)
	{
		vector<double> temp;
		int x2 = (*points)[i][0];
		int y2 = (*points)[i][1];
		for (int j = 0; j < n; j++)
		{
			int x1 = (*points)[j][0];
			int y1 = (*points)[j][1];
			double distance = sqrt((double)(x2 - x1) * (x2 - x1) + (double)(y2 - y1) * (y2 - y1));
			temp.push_back(distance);
		}
		(*distances).push_back(temp);
	}
	distances->resize(distances->size());
}

//Возвращает координаты вершины графа
vector<int> graph::getPoint(int i)
{
	return (*points)[i];
}

vector<vector<int>> graph::getPoints()
{
	return (*points);
}

vector<vector<double>> graph::getDistances()
{
	return (*distances);
}

//Считает длину маршрута
double graph::allPath(vector<int> path)
{
	double sum = 0;
	int  k = 0;
	while (k < n - 1)
	{
		sum += (*distances)[path[k]][path[k + 1]];
		k++;
	}
	sum += (*distances)[path[n - 1]][path[0]];
	return sum;
}

//Возвращает количество вершин графа
int graph::getSizePoints()
{
	return points->size();
}

void graph::setPoints(vector<vector<int>> points)
{
	(*this->points) = points;
}

void graph::sortPointsByPath(vector<int> path)
{
	vector<vector<int>> tempPoints(*points);
	for (int i = 0; i < getSizePoints(); i++)
	{
		int ind = path[i];
		(*points)[i] = tempPoints[ind];
	}
}

void graph::setRandomGraph()
{
	int x, y;
	x = rand() % 1300 + 10;
	y = rand() % 500 + 10;
	addVertex({ x, y });
	for (int i = 0; i < n - 1; i++)
	{
		x = rand() % 1300 + 10;
		y = rand() % 500 + 10;
		int j = 0;
		while (j < getSizePoints())
		{
			if ((abs((*points)[j][0] - x) < 2) && (abs((*points)[j][1] == y) < 2))
			{
				x = rand() % 1300 + 10;
				y = rand() % 500 + 10;
				j = -1;
			}
			j++;
		}
		addVertex({ x, y });
	}
}

void graph::setN(int n)
{
	this->n = n;
}

void graph::setAllPaths(vector<int> path)
{
	*this->path = vector<int>(path);
}

void graph::clearAllPath()
{
	path->clear();
}

void graph::clearAll()
{
	path->clear();
	points->clear();
	distances->clear();
	path = new vector<int>();
	points = new vector<vector<int>>();
	distances = new vector<vector<double>>();
}

void graph::clearPoints()
{
	points->clear();
}

void graph::clearDistances()
{
	distances->clear();
	distances = new vector<vector<double>>();
}

void graph::clearMax() 
{
	max_standard = 0;
	max_modify = 0;
}

double graph::get_max(int i) 
{
	if (i == 0) return max_standard;
	if (i == 1) return max_modify;
}
