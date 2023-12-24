#include <random>
#include<SFML/Graphics.hpp>
#include <ctime>
#include<iostream>
#include<vector>
#include"VectorSortare.h"
using namespace std;

VectorSortare::VectorSortare()
{
	vectorSize = 39;
	crescator = true;
	complexitate.setCharacterSize(40);
	complexitate.setFillColor(sf::Color::White);
	
	complexitate.setPosition(30, 80);
	complexitate.setString("");
	reset();
}

void VectorSortare::deseneazaVector(Game* game)
{
	complexitate.setFont(game->font);
	game->window.draw(complexitate);

	for (size_t i = 0; i < vectorSize; ++i) {
		sf::RectangleShape rect(sf::Vector2f(20, v[i] * 5));
		rect.setPosition(i * 30 + 20, 795 - v[i] * 5);
		game->window.draw(rect);
	}

	
}

void VectorSortare::reset() {
	complexitate.setString("");
	srand(static_cast<unsigned int>(time(0)));
	for (int i = 0; i < vectorSize; i++)
	{
		v[i] = rand() % 100 + 10;
	}
}

void VectorSortare::bubbleSort(Game *game, vector<sf::Text> text, sf::RectangleShape linie) {

	complexitate.setString("Complexitate: O(n^2)");
	
	for (int i = 0; i < vectorSize - 1; ++i) {
		for (int j = 0; j < vectorSize - i - 1; ++j) {
			if (crescator)
			{
				if (v[j] > v[j + 1]) {
					swap(v[j], v[j + 1]);

					//sterge de pe ecran si actualizeaza vectorul
					updateVector(game, text, linie, i, j+1);
					sf::sleep(sf::milliseconds(10));
				}
			}
			else {
				if (v[j] < v[j + 1]) {
					swap(v[j], v[j + 1]);
					updateVector(game, text, linie, i, j+1);
					sf::sleep(sf::milliseconds(10));
				}
			}
		}
	}

}

void VectorSortare::insertionSort(Game* game, std::vector<sf::Text> text, sf::RectangleShape linie) {
	int i, key, j;
	complexitate.setString("Complexitate: O(n^2)");
	for (i = 1; i < vectorSize; i++) {
		key = v[i];
		j = i - 1;
		if (crescator) {
			while (j >= 0 && v[j] > key) {
				v[j + 1] = v[j];
				updateVector(game, text, linie, j, j + 1);
				sf::sleep(sf::milliseconds(20));
				j = j - 1;
			}
		}
		else {
			while (j >= 0 && v[j] < key) {
				v[j + 1] = v[j];
				updateVector(game, text, linie, j, j + 1);
				sf::sleep(sf::milliseconds(20));
				j = j - 1;
			}
		}
		v[j + 1] = key;
	}
}

void VectorSortare::selectionSort(Game* game, std::vector<sf::Text> text, sf::RectangleShape linie) {
	complexitate.setString("Complexitate: O(n^2)");
	int i, j, minIndx;
	for (i = 0; i < vectorSize - 1; i++) {
		minIndx = i;
		for (j = i + 1; j < vectorSize; j++) {
			if (crescator) {
				if (v[j] < v[minIndx])
					minIndx = j;
			}
			else {
				if (v[j] > v[minIndx])
					minIndx = j;
			}
		}
		if (minIndx != i) {
			swap(v[minIndx], v[i]);
			updateVector(game, text, linie, i, minIndx);
			sf::sleep(sf::milliseconds(40));
		}
	}
}

void VectorSortare::mergeSort(Game* game, std::vector<sf::Text> text, sf::RectangleShape linie, int left, int right) {
	complexitate.setString("Complexitate: O(n*log(n))");
	if (left < right) {
		int mid = (left + right) / 2;
		mergeSort(game, text, linie, left, mid);
		mergeSort(game, text, linie, mid + 1, right);

		merge(game, text, linie, left, right, mid);
	}

}

void VectorSortare::merge(Game* game, std::vector<sf::Text> text, sf::RectangleShape linie, int left, int right, int mid) {
	int n1 = mid - left + 1;
	int n2 = right - mid;

	int leftArr[100];
	int rightArr[100];

	for (int i = 0; i < n1; i++)
		leftArr[i] = v[left + i];
	for (int j = 0; j < n2; j++)
		rightArr[j] = v[mid + 1 + j];

	int i = 0;  // Initial index of first subarray
	int j = 0;  // Initial index of second subarray
	int k = left;

	while (i < n1 && j < n2) {
		if (crescator) {
			if (leftArr[i] <= rightArr[j]) {
				v[k] = leftArr[i];
				updateVector(game, text, linie, i, k);
				sf::sleep(sf::milliseconds(40));
				i++;
			}
			else {
				v[k] = rightArr[j];
				updateVector(game, text, linie, j, k);
				sf::sleep(sf::milliseconds(40));
				j++;
			}
		}
		else {
			if (leftArr[i] >= rightArr[j]) {
				v[k] = leftArr[i];
				updateVector(game, text, linie, i, k);
				sf::sleep(sf::milliseconds(40));
				i++;
			}
			else {
				v[k] = rightArr[j];
				updateVector(game, text, linie, j, k);
				sf::sleep(sf::milliseconds(40));
				j++;
			}
		}
		k++;
	}

	while (i < n1) {
		v[k] = leftArr[i];
		updateVector(game, text, linie, i, k);
		sf::sleep(sf::milliseconds(40));
		i++;
		k++;
	}

	while (j < n2) {
		v[k] = rightArr[j];
		updateVector(game, text, linie, j, k);
		sf::sleep(sf::milliseconds(40));
		j++;
		k++;
	}
}

void VectorSortare::updateVector(Game* game, std::vector<sf::Text> text, sf::RectangleShape linie,int i, int j)
{

	game->window.clear(sf::Color(161, 161, 161));

	for (int l = 0; l < vectorSize; ++l) {
		sf::RectangleShape rect(sf::Vector2f(20, v[l] * 5));
		if (l == i)
		{
			rect.setFillColor(sf::Color::Red);
		}
		else if (l == j ) {
			rect.setFillColor(sf::Color::Cyan);
		}
		else {
			rect.setFillColor(sf::Color::White);
		}
		rect.setPosition(l * 30 + 20, 795 - v[l] * 5);
		game->window.draw(rect);
	}

	for (int k = 0; k < text.size(); k++)
		game->window.draw(text[k]);
	game->window.draw(complexitate);
	game->window.draw(linie);

	game->window.display();
}

void VectorSortare::setCrescatorStatus(bool status)
{
	crescator = status;
}

void VectorSortare::resetComp() {
	complexitate.setString("");
}