//
//  main.cpp
//  BMOOpenCV-08
//
//  Created by Breno Medeiros on 01/04/20.
//  Copyright © 2020 ProgramasBMO. All rights reserved.
//

#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/aruco.hpp>
#include <opencv2/calib3d.hpp>

#include <sstream>
#include <iostream>
#include <fstream>

using namespace std;
using namespace cv;

String caminho = "/Users/brenomedeiros/Documents/ProgramasBMO/Cpp/BMOOpenCV-08/BMOOpenCV-08/";
String caminhoImagens = "/Users/brenomedeiros/Documents/ProgramasBMO/Cpp/BMOOpenCV-08/BMOOpenCV-08/Images/";

void criarMarcadoresAruco() {
    Mat marcadorDeSaida;
    
    // Abaixo defininermos um ponteiro de um dicionario, para podermos percorrer varios marcadores diferentes.
    // E usaremos o dicionario predefinido DICT_4X4_50, pois 4x4 é o mais rapido disponivel, e não usaremos mais de 50 marcadores.
    Ptr<aruco::Dictionary> dicionarioDeMarcadores = aruco::getPredefinedDictionary(aruco::PREDEFINED_DICTIONARY_NAME::DICT_4X4_50);
    
    for (int i=0; i<50; i++) {
        // Determinaremos qual desses marcadores do nosso dicionario(DICT_4X4_50) enviaremos para o nosso objeto 'marcadorDeSaida'
        aruco::drawMarker(dicionarioDeMarcadores, i, 500, marcadorDeSaida, 1);
        
        // Pega o nome da string e da 'append' no valor de 'i', e usaremos como nome do arquivo que criaremos para cada marcador.
        ostringstream conversor;
        string nomeDaImagem = "Marcador4x4_";
        conversor << nomeDaImagem << i << ".jpg";
        imwrite(caminhoImagens+conversor.str(), marcadorDeSaida);
    }
}


int main(int argc, const char * argv[]) {
    // insert code here...
    criarMarcadoresAruco();
    
    
    return 0;
}
