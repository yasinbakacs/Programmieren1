#include <iostream>
#include <stdexcept>
#include <string>


class ConfigError : public std::runtime_error {
public:
    ConfigError(const std::string& message) : std::runtime_error(message) {}
};

class ConfigLoader {
public:
    void load(const std::string& filename) {
        if (filename.empty()) {
            throw std::invalid_argument("Dateiname darf nicht leer sein");
        }

        if (filename.length() < 4 ||
            filename.substr(filename.length() - 4) != ".cfg") {
            throw std::invalid_argument("Nur .cfg-Dateien sind erlaubt");
        }

        if (filename == "missing.cfg") {
            throw std::runtime_error("Datei konnte nicht geoeffnet werden");
        }

        if (filename == "invalid.cfg") {
            throw ConfigError("Systemspezifische Konfiguration ist fehlerhaft");
        }

        std::cout << "Konfiguration geladen: " << filename << std::endl;
    }
};

int main() {
    ConfigLoader loader;

    std::string tests[] = {
        "",
        "config.txt",
        "missing.cfg",
        "invalid.cfg",
        "valid.cfg"
    };

    for (const std::string& filename : tests) {
        try {
            loader.load(filename);
        }
        catch (const std::invalid_argument& e) {
            std::cout << "Ungueltige Eingabe: " << e.what() << std::endl;
        }
        catch (const ConfigError& e) {
            std::cout << "Config-Fehler: " << e.what() << std::endl;
        }
        catch (const std::runtime_error& e) {
            std::cout << "Laufzeitfehler: " << e.what() << std::endl;
        }
        catch (const std::exception& e) {
            std::cout << "Allgemeiner Fehler: " << e.what() << std::endl;
        }
    }

    return 0;
}
