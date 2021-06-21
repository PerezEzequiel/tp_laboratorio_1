/** \brief Carga en el programa, los datos de un archivo de texto.
 *
 * \param path char* Ruta del archivo.
 * \param pArrayListEmployee LinkedList* Lista recibida.
 * \return int Retorna 0 si, los punteros recibidos son igual a NULL, de lo contrario retorna 1.
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee);



/** \brief Carga en el programa, los datos de un archivo binario.
 *
 * \param path char* Ruta del archivo.
 * \param pArrayListEmployee LinkedList* Lista recibida.
 * \return int Retorna 0 si, los punteros recibidos son igual a NULL, de lo contrario retorna 1.
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee);




/** \brief Agrega un nuevo empleado en la lista.
 *
 * \param pArrayListEmployee LinkedList* Lista recibida.
 * \return int Retorna 0 si, la lista es igual a NULL, de lo contrario retorna 1.
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee);



/** \brief Edita un empleado de la lista.
 *
 * \param pArrayListEmployee LinkedList* Lista recibida.
 * \return int Retorna 0 si, la lista es igual a NULL, de lo contrario retorna 1.
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee);



/** \brief Elimina un empleado de la lista.
 *
 * \param pArrayListEmployee LinkedList* Lista recibida.
 * \return int Retorna 0 si, la lista es igual a NULL, de lo contrario retorna 1.
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee);




/** \brief Muestra la lista de  empleados.
 *
 * \param pArrayListEmployee LinkedList* Lista recibida.
 * \return int Retorna 0 si, la lista es igual a NULL, de lo contrario retorna 1.
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee);




/** \brief Ordena la lista de  empleados.
 *
 * \param pArrayListEmployee LinkedList* Lista recibida.
 * \return int Retorna 0 si, la lista es igual a NULL, de lo contrario retorna 1.
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee);




/** \brief Guarda la lista(modo texto) en la ruta recibida.
 *
 * \param path char* Ruta recibida.
 * \param pArrayListEmployee LinkedList* Lista recibida.
 * \return int Retorna 0 si, los punteros recibidos son NULL, de lo contrario retorna 1.
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee);



/** \brief Guarda la lista(modo binario) en la ruta recibida.
 *
 * \param path char* Ruta recibida.
 * \param pArrayListEmployee LinkedList* Lista recibida.
 * \return int Retorna 0 si, los punteros recibidos son NULL, de lo contrario retorna 1.
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee);




