#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include<stdlib.h>
#define PI 3.14159265358979323846

struct geoCoord
{
    double latitudes;
    double longitudes;
};
double DistanceKm(double lat1, double lat2, double lon1, double lon2);
double totalDistanceKm(struct geoCoord* coordinates, int numWaypoints);

int main() {
    int waypntsNum;
    printf("Enter the number of waypoints (minimum = 2): ");
    do {
        if ((scanf("%d", &waypntsNum)) != 1 || waypntsNum <= 1)
        {
            printf("Invalid input. Expected a number greater 1.\nPlease try again: ");
            while (getchar() != '\n');
        }
    } while (waypntsNum <= 1);

    struct geoCoord* coordinates = (struct geoCoord*)malloc(waypntsNum * sizeof(struct geoCoord));
    if (coordinates == NULL)
        exit(EXIT_FAILURE);
    
    printf("\nEnter the cooridates of the waypoints as <latitude><longitude>\n");
    for (int i = 0;i < waypntsNum;i++)
    {
        printf("Waypoint %d:", i + 1);
        do
        {
            if (scanf("%lf %lf", &coordinates[i].latitudes, &coordinates[i].longitudes) != 2 || coordinates[i].latitudes < -90.0 || coordinates[i].latitudes > 90.0 || coordinates[i].longitudes < -180.0 || coordinates[i].longitudes > 180.0)
                printf("Invalid input. Expected <latitude><longitude>.\nPlease try again: ");
            while (getchar() != '\n');
        } while (coordinates[i].latitudes < -90.0 || coordinates[i].latitudes > 90.0 || coordinates[i].longitudes < -180.0 || coordinates[i].longitudes > 180.0);
    }
 
    double result = totalDistanceKm(coordinates, waypntsNum);
    printf("\nBy taking this route you will travel %.2lfKm", result);
  
    free(coordinates);
    getchar();
    return 0;
}

double DistanceKm(double lat1, double lat2, double lon1, double lon2) {
    double distance = 6378.388 * acos(sin(lat1 * PI / 180.0) * sin(lat2 * PI / 180.0) +
        cos(lat1 * PI / 180.0) * cos(lat2 * PI / 180.0) * cos((lon2 - lon1) * PI / 180.0));
    return distance;
}

double totalDistanceKm(struct geoCoord* coordinates, int numWaypoints) {
    double totalDistance = 0.0;
    for (int i = 0; i < numWaypoints - 1; i++) {
        totalDistance += DistanceKm(coordinates[i].latitudes, coordinates[i + 1].latitudes,
            coordinates[i].longitudes, coordinates[i + 1].longitudes);
    }
    return totalDistance;
}
