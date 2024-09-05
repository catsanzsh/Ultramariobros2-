#include <cmath>
#include <algorithm>

// Define a structure for a light source
struct Light {
    float x, y, z;       // Position of the light
    float r, g, b;       // Color of the light
};

// Define a structure for material properties
struct Material {
    float ambient[3];    // Ambient color
    float diffuse[3];    // Diffuse color
    float specular[3];   // Specular color
    float shininess;     // Shininess factor
};

// Define a structure for a vertex
struct Vertex {
    float x, y, z;       // Position of the vertex
    float nx, ny, nz;    // Normal vector
};

// Lighting calculations
void applyLighting(Vertex &vertex, const Light &light, const Material &material) {
    // Calculate ambient component
    float ambient[3] = {
        material.ambient[0] * light.r,
        material.ambient[1] * light.g,
        material.ambient[2] * light.b
    };

    // Calculate diffuse component
    float lightDir[3] = { light.x - vertex.x, light.y - vertex.y, light.z - vertex.z };
    float length = std::sqrt(lightDir[0] * lightDir[0] + lightDir[1] * lightDir[1] + lightDir[2] * lightDir[2]);
    lightDir[0] /= length;
    lightDir[1] /= length;
    lightDir[2] /= length;

    float dotProduct = std::max(0.0f, lightDir[0] * vertex.nx + lightDir[1] * vertex.ny + lightDir[2] * vertex.nz);
    float diffuse[3] = {
        material.diffuse[0] * light.r * dotProduct,
        material.diffuse[1] * light.g * dotProduct,
        material.diffuse[2] * light.b * dotProduct
    };

    // Calculate specular component
    float viewDir[3] = { 0.0f, 0.0f, 1.0f }; // Assuming a fixed view direction for simplicity
    float reflectDir[3] = {
        2.0f * dotProduct * vertex.nx - lightDir[0],
        2.0f * dotProduct * vertex.ny - lightDir[1],
        2.0f * dotProduct * vertex.nz - lightDir[2]
    };

    float spec = std::max(0.0f, viewDir[0] * reflectDir[0] + viewDir[1] * reflectDir[1] + viewDir[2] * reflectDir[2]);
    spec = std::pow(spec, material.shininess);

    float specular[3] = {
        material.specular[0] * light.r * spec,
        material.specular[1] * light.g * spec,
        material.specular[2] * light.b * spec
    };

    // Combine components
    float finalColor[3] = {
        ambient[0] + diffuse[0] + specular[0],
        ambient[1] + diffuse[1] + specular[1],
        ambient[2] + diffuse[2] + specular[2]
    };

    // Set the final color of the vertex (or pixel)
    vertex.r = std::min(1.0f, finalColor[0]);
    vertex.g = std::min(1.0f, finalColor[1]);
    vertex.b = std::min(1.0f, finalColor[2]);
}
