//
//  main.cpp
//  H - White Knight
//
//  Created by Anirudha Paul on 5/29/15.
//  Copyright (c) 2015 Anirudha Paul. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <string>
#include <string.h>
#include <algorithm>

using namespace std;

char chess_board[1010][1010];
int max_combo[1010][1010];

int maximumCombo(int king_i , int king_j , int row_column);

int main(int argc, const char * argv[])
{
    int input_no;
    
    scanf("%d" , &input_no);
    
    for (int i = 0 ; i < input_no ; i++)
    {
        int king_i = 0 , king_j = 0;
        int row_column;
        
        memset(max_combo, -1 , sizeof(max_combo));
        
        scanf("%d" ,&row_column);
        
        for (int k = 0 ; k < row_column ; k++)
        {
            string input;
            cin >> input;
            
            for (int j = 0 ; j < input.length(); j++)
            {
                if (input[j] == 'K')
                {
                    king_i = k ;
                    king_j = j ;
                }
                chess_board[k][j] = input[j];
            }
        }
        
        
        int result = maximumCombo(king_i, king_j, row_column);
        
        printf("%d\n" ,result);
    }
    return 0;
}

int maximumCombo(int king_i , int king_j , int row_column )
{
    int sum = 0;
    if (king_i < 0 || king_i >= row_column || king_j < 0 || king_j >= row_column)
    {
        return 0;
    }
    
    if (chess_board[king_i][king_j] == 'P')
    {
        sum = sum + 1;
    }
    
    if (max_combo[king_i][king_j] != -1)
    {
        return max_combo[king_i][king_j];
    }
    
    
        int a1 , a2 , a3 , a4   ;
        
        
            a1 = maximumCombo(king_i + 1, king_j + 2,row_column);
            a2 = maximumCombo(king_i + 2 , king_j + 1, row_column);
            a3 = maximumCombo(king_i -1, king_j + 2,row_column);
            a4 = maximumCombo(king_i - 2 , king_j + 1,row_column);
            
            max_combo[king_i] [king_j] = sum + max(max(max(a1, a2),a3),a4);
        
    
    return max_combo[king_i][king_j];
}