#include "type.h"

Type::Type(ValueType valueType) {
    this->type = valueType;
}

string Type::getTypeInfo() {
    switch(this->type) {
        case VALUE_BOOL:
            return "bool";
        case VALUE_INT:
            return "int";
        case VALUE_CHAR:
            return "char";
        case VALUE_STRING:
            return "string";
        case VALUE_VOID:
            return "void";
        default:
            cerr << "shouldn't reach here, typeinfo";
            assert(0);
    }
    return "?";
}

Type* Type::getType(string typestr){
    if(typestr == "int")
        return TYPE_INT;
    else if(typestr == "char")
        return TYPE_CHAR;
    else if(typestr == "bool")
        return TYPE_BOOL;
    else if(typestr == "string")
        return TYPE_STRING;
    else if(typestr == "void")
        return TYPE_VOID;
    else
    {
            return nullptr;
    }
}