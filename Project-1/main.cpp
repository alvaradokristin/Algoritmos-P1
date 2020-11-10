#include <iostream>
#include <chrono>

#include "headers/Timer.h"
#include "headers/List.h"

using namespace headers;
using namespace std;
using namespace System;
using namespace System::Xml;


int main() {
                XmlDocument doc = new XmlDocument();
                doc.Load("C:\\Users\\famil\\Downloads\\archivo.xml");
                foreach (XmlNode node in doc.DocumentElement.ChildNodes)
                {
                    String id = node.Attributes["id"].Value;
                    Console.WriteLine("id: " + id);
                    if (node.HasChildNodes)
                    {
                        for (int i = 0; i < node.ChildNodes.Count; i++)
                        {
                            Console.WriteLine(node.ChildNodes[i].Name + " : " + node.ChildNodes[i].InnerText);
                        }
                    }
                }
                Console.ReadKey();
}

