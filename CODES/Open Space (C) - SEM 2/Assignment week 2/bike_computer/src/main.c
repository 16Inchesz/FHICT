#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>
#include <Windows.h>
#include <time.h>

#define MIN_SPEED 20
#define MAX_SPEED 60
#define MIN_POWER 150
#define MAX_POWER 200
#define MIN_HEART_RATE 60
#define MAX_HEART_RATE 140
#define MIN_CADENCE 50
#define MAX_CADENCE 100

#define MAX_NUMBER_MEASUREMENTS 32

// variable to keep track of added values in the array.
int i = 0;

enum bike_data_type
{
	BIKE_SPEED,
	BIKE_HEART_RATE,
	BIKE_CADENCE
};

struct bike_data
{
	uint16_t speed;
	uint16_t heart_rate;
	uint16_t cadence;
};

/*
 * Function declarations
 */
uint16_t get_random_value(uint16_t, uint16_t);
uint16_t bike_measure_speed_in_kmh();
uint16_t bike_measure_heart_rate_in_bpm();
uint16_t bike_measure_cadence_in_rpm();
uint16_t get_maximum_number_of_measurements();
uint16_t get_number_of_measurements_present();
void add_measurement(struct bike_data);
struct bike_data get_measurement(uint16_t);
uint16_t get_value_for_data_type(struct bike_data, enum bike_data_type);
uint16_t calculate_min_value(enum bike_data_type);
uint16_t calculate_max_value(enum bike_data_type);
uint16_t calculate_average_value(enum bike_data_type);

/*
 * Global variables
 */
struct bike_data bike_measurements[MAX_NUMBER_MEASUREMENTS] = {{0}};
uint16_t number_of_measurements_present = 0;

int main()
{
	struct bike_data measurement;
	uint16_t min = 0, max = 0, average = 0;
	enum bike_data_type type;

	while (true)
	{
		measurement.speed = bike_measure_speed_in_kmh();
		measurement.heart_rate = bike_measure_heart_rate_in_bpm();
		measurement.cadence = bike_measure_cadence_in_rpm();

		add_measurement(measurement);

		type = BIKE_SPEED;
		min = 0;
		max = 0;
		average = 0;
		min = calculate_min_value(type);
		max = calculate_max_value(type);
		average = calculate_average_value(type); 
		printf("SPEED:\t\t%d, average = %d, min = %d, max = %d [km/h]\n", measurement.speed, average, min, max);

		type = BIKE_HEART_RATE;
		min = calculate_min_value(type);
		max = calculate_max_value(type);
		average = calculate_average_value(type);
		printf("HEART-RATE:\t%d, average = %d, min = %d, max = %d [hrm]\n", measurement.heart_rate, average, min, max);

		type = BIKE_CADENCE;
		min = calculate_min_value(type);
		max = calculate_max_value(type);
		average = calculate_average_value(type);
		printf("CADENCE: \t%d, average = %d, min = %d, max = %d [RPM]\n", measurement.cadence, average, min, max);

		printf("\n");
		Sleep(1000); // Pause the program for 1 second
	}

	return (0);
}

/*
 * Function definitions
 */
uint16_t get_random_value(uint16_t min_range, uint16_t max_range)
{
	// reference: stackoverflow
	srand(time(NULL));

	int random = rand() % (max_range - min_range + 1) + min_range; 

	return random;
}

uint16_t bike_measure_speed_in_kmh()
{
	return get_random_value(MIN_SPEED, MAX_SPEED);
}

uint16_t bike_measure_heart_rate_in_bpm()
{
	return get_random_value(MIN_HEART_RATE, MAX_HEART_RATE);
}

uint16_t bike_measure_cadence_in_rpm()
{
	return get_random_value(MIN_CADENCE, MAX_CADENCE);
}

uint16_t get_maximum_number_of_measurements()
{
	return MAX_NUMBER_MEASUREMENTS;
}

uint16_t get_number_of_measurements_present()
{
	return number_of_measurements_present;
}

void add_measurement(struct bike_data value)
{
	bike_measurements[i] = value;
	i++;
	i = (i % 32);
	if (number_of_measurements_present < 32){
		number_of_measurements_present++;
	}
}

struct bike_data get_measurement(uint16_t index)
{
	return bike_measurements[index];
}

uint16_t get_value_for_data_type(struct bike_data measurement, enum bike_data_type type)
{
	uint16_t value = 0;

	if (type == BIKE_SPEED)
	{
		value = measurement.speed;
	}

	if (type == BIKE_HEART_RATE)
	{
		value = measurement.heart_rate;
	}

	if (type == BIKE_CADENCE)
	{
		value = measurement.cadence;
	}
	return value;
}

uint16_t calculate_min_value(enum bike_data_type type)
{
	uint16_t number_of_measurements = get_number_of_measurements_present();

	// check if its within Unsigned int threshold.
	uint16_t min_value = UINT16_MAX;

	for (uint16_t index_position = 0; index_position < number_of_measurements; index_position++)
	{
		struct bike_data measurement = get_measurement(index_position);
		uint16_t value = get_value_for_data_type(measurement, type);
		if (value < min_value)
		{
			min_value = value;
		}
	}

	return min_value;
}

uint16_t calculate_max_value(enum bike_data_type type)
{
	uint16_t number_of_measurements = get_number_of_measurements_present();

	uint16_t max_value = 0;

	for (uint16_t index_position = 0; index_position < number_of_measurements; index_position++)
	{
		struct bike_data measurement = get_measurement(index_position);
		uint16_t value = get_value_for_data_type(measurement, type);
		if (value > max_value)
		{
			max_value = value;
		}
	}

	return max_value;
}

uint16_t calculate_average_value(enum bike_data_type type)
{
	uint16_t number_of_measurements = get_number_of_measurements_present();

	uint16_t average_value = 0;
	uint16_t sum_value = 0;

	for (uint16_t index_position = 0; index_position < number_of_measurements; index_position++)
	{
		struct bike_data measurement = get_measurement(index_position);
		uint16_t value = get_value_for_data_type(measurement, type);
		sum_value += value;
	}
	average_value = sum_value / number_of_measurements;

	return average_value;
}