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

// QWERTY key mapping

constexpr std::vector<std::pair<int, bool>> generate_qwerty_key_mapping() {
    const std::pair<int, bool> default_key = {0, false};
    std::vector<std::pair<int, bool>> mapping(256, default_key);

    mapping['1'] = {KEY_1, false};
    mapping['!'] = {KEY_1, true};

    mapping['2'] = {KEY_2, false};
    mapping['@'] = {KEY_2, true};

    mapping['3'] = {KEY_3, false};
    mapping['#'] = {KEY_3, true};

    mapping['4'] = {KEY_4, false};
    mapping['$'] = {KEY_4, true};

    mapping['5'] = {KEY_5, false};
    mapping['%'] = {KEY_5, true};

    mapping['6'] = {KEY_6, false};
    mapping['^'] = {KEY_6, true};

    mapping['7'] = {KEY_7, false};
    mapping['&'] = {KEY_7, true};

    mapping['8'] = {KEY_8, false};
    mapping['*'] = {KEY_8, true};

    mapping['9'] = {KEY_9, false};
    mapping['('] = {KEY_9, true};

    mapping['0'] = {KEY_0, false};
    mapping[')'] = {KEY_0, true};

    mapping['/'] = {KEY_SLASH, false};
    mapping['?'] = {KEY_SLASH, true};

    mapping['\''] = {KEY_APOSTROPHE, false};
    mapping['"'] = {KEY_APOSTROPHE, true};

    mapping['='] = {KEY_EQUAL, false};
    mapping['+'] = {KEY_EQUAL, true};

    mapping['\\'] = {KEY_BACKSLASH, false};
    mapping['|'] = {KEY_BACKSLASH, true};

    mapping[','] = {KEY_COMMA, false};
    mapping['<'] = {KEY_COMMA, true};

    mapping['.'] = {KEY_DOT, false};
    mapping['>'] = {KEY_DOT, true};

    mapping['['] = {KEY_LEFTBRACE, false};
    mapping['{'] = {KEY_LEFTBRACE, true};

    mapping[']'] = {KEY_RIGHTBRACE, false};
    mapping['}'] = {KEY_RIGHTBRACE, true};

    mapping['-'] = {KEY_MINUS, false};
    mapping['_'] = {KEY_MINUS, true};

    mapping[';'] = {KEY_SEMICOLON, false};
    mapping[':'] = {KEY_SEMICOLON, true};

    mapping[' '] = {KEY_SPACE, false};

    mapping['\n'] = {KEY_ENTER, false};

    mapping['a'] = {KEY_A, false};
    mapping['A'] = {KEY_A, true};

    mapping['b'] = {KEY_B, false};
    mapping['B'] = {KEY_B, true};

    mapping['c'] = {KEY_C, false};
    mapping['C'] = {KEY_C, true};

    mapping['d'] = {KEY_D, false};
    mapping['D'] = {KEY_D, true};

    mapping['e'] = {KEY_E, false};
    mapping['E'] = {KEY_E, true};

    mapping['f'] = {KEY_F, false};
    mapping['F'] = {KEY_F, true};

    mapping['g'] = {KEY_G, false};
    mapping['G'] = {KEY_G, true};

    mapping['h'] = {KEY_H, false};
    mapping['H'] = {KEY_H, true};

    mapping['i'] = {KEY_I, false};
    mapping['I'] = {KEY_I, true};

    mapping['j'] = {KEY_J, false};
    mapping['J'] = {KEY_J, true};

    mapping['k'] = {KEY_K, false};
    mapping['K'] = {KEY_K, true};

    mapping['l'] = {KEY_L, false};
    mapping['L'] = {KEY_L, true};

    mapping['m'] = {KEY_M, false};
    mapping['M'] = {KEY_M, true};

    mapping['n'] = {KEY_N, false};
    mapping['N'] = {KEY_N, true};

    mapping['o'] = {KEY_O, false};
    mapping['O'] = {KEY_O, true};

    mapping['p'] = {KEY_P, false};
    mapping['P'] = {KEY_P, true};

    mapping['q'] = {KEY_Q, false};
    mapping['Q'] = {KEY_Q, true};

    mapping['r'] = {KEY_R, false};
    mapping['R'] = {KEY_R, true};

    mapping['s'] = {KEY_S, false};
    mapping['S'] = {KEY_S, true};

    mapping['t'] = {KEY_T, false};
    mapping['T'] = {KEY_T, true};

    mapping['u'] = {KEY_U, false};
    mapping['U'] = {KEY_U, true};

    mapping['v'] = {KEY_V, false};
    mapping['V'] = {KEY_V, true};

    mapping['w'] = {KEY_W, false};
    mapping['W'] = {KEY_W, true};

    mapping['x'] = {KEY_X, false};
    mapping['X'] = {KEY_X, true};

    mapping['y'] = {KEY_Y, false};
    mapping['Y'] = {KEY_Y, true};

    mapping['z'] = {KEY_Z, false};
    mapping['Z'] = {KEY_Z, true};

    return mapping;
}

constexpr std::vector<std::pair<int, bool>> generate_dvorak_key_mapping() {
    const std::pair<int, bool> default_key = {0, false};
    std::vector<std::pair<int, bool>> mapping(256, default_key);

    mapping['1'] = {KEY_1, false};
    mapping['!'] = {KEY_1, true};

    mapping['2'] = {KEY_2, false};
    mapping['@'] = {KEY_2, true};

    mapping['3'] = {KEY_3, false};
    mapping['#'] = {KEY_3, true};

    mapping['4'] = {KEY_4, false};
    mapping['$'] = {KEY_4, true};

    mapping['5'] = {KEY_5, false};
    mapping['%'] = {KEY_5, true};

    mapping['6'] = {KEY_6, false};
    mapping['^'] = {KEY_6, true};

    mapping['7'] = {KEY_7, false};
    mapping['&'] = {KEY_7, true};

    mapping['8'] = {KEY_8, false};
    mapping['*'] = {KEY_8, true};

    mapping['9'] = {KEY_9, false};
    mapping['('] = {KEY_9, true};

    mapping['0'] = {KEY_0, false};
    mapping[')'] = {KEY_0, true};

    mapping['\\'] = {KEY_BACKSLASH, false};
    mapping['|'] = {KEY_BACKSLASH, true};

    mapping['/'] = {KEY_LEFTBRACE, false};
    mapping['?'] = {KEY_LEFTBRACE, true};

    mapping['='] = {KEY_RIGHTBRACE, false};
    mapping['+'] = {KEY_RIGHTBRACE, true};

    mapping['['] = {KEY_MINUS, false};
    mapping['{'] = {KEY_MINUS, true};

    mapping[']'] = {KEY_EQUAL, false};
    mapping['}'] = {KEY_EQUAL, true};

    mapping[' '] = {KEY_SPACE, false};

    mapping['\n'] = {KEY_ENTER, false};

    mapping['\''] = {KEY_Q, false};
    mapping['"'] = {KEY_Q, true};

    mapping[','] = {KEY_W, false};
    mapping['<'] = {KEY_W, true};

    mapping['.'] = {KEY_E, false};
    mapping['>'] = {KEY_E, true};

    mapping[';'] = {KEY_Z, false};
    mapping[':'] = {KEY_Z, true};

    mapping['-'] = {KEY_APOSTROPHE, false};
    mapping['_'] = {KEY_APOSTROPHE, true};

    mapping['a'] = {KEY_A, false};
    mapping['A'] = {KEY_A, true};

    mapping['b'] = {KEY_N, false};
    mapping['B'] = {KEY_N, true};

    mapping['c'] = {KEY_I, false};
    mapping['C'] = {KEY_I, true};

    mapping['d'] = {KEY_H, false};
    mapping['D'] = {KEY_H, true};

    mapping['e'] = {KEY_D, false};
    mapping['E'] = {KEY_D, true};

    mapping['f'] = {KEY_Y, false};
    mapping['F'] = {KEY_Y, true};

    mapping['g'] = {KEY_U, false};
    mapping['G'] = {KEY_U, true};

    mapping['h'] = {KEY_J, false};
    mapping['H'] = {KEY_J, true};

    mapping['i'] = {KEY_G, false};
    mapping['I'] = {KEY_G, true};

    mapping['j'] = {KEY_C, false};
    mapping['J'] = {KEY_C, true};

    mapping['k'] = {KEY_V, false};
    mapping['K'] = {KEY_V, true};

    mapping['l'] = {KEY_P, false};
    mapping['L'] = {KEY_P, true};

    mapping['m'] = {KEY_M, false};
    mapping['M'] = {KEY_M, true};

    mapping['n'] = {KEY_L, false};
    mapping['N'] = {KEY_L, true};

    mapping['o'] = {KEY_S, false};
    mapping['O'] = {KEY_S, true};

    mapping['p'] = {KEY_R, false};
    mapping['P'] = {KEY_R, true};

    mapping['q'] = {KEY_X, false};
    mapping['Q'] = {KEY_X, true};

    mapping['r'] = {KEY_O, false};
    mapping['R'] = {KEY_O, true};

    mapping['s'] = {KEY_SEMICOLON, false};
    mapping['S'] = {KEY_SEMICOLON, true};

    mapping['t'] = {KEY_K, false};
    mapping['T'] = {KEY_K, true};

    mapping['u'] = {KEY_F, false};
    mapping['U'] = {KEY_F, true};

    mapping['v'] = {KEY_DOT, false};
    mapping['V'] = {KEY_DOT, true};

    mapping['w'] = {KEY_COMMA, false};
    mapping['W'] = {KEY_COMMA, true};

    mapping['x'] = {KEY_B, false};
    mapping['X'] = {KEY_B, true};

    mapping['y'] = {KEY_T, false};
    mapping['Y'] = {KEY_T, true};

    mapping['z'] = {KEY_SLASH, false};
    mapping['Z'] = {KEY_SLASH, true};

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
    int delay_ms = 1; // Default delay is 0 ms
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

    usleep(400000); // Wait for the device to be ready

    std::string clipboard_content = get_clipboard_content();
    send_keystrokes(clipboard_content, fd, key_mapping, delay_ms);

    ioctl(fd, UI_DEV_DESTROY);
    close(fd);

    return EXIT_SUCCESS;
}
