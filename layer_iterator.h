//
// Created by gmora on 07.12.2021.
//

#ifndef TMPS_LAYER_ITERATOR_H
#define TMPS_LAYER_ITERATOR_H

#include "network.h"

class LayerIterator {

public:
	vector<IObject *> operator*() const { return *m_ptr; }

	//Prefix increment
	LayerIterator &operator++() {
		m_ptr = &((Neuron *) m_ptr->front())->link.obj_list;
		return *this;
	}

	friend bool operator==(const LayerIterator &a, const LayerIterator &b) {
		bool first_null = a.m_ptr == nullptr || (a.m_ptr->empty());
		bool second_null = b.m_ptr == nullptr || (b.m_ptr->empty());
		if (first_null == second_null) {
			if (first_null) {
				return true;
			} else {
				return a.m_ptr == b.m_ptr;
			}

		}
		return false;
	};


	friend bool operator!=(const LayerIterator &a, const LayerIterator &b) { return !(a == b); };

	LayerIterator(vector<IObject *> *layer) {
		this->m_ptr = layer;
	}

	LayerIterator() {
		this->m_ptr = nullptr;
	}

private:

	vector<IObject *> *m_ptr;
};


#endif //TMPS_LAYER_ITERATOR_H
