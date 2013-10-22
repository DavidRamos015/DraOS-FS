#include "utilerias.h"
#include "sectorceroinfo.h"
#include "usuario.h"
#include "datablock.h"
#include "directorio.h"
#include "mapabits.h"

Utilerias::Utilerias()
{
    //InfoDisco=new SectorCeroInfo();

}

int Utilerias::IndiceUsuarioActual=1;//root

int const Utilerias::UsuariosSoportado=16;
int Utilerias::TamanoDisco=10485760;
const char *Utilerias::PathDisco = "F:\\HHDRIVE.bin";


int Utilerias::TamanoSectorCero()
{
    //SectorCeroInfo c;

    return SectorCeroInfo::TamanoEstructura();
}

int Utilerias::TamanoUsuario(){return Usuario::TamanoEstructura();}
int Utilerias::TamanoCluster(){return DataBlock::TamanoEstructura();}
int Utilerias::TamanoMapaBits(){return MapaBits::TamanoEstructura();}
int Utilerias::TamanoDirectorio(){return Directorio::TamanoEstructura();}



void  Utilerias::MostraAlerta(QString mensaje)
{
    QMessageBox m;
    m.setText(QString(mensaje));
    //m.setInformativeText("Información");
    m.setWindowTitle("Información");
    m.exec();
}

QString Utilerias::PadLeft(QString w, int len, char padding)
{
    QString ret=w;
    if(ret.length()<len)
    {
        for(int i=ret.length();i<len;i++)
        {
            ret.append(padding);
        }
    }

    return  ret;
}

void  Utilerias::MostraAlertaStd(string mensaje)
{
    QMessageBox m;
    m.setText(QString::fromStdString(mensaje));
    //m.setInformativeText("Información");
    m.setWindowTitle("Información");
    m.exec();
}

void Utilerias::MostraAlerta(QString mensaje, QString titulo)
{
    QMessageBox m;
    m.setText(QString(mensaje));
    //m.setInformativeText("Información");
    m.setWindowTitle(QString(titulo));
    m.exec();
}

bool Utilerias::Preguntar(QString mensaje)
{
    QMessageBox msgBox;
    msgBox.setText(QString(mensaje));
    msgBox.setWindowTitle("Desea continuar?");
    msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
    msgBox.setDefaultButton(QMessageBox::Yes);
    int ret = msgBox.exec();
    if (ret==QMessageBox::Yes)
        return true;
    else
        return false;
}

string Utilerias::Trim(string w)
{
    string final="";
    for(int i=0;i<w.length();i++)
    {
        if(w[i]!=' ')
            final+=w[i];
    }

    return final;
}

int Utilerias::GetHashNextUserPointer(SectorCeroInfo infoDisco, int CurrentNumber)
{
    if(CurrentNumber<0)
        CurrentNumber=0;

    if (CurrentNumber>=Utilerias::UsuariosSoportado)
        return -1; //no permite mas

    int NextPointer=infoDisco.BloqueInicioUsuarios+(Utilerias::TamanoUsuario()*CurrentNumber);

    if (NextPointer>=infoDisco.BloqueInicioMapaBits)
        return -1; //no permite mas

    return NextPointer;

}

string Utilerias::getFileExtension(string path)
{
    if(path.find_last_of(".") != std::string::npos)
        return path.substr(path.find_last_of(".")+1);

    return "NNN";
}

string Utilerias::getFileName(string path)
{
    if(path.find_last_of("/") != std::string::npos)
    {
        string n=path.substr(path.find_last_of("/")+1);
        string e=Utilerias::getFileExtension(n);
        n=QString("%0").arg(QString::fromStdString(n)).replace(QString(".%0").arg(QString::fromStdString(e)),"").toStdString();
        return n;
    }

    return "";
}

long Utilerias::getFileSize(FILE *file)
{

    long lCurPos, lEndPos;
    lCurPos = ftell(file);
    fseek(file, 0, 2);
    lEndPos = ftell(file);
    fseek(file, lCurPos, 0);
    return lEndPos;
}

long Utilerias::getFileSize(string Path)
{
    FILE *file = NULL;

    char *a=new char[strlen(Path.c_str())];
    strcpy(a,Path.c_str());

    //Verificar si existe y puede abrir
    if ((file = fopen(a, "rw")) == NULL)
    {
        Utilerias::MostraAlertaStd("No se puede abrir el disco.");
        return -1;
    }

    long l=Utilerias::getFileSize(file);

    fclose(file);

    return l;

}
