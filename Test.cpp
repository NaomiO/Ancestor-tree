
#include "doctest.h"
#include "FamilyTree.hpp"

using namespace family;
using namespace std;


TEST_CASE("Test creation of small input"){
	Tree T1("Yosef");
	T1.addFather("Yosef", "Yaakov") 
	 .addMother("Yosef", "Rachel");
	CHECK(T1.relation("Yaakov") == "father");
	CHECK(T1.relation("Rachel") == "mother");
	CHECK(T1.find("father") == "Yaakov");
	CHECK(T1.find("mother") == "Rachel");
	Tree T2("Beni");
	T2.addFather("Beni", "Jon") 
	 .addMother("Beni", "Bella");
	CHECK(T2.relation("Jon") == "father");
	CHECK(T2.relation("Bella") == "mother");
	CHECK(T2.find("father") == "Jon");
	CHECK(T2.find("mother") == "Bella");
}


TEST_CASE("Test relation not found"){
    Tree T ("Yosef"); 
	T.addFather("Yosef", "Yaakov") 
	 .addMother("Yosef", "Rachel") 
	 .addFather("Yaakov", "Isaac")
	 .addMother("Yaakov", "Rivka")
	 .addFather("Isaac", "Avraham")
	 .addFather("Avraham", "Terah");
	CHECK(T.relation("ab") == "unrelated");
	CHECK(T.relation("ghh") == "unrelated");
	CHECK(T.relation("klll") == "unrelated");
	CHECK(T.relation("tyyy") == "unrelated");
	CHECK(T.relation("ettt") == "unrelated");
	CHECK(T.relation("poooo") == "unrelated");
	CHECK(T.relation("gtyy") == "unrelated");
	CHECK(T.relation("tttt") == "unrelated");
	CHECK(T.relation("eppp") == "unrelated");
	CHECK(T.relation("fggg") == "unrelated");
	CHECK(T.relation("rtyy") == "unrelated");
	CHECK(T.relation("qppp") == "unrelated");
	CHECK(T.relation("ceded") == "unrelated");
	CHECK(T.relation("qqq") == "unrelated");
	CHECK(T.relation("avrasssham") == "unrelated");
	CHECK(T.relation("Te rah") == "unrelated");
	CHECK(T.relation("Noah") == "unrelated");
	CHECK(T.relation("David") == "unrelated");
	CHECK(T.relation("Shlomo") == "unrelated");
	CHECK(T.relation("Yonah") == "unrelated");
	CHECK(T.relation("Yosef123") == "unrelated");
	CHECK(T.relation("1issaac") == "unrelated");
	CHECK(T.relation("avraham") == "unrelated");
	CHECK(T.relation("Tah") == "unrelated");
} 

TEST_CASE("Test simple addition"){
    Tree T ("Yosef"); 
	T.addFather("Yosef", "Yaakov") 
	 .addMother("Yosef", "Rachel") 
	 .addFather("Yaakov", "Isaac")
	 .addMother("Yaakov", "Rivka")
	 .addFather("Isaac", "Avraham")
	 .addFather("Avraham", "Terah");
	 T.display();
	CHECK(T.relation("Yaakov") == "father");
	CHECK(T.relation("Rachel") == "mother");
	CHECK(T.relation("Isaac") == "grandfather");
	CHECK(T.relation("Rivka") == "grandmother");
	CHECK(T.relation("Avraham") == "great-grandfather");
	CHECK(T.relation("Terah") == "great-great-grandfather");
	CHECK(T.relation("Yosef") == "me"); 
}

TEST_CASE("Test ordered removal"){
    Tree T ("Yosef"); 
	T.addFather("Yosef", "Yaakov") 
	 .addMother("Yosef", "Rachel") 
	 .addFather("Yaakov", "Isaac")
	 .addMother("Yaakov", "Rivka")
	 .addFather("Isaac", "Avraham")
	 .addFather("Avraham", "Terah");
	T.remove("Terah");
	T.remove("Avraham");
	T.remove("Rivka");
	T.remove("Isaac");
	T.remove("Rachel");
	T.remove("Yaakov");
	CHECK_THROWS(T.find("Terah")); 
	CHECK_THROWS(T.find("Avraham")); 
	CHECK_THROWS(T.find("Rivka")); 
	CHECK_THROWS(T.find("Rachel")); 
	CHECK_THROWS(T.find("Isaac")); 
	CHECK_THROWS(T.find("Yaakov")); 
}
TEST_CASE("Test addition after removal"){
    Tree T ("Yosef"); 
	T.addFather("Yosef", "Yaakov") 
	 .addMother("Yosef", "Rachel") 
	 .addFather("Yaakov", "Isaac")
	 .addMother("Yaakov", "Rivka")
	 .addFather("Isaac", "Avraham")
	 .addFather("Avraham", "Terah");
	T.remove("Terah");
	T.remove("Avraham");
	T.remove("Rivka");
	T.remove("Isaac");
	T.remove("Rachel");
	T.remove("Yaakov");
	T.addFather("Yosef", "Yaakov") 
	 .addMother("Yosef", "Rachel") 
	 .addFather("Yaakov", "Isaac")
	 .addMother("Yaakov", "Rivka")
	 .addFather("Isaac", "Avraham")
	 .addFather("Avraham", "Terah");
	CHECK(T.relation("Yaakov") == "father");
	CHECK(T.relation("Rachel") == "mother");
	CHECK(T.relation("Isaac") == "grandfather");
	CHECK(T.relation("Rivka") == "grandmother");
	CHECK(T.relation("Avraham") == "great-grandfather");
	CHECK(T.relation("Terah") == "great-great-grandfather");
	CHECK(T.relation("Yosef") == "me"); 
}



TEST_CASE("Test unordered removal"){
    Tree T ("Yosef"); 
	T.addFather("Yosef", "Yaakov") 
	 .addMother("Yosef", "Rachel") 
	 .addFather("Yaakov", "Isaac")
	 .addMother("Yaakov", "Rivka")
	 .addFather("Isaac", "Avraham")
	 .addFather("Avraham", "Terah");
	 T.remove("Yaakov");
	CHECK(T.relation("Yaakov") == "unrelated");
	CHECK(T.relation("Rachel") == "mother");
	CHECK(T.relation("Isaac") == "unrelated");
	CHECK(T.relation("Rivka") == "unrelated");
	CHECK(T.relation("Avraham") == "unrelated");
	CHECK(T.relation("Terah") == "unrelated");
	CHECK(T.relation("Yosef") == "me");
}

/*TEST_CASE("Test duplicates"){
    Tree T ("Yosef"); 
	T.addFather("Yosef", "Yaakov") 
	 .addMother("Yosef", "Rachel") 
	 .addFather("Yaakov", "Yaakov")
	 .addMother("Yaakov", "Rachel");
	CHECK(T.relation("Yaakov") == "father");
	CHECK(T.relation("Rachel") == "mother");
}*/

TEST_CASE("Test unordered removal"){
    Tree T ("Yosef"); 
	T.addFather("Yosef", "Yaakov") 
	 .addMother("Yosef", "Rachel") 
	 .addFather("Rachel", "Patrick")
	 .addMother("Rachel", "Cynthia")
	 .addFather("Yaakov", "Isaac")
	 .addMother("Yaakov", "Rivka")
	 .addFather("Isaac", "Avraham")
	 .addFather("Avraham", "Terah");
	T.remove("Yaakov");
	CHECK(T.relation("Yaakov") == "unrelated");
	CHECK(T.relation("Rachel") == "mother");
	CHECK(T.relation("Isaac") == "unrelated");
	CHECK(T.relation("Patrick") == "grandfather");
	CHECK(T.relation("Cynthia") == "grandmother");
	CHECK(T.relation("Rivka") == "unrelated");
	CHECK(T.relation("Avraham") == "unrelated");
	CHECK(T.relation("Terah") == "unrelated");
	CHECK(T.relation("Yosef") == "me");
	CHECK(T.relation("Yaakov") == "unrelated");
	CHECK(T.relation("Rachel") == "mother");
	CHECK(T.relation("Isaac") == "unrelated");
	CHECK(T.relation("Patrick") == "grandfather");
	CHECK(T.relation("Cynthia") == "grandmother");
	CHECK(T.relation("Rivka") == "unrelated");
	CHECK(T.relation("Avraham") == "unrelated");
	CHECK(T.relation("Terah") == "unrelated");
	CHECK(T.relation("Yosef") == "me");
}

/*TEST_CASE("Test addition after unordered removal"){   ///////////////////////////////////////
    Tree T ("Yosef"); 
	T.addFather("Yosef", "Yaakov") 
	 .addMother("Yosef", "Rachel") 
	 .addFather("Yaakov", "Isaac")
	 .addMother("Yaakov", "Rivka")
	 .addFather("Isaac", "Avraham")
	 .addFather("Avraham", "Terah");
	T.remove("Yaakov");
	T.addFather("Yaakov", "Isaac")
	 .addMother("Yaakov", "Rivka")
	 .addFather("Isaac", "Avraham")
	 .addFather("Avraham", "Terah");
	CHECK(T.relation("Yaakov") == "unrelated");
	CHECK(T.relation("Rachel") == "mother");
	CHECK(T.relation("Isaac") == "unrelated");
	CHECK(T.relation("Rivka") == "unrelated");
	CHECK(T.relation("Avraham") == "unrelated");
	CHECK(T.relation("Terah") == "unrelated");
	CHECK(T.relation("Yosef") == "me");
}*/

TEST_CASE("Test find"){
    Tree T ("Yosef"); 
	T.addFather("Yosef", "Yaakov") 
	 .addMother("Yosef", "Rachel") 
	 .addFather("Yaakov", "Isaac")
	 .addMother("Yaakov", "Rivka")
	 .addFather("Isaac", "Avraham")
	 .addFather("Avraham", "Terah");
	CHECK(T.find("father") == "Yaakov");
	CHECK(T.find("mother") == "Rachel");
	CHECK(T.find("grandfather") == "Isaac");
	CHECK(T.find("grandmother") == "Rivka");
	CHECK(T.find("great-grandfather") == "Avraham");
	CHECK(T.find("great-great-grandfather") == "Terah");
	CHECK(T.find("me") == "Yosef"); 
}
TEST_CASE("Test not found"){
    Tree T ("Yosef"); 
	T.addFather("Yosef", "Yaakov") 
	 .addMother("Yosef", "Rachel") 
	 .addFather("Yaakov", "Isaac")
	 .addMother("Yaakov", "Rivka");
	CHECK_THROWS_AS(T.find("great-grandfather"), const exception&);
	CHECK_THROWS_AS(T.find("great-great-grandfather"), const exception&);
	T.remove("Rachel");
	T.remove("Yaakov");
	CHECK_THROWS_AS(T.find("mother"), const exception&);
	CHECK_THROWS_AS(T.find("father"), const exception&);
}
TEST_CASE("Test find bad input"){
    Tree T ("Yosef"); 
	T.addFather("Yosef", "Yaakov") 
	 .addMother("Yosef", "Rachel") 
	 .addFather("Yaakov", "Isaac")
	 .addMother("Yaakov", "Rivka")
	 .addFather("Isaac", "Avraham")
	 .addFather("Avraham", "Terah");
	CHECK_THROWS_AS(T.find("father1"), const exception&);
	CHECK_THROWS_AS(T.find("mother-2"), const exception&);
	CHECK_THROWS_AS(T.find("grandfather-great"), const exception&);
	CHECK_THROWS_AS(T.find("grand mother"), const exception&);
	CHECK_THROWS_AS(T.find("great grandfather"), const exception&);
	CHECK_THROWS_AS(T.find("mother-great-great-grandfather"), const exception&);
	CHECK_THROWS_AS(T.find("I"), const exception&); 
}


TEST_CASE("Test relation and find being inverse"){
    Tree T ("Yosef"); 
	T.addFather("Yosef", "Yaakov") 
	 .addMother("Yosef", "Rachel") 
	 .addFather("Yaakov", "Isaac")
	 .addMother("Yaakov", "Rivka")
	 .addFather("Isaac", "Avraham")
	 .addFather("Avraham", "Terah");
	CHECK(T.relation(T.find("father")) == "father");
	CHECK(T.relation(T.find("mother")) == "mother");
	CHECK(T.relation(T.find("grandfather")) == "grandfather");
	CHECK(T.relation(T.find("grandmother")) == "grandmother");
	CHECK(T.relation(T.find("great-grandfather")) == "great-grandfather");
	CHECK(T.relation(T.find("great-great-grandfather")) == "great-great-grandfather");
	CHECK(T.find(T.relation("Yosef")) == "Yosef");
	CHECK(T.find(T.relation("Rachel")) == "Rachel");
	CHECK(T.find(T.relation("Yaakov")) == "Yaakov");
	CHECK(T.find(T.relation("Isaac")) == "Isaac");
	CHECK(T.find(T.relation("Avraham")) == "Avraham");
	CHECK(T.find(T.relation("Terah")) == "Terah");
}
