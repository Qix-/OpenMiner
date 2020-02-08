/*
 * =====================================================================================
 *
 *  OpenMiner
 *  Copyright (C) 2018-2020 Unarelith, Quentin Bazin <openminer@unarelith.net>
 *
 *  This program is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU Lesser General Public
 *  License as published by the Free Software Foundation; either
 *  version 2.1 of the License, or (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 *  Lesser General Public License for more details.
 *
 *  You should have received a copy of the GNU Lesser General Public License
 *  along with this program; if not, write to the Free Software Foundation, Inc.,
 *  51 Franklin Street, Fifth Floor, Boston, MA  02110-1301 USA
 *
 * =====================================================================================
 */
#include "ItemStack.hpp"
#include "Registry.hpp"

const Item &ItemStack::item() const {
	return Registry::getInstance().getItemFromStringID(m_name);
}

sf::Packet &operator<<(sf::Packet &packet, const ItemStack &itemStack) {
	return packet << itemStack.item().name() << itemStack.amount();
}

sf::Packet &operator>>(sf::Packet &packet, ItemStack &itemStack) {
	std::string name;
	u16 amount;
	packet >> name >> amount;
	itemStack.setItem(name);
	itemStack.setAmount(amount);
	return packet;
}

