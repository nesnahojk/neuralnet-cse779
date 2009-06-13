/* 
 * File:   NeuralNetwork.h
 * Author: johank
 *
 * Created on February 14, 2009, 12:44 PM
 */

#ifndef _NEURALNETWORK_H
#define	_NEURALNETWORK_H
#include <vector>
#include <cmath>
#include <stdlib.h>

/*
 * A single neuron
 */
struct Node
{
    double a;
    double * weights; //incoming weights
    double * weights_change_lag; //for momentum
    double bias_weight;
    double bias_weight_change_lag; //for momentum
    double delta;
    double in;
};

/*
 * A single layer
 */
struct Layer
{
    int num_nodes;
    Node * nodes;
};


class sigmoid
{
 public:
  double operator()(double t)
  {
    return 1 / (1 + exp(-t));
  }
};

class sigmoid_prime
{
 public:
  double operator()(double t)
  {
    return t *(1-t);
  }
};




template <class ACT=sigmoid, class ACTP=sigmoid_prime>
class NeuralNetwork
{
private:

    int num_input, num_per_hidden, num_output, num_layers;
    double eta, alpha;
    std::vector<std::vector<double> > x;
    std::vector<std::vector<double> > y;
    double InitWeight(double a, double b);
    double sigmoid(double t);
    double sigmoid_prime(double t);
    void ReorderExamples();
    void ForwardPass(std::vector<double>);
    ACT activation;
    ACTP activation_prime;
    

public:
    Layer * layers;
    NeuralNetwork(int num_input, int num_per_hidden, int num_output, int num_layers, double eta = .5, double alpha = 0);
    virtual ~NeuralNetwork();
    void AddData(std::vector<std::vector<double> > &x,std::vector<std::vector<double> > &y);
    bool IsConverged(double tol = .05);
    std::vector<double> Predict(std::vector<double> x);
    void BackPropLearn();

};



#include "NeuralNetwork.impl"



#endif	/* _NEURALNETWORK_H */


