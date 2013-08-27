/** \file
 *  Game Develop
 *  2008-2013 Florian Rival (Florian.Rival@gmail.com)
 */
#if defined(GD_IDE_ONLY)
#ifndef SCENEEDITORCANVAS_H
#define SCENEEDITORCANVAS_H
#include <boost/shared_ptr.hpp>
#include <SFML/Graphics.hpp>
#include "GDCore/PlatformDefinition/LayoutEditorPreviewer.h"
#include "GDCore/PlatformDefinition/Project.h"
#include "GDCpp/RuntimeScene.h"
#include "GDCpp/RuntimeGame.h"
namespace gd { class InitialInstancesContainer; }
namespace gd { class Project; }
namespace gd { class Layout; }
namespace gd { class InitialInstance; }
namespace gd { class LayoutEditorCanvasOptions; }
namespace gd { class MainFrameWrapper; }
class wxAuiManager;
class DebuggerGUI;
class ProfileDlg;
class RenderDialog;
class InstancesRenderer;

/**
 * \brief The new scene editor canvas
 */
class GD_API CppLayoutPreviewer : public gd::LayoutEditorPreviewer
{
public:
    CppLayoutPreviewer(gd::LayoutEditorCanvas & editor);
    virtual ~CppLayoutPreviewer();

    /**
     * \brief Return a reference to the scene used for preview inside the editor.
     */
    RuntimeScene & GetRuntimeScene() { return previewScene; }

    /**
     * \brief Return a reference to the layout edited
     */
    gd::Layout & GetLayout();

    /**
     * \brief Return a reference to the layout edited
     */
    gd::Project & GetProject();

    /**
     * Can be called by the external window, owned by the editor, so as to notify the editor that
     * the window has been closed.
     */
    void ExternalWindowClosed();

    /**
     * Return a boost::shared_ptr to the profiler owned by the editor. Can be NULL.
     */
    boost::shared_ptr<ProfileDlg> GetProfileDialog() const { return profiler; }

    virtual void SetParentAuiManager(wxAuiManager * parentAuiManager_);

    virtual void CreatePreviewRibbonTools(wxRibbonButtonBar & buttonBar);
    virtual void ConnectPreviewRibbonToolsEvents();

    virtual void OnUpdate();

    virtual bool LaunchPreview();
    virtual void StopPreview();
    virtual void PlayPreview();
    virtual void PausePreview();

    virtual bool IsPaused() { return !playing; }


private:

    virtual void RefreshFromLayout();

    virtual void OnPreviewPlayBtClick( wxCommandEvent & event );
    virtual void OnPreviewPlayWindowBtClick( wxCommandEvent & event );
    virtual void OnPreviewPauseBtClick( wxCommandEvent & event );
    virtual void OnPreviewDebugBtClick( wxCommandEvent & event );
    virtual void OnPreviewProfilerBtClick( wxCommandEvent & event );

    void RefreshFromLayoutSecondPart();

    //Rendering methods. The rendering during preview is done by previewScene.
    void RenderCompilationScreen();

    //Members used during preview or compilation
    RuntimeGame previewGame; ///< Runtime game used during preview.
    RuntimeScene previewScene; ///< Runtime scene used to render or preview the scene.
    static sf::Texture reloadingIconImage;
    static sf::Sprite reloadingIconSprite;
    static sf::Text reloadingText;

    //Editors owned by the previewer
    boost::shared_ptr<RenderDialog> externalPreviewWindow;
    boost::shared_ptr<DebuggerGUI> debugger;
    boost::shared_ptr<ProfileDlg> profiler;

    //Custom ribbons buttons identifiers
    static const long idRibbonRefresh;
    static const long idRibbonPlay;
    static const long idRibbonPlayWin;
    static const long idRibbonPause;
    static const long idRibbonResetGlobalVars;
    static const long idRibbonDebugger;
    static const long idRibbonProfiler;

    gd::LayoutEditorCanvas & editor;
    gd::MainFrameWrapper & mainFrameWrapper;
    wxAuiManager * parentAuiManager;

    //State management
    bool isReloading; ///< Our previewer is a bit special: It sometimes need to wait for a compilation to finish before going into preview mode.
    bool playing;
};

#endif // SCENEEDITORCANVAS_H
#endif