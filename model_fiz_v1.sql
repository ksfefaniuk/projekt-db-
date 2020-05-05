--
-- File generated with SQLiteStudio v3.2.1 on wt. maj 5 21:54:12 2020
--
-- Text encoding used: UTF-8
--
PRAGMA foreign_keys = off;
BEGIN TRANSACTION;

-- Table: Klient
DROP TABLE IF EXISTS Klient;

CREATE TABLE Klient (
    k_id     INTEGER      PRIMARY KEY ASC AUTOINCREMENT
                          NOT NULL,
    imie     VARCHAR (20),
    nazwisko VARCHAR (20),
    telefon  INTEGER (9),
    k_mail   VARCHAR (30),
    adres    VARCHAR (40) 
);

INSERT INTO Klient (
                       k_id,
                       imie,
                       nazwisko,
                       telefon,
                       k_mail,
                       adres
                   )
                   VALUES (
                       1,
                       'Kamil',
                       'Kowalski',
                       312453745,
                       'kkowalski@gmail.com',
                       'Zamkowa 1'
                   );

INSERT INTO Klient (
                       k_id,
                       imie,
                       nazwisko,
                       telefon,
                       k_mail,
                       adres
                   )
                   VALUES (
                       2,
                       'Bognad',
                       'Dąb',
                       467273734,
                       'bdab@gmail.com',
                       'Klimasa 3'
                   );

INSERT INTO Klient (
                       k_id,
                       imie,
                       nazwisko,
                       telefon,
                       k_mail,
                       adres
                   )
                   VALUES (
                       3,
                       'Marta',
                       'Polanska',
                       461245234,
                       'mpolanska@gmail.com',
                       'Wolska 32'
                   );

INSERT INTO Klient (
                       k_id,
                       imie,
                       nazwisko,
                       telefon,
                       k_mail,
                       adres
                   )
                   VALUES (
                       4,
                       'Anna',
                       'Dachowska',
                       727323735,
                       'adach@hmail.com',
                       'Zimowa 33/1'
                   );


-- Table: Serwis
DROP TABLE IF EXISTS Serwis;

CREATE TABLE Serwis (
    s_id  INTEGER       PRIMARY KEY ASC AUTOINCREMENT
                        NOT NULL,
    data1 VARCHAR(20),
    Opis  VARCHAR (200) 
);

INSERT INTO Serwis (
                       s_id,
                       data1,
                       Opis
                   )
                   VALUES (
                       1,
                       '12/04/2018',
                       'Podstawowy serwis'
                   );

INSERT INTO Serwis (
                       s_id,
                       data1,
                       Opis
                   )
                   VALUES (
                       2,
                       '13/01/2019',
                       'Podstawowy serwis'
                   );

INSERT INTO Serwis (
                       s_id,
                       data1,
                       Opis
                   )
                   VALUES (
                       3,
                       '29/07/2019',
                       'Naprawa'
                   );


-- Table: Serwis_detal
DROP TABLE IF EXISTS Serwis_detal;

CREATE TABLE Serwis_detal (
    id_detal INTEGER      PRIMARY KEY ASC AUTOINCREMENT
                          NOT NULL,
    adres1   VARCHAR (40),
    telefon1 VARCHAR (9),
    data2    VARCHAR (20),
    FOREIGN KEY(adres1) REFERENCES Klient(adres),
    FOREIGN KEY(telefon1) REFERENCES Klient(telefon),
    FOREIGN KEY(data2) REFERENCES Serwis(data1)
);

INSERT INTO Serwis_detal (
                             id_detal,
                             adres1,
                             telefon1,
                             data2
                         )
                         VALUES (
                             1,
                             NULL,
                             NULL,
                             NULL
                         );

INSERT INTO Serwis_detal (
                             id_detal,
                             adres1,
                             telefon1,
                             data2
                         )
                         VALUES (
                             2,
                             NULL,
                             NULL,
                             NULL
                         );

INSERT INTO Serwis_detal (
                             id_detal,
                             adres1,
                             telefon1,
                             data2
                         )
                         VALUES (
                             3,
                             NULL,
                             NULL,
                             NULL
                         );


-- Table: Urzadzenie
DROP TABLE IF EXISTS Urzadzenie;

CREATE TABLE Urzadzenie (
    u_id  INTEGER      PRIMARY KEY ASC AUTOINCREMENT
                       NOT NULL,
    Marka VARCHAR (30),
    Model VARCHAR (30) 
);

INSERT INTO Urzadzenie (
                           u_id,
                           Marka,
                           Model
                       )
                       VALUES (
                           1,
                           'Fujitsu',
                           'Luxury 2.0'
                       );

INSERT INTO Urzadzenie (
                           u_id,
                           Marka,
                           Model
                       )
                       VALUES (
                           2,
                           'Fujitsu',
                           'Economic'
                       );

INSERT INTO Urzadzenie (
                           u_id,
                           Marka,
                           Model
                       )
                       VALUES (
                           3,
                           'Gree',
                           'U-crown'
                       );


-- Table: Użytkownik
DROP TABLE IF EXISTS Użytkownik;

CREATE TABLE Użytkownik (
    us_id  INTEGER      PRIMARY KEY ASC AUTOINCREMENT
                        NOT NULL,
    u_name VARCHAR (30),
    u_pass VARCHAR (30),
    u_mail VARCHAR (40) 
);

INSERT INTO Użytkownik (
                           us_id,
                           u_name,
                           u_pass,
                           u_mail
                       )
                       VALUES (
                           1,
                           'admin',
                           'password123',
                           'admin@gmail.com'
                       );


COMMIT TRANSACTION;
PRAGMA foreign_keys = on;
