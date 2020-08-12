class Random {
    public:
        static std::string string(size_t length) {
            auto randchar = []() -> char
            {
                const char charset[] =
                "0123456789"
                "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
                "abcdefghijklmnopqrstuvwxyz";
                const size_t max_index = (sizeof(charset) - 1);
                return charset[ rand() % max_index ];
            };
            std::string str(length,0);
            std::generate_n( str.begin(), length, randchar );
            return str;
        }

        // random 0-1
        static float simple() {
            return (float) rand() / RAND_MAX;
        }
        
        // random 0-max
        static int range(int max) {
            return (rand() % max) + 1;
        }
};