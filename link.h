#pragma once
#include <vector>
#include "object.h"
using namespace std;

struct Link :public IObject {
	vector<IObject*> obj_list;
	// Inherited via IObject

	Link() {}
	Link(vector<IObject*> obj_list) {
		this->obj_list = obj_list;
	}

	virtual Data on_send() override {
		Data result{ 0 };
		for (auto object : obj_list) {
			result.value += object->on_send().value;
		}
		return result;
	};
	virtual void on_receive(Data data) override {
		for (auto object : obj_list) {
			object->on_receive(data);
		}
	};

	virtual IObject* clone() override{
		return new Link(obj_list);
	}
};