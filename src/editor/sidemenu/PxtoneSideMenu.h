#ifndef PXTONESIDEMENU_H
#define PXTONESIDEMENU_H

#include <QObject>

#include "SideMenu.h"
#include "editor/PxtoneClient.h"
#include "editor/audio/NotePreview.h"

extern AddWoice make_addWoice_from_path(const QString &path);

class PxtoneSideMenu : public SideMenu {
  Q_OBJECT
  PxtoneClient *m_client;
  EditState m_last_edit_state;
  std::unique_ptr<NotePreview> m_note_preview;

  void handleNewEditState(const EditState &s);
  void refreshWoices();
  void refreshTempoBeat();
  void refreshCopyCheckbox();

 public:
  explicit PxtoneSideMenu(PxtoneClient *client, QWidget *parent = nullptr);
 signals:
};

#endif  // PXTONESIDEMENU_H
