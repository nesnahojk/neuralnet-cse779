/* 
 * File:   main.cpp
 * Author: johank
 * Neural Network Class and test
 * Created on February 7, 2009, 12:51 PM
 */

#include <stdlib.h>
#include <iostream>
#include <cmath>
#include <vector>
#include "NeuralNetwork.h"
using namespace std;


int main(int argc, char** argv) {

    double alpha=0.0;
    if(argc>1)
    {
        alpha=atof(argv[1]);
    }
    double x [16][4];
    double y [16][1];


    //Define the patterns
    for(int i=0;i<4;i++)
    {
        int cut=16/pow(2,i+1);
        int cc=0;
        while(cc<16)
        {
            for(int j=0;j<cut;j++)
            {
                x[cc+j][i]=1.0;
            }
            cc+=cut;
            for(int j=0;j<cut;j++)
            {
                x[cc+j][i]=0.0;
            }
            cc+=cut;
        }
    }

    //Get the class label
    for(int i=0;i<16;i++)
    {
        double sum=0;
        for(int j=0;j<4;j++)
        {
            sum+=x[i][j];
        }
        if((int)sum%2==0)
        {
            y[i][0]=0.0;
        }
        else
        {
            y[i][0]=1.0;
        }
    }
    y[0][0]=0.0;
    
    vector<vector<double> > vecx;
    vector<vector<double> > vecy;


    //put the data into vectors
    for(int i=0;i<16;i++)
    {
        vector<double> temp;
        for(int j=0;j<4;j++)
        {
            temp.push_back(x[i][j]);
        }
        vector<double> ty;
        ty.push_back(y[i][0]);
        vecx.push_back(temp);
        vecy.push_back(ty);
    }

    //set alpha here
    

    //loop over all possible values of eta
    for(int i=0;i<4;i++)
    {
        double eta=.05*i+.05;

        NeuralNetwork<sigmoid,sigmoid_prime> np(4,4,1,3,eta,alpha);
        np.AddData(vecx,vecy);

        int epochs_req_converge=0;
        while(!np.IsConverged())
        {
            epochs_req_converge++;
            np.BackPropLearn();
        }
        printf("%.2f,%d\n",eta,epochs_req_converge);
    }
 
    return (EXIT_SUCCESS);
}















