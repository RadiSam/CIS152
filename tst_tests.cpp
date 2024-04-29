#include <QtTest>
#include <binarytree.cpp>
#include <btnodes.cpp>
#include <player.cpp>
#include <plinko.cpp>
#include <report.cpp>
#include <reportnodes.cpp>
#include <roulette.cpp>
#include <store.cpp>

class tests : public QObject
{
    Q_OBJECT

public:
    tests();
    ~tests();

private slots:
    //binarytree tests
    void testCreateTree();
    void testGetRoot();
    void testInsertTree();
    void testIsEmptyTreeTRUE();
    void testIsEmptyTreeFALSE();
    void testInOrderPrint();
    //btnodes tests
    void testCreateBtNode1();
    void testCreateBtNode2();
    void testGetScaleNum();
    void testGetLeft();
    void testGetRight();
    void testSetLeft();
    void testSetRight();
    //player tests
    void testCreatePlayer1();
    void testCreatePlayer2();
    void testCreatePlayer3();
    void testSetPocket();
    void testSetChances();
    void testGetName();
    void testGetPocket();
    void testGetChances();
    void testPrintTitle();
    //void testValidChanceInput(); requires userinput
    //plinko tests
    void testCreatePlinko();
    void testGetResult();
    void testGetTree();
    void testStartPlinko();
    void testMakeCourse();
    void testPrintCourse();
    //report tests
    void testCreateReport();
    void testIsEmptyTRUE();
    void testIsEmptyFALSE();
    void testPeek1();
    void testPeek2();
    void testSize();
    void testGetHead();
    void testInsert();
    void testRemove();
    void testSearch1();
    void testSearch2();
    void testSearchConversion1();
    void testSearchConversion2();
    void testInsertionSort();
    void testPrintList();
    void testPrintEarned();
    void testPrintNodePTR();
    void testPrintNodeOBJ();
    //reportnods tests
    void testCreateReportNode1();
    void testCreateReportNode2();
    void testSetGetRound();
    void testSetGetMoneySpent();
    void testSetGetChancesSpent();
    void testSetGetMoneyEarned();
    void testSetGetPResult();
    void testSetGetRResult();
    void testSetGetNext();
    //roulette tests
    void testCreateRoulette1();
    void testCreateRoulette2();
    void testSetQueue();
    void testGetResult1();
    void testGetResult2();
    void testQueueAvailableTRUE();
    void testQueueAvailableFALSE();
    void testGetWheel();
    //store tests
    void testCreateStore();
    void testSetGetChances();
    void testSetGetBank();
    //void testBuyStuff(); requires user input

};

tests::tests()
{

}

tests::~tests()
{

}

//binarytree tests
void tests::testCreateTree() {
    // ARRANGE
    binarytree myTree;
    btnodes* myNode;
    bool actual = false;
    // ACT
    myNode = myTree.getRoot();
    if (myNode == NULL) {actual = true;}
    // ASSERT
    QVERIFY(actual); // verify true
}
void tests::testGetRoot() {
    // ARRANGE
    binarytree myTree;
    btnodes* actual;
    // ACT
    actual = NULL;
    // ASSERT
    QCOMPARE(actual, myTree.getRoot()); // verify NULL
}
void tests::testInsertTree() {
    // ARRANGE
    binarytree myTree;
    btnodes* myNode = new btnodes(54.5);
    double actual;
    // ACT
    myTree.insert(myNode, 0);
    actual = (myTree.getRoot()->getScaleNum());
    delete myNode;
    // ASSERT
    QCOMPARE(actual, 54.5); // verify same double added in node
}
void tests::testIsEmptyTreeTRUE() {
    // ARRANGE
    binarytree myTree;
    bool actual;
    // ACT
    actual = true;
    // ASSERT
    QCOMPARE(actual, myTree.isEmpty()); // verify true
}
void tests::testIsEmptyTreeFALSE() {
    // ARRANGE
    binarytree myTree;
    btnodes* myNode = new btnodes(10.0);
    bool actual;
    // ACT
    myTree.insert(myNode, 0);
    actual = false;
    delete myNode;
    // ASSERT
    QCOMPARE(actual, myTree.isEmpty()); // verify true
}
void tests::testInOrderPrint() {
    // ARRANGE
    binarytree myTree;
    btnodes* myNode1 = new btnodes(10.0);
    btnodes* myNode2 = new btnodes(15.0);
    btnodes* myNode3 = new btnodes(20.0);
    string actual;
    string result;
    // ACT
    myTree.insert(myNode1, 0);
    myTree.insert(myNode2, 0);
    myTree.insert(myNode3, 0);
    actual = myTree.inorderPrint(myTree.getRoot());
    delete myNode1;
    delete myNode2;
    delete myNode3;
    result = "10.000000 15.000000 20.000000 ";
    // ASSERT
    QCOMPARE(actual, result); // verify same string
}

//btnodes tests
void tests::testCreateBtNode1() {
    // ARRANGE
    btnodes* myNode1 = new btnodes();
    double actual;
    // ACT
    actual = myNode1->getScaleNum();
    delete myNode1;
    // ASSERT
    QCOMPARE(actual, 0.000000); // verify same double of 0
}
void tests::testCreateBtNode2() {
    // ARRANGE
    btnodes* myNode1 = new btnodes(25.0);
    double actual;
    // ACT
    actual = myNode1->getScaleNum();
    delete myNode1;
    // ASSERT
    QCOMPARE(actual, 25.000000); // verify same double of 25
}
void tests::testGetScaleNum() {
    // ARRANGE
    btnodes* myNode1 = new btnodes(25.0);
    double actual;
    // ACT
    actual = myNode1->getScaleNum();
    delete myNode1;
    // ASSERT
    QCOMPARE(actual, 25.000000); // verify same double of 25
}
void tests::testGetLeft() {
    // ARRANGE
    binarytree myTree;
    btnodes* myNode1 = new btnodes(10.0);
    btnodes* myNode2 = new btnodes(5.0);
    btnodes* myNode3;
    double actual;
    // ACT
    myTree.insert(myNode1, 0);
    myTree.insert(myNode2, 0);
    myNode3 = myNode1->getLeft();
    actual = myNode3->getScaleNum();
    delete myNode1;
    delete myNode2;
    // ASSERT
    QCOMPARE(actual, 5.000000); // verify same double from left of root
}
void tests::testGetRight() {
    // ARRANGE
    binarytree myTree;
    btnodes* myNode1 = new btnodes(10.0);
    btnodes* myNode2 = new btnodes(5.0);
    btnodes* myNode3;
    double actual;
    // ACT
    myTree.insert(myNode1, 0);
    myTree.insert(myNode2, 1);
    myNode3 = myNode1->getRight();
    actual = myNode3->getScaleNum();
    delete myNode1;
    delete myNode2;
    // ASSERT
    QCOMPARE(actual, 5.000000); // verify same double from right of root
}
void tests::testSetLeft() {
    // ARRANGE
    btnodes* myNode1 = new btnodes(10.0);
    btnodes* myNode2 = new btnodes(5.0);
    double actual;
    // ACT
    myNode1->setLeft(myNode2);
    actual = myNode1->getLeft()->getScaleNum();
    delete myNode1;
    delete myNode2;
    // ASSERT
    QCOMPARE(actual, 5.000000); // verify same double from left of node
}
void tests::testSetRight() {
    // ARRANGE
    btnodes* myNode1 = new btnodes(10.0);
    btnodes* myNode2 = new btnodes(5.0);
    double actual;
    // ACT
    myNode1->setRight(myNode2);
    actual = myNode1->getRight()->getScaleNum();
    delete myNode1;
    delete myNode2;
    // ASSERT
    QCOMPARE(actual, 5.000000); // verify same double from right of node
}

//player tests
void tests::testCreatePlayer1() {
    // ARRANGE
    Player myPlayer;
    string actual;
    // ACT
    actual = myPlayer.getName();
    // ASSERT
    QCOMPARE(actual, "N/A");// verify N/A string as name
}
void tests::testCreatePlayer2() {
    // ARRANGE
    Player myPlayer("Carl", 50000);
    int actual;
    // ACT
    actual = myPlayer.getPocket();
    // ASSERT
    QCOMPARE(actual, 10000);// verify pocket is 10000
}
void tests::testCreatePlayer3() {
    // ARRANGE
    Player myPlayer("Carl", -500);
    int actual;
    // ACT
    actual = myPlayer.getPocket();
    // ASSERT
    QCOMPARE(actual, 100);// verify pocket is 100
}
void tests::testSetPocket() {
    // ARRANGE
    Player myPlayer("Carl", -500);
    int actual;
    // ACT
    myPlayer.setPocket(500);
    actual = myPlayer.getPocket();
    // ASSERT
    QCOMPARE(actual, 500);// verify pocket is 500
}
void tests::testSetChances() {
    // ARRANGE
    Player myPlayer("Carl", -500);
    int actual;
    // ACT
    myPlayer.setChances(50);
    actual = myPlayer.getChances();
    // ASSERT
    QCOMPARE(actual, 50);// verify chances is 50
}
void tests::testGetName() {
    // ARRANGE
    Player myPlayer("Carl", 50000);
    string actual;
    // ACT
    actual = myPlayer.getName();
    // ASSERT
    QCOMPARE(actual, "Carl");// verify name is Carl
}
void tests::testGetPocket() {
    // ARRANGE
    Player myPlayer("Carl", 50000);
    int actual;
    // ACT
    actual = myPlayer.getPocket();
    // ASSERT
    QCOMPARE(actual, 10000);// verify pocket is 10000
}
void tests::testGetChances() {
    // ARRANGE
    Player myPlayer("Carl", 50000);
    int actual;
    // ACT
    actual = myPlayer.getChances();
    // ASSERT
    QCOMPARE(actual, 0);// verify chances is 0
}
void tests::testPrintTitle() {
    // ARRANGE
    Player myPlayer("Carl", 50000);
    string actual;
    string result;
    // ACT
    result = "Name: Carl\nCurrency held: $10000\nChances held: 0";
    actual = myPlayer.printTitle();
    // ASSERT
    QCOMPARE(actual, result);// verify same string
}

//plinko tests
void tests::testCreatePlinko() {
    // ARRANGE
    Plinko myPlinko;
    binarytree myTree;
    bool result;
    // ACT
    myTree = myPlinko.getTree();
    result = myTree.isEmpty();
    // ASSERT
    QVERIFY(!result);// verify true for non-empty tree
}
void tests::testGetResult() {
    // ARRANGE
    Plinko myPlinko;
    int actual;
    // ACT
    actual = myPlinko.getResult();
    // ASSERT
    QCOMPARE(actual, 0);// verify 0
}
void tests::testGetTree() {
    // ARRANGE
    Plinko myPlinko;
    binarytree myTree;
    bool result;
    // ACT
    myTree = myPlinko.getTree();
    result = myTree.isEmpty();
    // ASSERT
    QVERIFY(!result);// verify true for non-empty tree
}
void tests::testStartPlinko() {
    // ARRANGE
    Plinko myPlinko;
    ReportNodes* myNode = new ReportNodes();
    Player myPlayer("Joe", 100);
    string report = "test";
    bool actual;
    // ACT
    myPlayer.setPocket(myPlinko.startPlinko(myPlayer, myNode));
    report = myNode->getPResult();
    delete myNode;
    if (report != "test") {actual = true;}
    // ASSERT
    QVERIFY(actual);// verify true for change report string
}
void tests::testMakeCourse() {
    // ARRANGE
    Plinko myPlinko;
    binarytree myTree;
    bool result;
    // ACT
    myTree = myPlinko.getTree();
    result = myTree.isEmpty();
    // ASSERT
    QVERIFY(!result);// verify true for non-empty tree
}
void tests::testPrintCourse() {
    // ARRANGE
    Plinko myPlinko;
    string result;
    string actual;
    // ACT
    actual = myPlinko.printCourse();
    result = "0.000000 0.500000 1.000000 1.400000 1.500000 1.600000 1.750000 1.900000 2.000000 2.200000 2.500000 2.600000 ";
    result.append("2.750000 2.900000 3.000000 4.000000 3.000000 2.900000 2.750000 2.600000 2.500000 2.200000 2.000000 ");
    result.append("1.900000 1.750000 1.600000 1.500000 1.400000 1.000000 0.500000 0.000000 ");
    // ASSERT
    QCOMPARE(actual, result);// verify same string
}
//report tests
void tests::testCreateReport() {
    // ARRANGE
    Report myReport;
    int actual;
    // ACT
    actual = myReport.Size();
    // ASSERT
    QCOMPARE(actual, 10);// verify size is set to ten on default
}
void tests::testIsEmptyTRUE() {
    // ARRANGE
    Report myReport;
    bool actual;
    // ACT
    myReport.remove(1);
    myReport.remove(2);
    myReport.remove(3);
    myReport.remove(4);
    myReport.remove(5);
    myReport.remove(6);
    myReport.remove(7);
    myReport.remove(8);
    myReport.remove(9);
    myReport.remove(10);
    actual = myReport.isEmpty();
    // ASSERT
    QVERIFY(actual);// verify empty
}
void tests::testIsEmptyFALSE() {
    // ARRANGE
    Report myReport;
    bool actual;
    // ACT
    actual = myReport.isEmpty();
    // ASSERT
    QVERIFY(!actual);// verify not empty
}
void tests::testPeek1() {
    // ARRANGE
    Report myReport;
    int actual;
    // ACT
    actual = myReport.peek()->getRound();
    // ASSERT
    QCOMPARE(actual, 10);// verify gets head of round 10
}
void tests::testPeek2() {
    // ARRANGE
    Report myReport;
    bool actual = false;
    // ACT
    myReport.remove(1);
    myReport.remove(2);
    myReport.remove(3);
    myReport.remove(4);
    myReport.remove(5);
    myReport.remove(6);
    myReport.remove(7);
    myReport.remove(8);
    myReport.remove(9);
    myReport.remove(10);
    if (myReport.peek() == nullptr) {actual = true;}
    // ASSERT
    QVERIFY(actual);// verify peek returns nullptr
}
void tests::testSize() {
    // ARRANGE
    Report myReport;
    int actual;
    // ACT
    actual = myReport.Size();
    // ASSERT
    QCOMPARE(actual, 10);// verify size is set to ten
}
void tests::testGetHead() {
    // ARRANGE
    Report myReport;
    int actual;
    // ACT
    actual = myReport.getHead()->getRound();
    // ASSERT
    QCOMPARE(actual, 10);// verify round is 10 in head
}
void tests::testInsert() {
    // ARRANGE
    Report myReport;
    ReportNodes* myNode = new ReportNodes(11);
    int actual;
    // ACT
    myReport.insert(myNode);
    actual = myReport.Size();
    delete myNode;
    // ASSERT
    QCOMPARE(actual, 11);// verify size is 11
}
void tests::testRemove() {
    // ARRANGE
    Report myReport;
    int actual;
    // ACT
    myReport.remove(10);
    actual = myReport.Size();
    // ASSERT
    QCOMPARE(actual, 9);// verify size is 9
}
void tests::testSearch1() {
    // ARRANGE
    Report myReport;
    int actual;
    // ACT
    actual = myReport.search(5)->getRound();
    // ASSERT
    QCOMPARE(actual, 5);// verify round 5 was added
}
void tests::testSearch2() {
    // ARRANGE
    Report myReport;
    bool actual = false;
    // ACT
    myReport.remove(5);
    if (myReport.search(5) == nullptr) {actual = true;}
    // ASSERT
    QVERIFY(actual);// verify nullptr returned
}
void tests::testSearchConversion1() {
    // ARRANGE
    Report myReport;
    ReportNodes myNode;
    int actual;
    // ACT
    myNode = myReport.searchConversion(5);
    actual = myNode.getRound();
    // ASSERT
    QCOMPARE(actual, 5);// verify round 5 was added
}
void tests::testSearchConversion2() {
    // ARRANGE
    Report myReport;
    ReportNodes myNode;
    int actual;
    // ACT
    myReport.remove(5);
    myNode = myReport.searchConversion(5);
    actual = myNode.getRound();
    // ASSERT
    QCOMPARE(actual, 0);// verify 0 round from default node
}
void tests::testInsertionSort() {
    // ARRANGE
    Report myReport;
    ReportNodes myNode;
    ReportNodes otherNode;
    ReportNodes notNode;
    vector<ReportNodes> vect;
    string actual = "";
    // ACT
    myNode.setMoneyEarned(1);
    otherNode.setMoneyEarned(2);
    notNode.setMoneyEarned(3);
    vect.push_back(notNode);
    vect.push_back(myNode);
    vect.push_back(otherNode);
    vect = myReport.insertionSort(vect, 3);
    actual.append(to_string(vect.at(0).getMoneyEarned()));
    actual.append(to_string(vect.at(1).getMoneyEarned()));
    actual.append(to_string(vect.at(2).getMoneyEarned()));
    // ASSERT
    QCOMPARE(actual, "123");// verify vect ordered by money earned
}
void tests::testPrintList() {
    // ARRANGE
    Report myReport;
    string actual;
    string result;
    // ACT
    actual = myReport.printList(3);
    result = "\nRound: 1\nChances Spent: 0\nMoney Earned: 0\nMoney Spent: 0";
    result.append("\nRound: 2\nChances Spent: 0\nMoney Earned: 0\nMoney Spent: 0");
    // ASSERT
    QCOMPARE(actual, result);// verify same string
}
void tests::testPrintEarned() {
    // ARRANGE
    Report myReport;
    string actual;
    string result;
    // ACT
    myReport.search(1)->setMoneyEarned(-500);
    myReport.search(2)->setMoneyEarned(-2000);
    actual = myReport.printEarnedLtoH(3);
    result = "\nRound: 2\nChances Spent: 0\nMoney Earned: -2000\nMoney Spent: 0";
    result.append("\nRound: 1\nChances Spent: 0\nMoney Earned: -500\nMoney Spent: 0");
    // ASSERT
    QCOMPARE(actual, result);// verify same string
}
void tests::testPrintNodePTR() {
    // ARRANGE
    Report myReport;
    string actual;
    string result;
    // ACT
    actual = myReport.printNode(myReport.search(1));
    result = "\nRound: 1\nChances Spent: 0\nMoney Earned: 0\nMoney Spent: 0";
    // ASSERT
    QCOMPARE(actual, result);// verify same string
}
void tests::testPrintNodeOBJ() {
    // ARRANGE
    Report myReport;
    string actual;
    string result;
    // ACT
    actual = myReport.printNode(myReport.searchConversion(1));
    result = "\nRound: 1\nChances Spent: 0\nMoney Earned: 0\nMoney Spent: 0";
    // ASSERT
    QCOMPARE(actual, result);// verify same string
}
//reportnods tests
void tests::testCreateReportNode1() {
    // ARRANGE
    ReportNodes myNode;
    int actual;
    // ACT
    actual = myNode.getRound();
    // ASSERT
    QCOMPARE(actual, 0);// verify round default 0
}
void tests::testCreateReportNode2() {
    // ARRANGE
    ReportNodes myNode(50);
    int actual;
    // ACT
    actual = myNode.getRound();
    // ASSERT
    QCOMPARE(actual, 50);// verify round 50
}
void tests::testSetGetRound() {
    // ARRANGE
    ReportNodes myNode;
    int actual;
    // ACT
    myNode.setRound(50);
    actual = myNode.getRound();
    // ASSERT
    QCOMPARE(actual, 50);// verify round 50
}
void tests::testSetGetMoneySpent() {
    // ARRANGE
    ReportNodes myNode;
    int actual;
    // ACT
    myNode.setMoneySpent(50);
    actual = myNode.getMoneySpent();
    // ASSERT
    QCOMPARE(actual, 50);// verify money spent 50
}
void tests::testSetGetChancesSpent() {
    // ARRANGE
    ReportNodes myNode;
    int actual;
    // ACT
    myNode.setChancesSpent(50);
    actual = myNode.getChancesSpent();
    // ASSERT
    QCOMPARE(actual, 50);// verify chances spent 50
}
void tests::testSetGetMoneyEarned() {
    // ARRANGE
    ReportNodes myNode;
    int actual;
    // ACT
    myNode.setMoneyEarned(50);
    actual = myNode.getMoneyEarned();
    // ASSERT
    QCOMPARE(actual, 50);// verify money earned 50
}
void tests::testSetGetPResult() {
    // ARRANGE
    ReportNodes myNode;
    string actual;
    // ACT
    myNode.setPResult("50");
    actual = myNode.getPResult();
    // ASSERT
    QCOMPARE(actual, "50");// verify Plinko result 50
}
void tests::testSetGetRResult() {
    // ARRANGE
    ReportNodes myNode;
    string actual;
    // ACT
    myNode.setRResult("50");
    actual = myNode.getRResult();
    // ASSERT
    QCOMPARE(actual, "50");// verify Roulette result 50
}
void tests::testSetGetNext() {
    // ARRANGE
    ReportNodes* myNode = new ReportNodes(5);
    ReportNodes* otherNode = new ReportNodes(10);
    int actual;
    // ACT
    myNode->setNext(otherNode);
    actual = myNode->getNext()->getRound();
    delete myNode;
    delete otherNode;
    // ASSERT
    QCOMPARE(actual, 10);// verify 10 from mynodes next round
}

//roulette tests
void tests::testCreateRoulette1() {
    // ARRANGE
    Roulette myRoulette;
    int actual;
    // ACT
    actual = myRoulette.getWheel().size();
    // ASSERT
    QCOMPARE(actual, 20);// verify deafult size 20
}
void tests::testCreateRoulette2() {
    // ARRANGE
    Roulette myRoulette(100);
    int actual;
    // ACT
    actual = myRoulette.getWheel().size();
    // ASSERT
    QCOMPARE(actual, 100);// verify size of 100
}
void tests::testSetQueue() {
    // ARRANGE
    Roulette myRoulette;
    int actual;
    // ACT
    myRoulette.setQueue(30);
    actual = myRoulette.getWheel().size();
    // ASSERT
    QCOMPARE(actual, 30);// verify size of 30
}
void tests::testGetResult1() {
    // ARRANGE
    Roulette myRoulette;
    Player myPlayer;
    ReportNodes* myNode = new ReportNodes();
    string actual;
    // ACT
    actual = myRoulette.getResult(0, myPlayer, myNode);
    delete myNode;
    // ASSERT
    QCOMPARE(actual, "Looks like nothing was entered.");// verify same string
}
void tests::testGetResult2() {
    // ARRANGE
    Roulette myRoulette;
    Player myPlayer;
    ReportNodes* myNode = new ReportNodes();
    int result;
    bool actual = false;
    // ACT
    myPlayer.setChances(5);
    myRoulette.getResult(5, myPlayer, myNode);
    result = myPlayer.getPocket();
    if (result != 0) {actual = true;}
    delete myNode;
    // ASSERT
    QVERIFY(actual);// verify player pocket changed
}
void tests::testQueueAvailableTRUE() {
    // ARRANGE
    Roulette myRoulette;
    bool actual = false;
    // ACT
    actual = myRoulette.queueAvailable(10, myRoulette.getWheel());
    // ASSERT
    QVERIFY(actual);// verify available chances in wheel
}
void tests::testQueueAvailableFALSE() {
    // ARRANGE
    Roulette myRoulette;
    bool actual = false;
    // ACT
    actual = myRoulette.queueAvailable(30, myRoulette.getWheel());
    // ASSERT
    QVERIFY(!actual);// verify not enough available chances in wheel
}
void tests::testGetWheel() {
    // ARRANGE
    Roulette myRoulette;
    queue<int> wheel;
    int actual;
    // ACT
    wheel = myRoulette.getWheel();
    actual = wheel.size();
    // ASSERT
    QCOMPARE(actual, 20);// verify size is 20
}

//store tests
void tests::testCreateStore() {
    // ARRANGE
    Store myStore;
    int actual;
    // ACT
    actual = myStore.getBank();
    // ASSERT
    QCOMPARE(actual, 0);// verify bank default 0
}
void tests::testSetGetChances() {
    // ARRANGE
    Store myStore;
    int actual;
    // ACT
    myStore.setChances(500);
    actual = myStore.getChances();
    // ASSERT
    QCOMPARE(actual, 500);// verify chances set to 500
}
void tests::testSetGetBank() {
    // ARRANGE
    Store myStore;
    int actual;
    // ACT
    myStore.setBank(500);
    actual = myStore.getBank();
    // ASSERT
    QCOMPARE(actual, 500);// verify bank set to 500
}

QTEST_APPLESS_MAIN(tests)

#include "tst_tests.moc"
