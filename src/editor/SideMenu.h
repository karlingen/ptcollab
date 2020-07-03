#ifndef SIDEMENU_H
#define SIDEMENU_H

#include <QFileDialog>
#include <QInputDialog>
#include <QStringListModel>
#include <QWidget>

namespace Ui {
class SideMenu;
}

class SideMenu : public QWidget {
  Q_OBJECT

 public:
  explicit SideMenu(QWidget *parent = nullptr);
  void setEditWidgetsEnabled(bool);
  ~SideMenu();

 signals:
  void quantXIndexUpdated(int);
  void quantYIndexUpdated(int);
  void currentUnitChanged(int);
  void playButtonPressed();
  void stopButtonPressed();
  void saveButtonPressed();
  void hostButtonPressed();
  void connectButtonPressed();
  void addUnit(int woice_idx, QString unit_name);
  void removeUnit();
  // TODO: Maybe set up the UI so that you can also give a name
  void addWoice(QString filename);
  void removeWoice(int idx, QString name);
  void changeWoice(int idx, QString name, QString filename);
  void selectWoice(int);
  void candidateWoiceSelected(QString filename);
  void selectedUnitsChanged(QList<qint32> idx);

 public slots:
  void setQuantXIndex(int);
  void setQuantYIndex(int);
  void setUnits(QStringList const &units);
  // void setSelectedUnits(QList<qint32> idx);
  void setCurrentUnit(int);
  void setPlay(bool);
  void setModified(bool);
  void setUserList(QList<std::pair<qint64, QString>> users);
  void setWoiceList(QStringList);

 private:
  Ui::SideMenu *ui;
  QStringListModel *m_users;
  QFileDialog *m_add_woice_dialog;
  QFileDialog *m_change_woice_dialog;
  QInputDialog *m_add_unit_dialog;
};

#endif  // SIDEMENU_H
