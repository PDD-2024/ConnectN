#ifndef LANGUAGE
#define LANGUAGE

#include <string>
#include <map>
#include <array>

/**
 * @brief Enum to represent that languages supported in ConnectN.
 * ConnectN supports two languages: English and Spanish
 */
enum Language {
    English,
    Spanish
};

const std::map<Language, std::array<std::string, 2> > CREDITS_CONTENT{
    {English, {std::string("\n\n\nCreated by J&B Development\n\tJoel Markley - Developer\n\tBrooklyn Cooper - Developer\n\nEnter ("), std::string(") to return to menu\n\n")}}, 
    {Spanish, {std::string("\n\n\nCreado por J&B Development\n\tJoel Markley - Desarrollador\n\tBrooklyn Cooper - Desarrolladora\n\nPresiona ("), std::string(") para volver al menú\n\n")}}
};

const std::map<Language, std::array<std::string, 12> > GAME_CONTENT{
    {English, {std::string("\n\n\nEnter the first player's name:\n\n"), std::string("\n\n\nEnter the second player's name:\n\n"), std::string("\n\n\nEnter N (the number of tiles to connect in order to win):\n\n"),
    std::string(" It's "), std::string("'s turn. Enter the number of the column where you would like to play:\n\n"), std::string("\n\n\nThe game ended in a tie. Choose an option:\n\t("), std::string(") Play again\n\t("),
    std::string(") Return to menu\n\t("), std::string(") Exit\n\n"), std::string("\n\n\nThe winner is "), std::string("! Choose an option:\n\t(")}}, 
    {Spanish, {std::string("\n\n\nIntroduce el nombre del primer jugador:\n\n"), std::string("\n\n\nIntroduce el nombre del segundo jugador:\n\n"), std::string("\n\n\nIntroduce N (el número de fichas que se han de conectar para ganar):\n\n"),
    std::string(" Es el turno de "), std::string(". Introduce el número de la columna en la que quieres jugar:\n\n"), std::string("\n\n\nEl juego ha acabado en empate. Elige una opción:\n\t("), std::string(") Jugar de nuevo\n\t("),
    std::string(") Volver al menú\n\t("), std::string(") Salir\n\n"), std::string("\n\n\nEl ganador es "), std::string("! Elije una opción:\n\t(")}}
};

const std::map<Language, std::array<std::string, 5> > GAME_ERRORS{
    {English, {std::string("Error: illegal game state!"), std::string("\n\n\nThat board size is invalid. Please enter a number greater than 1:\n\n"), std::string("That column value is invalid. Please enter a number between 0 and "),
    std::string("That column is full. Please choose another column:\n\n"), std::string("Invalid input. Try again.")}},
    {Spanish, {std::string("Error: Estado de juego ilegal!"), std::string("\n\n\nEl tamaño del tablero no es valido. Introduce un número mayor a 1:\n\n"), std::string("El valor de la columna no es válido. Por favor, introduce un número entre 0 y"),
    std::string("La columna esta completa. Por favor, elige otro número:\n\n"), std::string("Entrada no válida. Prueba de nuevo.")}}
};

const std::map<Language, std::array<std::string, 5> > MENU_CONTENT{
    {English, {std::string("\n\n\nMenu - Choose an option\n\t("), std::string(") Play Game\n\t("), std::string(") Settings\n\t("), std::string(") View Credits\n\t("), std::string(") Exit\n\n")}}, 
    {Spanish, {std::string("\n\n\nMenú - Elige una opción\n\t("), std::string(") Jugar\n\t("), std::string(") Ajustes\n\t("), std::string(") Ver créditos\n\t("), std::string(") Salida\n\n")}}
};

const std::map<Language, std::array<std::string, 4> > SETTINGS_CONTENT{
    {English, {std::string("\n\n\nSettings - Choose an option:\n\t("), std::string(") Change Language (current: "), std::string(") Save Settings and Return to Menu\n\t("), std::string(") Return to Menu\n\n")}}, 
    {Spanish, {std::string("\n\n\nAjustes - Elige una opción:\n\t("), std::string(") Cambiar idioma (actual: "), std::string(") Guardar ajustes y volver al menú\n\t("), std::string(") Volver al menú\n\n")}}
};

#endif 
