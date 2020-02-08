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
#ifndef SERVERCOMMANDHANDLER_HPP_
#define SERVERCOMMANDHANDLER_HPP_

#include <unordered_map>

#include <gk/core/Vector3.hpp>

class Registry;
class ScriptEngine;
class Server;
class ServerPlayer;
class ServerWorld;

class ServerCommandHandler {
	public:
		ServerCommandHandler(ScriptEngine &scriptEngine, Server &server, ServerWorld &world, std::unordered_map<u16, ServerPlayer> &players, Registry &registry)
			: m_scriptEngine(scriptEngine), m_server(server), m_world(world), m_players(players), m_registry(registry) {}

		void setupCallbacks();

	private:
		ScriptEngine &m_scriptEngine;

		Server &m_server;
		ServerWorld &m_world;
		std::unordered_map<u16, ServerPlayer> &m_players;

		Registry &m_registry;

		// FIXME: Warning: Duplicated in ClientPlayer.cpp
		gk::Vector3<s32> m_spawnPosition{12, 18, 12};
};

#endif // SERVERCOMMANDHANDLER_HPP_
