#include "network.h"

void manual_creation() {
	//Create neural network
	NeuronBuilder neuron_builder;

	//Output neurons
	constexpr int OUTPUT_N = 4;
	vector<IObject*> output_vector;
	for (int i = 0; i < OUTPUT_N; i++) { output_vector.push_back(neuron_builder.build()); }


	//Hidden neurons
	constexpr int HIDDEN_N = 10;
	vector<IObject*> hidden_vector;
	for (auto object : output_vector) { neuron_builder.add_link(object); }
	for (int i = 0; i < HIDDEN_N; i++) { hidden_vector.push_back(neuron_builder.build()); }
	neuron_builder.reset_link();


	//Input neurons
	constexpr int INPUT_N = 3;
	for (auto object : hidden_vector) { neuron_builder.add_link(object); }
	vector<IObject*> input_vector;
	for (int i = 0; i < INPUT_N; i++) { input_vector.push_back(neuron_builder.build()); }


	//Initialise inputs
	float input_values[INPUT_N];
	for (int i = 0; i < INPUT_N; i++) { input_values[i] = RANDF * 3; }


	//Propagate values forward
	printf("Manual Input neurons:\n");
	for (int i = 0; i < INPUT_N; i++) {
		printf("%f\n", input_values[i]);
		input_vector.at(i)->on_receive({ input_values[i] });
	}

	//Print output
	printf("Manual Output neurons:\n");

	for (auto object : output_vector) { printf("%f\n", object->on_send().value); }
}

int main() {
	//manual_creation();
	srand(69);

	Network n = Network({ 3,3,2,2 });
	vector<float> input_vector = { -0.01,0.1, 0.01 };
	printf("Automatic network creation:\n");
	printf("Input neurons:\n");
	for (auto input : input_vector) {
		printf("%f\n", input);
	}

	n.propagate(input_vector);
	printf("Output neurons:\n");
	for (auto output : n.get_result()) {
		printf("%f\n", output);
	}
	printf("Softmaxed output neurons:\n");
	for (auto output : Softmax::GetInstance().get_result()) {
		printf("%f\n", output);
	}

	n.add_input_neuron();
	input_vector.push_back(-3);
	printf("Expanded neural network:\n");
	printf("Input neurons:\n");
	for (auto input : input_vector) {
		printf("%f\n", input);
	}

	n.propagate(input_vector);
	printf("Output neurons:\n");
	for (auto output : n.get_result()) {
		printf("%f\n", output);
	}
	printf("Softmaxed output neurons:\n");
	for (auto output : Softmax::GetInstance().get_result()) {
		printf("%f\n", output);
	}
	


	return 0;
}