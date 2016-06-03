#include "CSmtp.h"
#include <iostream>

int main()
{
	bool bError = false;

	try
	{
		CSmtp mail;

#define test_gmail_tls

#if defined(test_gmail_tls)
		mail.SetSMTPServer("smtp.gmail.com",25);
		mail.SetSecurityType(USE_TLS);
#elif defined(test_gmail_ssl)
		mail.SetSMTPServer("smtp.gmail.com",25);
		mail.SetSecurityType(USE_SSL);
#elif defined(test_hotmail_TLS)
		mail.SetSMTPServer("smtp.live.com",25);
		mail.SetSecurityType(USE_TLS);
#elif defined(test_aol_tls)
		mail.SetSMTPServer("smtp.aol.com",587);
		mail.SetSecurityType(USE_TLS);
#elif defined(test_yahoo_ssl)
		mail.SetSMTPServer("plus.smtp.mail.yahoo.com",465);
		mail.SetSecurityType(USE_SSL);
#endif

		mail.SetLogin("pksinha217@gmail.com");
		mail.SetPassword("*********************");
  		mail.SetSenderName("IN - OPTRA");
  		mail.SetSenderMail("pksinha1997@yahoo.in");
  		mail.SetReplyTo("");
  		mail.SetSubject("Succesful Registration");
  		mail.AddRecipient("pksinha217@gmail.com");
		//mail.AddRecipient("vi.ahuja96@gmail.com");
  		mail.SetXPriority(XPRIORITY_NORMAL);
  		mail.SetXMailer("The Bat! (v3.02) Professional");
  		mail.AddMsgLine("Hello,");
		mail.AddMsgLine("");
		mail.AddMsgLine("...");
		mail.AddMsgLine("You have successfully registered.....");
		mail.AddMsgLine("Enjoy your show at your time.");
		mail.AddMsgLine("Regards");
		mail.ModMsgLine(5,"regards");
		mail.DelMsgLine(2);
		mail.AddMsgLine("BookMyShow");

  		//mail.AddAttachment("../test1.jpg");
  		//mail.AddAttachment("c:\\test2.exe");
		//mail.AddAttachment("c:\\test3.txt");
		mail.Send();
		printf("MailSent....");
	}
	catch(ECSmtp e)
	{
		std::cout << "Error: " << e.GetErrorText().c_str() << ".\n";
		bError = true;
	}
	if(!bError)
		std::cout << "Mail was send successfully.\n";
	return 0;
}
