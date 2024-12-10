# ASCII Weather

ASCII Weather is a terminal screensaver that displays various weather conditions using ASCII art. The project is built in C and utilizes the `ncurses` library for terminal-based user interfaces. You can build the project either manually using `make` or by using `nix`.

<!--toc:start-->

- [ASCII Weather](#ascii-weather)
  - [Features](#features)
  - [Requirements](#requirements)
  - [Installation](#installation)
    - [Option 1: Build with `make`](#option-1-build-with-make)
    - [Option 2: Build with `nix`](#option-2-build-with-nix)
  - [Usage](#usage)
  - [Troubleshooting](#troubleshooting)
  - [License](#license)
  - [Contributing](#contributing)
  <!--toc:end-->

## Features

- Displays different weather conditions in ASCII art format.
- Built with `ncurses` for a smooth terminal experience.
- Supports manual build using `make` or automated build using `nix`.
- Includes a help menu with the `-h` or `--help` flag.
- Allows you to change the weather using an interactive menu.
- Keybindings:
  - `ESC` or `q` to quit.
  - `m` to open the weather changer menu.

## Requirements

- `ncurses` library for terminal manipulation.
- A Unix-like environment (Linux/macOS) for building and running.

## Installation

You can build and install the project in two ways: manually using `make` or by using `nix`.

### Option 1: Build with `make`

1. Clone the repository:

   ```bash
   git clone https://github.com/NewDawn0/asciiWeather.git
   ```

2. Navigate to the project directory:

   ```bash
   cd asciiWeather
   ```

3. Build the project using `make`:

   ```bash
   make build
   ```

4. After building, you can run the program:
   ```bash
   ./ascii-weather
   ```

### Option 2: Build with `nix`

If you're using `nix`, you can build the project with the provided `nix` configuration:

1. Clone the repository (if you haven't already):

   ```bash
   git clone https://github.com/NewDawn0/asciiWeather.git
   ```

2. Navigate to the project directory:

   ```bash
   cd asciiWeather
   ```

3. Build the project with `nix`:

   ```bash
   nix build
   ```

4. Once the build is complete, run the program:
   ```bash
   ./result/bin/ascii-weather
   ```

## Usage

When you run the program, it will display different weather conditions in your terminal window. You can use the following options and keybindings:

- **Help Menu**: Use the `-h` or `--help` flag to display a list of available weather options and keybindings.

  Example:

  ```bash
  ./ascii-weather -h
  ```

- **Changing Weather**: Press `m` to bring up the weather changer menu, where you can choose from different weather conditions listed in the help menu.

- **Quit the Program**: Press `ESC` or `q` to quit the program at any time.

The screensaver will run until you quit it. You can change the weather at any time by opening the weather changer menu.

## Troubleshooting

If you encounter any issues during build or runtime:

- Ensure that the `ncurses` library is installed on your system.
- On Linux, you can install it using:
  ```bash
  sudo apt-get install libncurses-dev
  ```
- On macOS, you can use Homebrew:
  ```bash
  brew install ncurses
  ```

## License

This project is open-source and available under the [MIT License](LICENSE).

## Contributing

Feel free to open issues or submit pull requests to contribute to this project.
