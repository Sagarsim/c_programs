#include <vector>
#include <iostream>
#include <cstdlib>
#include <cassert>
#include <cmath>

using namespace std;

struct Connection {
    double weight;
    double deltaWeight;
};

class Neuron;
typedef vector<Neuron> Layer;

class Neuron{
    public:
        Neuron(unsigned numOutputs, unsigned myIndex);
        void setOutputVals(double val) { n_outputVals = val; }
        double getOutputVal(void) const { return n_outputVals; }
        void feedForward(const Layer &prevLayer);
        void calcOutputGradients(double targetVals);
        void calcHiddenGradients(const Layer &nextLayer);
        void updateInputWeights(Layer &prevLayer);

    private:
        static double eta; //overall net learning rate [0.0...1.0]
        static double alpha; //momentum
        static double activationFunction(double x);
        static double activationFunctionDerivative(double x);
        static double randomWeight(void){ return rand() / double(RAND_MAX); }
        double sumDOW(const Layer &nextLayer) const;
        double n_outputVals;
        vector<Connection> n_outputWeights;
        unsigned n_myIndex;
        double n_gradient;
};

double Neuron::eta = 0.15;
double Neuron::alpha = 0.5;

void Neuron::calcOutputGradients(double targetVals){
    double delta = targetVals - n_outputVals;
    n_gradient = delta * Neuron::activationFunctionDerivative(n_outputVals);
}

void Neuron::calcHiddenGradients(const Layer &nextLayer){
    double dow = sumDOW(nextLayer);
    n_gradient = dow * Neuron::activationFunctionDerivative(n_outputVals);
}

double Neuron::sumDOW(const Layer &nextLayer) const {
    double sum = 0.0;

    for(unsigned n = 0;n < nextLayer.size() - 1; ++n){
        sum += n_outputWeights[n].weight * nextLayer[n].n_gradient;
    }

    return sum;
}

void Neuron::updateInputWeights(Layer &prevLayer){
    for (unsigned n = 0; n < prevLayer.size(); ++n){
        Neuron &neuron = prevLayer[n];
        double oltDeltaWeight = neuron.n_outputWeights[n_myIndex].deltaWeight;

        double newDeltaWeight = 

            eta
            *neuron.getOutputVal()
            *n_gradient

            +alpha
            *oltDeltaWeight;

        neuron.n_outputWeights[n_myIndex].deltaWeight = newDeltaWeight;
        neuron.n_outputWeights[n_myIndex].weight += newDeltaWeight;
    }
}

Neuron::Neuron(unsigned numOutputs, unsigned myIndex){
    for(unsigned c = 0;c < numOutputs; ++c){
        n_outputWeights.push_back(Connection());
        n_outputWeights.back().weight = randomWeight(); 
    }

    n_myIndex = myIndex;
}

void Neuron::feedForward(const Layer &prevLayer){
    double sum = 0.0;

    for(unsigned n = 0; n < prevLayer.size(); ++n){
        sum += prevLayer[n].getOutputVal() * 
                prevLayer[n].n_outputWeights[n_myIndex].weight;
    }

    n_outputVals = Neuron::activationFunction(sum);
}

double Neuron::activationFunction(double x){

    return tanh(x);
}

double Neuron::activationFunctionDerivative(double x){
    //Approximate derivative of tanh 
    double 1.0 - x * x;
}

class Net
{
    public: 
    Net(const vector<unsigned> &topology);
    void feedForward(const vector<double> &inputVals) {};
    void backProp(const vector<double> &targetVals) {};
    void getResults(vector<double> &resultsVals) const {};

    private:
    vector<Layer> n_layers; //n_layers[layerNum][neuronNum]
    double n_error;
    double n_recentAverageError;
    double n_recentAverageSmoothingFactor;
};

Net::Net(const vector<unsigned> &topology){
    unsigned numLayers = topology.size();
    //For creating layers
    for(unsigned layerNum = 0; layerNum < numLayers; ++layerNum) {
        n_layers.push_back(Layer());
        unsigned numOutputs = layerNum == topology.size() - 1 ? 0 : topology[layerNum + 1];
        //For adding neurons to the layers with a bias neuron
        for(unsigned neuronNum = 0;neuronNum <= topology[layerNum]; ++neuronNum) {
            n_layers.back().push_back(Neuron(numOutputs, neuronNum));
            cout << "Created a Neuron!" << endl;
        }
    }
}

void Net::feedForward(const vector<double> &inputVals){
    assert(inputVals.size() == n_layers[0].size() - 1);

    for(unsigned i = 0; i < inputVals.size(); ++i){
        n_layers[0][i].setOutputVals(inputVals[i]);
    }

    //Feed Forward
    for(unsigned layerNum = 1; layerNum < n_layers.size(); ++layerNum){
        Layer &prevLayer = n_layers[layerNum - 1];
        for(unsigned n = 0; n < n_layers[layerNum - 1]; ++n) {
            n_layers[layerNum][n].feedForward(prevLayer);
        }
    }
}

void Net::backProp(const vector<double> &targetVals){
    //Calculate overall net error (RMS of output neuron errors)

    Layer &outputLayer = n_layers.back();
    n_error = 0.0;

    for (unsigned n = 0;n < outputLayer.size() - 1; ++n){
        double delta = targetVals[n] - outputLayer[n].getOutputVal();
        n_error += delta * delta; 
    }

    n_error /= outputLayer.size() - 1;
    n_error = sqrt(n_error); //RMS

    n_recentAverageError = (n_recentAverageError * n_recentAverageSmoothingFactor + n_error)
    / (n_recentAverageSmoothingFactor + 1.0);

    //Calculate output layer gradients

    for(unsigned n = 0;n < outputLayer.size() - 1; ++n){
        outputLayer[n].calcOutputGradients(targetVals[n]);
    }
    //Calculate the gradients of hidden layers

    for(unsigned layerNum = n_layers.size() - 2; layerNum > 0; --layerNum){
        Layer &hiddenLayer = n_layers[layerNum];
        Layer &nextLayer = n_layers[layerNum + 1];

        for(unsigned n = 0; n < hiddenLayer.size(); ++n){
            hiddenLayer[n].calcHiddenGradients(nextLayer);
        }
    }

    //From output to first hidden layer update connection weights

    for(unsigned layerNum = n_layers.size() - 1;layerNum > 0;--layerNum){
        Layer &layer = n_layer[layerNum];
        Layer &prevLayer = n_layer[layerNum - 1];

        for(unsigned n = 0;n < layer.size() - 1; ++n){
            layer[n].updateInputWeights(prevLayer);
        }
    }
} 

void Net::getResults(vector<double> &targetVals){
    resultVals.clear();

    for(unsigned n = 0;n < n_layers.back().size() - 1; ++n){
        resultsVals.push_back(n_layer.back()[n].getOutputVal());
    }
}

int main(){

    vector<unsigned> topology;
    topology.push_back(3);
    topology.push_back(2);
    topology.push_back(1);
    Net myNet(topology);

    vector<double> inputVals;
    myNet.feedForward(inputVals);

    vector<double> targetVals;
    myNet.backProp(targetVals);

    vector<double> resultsVals;
    myNet.getResults(resultsVals);
}