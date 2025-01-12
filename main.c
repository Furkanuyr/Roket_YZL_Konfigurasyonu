#include <stdio.h>
#include <stdint.h>


enum AccelRange {
    AFS_2G = 0b00,
    AFS_4G = 0b01,
    AFS_8G = 0b10,
    AFS_16G = 0b11
};

enum Bandwidth {
    BW_7_81Hz = 0b000,
    BW_15_63Hz = 0b001,
    BW_31_25Hz = 0b010,
    BW_62_5Hz = 0b011,
    BW_125Hz = 0b100,
    BW_250Hz = 0b101,
    BW_500Hz = 0b110,
    BW_1000Hz = 0b111
};

enum OperationMode {
    MODE_NORMAL = 0b000,
    MODE_SUSPEND = 0b001,
    MODE_LOW_POWER_1 = 0b010,
    MODE_STANDBY = 0b011,
    MODE_LOW_POWER_2 = 0b100,
    MODE_DEEP_SUSPEND = 0b101
};


struct AccConfig {
    enum AccelRange gRange;
    enum Bandwidth bandwidth;
    enum OperationMode operationMode;
    uint8_t configValue;
};


void calculateConfigValue(struct AccConfig* config) {
    config->configValue = (config->operationMode << 5) | (config->bandwidth << 2) | config->gRange;
}

int main() {
    struct AccConfig config;


    config.gRange = AFS_8G;
    config.bandwidth = BW_500Hz;
    config.operationMode = MODE_NORMAL;


    calculateConfigValue(&config);


    printf("Config Value (Decimal): %d\n", config.configValue);
    printf("Config Value (Hexadecimal): 0x%02X\n", config.configValue);
    printf("Config Value (Binary): ");
    printf("0b");
    for (int i = 7; i >= 0; i--) {
        printf("%d", (config.configValue >> i) & 1);
    }
    printf("\n");

    return 0;
}
