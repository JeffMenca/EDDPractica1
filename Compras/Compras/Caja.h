#ifndef CAJA_H
#define CAJA_H
class Caja
{
private:
	int numeroCaja;
	int tiempoServicio;
	int tiempoRestante;
	bool estadoLibre;
	int codigoCliente;
	int codigoCarreta;

public:
	Caja(int,int,int,bool,int,int);
	Caja();
	int getNumeroCaja();
	int getTiempoServicio();
	int getTiempoRestante();
	bool getEstadoLibre();
	int getCodigoCliente();
	int getCodigoCarreta();
	void setNumeroCaja(int numeroCaja);
	void setTiempoServicio(int tiempoServicio);
	void setTiempoRestante(int tiempoRestante);
	void setEstadoLibre(bool estadoLibre);
	void setCodigoCliente(int codigoCliente);
	void setCodigoCarreta(int codigoCarreta);
};
#endif /* CAJA_H */