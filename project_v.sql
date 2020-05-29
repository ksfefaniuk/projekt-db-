--
-- File generated with SQLiteStudio v3.2.1 on pt. maj 29 11:33:31 2020
--
-- Text encoding used: UTF-8
--
PRAGMA foreign_keys = off;
BEGIN TRANSACTION;

-- Table: Klient
DROP TABLE IF EXISTS Klient;

CREATE TABLE Klient (
    k_id     INTEGER      PRIMARY KEY ASC AUTOINCREMENT,
    imie     VARCHAR (20) NOT NULL,
    nazwisko VARCHAR (20) NOT NULL,
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

INSERT INTO Klient (
                       k_id,
                       imie,
                       nazwisko,
                       telefon,
                       k_mail,
                       adres
                   )
                   VALUES (
                       5,
                       'Stefan',
                       'Kowal',
                       312323221,
                       'sstefanski@gmail.com',
                       'Niska 3/22'
                   );


-- Table: Naprawa
DROP TABLE IF EXISTS Naprawa;

CREATE TABLE Naprawa (
    s_id   INTEGER       PRIMARY KEY ASC AUTOINCREMENT,
    us_id2               REFERENCES Uzytkownik (us_id),
    u_id2                REFERENCES Urzadzenie (u_id),
    data1  VARCHAR (20)  NOT NULL,
    opis   VARCHAR (200) 
);

INSERT INTO Naprawa (
                        s_id,
                        us_id2,
                        u_id2,
                        data1,
                        opis
                    )
                    VALUES (
                        1,
                        2,
                        3,
                        '01.03.14',
                        'Czyszczenie'
                    );

INSERT INTO Naprawa (
                        s_id,
                        us_id2,
                        u_id2,
                        data1,
                        opis
                    )
                    VALUES (
                        2,
                        4,
                        2,
                        '31.01.09',
                        'Serwis'
                    );

INSERT INTO Naprawa (
                        s_id,
                        us_id2,
                        u_id2,
                        data1,
                        opis
                    )
                    VALUES (
                        3,
                        1,
                        1,
                        '21.03.11',
                        'Naprawa'
                    );

INSERT INTO Naprawa (
                        s_id,
                        us_id2,
                        u_id2,
                        data1,
                        opis
                    )
                    VALUES (
                        4,
                        'test1',
                        2,
                        '31.12.12',
                        'Serwis'
                    );

INSERT INTO Naprawa (
                        s_id,
                        us_id2,
                        u_id2,
                        data1,
                        opis
                    )
                    VALUES (
                        5,
                        'test2',
                        2,
                        '02.02.20',
                        'Naprawa'
                    );


-- Table: Serwisowanie
DROP TABLE IF EXISTS Serwisowanie;

CREATE TABLE Serwisowanie (
    ser_id INTEGER PRIMARY KEY ASC AUTOINCREMENT,
    u_id1          NOT NULL
                   REFERENCES Urzadzenie (u_id) 
                   UNIQUE,
    us_id1         REFERENCES Uzytkownik (us_id) 
                   NOT NULL,
				   UNIQUE (u_id1, us_id1)
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
                             3,
                             1
                         );

INSERT INTO Serwisowanie (
                             ser_id,
                             u_id1,
                             us_id1
                         )
                         VALUES (
                             3,
                             1,
                             1
                         );

INSERT INTO Serwisowanie (
                             ser_id,
                             u_id1,
                             us_id1
                         )
                         VALUES (
                             4,
                             4,
                             2
                         );

INSERT INTO Serwisowanie (
                             ser_id,
                             u_id1,
                             us_id1
                         )
                         VALUES (
                             5,
                             5,
                             5
                         );


-- Table: Urzadzenie
DROP TABLE IF EXISTS Urzadzenie;

CREATE TABLE Urzadzenie (
    u_id  INTEGER      PRIMARY KEY ASC AUTOINCREMENT,
    k_id1              REFERENCES Klient (k_id),
    Marka VARCHAR (30) NOT NULL,
    Model VARCHAR (30) NOT NULL
);

INSERT INTO Urzadzenie (
                           u_id,
                           k_id1,
                           Marka,
                           Model
                       )
                       VALUES (
                           1,
                           1,
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
                           3,
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
                           3,
                           'Gree',
                           'U-crown'
                       );

INSERT INTO Urzadzenie (
                           u_id,
                           k_id1,
                           Marka,
                           Model
                       )
                       VALUES (
                           4,
                           2,
                           'Samsung',
                           'Swing'
                       );

INSERT INTO Urzadzenie (
                           u_id,
                           k_id1,
                           Marka,
                           Model
                       )
                       VALUES (
                           5,
                           5,
                           'LG',
                           'Pearl'
                       );


-- Table: Uzytkownik
DROP TABLE IF EXISTS Uzytkownik;

CREATE TABLE Uzytkownik (
    us_id  INTEGER      PRIMARY KEY ASC AUTOINCREMENT,
    u_name VARCHAR (30) UNIQUE
                        NOT NULL,
    u_pass VARCHAR (30) NOT NULL,
    u_mail VARCHAR (40) NOT NULL
                        UNIQUE
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

INSERT INTO Uzytkownik (
                           us_id,
                           u_name,
                           u_pass,
                           u_mail
                       )
                       VALUES (
                           2,
                           'test1',
                           'test123',
                           'test@o2o.pl'
                       );

INSERT INTO Uzytkownik (
                           us_id,
                           u_name,
                           u_pass,
                           u_mail
                       )
                       VALUES (
                           3,
                           'test2',
                           'test123',
                           'eqweqw@o2.pl'
                       );

INSERT INTO Uzytkownik (
                           us_id,
                           u_name,
                           u_pass,
                           u_mail
                       )
                       VALUES (
                           4,
                           'Kamzi',
                           'test123',
                           'tes@o2o2.pl'
                       );

INSERT INTO Uzytkownik (
                           us_id,
                           u_name,
                           u_pass,
                           u_mail
                       )
                       VALUES (
                           5,
                           'master',
                           'master123',
                           'ms@o2o.pl'
                       );


COMMIT TRANSACTION;
PRAGMA foreign_keys = on;
