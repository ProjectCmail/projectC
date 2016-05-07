#include "Adapter.h"

Json::Value AdapterForFile::readData()
{
//    Json::Value aditionalWriter;
//    Json::Value rootReader; // will contains the root value after parsing.
//    Json::Reader reader;
//    Json::StyledStreamWriter writer;


//    rootWriter["encoding"] = "UTF-8";
//    rootWriter["name"] = "Andry";
//    rootWriter["age"] = "21";

//     aditionalWriter["1"] = "task1";
//     aditionalWriter["2"] = "task2";
//     aditionalWriter["3"] = "task3";

//     rootWriter["tasks"] = aditionalWriter;

//     rootWriter.removeMember("tasks");

//     //rootWriter -= aditionalWriter;

//    std::ofstream test1(this->fileName.c_str());
//    writer.write(test1,rootWriter);
//    test1.close();

    Json::Value root = NULL;
    std::ifstream in(this->fileName.c_str(), std::ifstream::binary);

    if(!in.is_open())
        throw "Error, file is not open!";

    try{
        root = parserJson(in);
    }catch(std::string ex)
    {
        in.close();
        throw ex;
    }
    in.close();
    return root;
}


void AdapterForFile::writeData(Json::Value& rootWriter)
{
    std::ofstream out(this->fileName.c_str());
    if(!out.is_open())
        throw "Error, file is not open!";
    try{
        Json::StyledStreamWriter writer;
        writer.write(out,rootWriter);
    }catch(...)
    {
        out.close();
        throw "Error in write file!";
    }

    out.close();
}

Json::Value AdapterForFile::parserJson(std::ifstream& in)
{
    Json::Value root;
    Json::Reader reader;
    bool parsingSuccessful = reader.parse( in, root, false );
    if ( !parsingSuccessful )
    {
        std::cout  << reader.getFormatedErrorMessages()<< "\n";
        throw "Error, file is corrupted!";
    }

    return root;
}
