DROP TABLE akill CASCADE;
CREATE TABLE akill (
  id              SERIAL PRIMARY KEY,
  mask            VARCHAR(255) NOT NULL,
  reason          VARCHAR(255) NOT NULL,
  setter          INTEGER REFERENCES account(id) ON DELETE SET NULL,
  time            INTEGER NOT NULL,
  duration        INTEGER NOT NULL,
  UNIQUE (mask)
);

DROP TABLE sent_mail;
CREATE TABLE sent_mail (
  id              SERIAL PRIMARY KEY,
  account_id      INTEGER NOT NULL REFERENCES account(id) ON DELETE CASCADE,
  email           VARCHAR(255) NOT NULL,
  sent            INTEGER NOT NULL
);
