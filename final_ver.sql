--
-- File generated with SQLiteStudio v3.2.1 on pon. maj 11 23:28:13 2020
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
    data1 VARCHAR (20)  NOT NULL,
    opis  VARCHAR (200) 
);

INSERT INTO Serwis (
                       s_id,
                       data1,
                       opis
                   )
                   VALUES (
                       1,
                       '01.03.14',
                       'Czyszczenie'
                   );

INSERT INTO Serwis (
                       s_id,
                       data1,
                       opis
                   )
                   VALUES (
                       2,
                       '31.01.09',
                       'Serwis'
                   );

INSERT INTO Serwis (
                       s_id,
                       data1,
                       opis
                   )
                   VALUES (
                       3,
                       '21.03.11',
                       'Naprawa'
                   );


-- Table: Serwisowanie
DROP TABLE IF EXISTS Serwisowanie;

CREATE TABLE Serwisowanie (
    ser_id INTEGER PRIMARY KEY ASC AUTOINCREMENT
                   NOT NULL,
    u_id1          NOT NULL
                   REFERENCES Urzadzenie (u_id),
    us_id1         REFERENCES Uzytkownik (us_id) 
                   NOT NULL
);

INSERT INTO Serwisowanie (
                             ser_id,
                             u_id1,
                             us_id1
                         )
                         VALUES (
                             1,
                             2,
                             1
                         );

INSERT INTO Serwisowanie (
                             ser_id,
                             u_id1,
                             us_id1
                         )
                         VALUES (
                             2,
                             1,
                             1
                         );

INSERT INTO Serwisowanie (
                             ser_id,
                             u_id1,
                             us_id1
                         )
                         VALUES (
                             3,
                             3,
                             1
                         );


-- Table: Urzadzenie
DROP TABLE IF EXISTS Urzadzenie;

CREATE TABLE Urzadzenie (
    u_id  INTEGER      PRIMARY KEY ASC AUTOINCREMENT
                       NOT NULL,
    k_id1              REFERENCES Klient (k_id),
    Marka VARCHAR (30),
    Model VARCHAR (30) 
);

INSERT INTO Urzadzenie (
                           u_id,
                           k_id1,
                           Marka,
                           Model
                       )
                       VALUES (
                           1,
                           NULL,
                           'Fujitsu',
                           'Luxury 2.0'
                       );

INSERT INTO Urzadzenie (
                           u_id,
                           k_id1,
                           Marka,
                           Model
                       )
                       VALUES (
                           2,
                           NULL,
                           'Fujitsu',
                           'Economic'
                       );

INSERT INTO Urzadzenie (
                           u_id,
                           k_id1,
                           Marka,
                           Model
                       )
                       VALUES (
                           3,
                           NULL,
                           'Gree',
                           'U-crown'
                       );


-- Table: Uzytkownik
DROP TABLE IF EXISTS Uzytkownik;

CREATE TABLE Uzytkownik (
    us_id  INTEGER      PRIMARY KEY ASC AUTOINCREMENT
                        NOT NULL,
    u_name VARCHAR (30),
    u_pass VARCHAR (30),
    u_mail VARCHAR (40) 
);

INSERT INTO Uzytkownik (
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
