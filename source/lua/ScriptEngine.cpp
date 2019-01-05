/*
 * =====================================================================================
 *
 *       Filename:  ScriptEngine.cpp
 *
 *    Description:
 *
 *        Created:  20/12/2018 00:42:55
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#include "LuaMod.hpp"
#include "Player.hpp"
#include "Registry.hpp"
#include "ScriptEngine.hpp"

#include "CraftingRecipe.hpp"
#include "SmeltingRecipe.hpp"

#include "BlockFurnace.hpp"
#include "BlockWater.hpp"
#include "BlockWorkbench.hpp"

ScriptEngine *ScriptEngine::s_instance = nullptr;

void ScriptEngine::init() {
	setInstance(this);

	initUsertypes();

	m_lua["registry"] = &Registry::getInstance();
	m_lua["open_workbench"] = &openWorkbench;
	m_lua["open_furnace"] = &openFurnace;
	m_lua["update_furnace"] = &updateFurnace;

	m_lua.open_libraries(sol::lib::base);
	m_lua.safe_script_file("mods/test.lua");
}

void ScriptEngine::initUsertypes() {
	m_lua.new_usertype<Player>("Player",
		"inventory", &Player::inventory);

	m_lua.new_usertype<Inventory>("Inventory",
		"add_stack",  &Inventory::addStack
	);

	m_lua.new_usertype<LuaMod>("LuaMod",
		sol::constructors<LuaMod(std::string)>(),
		"id",              &LuaMod::id,
		"block",           &LuaMod::registerBlock,
		"item",            &LuaMod::registerItem,
		"crafting_recipe", &LuaMod::registerCraftingRecipe,
		"smelting_recipe", &LuaMod::registerSmeltingRecipe
	);
}

#include "BlockFurnace.hpp"
#include "BlockWorkbench.hpp"
#include "Chunk.hpp"
#include "Player.hpp"
#include "World.hpp"

bool ScriptEngine::openWorkbench(const glm::ivec3 &position, Player &player, World &world) {
	BlockWorkbench block;
	return block.onBlockActivated(position, player, world);
}

bool ScriptEngine::openFurnace(const glm::ivec3 &position, Player &player, World &world) {
	BlockFurnace block;
	return block.onBlockActivated(position, player, world);
}

void ScriptEngine::updateFurnace(const glm::ivec3 &position, Player &player, Chunk &chunk, World &world) {
	BlockFurnace block;
	return block.onTick(position, player, chunk, world);
}

