#ifndef __STOCK__
#define __STOCK__

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

#define MAX_GEN		1400
#define MAX_CLOTH	212
#define MAX_TEXTILE 139
#define MAX_WASHING 7

string* makeListStock(){
	ifstream fCloth("stock_list/clothes.txt");
	ifstream fTextile("stock_list/textile.txt");
	ifstream fWashing("stock_list/washing.txt");
	FILE *fStock = fopen("listOfStock.txt","w");

	string cloth[MAX_CLOTH];
	string textile[MAX_TEXTILE];
	string washing[MAX_WASHING];
	string csize[4] = {"S","M","L","XL"};
	
	srand(time(NULL));		
	fprintf(fStock,"%d\n",MAX_GEN);
	for(int i = 0; i<MAX_CLOTH; i++){
		getline(fCloth,cloth[i]);
	}	
	fCloth.close();

	for(int i = 0; i<MAX_TEXTILE; i++){
		getline(fTextile,textile[i]);
	}
	fTextile.close();

	for(int i = 0; i<MAX_WASHING; i++){
		getline(fWashing,washing[i]);
	}
	fWashing.close();

	string* stockId = new string[MAX_GEN];

	for(int i = 0; i < MAX_GEN; i++){
		string output = cloth[rand()%MAX_CLOTH] + "|" + textile[rand()%MAX_TEXTILE] + "|";
		ostringstream ss;
		int price = (rand()%999+1)*100;
		int stock = rand()%9999+1;
		long long int id = rand()%1000000000000LL;
		char strId[13];
		sprintf(strId, "%012lld", id);

		stockId[i] = string(strId);

		// price
		if(price >= 1000){
			ss << price/1000;
			output = output + ss.str() + ",";
			ss.str("");
			ss.clear();
			if(!(price % 1000))
				output = output + "000";
			else{
				ss << price % 1000;
				output = output + ss.str();
			}
			ss.str("");
			ss.clear();
		}
		else{
			ss << price;
			output = output + ss.str();
			ss.str("");
			ss.clear();
		}
		ss << stock; 
		output = output + "|" + ss.str() + "|" + washing[rand()%MAX_WASHING] + "|" + csize[rand()%4];
		fprintf(fStock,"%s|%s\n", strId,output.c_str());
	}
	return stockId;
}

#endif
