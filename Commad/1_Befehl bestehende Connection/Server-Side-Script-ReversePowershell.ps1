#Setup Variablen
$decision = $true
$message = $null

# Server-Skript: Startet einen TCP-Listener auf Port 4444
$listener = New-Object System.Net.Sockets.TcpListener([System.Net.IPAddress]::Any, 4444)

try{
    # Starte den TCP-Listener
    $listener.Start()
    Write-Output "Warte auf Verbindung..." + $port

    # Akzeptiere einen eingehenden Client
    $client = $listener.AcceptTcpClient()
    Write-Output "Client verbunden!"
    
    # Erstelle den Stream, Reader und Writer
    $stream = $client.GetStream()
    $reader = New-Object System.IO.StreamReader($stream)
    $writer = New-Object System.IO.StreamWriter($stream)
    $writer.AutoFlush = $true
while ($decision) 
    {
        try 
        {
            $command = Read-Host -Prompt "Befehl:"
            if ($command) # Überprüfe, ob die Nachricht nicht null ist
            { 
                # Antwort an den Client senden
                $writer.WriteLine($command)
            }
            $message = $reader.ReadLine()
            Write-Output "Client: $message"
            Write-Output "________________________"
            #Überprüft ob man die Verbindung bei Behalten möchte
            $question = Read-Host -Prompt "Continue? y/n"
            if($question -eq "y")
            {
                $decision = $true
            }
            else 
            {        
                $decision = $false   
            }
            
        } catch {
                    Write-Output "Fehler: $_"
                }
    }
    # Schließe den Client nach der Kommunikation
    $client.Close()
    $listener.Stop()
    Write-Output "Verbindung geschlossen!"
}
catch
{
    Write-Output "Fehler: $_"
}
