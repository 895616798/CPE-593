//
//  Player_awesome.hpp
//  CPE-593-group_project
//
//  Created by FANXUEZHOU on 16/4/4.
//  Copyright © 2016年 FANXUEZHOU. All rights reserved.
//

#ifndef Player_awesome_h
#define Player_awesome_h
#include "Weight_chart.hpp"

class Player_awesome:public Player{
private:
    vector<vector<int>> status;
    vector<pair<int,int>> optionPosition;
    bool turn;
    Weight_chart *weightChart;
public:
    Player_awesome(Weight_chart *wc){
        name="awesome_player";
        weightChart = wc;
    }
    void getSituation(const vector<vector<int>>&stat,bool t)
    {
        turn=t;
        status=stat;
        
    }
    pair<int,int> chosePosition()
    {
        return weightChart->getBestPos(optionPosition);
    }
    string getName(){
        return name;
    }
    void findOption(const vector<pair<int,int>> &OP)
    {
        optionPosition=OP;
    }
};


#endif /* Player_awesome_h */
