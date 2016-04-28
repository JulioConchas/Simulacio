class queue{
private:
    class Nodo{
    public:
        char data;
        Nodo *next;
    };
    Nodo *raiz;
    Nodo *fondo;
public:
    queue();
    ~queue();
    void insertar(char);
    int extraer();
    void print();
    bool empty();
};
