/*
	@File 		nokia5110.cpp
	@Author		JOSIMAR PEREIRA LEITE
	@country	Brazil
	@Date		07/06/2021
	

    Copyright (C) 2021  JOSIMAR PEREIRA LEITE

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.
*/ 

#define F_CPU 16000000UL

#include <avr/io.h>
#include <util/delay.h>
#include <stdio.h>

#include "nokia5110.h"
#include "i2c.h"

NOKIA5110 nokia5110;

#define PCA9536_SLA_W				0B10000010
#define PCA9536_SLA_R				0B10000011

#define PCA9536_INPUT				0B00000000
#define PCA9536_OUTPUT				0B00000001
#define PCA9536_POLARITY_INV		0B00000010
#define PCA9536_CONFIG				0B00000011

void PCA9536_cmd(char reg, char data)
{
	i2c_start();
	i2c_write(PCA9536_SLA_W);
	i2c_write(reg);
	i2c_write(data);
	i2c_stop();
}

void PCA9536_write(char data)
{
	i2c_start();
	i2c_write(PCA9536_SLA_W);
	i2c_write(PCA9536_OUTPUT);
	i2c_write(data);
	i2c_stop();
}


int main()
{
	i2c_init( F_CPU );
	
	nokia5110.Init();
	
	PCA9536_cmd(PCA9536_CONFIG, PCA9536_INPUT);
	
	PCA9536_cmd(PCA9536_CONFIG, PCA9536_INPUT);
	
	
	PCA9536_write(0B00000001);
	
	while(1);
}