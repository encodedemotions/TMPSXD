#pragma once

#include "neuron.h"
#include <list>
#include "neuron_builder.h"
#include "layer_iterator.h"

struct Network {
	vector<IObject *> output_vector;
	vector<IObject *> input_vector;
	int input_size;
	int output_size;

	Network(const list<int> &network_size) {
		NeuronBuilder neuron_builder;

		for (int i = 0; i < network_size.back(); i++) {
			neuron_builder.add_link(new Neuron());
		}
		output_vector = neuron_builder.link.obj_list;
		output_size = output_vector.size();

		for (auto it = next(network_size.rbegin()); it != network_size.rend(); it++) {
			vector<IObject *> temporary_list;
			auto layer_size = *it;
			for (int i = 0; i < layer_size; i++) {
				temporary_list.push_back(neuron_builder.build());
			}
			neuron_builder.reset_link();
			neuron_builder.link = Link{temporary_list};
		}
		input_vector = neuron_builder.link.obj_list;
		input_size = input_vector.size();
	}

	void propagate(vector<float> input) {
		for (int i = 0; i < input_size; i++) {
			input_vector.at(i)->on_receive({input[i]});
		}
	}

	void add_input_neuron() {
		input_vector.push_back(input_vector.front()->clone());
		input_size++;
	}

	vector<float> get_result() {
		vector<float> ret;
		for (auto object: output_vector) {
			auto value = object->on_send().value;
			ret.push_back(value);
		}
		for (auto object: input_vector) { (object->on_send()); }
		return ret;
	}

	LayerIterator begin() { return {&this->input_vector}; }

	LayerIterator end() { return {}; }

};