#pragma once
#include<vector>
#include"../Game.h"
class VectorSortare
{
private:
	int v[101], vectorSize;
	bool crescator;
	sf::Text complexitate;

public:
	VectorSortare();
	void deseneazaVector(Game *game);
	void reset();
	void bubbleSort(Game* game, std::vector<sf::Text> text, sf::RectangleShape linie);
	void insertionSort(Game* game, std::vector<sf::Text> text, sf::RectangleShape linie);
	void selectionSort(Game* game, std::vector<sf::Text> text, sf::RectangleShape linie);
	void mergeSort(Game* game, std::vector<sf::Text> text, sf::RectangleShape linie, int left, int right);
	void merge(Game* game, std::vector<sf::Text> text, sf::RectangleShape linie, int left, int right, int mid);
	void updateVector(Game* game, std::vector<sf::Text> text, sf::RectangleShape linie, int i, int j);
	void setCrescatorStatus(bool status);
	void resetComp();
};
