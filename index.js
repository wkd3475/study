var mysql = require('mysql');

var connection = mysql.createConnection({

	host:'localhost'

	,user:'wkd3475'

    ,password:'2rnlska',

    port: 3306,
    
    database: ''

});

connection.connect();

connection.query('use test;');

function change() {
     $('form').animate({height: "toggle", opacity: "toggle"}, "slow");
 }

function login() {
     
 }

function accountCreate() {
    connection.query("insert into user (user_name, user_password, user_email_address) values('test', 'test123', 'test@gmail.com');")
 }