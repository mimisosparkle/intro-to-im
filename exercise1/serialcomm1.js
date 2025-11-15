let port;
let sensorValue = 0;
let baudrate = 9600;

function setup() {
  createCanvas(400, 400);

// creates serial connection
port = createSerial();

// reopens previous port automatically if available
let usedPorts = usedSerialPorts();
if (usedPorts.length > 0) {
    port.open(usedPorts[0], baudrate);
  }

  textSize(16);
}

function draw() {
  background(220);
  

  // read sensor value from Arduino
  let data = port.readUntil("\n");
  if (data.length > 0) {
    sensorValue = int(trim(data)); // convert from string to number
  }

  // maps potentiometer range (0–1023) to screen width
  let x = map(sensorValue, 0, 1023, 0, width);
  let y = height / 2;

  //draws ellipse 
  ellipse(x, y, 50, 50);

  
  fill(0);
  text("Sensor value: " + sensorValue, 20, 30);
}

function keyPressed() {
  if (key == " ") {
    // press SPACE to open serial port
    if (!port.opened()) {
      port.open("Arduino", baudrate);
    } else {
      port.close();
    }
  }
}
