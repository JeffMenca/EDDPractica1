class Caja
{
private:
    int numeroCaja;
    float tiempoServicio;
    bool estadoLibre;
    int codigoCliente;
    int codigoCarreta;

public:
    Caja(int, double, bool, int, int);
    int getNumeroCaja();
    double getTiempoServicio();
    bool getEstadoLibre();
    int getCodigoCliente();
    int getCodigoCarreta();
	void setNumeroCaja(int numeroCaja);
	void setTiempoServicio(double tiempoServicio);
	void setEstadoLibre(bool estadoLibre);
	void setCodigoCliente(int codigoCliente);
	void setCodigoCarreta(int codigoCarreta);
};