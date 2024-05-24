#include "SensorGempa.h"

Define_Module(SensorGempa);

SensorGempa::SensorGempa() : lastSendTime(simTime()), minMagnitude(0.1f)
{
}

void SensorGempa::initialize()
{
    // Menjadwalkan pengiriman pesan pertama
    scheduleAt(simTime() + uniform(1, 3), new cMessage("sendTimer"));
}

void SensorGempa::handleMessage(cMessage *msg)
{
    if (msg->isSelfMessage()) {
        // Menghasilkan magnitudo acak dan mengirim pesan gempa
        float randomFloat = (rand() % 89 + 1) / 10.0f;
        sendEarthquakeMessage(randomFloat);
        delete msg;
    } else {

    }
}

void SensorGempa::sendEarthquakeMessage(float magnitude)
{
    if (checkThreshold(magnitude)) {
        // Membuat pesan dengan nama yang merepresentasikan magnitudo acak
        char msgName[10];
        sprintf(msgName, "%.1f Mw", magnitude);

        cMessage *msg = new cMessage(msgName);
        msg->setKind(static_cast<int>(magnitude * 10));

        // Mengirim pesan ke output gate
        send(msg, "out");

        // Menyimpan waktu pengiriman terakhir
        lastSendTime = simTime();
    }

    // Menjadwalkan pengiriman pesan berikutnya
    scheduleAt(simTime() + uniform(1, 3), new cMessage("sendTimer"));
}

bool SensorGempa::checkThreshold(float magnitude)
{
    // Memeriksa apakah magnitudo memenuhi ambang batas
    return magnitude >= minMagnitude;
}
