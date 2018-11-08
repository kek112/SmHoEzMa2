
USE smhoezma;

CREATE TABLE Devices (
	DeviceID      INT NOT NULL AUTO_INCREMENT,
	Name          VARCHAR(255) NOT NULL,
	IP            VARCHAR(255) NOT NULL,
	GeräteNummer  DECIMAL NOT NULL,
	Settings      VARCHAR(255) NOT NULL,
	PRIMARY KEY (DeviceID)
);
