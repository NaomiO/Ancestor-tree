
#include "doctest.h"
#include "FamilyTree.hpp"

using namespace family;
using namespace std;


TEST_CASE("Test for small trees"){
	Tree T1("Naomi");
	T1.addFather("Naomi", "Benjamin") 
	 .addMother("Naomi", "Rivka");
	CHECK(T1.relation("Benjamin") == "father");
	CHECK(T1.relation("Rivka") == "mother");
	CHECK(T1.find("father") == "Benjamin");
	CHECK(T1.find("mother") == "Rivka");
	Tree T2("Shimon");
	T2.addFather("Shimon", "Mickael") 
	 .addMother("Shimon", "Agnes");
	CHECK(T2.relation("Mickael") == "father");
	CHECK(T2.relation("Agnes") == "mother");
	CHECK(T2.find("father") == "Mickael");
	CHECK(T2.find("mother") == "Agnes");
	Tree T3("Sarah");
	T3.addFather("Sarah", "Gilles") 
	 .addMother("Sarah", "Agnes");
	CHECK(T3.relation("Gilles") == "father");
	CHECK(T3.relation("Florence") == "mother");
	CHECK(T3.find("father") == "Gilles");
	CHECK(T3.find("mother") == "Florence");
	Tree T4("Talya");
	T4.addFather("Talya", "Avraham") 
	 .addMother("Talya", "Gila");
	CHECK(T4.relation("Avraham") == "father");
	CHECK(T4.relation("Gila") == "mother");
	CHECK(T4.find("father") == "Avraham");
	CHECK(T4.find("mother") == "Gila");
}


TEST_CASE("Test relation not found"){
    Tree T ("Naomi"); 
	T.addFather("Naomi", "Benjamin") 
	 .addMother("Naomi", "Rivka") 
	 .addFather("Benjamin", "Henry")
	 .addMother("Benjamin", "Jacqueline")
	 .addFather("Henry", "Christophe")
	 .addMother("Henry", "Julia");
	CHECK(T.relation("jonny") == "unrelated");
	CHECK(T.relation("pablo") == "unrelated");
	CHECK(T.relation("mick") == "unrelated");
	CHECK(T.relation("ben") == "unrelated");
	CHECK(T.relation("brad") == "unrelated");
	CHECK(T.relation("penny") == "unrelated");
	CHECK(T.relation("ken") == "unrelated");
	CHECK(T.relation("tom") == "unrelated");
	CHECK(T.relation("erick") == "unrelated");
	CHECK(T.relation("chris") == "unrelated");
	CHECK(T.relation("gavin") == "unrelated");
	CHECK(T.relation("kyle") == "unrelated");
	CHECK(T.relation("troy") == "unrelated");
	CHECK(T.relation("evan") == "unrelated");
	CHECK(T.relation("paris") == "unrelated");
	CHECK(T.relation("Baajemin") == "unrelated");
	CHECK(T.relation("Heeenry") == "unrelated");
	CHECK(T.relation("Juliiiiia") == "unrelated");
	CHECK(T.relation("Christiiii") == "unrelated");
	CHECK(T.relation("Ravaka") == "unrelated");
	CHECK(T.relation("Naooomi") == "unrelated");


} 

TEST_CASE("Test big family"){
    Tree T ("Naomi"); 
	T.addFather("Naomi", "Benjamin") 
	 .addMother("Naomi", "Rivka") 
	 .addFather("Benjamin", "Henry")
	 .addMother("Benjamin", "Jacqueline")
	 .addFather("Rivka", "Nissim")
	 .addMother("Rivka", "Gloria")
	 .addFather("Henry", "Christophe")
	 .addMother("Henry", "Madeleine")
	 .addFather("Christophe", "Jacques")
	 .addMother("Christophe", "Julia");
	 T.display();
	CHECK(T.relation("Benjamin") == "father");
	CHECK(T.relation("Rivka") == "mother");
	CHECK(T.relation("Henry") == "grandfather");
	CHECK(T.relation("Jacqueline") == "grandmother");
	CHECK(T.relation("Nissim") == "grandfather");
	CHECK(T.relation("Gloria") == "grandmother");
	CHECK(T.relation("Christophe") == "great-grandfather");
	CHECK(T.relation("Madeleine") == "great-grandmother");
	CHECK(T.relation("Jacques") == "great-great-grandfather");
	CHECK(T.relation("Julia") == "great-great-grandmother");
    CHECK(T.relation("Naomi") == "me"); 
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
