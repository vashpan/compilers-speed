#!/usr/bin/env python3

import argparse

def measure_average_time(baseline, measurements):
    if len(measurements) < 3:
        raise ValueError("Number of measurements should be at least 3.")

    # Find the index of the best and worst measurements
    best_index = measurements.index(min(measurements))
    worst_index = measurements.index(max(measurements))

    # Remove the best and worst measurements
    trimmed_measurements = [
        time for i, time in enumerate(measurements) if i not in (best_index, worst_index)
    ]

    # Calculate the average time
    average_time = sum(trimmed_measurements) / len(trimmed_measurements)

    # Calculate the percentage of baseline
    percentage_of_baseline = (average_time / baseline) * 100

    # Print the result to the terminal
    print(f"Baseline: {baseline} s")
    print(f"Data: {measurements}")
    print(f"Average Time (excluding best and worst): {average_time:.3f} s")
    print(f"Percentage of Baseline: {percentage_of_baseline:.2f}%")

if __name__ == "__main__":
    parser = argparse.ArgumentParser(description="Measure and analyze average time.")
    parser.add_argument("baseline", type=float, help="Baseline time in seconds")
    parser.add_argument("measurements", type=float, nargs="+", help="Time measurements in seconds")

    args = parser.parse_args()

    measure_average_time(args.baseline, args.measurements)
