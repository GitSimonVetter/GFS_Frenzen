# Client-Skript: Verbindet sich zum Server auf Port 8080
$serverAddress = "127.0.0.1"  # localhost für Testzwecke
$port = 8080                    # Der gleiche Port wie im Server-Skript

try {
    $client = New-Object System.Net.Sockets.TcpClient($serverAddress, $port)
    $stream = $client.GetStream()
    $writer = New-Object System.IO.StreamWriter($stream)
    $reader = New-Object System.IO.StreamReader($stream)
    $writer.AutoFlush = $true

    # Nachricht an den Server senden
    $message = "Hallo, dies ist eine Nachricht vom Client.1"
    $writer.WriteLine($message)

    # Antwort vom Server lesen
    $response = $reader.ReadLine()
    Write-Output "Antwort vom Server2: $response"

    # Schließe die Verbindung
    $client.Close()
} catch {
    Write-Output "Fehler bei der Verbindung: $_"
}