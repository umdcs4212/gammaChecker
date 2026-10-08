#include <iostream>
#include <array>

#include "png++/png.hpp"

int main(int argc, char *argv[])
{
    // default width and height
    int w = 100, h = 100;
    
    // takes two args for width and height
    if (argc == 3) {
        w = atoi(argv[1]);
        h = atoi(argv[2]);
    }
    else if (argc == 2) {
        w = h = atoi(argv[1]);
    }

    std::cout << "Generating gamma test image: " << w << " by " << h << " pixels." << std::endl;

    // Create an image for gamma testing
    png::image< png::rgb_pixel > imData( w, h );

    // first the gamma 50-50 part on half the image width

    for (size_t y = 0; y < imData.get_height(); ++y)
    {
        for (size_t x = 0; x < imData.get_width()/2; ++x)
	{
            if (y % 2 == 0)
                imData[y][x] = png::rgb_pixel(255, 255, 255);
            else
                imData[y][x] = png::rgb_pixel(0, 0, 0);                
	}
    }


    constexpr int max = 10;
    int divWidth = imData.get_height() / max;
    
    // generate the specific values I want to check -- 181 is close to
    // gamma 2 for reference
    // no real need to check 0, 32, 64 since so dark
    // std::array<int, max> vals = { 0, 32, 64, 96, 128, 160, 181,
    // 192, 224, 255 };

    std::array<int, max> vals = { 0, 96, 128, 160, 181, 186, 188, 192, 198, 255 };

    // might be better to more evenly sample the gamma space starting
    // at 128 (gamma=1), up to V (gamma=2.8)

    float gammaStep = 1.8/6.0;
    for (int sample=0; sample<6; ++sample) {
        float gamma = 1.0 + (sample+1) * gammaStep;
        int val = (int)floor( pow(0.5, 1.0/gamma) * 256 );
        vals[3 + sample] = val;
    }

    for (int iter=0; iter<max; ++iter) {
        
        int val = vals[iter];
        float gamma = log(0.5) / log( val / (float)256 );
        
        std::cout << "Level " << iter << ": " << val << std::fixed << std::setprecision(1) << ", gamma=" << gamma << std::endl;

        for (size_t y = iter*divWidth; y < iter*divWidth + divWidth; ++y)
        {
            for (size_t x = imData.get_width()/2; x < imData.get_width(); ++x)
            {
                imData[y][x] = png::rgb_pixel(val, val, val);
            }
        }
        
    }
    
    imData.write( "gammaCheck.png" );

    exit(EXIT_SUCCESS);
}
