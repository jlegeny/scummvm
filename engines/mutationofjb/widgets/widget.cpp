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

#include "mutationofjb/widgets/widget.h"

namespace MutationOfJB {

int Widget::getId() const {
	return _id;
}

void Widget::setId(int id) {
	_id = id;
}

bool Widget::isVisible() const {
	return _visible;
}

void Widget::setVisible(bool visible) {
	if (!_visible && visible) {
		markDirty();
	}
	_visible = visible;
}

void Widget::markDirty() {
	_dirty = true;
}

bool Widget::isDirty() const {
	return _dirty;
}

void Widget::update(Graphics::ManagedSurface &surface) {
	if (_dirty) {
		if (_visible) {
			draw(surface);
		}
		_dirty = false;
	}
}

}
