class Color{
    public:
        Color(int rows, int cols, int numCountries, char **input);
        ~Color();

        void findColors();
        void printColors();

    private:
        int rows_;
        int cols_;
        int numCountries_;
        char **map;
        int *mapColors;
        bool **adjacencies;
        bool isValid();
        bool colorHelper(char country);
};