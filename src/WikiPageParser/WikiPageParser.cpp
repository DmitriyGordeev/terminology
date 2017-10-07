#include "WikiPageParser.h"

#include <gq/Document.h>
#include <gq/Node.h>

#include <iostream>

using namespace std;

std::string WikiPageParser::gumboExample(const std::string& htmlCode)
{
    CDocument doc;
    doc.parse(htmlCode);

    string result;
    CSelection cs = doc.find("div#content")
            .find("div#bodyContent")
            .find("div#mw-content-text")
            .find("div.mw-parser-output > p");


    if(cs.nodeNum() > 0) {
        CNode node = cs.nodeAt(0);
        result = node.text();

        cs = node.find("a");
        if(cs.nodeNum() > 0) {
            for(size_t i = 0; i < cs.nodeNum(); i++) {
                cout << cs.nodeAt(i).attribute("href") << endl;
            }
        }
    }


    return result;
}