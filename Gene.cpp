#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>

using namespace std;

const int INF = 1e9;
const int ALPHABET_SIZE = 4;

// Mapeamento rápido de DNA para 0-3 para economizar memória na Trie
int char_to_idx(char c) {
    if (c == 'A') return 0;
    if (c == 'C') return 1;
    if (c == 'G') return 2;
    return 3;
}

// Estrutura da Segment Tree (Idêntica à anterior)
struct SegTree {
    int n;
    vector<int> tree;

    SegTree(int n) {
        this->n = n;
        tree.assign(4 * n, INF);
    }

    void update(int node, int start, int end, int idx, int val) {
        if (start == end) {
            tree[node] = min(tree[node], val);
            return;
        }
        int mid = (start + end) / 2;
        if (start <= idx && idx <= mid)
            update(2 * node, start, mid, idx, val);
        else
            update(2 * node + 1, mid + 1, end, idx, val);

        tree[node] = min(tree[2 * node], tree[2 * node + 1]);
    }

    int query(int node, int start, int end, int l, int r) {
        if (r < start || end < l) return INF;
        if (l <= start && end <= r) return tree[node];
        int mid = (start + end) / 2;
        return min(query(2 * node, start, mid, l, r),
                   query(2 * node + 1, mid + 1, end, l, r));
    }
};

// Estrutura do Nó do Aho-Corasick
struct ACNode {
    int next[ALPHABET_SIZE];
    int fail;
    int exit_link;
    int gene_id;
    int gene_len;

    ACNode() {
        fill(next, next + ALPHABET_SIZE, -1);
        fail = -1;
        exit_link = -1;
        gene_id = INF; // Guarda o ID mais relevante se houver duplicatas (o problema diz que são únicos)
        gene_len = 0;
    }
};

struct Query {
    int L, id;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string T;
    if (!(cin >> T)) return 0;
    int n = T.size();

    int G;
    cin >> G;

    vector<ACNode> trie(1); // Nó 0 é a raiz

    // 1. Inserção dos genes na Trie
    for (int g = 1; g <= G; ++g) {
        string gene;
        cin >> gene;
        int u = 0;
        for (char c : gene) {
            int idx = char_to_idx(c);
            if (trie[u].next[idx] == -1) {
                trie[u].next[idx] = trie.size();
                trie.emplace_back();
            }
            u = trie[u].next[idx];
        }
        // Se já existisse um gene aqui, manteríamos o de menor ID (mais relevante)
        trie[u].gene_id = min(trie[u].gene_id, g);
        trie[u].gene_len = gene.size();
    }

    // 2. Construção dos Fail Links e Exit Links (BFS)
    queue<int> q;
    for (int i = 0; i < ALPHABET_SIZE; ++i) {
        if (trie[0].next[i] != -1) {
            trie[trie[0].next[i]].fail = 0;
            q.push(trie[0].next[i]);
        } else {
            trie[0].next[i] = 0;
        }
    }

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        // Configura o Exit Link:
        // Se o fail link do nó atual for um fim de gene, o exit link aponta pra ele.
        // Se não, o exit link do nó atual é o mesmo exit link do seu fail link.
        int f = trie[u].fail;
        if (trie[f].gene_id != INF) {
            trie[u].exit_link = f;
        } else {
            trie[u].exit_link = trie[f].exit_link;
        }

        for (int i = 0; i < ALPHABET_SIZE; ++i) {
            if (trie[u].next[i] != -1) {
                trie[trie[u].next[i]].fail = trie[f].next[i];
                q.push(trie[u].next[i]);
            } else {
                trie[u].next[i] = trie[f].next[i];
            }
        }
    }

    // Leitura das consultas agrupadas pelo final (R)
    int Q_queries;
    cin >> Q_queries;
    vector<vector<Query>> queries(n);
    vector<int> ans(Q_queries);

    for (int i = 0; i < Q_queries; ++i) {
        int L, R;
        cin >> L >> R;
        L--; R--;
        queries[R].push_back({L, i});
    }

    SegTree seg(n);
    int curr_state = 0;

    // 3. Processamento do texto (Sweep Line)
    for (int R = 0; R < n; ++R) {
        curr_state = trie[curr_state].next[char_to_idx(T[R])];

        int temp = curr_state;

        // Coleta todos os genes que terminam em R usando o Exit Link
        while (temp != -1 && temp != 0) {
            if (trie[temp].gene_id != INF) {
                int L_gene = R - trie[temp].gene_len + 1;
                seg.update(1, 0, n - 1, L_gene, trie[temp].gene_id);
            }
            temp = trie[temp].exit_link;
        }

        // Responde as consultas que terminam em R
        for (const auto& q : queries[R]) {
            int best_gene = seg.query(1, 0, n - 1, q.L, R);
            ans[q.id] = (best_gene == INF) ? -1 : best_gene;
        }
    }

    // Saída
    for (int i = 0; i < Q_queries; ++i) {
        cout << ans[i] << "\n";
    }

    return 0;
}