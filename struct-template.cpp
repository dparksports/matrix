template <>
struct Traits<Color>{

    static string name(int index) {
        Color color = static_cast<Color>(index);

        switch (color) {
            case Color::red :
                return "red";
            case Color::orange :
                return "orange";
            case Color::green :
                return "green";
            default:
                return "unknown";
        }
    }
};

template <>
struct Traits<Fruit>{

    static string name(int index) {
        Fruit fruit = static_cast<Fruit>(index);

        switch (fruit) {
            case Fruit::apple :
                return "apple";
            case Fruit::orange :
                return "orange";
            case Fruit::pear :
                return "pear";
            default:
                return "unknown";
        }
    }
};
