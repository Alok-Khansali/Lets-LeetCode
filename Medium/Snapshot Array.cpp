class SnapshotArray // Code is correct but gives Memory limit error
{
public:
    unordered_map<int, vector<int>> Snap_table;
    vector<int> v;
    int Snapshot;
    SnapshotArray(int length)
    {
        v.resize(length, 0);
        Snapshot = 0;
    }

    void set(int index, int val)
    {
        v[index] = val;
    }

    int snap()
    {
        Snap_table[Snapshot++] = v;
        return Snapshot - 1;
    }

    int get(int index, int snap_id)
    {
        return Snap_table[snap_id][index];
    }
};
// Approach 2