#include "aquila/source/WaveFile.h"
#include "aquila/source/generator/SineGenerator.h"

#include <iostream>

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        std::cout << "Usage: generate_test_wavfile <FILENAME>" << std::endl;
        return 1;
    }

    const auto sampleRate = 44100;
    Aquila::SineGenerator sineGenerator(sampleRate);
    sineGenerator.setFrequency(220).setAmplitude(255).generate(sampleRate*12-5);

    Aquila::WaveFile::save(sineGenerator, argv[1]);
}
