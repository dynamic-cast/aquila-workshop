#include "aquila/functions.h"
#include "aquila/source/WaveFile.h"
#include "aquila/transform/Mfcc.h"

#include <algorithm>
#include <iostream>
#include <vector>

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        std::cout << "Usage: workshop <FILENAME>" << std::endl;
        return 1;
    }

    Aquila::WaveFile wav(argv[1]);

    wav.padToPowerOf2();

    const auto numSamples = wav.getSamplesCount();

    Aquila::Mfcc mfcc(numSamples);
    const auto mfccValues = mfcc.calculate(wav);

    for (const auto val : mfccValues)
    {
        std::cout << val << " ";
    }

    std::cout << std::endl;
}
