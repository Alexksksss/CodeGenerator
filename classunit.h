#ifndef CLASSUNIT_H
#define CLASSUNIT_H
#include "unit.h"
#include <vector>
class ClassUnit : public Unit
{
    using Fields = std::vector< std::shared_ptr< Unit >>;// Определение типа Fields как вектор указателей на объекты класса Unit
public:
    enum AccessModifier {
        PUBLIC,
        PROTECTED,
        PRIVATE
    };
    static const std::vector<std::string> ACCESS_MODIFIERS; // Статический вектор строк для хранения модификаторов доступа

public:
    explicit ClassUnit( const std::string& name ) : m_name( name ) {
        m_fields.resize( ACCESS_MODIFIERS.size() );// Инициализация вектора полей для каждого модификатора доступа
    }
    // Добавление подузла в класс с указанием флагов доступа
    void add( const std::shared_ptr< Unit >& unit, Flags flags ) {
        int accessModifier = PRIVATE; // По умолчанию устанавливаем приватный доступ
        if( flags < ACCESS_MODIFIERS.size() ) // Проверка корректности флага доступа
            accessModifier = flags;
        m_fields[accessModifier].push_back(unit); // Добавление подузла в соответствующий модификатор доступа
    }
    std::string GetName() const{return m_name;} // Получение имени класса
    Fields GetFields(unsigned int access_m)const{return m_fields[access_m];} // Получение полей класса по модификатору доступа
private:
    std::string m_name;
    std::vector< Fields > m_fields;
};
const std::vector< std::string > ClassUnit::ACCESS_MODIFIERS = { "public",
                                                                 "protected", "private"}; // Инициализация статического вектора модификаторов доступа

#endif // CLASSUNIT_H
