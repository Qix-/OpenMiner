/*
 * =====================================================================================
 *
 *  OpenMiner
 *
 *  Copyright (C) 2018-2020 Unarelith, Quentin Bazin <openminer@unarelith.net>
 *  Copyright (C) 2019-2020 the OpenMiner contributors (see CONTRIBUTORS.md)
 *
 *  This file is part of OpenMiner.
 *
 *  OpenMiner is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU Lesser General Public
 *  License as published by the Free Software Foundation; either
 *  version 2.1 of the License, or (at your option) any later version.
 *
 *  OpenMiner is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 *  Lesser General Public License for more details.
 *
 *  You should have received a copy of the GNU Lesser General Public License
 *  along with OpenMiner; if not, write to the Free Software Foundation, Inc.,
 *  51 Franklin Street, Fifth Floor, Boston, MA  02110-1301 USA
 *
 * =====================================================================================
 */
#include <map>

#include <gk/core/IntTypes.hpp>

#include "Network.hpp"

std::string Network::commandToString(Network::Command command) {
	std::map<Network::Command, std::string> commandNames = {
		{Network::Command::ClientConnect,         "ClientConnect"},
		{Network::Command::ClientDisconnect,      "ClientDisconnect"},
		{Network::Command::ClientOk,              "ClientOk"},
		{Network::Command::ClientRefused,         "ClientRefused"},

		{Network::Command::KeyState,              "KeyState"},

		{Network::Command::ChunkData,             "ChunkData"},
		{Network::Command::ChunkRequest,          "ChunkRequest"},

		{Network::Command::PlayerPlaceBlock,      "PlayerPlaceBlock"},
		{Network::Command::PlayerDigBlock,        "PlayerDigBlock"},
		{Network::Command::PlayerInvUpdate,       "PlayerInvUpdate"},
		{Network::Command::PlayerPosUpdate,       "PlayerPosUpdate"},
		{Network::Command::PlayerSpawn,           "PlayerSpawn"},
		{Network::Command::PlayerInventory,       "PlayerInventory"},
		{Network::Command::PlayerCreativeWindow,  "PlayerCreativeWindow"},
		{Network::Command::PlayerChangeDimension, "PlayerChangeDimension"},

		{Network::Command::BlockUpdate,           "BlockUpdate"},
		{Network::Command::BlockActivated,        "BlockActivated"},
		{Network::Command::BlockGUIData,          "BlockGUIData"},
		{Network::Command::BlockInvUpdate,        "BlockInvUpdate"},
		{Network::Command::BlockDataUpdate,       "BlockDataUpdate"},

		{Network::Command::RegistryData,          "RegistryData"},

		{Network::Command::ChatMessage,           "ChatMessage"},

		{Network::Command::EntitySpawn,           "EntitySpawn"},
		{Network::Command::EntityDespawn,         "EntityDespawn"},
		{Network::Command::EntityPosition,        "EntityPosition"},
		{Network::Command::EntityRotation,        "EntityRotation"},
		{Network::Command::EntityAnimation,       "EntityRotation"},
		{Network::Command::EntityDrawableDef,     "EntityDrawableDef"},
	};

	return commandNames[command];
}

sf::Packet &operator<<(sf::Packet &packet, Network::Command command) {
	return packet << static_cast<u16>(command);
}

sf::Packet &operator>>(sf::Packet &packet, Network::Command &command) {
	u16 tmp;
	packet >> tmp;
	command = static_cast<Network::Command>(tmp);
	return packet;
}

