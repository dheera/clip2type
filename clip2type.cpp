#include <iostream>
#include <string>
#include <map>
#include <unistd.h>
#include <linux/uinput.h>
#include <fcntl.h>
#include <cstring>
#include <cstdlib>
#include <getopt.h>

// the mapping formats below are:
//   [char that we want] -> { [uinput key that needs to be hit to get that char, whether shift needs to be pressed] }

// QWERTY key mapping
std::map<char, std::pair<int, bool>> qwerty_key_mapping = {
    {'A', {KEY_A, true}},
    {'B', {KEY_B, true}},
    {'C', {KEY_C, true}},
    {'D', {KEY_D, true}},
    {'E', {KEY_E, true}},
    {'F', {KEY_F, true}},
    {'G', {KEY_G, true}},
    {'H', {KEY_H, true}},
    {'I', {KEY_I, true}},
    {'J', {KEY_J, true}},
    {'K', {KEY_K, true}},
    {'L', {KEY_L, true}},
    {'M', {KEY_M, true}},
    {'N', {KEY_N, true}},
    {'O', {KEY_O, true}},
    {'P', {KEY_P, true}},
    {'Q', {KEY_Q, true}},
    {'R', {KEY_R, true}},
    {'S', {KEY_S, true}},
    {'T', {KEY_T, true}},
    {'U', {KEY_U, true}},
    {'V', {KEY_V, true}},
    {'W', {KEY_W, true}},
    {'X', {KEY_X, true}},
    {'Y', {KEY_Y, true}},
    {'Z', {KEY_Z, true}},
    {'a', {KEY_A, false}},
    {'b', {KEY_B, false}},
    {'c', {KEY_C, false}},
    {'d', {KEY_D, false}},
    {'e', {KEY_E, false}},
    {'f', {KEY_F, false}},
    {'g', {KEY_G, false}},
    {'h', {KEY_H, false}},
    {'i', {KEY_I, false}},
    {'j', {KEY_J, false}},
    {'k', {KEY_K, false}},
    {'l', {KEY_L, false}},
    {'m', {KEY_M, false}},
    {'n', {KEY_N, false}},
    {'o', {KEY_O, false}},
    {'p', {KEY_P, false}},
    {'q', {KEY_Q, false}},
    {'r', {KEY_R, false}},
    {'s', {KEY_S, false}},
    {'t', {KEY_T, false}},
    {'u', {KEY_U, false}},
    {'v', {KEY_V, false}},
    {'w', {KEY_W, false}},
    {'x', {KEY_X, false}},
    {'y', {KEY_Y, false}},
    {'z', {KEY_Z, false}},
    {'0', {KEY_0, false}},
    {'1', {KEY_1, false}},
    {'2', {KEY_2, false}},
    {'3', {KEY_3, false}},
    {'4', {KEY_4, false}},
    {'5', {KEY_5, false}},
    {'6', {KEY_6, false}},
    {'7', {KEY_7, false}},
    {'8', {KEY_8, false}},
    {'9', {KEY_9, false}},
    {' ', {KEY_SPACE, false}},
    {'\n', {KEY_ENTER, false}},
    {',', {KEY_COMMA, false}},
    {'.', {KEY_DOT, false}},
    {'/', {KEY_SLASH, false}},
    {'-', {KEY_MINUS, false}},
    {'=', {KEY_EQUAL, false}},
    {';', {KEY_SEMICOLON, false}},
    {'\'', {KEY_APOSTROPHE, false}},
    {'[', {KEY_LEFTBRACE, false}},
    {']', {KEY_RIGHTBRACE, false}},
    {'\\', {KEY_BACKSLASH, false}},
    {'!', {KEY_1, true}},
    {'@', {KEY_2, true}},
    {'#', {KEY_3, true}},
    {'$', {KEY_4, true}},
    {'%', {KEY_5, true}},
    {'^', {KEY_6, true}},
    {'&', {KEY_7, true}},
    {'*', {KEY_8, true}},
    {'(', {KEY_9, true}},
    {')', {KEY_0, true}},
    {'_', {KEY_MINUS, true}},
    {'+', {KEY_EQUAL, true}},
    {':', {KEY_SEMICOLON, true}},
    {'"', {KEY_APOSTROPHE, true}},
    {'<', {KEY_COMMA, true}},
    {'>', {KEY_DOT, true}},
    {'?', {KEY_SLASH, true}},
    {'{', {KEY_LEFTBRACE, true}},
    {'}', {KEY_RIGHTBRACE, true}},
    {'|', {KEY_BACKSLASH, true}},
};

std::map<char, std::pair<int, bool>> dvorak_key_mapping = {
    {'A', {KEY_A, true}},
    {'O', {KEY_S, true}},
    {'E', {KEY_D, true}},
    {'U', {KEY_F, true}},
    {'I', {KEY_G, true}},
    {'D', {KEY_H, true}},
    {'H', {KEY_J, true}},
    {'T', {KEY_K, true}},
    {'N', {KEY_L, true}},
    {'S', {KEY_SEMICOLON, true}},
    {'\'', {KEY_Q, true}},
    {',', {KEY_W, true}},
    {'.', {KEY_E, true}},
    {'P', {KEY_R, true}},
    {'Y', {KEY_T, true}},
    {'F', {KEY_Y, true}},
    {'G', {KEY_U, true}},
    {'C', {KEY_I, true}},
    {'R', {KEY_O, true}},
    {'L', {KEY_P, true}},
    {'/', {KEY_LEFTBRACE, true}},
    {'=', {KEY_RIGHTBRACE, true}},
    {';', {KEY_Z, true}},
    {'Q', {KEY_X, true}},
    {'J', {KEY_C, true}},
    {'K', {KEY_V, true}},
    {'X', {KEY_B, true}},
    {'B', {KEY_N, true}},
    {'M', {KEY_M, true}},
    {'W', {KEY_COMMA, true}},
    {'V', {KEY_DOT, true}},
    {'Z', {KEY_SLASH, true}},
    {'a', {KEY_A, false}},
    {'o', {KEY_S, false}},
    {'e', {KEY_D, false}},
    {'u', {KEY_F, false}},
    {'i', {KEY_G, false}},
    {'d', {KEY_H, false}},
    {'h', {KEY_J, false}},
    {'t', {KEY_K, false}},
    {'n', {KEY_L, false}},
    {'s', {KEY_SEMICOLON, false}},
    {'-', {KEY_APOSTROPHE, false}},
    {'_', {KEY_APOSTROPHE, true}},
    {'\'', {KEY_Q, false}},
    {',', {KEY_W, false}},
    {'.', {KEY_E, false}},
    {'p', {KEY_R, false}},
    {'y', {KEY_T, false}},
    {'f', {KEY_Y, false}},
    {'g', {KEY_U, false}},
    {'c', {KEY_I, false}},
    {'r', {KEY_O, false}},
    {'l', {KEY_P, false}},
    {'/', {KEY_LEFTBRACE, false}},
    {'=', {KEY_RIGHTBRACE, false}},
    {';', {KEY_Z, false}},
    {'q', {KEY_X, false}},
    {'j', {KEY_C, false}},
    {'k', {KEY_V, false}},
    {'x', {KEY_B, false}},
    {'b', {KEY_N, false}},
    {'m', {KEY_M, false}},
    {'w', {KEY_COMMA, false}},
    {'v', {KEY_DOT, false}},
    {'z', {KEY_SLASH, false}},
    {' ', {KEY_SPACE, false}},
    {'\n', {KEY_ENTER, false}},
    {'\"', {KEY_Q, true}},
    {'<', {KEY_W, true}},
    {'>', {KEY_E, true}},
    {'?', {KEY_LEFTBRACE, true}},
    {'+', {KEY_RIGHTBRACE, true}},
    {':', {KEY_Z, true}},
    {'0', {KEY_0, false}},
    {'1', {KEY_1, false}},
    {'2', {KEY_2, false}},
    {'3', {KEY_3, false}},
    {'4', {KEY_4, false}},
    {'5', {KEY_5, false}},
    {'6', {KEY_6, false}},
    {'7', {KEY_7, false}},
    {'8', {KEY_8, false}},
    {'9', {KEY_9, false}},
};


std::string get_clipboard_content() {
    char buffer[128];
    std::string result = "";
    FILE* pipe = popen("xclip -o -selection clipboard", "r");
    if (!pipe) throw std::runtime_error("popen() failed!");
    try {
        while (fgets(buffer, sizeof(buffer), pipe) != nullptr) {
            result += buffer;
        }
    } catch (...) {
        pclose(pipe);
        throw;
    }
    pclose(pipe);
    return result;
}

void send_keystrokes(const std::string& content, int fd, int delay_ms, std::map<char, std::pair<int, bool>>& key_mapping) {
    struct input_event ev;

    for (char ch : content) {
        auto key_pair = key_mapping.find(ch);
        if (key_pair != key_mapping.end()) {
            int key = key_pair->second.first;
            bool shift = key_pair->second.second;

            if (shift) {
                memset(&ev, 0, sizeof(struct input_event));
                ev.type = EV_KEY;
                ev.code = KEY_LEFTSHIFT;
                ev.value = 1;
                write(fd, &ev, sizeof(struct input_event));

                memset(&ev, 0, sizeof(struct input_event));
                ev.type = EV_KEY;
                ev.code = key;
                ev.value = 1;
                write(fd, &ev, sizeof(struct input_event));

                memset(&ev, 0, sizeof(struct input_event));
                ev.type = EV_KEY;
                ev.code = key;
                ev.value = 0;
                write(fd, &ev, sizeof(struct input_event));

                memset(&ev, 0, sizeof(struct input_event));
                ev.type = EV_KEY;
                ev.code = KEY_LEFTSHIFT;
                ev.value = 0;
                write(fd, &ev, sizeof(struct input_event));
            } else {
                memset(&ev, 0, sizeof(struct input_event));
                ev.type = EV_KEY;
                ev.code = key;
                ev.value = 1;
                write(fd, &ev, sizeof(struct input_event));

                memset(&ev, 0, sizeof(struct input_event));
                ev.type = EV_KEY;
                ev.code = key;
                ev.value = 0;
                write(fd, &ev, sizeof(struct input_event));
            }

            memset(&ev, 0, sizeof(struct input_event));
            ev.type = EV_SYN;
            ev.code = SYN_REPORT;
            ev.value = 0;
            write(fd, &ev, sizeof(struct input_event));

            usleep(delay_ms * 1000); // Delay in microseconds
        }
    }
}

int main(int argc, char* argv[]) {
    int delay_ms = 0; // Default delay is 0 ms
    std::map<char, std::pair<int, bool>>* key_mapping = &qwerty_key_mapping; // Default to QWERTY

    // Option parsing
    int opt;
    while ((opt = getopt(argc, argv, "d:l:")) != -1) {
        switch (opt) {
            case 'd':
                delay_ms = atoi(optarg);
                break;
            case 'l':
                if (std::string(optarg) == "dvorak") {
                    key_mapping = &dvorak_key_mapping;
                } else if (std::string(optarg) != "qwerty") {
                    std::cerr << "Unknown layout: " << optarg << std::endl;
                    return EXIT_FAILURE;
                }
                break;
            default:
                std::cerr << "Usage: " << argv[0] << " [-d delay_in_ms] [-l layout (qwerty|dvorak)]" << std::endl;
                return EXIT_FAILURE;
        }
    }

    int fd = open("/dev/uinput", O_WRONLY | O_NONBLOCK);
    if (fd < 0) {
        std::cerr << "Error: Unable to open /dev/uinput" << std::endl;
        return EXIT_FAILURE;
    }

    ioctl(fd, UI_SET_EVBIT, EV_KEY);
    ioctl(fd, UI_SET_EVBIT, EV_SYN);

    for (const auto& key : *key_mapping) {
        ioctl(fd, UI_SET_KEYBIT, key.second.first);
    }
    ioctl(fd, UI_SET_KEYBIT, KEY_LEFTSHIFT);

    struct uinput_setup usetup;
    memset(&usetup, 0, sizeof(usetup));
    usetup.id.bustype = BUS_USB;
    usetup.id.vendor = 0x1234; // Sample vendor
    usetup.id.product = 0x5678; // Sample product
    strcpy(usetup.name, "Clipboard-Paste-Device");

    ioctl(fd, UI_DEV_SETUP, &usetup);
    ioctl(fd, UI_DEV_CREATE);

    sleep(1); // Wait for the device to be ready

    std::string clipboard_content = get_clipboard_content();
    send_keystrokes(clipboard_content, fd, delay_ms, *key_mapping);

    ioctl(fd, UI_DEV_DESTROY);
    close(fd);

    return EXIT_SUCCESS;
}






