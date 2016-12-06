// Basic structure of a "tinCan".
// We want to sniff on wlol1. This will capture packets of at most 64kb.
Sniffer sniffer("wlo1");
//Only retrieve IP datagrams which are sent from 192.168.0.1
sniffer.set_filter("ip src 192.168.0.1");
// Retrieve the packet.
PDU *some_pdu = sniffer.next_packet();
// Do something with some_pdu...
.....
//Delete it.
delete some_pdu;
