/*
 * SplitApplyCombineImpl.h
 *
 *  Created on: 9 oct. 2021
 *      Author: andres
 */

#ifndef SPLITAPPLYCOMBINEIMPL_H_
#define SPLITAPPLYCOMBINEIMPL_H_
#include <string>
#include "LectorDeArchivo.h"
#include "Operacion.h"
#include "OperacionStrategy.h"

class SplitApplyCombineImpl {
private:
	int filaInicio;

	int nroParticiones;

	int filaFin;

	std::string operacion;

	OperacionStrategy* particion;

	LectorDeArchivo* gestorDeDatos;

public:
	SplitApplyCombineImpl(int filaInicio, int filaFin, std::string operacion, int nroParticiones);

	void cargarDatosParaResolverOperaciones(char *argv[], int columnaDondeOperar);

	void SplitApplyCombineImplementarOperacion();

	int SplitApplyCombineResultadoOperacion();

	virtual ~SplitApplyCombineImpl();

private:
	bool SplitApply(OperacionStrategy* particion);

	void Combine(OperacionStrategy* particion, OperacionStrategy* nuevaParticion);

};
#endif /* SPLITAPPLYCOMBINEIMPL_H_ */
