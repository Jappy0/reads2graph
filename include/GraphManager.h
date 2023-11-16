#ifndef GRAPH_MANAGER_H
#define GRAPH_MANAGER_H

#include "Utils.h"
#include "LoggingLevels.h"
#include "EdgeConstructor.h"
#include <seqan3/alphabet/nucleotide/dna5.hpp>
#include <map>
#include <vector>
#include <seqan3/core/debug_stream.hpp> // for debug_stream
#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/graph_utility.hpp>
#include <boost/property_map/dynamic_property_map.hpp>
#include <boost/property_map/property_map.hpp>
#include <boost/graph/graphviz.hpp>
#include <boost/lexical_cast.hpp>
#include <boost/graph/graph_traits.hpp>
#include <boost/graph/properties.hpp>
// Define the graph type with properties for vertices and edges
struct VertexProperties {
    std::vector<seqan3::dna5> read;
    uint32_t count;
};

struct EdgeProperties {
    std::vector<seqan3::dna5> read1;
    std::vector<seqan3::dna5> read2;    
    int weight;
};

namespace std {
template <>
struct hash<std::vector<seqan3::dna5>>
{
    std::size_t operator()(const std::vector<seqan3::dna5> & v) const
    {
        // Your custom hash implementation here, for example:
        std::size_t hash_value = 0;
        for (seqan3::dna5 character : v)
        {
            hash_value ^= seqan3::to_rank(character) + 0x9e3779b9 + (hash_value << 6) + (hash_value >> 2);
        }
        return hash_value;
    }
};
}

typedef boost::adjacency_list<boost::vecS, boost::vecS, boost::undirectedS, VertexProperties, EdgeProperties> Graph;
class GraphManager {
public:
    // Constructor
    GraphManager(std::map<std::pair<std::vector<seqan3::dna5>, std::vector<seqan3::dna5>>, int, pair_comparator> edge_lst, std::map<std::vector<seqan3::dna5>, uint32_t> read2count, cmd_arguments args);
    // Destructor
    ~GraphManager();
    void construct_graph();
    void save_graph() const;

private:
    std::map<std::vector<seqan3::dna5>, uint32_t> read2count_;
    std::map<std::pair<std::vector<seqan3::dna5>, std::vector<seqan3::dna5>>, int, pair_comparator> edge_lst_;
    cmd_arguments args;
    std::filesystem::path graph_full_path_; 
    // Create maps to store the mappings
    // std::unordered_map<std::vector<seqan3::dna5>, boost::graph_traits<Graph>::vertex_descriptor> read2vertex;
    // std::unordered_map<boost::graph_traits<Graph>::vertex_descriptor, std::vector<seqan3::dna5>> vertex2read;      
    std::unordered_map<std::vector<seqan3::dna5>, boost::graph_traits<Graph>::vertex_descriptor, std::hash<std::vector<seqan3::dna5>>> read2vertex;
    std::unordered_map<boost::graph_traits<Graph>::vertex_descriptor, std::vector<seqan3::dna5>, std::hash<boost::graph_traits<Graph>::vertex_descriptor>> vertex2read;
    Graph graph;

};

#endif // GRAPH_MANAGER_H