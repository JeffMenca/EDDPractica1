#ifndef CLIENTE_H
#define CLIENTE_H
class Cliente
{
public:
	Cliente(int);
	Cliente();
	int getCodigoCliente();
	void setCodigoCliente(int codigoCliente);
private:
	int codigoCliente;
};
#endif /* CLIENTE_H */