#pragma once

class TransformObject {
    public:
        // covert 0-360 to 0-512
        static int rotate(int angle);

        // convert 0-800% to 0-64-512 (64 = 100%)
        static int scale(int value);

        // convert 0-100 to 0-31;
        static int alpha(int value);

    private:
};