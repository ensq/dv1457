#! /usr/bin/python -tt

import sys
import getopt

import time
import datetime

import log_sum_filter
from log_sum_filter import log_sum_filter

# Queries:
import log_sum_queries
from log_sum_queries import Queries
import log_sum_c
from log_sum_c import log_sum_c

# How to call the script:
# ---
# log_sum(.sh|.py) [-n N] [-h H|-d D] [-c|-2|-r|-F|-t|-f] <filename>
# Use Python 3.4 or above.
# ---
# -n: Limit the number of results to N.
# -h: Limit the query to the last number of hours (< 24).
# -d: Limit the query to the last number of days (counting from midnight).
# -c: Which IP address makes the most number of connection attempts?
# -2: Which address makes the most number of successful attempts?
# -r: What are the most common results codes and where do they come from?
# -F: What are the most common result codes that indicate failure (no auth, not found etc) and where do they come from?
# -t: Which IP number get the most bytes sent to them?
# -f: Which IP number sends the most bytes to the server <filename> refers to the logfile. If '-' is given as a filename, or no filename is given, then standard input should be read. This enables the script to be used in a pipeline.


# Parse arguments using getopt:
try:
	opts, args = getopt.getopt( sys.argv[1:], ":n:|:h:d:|:c2rFtf" )
except getopt.GetoptError as e:
	print( e )
	sys.exit( 2 )

q = Queries.Queries_NA
date = datetime.datetime.now()

# Interpret arguments parsed to script:
for opt, arg in opts:
	if opt == "-n":
		print( "log_sum: Arglimit" )
	if opt in ( "-h", "-d" ):
		if opt == "-h": # Now - Hours
			date = date + datetime.timedelta( hours = -int(arg) )
		elif opt == "-d": # Now - Days
			date = date + datetime.timedelta( days = -int(arg) )
	if opt in ( "-c", "-2", "-r", "-F", "-t", "-f" ):
		if opt == "-c":
			q = Queries.Queries_c
		elif opt == "-2":
			q = Queries.Queries_2
		elif opt == "-r":
			q = Queries.Queries_r
		elif opt == "-F":
			q = Queries.Queries_F
		elif opt == "-t":
			q = Queries.Queries_t
		elif opt == "-f":
			q = Queries.Queries_f

# Filter the input according to date:
src = log_sum_filter( "thttpd.log", date ) #Temp, this ought to be read as a parameter

# Call the specified query:
results=[]
if q == Queries.Queries_c:
	log_sum_c( src, results )

sys.exit( 0 )