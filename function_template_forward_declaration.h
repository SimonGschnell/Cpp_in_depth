#ifndef FUNCTION_TEMPLATE_FORWARD_DECLARATION_H
#define FUNCTION_TEMPLATE_FORWARD_DECLARATION_H

namespace Function_template_forward_declaration {
    namespace TemplateFunctions {
        //? template definitions are exempt from the ONE DEFINITION RULE and their instantiations are implicitly inline
        template <typename T> void printType(T value){
            std::cout << value << std::endl;
        }
    }
}

#endif