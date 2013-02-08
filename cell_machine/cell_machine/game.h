
namespace cell_machine{
    class CellMachineGame{
        unsigned int gameFieldLength;
        unsigned int gameFieldWidth;
        unsigned int fieldSizeInDwords;
        static const unsigned int defaultGameFieldLength = 32;
        static const unsigned int defaultGameFieldWidth = 32;
        static const unsigned int defaultGameFieldSizeInDwords = 32;
        static const unsigned int maxGameFieldLength = 100;
        static const unsigned int maxGameFieldWidth = 100;
        static const char* const greetingStr; 
        unsigned int *gameFieldDwords;

        void drawFieldConsole();
        void populateField();
        
    public:
        CellMachineGame(const unsigned int fieldLength = defaultGameFieldLength,
                        const unsigned int fieldWidth = defaultGameFieldWidth);
        CellMachineGame(const CellMachineGame &cmg);
        ~CellMachineGame();
        void start();

    };

}