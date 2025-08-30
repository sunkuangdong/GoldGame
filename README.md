# 🪙 Gold Game - Qt Coin Flip Puzzle

[![Qt](https://img.shields.io/badge/Qt-5%2F6-green.svg)](https://www.qt.io/)
[![C++](https://img.shields.io/badge/C%2B%2B-17-blue.svg)](https://isocpp.org/)
[![CMake](https://img.shields.io/badge/CMake-3.16%2B-red.svg)](https://cmake.org/)
[![Platform](https://img.shields.io/badge/Platform-Windows%20%7C%20macOS%20%7C%20Linux-lightgrey.svg)](https://github.com/sunkuangdong/GoldGame)

A sophisticated **cross-platform puzzle game** built with Qt/C++, featuring elegant UI design, smooth animations, and challenging gameplay mechanics. Players must strategically flip coins to achieve uniform orientation across a 4×4 grid.

> **🎮 [▶️ Download & Play Now](https://github.com/sunkuangdong/GoldGame_zip)** - Ready to run on Windows, no installation required!

## ✨ Features

### 🎮 Core Gameplay
- **20 Progressive Levels** with increasing difficulty
- **4×4 Grid System** with strategic coin-flipping mechanics
- **Chain Reaction Logic** - clicking a coin affects adjacent coins
- **Win Condition Detection** with smooth victory animations

### 🎨 User Interface
- **Multi-Scene Architecture** (Main Menu → Level Selection → Gameplay)
- **Custom Widget Components** with hover effects and animations
- **Responsive Design** optimized for 320×588 resolution
- **Intuitive Navigation** with back button functionality

### 🔊 Multimedia Integration
- **Immersive Audio System** with sound effects for interactions
- **High-Quality Graphics** with coin flip animations
- **Resource Management** through Qt Resource System
- **Smooth Transitions** between game states

### 🛠️ Technical Excellence
- **Object-Oriented Architecture** with custom classes (`MyCoin`, `MyPushButton`)
- **Event-Driven Programming** with Qt signal-slot mechanism
- **Memory Management** with proper cleanup and deletion
- **Cross-Platform Compatibility** via CMake build system

## 🏗️ Architecture

```
┌─────────────────┐    ┌──────────────────┐    ┌─────────────────┐
│   MainScene     │───▶│ ChooseLevelScene │───▶│   PlayScene     │
│  (Entry Point)  │    │  (Level Grid)    │    │ (Game Logic)    │
└─────────────────┘    └──────────────────┘    └─────────────────┘
         │                        │                       │
         ▼                        ▼                       ▼
┌─────────────────┐    ┌──────────────────┐    ┌─────────────────┐
│ MyPushButton    │    │   Custom UI      │    │    MyCoin       │
│ (Interactions)  │    │   Components     │    │ (Game Entity)   │
└─────────────────┘    └──────────────────┘    └─────────────────┘
```

## 🚀 Quick Start

### Option 1: Download & Play (Windows) 🎮

**For immediate gameplay:**

1. **Download the game**
   ```bash
   git clone https://github.com/sunkuangdong/GoldGame_zip.git
   cd GoldGame_zip
   ```

2. **Run the game**
   ```bash
   # Double-click CoinFilp.exe or run from command line
   ./CoinFilp.exe
   ```

### Option 2: Build from Source 🛠️

**For development or other platforms:**

#### Prerequisites
- **Qt 5.12+** or **Qt 6.x**
- **CMake 3.16+**
- **C++17** compatible compiler
- **Git** (for cloning)

#### Installation

1. **Clone the repository**
   ```bash
   git clone https://github.com/sunkuangdong/GoldGame.git
   cd GoldGame
   ```

2. **Create build directory**
   ```bash
   mkdir build && cd build
   ```

3. **Configure with CMake**
   ```bash
   cmake .. -DCMAKE_BUILD_TYPE=Release
   ```

4. **Build the project**
   ```bash
   cmake --build . --config Release
   ```

5. **Run the game**
   ```bash
   ./CoinFilp        # Linux/macOS
   CoinFilp.exe      # Windows
   ```

### Alternative: Qt Creator
1. Open `CMakeLists.txt` in Qt Creator
2. Configure kit and build directory
3. Build and run the project

## 🎯 How to Play

1. **Start the Game** - Launch from the main menu
2. **Select Level** - Choose from 20 available levels (1-20)
3. **Flip Strategy** - Click coins to flip them and adjacent coins
4. **Win Condition** - Turn all coins to show the same side (heads)
5. **Progress** - Complete levels to unlock new challenges

### Game Rules
- Clicking a coin flips it and its **four adjacent** coins (up, down, left, right)
- **Diagonal coins** are not affected
- **Edge and corner** coins have fewer adjacent coins
- **Strategic thinking** required to solve puzzles efficiently

## 📁 Project Structure

```
GoldGame/
├── 📄 main.cpp                # Application entry point
├── 📄 mainscene.{h,cpp,ui}    # Main menu scene
├── 📄 chooselevelscene.{h,cpp} # Level selection scene
├── 📄 playscene.{h,cpp}       # Gameplay scene
├── 📄 mycoin.{h,cpp}          # Coin widget implementation
├── 📄 mypushbutton.{h,cpp}    # Custom button widget
├── 📄 dataconfig.{h,cpp}      # Level data configuration
├── 📁 res/                    # Game resources
│   ├── 🖼️ *.png              # UI graphics and sprites
│   ├── 🔊 *.wav              # Audio files
│   └── res.qrc               # Qt resource file
├── 📁 build/                  # Build artifacts
├── 📄 CMakeLists.txt          # Build configuration
└── 📄 README.md               # Project documentation
```

## 🔧 Development

### Code Style
- **Modern C++17** features and best practices
- **Qt conventions** for signal-slot connections
- **RAII** for resource management
- **Const-correctness** where applicable

### Key Components

#### `MyCoin` Class
```cpp
class MyCoin : public QPushButton {
    Q_OBJECT
public:
    MyCoin(QString imgPath);
    void changeFlag();           // Flip coin state
    bool flag;                   // Current coin state
    int posX, posY;             // Grid position
    bool isAnimation;           // Animation state
    bool isWin;                 // Win condition flag
};
```

#### `PlayScene` Logic
- **Grid Management**: 4×4 array tracking coin states
- **Click Handling**: Processes coin interactions
- **Win Detection**: Checks victory conditions
- **Animation System**: Smooth transitions and effects

### Building from Source

**Debug Build:**
```bash
cmake .. -DCMAKE_BUILD_TYPE=Debug
cmake --build . --config Debug
```

**Release Build:**
```bash
cmake .. -DCMAKE_BUILD_TYPE=Release
cmake --build . --config Release
```

## 🤝 Contributing

Contributions are welcome! Please feel free to submit issues, feature requests, or pull requests.

### Development Guidelines
1. Follow the existing code style and conventions
2. Write clear commit messages
3. Test your changes thoroughly
4. Update documentation as needed

## 📄 License

This project is open source and available under the [MIT License](LICENSE).

## 🔗 Links

- **🎮 Play Now**: [Download & Play the Game](https://github.com/sunkuangdong/GoldGame_zip) - Ready-to-run Windows executable
- **📝 Source Code**: [View on GitHub](https://github.com/sunkuangdong/GoldGame) - Complete source code and development files
- **🐛 Issues**: [Report bugs](https://github.com/sunkuangdong/GoldGame/issues)
- **📦 Releases**: [Download builds](https://github.com/sunkuangdong/GoldGame/releases)

## 📂 Repository Structure

This project is organized across two GitHub repositories:

- **📦 [GoldGame](https://github.com/sunkuangdong/GoldGame)** - Complete source code, development files, and documentation
- **🎮 [GoldGame_zip](https://github.com/sunkuangdong/GoldGame_zip)** - Pre-built Windows executable with all dependencies

## 📧 Contact

**Developer**: sunkuangdong  
**GitHub**: [@sunkuangdong](https://github.com/sunkuangdong)

---

*Built with ❤️ using Qt and C++*
