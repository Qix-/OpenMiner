/*
 * =====================================================================================
 *
 *       Filename:  MenuWidget.hpp
 *
 *    Description:
 *
 *        Created:  28/06/2018 10:32:26
 *
 *         Author:  Quentin Bazin, <quent42340@gmail.com>
 *
 * =====================================================================================
 */
#ifndef MENUWIDGET_HPP_
#define MENUWIDGET_HPP_

#include "TextButton.hpp"

class MenuWidget : public Widget {
	public:
		void onEvent(const SDL_Event &event) override;

		void addButton(const std::string &text, const TextButton::Callback &callback);

	private:
		void draw(RenderTarget &target, RenderStates states) const override;

		std::vector<TextButton> m_buttons;
};

#endif // MENUWIDGET_HPP_
