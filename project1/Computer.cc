#include "Computer.h"
#include <string>

using namespace omnetpp;

Define_Module(Computer);

Computer::Computer() : waterLevelThreshold(50), earthquakeMagnitudeThreshold(6.9f)
{
}

void Computer::initialize()
{

}

void Computer::handleMessage(cMessage *msg)
{
    // Ekstraksi jenis pesan yang mengandung angka acak
    int messageKind = msg->getKind();

    // Ekstraksi nama pesan
    const char *msgName = msg->getName();

    // Cek jenis pesan berdasarkan konvensi penamaan
    std::string messageNameStr(msgName);
    if (messageNameStr.find("cm") != std::string::npos) {
        // Ini adalah pesan dari SensorLaut
        EV << "Received water level message: " << msgName << " with value " << messageKind << " cm" << endl;
        // Handle water level message
        if (messageKind > 70) { // Contoh ambang batas untuk pasang tinggi
            EV << "High tide detected!" << endl;
        }
        lastData.waterLevel = messageKind; // Simpan level air terakhir
    } else if (messageNameStr.find("Mw") != std::string::npos) {
        // Ini adalah pesan dari SensorGempa
        float magnitude = messageKind / 10.0f; // Konversi kembali ke float
        EV << "Received earthquake message: " << msgName << " with magnitude " << magnitude << " Mw" << endl;
        // Handle earthquake message
        if (magnitude > 5.0) { // Contoh ambang batas untuk gempa signifikan
            EV << "Significant earthquake detected!" << endl;
        }
        lastData.magnitude = magnitude; // Simpan magnitudo terakhir
    }

    // Cek kemungkinan tsunami jika kedua nilai telah diperbarui
    if (lastData.isValid()) {
        checkForTsunami();
        // Reset nilai setelah pengecekan
    }

    // Bersihkan pesan
    delete msg;
}

void Computer::checkForTsunami()
{
    if (waterLevelThreshold >= lastData.waterLevel && lastData.magnitude >= earthquakeMagnitudeThreshold) {
        EV << "Warning: Potential tsunami detected!" << endl;
        // Anda dapat menambahkan tindakan lain di sini, seperti mengirim pesan ke modul lain
    }
}
