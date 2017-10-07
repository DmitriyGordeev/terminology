#include "WikiPageParser.h"

#include <gq/Document.h>
#include <gq/Node.h>

using namespace std;

std::string WikiPageParser::getArticle()
{
    std::string pageContent =
            "<!DOCTYPE>\n"
            "<html>\n"
                "<head>\n"
                    "<title>"
                        "Тайтл страницы"
                    "</title>\n"
                "</head>\n"
                "<body>\n"
                "</body>\n"
            "</html>";


    CDocument doc;
    doc.parse(pageContent);

    CSelection s = doc.find("title");
    return s.nodeAt(0).text();
}