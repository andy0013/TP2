/*
 * SplitApplyCombineImpl.h
 *
 *  Created on: 9 oct. 2021
 *      Author: andres
 */

#ifndef SPLITAPPLYCOMBINEIMPL_H_
#define SPLITAPPLYCOMBINEIMPL_H_

#include "LectorDeArchivo.h"
#include "Operacion.h"
#include "OperacionStrategy.h"

class SplitApplyCombineImpl {

private:

	int filaInicio;

	int nroParticiones;

	int filaFin;

	std::string operacion;

	LectorDeArchivo* gestorDeDatos;

public:

	SplitApplyCombineImpl(int filaInicio, int filaFin, std::string operacion, int nroParticiones);

	void cargarDatosParaResolverOperaciones(std::string nombreDataset, int cantidadColumnas, int columnaDondeOperar);

	void SplitApplyCombineImplementarOperacion();

	virtual ~SplitApplyCombineImpl();
};

#endif /* SPLITAPPLYCOMBINEIMPL_H_ */
