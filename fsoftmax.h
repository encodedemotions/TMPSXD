//
// Created by gmora on 10.11.2021.
//

#ifndef TMPS_FSOFTMAX_H
#define TMPS_FSOFTMAX_H

#include "softmax_singleton.h"

vector<float> softmax_layer(const vector<float> &layer_values) {
	Softmax::GetInstance().reset();
	for (auto value: layer_values) {
		Softmax::GetInstance().add_component(value);
	}
	return Softmax::GetInstance().get_result();
}


#endif //TMPS_FSOFTMAX_H
