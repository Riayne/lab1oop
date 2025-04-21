#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>
#include <memory>
#include <algorithm>

enum class LogSeverity {
    INFO,
    WARNING,
    ERROR
};

class LogEntry {
public:
    LogEntry(const std::string& module, LogSeverity severity, const std::string& message)
        : module_(module), severity_(severity), message_(message), timestamp_(getCurrentTimestamp()) {}

    std::string toString() const {
        std::string severityStr;
        switch (severity_) {
            case LogSeverity::INFO: severityStr = "INFO"; break;
            case LogSeverity::WARNING: severityStr = "WARN"; break;
            case LogSeverity::ERROR: severityStr = "ERROR"; break;
        }
        return "[" + timestamp_ + "] [" + module_ + "] [" + severityStr + "] " + message_;
    }

    LogSeverity getSeverity() const { return severity_; }
    std::string getModule() const { return module_; }
    std::string getTimestamp() const { return timestamp_; }

private:
    static std::string getCurrentTimestamp() {
        // Simplified timestamp for this example
        return "TIMESTAMP"; // In real implementation, use actual time
    }

    std::string module_;
    LogSeverity severity_;
    std::string message_;
    std::string timestamp_;
};

class Logger {
private:
    std::vector<LogEntry> logs_;
    const size_t MAX_LOG_ENTRIES = 1000;
    static std::unique_ptr<Logger> instance_;
    static bool auditorAuthenticated_;

    Logger() = default;
    Logger(const Logger&) = delete;
    Logger& operator=(const Logger&) = delete;

    void addLogEntry(const LogEntry& entry) {
        if (logs_.size() >= MAX_LOG_ENTRIES) {
            // Remove the oldest log (first element)
            logs_.erase(logs_.begin());
        }
        logs_.push_back(entry);
    }

public:
    static Logger& getInstance() {
        if (!instance_) {
            instance_ = std::unique_ptr<Logger>(new Logger());
        }
        return *instance_;
    }

    static void authenticateAuditor(const std::string& password) {
        // In real implementation, use proper authentication
        auditorAuthenticated_ = (password == "secure123");
    }

    static void logoutAuditor() {
        auditorAuthenticated_ = false;
    }

    void log(const std::string& module, LogSeverity severity, const std::string& message) {
        addLogEntry(LogEntry(module, severity, message));
    }

    void logInfo(const std::string& module, const std::string& message) {
        log(module, LogSeverity::INFO, message);
    }

    void logWarning(const std::string& module, const std::string& message) {
        log(module, LogSeverity::WARNING, message);
    }

    void logError(const std::string& module, const std::string& message) {
        log(module, LogSeverity::ERROR, message);
    }

    class LogIterator {
    private:
        typename std::vector<LogEntry>::const_iterator current_;
        typename std::vector<LogEntry>::const_iterator end_;

    public:
        LogIterator(typename std::vector<LogEntry>::const_iterator begin,
                   typename std::vector<LogEntry>::const_iterator end)
            : current_(begin), end_(end) {}

        bool hasNext() const { return current_ != end_; }
        const LogEntry& next() { return *current_++; }
    };

    LogIterator getLogs() const {
        if (!auditorAuthenticated_) {
            throw std::runtime_error("Auditor not authenticated");
        }
        return LogIterator(logs_.begin(), logs_.end());
    }

    size_t getLogCount() const {
        return logs_.size();
    }
};

// Initialize static members
std::unique_ptr<Logger> Logger::instance_ = nullptr;
bool Logger::auditorAuthenticated_ = false;

// Simulated system modules
class NetworkModule {
public:
    void connect() {
        Logger::getInstance().logInfo("Network", "Attempting to connect to server");
    }

    void disconnect() {
        Logger::getInstance().logWarning("Network", "Unexpected disconnection");
    }
};

class DatabaseModule {
public:
    void query(const std::string& sql) {
        Logger::getInstance().logInfo("Database", "Executing query: " + sql);
    }

    void reportError(const std::string& error) {
        Logger::getInstance().logError("Database", "Query failed: " + error);
    }
};

int main() {
    // Simulate application components logging messages
    NetworkModule network;
    DatabaseModule db;

    network.connect();
    db.query("SELECT * FROM users");
    network.disconnect();
    db.reportError("Connection timeout");

    // Try to access logs without authentication (should fail)
    try {
        auto& logger = Logger::getInstance();
        auto it = logger.getLogs();
        std::cout << "This shouldn't appear!" << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Access denied: " << e.what() << std::endl;
    }

    // Authenticate and access logs
    Logger::authenticateAuditor("secure123");
    
    std::cout << "\nAudit Logs (" << Logger::getInstance().getLogCount() << " entries):\n";
    auto it = Logger::getInstance().getLogs();
    while (it.hasNext()) {
        const auto& entry = it.next();
        std::cout << entry.toString() << std::endl;
    }

    // Test log rotation (fill up the logs)
    std::cout << "\nTesting log rotation...\n";
    for (int i = 0; i < 1005; i++) {
        Logger::getInstance().logInfo("Test", "Message " + std::to_string(i));
    }
    std::cout << "Total logs after rotation: " << Logger::getInstance().getLogCount() << std::endl;

    Logger::logoutAuditor();
    return 0;
}
