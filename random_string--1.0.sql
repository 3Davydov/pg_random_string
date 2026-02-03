/* contrib/random_string/random_string--1.0.sql */

\echo Use "CREATE EXTENSION random_string" to load this file. \quit

CREATE FUNCTION generate_random_string(length INT DEFAULT 20)
RETURNS TEXT
AS 'MODULE_PATHNAME', 'generate_random_string'
LANGUAGE C STRICT;
