#include "network.h"
#include "dnetwork.h"
#include "fsoftmax.h"


int main() {
	srand(69);

	DNetwork n = DNetwork({3, 2, 2, 4});
	vector<float> input_vector = {-0.01, 0.1, 0.01};
	printf("Automatic network creation:\n");
	printf("Input values:\n");
	for (auto input: input_vector) {
		printf("%f ", input);
	}

	n.propagate(input_vector);
	printf("\nOutput values:\n");
	auto result = n.get_result();
	for (auto output: result) {
		printf("%f ", output);
	}
	printf("\nSoftmaxed output neurons:\n");
	for (auto output: softmax_layer(result)) {
		printf("%f ", output);
	}

	n.add_input_neuron();
	input_vector = {0, -5, 0, 0};
	printf("\n\nExpanded neural network:\n");
	printf("Input values:\n");
	for (auto input: input_vector) {
		printf("%f ", input);
	}

	n.propagate(input_vector);
	printf("\nOutput values:\n");
	result = n.get_result();
	for (auto output: result) {
		printf("%f ", output);
	}
	printf("\nSoftmaxed output neurons:\n");
	for (auto output: softmax_layer(result)) {
		printf("%f ", output);
	}

	printf("\nPrinting the layers |Weight Bias|\n");
	n.print_all_layers();


	printf("Print the layers with iterator:\n");
	for (auto layer: n) {
		for (auto neurons_obj: layer) {
			printf("%f ", ((Neuron *) neurons_obj)->weight);
		}
		printf("\n");
	}


	return 0;
}