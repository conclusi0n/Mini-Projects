import smtplib
from email.message import EmailMessage
import xml.etree.ElementTree as ET

def load_subscribers(xml_file):
    tree = ET.parse(xml_file)
    root = tree.getroot()
    subscribers = []
    
    for subscriber in root.findall('subscriber'):
        name = subscriber.find('name').text
        email = subscriber.find('email').text
        subscribers.append({"name": name, "email": email})
    
    return subscribers

def send_email(sender_email, sender_password, to_email, subject, body):
    try:
        msg = EmailMessage()
        msg.set_content(body)
        msg['Subject'] = subject
        msg['From'] = sender_email
        msg['To'] = to_email

        # Set up the server (Gmail SMTP server)
        server = smtplib.SMTP('smtp.gmail.com', 587)
        server.starttls()
        server.login(sender_email, sender_password)
        server.send_message(msg)
        server.quit()

        print(f"Email sent to {to_email}!")

    except Exception as e:
        print(f"Failed to send email to {to_email}: {e}")

def create_email_body(name, message):
    return f"Hello {name},\n\n{message}"

def main():
    # Load subscribers from XML
    subscribers = load_subscribers('emails.xml')

    sender_email = input("Your Email: ")
    sender_password = input("Your Email Password (or App Password for Gmail): ")
    subject = input("Subject of the email: ")
    message = input("Message to send to subscribers: ")

    # Send personalized email to each subscriber
    for subscriber in subscribers:
        body = create_email_body(subscriber['name'], message)
        send_email(sender_email, sender_password, subscriber['email'], subject, body)

if __name__ == "__main__":
    main()
