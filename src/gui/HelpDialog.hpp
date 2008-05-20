/*
 * Stellarium
 * Copyright (C) 2007 Matthew Gates
 * 
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
 */

#ifndef _HELPDIALOG_HPP_
#define _HELPDIALOG_HPP_

#include <QString>
#include <QObject>
#include <QMultiMap>
#include <QPair>
#include <QHash>

#include "StelDialog.hpp"

class Ui_helpDialogForm;

class HelpDialog : public StelDialog
{
	Q_OBJECT;
public:
	HelpDialog();

	//! Set a key and description.
	//!
	//! @note @a group and @a description must be in English; this function takes
	//! care of translating them. Of course, they still have to be marked for
	//! translation using the <tt>N_()</tt> macro.
	//!
	//! @param group is the help group.  e.g. "Movement" or "Time & Date"
	//! @param key is the textual representation of a key, e.g. "CTRL + H"
	//! @param description is a short description of what the key does
	void setKey(QString group, QString oldKey, QString newKey, QString description);

	void languageChanged();

protected:
	//! Initialize the dialog widgets and connect the signals/slots
	virtual void createDialogContent();
	
	Ui_helpDialogForm* ui;

private:
	//! Return the header text.
	QString getHeaderText(void);

	//! Return the footer text.
	QString getFooterText(void);

	//! This function concatenates the header, key codes and footer to build
	//! up the help text.
	void updateText(void);

	//! This uses the group key description as the key to the map, and a 
	//! containing the helpGroup and description as the map value.
	//! code and description.
	QMultiMap<QString, QPair<QString, QString> > keyData;

	//! A hash that maps some special keys to translatable strings.
	QHash<QString, QString> specialKeys;
};

#endif /*_HELPDIALOG_HPP_*/

