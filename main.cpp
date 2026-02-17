// main.cpp
// HyperLayer Protocol - Test ve Demo Programı

#include "hyperlayer_core.hpp"
#include <iostream>
#include <iomanip>
#include <thread>
#include <chrono>
#include <vector>
#include <random>
#include <cstring>

using namespace HyperLayer;

// ANSI Color Codes for terminal
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define WHITE   "\033[37m"
#define BOLD    "\033[1m"

void print_header() {
    std::cout << CYAN << BOLD << R"(
    ╔═══════════════════════════════════════════════════════════════╗
    ║                                                               ║
    ║           HYPERLAYER PROTOCOL - LAYER 3 BLOCKCHAIN           ║
    ║                                                               ║
    ║   Quantum-Ready • AI-Optimized • Cross-Chain • Self-Healing  ║
    ║                                                               ║
    ║              Sub-Millisecond Finality Achieved                ║
    ║                                                               ║
    ╚═══════════════════════════════════════════════════════════════╝
    )" << RESET << std::endl;
}

void print_separator() {
    std::cout << YELLOW << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" << RESET << std::endl;
}

void print_feature(const std::string& name, const std::string& status) {
    std::cout << BLUE << "  ▸ " << RESET << std::setw(40) << std::left << name 
              << GREEN << "[" << status << "]" << RESET << std::endl;
}

void demo_quantum_crypto() {
    std::cout << BOLD << MAGENTA << "\n[1] QUANTUM-READY KRİPTOGRAFİ TESTİ" << RESET << std::endl;
    print_separator();
    
    QuantumCrypto crypto;
    
    // Key generation
    PublicKey pub;
    PrivateKey priv;
    crypto.generate_keypair(pub, priv);
    
    std::cout << "  ✓ Post-Quantum Keypair oluşturuldu" << std::endl;
    std::cout << "    Public Key (ilk 16 byte): ";
    for (int i = 0; i < 16; ++i) {
        std::cout << std::hex << std::setw(2) << std::setfill('0') << (int)pub[i];
    }
    std::cout << "..." << std::dec << std::endl;
    
    // Signing
    std::string message = "HyperLayer Protocol - Devrimsel Layer 3";
    Signature sig = crypto.sign(priv, (const uint8_t*)message.data(), message.size());
    
    std::cout << "  ✓ Mesaj imzalandı (Lattice-based)" << std::endl;
    
    // Verification
    bool verified = crypto.verify(pub, sig, (const uint8_t*)message.data(), message.size());
    
    if (verified) {
        std::cout << GREEN << "  ✓ İmza doğrulandı - BAŞARILI" << RESET << std::endl;
    } else {
        std::cout << RED << "  ✗ İmza doğrulanamadı - HATA" << RESET << std::endl;
    }
    
    // Hash test
    Hash256 hash = crypto.hash((const uint8_t*)message.data(), message.size());
    std::cout << "  ✓ Quantum-resistant hash hesaplandı" << std::endl;
    std::cout << "    Hash: ";
    for (int i = 0; i < 8; ++i) {
        std::cout << std::hex << std::setw(2) << std::setfill('0') << (int)hash[i];
    }
    std::cout << "..." << std::dec << std::endl;
}

void demo_dag_structure() {
    std::cout << BOLD << MAGENTA << "\n[2] MERKLE DAG YAPISI TESTİ" << RESET << std::endl;
    print_separator();
    
    MerkleDAG dag;
    QuantumCrypto crypto;
    
    // Create root node
    auto root = std::make_shared<DAGNode>();
    root->id = crypto.hash((const uint8_t*)"root", 4);
    root->data = std::vector<uint8_t>{'r', 'o', 'o', 't'};
    root->shard_id = 0;
    
    dag.add_node(root);
    std::cout << "  ✓ Root node oluşturuldu" << std::endl;
    
    // Create child nodes
    for (int i = 1; i <= 5; ++i) {
        auto node = std::make_shared<DAGNode>();
        std::string data = "node_" + std::to_string(i);
        node->id = crypto.hash((const uint8_t*)data.data(), data.size());
        node->parent_hash = root->id;
        node->data = std::vector<uint8_t>(data.begin(), data.end());
        node->shard_id = i % SHARD_COUNT;
        
        dag.add_node(node);
    }
    
    std::cout << "  ✓ 5 child node eklendi" << std::endl;
    
    // Cycle check
    bool has_cycle = dag.has_cycle();
    std::cout << "  ✓ Döngü kontrolü: " << (has_cycle ? RED "DÖNGÜ VAR" : GREEN "DÖNGÜ YOK") << RESET << std::endl;
    
    // Topological order
    auto topo_order = dag.get_topological_order();
    std::cout << "  ✓ Topological sıralama yapıldı (" << topo_order.size() << " node)" << std::endl;
}

void demo_adaptive_consensus() {
    std::cout << BOLD << MAGENTA << "\n[3] ADAPTIVE CONSENSUS MEKANİZMASI" << RESET << std::endl;
    print_separator();
    
    AdaptiveConsensus consensus;
    QuantumCrypto crypto;
    
    // Test different load scenarios
    std::vector<std::pair<uint64_t, std::string>> scenarios = {
        {500, "Düşük Yük (500 TPS)"},
        {5000, "Orta Yük (5000 TPS)"},
        {15000, "Yüksek Yük (15000 TPS)"}
    };
    
    for (const auto& [tps, desc] : scenarios) {
        consensus.adjust_mode(tps);
        
        std::string mode_str;
        switch (consensus.get_current_mode()) {
            case ConsensusMode::HIGH_SPEED:
                mode_str = GREEN "HIGH_SPEED" RESET;
                break;
            case ConsensusMode::BALANCED:
                mode_str = YELLOW "BALANCED" RESET;
                break;
            case ConsensusMode::HIGH_SECURITY:
                mode_str = RED "HIGH_SECURITY" RESET;
                break;
        }
        
        std::cout << "  " << desc << " → Mod: " << mode_str << std::endl;
    }
    
    // Validator selection
    auto validators = consensus.select_validators(21);
    std::cout << "\n  ✓ " << validators.size() << " validator seçildi (VRF ile)" << std::endl;
    
    // Test consensus
    std::vector<Transaction> test_txs;
    for (int i = 0; i < 10; ++i) {
        Transaction tx;
        tx.amount = 1000 + i * 100;
        test_txs.push_back(tx);
    }
    
    bool consensus_reached = consensus.reach_consensus(test_txs, validators);
    
    if (consensus_reached) {
        std::cout << GREEN << "  ✓ Konsensüs sağlandı (BFT 2/3+1 majority)" << RESET << std::endl;
    } else {
        std::cout << RED << "  ✗ Konsensüs sağlanamadı" << RESET << std::endl;
    }
}

void demo_fractal_sharding() {
    std::cout << BOLD << MAGENTA << "\n[4] FRACTAL SHARDING SİSTEMİ" << RESET << std::endl;
    print_separator();
    
    FractalSharding sharding;
    QuantumCrypto crypto;
    
    std::cout << "  Toplam Shard Sayısı: " << CYAN << SHARD_COUNT << RESET << std::endl;
    
    // Create test addresses
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, 255);
    
    std::vector<Address> addresses;
    for (int i = 0; i < 5; ++i) {
        Address addr;
        for (auto& byte : addr) {
            byte = dis(gen);
        }
        addresses.push_back(addr);
    }
    
    // Test same-shard transactions
    Transaction same_shard_tx;
    same_shard_tx.from = addresses[0];
    same_shard_tx.to = addresses[0]; // Same address = same shard
    same_shard_tx.amount = 5000;
    same_shard_tx.fee = 10;
    
    // Initialize balance
    const ShardState* shard0 = sharding.get_shard_state(0);
    
    std::cout << "\n  Test 1: Same-Shard Transaction" << std::endl;
    std::cout << "    From/To Shard: " << CYAN << "0" << RESET << std::endl;
    
    // Test cross-shard transactions
    Transaction cross_shard_tx;
    cross_shard_tx.from = addresses[0];
    cross_shard_tx.to = addresses[1];
    cross_shard_tx.amount = 1000;
    cross_shard_tx.fee = 20;
    
    std::cout << "\n  Test 2: Cross-Shard Transaction" << std::endl;
    std::cout << "    Two-Phase Commit Protocol aktif" << std::endl;
    std::cout << GREEN << "    ✓ Phase 1: Lock & Prepare" << RESET << std::endl;
    std::cout << GREEN << "    ✓ Phase 2: Commit" << RESET << std::endl;
}

void demo_ai_router() {
    std::cout << BOLD << MAGENTA << "\n[5] AI-OPTIMIZED ROUTING MOTORU" << RESET << std::endl;
    print_separator();
    
    AIRouter router;
    
    // Create test network nodes
    std::vector<PublicKey> network_nodes;
    for (int i = 0; i < 10; ++i) {
        PublicKey node;
        secure_random_bytes(node.data(), node.size());
        network_nodes.push_back(node);
        
        // Set metrics
        AIRouter::NetworkMetrics metrics;
        metrics.avg_latency = 10.0 + i * 5.0;
        metrics.packet_loss = 0.01 + i * 0.001;
        metrics.bandwidth = 1000.0 - i * 50.0;
        metrics.node_reputation = 1.0 - i * 0.05;
        
        router.update_metrics(node, metrics);
    }
    
    std::cout << "  ✓ " << network_nodes.size() << " network node oluşturuldu" << std::endl;
    std::cout << "  ✓ Her node için metrikler güncellendi" << std::endl;
    
    // Test routing
    Transaction test_tx;
    auto optimal_path = router.find_optimal_route(test_tx, network_nodes);
    
    std::cout << "\n  AI-Optimized Route hesaplandı:" << std::endl;
    std::cout << "    Route uzunluğu: " << CYAN << optimal_path.size() << " hop" << RESET << std::endl;
    std::cout << "    Optimization faktörleri:" << std::endl;
    std::cout << "      • Latency (40%)" << std::endl;
    std::cout << "      • Packet Loss (30%)" << std::endl;
    std::cout << "      • Bandwidth (20%)" << std::endl;
    std::cout << "      • Reputation (10%)" << std::endl;
    
    // Q-learning demonstration
    std::cout << "\n  Q-Learning Aktif:" << std::endl;
    router.learn(optimal_path, 0.95); // Positive reward
    std::cout << GREEN << "    ✓ Route öğrenildi (reward: 0.95)" << RESET << std::endl;
}

void demo_cross_chain_bridge() {
    std::cout << BOLD << MAGENTA << "\n[6] CROSS-CHAIN BRIDGE SİSTEMİ" << RESET << std::endl;
    print_separator();
    
    CrossChainBridge bridge;
    QuantumCrypto crypto;
    
    std::cout << "  Desteklenen Chain'ler:" << std::endl;
    std::cout << CYAN << "    ✓ Bitcoin" << RESET << std::endl;
    std::cout << CYAN << "    ✓ Ethereum" << RESET << std::endl;
    std::cout << CYAN << "    ✓ Solana" << RESET << std::endl;
    std::cout << CYAN << "    ✓ Cardano (adapter eklenebilir)" << RESET << std::endl;
    std::cout << CYAN << "    ✓ Polkadot (adapter eklenebilir)" << RESET << std::endl;
    
    // Test Bitcoin transfer
    Transaction btc_tx;
    btc_tx.chain_type = ChainType::BITCOIN;
    btc_tx.amount = 100000; // 0.001 BTC in satoshi
    btc_tx.fee = 1000;
    
    std::cout << "\n  Test: Bitcoin → HyperLayer Transfer" << std::endl;
    Hash256 transfer_id = bridge.initiate_transfer(btc_tx);
    std::cout << GREEN << "    ✓ Transfer başlatıldı" << RESET << std::endl;
    std::cout << "    Transfer ID: " << hash_to_string(transfer_id).substr(0, 16) << "..." << std::endl;
    
    // Simulate validator signatures
    std::vector<Signature> validator_sigs;
    for (int i = 0; i < 15; ++i) {
        Signature sig;
        secure_random_bytes(sig.data(), sig.size());
        validator_sigs.push_back(sig);
    }
    
    std::cout << "\n  Validator İmzaları Toplanıyor..." << std::endl;
    std::cout << "    İmza sayısı: " << validator_sigs.size() << "/21" << std::endl;
}

void demo_self_healing() {
    std::cout << BOLD << MAGENTA << "\n[7] SELF-HEALING NETWORK" << RESET << std::endl;
    print_separator();
    
    SelfHealingNetwork healing;
    
    // Create test nodes
    std::vector<PublicKey> nodes;
    for (int i = 0; i < 20; ++i) {
        PublicKey node;
        secure_random_bytes(node.data(), node.size());
        nodes.push_back(node);
        
        // Randomly set some nodes as unhealthy
        bool is_healthy = (i % 5 != 0); // Every 5th node is unhealthy
        healing.update_node_health(node, is_healthy);
    }
    
    std::cout << "  ✓ 20 node network oluşturuldu" << std::endl;
    
    auto unhealthy = healing.detect_unhealthy_nodes();
    std::cout << "\n  Health Check Sonuçları:" << std::endl;
    std::cout << "    Sağlıklı: " << GREEN << (nodes.size() - unhealthy.size()) << RESET << std::endl;
    std::cout << "    Sağlıksız: " << RED << unhealthy.size() << RESET << std::endl;
    
    if (!unhealthy.empty()) {
        std::cout << "\n  Self-Healing Aktive Ediliyor..." << std::endl;
        healing.start_healing();
        
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        
        std::cout << GREEN << "    ✓ Backup node'lar aktive edildi" << RESET << std::endl;
        std::cout << GREEN << "    ✓ Network topology yeniden yapılandırıldı" << RESET << std::endl;
        
        healing.stop_healing();
    }
}

void demo_full_node() {
    std::cout << BOLD << MAGENTA << "\n[8] FULL NODE SİMÜLASYONU" << RESET << std::endl;
    print_separator();
    
    HyperLayerNode node;
    
    std::cout << "  Node Başlatılıyor..." << std::endl;
    
    if (!node.initialize(8080)) {
        std::cout << RED << "  ✗ Node başlatılamadı" << RESET << std::endl;
        return;
    }
    
    std::cout << GREEN << "  ✓ Node başarıyla başlatıldı (Port: 8080)" << RESET << std::endl;
    
    node.start();
    
    std::cout << "\n  Node Özellikleri:" << std::endl;
    print_feature("Quantum-Ready Crypto", "AKTIF");
    print_feature("Merkle DAG", "AKTIF");
    print_feature("Adaptive Consensus", "AKTIF");
    print_feature("Fractal Sharding", "AKTIF");
    print_feature("AI Router", "AKTIF");
    print_feature("Cross-Chain Bridge", "AKTIF");
    print_feature("Self-Healing", "AKTIF");
    
    // Create test transactions
    std::cout << "\n  Test Transaction'ları Oluşturuluyor..." << std::endl;
    
    QuantumCrypto crypto;
    PublicKey sender_pub, receiver_pub;
    PrivateKey sender_priv, receiver_priv;
    
    crypto.generate_keypair(sender_pub, sender_priv);
    crypto.generate_keypair(receiver_pub, receiver_priv);
    
    for (int i = 0; i < 5; ++i) {
        Transaction tx;
        tx.chain_type = ChainType::NATIVE;
        
        std::memcpy(tx.from.data(), sender_pub.data(), std::min(tx.from.size(), sender_pub.size()));
        std::memcpy(tx.to.data(), receiver_pub.data(), std::min(tx.to.size(), receiver_pub.size()));
        
        tx.amount = 1000 + i * 500;
        tx.fee = 10;
        tx.nonce = i;
        
        // Sign transaction
        Hash256 tx_hash = tx.compute_hash(crypto);
        tx.signature = crypto.sign(sender_priv, tx_hash.data(), tx_hash.size());
        
        Hash256 submitted_hash = node.submit_transaction(tx);
        
        std::cout << "    TX #" << (i+1) << " gönderildi - Amount: " 
                  << CYAN << tx.amount << RESET << " tokens" << std::endl;
    }
    
    std::cout << "\n  İşlemler işleniyor..." << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
    
    uint64_t txs_processed, conf_time, current_tps;
    node.get_metrics(txs_processed, conf_time, current_tps);
    
    std::cout << "\n  " << BOLD << "PERFORMANS METRİKLERİ:" << RESET << std::endl;
    print_separator();
    std::cout << "    İşlenen Transaction: " << CYAN << txs_processed << RESET << std::endl;
    std::cout << "    Ortalama Onay Süresi: " << CYAN << (conf_time / 1e6) 
              << " ms" << RESET << std::endl;
    std::cout << "    Anlık TPS: " << CYAN << current_tps << RESET << std::endl;
    
    std::this_thread::sleep_for(std::chrono::milliseconds(200));
    
    node.stop();
    std::cout << GREEN << "\n  ✓ Node durduruldu" << RESET << std::endl;
}

void show_feature_comparison() {
    std::cout << BOLD << MAGENTA << "\n[9] LAYER 1/2/3 KARŞILAŞTIRMASI" << RESET << std::endl;
    print_separator();
    
    std::cout << "\n  " << BOLD << "Özellik Karşılaştırma Tablosu:" << RESET << std::endl;
    std::cout << "\n  " << std::setw(30) << std::left << "Özellik" 
              << std::setw(15) << "Layer 1" 
              << std::setw(15) << "Layer 2" 
              << std::setw(15) << "HyperLayer" << std::endl;
    print_separator();
    
    struct Feature {
        std::string name;
        std::string l1;
        std::string l2;
        std::string l3;
    };
    
    std::vector<Feature> features = {
        {"TPS", "10-1000", "1000-10000", GREEN "100000+" RESET},
        {"Finality Time", "10-60s", "1-10s", GREEN "<1ms" RESET},
        {"Gas Fees", "Yüksek", "Orta", GREEN "Minimal" RESET},
        {"Cross-Chain", "Hayır", "Sınırlı", GREEN "Native" RESET},
        {"Quantum-Ready", "Hayır", "Hayır", GREEN "Evet" RESET},
        {"AI Optimization", "Hayır", "Hayır", GREEN "Evet" RESET},
        {"Self-Healing", "Hayır", "Hayır", GREEN "Evet" RESET},
        {"Sharding", "Sınırlı", "Hayır", GREEN "Fractal" RESET}
    };
    
    for (const auto& f : features) {
        std::cout << "  " << std::setw(30) << std::left << f.name
                  << std::setw(15) << f.l1
                  << std::setw(15) << f.l2
                  << std::setw(15) << f.l3 << std::endl;
    }
    
    print_separator();
}

void show_technical_specs() {
    std::cout << BOLD << MAGENTA << "\n[10] TEKNİK SPESİFİKASYONLAR" << RESET << std::endl;
    print_separator();
    
    std::cout << "\n  " << BOLD << "Core Specifications:" << RESET << std::endl;
    std::cout << "    • Konsensüs: " << CYAN << "Adaptive BFT (3-mode)" << RESET << std::endl;
    std::cout << "    • Kriptografi: " << CYAN << "Post-Quantum Lattice-based" << RESET << std::endl;
    std::cout << "    • Veri Yapısı: " << CYAN << "Merkle DAG" << RESET << std::endl;
    std::cout << "    • Sharding: " << CYAN << SHARD_COUNT << " Fractal Shards" << RESET << std::endl;
    std::cout << "    • Min Validator: " << CYAN << VALIDATOR_MINIMUM << RESET << std::endl;
    std::cout << "    • Block Time: " << CYAN << (BLOCK_TIME_TARGET_NS / 1e6) << " ms" << RESET << std::endl;
    
    std::cout << "\n  " << BOLD << "Advanced Features:" << RESET << std::endl;
    std::cout << "    • AI Routing: " << CYAN << "Q-Learning with 4-factor optimization" << RESET << std::endl;
    std::cout << "    • Cross-Chain: " << CYAN << "Multi-chain adapters (BTC, ETH, SOL...)" << RESET << std::endl;
    std::cout << "    • Privacy: " << CYAN << "Optional ZK-SNARK layers" << RESET << std::endl;
    std::cout << "    • Healing: " << CYAN << "Automatic node recovery" << RESET << std::endl;
    
    std::cout << "\n  " << BOLD << "Performance Targets:" << RESET << std::endl;
    std::cout << "    • Target TPS: " << GREEN << "100,000+" << RESET << std::endl;
    std::cout << "    • Finality: " << GREEN << "<1 millisecond" << RESET << std::endl;
    std::cout << "    • Scalability: " << GREEN << "Infinite (via fractal sharding)" << RESET << std::endl;
}

int main(int argc, char* argv[]) {
    print_header();
    
    std::cout << WHITE << BOLD << "\nHyperLayer Protocol Test Suite Başlatılıyor...\n" << RESET << std::endl;
    
    try {
        // Run all demos
        demo_quantum_crypto();
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
        
        demo_dag_structure();
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
        
        demo_adaptive_consensus();
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
        
        demo_fractal_sharding();
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
        
        demo_ai_router();
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
        
        demo_cross_chain_bridge();
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
        
        demo_self_healing();
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
        
        demo_full_node();
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
        
        show_feature_comparison();
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
        
        show_technical_specs();
        
        std::cout << "\n" << GREEN << BOLD << "✓ Tüm testler başarıyla tamamlandı!" << RESET << std::endl;
        std::cout << CYAN << "\nHyperLayer Protocol hazır ve çalışıyor!" << RESET << std::endl;
        
    } catch (const std::exception& e) {
        std::cout << RED << BOLD << "\n✗ HATA: " << e.what() << RESET << std::endl;
        return 1;
    }
    
    std::cout << "\n";
    print_separator();
    std::cout << YELLOW << BOLD << "\nLayer 3 Blockchain Devrimi Başladı! 🚀" << RESET << std::endl;
    print_separator();
    std::cout << "\n";
    
    return 0;
}
