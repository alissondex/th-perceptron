#ifndef TRAINING_HPP_
#define TRAINING_HPP_

#include "neuron.hpp"

struct set_input {
	float matrix[9];
	neuron::response desired_response;
};

set_input input_for_training[] =
{
	{
		{ 1.0f, 1.0f, 1.0f,
		  0.0f, 1.0f, 0.0f,
		  0.0f, 1.0f, 0.0f  },
		neuron::response::letter_t
	}, 

	{
		{ 1.0f, 0.0f, 1.0f,
		  1.0f, 1.0f, 1.0f,
		  1.0f, 0.0f, 1.0f  },
		neuron::response::letter_h
	}
};

#endif /* TRAINING_HPP_ */