CREATE TABLE Devices (
	DeviceID      INT NOT NULL AUTO_INCREMENT,
	Name          VARCHAR(255) NOT NULL,
	IP            VARCHAR(255) NOT NULL,
  GeraeteNummer INT NOT NULL,
	Heat          INT,
	Light         INT,
	Hue           INT,
	Saturation    INT,
	Switch        INT,
	Brightness    INT,
	PRIMARY KEY (DeviceID)
);
