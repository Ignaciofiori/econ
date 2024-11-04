#include "ArchivoAcumulador.h"
#include "AcumuladorId.h"
ArchivoAcumuladorId::ArchivoAcumuladorId(std::string nombreArchivo) {
    _nombreArchivo = nombreArchivo;
};


bool ArchivoAcumuladorId::GuardarAcumuladorId(AcumuladorId acum){
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "ab");
    if (pArchivo == NULL) {
        return false;
    }
    bool ok = fwrite(&acum, sizeof(AcumuladorId), 1, pArchivo);
    fclose(pArchivo);
    return ok;
}


bool ArchivoAcumuladorId::EditarAcumuladorId(AcumuladorId acum, int posicion){
     FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb+");
    if (pArchivo == NULL) {
        return false;
    }
    fseek(pArchivo, sizeof(AcumuladorId) * posicion, SEEK_SET);
        bool ok = (fwrite(&acum, sizeof(AcumuladorId), 1, pArchivo) == 1);
    fclose(pArchivo);
    return ok;
}

AcumuladorId ArchivoAcumuladorId::LeerAcumuladorId(int posicion){
FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb");
    if (pArchivo == NULL) {
        return AcumuladorId();
    }

    AcumuladorId acum;
    fseek(pArchivo, sizeof(AcumuladorId) * posicion, SEEK_SET);
    fread(&acum, sizeof(AcumuladorId), 1, pArchivo);
    fclose(pArchivo);

    return acum;
};


  int ArchivoAcumuladorId::CantidadAcumuladorId(){
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb");
    if (pArchivo == NULL) {
        return 0;
    }
    fseek(pArchivo, 0, SEEK_END);
    int cantidadRegistros = ftell(pArchivo) / sizeof(AcumuladorId);
    fclose(pArchivo);
    return cantidadRegistros;
  };

  void ArchivoAcumuladorId::LeerAcumuladorId(int cantidad, AcumuladorId *vector){
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb");
    if (pArchivo == NULL) {
        return;
    }
    int i = 0;
    AcumuladorId acum;
    while (i < cantidad && fread(&acum, sizeof(AcumuladorId), 1, pArchivo)) {

            vector[i] = acum;
            i++;


    }
    fclose(pArchivo);
  };
