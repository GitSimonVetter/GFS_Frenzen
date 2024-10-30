# Server-Skript: Startet einen TCP-Listener auf Port 8080
$listener = New-Object System.Net.Sockets.TcpListener([System.Net.IPAddress]::Any, 8080)

# Starte den TCP-Listener
try{
    $listener.Start()
    Write-Output "Warte auf Verbindung..."
}
catch
{
    Write-Output "Fehler: $_"
}


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
        Write-Output "Client: $message"

        $command = Read-Host -Prompt "Befehl:"
        if ($command) # Überprüfe, ob die Nachricht nicht null ist
        { 
            # Antwort an den Client senden
            $writer.WriteLine($command)
        }
        $message = $reader.ReadLine()
        Write-Output "Client: $message"
        # Schließe den Client nach der Kommunikation
        $client.Close()
    } catch {
        
    }
}