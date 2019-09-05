#pragma once
struct Node {
	int value;
	Node* next;

	Node(int i) : value(i), next(nullptr) {}
	Node() : value(0), next(nullptr) {}
};