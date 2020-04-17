#!/usr/bin/env bash
set -e

echo '-- downloading SQLite...'
wget https://www.sqlite.org/2020/sqlite-amalgamation-3310100.zip
unzip sqlite-amalgamation-3310100.zip
mkdir -p Hadrons/sqlite/
mv sqlite-amalgamation-3310100/sqlite3* Hadrons/sqlite/
rm -rf sqlite-amalgamation-3310100 sqlite-amalgamation-3310100.zip
echo '-- generating configure script...'
mkdir -p .buildutils/m4
autoreconf -fvi