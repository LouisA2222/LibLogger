#include "./src/Logger.hpp"

int main(void) {
    Logger logger;
    logger.info("Hello World!", __FILE__, __FUNCTION__, __LINE__);
    logger.warning("Hello World!", __FILE__, __FUNCTION__, __LINE__);
    logger.error("Hello World!", __FILE__, __FUNCTION__, __LINE__);
    return 0;
}