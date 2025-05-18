class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        
        vector <int> ans ;

        for (int i {0} ; i < nums.size(); i++)
        {
            ans.push_back(nums[i]);
        }
         for (int i {0} ; i < nums.size(); i++)
        {
            ans.push_back(nums[i]);
        }
        return ans;

    }
};

/*
#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <random>
#include <chrono>
#include <queue>
#include <unordered_map>
#include <iomanip>
#include <fstream> // For file output
#include <sstream> // For string stream

// Forward declarations
class DataPacket;
class IPNode;
class SplayTree;
class RoutingCache;

// Class to represent a data packet
class DataPacket {
private:
    std::string source;
    std::string destination;
    size_t size;
    std::time_t timestamp;

public:
    DataPacket(const std::string& src, const std::string& dest, size_t sz) 
        : source(src), destination(dest), size(sz) {
        timestamp = std::time(nullptr);
    }

    std::string getSource() const { return source; }
    std::string getDestination() const { return destination; }
    size_t getSize() const { return size; }
    std::time_t getTimestamp() const { return timestamp; }
    
    // Get formatted timestamp as string
    std::string getFormattedTimestamp() const {
        char buffer[20];
        std::strftime(buffer, sizeof(buffer), "%H:%M:%S", std::localtime(&timestamp));
        return std::string(buffer);
    }

    // Convert packet to CSV format
    std::string toCSV() const {
        std::stringstream ss;
        ss << source << "," << destination << "," << size << "," << getFormattedTimestamp();
        return ss.str();
    }

    friend std::ostream& operator<<(std::ostream& os, const DataPacket& packet) {
        os << "Packet[" << packet.source << " -> " << packet.destination 
           << ", Size: " << packet.size << " bytes, Time: " 
           << std::put_time(std::localtime(&packet.timestamp), "%H:%M:%S") << "]";
        return os;
    }
};

// Class to represent an IP node in the splay tree
class IPNode {
private:
    std::string ipAddress;
    IPNode* left;
    IPNode* right;
    std::time_t lastAccessed;
    std::vector<DataPacket> packetHistory;
    size_t ttl; // Time-to-live in seconds
    int depth; // Track node depth for visualization

public:
    IPNode(const std::string& ip, size_t timeToLive = 300) 
        : ipAddress(ip), left(nullptr), right(nullptr), ttl(timeToLive), depth(0) {
        lastAccessed = std::time(nullptr);
    }

    ~IPNode() {
        // Destructor
    }

    std::string getIP() const { return ipAddress; }
    IPNode* getLeft() const { return left; }
    IPNode* getRight() const { return right; }
    std::time_t getLastAccessed() const { return lastAccessed; }
    const std::vector<DataPacket>& getPacketHistory() const { return packetHistory; }
    size_t getTTL() const { return ttl; }
    int getDepth() const { return depth; }

    void setLeft(IPNode* node) { left = node; }
    void setRight(IPNode* node) { right = node; }
    void setDepth(int d) { depth = d; }
    
    void updateAccessTime() { 
        lastAccessed = std::time(nullptr); 
    }

    void addPacket(const DataPacket& packet) {
        packetHistory.push_back(packet);
        updateAccessTime();
    }

    bool isExpired() const {
        return std::difftime(std::time(nullptr), lastAccessed) > ttl;
    }
    
    // Get formatted last accessed time as string
    std::string getFormattedLastAccessed() const {
        char buffer[20];
        std::strftime(buffer, sizeof(buffer), "%H:%M:%S", std::localtime(&lastAccessed));
        return std::string(buffer);
    }
    
    // Convert node to CSV format
    std::string toCSV() const {
        std::stringstream ss;
        ss << ipAddress << "," << packetHistory.size() << "," << getFormattedLastAccessed() 
           << "," << (left ? left->getIP() : "null") << "," << (right ? right->getIP() : "null")
           << "," << depth;
        return ss.str();
    }

    friend class SplayTree;
};

// Structure to track operation statistics
struct OperationStats {
    int insertions = 0;
    int searches = 0;
    int successful_searches = 0;
    int deletions = 0;
    int successful_deletions = 0;
    int expirations = 0;
    
    // Convert stats to CSV format
    std::string toCSV() const {
        std::stringstream ss;
        ss << "Operation,Count\n";
        ss << "Insertions," << insertions << "\n";
        ss << "Searches," << searches << "\n";
        ss << "Successful Searches," << successful_searches << "\n";
        ss << "Deletions," << deletions << "\n";
        ss << "Successful Deletions," << successful_deletions << "\n";
        ss << "Expirations," << expirations;
        return ss.str();
    }
};

// Splay Tree implementation for IP routing cache
class SplayTree {
private:
    IPNode* root;
    OperationStats stats;
    
    // Right rotation
    IPNode* rightRotate(IPNode* x) {
        IPNode* y = x->left;
        x->left = y->right;
        y->right = x;
        return y;
    }

    // Left rotation
    IPNode* leftRotate(IPNode* x) {
        IPNode* y = x->right;
        x->right = y->left;
        y->left = x;
        return y;
    }

    // Splay operation to bring a node to the root
    IPNode* splay(IPNode* root, const std::string& ip) {
        if (root == nullptr || root->ipAddress == ip)
            return root;

        if (ip < root->ipAddress) {
            // IP is in left subtree
            if (root->left == nullptr) return root;

            if (ip < root->left->ipAddress) {
                // Zig-Zig case (Left Left)
                root->left->left = splay(root->left->left, ip);
                root = rightRotate(root);
                if (root->left == nullptr) return root;
                return rightRotate(root);
            } else if (ip > root->left->ipAddress) {
                // Zig-Zag case (Left Right)
                root->left->right = splay(root->left->right, ip);
                if (root->left->right != nullptr)
                    root->left = leftRotate(root->left);
                if (root->left == nullptr) return root;
                return rightRotate(root);
            } else {
                // Zig case (Left)
                return rightRotate(root);
            }
        } else {
            // IP is in right subtree
            if (root->right == nullptr) return root;

            if (ip > root->right->ipAddress) {
                // Zig-Zig case (Right Right)
                root->right->right = splay(root->right->right, ip);
                root = leftRotate(root);
                if (root->right == nullptr) return root;
                return leftRotate(root);
            } else if (ip < root->right->ipAddress) {
                // Zig-Zag case (Right Left)
                root->right->left = splay(root->right->left, ip);
                if (root->right->left != nullptr)
                    root->right = rightRotate(root->right);
                if (root->right == nullptr) return root;
                return leftRotate(root);
            } else {
                // Zig case (Right)
                return leftRotate(root);
            }
        }
    }

    // Helper function for in-order traversal
    void inOrderTraversal(IPNode* node, int level = 0) const {
        if (node != nullptr) {
            inOrderTraversal(node->right, level + 1);
            
            std::cout << std::string(level * 4, ' ') << node->ipAddress 
                      << " (Packets: " << node->packetHistory.size() 
                      << ", Last accessed: " << std::put_time(std::localtime(&node->lastAccessed), "%H:%M:%S")
                      << ")" << std::endl;
            
            inOrderTraversal(node->left, level + 1);
        }
    }
    
    // Helper function to clean up memory
    void destroyTree(IPNode* node) {
        if (node != nullptr) {
            destroyTree(node->left);
            destroyTree(node->right);
            delete node;
        }
    }

public:
    SplayTree() : root(nullptr) {}

    ~SplayTree() {
        destroyTree(root);
    }

    // Get operation statistics
    const OperationStats& getStats() const {
        return stats;
    }
    
    // Get root node (added getter for root)
    IPNode* getRoot() const {
        return root;
    }

    // Insert a new IP node or update existing one
    void insert(const std::string& ip, const DataPacket& packet) {
        stats.insertions++;
        
        if (root == nullptr) {
            root = new IPNode(ip);
            root->addPacket(packet);
            return;
        }

        root = splay(root, ip);

        if (root->ipAddress == ip) {
            // IP already exists, update it
            root->addPacket(packet);
            return;
        }

        IPNode* newNode = new IPNode(ip);
        newNode->addPacket(packet);

        if (ip < root->ipAddress) {
            newNode->right = root;
            newNode->left = root->left;
            root->left = nullptr;
        } else {
            newNode->left = root;
            newNode->right = root->right;
            root->right = nullptr;
        }

        root = newNode;
    }

    // Search for an IP node
    IPNode* search(const std::string& ip) {
        stats.searches++;
        
        if (root == nullptr) return nullptr;

        root = splay(root, ip);
        
        if (root->ipAddress != ip) return nullptr;
        
        stats.successful_searches++;
        root->updateAccessTime();
        return root;
    }

    // Delete an IP node
    bool remove(const std::string& ip) {
        stats.deletions++;
        
        if (root == nullptr) return false;

        root = splay(root, ip);
        
        if (root->ipAddress != ip) return false;

        IPNode* temp = root;
        
        if (root->left == nullptr) {
            root = root->right;
        } else {
            IPNode* rightSubtree = root->right;
            root = root->left;
            
            // Find the maximum element in the left subtree
            IPNode* maxInLeft = root;
            while (maxInLeft->right != nullptr) {
                maxInLeft = maxInLeft->right;
            }
            
            // Splay the maximum element to the root of left subtree
            root = splay(root, maxInLeft->ipAddress);
            
            // Connect the right subtree
            root->right = rightSubtree;
        }
        
        delete temp;
        stats.successful_deletions++;
        return true;
    }

    // Check and remove expired nodes (LRU functionality)
    void cleanupExpiredNodes() {
        std::vector<std::string> expiredIPs;
        collectExpiredNodes(root, expiredIPs);
        
        for (const auto& ip : expiredIPs) {
            std::cout << "Removing expired IP: " << ip << std::endl;
            remove(ip);
            stats.expirations++;
        }
    }

    // Helper to collect expired nodes
    void collectExpiredNodes(IPNode* node, std::vector<std::string>& expiredIPs) {
        if (node == nullptr) return;
        
        collectExpiredNodes(node->left, expiredIPs);
        collectExpiredNodes(node->right, expiredIPs);
        
        if (node->isExpired()) {
            expiredIPs.push_back(node->ipAddress);
        }
    }

    // Display the routing table
    void displayRoutingTable() const {
        std::cout << "\n===== IP Routing Cache (Splay Tree) =====\n";
        if (root == nullptr) {
            std::cout << "Empty routing table\n";
            return;
        }
        inOrderTraversal(root);
        std::cout << "=======================================\n";
    }

    // Get packet history for an IP
    std::vector<DataPacket> getPacketHistory(const std::string& ip) {
        IPNode* node = search(ip);
        if (node != nullptr) {
            return node->getPacketHistory();
        }
        return {};
    }
    
    // Helper function to collect nodes for CSV output - FIXED: added const qualifier
    void collectNodes(IPNode* node, std::vector<IPNode*>& nodes, int depth = 0) const {
        if (node != nullptr) {
            node->setDepth(depth); // Note: This requires setDepth to be mutable or non-const
            nodes.push_back(node);
            collectNodes(node->getLeft(), nodes, depth + 1);
            collectNodes(node->getRight(), nodes, depth + 1);
        }
    }
    
    // Export tree structure to CSV
    bool exportTreeToCSV(const std::string& filename) const {
        std::ofstream file(filename);
        if (!file.is_open()) {
            std::cerr << "Failed to open file: " << filename << std::endl;
            return false;
        }
        
        // Write CSV header
        file << "IP,PacketCount,LastAccessed,LeftChild,RightChild,Depth\n";
        
        // Collect all nodes
        std::vector<IPNode*> nodes;
        collectNodes(root, nodes);
        
        // Write each node to CSV
        for (const auto& node : nodes) {
            file << node->toCSV() << "\n";
        }
        
        file.close();
        std::cout << "Tree structure exported to " << filename << std::endl;
        return true;
    }
    
    // Export packet history to CSV
    bool exportPacketHistoryToCSV(const std::string& filename) const {
        std::ofstream file(filename);
        if (!file.is_open()) {
            std::cerr << "Failed to open file: " << filename << std::endl;
            return false;
        }
        
        // Write CSV header
        file << "IP,Source,Destination,Size,Timestamp\n";
        
        // Collect all nodes
        std::vector<IPNode*> nodes;
        collectNodes(root, nodes);
        
        // Write packet history for each node
        for (const auto& node : nodes) {
            for (const auto& packet : node->getPacketHistory()) {
                file << node->getIP() << "," << packet.toCSV() << "\n";
            }
        }
        
        file.close();
        std::cout << "Packet history exported to " << filename << std::endl;
        return true;
    }
    
    // Export operation statistics to CSV
    bool exportStatsToCSV(const std::string& filename) const {
        std::ofstream file(filename);
        if (!file.is_open()) {
            std::cerr << "Failed to open file: " << filename << std::endl;
            return false;
        }
        
        file << stats.toCSV();
        
        file.close();
        std::cout << "Operation statistics exported to " << filename << std::endl;
        return true;
    }
};

// Class to manage multiple routing trees for load balancing
class RoutingCache {
private:
    std::unordered_map<std::string, SplayTree*> subnetTrees;
    
    // Extract subnet from IP address (e.g., "192.168.1" from "192.168.1.x")
    std::string extractSubnet(const std::string& ip) {
        size_t lastDot = ip.find_last_of('.');
        if (lastDot != std::string::npos) {
            return ip.substr(0, lastDot);
        }
        return ip;
    }

public:
    RoutingCache() {}
    
    ~RoutingCache() {
        for (auto& pair : subnetTrees) {
            delete pair.second;
        }
    }

    // Process a packet (insert into appropriate tree)
    void processPacket(const std::string& ip, const DataPacket& packet) {
        std::string subnet = extractSubnet(ip);
        
        if (subnetTrees.find(subnet) == subnetTrees.end()) {
            subnetTrees[subnet] = new SplayTree();
        }
        
        subnetTrees[subnet]->insert(ip, packet);
    }

    // Search for an IP across all trees
    IPNode* searchIP(const std::string& ip) {
        std::string subnet = extractSubnet(ip);
        
        if (subnetTrees.find(subnet) != subnetTrees.end()) {
            return subnetTrees[subnet]->search(ip);
        }
        
        return nullptr;
    }

    // Delete an IP from its tree
    bool deleteIP(const std::string& ip) {
        std::string subnet = extractSubnet(ip);
        
        if (subnetTrees.find(subnet) != subnetTrees.end()) {
            return subnetTrees[subnet]->remove(ip);
        }
        
        return false;
    }

    // Clean up expired nodes across all trees
    void cleanupExpiredNodes() {
        for (auto& pair : subnetTrees) {
            pair.second->cleanupExpiredNodes();
        }
    }

    // Display all routing tables
    void displayAllRoutingTables() const {
        std::cout << "\n===== ALL IP ROUTING TABLES =====\n";
        if (subnetTrees.empty()) {
            std::cout << "No routing tables exist\n";
            return;
        }
        
        for (const auto& pair : subnetTrees) {
            std::cout << "\nSubnet: " << pair.first << ".x\n";
            pair.second->displayRoutingTable();
        }
        std::cout << "===============================\n";
    }

    // Get packet history for an IP
    std::vector<DataPacket> getPacketHistory(const std::string& ip) {
        IPNode* node = searchIP(ip);
        if (node != nullptr) {
            return node->getPacketHistory();
        }
        return {};
    }
    
    // Export all trees to CSV files
    void exportAllTreesToCSV(const std::string& baseFilename) {
        std::cout << "\n===== EXPORTING DATA TO CSV FILES =====\n";
        
        // Export subnet summary
        std::ofstream summaryFile(baseFilename + "_subnet_summary.csv");
        if (summaryFile.is_open()) {
            summaryFile << "Subnet,NodeCount,TotalPackets\n";
            
            for (const auto& pair : subnetTrees) {
                // Collect nodes to count
                std::vector<IPNode*> nodes;
                pair.second->collectNodes(pair.second->getRoot(), nodes);
                
                int totalPackets = 0;
                for (const auto& node : nodes) {
                    totalPackets += node->getPacketHistory().size();
                }
                
                summaryFile << pair.first << ".x," << nodes.size() << "," << totalPackets << "\n";
            }
            
            summaryFile.close();
            std::cout << "Subnet summary exported to " << baseFilename + "_subnet_summary.csv" << std::endl;
        }
        
        // Export each subnet tree
        for (const auto& pair : subnetTrees) {
            std::string subnet = pair.first;
            std::string subnetFilename = baseFilename + "_" + subnet.substr(subnet.find_last_of('.') + 1) + ".csv";
            pair.second->exportTreeToCSV(subnetFilename);
            
            std::string packetFilename = baseFilename + "_packets_" + subnet.substr(subnet.find_last_of('.') + 1) + ".csv";
            pair.second->exportPacketHistoryToCSV(packetFilename);
            
            std::string statsFilename = baseFilename + "_stats_" + subnet.substr(subnet.find_last_of('.') + 1) + ".csv";
            pair.second->exportStatsToCSV(statsFilename);
        }
        
        // Export combined packet history
        std::ofstream allPacketsFile(baseFilename + "_all_packets.csv");
        if (allPacketsFile.is_open()) {
            allPacketsFile << "Subnet,IP,Source,Destination,Size,Timestamp\n";
            
            for (const auto& pair : subnetTrees) {
                std::string subnet = pair.first;
                
                // Collect all nodes
                std::vector<IPNode*> nodes;
                pair.second->collectNodes(pair.second->getRoot(), nodes);
                
                // Write packet history for each node
                for (const auto& node : nodes) {
                    for (const auto& packet : node->getPacketHistory()) {
                        allPacketsFile << subnet << ".x," << node->getIP() << "," << packet.toCSV() << "\n";
                    }
                }
            }
            
            allPacketsFile.close();
            std::cout << "All packets exported to " << baseFilename + "_all_packets.csv" << std::endl;
        }
        
        std::cout << "===== CSV EXPORT COMPLETE =====\n";
    }
};

// Utility function to generate a random IP address
std::string generateRandomIP() {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    static std::uniform_int_distribution<> subnet_dist(1, 3);
    static std::uniform_int_distribution<> host_dist(1, 254);
    
    int subnet = subnet_dist(gen);
    int host = host_dist(gen);
    
    return "192.168." + std::to_string(subnet) + "." + std::to_string(host);
}

// Utility function to generate a random data packet
DataPacket generateRandomPacket() {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    static std::uniform_int_distribution<> size_dist(64, 1500);
    
    std::string src = generateRandomIP();
    std::string dest = generateRandomIP();
    size_t size = size_dist(gen);
    
    return DataPacket(src, dest, size);
}

// Main function to demonstrate the IP Routing Cache Simulator
int main() {
    RoutingCache routingCache;
    
    std::cout << "IP Routing Cache Simulator with Splay Tree\n";
    std::cout << "=========================================\n";
    
    // Simulate packet traffic
    const int NUM_PACKETS = 50;
    std::cout << "Generating " << NUM_PACKETS << " random packets...\n";
    
    // Create a log file for packet processing
    std::ofstream logFile("packet_processing_log.csv");
    if (logFile.is_open()) {
        logFile << "Step,Action,IP,Source,Destination,Size,Timestamp\n";
    }
    
    for (int i = 0; i < NUM_PACKETS; i++) {
        std::string ip = generateRandomIP();
        DataPacket packet = generateRandomPacket();
        
        std::cout << "Processing: " << ip << " with " << packet << std::endl;
        
        // Log packet processing
        if (logFile.is_open()) {
            logFile << i + 1 << ",Process," << ip << "," << packet.toCSV() << "\n";
        }
        
        routingCache.processPacket(ip, packet);
        
        // Periodically clean up expired nodes (every 10 packets)
        if (i % 10 == 0 && i > 0) {
            std::cout << "\nPerforming cleanup of expired nodes...\n";
            if (logFile.is_open()) {
                logFile << i + 1 << ",Cleanup,,,,,\n";
            }
            routingCache.cleanupExpiredNodes();
        }
    }
    
    if (logFile.is_open()) {
        logFile.close();
        std::cout << "\nPacket processing log saved to packet_processing_log.csv\n";
    }
    
    // Display all routing tables
    routingCache.displayAllRoutingTables();
    
    // Demonstrate search operation with a successful search
    std::string searchIP = generateRandomIP(); // Use an IP we've likely processed
    std::cout << "\nSearching for IP: " << searchIP << std::endl;
    IPNode* foundNode = routingCache.searchIP(searchIP);
    
    std::ofstream searchLog("search_operations.csv");
    if (searchLog.is_open()) {
        searchLog << "Operation,IP,Result,PacketCount\n";
        searchLog << "Search," << searchIP << "," << (foundNode ? "Found" : "Not Found") << "," 
                 << (foundNode ? std::to_string(foundNode->getPacketHistory().size()) : "0") << "\n";
    }
    
    if (foundNode != nullptr) {
        std::cout << "Found IP: " << searchIP << " with " 
                  << foundNode->getPacketHistory().size() << " packets\n";
                  
        // Display packet history
        std::cout << "Packet History:\n";
        for (const auto& packet : foundNode->getPacketHistory()) {
            std::cout << "  " << packet << std::endl;
        }
    } else {
        std::cout << "IP not found in cache\n";
        
        // Try another search with an IP we know exists
        searchIP = "192.168.1.1"; // Let's insert this one explicitly
        DataPacket newPacket("192.168.0.1", "192.168.0.2", 100);
        routingCache.processPacket(searchIP, newPacket);
        
        std::cout << "\nAdded and searching for IP: " << searchIP << std::endl;
        foundNode = routingCache.searchIP(searchIP);
        
        if (searchLog.is_open()) {
            searchLog << "Insert+Search," << searchIP << "," << (foundNode ? "Found" : "Not Found") << "," 
                     << (foundNode ? std::to_string(foundNode->getPacketHistory().size()) : "0") << "\n";
        }
        
        if (foundNode != nullptr) {
            std::cout << "Found IP: " << searchIP << " with " 
                      << foundNode->getPacketHistory().size() << " packets\n";
        } else {
            std::cout << "IP still not found in cache (unexpected)\n";
        }
    }
    
    // Demonstrate delete operation
    std::string deleteIP = searchIP; // Delete the IP we just searched for
    std::cout << "\nDeleting IP: " << deleteIP << std::endl;
    bool deleted = routingCache.deleteIP(deleteIP);
    std::cout << "Delete operation " << (deleted ? "successful" : "failed") << std::endl;
    
    if (searchLog.is_open()) {
        searchLog << "Delete," << deleteIP << "," << (deleted ? "Successful" : "Failed") << ",0\n";
        searchLog.close();
        std::cout << "Search and delete operations logged to search_operations.csv\n";
    }
    
    // Final display of routing tables
    routingCache.displayAllRoutingTables();
    
    // Export all data to CSV files
    routingCache.exportAllTreesToCSV("routing_cache");
    
    std::cout << "\nSimulation complete. CSV files have been generated for analysis.\n";
    std::cout << "The following CSV files were created:\n";
    std::cout << "1. packet_processing_log.csv - Log of all packet processing steps\n";
    std::cout << "2. search_operations.csv - Log of search and delete operations\n";
    std::cout << "3. routing_cache_subnet_summary.csv - Summary of all subnets\n";
    std::cout << "4. routing_cache_1.csv, routing_cache_2.csv, routing_cache_3.csv - Tree structures for each subnet\n";
    std::cout << "5. routing_cache_packets_1.csv, routing_cache_packets_2.csv, routing_cache_packets_3.csv - Packet histories\n";
    std::cout << "6. routing_cache_stats_1.csv, routing_cache_stats_2.csv, routing_cache_stats_3.csv - Operation statistics\n";
    std::cout << "7. routing_cache_all_packets.csv - Combined packet history across all subnets\n";
    
    return 0;
}

*/


/*
https://github.com/ed-roh/chat-app?tab=readme-ov-file

https://github.com/shantanu2002git/AIchat-app














https://github.com/mukulsomukesh/file-sharing-app

https://github.com/shantanu2002git/File-sharing
*/