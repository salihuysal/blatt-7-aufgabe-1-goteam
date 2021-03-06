#include <algorithm>
#include "AvlTree.h"

AvlTree::node::node(const int k,
                    int bF,
                    AvlTree::node *p,
                    AvlTree::node *lS,
                    AvlTree::node *rS) : key(k),
                                         balanceFactor(bF),
                                         predecessor(p),
                                         leftSuccessor(lS),
                                         rightSuccessor(rS) {
}

AvlTree::node::node(const int k,
                    AvlTree::node *p) : key(k),
                                        balanceFactor(0),
                                        predecessor(p),
                                        leftSuccessor(nullptr),
                                        rightSuccessor(nullptr) {
}

AvlTree::node::~node() {
    delete leftSuccessor;
    delete rightSuccessor;
}

AvlTree::~AvlTree() {
    delete root;
}

void AvlTree::add(const int key) {
    if (root == nullptr) {
        root = new node(key, nullptr);
    } else {
        add(key, root);
    }
}

void AvlTree::add(const int key, AvlTree::node *currentNode) {
    if (key < currentNode->key) {
        if (currentNode->leftSuccessor == nullptr) {
            auto toInsert = new node(key, currentNode);
            currentNode->leftSuccessor = toInsert;
            startUpIn(currentNode);
        } else {
            add(key, currentNode->leftSuccessor);
        }
    }

    if (key > currentNode->key) {
        if (currentNode->rightSuccessor == nullptr) {
            auto toInsert = new node(key, currentNode);
            currentNode->rightSuccessor = toInsert;
            startUpIn(currentNode);
        } else {
            add(key, currentNode->rightSuccessor);
        }
    }
}

AvlTree::node *AvlTree::search(const int key) {
    return search(key, root);
}

AvlTree::node *AvlTree::search(const int key, AvlTree::node *currentNode) {
    if (currentNode == nullptr) {
        return nullptr;
    }
    if (key == currentNode->key) {
        return currentNode;
    }
    if (key < currentNode->key) {
        return search(key, currentNode->leftSuccessor);
    }
    if (key > currentNode->key) {
        return search(key, currentNode->rightSuccessor);
    }
    return nullptr;
}

void AvlTree::startUpIn(AvlTree::node *currentNode) {
    if (currentNode->balanceFactor == 0) {
        if (currentNode->leftSuccessor != nullptr) {
            currentNode->balanceFactor = -1;
        }
        if (currentNode->rightSuccessor != nullptr) {
            currentNode->balanceFactor = 1;
        }
        //stop recursion at root
        if (currentNode->predecessor != nullptr) {
            recursiveUpIn(currentNode);
        }
    } else {
        currentNode->balanceFactor = 0;
    }
}

void AvlTree::recursiveUpIn(AvlTree::node *currentNode) {
    if (currentNode->predecessor != nullptr) {
        node *predecessor = currentNode->predecessor;

        //left side
        if (currentNode == predecessor->leftSuccessor) {
            // check if grew
            if (currentNode->balanceFactor != 0) {
                switch (predecessor->balanceFactor) {
                    case -1:
                        if (currentNode->balanceFactor == -1) {
                            rotateRight(currentNode);
                            currentNode->balanceFactor = 0;
                            currentNode->rightSuccessor->balanceFactor = 0;
                        }
                        if (currentNode->balanceFactor == 1) {
                            doublerotateLeftRight(currentNode);
                            currentNode->balanceFactor = 0;
                            currentNode->predecessor->balanceFactor = 0;
                            currentNode->predecessor->rightSuccessor->balanceFactor = 0;
                        }
                        break;
                    case 0:
                        predecessor->balanceFactor = -1;
                        recursiveUpIn(predecessor);
                        break;
                    case 1:
                        predecessor->balanceFactor = 0;
                        break;
                    default:
                        break;
                }
            }
        }

        //right side
        if (currentNode == predecessor->rightSuccessor) {
            // check if grew
            if (currentNode->balanceFactor != 0) {
                switch (predecessor->balanceFactor) {
                    case -1:
                        predecessor->balanceFactor = 0;
                        break;
                    case 0:
                        predecessor->balanceFactor = 1;
                        recursiveUpIn(predecessor);
                        break;
                    case 1:
                        if (currentNode->balanceFactor == 1) {
                            rotateLeft(currentNode);
                            currentNode->balanceFactor = 0;
                            currentNode->leftSuccessor->balanceFactor = 0;
                        }
                        if (currentNode->balanceFactor == -1) {
                            doublerotateRightLeft(currentNode);
                            currentNode->balanceFactor = 0;
                            currentNode->predecessor->balanceFactor = 0;
                            currentNode->predecessor->leftSuccessor->balanceFactor = 0;
                        }
                        break;
                    default:
                        break;
                }
            }
        }
    }
}


void AvlTree::remove(const int value) {
    if (root != nullptr) {
        auto nodeToDelete = search(value);
        if (nodeToDelete != nullptr) {
            // CASE 1: Both successors of the node to delete are leafs
            if (nodeToDelete->leftSuccessor == nullptr && nodeToDelete->rightSuccessor == nullptr) {
                removeNodeWithoutSuccessors(nodeToDelete);
            } else if (nodeToDelete->leftSuccessor != nullptr && nodeToDelete->rightSuccessor != nullptr) {
                removeNodeWithTwoSuccessors(nodeToDelete);
            } else {
                removeNodeWithOneSuccessor(nodeToDelete);
            }
        }
    }
}

void AvlTree::removeNodeWithoutSuccessors(AvlTree::node *nodeToDelete) {
    if(nodeToDelete == root){
        root = nullptr;
        delete nodeToDelete;
    } else {
        startUpOut(nodeToDelete);

        if(nodeToDelete == nodeToDelete->predecessor->leftSuccessor){
            nodeToDelete->predecessor->leftSuccessor = nullptr;
        } else if(nodeToDelete == nodeToDelete->predecessor->rightSuccessor){
            nodeToDelete->predecessor->rightSuccessor = nullptr;
        }

        nodeToDelete->leftSuccessor = nullptr;
        nodeToDelete->rightSuccessor = nullptr;
        nodeToDelete->predecessor = nullptr;
        delete nodeToDelete;
    }
}

void AvlTree::removeNodeWithTwoSuccessors(AvlTree::node *nodeToDelete) {
    node *symSuccessor = findSymSucc(nodeToDelete);

    startUpOut(symSuccessor);
    symSuccessor->balanceFactor = nodeToDelete->balanceFactor;

    //release symSuccessor
    if (symSuccessor == nodeToDelete->rightSuccessor){
        if (symSuccessor->rightSuccessor != nullptr) {
            symSuccessor->predecessor->rightSuccessor = symSuccessor->rightSuccessor;
            symSuccessor->rightSuccessor->predecessor = symSuccessor->predecessor;
        } else {
            symSuccessor->predecessor->rightSuccessor = nullptr;
        }
    }else{
        if (symSuccessor->rightSuccessor != nullptr) {
            symSuccessor->predecessor->leftSuccessor = symSuccessor->rightSuccessor;
            symSuccessor->rightSuccessor->predecessor = symSuccessor->predecessor;
        } else {
            symSuccessor->predecessor->leftSuccessor = nullptr;
        }
    }

    //put symSuccessor in the place of nodeToDelete
    if (nodeToDelete->rightSuccessor != symSuccessor && nodeToDelete->rightSuccessor != nullptr) {
        symSuccessor->rightSuccessor = nodeToDelete->rightSuccessor;
        nodeToDelete->rightSuccessor->predecessor = symSuccessor;
    }

    symSuccessor->leftSuccessor = nodeToDelete->leftSuccessor;
    nodeToDelete->leftSuccessor->predecessor = symSuccessor;

    if (nodeToDelete != root) {
        symSuccessor->predecessor = nodeToDelete->predecessor;
        if (nodeToDelete == nodeToDelete->predecessor->leftSuccessor) {
            nodeToDelete->predecessor->leftSuccessor = symSuccessor;
        } else if (nodeToDelete == nodeToDelete->predecessor->rightSuccessor) {
            nodeToDelete->predecessor->rightSuccessor = symSuccessor;
        }
    } else {
        symSuccessor->predecessor = nullptr;
        root = symSuccessor;
    }

    nodeToDelete->leftSuccessor = nullptr;
    nodeToDelete->rightSuccessor = nullptr;
    nodeToDelete->predecessor = nullptr;
    delete nodeToDelete;
}

void AvlTree::removeNodeWithOneSuccessor(AvlTree::node *nodeToDelete) {
    node *successor = nullptr;
    if (nodeToDelete->leftSuccessor != nullptr) {
        successor = nodeToDelete->leftSuccessor;

    } else if (nodeToDelete->rightSuccessor != nullptr) {
        successor = nodeToDelete->rightSuccessor;
    }
    if (nodeToDelete != root) {
        startUpOut(nodeToDelete);

        node *predecessor = nodeToDelete->predecessor;
        if (successor != nullptr) {
            successor->predecessor = predecessor;

            if (predecessor->leftSuccessor == nodeToDelete) {
                predecessor->leftSuccessor = successor;
            } else if (predecessor->rightSuccessor == nodeToDelete) {
                predecessor->rightSuccessor = successor;
            }
        }
        upOut(predecessor);
    } else {
        if (successor != nullptr) {
            root = successor;
            successor->predecessor = nullptr;
        }
    }

    nodeToDelete->leftSuccessor = nullptr;
    nodeToDelete->rightSuccessor = nullptr;
    nodeToDelete->predecessor = nullptr;
    delete nodeToDelete;
}

void AvlTree::startUpOut(AvlTree::node *currentNode) {
    //currentNode nodeToDelete
    node* predecessor = currentNode->predecessor;
    if (predecessor->leftSuccessor == currentNode){
        switch (predecessor->balanceFactor) {
            case -1:
                predecessor->balanceFactor = 0;
                upOut(predecessor);
                break;
            case 0:
                predecessor->balanceFactor = 1;
                break;
            case 1:
                if(predecessor->rightSuccessor->balanceFactor !=0){
                    if(predecessor->rightSuccessor->balanceFactor == 1){
                        rotateLeft(predecessor->rightSuccessor);
                    } else if(predecessor->rightSuccessor->balanceFactor == -1){
                        doublerotateRightLeft(predecessor->rightSuccessor);
                    }
                    predecessor->predecessor->balanceFactor = 0;
                    predecessor->predecessor->leftSuccessor->balanceFactor = 0;
                    predecessor->predecessor->rightSuccessor->balanceFactor = 0;
                }
                upOut(predecessor->predecessor);
                break;
            default:
                break;
        }
    } else if (predecessor->rightSuccessor == currentNode){
        switch (predecessor->balanceFactor) {
            case -1:
                if(predecessor->leftSuccessor->balanceFactor !=0){
                    if(predecessor->leftSuccessor->balanceFactor == -1){
                        rotateRight(predecessor->leftSuccessor);
                    } else if(predecessor->leftSuccessor->balanceFactor == 1){
                        doublerotateLeftRight(predecessor->leftSuccessor);
                    }
                    predecessor->predecessor->balanceFactor = 0;
                    predecessor->predecessor->leftSuccessor->balanceFactor = 0;
                    predecessor->predecessor->rightSuccessor->balanceFactor = 0;
                }
                upOut(predecessor->predecessor);
                break;
            case 0:
                predecessor->balanceFactor = -1;
                break;
            case 1:
                predecessor->balanceFactor = 0;
                upOut(predecessor);
                break;
            default:
                break;
        }
    }
}

void AvlTree::upOut(AvlTree::node *currentNode) {
    if (currentNode == nullptr) return;
    auto p = currentNode;
    auto father = p->predecessor;
    if (p->balanceFactor == 0 && father != nullptr) {
        if (father->leftSuccessor == p) {
            if (father->balanceFactor == -1) {
                father->balanceFactor = 0;
                upOut(father);
            } else if (father->balanceFactor == 0) {
                father->balanceFactor = 1;
            } else if (father->balanceFactor == +1) {
                auto q = father->rightSuccessor;
                if (q->balanceFactor == 0) {
                    rotateLeft(q);
                    father->balanceFactor = +1;
                    q->balanceFactor = -1;
                } else if (q->balanceFactor == +1) {
                    rotateLeft(q);
                    father->balanceFactor = 0;
                    q->balanceFactor = 0;
                    upOut(q);
                } else if (q->balanceFactor == -1) {
                    auto r = q->leftSuccessor;
                    doublerotateRightLeft(q);
                    father->balanceFactor =0;
                    r->balanceFactor = 0;
                    q->balanceFactor = 0;
                    upOut(r);
                }
            }
        } else if (father->rightSuccessor == p) {
            if (father->balanceFactor == +1) {
                father->balanceFactor = 0;
                upOut(father);
            } else if (father->balanceFactor == 0) {
                father->balanceFactor = -1;
            } else if (father->balanceFactor == -1) {
                auto q = father->leftSuccessor;
                if (q->balanceFactor == 0) {
                    rotateRight(q);
                    father->balanceFactor = -1;
                    q->balanceFactor = +1;
                } else if (q->balanceFactor == -1) {
                    rotateRight(q);
                    father->balanceFactor = 0;
                    q->balanceFactor = 0;
                    upOut(q);
                } else if (q->balanceFactor == +1) {
                    auto r = q->rightSuccessor;
                    doublerotateLeftRight(q);
                    father->balanceFactor =0;
                    r->balanceFactor = 0;
                    q->balanceFactor = 0;
                    upOut(r);
                }
            }
        }
    }
}

AvlTree::node *findSymSucc(AvlTree::node *node) {
    if (node->rightSuccessor != nullptr) {
        auto symSucc = node->rightSuccessor;
        while (symSucc->leftSuccessor != nullptr) {
            symSucc = symSucc->leftSuccessor;
        }
        return symSucc;
    }
    return nullptr;
}

void AvlTree::rotateRight(AvlTree::node *currentNode) {
    node *predecessor = currentNode->predecessor;

    if (predecessor == root) {
        root = currentNode;
        currentNode->predecessor = nullptr;
    } else {
        node *prePredecessor = predecessor->predecessor;

        if (predecessor == prePredecessor->leftSuccessor) {
            prePredecessor->leftSuccessor = currentNode;
            currentNode->predecessor = prePredecessor;
        }
        if (predecessor == prePredecessor->rightSuccessor) {
            prePredecessor->rightSuccessor = currentNode;
            currentNode->predecessor = prePredecessor;
        }
    }

    if (currentNode->rightSuccessor != nullptr) {
        predecessor->leftSuccessor = currentNode->rightSuccessor;
        currentNode->rightSuccessor->predecessor = predecessor;
    } else {
        predecessor->leftSuccessor = nullptr;
    }

    currentNode->rightSuccessor = predecessor;
    predecessor->predecessor = currentNode;

}

void AvlTree::rotateLeft(AvlTree::node *currentNode) {
    node *predecessor = currentNode->predecessor;

    if (predecessor == root) {
        root = currentNode;
        currentNode->predecessor = nullptr;
    } else {
        node *prePredecessor = predecessor->predecessor;

        if (predecessor == prePredecessor->rightSuccessor) {
            prePredecessor->rightSuccessor = currentNode;
            currentNode->predecessor = prePredecessor;
        }
        if (predecessor == prePredecessor->leftSuccessor) {
            prePredecessor->leftSuccessor = currentNode;
            currentNode->predecessor = prePredecessor;
        }
    }

    if (currentNode->leftSuccessor != nullptr) {
        predecessor->rightSuccessor = currentNode->leftSuccessor;
        currentNode->leftSuccessor->predecessor = predecessor;
    } else {
        predecessor->rightSuccessor = nullptr;
    }

    currentNode->leftSuccessor = predecessor;
    predecessor->predecessor = currentNode;

}

void AvlTree::doublerotateLeftRight(AvlTree::node *currentNode) {
    rotateLeft(currentNode->rightSuccessor);
    rotateRight(currentNode->predecessor);
}

void AvlTree::doublerotateRightLeft(AvlTree::node *currentNode) {
    rotateRight(currentNode->leftSuccessor);
    rotateLeft(currentNode->predecessor);
}

