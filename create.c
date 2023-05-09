#include <kipr/wombat.h>

//speed values
int lspeed;
int rspeed;
int armspeed;

//ports
int arm;
int claw;
int base;
int etSensor;
 
//servo values
int open;
int close;
int high;
int low;
int set;
int grab;
int stack;
int place;

//encoders
int deg;
int cm;

//drive functions
void forward(int distance) {
  set_create_distance(0);
  while(get_create_distance() < distance*cm){
    create_drive_direct(rspeed, lspeed);
    msleep(10);
  }
  create_drive_direct(0,0);
}

void backward(int distance) {
  set_create_distance(0);
  while(abs(get_create_distance()) < distance*cm){
    create_drive_direct(-rspeed, -lspeed);
    msleep(10);
  }
  create_drive_direct(0,0);
}

void rturn(int angle) {
  set_create_angle_turned(0);
  while(abs(get_create_angle_turned()) < angle*deg) {
    create_drive_direct(-rspeed, lspeed);
    msleep(10);
  }
  create_drive_direct(0,0);
}

void lturn(int angle) {
  set_create_angle_turned(0);
  while(abs(get_create_angle_turned()) < angle*deg) {
    create_drive_direct(rspeed, -lspeed);
    msleep(10);
  }
  create_drive_direct(0,0);
}

void forward_wallride(int distance) {
  set_create_distance(0);
  while(get_create_distance() < distance*cm){
    if(get_create_lbump() == 0) {
      create_drive_direct(lspeed-100, rspeed);
      msleep(10);
    } 
    else{
      create_drive_direct(rspeed, lspeed);
      msleep(10);
    }
  }
  create_drive_direct(0,0);
}

void backward_wallride(int distance) {
  while(get_create_distance() < distance*cm){
    if(get_create_lbump() == 0) {
      create_drive_direct(-lspeed-100, -rspeed);
      msleep(10);
    } 
    else{
      create_drive_direct(-rspeed, -lspeed);
      msleep(10);
    }
  }
  create_drive_direct(0,0);
}

//grab functions
void high;
void low;

//drop functions
void stack;
void botgal;


