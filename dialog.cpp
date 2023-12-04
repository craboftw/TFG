#include "dialog.h"
#include "./ui_dialog.h"
#include "HTML/ServicioHTML.h"
#include "Servicio/ServicioTrackeable.h"

void setUpIndex(Ui::Dialog *ui,OID id);

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
    setUpIndex(ui,{"IX",1});
    //make textBrowser show an html that is named SH1.html
    ui->textBrowser->setSource(QUrl("index.html"));

}

Dialog::~Dialog()
{
    delete ui;
}


void Dialog::on_VistaObjetos_doubleClicked(const QModelIndex &index)
{

}
QString emojiForOid(OID id);

void setUpIndex(Ui::Dialog *ui,OID id)
{
    ServicioHTML servicioHTML;
    auto vec = servicioHTML.getIndex(id);
    auto indice = ui->treeWidget;
    ServicioTrackeable servicioTrackeable;
    //Creamos un vector de elementos del indice
    std::vector<QTreeWidgetItem *> rama(vec.size());
    //erase front vector
    rama.erase(rama.begin());
    for(auto i:vec){
        //contamos el numero de '.' que contiene su indice. i.indice
        unsigned n = std::count(i.indice.begin(), i.indice.end(), '.');
        QTreeWidgetItem *item;
        if(n==0){
            item = new QTreeWidgetItem(indice);
        }else{
            //we add the item as a child of the n-1 item in rama
            item = new QTreeWidgetItem(rama[n-1]);
        }
        item->setText(0, QString::fromStdString(i.indice));
        item->setText(1, QString::fromStdString(i.titulo));
        rama[n] = item;
        auto hijos = i.elementos;
        for(auto j:hijos){
            QTreeWidgetItem *item2 = new QTreeWidgetItem(item);

            item2->setText(1, emojiForOid(j) + QString::fromStdString(servicioTrackeable.getName(j)));
            item2->setText(2, QString::fromStdString(j.operator std::string()));
        }
    }
}
/*    inline static  std::map<std::string, unsigned> prefijos = {{Stakeholder::getPrefixID(),STAKEHOLDER},
                                                                {RestrictionRequirement::getPrefixID(),RESTRICTION_REQUIREMENT},
                                                                {FunctionalRequirement::getPrefixID(),FUNCTIONAL_REQUIREMENT},
                                                                {NonFunctionalRequirement::getPrefixID(),NON_FUNCTIONAL_REQUIREMENT},
                                                                {ActorUC::getPrefixID(),ACTOR_UC},
                                                                {InformationRequirement::getPrefixID(),INFORMATION_REQUIREMENT},
                                                                {Organization::getPrefixID(),ORGANIZATION},
                                                                {SystemObjective::getPrefixID(),SYSTEM_OBJECTIVE},
                                                                {UserCase::getPrefixID(),USER_CASE},
                                                                {Text::getPrefixID(),TEXT},
                                                                {MatrixTraces::getPrefixID(),MATRIX_TRACES},
                                                                {UserStories::getPrefixID(),USER_STORIES},
                                                                {UserCaseDiagram::getPrefixID(),USER_CASE_DIAGRAM},
                                                                {Persona::getPrefixID(),PERSONA},
                                                                {Interview::getPrefixID(),INTERVIEW},
                                                                {Class::getPrefixID(),CLASS},
                                                                {Asociation::getPrefixID(),ASOCIATION},
                                                                {OID().getPrefix(),NULLTYPE}};*/

QString emojiForOid(OID id)
{
    switch(ServicioHTML::prefijos[id.getPrefix()])
    {
        case STAKEHOLDER:
            return QString::fromUtf8("👤");
        case RESTRICTION_REQUIREMENT:
            return QString::fromUtf8("🔒");
        case FUNCTIONAL_REQUIREMENT:
            return QString::fromUtf8("🛠️");
        case NON_FUNCTIONAL_REQUIREMENT:
            return QString::fromUtf8("⚖️");
        case ACTOR_UC:
            return QString::fromUtf8("🙂");
        case INFORMATION_REQUIREMENT:
            return QString::fromUtf8("📖");
        case ORGANIZATION:
            return QString::fromUtf8("🏢");
        case SYSTEM_OBJECTIVE:
            return QString::fromUtf8("🎯");
        case USER_CASE:
            return QString::fromUtf8("📜");
        case TEXT:
            return QString::fromUtf8("📝");
        case MATRIX_TRACES:
            return QString::fromUtf8("🧮");
        case USER_STORIES:
            return QString::fromUtf8("🗣️");
        case USER_CASE_DIAGRAM:
            return QString::fromUtf8("📊");
        case PERSONA:
            return QString::fromUtf8("🎭");
        case INTERVIEW:
            return QString::fromUtf8("🎤");
        case CLASS:
            return QString::fromUtf8("📦");
        case ASOCIATION:
            return QString::fromUtf8("🤝");
        case NULLTYPE:
            return QString::fromUtf8("🤔");
        default:
            return QString::fromUtf8("🤔");
    }
}


void Dialog::on_treeWidget_itemClicked(QTreeWidgetItem *item, int column)
{
    ui->textBrowser->setSource(QUrl(item->text(2) + ".html"));


}

