#!/usr/bin/python3
q = open("A/index.h", "w")
q.write("#include <iostream>\n")
q.write("using namespace std;\n")
q.write("void test() {\n")
q.write("cout << \"index.h works\" << endl;\n")
q.write("}\n")
q.close()
