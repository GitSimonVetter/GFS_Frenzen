# Server-Skript: Startet einen TCP-Listener auf Port 80
$listener = New-Object System.Net.Sockets.TcpListener([System.Net.IPAddress]::Any, 8080)

# Starte den TCP-Listener
$listener.Start()
Write-Output "Warte auf Verbindung..."

while ($true) {
    try {
        # Akzeptiere einen eingehenden Client
        $client = $listener.AcceptTcpClient()
        Write-Output "Client verbunden!"

        # Erstelle den Stream, Reader und Writer
        $stream = $client.GetStream()
        $reader = New-Object System.IO.StreamReader($stream)
        $writer = New-Object System.IO.StreamWriter($stream)
        $writer.AutoFlush = $true

        # Nachricht empfangen
        $message = $reader.ReadLine()
        if ($message) {  # Überprüfe, ob die Nachricht nicht null ist
            Write-Output "Nachricht empfangen1: $message"

            # Antwort an den Client senden
            $writer.WriteLine("Nachricht empfangen2: $message")
        }

        # Schließe den Client nach der Kommunikation
        $client.Close()
    } catch {
        
    }
}