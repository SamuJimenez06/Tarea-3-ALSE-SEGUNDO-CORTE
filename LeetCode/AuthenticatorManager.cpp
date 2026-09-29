#include <string>
#include <unordered_map>

class AuthenticationManager {
private:
    int timeToLive;
    std::unordered_map<std::string, int> tokens;

public:
    AuthenticationManager(int timeToLive) {
        this->timeToLive = timeToLive;
    }
    
    void generate(std::string tokenId, int currentTime) {
        // El token expira en currentTime + timeToLive
        tokens[tokenId] = currentTime + timeToLive;
    }
    
    void renew(std::string tokenId, int currentTime) {
        // Verificamos si el token existe y si aún no ha expirado
        if (tokens.count(tokenId) && tokens[tokenId] > currentTime) {
            tokens[tokenId] = currentTime + timeToLive;
        }
    }
    
    int countUnexpiredTokens(int currentTime) {
        int count = 0;
        for (auto it = tokens.begin(); it != tokens.end(); ) {
            // Si ya expiró (<= currentTime), lo podemos eliminar o simplemente ignorarlo
            if (it->second <= currentTime) {
                it = tokens.erase(it); // Limpieza opcional de expirados
            } else {
                count++;
                ++it;
            }
        }
        return count;
    }
};
