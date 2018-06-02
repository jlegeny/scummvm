/* ScummVM - Graphic Adventure Engine
 *
 * ScummVM is the legal property of its developers, whose names
 * are too numerous to list here. Please refer to the COPYRIGHT
 * file distributed with this source distribution.
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
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
 *
 */

#include "pink/pda_mgr.h"
#include "pink/objects/actors/actor.h"
#include "pink/objects/pages/pda_page.h"
#include "pink/pink.h"

namespace Pink {


PDAPage PDAPage::create(const Common::String &pageName, PDAMgr &pdaMgr) {
	PDAPage page(pageName, pdaMgr);
	page._name = pageName;
	page._resMgr.init(pdaMgr.getGame(), &page);
	return page;
}

Array<Actor *> PDAPage::takeActors() {
	Array<Actor *> actorsCopy = _actors;
	_actors.clear();
	return actorsCopy;
}

void PDAPage::init() {
	for (uint i = 0; i < _actors.size(); ++i) {
		if (_actors[i]->initPallete(_pdaMgr.getGame()->getDirector()))
			break;
	}

	for (uint i = 0; i < _actors.size(); ++i) {
		_actors[i]->init(0);
	}
}

PDAPage::PDAPage(const Common::String &name, PDAMgr &pdaMgr)
		: _pdaMgr(pdaMgr) {
	_name = name;
}

} // End of namespace Pink