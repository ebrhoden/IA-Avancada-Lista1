#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <iostream>
#include <cstdlib>

std::string get_computer_configuration() {
    std::string configuration = "";
    FILE* pipe = popen("uname -a", "r");
    if (pipe) {
        char buffer[128];
        while (!feof(pipe)) {
            if (fgets(buffer, 128, pipe) != NULL)
                configuration += buffer;
        }
        pclose(pipe);
    }
    return configuration;
}

int main() {
    std::vector<std::string> algorithms = {"-bfs", "-idfs", "-gbfs", "-astar", "-idastar"};
    std::vector<std::string> puzzle_files = {"8puzzle_instances.txt", "15puzzle_instances.txt"};

    for (const auto& algorithm : algorithms) {
        std::ofstream csv_file;
        csv_file.open(algorithm.substr(1) + ".csv");
        csv_file << "Number of Expanded Nodes,Length of Optimal Solution,Time for Solution,Average Heuristic Value,Initial Heuristic Value,Number of Solved Initial States,Computer Configuration\n";

        int line_counter = 0;

        for (const auto& puzzle_file : puzzle_files) {
            std::ifstream file(puzzle_file);
            std::string line;
            while (std::getline(file, line)) {
                std::stringstream ss;
                ss << "./main " << algorithm << " " << line;
                std::string output = "";
                FILE* pipe = popen(ss.str().c_str(), "r");
                if (pipe) {
                    char buffer[128];
                    while (!feof(pipe)) {
                        if (fgets(buffer, 128, pipe) != NULL)
                            output += buffer;
                    }
                    pclose(pipe);
                }
                // Parse the output and calculate the average heuristic value
                std::stringstream output_ss(output);
                std::string token;
                std::vector<std::string> results;
                double average_heuristic_value = 0.0;
                int heuristic_count = 0;
                while (std::getline(output_ss, token, ',')) {
                    results.push_back(token);
                    if (heuristic_count == 3) {
                        average_heuristic_value += std::stod(token);
                        heuristic_count++;
                    } else if (heuristic_count == 4) {
                        heuristic_count = 0;
                    } else {
                        heuristic_count++;
                    }
                }
                average_heuristic_value /= (results.size() / 6);
                // Write the results to the CSV file
                if (output.empty()) {
                    csv_file << "-,-,-,-,-,-," << get_computer_configuration() << "\n";
                } else {
                    for (const auto& result : results) {
                        csv_file << result << ",";
                    }
                    // Write the average heuristic value to the CSV file
                    csv_file << average_heuristic_value << ",";
                    // Add the computer configuration to the CSV file
                    csv_file << get_computer_configuration() << "\n";
                }
                line_counter++;
            }
        }

        csv_file.close();
    }

    return 0;
}