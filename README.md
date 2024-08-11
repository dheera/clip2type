# clip2type

If you have encountered any websites that don't let you paste things from the clipboard, e.g.

* Bank websites that don't let you paste routing/account numbers for wire transfers
* Virtual machines that capture Ctrl+V but don't sync the clipboard
* SMS confirmations that use 6 separate text boxes and don't paste the code correctly
* Buggy HTML code editors
* Probably a lot of other things

... this is the solution. It takes the (text) contents of the keyboard, emulates a fake hardware USB keyboard on /dev/uinput and types out whatever is in the clipboard, so that the receiving application doesn't "know" it is being pasted into.

Supports qwerty and dvorak layouts (it is layout dependent since it is emulating actual **keystrokes**on /dev/uinput and so it needs to know whether your UI is configured for qwerty or dvorak). If you have some other layout, edit it yourself.

This should work on x11 and wayland, but I have only tested it on wayland.
