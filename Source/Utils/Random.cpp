#include "Random.hpp"

#include <ctime>

Random::Random() {
    gen.seed(std::time(nullptr));
}

Random& Random::get() {
    static Random rand;

    return rand;
}

int Random::intInRange(int low, int high) {
    std::uniform_int_distribution<int> dist(low, high);

    return dist(gen);
}

float Random::floatInRange(float low, float high) {
    std::uniform_real_distribution<float> dist(low, high);

    return dist(gen);
}
