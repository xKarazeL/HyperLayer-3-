# Makefile for HyperLayer Protocol
# Tamamen özgün Layer 3 blockchain

CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -O3 -pthread
LDFLAGS = -pthread

# Targets
TARGET = hyperlayer
SOURCES = main.cpp hyperlayer_core.cpp hyperlayer_core_part2.cpp
HEADERS = hyperlayer_core.hpp
OBJECTS = $(SOURCES:.cpp=.o)

# Colors for output
RED = \033[0;31m
GREEN = \033[0;32m
YELLOW = \033[0;33m
BLUE = \033[0;34m
MAGENTA = \033[0;35m
CYAN = \033[0;36m
NC = \033[0m # No Color

.PHONY: all clean run test help banner

all: banner $(TARGET)
	@echo "$(GREEN)✓ Build tamamlandı!$(NC)"
	@echo "$(CYAN)Çalıştırmak için: ./$(TARGET)$(NC)"

banner:
	@echo "$(CYAN)╔═══════════════════════════════════════════╗$(NC)"
	@echo "$(CYAN)║   HyperLayer Protocol - Layer 3 Build    ║$(NC)"
	@echo "$(CYAN)╚═══════════════════════════════════════════╝$(NC)"
	@echo ""

$(TARGET): $(OBJECTS)
	@echo "$(YELLOW)Linking...$(NC)"
	$(CXX) $(LDFLAGS) -o $@ $^
	@echo "$(GREEN)✓ Executable oluşturuldu: $(TARGET)$(NC)"

%.o: %.cpp $(HEADERS)
	@echo "$(BLUE)Compiling $<...$(NC)"
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	@echo "$(RED)Temizleniyor...$(NC)"
	rm -f $(OBJECTS) $(TARGET)
	@echo "$(GREEN)✓ Temizlik tamamlandı$(NC)"

run: all
	@echo ""
	@echo "$(MAGENTA)═══════════════════════════════════════════$(NC)"
	@echo "$(MAGENTA)  HyperLayer Protocol Başlatılıyor...$(NC)"
	@echo "$(MAGENTA)═══════════════════════════════════════════$(NC)"
	@echo ""
	./$(TARGET)

test: all
	@echo "$(CYAN)Running tests...$(NC)"
	./$(TARGET)

help:
	@echo "$(CYAN)HyperLayer Protocol - Build Komutları:$(NC)"
	@echo ""
	@echo "  $(GREEN)make$(NC)          - Projeyi derle"
	@echo "  $(GREEN)make run$(NC)      - Derle ve çalıştır"
	@echo "  $(GREEN)make test$(NC)     - Testleri çalıştır"
	@echo "  $(GREEN)make clean$(NC)    - Temizle"
	@echo "  $(GREEN)make help$(NC)     - Bu yardım mesajını göster"
	@echo ""
	@echo "$(YELLOW)Özellikler:$(NC)"
	@echo "  • Quantum-Ready Cryptography"
	@echo "  • Merkle DAG Structure"
	@echo "  • Adaptive Consensus (3-mode)"
	@echo "  • Fractal Sharding (256 shards)"
	@echo "  • AI-Optimized Routing"
	@echo "  • Cross-Chain Bridge"
	@echo "  • Self-Healing Network"
	@echo ""

# Debug build
debug: CXXFLAGS += -g -DDEBUG
debug: clean all
	@echo "$(YELLOW)Debug build tamamlandı$(NC)"

# Release build with maximum optimization
release: CXXFLAGS += -O3 -march=native -flto
release: clean all
	@echo "$(GREEN)Release build tamamlandı$(NC)"

# Performance profiling build
profile: CXXFLAGS += -pg
profile: LDFLAGS += -pg
profile: clean all
	@echo "$(YELLOW)Profile build tamamlandı$(NC)"

.DEFAULT_GOAL := all
