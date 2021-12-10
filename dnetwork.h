//
// Created by gmora on 10.11.2021.
//

#ifndef TMPS_DNETWORK_H
#define TMPS_DNETWORK_H

#include "network.h"
#include <utility>

struct DNetwork : public Network {
	DNetwork(const list<int> &network_size) : Network(network_size) {}

	void print_all_layers() {
		auto layer = &input_vector;
		for (int i = 0; true; ++i) {
			printf("Layer %d: ", i);
			print_layer(*layer);

			auto first_neuron = (Neuron *) layer->front();
			layer = &first_neuron->link.obj_list;
			if (layer->empty()) {
				return;
			}
		}
	}

	void print_layer(int n) {
		if (n == -1) {
			//Print output layer
			print_layer(this->output_vector);
			return;
		}

		auto layer = &input_vector;
		for (int i = 0; i < n; ++i) {

			auto first_neuron = (Neuron *) layer->front();
			layer = &first_neuron->link.obj_list;
			if (layer->empty()) {
				return;
			}
		}
		print_layer(*layer);
	}

	static void print_layer(const vector<IObject *> &layer) {
		for (auto object: layer) {
			auto neuron = dynamic_cast<Neuron *>(object);
			printf("|%f %f| ", neuron->weight, neuron->bias);
		}
		printf("\n");
	}
};


#endif //TMPS_DNETWORK_H
