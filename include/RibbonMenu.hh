// RibbonMenu
// Copyright (C) 2018 Citorva
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
//
// You should have received a copy of the GNU Lesser General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

#ifndef RIBBONMENU_HH_
#define RIBBONMENU_HH_

#include <CustomWindow.hh>

#include <QWidget>

#include <vector>

class QPaintEvent;

namespace QtRibbon {

class RibbonTab;
class RibbonQuickBar;
class RibbonTabGroup;
class RibbonQuickMenu;
class RibbonQuickShortcut;

class RibbonMenu : public QWidget
{
public:
    RibbonMenu(QWidget *parent);
    RibbonMenu(CustomWindow::CustomWindow *parent);
    virtual ~RibbonMenu();

    int addTab(const RibbonTab &tab) const;
    RibbonTab &tab(int tabId) const;
    bool removeTab(int tabId) const;

    int addTabGroup(const RibbonTabGroup &tabGroup);
    RibbonTabGroup &tabGroup(int tabGroupId) const;
    bool removeTabGroup(int tabGroupId) const;

    bool setQuickBar(const RibbonQuickBar &quickBar) const;
    RibbonQuickBar &quickBar(void) const;

    bool setQuickMenu(const RibbonQuickMenu &quickMenu) const;
    RibbonQuickMenu &quickMenu(void) const;

    bool enableQuickShortcut(void) const;
    bool disableQuickShortcut(void) const;
    bool useQuickShortcut(void) const;
    void setQuickShortcut(const RibbonQuickShortcut &quickShortcut);
    RibbonQuickShortcut &quickShortcut(void) const;

    int getError(void) const;

public slots:
    void tabChanged(int tabId);
    void clipChanged(bool clipped);

protected:
    void paintEvent(QPaintEvent *evt);

private:
    std::vector<RibbonTab> mTabs;
    std::vector<RibbonTabGroup> mTabGroups;
    RibbonQuickBar &mQuickBar;
    RibbonQuickMenu &mQuickMenu;

    int mErrorCode;

    bool mUseCustomWindow;
};

}

#endif // RIBBONMENU_HH_