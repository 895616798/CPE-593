//
//  Weight_chart.hpp
//  CPE-593-group_project
//
//  Created by FANXUEZHOU on 16/4/4.
//  Copyright © 2016年 FANXUEZHOU. All rights reserved.
//

#ifndef Weight_chart_h
#define Weight_chart_h
#include <vector>

using namespace::std;

class Weight_chart {
    
public:
    Weight_chart()
    {
        
    }
    
    virtual pair<int, int> getBestPos(const vector<pair<int, int>> &positionList) = 0;
};

#endif /* Weight_chart_h */
