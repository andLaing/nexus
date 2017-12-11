#ifndef HDF5_FUNCTIONS_H
#define HDF5_FUNCTIONS_H

#include <hdf5.h>
#include <iostream>

  /* typedef struct{ */
  /*   int channel; */
  /*   int sensorID; */
  /* } sensor_t; */

  /* typedef struct{ */
  /*   int run_number; */
  /* } runinfo_t; */

  typedef struct{
    int evt_number;
    int init_sns_data;
    int init_hit;
    int init_particle;
  
  } evt_limit_t;

  typedef struct{
    int evt_number;
    float evt_energy;
  } evt_t;

  typedef struct{
    unsigned int sensor_id;
    unsigned int time_bin;
    unsigned int charge;
  } sns_data_t;

  typedef struct{
	int hit_indx;
	float hit_position[3];
	float hit_time;
	float hit_energy;
        char label[20];
        int track_indx;
  } hit_info_t;

  typedef struct{
	int track_indx;
	char particle_name[20];
        char primary;
	int pdg_code;
	float initial_vertex[4];
	float final_vertex[4];
        char initial_volume[20];
        char final_volume[20];
	float momentum[4];
	float energy;
  } particle_info_t;

  hsize_t createEventType();
  hsize_t createSensorDataType();
  hsize_t createHitInfoType();
  hsize_t createParticleInfoType();
//  hid_t createRunType();
//  hid_t createSensorType();
  hid_t createTable(hid_t group, std::string& table_name, hsize_t memtype);
  hid_t createGroup(hid_t file, std::string& groupName);

  //  void WriteWaveforms(short int * data, hid_t dataset, hsize_t nsensors, hsize_t nsamples, hsize_t evt);
  // hid_t createWaveforms(hid_t group, std::string& dataset, hsize_t nsensors, hsize_t nsamples);

  // void WriteWaveform(short int * data, hid_t dataset, hsize_t nsamples, hsize_t evt);
  // hid_t createWaveform(hid_t group, std::string& dataset, hsize_t nsamples);

  void writeEvent(evt_t * evtData, hid_t dataset, hid_t memtype, hsize_t evt_number);
  void writeSnsData(sns_data_t* snsData, hid_t dataset, hid_t memtype, hsize_t counter);
  void writeHitInfo(hit_info_t* hitInfo, hid_t dataset, hid_t memtype, hsize_t counter);
  void writeParticleInfo(particle_info_t* particleInfo, hid_t dataset, hid_t memtype, hsize_t counter);
// void writeRun(runinfo_t * runData, hid_t dataset, hid_t memtype, hsize_t evt_number);
  // void writeSensor(sensor_t * sensorData, hid_t dataset, hid_t memtype, hsize_t sensor_number);
 


#endif

