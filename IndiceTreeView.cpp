#include "IndiceTreeView.h"
#include <QDragEnterEvent>
#include "HTML/ServicioHTML.h"

void IndiceTreeView::dragEnterEvent(QDragEnterEvent *event)
{
    //format must be 2letters and numbers
    //we have to check if the format is correct
    //we have to check if the format is correct
    event->acceptProposedAction();
}

void IndiceTreeView::dropEvent(QDropEvent *event)
{
    //con mimeData obtenemos el texto que se ha arrastrado
    //para saber donde se ha soltado el texto usamos dropPos
    //para saber que elemento se ha seleccionado usamos currentIndex
    ServicioHTML servicioHTML;
    //obtenemos el texto que se ha arrastrado
    auto texto = event->mimeData();
    //buscamos su nodo en el vec
    //dividimos el texto en dos partes, los dos caracteres y el numero que puede tener de 1 a 3 cifras
    std::string prefijo = texto->text().toStdString().substr(0,2);
    unsigned numero = std::stoi(texto->text().toStdString().substr(2,3));
    auto pos1 = servicioHTML.getIndex(


}

IndiceTreeView::IndiceTreeView(QWidget *parent)
{

}

void IndiceTreeView::mouseDoubleClickEvent(QMouseEvent *event)
{

}
