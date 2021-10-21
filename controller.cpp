#include "controller.h"
#include "terminalui.h"
#include "connection.h"
#include "network.h"

#include <string>
#include <iostream>

Controller::Controller (Cluster& cluster, Headnode& headnode, 
                        TerminalUI& terminalui) {
    this->cluster = &cluster;
    this->headnode = &headnode;
    this->terminalui = &terminalui;

    startView();
    terminalui.~TerminalUI();
}

void Controller::startView() {
    /* Timezone */
//    headnode->timezone = requestTimezone();
//    cluster->timezone = headnode->timezone;
//
//    /* Locale */
//    headnode->locale = requestLocale();
//    cluster->locale = headnode->locale;
//
//    /* Hostname and domainname*/
//    std::vector<std::string> fields = requestHostname();
//    headnode->hostname = fields[0];
//    headnode->domainname = fields[1];
//    headnode->fqdn = headnode->hostname + "." + headnode->domainname;

    /* External Network Interface */
    //Connection connection;
//    Network network;
//    network.setProfile(Network::Profile::External);
//    network.setType(Network::Type::Ethernet);
//    network.setInterfacename(requestNetworkInterface());
    //connection.setInterfaceName();
    //headnode->externalConnection.push_back(connection);
//    headnode->externalNetwork.push_back(network);

    /* Get IP addresses */
    std::vector<std::string> fields = requestNetworkAddress();
    headnode->managementNetwork[0].setIPAddress(fields[0], fields[1]);

}

std::string Controller::requestTimezone () {
    /* TODO: Fetch timezones from OS and remove placeholder text */
     const std::vector<std::string> timezones = {
         "America/Sao_Paulo",
         "UTC",
         "Gadific Mean Bolsotime",
         "Chronus",
         "Two blocks ahead"
     };

    return terminalui->drawTimezoneSelection(timezones);
}

std::string Controller::requestLocale () {
    const std::vector<std::string> locales = {
        "en.US_UTF-8",
        "pt.BR_UTF-8",
        "C"
    };

    return terminalui->drawLocaleSelection(locales);
}

/* This method should be renamed or ask just for hostname */
std::vector<std::string> Controller::requestHostname () {
    const std::vector<std::string> entries = {
        "Hostname",
        "Domain Name"
    };

    return terminalui->drawNetworkHostnameSelection(entries);
}

/* TODO: Data model is strange, needs fixing. requestNetworkInterface() should
 * be more generic than it's now, not being tied for internal or external
 * interfaces
 */
std::string Controller::requestNetworkInterface () {
    const std::vector<std::string> netInterfaces = {
        "eth0",
        "eth1",
        "enp4s0f0",
        "lo",
        "ib0",
    };

    return terminalui->drawNetworkInterfaceSelection(netInterfaces);
}

std::vector<std::string> Controller::requestNetworkAddress () {
    const std::vector<std::string> networkAddresses = {
            "Headnode IP",
            "Management Network"
    };

    return terminalui->drawNetworkAddress(networkAddresses);
}
