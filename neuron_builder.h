//
// Created by gmora on 10.11.2021.
//

#ifndef TMPS_NEURON_BUILDER_H
#define TMPS_NEURON_BUILDER_H

#include "ibuilder.h"
#include "link.h"

struct NeuronBuilder : public IBuilder {

	Link link;

	NeuronBuilder() {}

	void add_link(IObject *object) {
		link.obj_list.push_back(object);
	}

	//void remove_link(IObject* object) { //vector has no remove method, use list
	//	link.obj_list.remove(object);
	//}
	void reset_link() {
		link.obj_list.clear();
	}

	virtual IObject *build() override {
		return new Neuron(link);
	};
};

#endif //TMPS_NEURON_BUILDER_H
