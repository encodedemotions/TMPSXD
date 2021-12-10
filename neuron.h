#pragma once
#define RANDF ((float) rand()) / (float) RAND_MAX
#include <random>
#include "object.h"
#include "link.h"
#include "builder.h"
struct Neuron :public IObject {
	float weight;
	float bias;
	float result;
	Link link;

	Neuron() {
		weight = RANDF;
		bias = 0;
		result = 0;
	}

	Neuron(Link link) : Neuron() {
		this->link = link;
	}

	Neuron(float w, float b, Link link) {
		weight = w;
		bias = b;
		this->link = link;
		result = 0;
	}

	virtual Data on_send() override {
		Data ret = Data{ (result) };
		result = 0;
		return ret;
	};
	virtual void on_receive(Data data) override {
		result += data.value * weight + bias;
		link.on_receive({(result)});
	};

	virtual IObject* clone() override{
		return new Neuron(weight, bias, link);
	}
};


struct NeuronBuilder : public IBuilder {

	Link link;

	NeuronBuilder() {}

	void add_link(IObject* object) {
		link.obj_list.push_back(object);
	}
	//void remove_link(IObject* object) { //vector has no remove method, use list
	//	link.obj_list.remove(object);
	//}
	void reset_link() {
		link.obj_list.clear();
	}

	virtual IObject* build() override {
		return new Neuron(link);
	};
};