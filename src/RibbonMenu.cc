// RibbonMenu
// Copyright (C) 2018 Citorva
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
//
// You should have received a copy of the GNU Lesser General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

#include <RibbonMenu.hh>

namespace QtRibbon
{

RibbonMenu::RibbonMenu(QWidget *parent) :
	QWidget(parent)
{}

RibbonMenu::RibbonMenu(CustomWindow::CustomWindow *parent) :
	QWidget(parent),
	mUseCustomWindow(true)
{}

RibbonMenu::~RibbonMenu()
{}

int RibbonMenu::addTab(const RibbonTab &tab) const
{
	mTabs.push_back(tab);

}

RibbonTab &RibbonMenu::tab(int tabId) const
{}

bool RibbonMenu::removeTab(int tabId) const
{}

int RibbonMenu::addTabGroup(const RibbonTabGroup *tabGroup)
{}

RibbonTabGroup *RibbonMenu::tabGroup(int tabGroupId) const
{}

bool RibbonMenu::removeTabGroup(int tabGroupId) const
{}

bool RibbonMenu::setQuickBar(const RibbonQuickBar *quickBar) const
{}

RibbonQuickBar *RibbonMenu::quickBar(void) const
{}

bool RibbonMenu::setQuickMenu(const RibbonQuickMenu *quickMenu) const
{}

RibbonQuickMenu *RibbonMenu::quickMenu(void) const
{}

bool RibbonMenu::enableQuickShortcut(void) const
{}

bool RibbonMenu::disableQuickShortcut(void) const
{}

bool RibbonMenu::useQuickShortcut(void) const
{}

void RibbonMenu::setQuickShortcut(const RibbonQuickShortcut *quickShortcut)
{}

RibbonQuickShortcut *RibbonMenu::quickShortcut(void) const
{}

int RibbonMenu::getError(void) const
{}

void RibbonMenu::paintEvent(QPaintEvent *evt)
{}

}