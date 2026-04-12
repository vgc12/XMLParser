#include <iostream>
#include <cstdlib>
#include <libxml/parser.h>

static void printBookTitle(xmlNodePtr bookNode)
{
    for (xmlNodePtr child = bookNode->children; child != nullptr; child = child->next) {
        if (child->type == XML_ELEMENT_NODE &&
            xmlStrcmp(child->name, BAD_CAST "title") == 0) {
            xmlChar *title = xmlNodeGetContent(child);
            if (title != nullptr) {
                std::cout << title << std::endl;
                xmlFree(title);
            }
            }
    }
}

int main(int argc, char *argv[])
{
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <xml-file>" << std::endl;
        return EXIT_FAILURE;
    }

    xmlDocPtr doc = xmlReadFile(argv[1], nullptr, 0);
    if (doc == nullptr) {
        std::cerr << "Error: could not parse file." << std::endl;
        return EXIT_FAILURE;
    }

    xmlNodePtr root = xmlDocGetRootElement(doc);

    int count = 0;
    for (xmlNodePtr node = root->children; node != nullptr; node = node->next) {
        if (node->type == XML_ELEMENT_NODE &&
            xmlStrcmp(node->name, BAD_CAST "book") == 0) {
            ++count;
            std::cout << count << ". ";
            printBookTitle(node);
            }
    }

    std::cout << "Total: " << count << " book(s)" << std::endl;

    xmlFreeDoc(doc);
    xmlCleanupParser();
    return EXIT_SUCCESS;
}
