#include <vector>
#include <algorithm>

class ExamTracker {
private:
    std::vector<int> times;
    std::vector<long long> prefixSums;

public:
    ExamTracker() {
        // Constructor vacío, los vectores inician vacíos
    }

    void record(int time, int score) {
        times.push_back(time);
        long long currentSum = score;
        if (!prefixSums.empty()) {
            currentSum += prefixSums.back();
        }
        prefixSums.push_back(currentSum);
    }

    long long totalScore(int startTime, int endTime) {
        if (times.empty()) return 0;

        // Encontrar el índice del primer examen con time >= startTime
        auto startIt = std::lower_bound(times.begin(), times.end(), startTime);
        // Encontrar el índice del último examen con time <= endTime
        auto endIt = std::upper_bound(times.begin(), times.end(), endTime);

        int startIndex = std::distance(times.begin(), startIt);
        int endIndex = std::distance(times.begin(), endIt) - 1;

        if (startIndex > endIndex) {
            return 0; // No hay exámenes en ese rango
        }

        long long total = prefixSums[endIndex];
        if (startIndex > 0) {
            total -= prefixSums[startIndex - 1];
        }

        return total;
    }
};
