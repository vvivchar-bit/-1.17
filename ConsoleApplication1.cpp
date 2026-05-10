#include <iostream>
#include <string>
using namespace std;

class ReportGenerator {
public:
    string createReport() {
        return "Sales report was created.";
    }
};

class FileSaver {
public:
    void saveToFile(const string& report) {
        cout << "FileSaver: " << report << " Saved to file." << endl;
    }
};

class EmailSender {
public:
    void sendEmail(const string& report) {
        cout << "EmailSender: " << report << " Sent by email." << endl;
    }
};

class Logger {
public:
    void writeLog(const string& message) {
        cout << "Logger: " << message << endl;
    }
};

int main() {
    cout << "Bad example: God Object" << endl;
    cout << "One class should not create report, save file, send email and write logs." << endl;

    cout << endl;

    cout << "Good example: Single Responsibility Principle" << endl;

    ReportGenerator reportGenerator;
    FileSaver fileSaver;
    EmailSender emailSender;
    Logger logger;

    string report = reportGenerator.createReport();

    cout << report << endl;
    fileSaver.saveToFile(report);
    emailSender.sendEmail(report);
    logger.writeLog("Report operation completed.");

    return 0;
}
