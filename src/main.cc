#include "color.h"
#include "vec3.h"

#include <iostream>

int main()
{
    // Simple image
    const int image_w = 256;
    const int image_h = 256;

    // Render to a ppm file
    std::cout << "P3\n"
              << image_w << ' ' << image_h << "\n255\n";

    for (int j = image_h - 1; j >= 0; j--)
    {
        std::cerr << "\rScanlines reminaing: " << j << ' ' << std::flush;
        for (int i = 0; i < image_w; ++i)
        {
            color pixel_color(double(i)/(image_w - 1), double(j)/(image_h - 1), 0.25);
            write_color(std::cout, pixel_color);
        }
    }
    std::cerr << "\nDone.\n";
}