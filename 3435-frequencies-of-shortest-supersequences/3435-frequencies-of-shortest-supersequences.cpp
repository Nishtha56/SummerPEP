
class Solution {
public:
    vector<vector<int>> supersequences(vector<string>& words) {
        int present_mask = 0;
        int self_loop_mask = 0;
        int adj[26] = {0};
        
        // Step 1: Build the graph and identify self-loops (e.g., "aa")
        for (const string& w : words) {
            int u = w[0] - 'a';
            int v = w[1] - 'a';
            present_mask |= (1 << u);
            present_mask |= (1 << v);
            if (u == v) {
                self_loop_mask |= (1 << u);
            } else {
                adj[u] |= (1 << v);
            }
        }
        
        // Step 2: Extract unique characters present in the input
        vector<int> chars;
        for (int i = 0; i < 26; ++i) {
            if (present_mask & (1 << i)) {
                chars.push_back(i);
            }
        }
        
        int n = chars.size();
        int min_s_size = 1e9;
        vector<int> valid_s_masks;
        
        // Step 3: Iterate through all subsets of characters using bitmasks
        int total_subsets = 1 << n;
        for (int mask = 0; mask < total_subsets; ++mask) {
            int s_mask = 0;
            for (int i = 0; i < n; ++i) {
                if (mask & (1 << i)) {
                    s_mask |= (1 << chars[i]);
                }
            }
            
            // A valid duplicated subset MUST contain all characters that have self-loops
            if ((s_mask & self_loop_mask) != self_loop_mask) {
                continue;
            }
            
            // Check if the remaining characters (frequency 1) form a DAG
            int rem_mask = present_mask & ~s_mask;
            int current = rem_mask;
            bool is_dag = true;
            
            // Bitwise Kahn's Algorithm for ultra-fast cycle detection
            while (current > 0) {
                int all_dest = 0;
                int temp = current;
                while (temp > 0) {
                    int i = __builtin_ctz(temp); // Get the lowest set bit index
                    all_dest |= adj[i];
                    temp &= temp - 1;            // Clear the lowest set bit
                }
                
                // Nodes with 0 indegree within the current remaining subgraph
                int indeg_zero = current & ~all_dest;
                if (indeg_zero == 0) {
                    is_dag = false; // Cycle detected
                    break;
                }
                current ^= indeg_zero; // Remove nodes with 0 indegree
            }
            
            // Step 4: Record minimal valid subsets (Feedback Vertex Sets)
            if (is_dag) {
                int size = __builtin_popcount(s_mask);
                if (size < min_s_size) {
                    min_s_size = size;
                    valid_s_masks.clear();
                    valid_s_masks.push_back(s_mask);
                } else if (size == min_s_size) {
                    valid_s_masks.push_back(s_mask);
                }
            }
        }
        
        // Step 5: Construct frequency arrays for the shortest supersequences
        vector<vector<int>> result;
        for (int s_mask : valid_s_masks) {
            vector<int> freq(26, 0);
            for (int i = 0; i < 26; ++i) {
                if (s_mask & (1 << i)) {
                    freq[i] = 2; // Character is duplicated to break cycles
                } else if (present_mask & (1 << i)) {
                    freq[i] = 1; // Character appears exactly once
                }
            }
            result.push_back(freq);
        }
        
        return result;
    }
};