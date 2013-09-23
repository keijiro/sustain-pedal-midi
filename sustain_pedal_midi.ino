// Sustain pedal to MIDI converter
// by Keijiro Takahashi, 2013

boolean prevPedal = false;

void setup()
{
  // MIDI data rate.
  Serial.begin(31250);
  
  // Set pin-3 as input, and pull-up.
  pinMode(3, INPUT);
  digitalWrite(3, HIGH);
  
  // LED.
  pinMode(13, OUTPUT);
}

void loop()
{
  // Read the input.
  boolean pedal = (digitalRead(3) == 0);
  
  // Only when the state was changed.
  if (pedal != prevPedal) {
    // Send a sustain on/off message.
    Serial.write(0xb0);
    Serial.write(0x40);
    Serial.write(pedal ? 0x7f : 0);
    digitalWrite(13, pedal);
    prevPedal = pedal;
  }
  
  // 10 ms interval.
  delay(10);
}

