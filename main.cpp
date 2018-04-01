#include <iostream>

#include "training.hpp"

void test_neuron(neuron n)
{
	if(n.execute(input_for_training[0].matrix) == input_for_training[0].desired_response)
		printf("Acertou - letra 'T' identificada\n");

	if(n.execute(input_for_training[1].matrix) == input_for_training[1].desired_response)
		printf("Acertou - letra 'H' identificada\n");
}

int main(int argc, char **argv)
{
	srand(time(NULL));
	neuron n;

	std::vector<set_input> input;

	for(std::size_t x = 0; x < 5000000; x++) {
		int index = rand() % 2;
		input.push_back(input_for_training[index]);
	}

	for(auto i : input) {
		n.learn(i.matrix, i.desired_response);
	}

	test_neuron(n);

	return 0;
}