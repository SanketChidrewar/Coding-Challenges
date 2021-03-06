/*
 * students.cpp
 *
 *  Created on: 17-Apr-2020
 *      Author: sunbeam
 */

#include "students.h"
#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

students::students() {
	// TODO Auto-generated constructor stub
	this->id=0;
	this->name = " ";
	this->rank_a=0;
	this->rank_b=0;
	this->rank_c=0;
	this->degree = " ";
	this->degree_marks=0;
	this->allocated_pref=0;
	this->course_name = " ";
	this->center_id = " ";
	this->payment=0;
	this->reported=0;
	this->prn = " ";
}

students::students(int id, string name, int rank_a, int rank_b, int rank_c, string degree, double degree_marks, int allocated_pref, string course_name, string center_id, double payment, int reported, string prn)
{
	this->id=id;
	this->name = name;
	this->rank_a=rank_a;
	this->rank_b=rank_b;
	this->rank_c=rank_c;
	this->degree = degree;
	this->degree_marks=degree_marks;
	this->allocated_pref= allocated_pref;
	this->course_name = course_name;
	this->center_id = center_id;
	this->payment=0;
	this->reported=0;
	this->prn = prn;
}

int students::getAllocatedPref() const {
	return allocated_pref;
}

void students::setAllocatedPref(int allocatedPref) {
	allocated_pref = allocatedPref;
}

const string& students::getCenterId() const {
	return center_id;
}

void students::setCenterId(const string& centerId) {
	center_id = centerId;
}

const string& students::getCourseName() const {
	return course_name;
}

void students::setCourseName(const string& courseName) {
	course_name = courseName;
}

const string& students::getDegree() const {
	return degree;
}

void students::setDegree(const string& degree) {
	this->degree = degree;
}

double students::getDegreeMarks() const {
	return degree_marks;
}

void students::setDegreeMarks(double degreeMarks) {
	degree_marks = degreeMarks;
}

int students::getId() const {
	return id;
}

void students::setId(int id) {
	this->id = id;
}

const string& students::getName() const {
	return name;
}

void students::setName(const string& name) {
	this->name = name;
}

double students::getPayment() const {
	return payment;
}

void students::setPayment(double payment) {
	this->payment = payment;
}

const string& students::getPrn() const {
	return prn;
}

void students::setPrn(const string& prn) {
	this->prn = prn;
}

int students::getRankA() const {
	return rank_a;
}

void students::setRankA(int rankA) {
	rank_a = rankA;
}

int students::getRankB() const {
	return rank_b;
}

void students::setRankB(int rankB) {
	rank_b = rankB;
}

int students::getRankC() const {
	return rank_c;
}

void students::setRankC(int rankC) {
	rank_c = rankC;
}

int students::getReported() const {
	return reported;
}

void students::setReported(int reported) {
	this->reported = reported;
}

void students::display_students()
{
	cout<<this->id<<","<<this->name<<","<<this->rank_a<<","<<this->rank_b<<","<<this->rank_c<<","<<this->degree;
	cout<<","<<this->degree_marks<<","<<this->allocated_pref<<","<<this->course_name<<","<<this->center_id<<","<<this->payment;
	cout<<","<<this->reported<<","<<this->prn<<endl;
}

students::~students() {
	// TODO Auto-generated destructor stub
}

