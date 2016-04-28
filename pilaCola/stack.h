class stack{
    class Nodo{
    public:
        char data;
        Nodo *next;
    };
    Nodo *raiz;
public:
    stack();
    ~stack();
    void insertar(char);
    void extraer();
    void print();
};
