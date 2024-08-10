#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <unistd.h>
#include <linux/uinput.h>
#include <fcntl.h>
#include <cstring>
#include <cstdlib>
#include <getopt.h>

// the mapping formats below are:
// [char that we want] -> { [uinput key that needs to be hit to get that char], [whether shift needs to be pressed] }

constexpr std::pair<int, bool> default_key = {0, false};

// QWERTY key mapping

constexpr std::vector<std::pair<int, bool>> generate_qwerty_key_mapping() {
    std::vector<std::pair<int, bool>> mapping(256, default_key);

    mapping['A'] = {KEY_A, false};
    mapping['B'] = {KEY_B, false};
    mapping['C'] = {KEY_C, false};
    mapping['D'] = {KEY_D, false};
    mapping['E'] = {KEY_E, false};
    mapping['F'] = {KEY_F, false};
    mapping['G'] = {KEY_G, false};
    mapping['H'] = {KEY_H, false};
    mapping['I'] = {KEY_I, false};
    mapping['J'] = {KEY_J, false};
    mapping['K'] = {KEY_K, false};
    mapping['L'] = {KEY_L, false};
    mapping['M'] = {KEY_M, false};
    mapping['N'] = {KEY_N, false};
    mapping['O'] = {KEY_O, false};
    mapping['P'] = {KEY_P, false};
    mapping['Q'] = {KEY_Q, false};
    mapping['R'] = {KEY_R, false};
    mapping['S'] = {KEY_S, false};
    mapping['T'] = {KEY_T, false};
    mapping['U'] = {KEY_U, false};
    mapping['V'] = {KEY_V, false};
    mapping['W'] = {KEY_W, false};
    mapping['X'] = {KEY_X, false};
    mapping['Y'] = {KEY_Y, false};
    mapping['Z'] = {KEY_Z, false};
    mapping['a'] = {KEY_A, false};
    mapping['b'] = {KEY_B, false};
    mapping['c'] = {KEY_C, false};
    mapping['d'] = {KEY_D, false};
    mapping['e'] = {KEY_E, false};
    mapping['f'] = {KEY_F, false};
    mapping['g'] = {KEY_G, false};
    mapping['h'] = {KEY_H, false};
    mapping['i'] = {KEY_I, false};
    mapping['j'] = {KEY_J, false};
    mapping['k'] = {KEY_K, false};
    mapping['l'] = {KEY_L, false};
    mapping['m'] = {KEY_M, false};
    mapping['n'] = {KEY_N, false};
    mapping['o'] = {KEY_O, false};
    mapping['p'] = {KEY_P, false};
    mapping['q'] = {KEY_Q, false};
    mapping['r'] = {KEY_R, false};
    mapping['s'] = {KEY_S, false};
    mapping['t'] = {KEY_T, false};
    mapping['u'] = {KEY_U, false};
    mapping['v'] = {KEY_V, false};
    mapping['w'] = {KEY_W, false};
    mapping['x'] = {KEY_X, false};
    mapping['y'] = {KEY_Y, false};
    mapping['z'] = {KEY_Z, false};
    mapping['0'] = {KEY_0, false};
    mapping['1'] = {KEY_1, false};
    mapping['2'] = {KEY_2, false};
    mapping['3'] = {KEY_3, false};
    mapping['4'] = {KEY_4, false};
    mapping['5'] = {KEY_5, false};
    mapping['6'] = {KEY_6, false};
    mapping['7'] = {KEY_7, false};
    mapping['8'] = {KEY_8, false};
    mapping['9'] = {KEY_9, false};
    mapping[' '] = {KEY_SPACE, false};
    mapping['\n'] = {KEY_ENTER, false};
    mapping[','] = {KEY_COMMA, false};
    mapping['.'] = {KEY_DOT, false};
    mapping['/'] = {KEY_SLASH, false};
    mapping['-'] = {KEY_MINUS, false};
    mapping['='] = {KEY_EQUAL, false};
    mapping[';'] = {KEY_SEMICOLON, false};
    mapping['\''] = {KEY_APOSTROPHE, false};
    mapping['['] = {KEY_LEFTBRACE, false};
    mapping[']'] = {KEY_RIGHTBRACE, false};
    mapping['\\'] = {KEY_BACKSLASH, false};
    mapping['!'] = {KEY_1, true};
    mapping['@'] = {KEY_2, true};
    mapping['#'] = {KEY_3, true};
    mapping['$'] = {KEY_4, true};
    mapping['%'] = {KEY_5, true};
    mapping['^'] = {KEY_6, true};
    mapping['&'] = {KEY_7, true};
    mapping['*'] = {KEY_8, true};
    mapping['('] = {KEY_9, true};
    mapping[')'] = {KEY_0, true};
    mapping['_'] = {KEY_MINUS, true};
    mapping['+'] = {KEY_EQUAL, true};
    mapping[':'] = {KEY_SEMICOLON, true};
    mapping['"'] = {KEY_APOSTROPHE, true};
    mapping['<'] = {KEY_COMMA, true};
    mapping['>'] = {KEY_DOT, true};
    mapping['?'] = {KEY_SLASH, true};
    mapping['{'] = {KEY_LEFTBRACE, true};
    mapping['}'] = {KEY_RIGHTBRACE, true};
    mapping['|'] = {KEY_BACKSLASH, true};

    return mapping;
}

constexpr std::vector<std::pair<int, bool>> generate_dvorak_key_mapping() {
    std::vector<std::pair<int, bool>> mapping(256, default_key);

    mapping['A'] = {KEY_A, true};
    mapping['O'] = {KEY_S, true};
    mapping['E'] = {KEY_D, true};
    mapping['U'] = {KEY_F, true};
    mapping['I'] = {KEY_G, true};
    mapping['D'] = {KEY_H, true};
    mapping['H'] = {KEY_J, true};
    mapping['T'] = {KEY_K, true};
    mapping['N'] = {KEY_L, true};
    mapping['S'] = {KEY_SEMICOLON, true};
    mapping['\''] = {KEY_Q, true};
    mapping[','] = {KEY_W, true};
    mapping['.'] = {KEY_E, true};
    mapping['P'] = {KEY_R, true};
    mapping['Y'] = {KEY_T, true};
    mapping['F'] = {KEY_Y, true};
    mapping['G'] = {KEY_U, true};
    mapping['C'] = {KEY_I, true};
    mapping['R'] = {KEY_O, true};
    mapping['L'] = {KEY_P, true};
    mapping['/'] = {KEY_LEFTBRACE, true};
    mapping['='] = {KEY_RIGHTBRACE, true};
    mapping[';'] = {KEY_Z, true};
    mapping['Q'] = {KEY_X, true};
    mapping['J'] = {KEY_C, true};
    mapping['K'] = {KEY_V, true};
    mapping['X'] = {KEY_B, true};
    mapping['B'] = {KEY_N, true};
    mapping['M'] = {KEY_M, true};
    mapping['W'] = {KEY_COMMA, true};
    mapping['V'] = {KEY_DOT, true};
    mapping['Z'] = {KEY_SLASH, true};
    mapping['a'] = {KEY_A, false};
    mapping['o'] = {KEY_S, false};
    mapping['e'] = {KEY_D, false};
    mapping['u'] = {KEY_F, false};
    mapping['i'] = {KEY_G, false};
    mapping['d'] = {KEY_H, false};
    mapping['h'] = {KEY_J, false};
    mapping['t'] = {KEY_K, false};
    mapping['n'] = {KEY_L, false};
    mapping['s'] = {KEY_SEMICOLON, false};
    mapping['-'] = {KEY_APOSTROPHE, false};
    mapping['_'] = {KEY_APOSTROPHE, true};
    mapping['\''] = {KEY_Q, false};
    mapping[','] = {KEY_W, false};
    mapping['.'] = {KEY_E, false};
    mapping['p'] = {KEY_R, false};
    mapping['y'] = {KEY_T, false};
    mapping['f'] = {KEY_Y, false};
    mapping['g'] = {KEY_U, false};
    mapping['c'] = {KEY_I, false};
    mapping['r'] = {KEY_O, false};
    mapping['l'] = {KEY_P, false};
    mapping['/'] = {KEY_LEFTBRACE, true};
    mapping['}'] = {KEY_RIGHTBRACE, true};
    mapping['|'] = {KEY_BACKSLASH, true};

    return mapping;
}

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

void send_keystrokes(const std::string& content, int fd, const std::vector<std::pair<int, bool>>& key_mapping, int delay_ms) {
    struct input_event ev;

    for (char ch : content) {
        if (static_cast<unsigned char>(ch) < key_mapping.size()) {
            auto key_pair = key_mapping[static_cast<unsigned char>(ch)];
            int key = key_pair.first;
            bool shift = key_pair.second;

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
    bool use_dvorak = false; // Default to QWERTY

    // Option parsing
    int opt;
    while ((opt = getopt(argc, argv, "d:k:")) != -1) {
        switch (opt) {
            case 'd':
                delay_ms = atoi(optarg);
                break;
            case 'k':
                if (strcmp(optarg, "dvorak") == 0) {
                    use_dvorak = true;
                }
                break;
            default:
                std::cerr << "Usage: " << argv[0] << " [-d delay_in_ms] [-k keyboard_layout]" << std::endl;
                std::cerr << "Keyboard layout options: qwerty, dvorak" << std::endl;
                return EXIT_FAILURE;
        }
    }

    const auto qwerty_mapping = generate_qwerty_key_mapping();
    const auto dvorak_mapping = generate_dvorak_key_mapping();
    const auto& key_mapping = use_dvorak ? dvorak_mapping : qwerty_mapping;

    int fd = open("/dev/uinput", O_WRONLY | O_NONBLOCK);
    if (fd < 0) {
        std::cerr << "Error: Unable to open /dev/uinput" << std::endl;
        return EXIT_FAILURE;
    }

    ioctl(fd, UI_SET_EVBIT, EV_KEY);
    ioctl(fd, UI_SET_EVBIT, EV_SYN);

    for (const auto& key : key_mapping) {
        ioctl(fd, UI_SET_KEYBIT, key.first);
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
    send_keystrokes(clipboard_content, fd, key_mapping, delay_ms);

    ioctl(fd, UI_DEV_DESTROY);
    close(fd);

    return EXIT_SUCCESS;
}
