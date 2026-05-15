$port = New-Object System.IO.Ports.SerialPort COM4,9600
$port.Open()
while($true){$port.ReadLine()}