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
#include "SmeltingRecipe.hpp"

SmeltingRecipe::SmeltingRecipe(const ItemStack &input, const ItemStack &output) : Recipe("smelt", output) {
	m_input = input;
}

void SmeltingRecipe::serialize(sf::Packet &packet) const {
	packet << m_result << m_input;
}

void SmeltingRecipe::deserialize(sf::Packet &packet) {
	packet >> m_result >> m_input;
}

bool SmeltingRecipe::isMatching(const Inventory &inventory) const {
	return (inventory.getStack(0, 0).item().id() == m_input.item().id()
	     && inventory.getStack(0, 0).amount() >= m_input.amount());
}

