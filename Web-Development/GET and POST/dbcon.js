var mysql = require('mysql');
var pool = mysql.createPool({
  connectionLimit : 10,
  host            : 'mysql.eecs.oregonstate.edu',
  user            : 'cs290_alltope',
  password        : '0944',
  database        : 'cs290_alltope'
});

module.exports.pool = pool;
