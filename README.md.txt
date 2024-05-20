Distance Calculator Project
Overview

This project calculates the total distance between a series of geographical waypoints using their latitude and longitude coordinates. The distance is computed in kilometers using the Haversine formula.
Features

    Input a series of geographical coordinates (latitude and longitude).
    Calculate the distance between each pair of consecutive waypoints.
    Sum the distances to get the total travel distance.

Requirements

    C compiler (e.g., GCC)
    Standard C libraries (stdio.h, stdlib.h, math.h)

Compilation

To compile the program, use the following command in your terminal:

bash

gcc -o distance_calculator distance_calculator.c -lm

Make sure you have the distance_calculator.c file in the same directory as your terminal.
Usage

    Run the compiled program:

bash

./distance_calculator

    Enter the number of waypoints when prompted (minimum of 2).

    Enter the latitude and longitude for each waypoint. The format for each coordinate is <latitude> <longitude>.

    The program will output the total distance in kilometers that you will travel by visiting the waypoints in the given order.

Example

kotlin

Enter the number of waypoints (minimum = 2): 3

Enter the coordinates of the waypoints as <latitude><longitude>
Waypoint 1: 40.7128 -74.0060
Waypoint 2: 34.0522 -118.2437
Waypoint 3: 51.5074 -0.1278

By taking this route you will travel 12477.39Km

Code Structure

    struct geoCoord: A structure to store latitude and longitude of a waypoint.
    DistanceKm(double lat1, double lat2, double lon1, double lon2): A function to calculate the distance between two points given their latitudes and longitudes.
    totalDistanceKm(struct geoCoord* coordinates, int numWaypoints): A function to calculate the total distance for a series of waypoints.
    main(): The main function that handles input/output and coordinates the calculation process.

License

This project is licensed under the MIT License. See the LICENSE file for more details.
Author

Tanjid Hasan Tonmoy
Acknowledgments

    This project uses the Haversine formula to calculate distances between points on the Earth's surface.
    Special thanks to resources and tutorials available online that helped in understanding geographical distance calculations.

Feel free to contribute to this project by forking the repository and submitting pull requests. For any issues or suggestions, please open an issue on GitHub.