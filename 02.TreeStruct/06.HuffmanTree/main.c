//
// Created by Galaxy. on 2023/4/22.
//


#include "huffmanTree.h"
#include <stdlib.h>
#include <stdio.h>

void test01() {
    int w[] = {5, 29, 7, 8, 14, 23, 3, 11};
    char show[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'};

    int n = sizeof (w) / sizeof (w[0]);
    // 构建huffmantree
    HuffmanTree tree = createHuffmanTree(w, n);
    // for (int i = 1; i <= 2 * n - 1; i++) {
    //     printf("%d %d %d %d %d\n", i, tree[i].weight, tree[i].parent, tree[i].lChild, tree[i].rChild);
    // }
    HuffmanCode *codes = createHuffmanCode(tree, n);
    for (int i = 0; i < n; i++) {
        printf("%c : %s\n", show[i], codes[i]);
    }
    releaseHuffmanCode(codes, n);
    releaseHuffmanTree(tree);
}


int main() {
    test01();
    return 0;
}
