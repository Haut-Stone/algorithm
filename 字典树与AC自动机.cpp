/*
* Created by ShiJiahuan(li) in haut.
* for more please visit www.shallweitalk.com
* 
* Copyright 2017 SJH. All rights reserved.
*
* @Author: Haut-Stone
* @Date:   2017-08-02 14:23:09
* @Last Modified by:   Haut-Stone
* @Last Modified time: 2017-08-03 09:35:18
*/

#include <algorithm>
#include <iostream>
#include <cstdio>
#include <queue>
#define INPUT_TEST freopen("in.txt", "r", stdin)
using namespace std;

const int N = 1000100;
const int ALPHABET_SIZE = 26;

struct Node
{
	// int id;
	int isLast;
	Node* fail;
	Node* children[ALPHABET_SIZE];
	Node(){
		// id = 0;
		isLast = 0;
		fail = NULL;
		for(int i=0;i<ALPHABET_SIZE;i++){
			children[i] = NULL;
		}
	}
};

Node* root;
// int idNumber = 1;

void insert(char pattern[])
{
	Node* current = root;
	int len = (int)strlen(pattern);
	for(int i=0;i<len;i++){
		int tempChar = pattern[i] - 'a';
		if(current->children[tempChar] == NULL){
			current->children[tempChar] = new Node;
			// current->id = idNumber++;
		}
		current = current->children[tempChar];
	}
	(current->isLast)++;
}


void initFailPointer()
{
	Node* fatherFail;
	Node* father;
	Node* son;

	queue<Node* > Q;

	fatherFail = root;
	Q.push(fatherFail);

	while(!Q.empty()){
		father = Q.front();
		Q.pop();
		for(int i=0;i<ALPHABET_SIZE;i++){
			son = father->children[i];
			if(son != NULL){
				if(father == root){
					son->fail = root;
					// printf("%d---->root\n", son->id);
				}else{
					fatherFail = father->fail;
					while(fatherFail != NULL){
						if(fatherFail->children[i] != NULL){
							son->fail = fatherFail->children[i];
							// printf("%d---->%d\n", son->id, fatherFail->children[i]->id);							
							break;
						}
						fatherFail = fatherFail->fail;
					}
					if(fatherFail == NULL){
						son->fail = root;
						// printf("%d---->root\n", son->id);
					}
				}
				Q.push(son);
			}
		}
	}
}

int query(char text[])
{
	Node* current;
	Node* temp;
	int numberOfPatternsInText = 0;
	int textLen = (int)strlen(text);
	current = root;

	for(int i=0;i<textLen;i++){
		int tempChar = text[i] - 'a';
		while(current->children[tempChar] == NULL && current != root){
			current = current->fail;
		}
		current = current->children[tempChar];
		if(current == NULL) current = root;
		temp = current;
		while(temp != root){
			if(temp->isLast >= 0){
				numberOfPatternsInText += temp->isLast;
				temp->isLast = -1;
			}else{
				break;
			}
			temp = temp->fail;
		}
	}
	return numberOfPatternsInText;
}


int main(void)
{
	int T;
	int n;
	char patterns[N];
	char text[N];

	scanf("%d", &T);
	for(int cas=1;cas<=T;cas++){
		root = new Node;
		scanf("%d", &n);
		for(int i=0;i<n;i++){
			scanf("%s", patterns);
			insert(patterns);
		}
		initFailPointer();
		scanf("%s", text);
		int ans = query(text);
		printf("%d\n", ans);
	}
	return 0;
}