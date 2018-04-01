#ifndef NEURON_HPP_
#define NEURON_HPP_

#include <vector>
#include <functional>
#include <cstdlib>

float next_random_float()
{
	static const float low  = -1.0f;
	static const float high =  1.0f;

	return low + static_cast<float>(rand()) / (static_cast<float>(RAND_MAX / (high - low)));
}

class neuron
{
public:
	enum class response {
		letter_t,
		letter_h
	};

	neuron() {

		// [-1; 1]
		for(std::size_t x = 0; x < 9; x++)
			this->pesos_sinapticos.push_back(next_random_float());
	}

	// utilizar std::vector
	float learn(float a[9], neuron::response r) {
		static const float taxa_aprendizado = 0.1f;

		float e = this->response_to_float(r) - this->response_to_float(this->execute(a));
		float fator_linear = taxa_aprendizado * e;

		for(std::size_t x = 0; x < 9; x++)
			a[x] *= fator_linear;

		for(std::size_t x = 0; x < 9; x++)
			this->pesos_sinapticos[x] += a[x];

		return e;
	}

	neuron::response execute(const float a[9]) {
		float soma = 0.0f;

		for(std::size_t x = 0; x < 9; x++)
			soma += a[x] * pesos_sinapticos[x];

		return this->float_to_response(funcao_degrau(soma));
	}

private:

	float response_to_float(neuron::response r) {
		switch(r) {
		case neuron::response::letter_h:
			return 1.0f;
		case neuron::response::letter_t:
			return 0.0f;
		}

		std::exit(0);
	}

	neuron::response float_to_response(float v) {
		v = funcao_degrau(v);

		if(v == 1.0f) {
			return neuron::response::letter_h;
		} else if(v == 0.0f) {
			return neuron::response::letter_t;
		}

		printf("float nao identificado\n");
		std::exit(0);
	}

	float funcao_degrau(float v) {
		if(v >= 1.0f)
			return 1.0f;

		// v < 1.0f
		return 0.0f;
	}

	std::vector<float> pesos_sinapticos;
};

#endif /* NEURON_HPP_ */