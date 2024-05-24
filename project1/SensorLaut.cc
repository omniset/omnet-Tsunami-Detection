#include "SensorLaut.h"

Define_Module(SensorLaut);

SensorLaut::SensorLaut() : lastSendTime(simTime()), waterLevelThreshold(1)
{
}

void SensorLaut::initialize()
{
     // Menjadwalkan pengiriman pesan pertama
    scheduleAt(simTime() + uniform(1, 3), new cMessage("sendTimer"));
}

void SensorLaut::handleMessage(cMessage *msg)
{
    if (msg->isSelfMessage()) {
        // Menghasilkan level air acak dan mengirim pesan
        int waterLevel = rand() % 100 + 1;
        sendWaterLevelMessage(waterLevel);
        delete msg;
    } else {

    }
}

void SensorLaut::sendWaterLevelMessage(int waterLevel)
{
    if (checkThreshold(waterLevel)) {
        // Membuat pesan dengan nama yang merepresentasikan angka acak
        char msgName[20];
        sprintf(msgName, "%d cm", waterLevel);

        cMessage *msg = new cMessage(msgName);
        msg->setKind(waterLevel);

        // Mengirim pesan ke output gate
        send(msg, "out");

        // Menyimpan waktu pengiriman terakhir
        lastSendTime = simTime();
    }

    // Menjadwalkan pengiriman pesan berikutnya
    scheduleAt(simTime() + uniform(1, 3), new cMessage("sendTimer"));
}

bool SensorLaut::checkThreshold(int waterLevel)
{
    // Memeriksa apakah level air memenuhi ambang batas
    return waterLevel > waterLevelThreshold;
}
