// Create sniffer configuration object.
SnifferConfiguration config;
cnfig.set_filter("port 80")
config.set__promisc_mode(true);
config.set_snap_len(400);

// Construct a Snifeer object, using the configuration above.
Sniffer sniffer("wlo1", config);
