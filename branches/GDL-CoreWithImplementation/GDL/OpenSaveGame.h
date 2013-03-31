/** \file
 *  Game Develop
 *  2008-2013 Florian Rival (Florian.Rival@gmail.com)
 */

#ifndef OPENSAVEGAME_H
#define OPENSAVEGAME_H

#include "GDL/Game.h"
#include <string>
#include "GDL/tinyxml/tinyxml.h"
#include "GDL/CommonTools.h"
namespace gd { class Instruction; }
namespace gd { class InstructionMetadata;}
class InitialPosition;
class Layer;
namespace gd { class BaseEvent; }
namespace gd {typedef boost::shared_ptr<gd::BaseEvent> BaseEventSPtr;}

using namespace std;

/**
 * \brief Internal class used so as to save and open games files.
 *
 * \deprecated All saving/loading related tasks must now be transfered to SaveToXml/LoadFromXml member functions.
 */
class GD_API OpenSaveGame
{
public:
    #if defined(GD_IDE_ONLY)
    static void OpenEvents( vector < gd::BaseEventSPtr > & list, const TiXmlElement * elem );
    static void OpenConditions(vector < gd::Instruction > & list, const TiXmlElement * elem);
    static void OpenActions(vector < gd::Instruction > & list, const TiXmlElement * elem);

    static void SaveEvents( const vector < gd::BaseEventSPtr > & list, TiXmlElement * events );
    static void SaveConditions(const vector < gd::Instruction > & list, TiXmlElement * elem);
    static void SaveActions(const vector < gd::Instruction > & list, TiXmlElement * elem);

    static void OpenGroupesObjets( vector < gd::ObjectGroup > & list, const TiXmlElement * elem );
    static void SaveGroupesObjets( const vector < gd::ObjectGroup > & list, TiXmlElement * grpsobjets );

    static void SaveObjects( const vector < boost::shared_ptr<Object> > & list, TiXmlElement * objects );
    static void SaveLayers( const vector < Layer > & list, TiXmlElement * layers );

    static void OpenExternalEvents( vector < boost::shared_ptr<ExternalEvents> > & list, const TiXmlElement * elem );
    static void OpenImagesFromGD2010498(Game & game, const TiXmlElement * elem, const TiXmlElement * dossierElem );

    static void SaveExternalEvents( const vector < boost::shared_ptr<ExternalEvents> > & list, TiXmlElement * layers );
    #endif

    static void OpenObjects(vector < boost::shared_ptr<Object> > & objects, const TiXmlElement * elem);
    static void OpenLayers( vector < Layer > & list, const TiXmlElement * elem );
};

#endif // OPENSAVEGAME_H
