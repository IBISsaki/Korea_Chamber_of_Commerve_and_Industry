var express = require('express');
var app = express();

var temp = '';
var humi = '';

var http     = require('http').Server(app);
var io       = require('socket.io')(http);

var SerialPort = require('serialport').SerialPort;

var ReadlineParser = require('@serialport/parser-readline').ReadlineParser;

var parsers    = SerialPort.parsers;
var sp = new SerialPort( 
{

  path: 'COM3',

  baudRate: 9600,
});

const parser = sp.pipe(new ReadlineParser({ delimiter: '\r\n' }));

sp.on('open', () => console.log('Port open'));
var ledStatus ="";
parser.on('data', function (data) {
  var rcv = data.toString();
  ////////////////////////////////////////////////////////
  if (rcv.substring(0, 4) == 'temp'){

		temp = rcv.substring(4,6);
		console.log("temp = " + temp);
		io.emit('temp', temp);
  }
  if (rcv.substring(0, 4) == 'humi'){

		humi = rcv.substring(4,6)
		console.log("humi = " + humi);
		io.emit('humi', humi);
  }
});

 

app.get('/led_on',function(req,res)

{
	sp.write('led1\n\r', function(err){

		if (err) {

            return console.log('Error on write: ', err.message);

        }

        console.log('send: led on');

		res.writeHead(200, {'Content-Type': 'text/plain'});

		res.end('LED ON\n');

	});

});

 

app.get('/led_off',function(req,res)

{
	sp.write('led0\n\r', function(err){

		if (err) {

            return console.log('Error on write: ', err.message);

        }

        console.log('send: led off');

		res.writeHead(200, {'Content-Type': 'text/plain'});

		res.end('LED OFF\n');

	}); 

});

app.use(express.static(__dirname + '/public'));

const port = 3000;
http.listen(port, function () {
  console.log('Server listening on http://localhost:' + port);
});