#include "../inc/Mesh.hpp"
#include "../inc/Framework.hpp"

void Mesh::SetUp(std::string _file) {
	std::ifstream archivo;
	std::string aux = "../res/models/";

	archivo.open(aux+_file);

	if(archivo.fail()){
		archivo.close();
		throw SDL_Exception(__FILE__,"No such file o directory",__LINE__);
	}else{
		setFileObject(archivo);
	}
}


void Mesh::setFileObject(std::ifstream &_file){
    
        std::string line;
        while (!_file.eof()){

        	std::getline(_file, line);
            
            if (line.rfind("v ", 0) == 0){
                Vector3 vertex; 
                sscanf(line.c_str(), "v %lf %lf %lf", &vertex.x, &vertex.y, &vertex.z);
                this->vertices.push_back(vertex);

            }else if (line.rfind("f ", 0) == 0){
                int vertexIndices[3];

                sscanf(line.c_str(), "f %d %d %d",&vertexIndices[0],&vertexIndices[1], &vertexIndices[2]);
                Vector3 face;
                face.x = vertexIndices[0]-1;
                face.y = vertexIndices[1]-1;
                face.z = vertexIndices[2]-1;
                this->faces.push_back(face);
                Triangle newTriangle;
                this->triangles.push_back(newTriangle);
            }
        
    	}

    	this->T_size = this->triangles.size();

    _file.close();
}

void Mesh::Update(){
    
    rotation.x += rotationAmount.x;
    rotation.y += rotationAmount.y;
    rotation.z += rotationAmount.x;

    for (size_t i = 0; i < this->T_size; i++){

        this->triangles[i].vertices[0] = (vertices[static_cast<int>(faces[i].x)]);
        this->triangles[i].vertices[1] = (vertices[static_cast<int>(faces[i].y)]);
        this->triangles[i].vertices[2] = (vertices[static_cast<int>(faces[i].z)]);

        for (size_t j = 0; j < 3; j++) {

            this->triangles[i].RotateVertex(j, rotation);
            this->triangles[i].TranslateVertex(j, this->cameraPosition);
            this->triangles[i].ProjectVertex(j, ZOOM);
            this->triangles[i].projectedVertices[j].x += (this->WIDTH/2);
            this->triangles[i].projectedVertices[j].y += (this->HEIGHT/2)+30;
            
        }
    }
}