#pragma once

#include <vector>

using namespace std;

class Softmax {
	vector<float> components;
	float common_denominator = 0;
public:
	static Softmax &GetInstance() {
		static Softmax INSTANCE;
		return INSTANCE;
	}

	void add_component(float component) {
		float exp_c = exp(component);
		components.push_back(exp_c);
		common_denominator += exp_c;
	}

	vector<float> get_result() {
		vector<float> ret;
		for (auto component: components) {
			ret.push_back(component / common_denominator);
		}
		reset();
		return ret;
	}

	void reset() {
		components.clear();
		common_denominator = 0;
	}


private:
	Softmax() = default;

	// Delete copy/move so extra instances can't be created/moved.
	Softmax(const Softmax &) = delete;

	Softmax &operator=(const Softmax &) = delete;

	Softmax(Softmax &&) = delete;

	Softmax &operator=(Softmax &&) = delete;
};