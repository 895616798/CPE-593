//
//  Weight_chart_fixed.hpp
//  CPE-593-group_project
//
//  Created by FANXUEZHOU on 16/4/4.
//  Copyright © 2016年 FANXUEZHOU. All rights reserved.
//

#ifndef Weight_chart_fixed_h
#define Weight_chart_fixed_h
#include <vector>
#include "Weight_chart.hpp"
using namespace::std;

class Weight_chart_fixed : public Weight_chart{
private:
    vector<vector<int>> board;
    
public:
    Weight_chart_fixed()
    {
        read();
    }
    
    void read(){
        ifstream infile;
        infile.open("weight.txt");
        if(infile.fail())
            cout<<"open fail!"<<endl;
        board = vector<vector<int>>(8,vector<int>(8,0));
        for(int i=0;i<8;i++)
        {
            string temp;
            getline(infile,temp);
            stringstream x;
            x << temp;
            for(int j=0;j<8;j++)
            {
                int w;
                x >> w;
                board[i][j]=w;
            }
        }
        infile.close();
    }
    
    pair<int, int> getBestPos(const vector<pair<int, int>> &positionList)
    {
        int bestValue = INT_MIN;
        vector<pair<int,int>> candidateList;
        for (int i = 0; i < positionList.size(); ++i) {
            pair<int, int> p = positionList[i];
            int value = board[p.first][p.second];
            if (value > bestValue) {
                bestValue = value;
                candidateList.resize(1);
                candidateList[0] = p;
            } else if (value == bestValue) {
                candidateList.push_back(p);
            }
        }
        
        int randomIndex = arc4random() % candidateList.size();
        pair<int, int> sp = candidateList[randomIndex];
        return sp;
    }
};



#endif /* Weight_chart_fixed_h */
