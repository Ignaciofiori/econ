#pragma once
#include <cstdlib>
#include <limits> // Para std::numeric_limits
#include <iomanip>
#include "ArchivoUsuario.h"
#include "Usuario.h"
#include "Funciones.h"

Usuario registrarse();
Usuario nuevoAdmin();
Usuario login();
Usuario busquedaUsuarioPorEmail(char *email);
void mostrarUsuarios(Usuario *vectorUsuarios, int cantidadUsuarios);
bool confirmarContrasena(const char* contrasena1, const char* contrasena2);
void listarUsuariosconReclamos(ArchivoReclamo& archivoR, ArchivoUsuario& archivoU);
