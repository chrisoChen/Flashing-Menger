#include <array>
#include <iostream>
#include <vector>
#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include "../include/vec3f.hpp"
using namespace std;

#define SCREEN_WIDTH 1200
#define SCREEN_HEIGHT 720

// Functions
void keyCallback( GLFWwindow *window, int key, int scancode, int action, int mods );

// Vector Structs
struct Vec3f {
	//public members by default
	Vec3f() = default;
	Vec3f(float x, float y, float z) : x(x), y(y), z(z) {}
	
	float x = 0.f;	
	float y = 0.f;
	float z = 0.f;
};

struct Space {
    GLfloat xpos = 0.f;
    GLfloat ypos = 0.f;
    GLfloat zpos = 0.f;
    GLfloat edgeLength = 0.f;
};
const Vec3f colors[] =  {
        {1.0, 0.0, 1.0},            // purple
        {0.0, 1.0, 0.0},            // green
        {0.0, 0.0, 1.0},            // blue
        {1.0, 0.0, 0.0},            // red
        {1.0, 1.0, 0.0},            // yellow
        {0.929, 0.435, 0.027}};     // orange

// Operators
Vec3f add(Vec3f a, Vec3f b, Vec3f c) { return Vec3f(a.x + b.x + c.x, a.y + b.y + c.y, a.z + b.z + c.z ); }
Vec3f operator+(const Vec3f a, const Vec3f b);
Vec3f operator*(const Vec3f a, const float b);


std::ostream &operator<<(std::ostream &out, Vec3f const &a) {
	return out << a.x << ' ' << a.y << a.z;
}

// Classes
class Cube {
    Vec3f m_verts[24];
    Space position;

public:
    enum Vertex {A = 0, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, COUNT };
    using vertices = std::array<math::Vec3f, COUNT>;

    void setx(GLfloat x){position.xpos = x;}
    void sety(GLfloat y){position.ypos= y;}
    void setz(GLfloat z){position.zpos = z;}
    void setedgeLength(GLfloat e){position.edgeLength = e;}

    GLfloat getx(){return position.xpos;}
    GLfloat gety(){return position.ypos;}
    GLfloat getz(){return position.zpos;}
    GLfloat getedgeLength(){return position.edgeLength;}

    Cube() = default;


    Cube(Vec3f a, Vec3f b, Vec3f c, Vec3f d, Vec3f e, Vec3f f, Vec3f g, Vec3f h, Vec3f i, Vec3f j,
            Vec3f k, Vec3f l, Vec3f m, Vec3f n, Vec3f o, Vec3f p, Vec3f q, Vec3f r, Vec3f s, Vec3f t,
            Vec3f u, Vec3f v, Vec3f w, Vec3f x){
        m_verts[0] = a;
        m_verts[1] = b;
        m_verts[2] = c;
        m_verts[3] = d;

        m_verts[4] = e;
        m_verts[5] = f;
        m_verts[6] = g;
        m_verts[7] = h;

        m_verts[8] = i;
        m_verts[9] = j;
        m_verts[10] = k;
        m_verts[11] = l;

        m_verts[12] = m;
        m_verts[13] = n;
        m_verts[14] = o;
        m_verts[15] = p;

        m_verts[16] = q;
        m_verts[17] = r;
        m_verts[18] = s;
        m_verts[19] = t;

        m_verts[20] = u;
        m_verts[21] = v;
        m_verts[22] = w;
        m_verts[23] = x;
    }

    //functions to get/read value
    Vec3f a() const { return m_verts[0]; }
    Vec3f b() const { return m_verts[1]; }
    Vec3f c() const { return m_verts[2]; }
    Vec3f d() const { return m_verts[3]; }
    Vec3f e() const { return m_verts[4]; }
    Vec3f f() const { return m_verts[5]; }
    Vec3f g() const { return m_verts[6]; }
    Vec3f h() const { return m_verts[7]; }
    Vec3f i() const { return m_verts[8]; }
    Vec3f j() const { return m_verts[9]; }
    Vec3f k() const { return m_verts[10]; }
    Vec3f l() const { return m_verts[11]; }
    Vec3f m() const { return m_verts[12]; }
    Vec3f n() const { return m_verts[13]; }
    Vec3f o() const { return m_verts[14]; }
    Vec3f p() const { return m_verts[15]; }
    Vec3f q() const { return m_verts[16]; }
    Vec3f r() const { return m_verts[17]; }
    Vec3f s() const { return m_verts[18]; }
    Vec3f t() const { return m_verts[19]; }
    Vec3f u() const { return m_verts[20]; }
    Vec3f v() const { return m_verts[21]; }
    Vec3f w() const { return m_verts[22]; }
    Vec3f x() const { return m_verts[23]; }

    Vec3f operator[](int index) const { return m_verts[index]; }

    //functions to set value
    Vec3f &a() { return m_verts[0]; }
    Vec3f &b() { return m_verts[1]; }
    Vec3f &c() { return m_verts[2]; }
    Vec3f &d() { return m_verts[3]; }
    Vec3f &e()  { return m_verts[4]; }
    Vec3f &f()  { return m_verts[5]; }
    Vec3f &g()  { return m_verts[6]; }
    Vec3f &h()  { return m_verts[7]; }
    Vec3f &i()  { return m_verts[8]; }
    Vec3f &j()  { return m_verts[9]; }
    Vec3f &k()  { return m_verts[10]; }
    Vec3f &l()  { return m_verts[11]; }
    Vec3f &m()  { return m_verts[12]; }
    Vec3f &n()  { return m_verts[13]; }
    Vec3f &o()  { return m_verts[14]; }
    Vec3f &p()  { return m_verts[15]; }
    Vec3f &q()  { return m_verts[16]; }
    Vec3f &r()  { return m_verts[17]; }
    Vec3f &s()  { return m_verts[18]; }
    Vec3f &t()  { return m_verts[19]; }
    Vec3f &u()  { return m_verts[20]; }
    Vec3f &v()  { return m_verts[21]; }
    Vec3f &w()  { return m_verts[22]; }
    Vec3f &x()  { return m_verts[23]; }
    Vec3f &operator[](int index) { return m_verts[index]; }

};

// Global Variable
GLfloat rotationX = 0.0f;
GLfloat rotationY = 0.0f;

// Cube Matrix Operations
Cube translate(Cube cube, math::Vec3f v);
Cube scale(Cube cube, float s);

// Functions to draw Points
Cube drawCubePoints(GLfloat centerPosX, GLfloat centerPosY, GLfloat centerPosZ, GLfloat edgeLength);
std::vector<Cube> mengeAndsponge(GLfloat centerPosX, GLfloat centerPosY, GLfloat centrePosZ, GLfloat edgelength);
void drawMenge(int depth);
void draw(std::vector<Cube> listCube);

// *****************************************************************************************************************
// *****************************************************************************************************************
int main() {
    GLFWwindow *window = nullptr;

    // Close if OpenGL is not initialized
    if (!glfwInit()) {
        exit(EXIT_FAILURE);
    }

    // Currently installed version of OpenGL
    int glfwMajor, glfwMinor, glfwRevision;
    glfwGetVersion(&glfwMajor, &glfwMinor, &glfwRevision);
    std::cout << "GLFW Version: " << glfwMajor << "." << glfwMinor << "."
              << glfwRevision << std::endl;

    //Assign OpenGL version for program
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 2);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);

    //Create window
    window = glfwCreateWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Cube", NULL, NULL);
    if (!window) {
        glfwTerminate();
        exit(EXIT_FAILURE);
    }

    // Call keyCallBack for key inputs
    glfwSetKeyCallback(window, keyCallback);
    glfwSetInputMode(window, GLFW_STICKY_KEYS, 1);          // GLFW_STICKY_KEYS: ensure keyboard event is polled

    //Set context to window
    glfwMakeContextCurrent(window);

    //Load up
    gladLoadGLLoader((GLADloadproc) glfwGetProcAddress);

    glfwSwapInterval(1); // vsync

    //Set data
    GLfloat halfScreenWidth = SCREEN_WIDTH / 2;
    GLfloat halfScreenHeight = SCREEN_HEIGHT / 2;

    // Rendering loop
    while (!glfwWindowShouldClose(window)) {

        glClear(GL_DEPTH_BUFFER_BIT |
                GL_COLOR_BUFFER_BIT);     // clear depth buffer so every pixel on screen is farther away

        //Viewport
        glEnable(GL_DEPTH_TEST);                                // compare drawn objects depth of what's already drawn, kill new frag if farther than old one
        glViewport(0.0f, 0.0f, SCREEN_WIDTH,
                   SCREEN_HEIGHT);    // x and y value, tell what part of window to draw to pixels
        glMatrixMode(GL_PROJECTION);                            // projection matrix: define properties of camera
        glLoadIdentity();                                       // swap with Identity Matrix, reset GL load identity
        glOrtho(0, SCREEN_WIDTH, 0, SCREEN_HEIGHT, 0.01,
                1000);    // new coord system, 0 -> 640, 0-> 480.     clipping plane 0-1000,
        glMatrixMode(GL_MODELVIEW);                            // default matrix mode, define how objects transform
        glLoadIdentity();

        // Rotate Cube
        glPushMatrix();
        glTranslatef(halfScreenWidth, halfScreenHeight, -300);
        glRotatef(rotationX, 1, 0, 0);
        glRotatef(rotationY, 0, 1, 0);
        glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

        // Draw Menger Sponge; Change int input for deepter levels of recursion
        drawMenge(3);

        //Swap current scene with next scene
        glfwSwapBuffers(window);
        glfwPollEvents(); // will process event queue and carry on
    }

  glfwDestroyWindow(window);
  glfwTerminate();
  return EXIT_SUCCESS;
}

void keyCallback( GLFWwindow *window, int key, int scancode, int action, int mods ){
    const GLfloat rotationSpeed = 10;

    if (action == GLFW_PRESS || action == GLFW_REPEAT ){
        switch (key){
            case GLFW_KEY_UP:
                rotationX -= rotationSpeed;
                break;
            case GLFW_KEY_DOWN:
                rotationX += rotationSpeed;
                break;
            case GLFW_KEY_RIGHT:
                rotationY += rotationSpeed;
                break;
            case GLFW_KEY_LEFT:
                rotationY -= rotationSpeed;
            default:
                break;
        }

    }
}

Cube translate(Cube cube, Vec3f v){
    for(int idx = 0; idx < Cube::Vertex::COUNT; ++idx)
    {
        cube[idx] =  cube[idx] + v;
    }
    return cube;
}

Cube scale(Cube cube, float v){
    for(int idx = 0; idx < Cube::Vertex::COUNT; ++idx)
    {
        cube[idx] = cube[idx] * v;
    }
    return cube;
}

Vec3f operator+(const Vec3f a, const Vec3f b){
    Vec3f copy;
    copy.x = a.x + b.x;
    copy.y = a.y + b.y;
    copy.z = a.z + b.z;
    return copy;
}

Vec3f operator*(const Vec3f a, const float b){
    Vec3f copy;
    copy.x = a.x * b;
    copy.y = a.y * b;
    copy.z = a.z * b;
    return copy;
}

// define new cube points with previous iterations of menger sponge points
Cube drawCubePoints(GLfloat centerPosX, GLfloat centerPosY, GLfloat centerPosZ, GLfloat edgeLength){
    GLfloat halfSideLength = edgeLength /2;
    Cube temp (
    // Front Face
    {centerPosX - halfSideLength, centerPosY + halfSideLength, centerPosZ + halfSideLength},  // top left
    {centerPosX + halfSideLength, centerPosY + halfSideLength, centerPosZ + halfSideLength},  // top right
    {centerPosX + halfSideLength, centerPosY - halfSideLength, centerPosZ + halfSideLength},  // bottom right
    {centerPosX - halfSideLength, centerPosY - halfSideLength, centerPosZ + halfSideLength},  // bottom left,
    // back face
    {centerPosX - halfSideLength, centerPosY + halfSideLength, centerPosZ - halfSideLength},  // top left
    {centerPosX + halfSideLength, centerPosY + halfSideLength, centerPosZ - halfSideLength},  // top right
    {centerPosX + halfSideLength, centerPosY - halfSideLength, centerPosZ - halfSideLength},  // bottom right
    {centerPosX - halfSideLength, centerPosY - halfSideLength, centerPosZ - halfSideLength},  // bottom left
    // left face
    {centerPosX - halfSideLength, centerPosY + halfSideLength, centerPosZ + halfSideLength},  // top left
    {centerPosX - halfSideLength, centerPosY + halfSideLength, centerPosZ - halfSideLength},  // top right
    {centerPosX - halfSideLength, centerPosY - halfSideLength, centerPosZ - halfSideLength},  // bottom right
    {centerPosX - halfSideLength, centerPosY - halfSideLength, centerPosZ +  halfSideLength},  // bottom left,
    // right face
    {centerPosX + halfSideLength, centerPosY + halfSideLength, centerPosZ + halfSideLength},  // top left
    {centerPosX + halfSideLength, centerPosY + halfSideLength, centerPosZ - halfSideLength},  // top right
    {centerPosX + halfSideLength, centerPosY - halfSideLength, centerPosZ - halfSideLength},  // bottom right
    {centerPosX + halfSideLength, centerPosY - halfSideLength, centerPosZ +  halfSideLength},  // bottom left
    // top face
    {centerPosX - halfSideLength, centerPosY + halfSideLength, centerPosZ + halfSideLength},  // top left
    {centerPosX - halfSideLength, centerPosY + halfSideLength, centerPosZ - halfSideLength},  // top right
    {centerPosX + halfSideLength, centerPosY + halfSideLength, centerPosZ - halfSideLength},  // bottom right
    {centerPosX + halfSideLength, centerPosY + halfSideLength, centerPosZ +  halfSideLength},  // bottom left
    // bottom face
    {centerPosX - halfSideLength, centerPosY - halfSideLength, centerPosZ + halfSideLength},  // top left
    {centerPosX - halfSideLength, centerPosY - halfSideLength, centerPosZ - halfSideLength},  // top right
    {centerPosX + halfSideLength, centerPosY - halfSideLength, centerPosZ - halfSideLength},  // bottom right
    {centerPosX + halfSideLength, centerPosY - halfSideLength, centerPosZ +  halfSideLength});

   /* // set X Y Z positions to Cube
    temp.setcenterPosX(centerPosX);
    temp.setcenterPosY(centerPosY);
    temp.setcenterPosZ(centerPosZ);
    temp.setedgeLength(edgeLength);*/
    return temp;
}

std::vector<Cube> mengeAndsponge(GLfloat centerPosX, GLfloat centerPosY, GLfloat centerPosZ, GLfloat edgeLength){

    // Set parameters
    GLfloat thirdEdgeLength = edgeLength;
/*
    GLfloat centerPosX = halfScreenWidth;
    GLfloat centerPosY = halfScreenHeight;
    GLfloat centerPosZ = centreZ;
*/

    std::vector<Cube> listCube;
    int counter = 0;
    Cube temp;

    // ************************** Bottom Half Cubes ***************************
    Vec3f threefloatTopleft = {-thirdEdgeLength , -thirdEdgeLength, thirdEdgeLength};
    temp = translate(drawCubePoints(centerPosX, centerPosY, centerPosZ, thirdEdgeLength), threefloatTopleft);
    temp.setx(centerPosX - thirdEdgeLength); temp.sety(centerPosY - thirdEdgeLength ); temp.setz(centerPosZ + thirdEdgeLength); temp.setedgeLength(thirdEdgeLength);
    listCube.push_back(temp);

    Vec3f threefloatOGX = {0 , -thirdEdgeLength, thirdEdgeLength};
    temp = translate(drawCubePoints(centerPosX, centerPosY, centerPosZ, thirdEdgeLength), threefloatOGX);
    temp.setx(centerPosX); temp.sety(centerPosY - thirdEdgeLength); temp.setz(centerPosZ + thirdEdgeLength); temp.setedgeLength(thirdEdgeLength);
    listCube.push_back(temp);

    Vec3f threefloatX2 = {thirdEdgeLength, -thirdEdgeLength, thirdEdgeLength};
    temp = translate(drawCubePoints(centerPosX, centerPosY, centerPosZ, thirdEdgeLength), threefloatX2);
    temp.setx(centerPosX + thirdEdgeLength); temp.sety(centerPosY - thirdEdgeLength); temp.setz(centerPosZ + thirdEdgeLength); temp.setedgeLength(thirdEdgeLength);
    listCube.push_back(temp);

    Vec3f threefloatOZ = {-thirdEdgeLength, -thirdEdgeLength, 0};
    temp = translate(drawCubePoints(centerPosX, centerPosY, centerPosZ, thirdEdgeLength), threefloatOZ);
    temp.setx(centerPosX - thirdEdgeLength); temp.sety(centerPosY - thirdEdgeLength); temp.setz(centerPosZ ); temp.setedgeLength(thirdEdgeLength);
    listCube.push_back(temp);

    Vec3f threefloatX2Z = {thirdEdgeLength, -thirdEdgeLength, 0};
    temp = translate(drawCubePoints(centerPosX, centerPosY, centerPosZ, thirdEdgeLength), threefloatX2Z);
    temp.setx(centerPosX + thirdEdgeLength ); temp.sety(centerPosY - thirdEdgeLength); temp.setz(centerPosZ ); temp.setedgeLength(thirdEdgeLength);
    listCube.push_back(temp);

    Vec3f threefloatY = {-thirdEdgeLength , -thirdEdgeLength, -thirdEdgeLength};
    temp = translate(drawCubePoints(centerPosX, centerPosY, centerPosZ, thirdEdgeLength), threefloatY);
    temp.setx(centerPosX - thirdEdgeLength); temp.sety(centerPosY - thirdEdgeLength); temp.setz(centerPosZ - thirdEdgeLength); temp.setedgeLength(thirdEdgeLength);
    listCube.push_back(temp);

    Vec3f threefloatY2 = {0 , -thirdEdgeLength, -thirdEdgeLength};
    temp = translate(drawCubePoints(centerPosX, centerPosY, centerPosZ, thirdEdgeLength), threefloatY2);
    temp.setx(centerPosX ); temp.sety(centerPosY - thirdEdgeLength); temp.setz(centerPosZ - thirdEdgeLength); temp.setedgeLength(thirdEdgeLength);
    listCube.push_back(temp);

    Vec3f threefloatXYY = {thirdEdgeLength , -thirdEdgeLength, -thirdEdgeLength};
    temp = translate(drawCubePoints(centerPosX, centerPosY, centerPosZ, thirdEdgeLength), threefloatXYY);
    temp.setx(centerPosX + thirdEdgeLength); temp.sety(centerPosY - thirdEdgeLength); temp.setz(centerPosZ - thirdEdgeLength); temp.setedgeLength(thirdEdgeLength);
    listCube.push_back(temp);

    // ********************** Mid 4 Cubes ***************************** //

    Vec3f threefloatY2Z = {-thirdEdgeLength , 0, thirdEdgeLength};
    temp = translate(drawCubePoints(centerPosX, centerPosY, centerPosZ, thirdEdgeLength), threefloatY2Z);
    temp.setx(centerPosX - thirdEdgeLength); temp.sety( centerPosY ); temp.setz(centerPosZ + thirdEdgeLength); temp.setedgeLength(thirdEdgeLength);
    listCube.push_back(temp);

    Vec3f threefloatXXYYZ = {-thirdEdgeLength , 0, -thirdEdgeLength};
    temp = translate(drawCubePoints(centerPosX, centerPosY, centerPosZ, thirdEdgeLength), threefloatXXYYZ);
    temp.setx(centerPosX - thirdEdgeLength ); temp.sety(centerPosY ); temp.setz(centerPosZ - thirdEdgeLength); temp.setedgeLength(thirdEdgeLength);
    listCube.push_back(temp);

    Vec3f threefloatXXYY = {thirdEdgeLength, 0, thirdEdgeLength};
    temp = translate(drawCubePoints(centerPosX, centerPosY, centerPosZ, thirdEdgeLength), threefloatXXYY);
    temp.setx(centerPosX + thirdEdgeLength); temp.sety(centerPosY ); temp.setz(centerPosZ + thirdEdgeLength); temp.setedgeLength(thirdEdgeLength);
    listCube.push_back(temp);

    Vec3f threefloatXXY = {thirdEdgeLength, 0, -thirdEdgeLength};
    temp = translate(drawCubePoints(centerPosX, centerPosY, centerPosZ, thirdEdgeLength), threefloatXXY);
    temp.setx(centerPosX + thirdEdgeLength); temp.sety(centerPosY); temp.setz(centerPosZ - thirdEdgeLength); temp.setedgeLength(thirdEdgeLength);
    listCube.push_back(temp);

    // ********************* Top Half Cubes **************************

    Vec3f threefloatOGZZ = {-thirdEdgeLength, thirdEdgeLength, thirdEdgeLength};
    temp = translate(drawCubePoints(centerPosX, centerPosY, centerPosZ, thirdEdgeLength), threefloatOGZZ);
    temp.setx(centerPosX - thirdEdgeLength); temp.sety(centerPosY + thirdEdgeLength ); temp.setz(centerPosZ + thirdEdgeLength); temp.setedgeLength(thirdEdgeLength);
    listCube.push_back(temp);

    Vec3f threefloatOGYYZZ = {0, thirdEdgeLength, thirdEdgeLength};
    temp = translate(drawCubePoints(centerPosX, centerPosY, centerPosZ, thirdEdgeLength), threefloatOGYYZZ);
    temp.setx(centerPosX); temp.sety(centerPosY + thirdEdgeLength); temp.setz(centerPosZ + thirdEdgeLength); temp.setedgeLength(thirdEdgeLength);
    listCube.push_back(temp);

    Vec3f threefloatOGXYYZZ = {thirdEdgeLength, thirdEdgeLength, thirdEdgeLength};
    temp = translate(drawCubePoints(centerPosX, centerPosY, centerPosZ, thirdEdgeLength), threefloatOGXYYZZ);
    temp.setx(centerPosX + thirdEdgeLength); temp.sety(centerPosY + thirdEdgeLength); temp.setz(centerPosZ + thirdEdgeLength ); temp.setedgeLength(thirdEdgeLength);
    listCube.push_back(temp);

    Vec3f threefloatOGYZZ = {-thirdEdgeLength, thirdEdgeLength, 0};
    temp = translate(drawCubePoints(centerPosX, centerPosY, centerPosZ, thirdEdgeLength), threefloatOGYZZ);
    temp.setx(centerPosX - thirdEdgeLength); temp.sety(centerPosY + thirdEdgeLength); temp.setz(centerPosZ ); temp.setedgeLength(thirdEdgeLength);
    listCube.push_back(temp);

    Vec3f threefloatOGXXYYZZ = {thirdEdgeLength, thirdEdgeLength, 0};
    temp = translate(drawCubePoints(centerPosX, centerPosY, centerPosZ, thirdEdgeLength), threefloatOGXXYYZZ);
    temp.setx(centerPosX + thirdEdgeLength ); temp.sety(centerPosY + thirdEdgeLength ); temp.setz(centerPosZ); temp.setedgeLength(thirdEdgeLength);
    listCube.push_back(temp);

    Vec3f threefloatOGXZZ = {-thirdEdgeLength, thirdEdgeLength, -thirdEdgeLength};
    temp = translate(drawCubePoints(centerPosX, centerPosY, centerPosZ, thirdEdgeLength), threefloatOGXZZ);
    temp.setx(centerPosX - thirdEdgeLength); temp.sety(centerPosY + thirdEdgeLength); temp.setz(centerPosZ - thirdEdgeLength); temp.setedgeLength(thirdEdgeLength);
    listCube.push_back(temp);

    Vec3f threefloatOGXXZZ = {0, thirdEdgeLength, -thirdEdgeLength};
    temp = translate(drawCubePoints(centerPosX, centerPosY, centerPosZ, thirdEdgeLength), threefloatOGXXZZ);
    temp.setx(centerPosX ); temp.sety(centerPosY + thirdEdgeLength); temp.setz(centerPosZ - thirdEdgeLength); temp.setedgeLength(thirdEdgeLength);
    listCube.push_back(temp);

    Vec3f threefloatOGXXYZZ = {thirdEdgeLength, thirdEdgeLength, -thirdEdgeLength};
    temp = translate(drawCubePoints(centerPosX, centerPosY, centerPosZ, thirdEdgeLength), threefloatOGXXYZZ);
    temp.setx(centerPosX + thirdEdgeLength); temp.sety(centerPosY + thirdEdgeLength); temp.setz(centerPosZ - thirdEdgeLength); temp.setedgeLength(thirdEdgeLength);
    listCube.push_back(temp);

    // for testing purposes
    // cout << listCube.size() << endl;
    return listCube;
}

void drawMenge(int depth) {
    GLfloat centerPosX = 0;
    GLfloat centerPosY = 0;
    GLfloat centerPosZ = 0;
    GLfloat edgeLength = 100;

    GLfloat newCenterX;
    GLfloat newCenterY;
    GLfloat newCenterZ;
    GLfloat newEdgeLength;

    // Base Recurse
   // draw(listCube);

   // Draw Base Cube
    std::vector<Cube> listCube;
    std::vector<Cube> templistCube;
    std::vector<Cube> storedCubes;

    listCube.push_back(drawCubePoints(centerPosX,  centerPosY, centerPosZ, edgeLength));
    draw(listCube);
    // listCube.clear();

    // Recursive part
    for (int depthCount = 1; depthCount <= depth; depthCount++) {
            // Base Menger
            if (depthCount == 1) {
                glClear(GL_COLOR_BUFFER_BIT);
                listCube = mengeAndsponge(centerPosX, centerPosY, centerPosZ, edgeLength);
                draw(listCube);
                // templistCube = listCube;
            }
            else {
                // each cube in list becomes 'center' cube, make more menger sponges based on each cube
                for (int k = 0; k < listCube.size(); k++) {
                    glClear(GL_COLOR_BUFFER_BIT);
                    newCenterX = listCube[k].getx();
                    newCenterY = listCube[k].gety();
                    newCenterZ = listCube[k].getz();
                    newEdgeLength = listCube[k].getedgeLength() / 3;
                    templistCube= mengeAndsponge(newCenterX, newCenterY, newCenterZ, newEdgeLength);

                    // take each created cube and append to master vector
                    for (int j = 0; j < templistCube.size(); j++){
                        storedCubes.push_back(templistCube[j]);
                    }
                }
                listCube = storedCubes;
                draw(listCube);
                // testing purposes
                // cout << listCube.size() << endl;
                }
            }
}

void draw(std::vector<Cube> listCube ){
    // Draw all Cubes stored in listCube
    glBegin(GL_QUADS);
    int count = 0;

    for(int i = 0; i < listCube.size(); i++) {
        Cube s = listCube[i];
        for (int j = 0; j < 24; j++) { // 24 verticie
            if (j % 4 == 0) {
                glColor3f(colors[count].x, colors[count].y, colors[count].z);
                count++;
            }
            glVertex3f(s[j].x, s[j].y, s[j].z);
        }
        count = 0;
    }
    glPopMatrix();
    glEnd();
}