#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

#define DEVICE_PATH "/dev/usb_cdc0"
#define BUF_SIZE 16

void test_cdc_device()
{
    int fd;
    char write_buf[BUF_SIZE] = "LED_ON";
    char read_buf[BUF_SIZE];

    // Open the device file
    fd = open(DEVICE_PATH, O_RDWR);
    if (fd < 0) {
        perror("Failed to open USB device");
        return;
    }

    printf("Device opened successfully: %s\n", DEVICE_PATH);

    // Write data to the device
    if (write(fd, write_buf, strlen(write_buf)) < 0) {
        perror("Write failed");
        close(fd);
        return;
    }

    printf("Sent: %s\n", write_buf);

    // Read response from the device
    memset(read_buf, 0, BUF_SIZE);
    if (read(fd, read_buf, BUF_SIZE) < 0) {
        perror("Read failed");
        close(fd);
        return;
    }

    printf("Received: %s\n", read_buf);

    // Close the device file
    close(fd);
    printf("Device closed.\n");
}

int main()
{
    test_cdc_device();
    return 0;
}
