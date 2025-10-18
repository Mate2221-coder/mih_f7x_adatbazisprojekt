#include <gtest/gtest.h>
#include "rclcpp/rclcpp.hpp"
#include "cosinus_signal_package/cosinus_signal_node.hpp"

class TestCosinusSignal : public ::testing::Test {
protected:
    void SetUp() override {
        rclcpp::init(0, nullptr);
        node = std::make_shared<CosinusSignalNode>();
    }

    void TearDown() override {
        rclcpp::shutdown();
    }

    std::shared_ptr<CosinusSignalNode> node;
};

TEST_F(TestCosinusSignal, TestCosineSignalGeneration) {
    double frequency = 1.0; 
    double amplitude = 1.0; 
    double time = 0.0; 

 
    double expected_value = amplitude * cos(2 * M_PI * frequency * time);
    double generated_value = node->generate_cosine_signal(time, frequency, amplitude);

    EXPECT_NEAR(expected_value, generated_value, 1e-5);
}

TEST_F(TestCosinusSignal, TestCosineSignalPublishing) {
   //test feltöltés
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}