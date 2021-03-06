/*
 * Copyright (c) 2011-2013, Guillermo A. Amaral B. (gamaral) <g@maral.me>
 * All rights reserved.
 *
 * This file is part of Marshmallow Game Engine.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 *   1. Redistributions of source code must retain the above copyright notice,
 *      this list of conditions and the following disclaimer.
 *
 *   2. Redistributions in binary form must reproduce the above copyright
 *      notice, this list of conditions and the following disclaimer in the
 *      documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE CONTRIBUTORS ``AS IS'' AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO
 * EVENT SHALL THE CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF
 * ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 * The views and conclusions contained in the software and documentation are
 * those of the authors and should not be interpreted as representing official
 * policies, either expressed or implied, of the project as a whole.
 */

#pragma once

/*!
 * @file
 *
 * @author Guillermo A. Amaral B. (gamaral) <g@maral.me>
 */

#ifndef MARSHMALLOW_GAME_IENGINE_H
#define MARSHMALLOW_GAME_IENGINE_H 1

MARSHMALLOW_NAMESPACE_BEGIN
namespace Core { /******************************************** Core Namespace */
	class Type;
} /*********************************************************** Core Namespace */

namespace Event { /****************************************** Event Namespace */
	class EventManager;
} /********************************************************** Event Namespace */

namespace Game { /******************************************** Game Namespace */

	class SceneManager;
	struct IEngineFeature;
	struct IFactory;

	/*! @brief Game Engine Interface */
	struct MARSHMALLOW_GAME_EXPORT
	IEngine
	{
		virtual ~IEngine(void);

		/*!
		 * @brief Start Engine
		 */
		virtual int run(void) = 0;

		/*!
		 * @brief Stop Engine
		 * @param exit_code Exit code
		 */
		virtual void stop(int exit_code = 0) = 0;

		/*!
		 * @brief Suspend Engine (pause)
		 */
		virtual void suspend(void) = 0;

		/*!
		 * @brief Resume Engine (unpause)
		 */
		virtual void resume(void) = 0;

		/*!
		 * @brief Returns true if engine is suspended
		 */
		virtual bool isSuspended(void) const = 0;

		/*!
		 * @brief Event Manager
		 */
		virtual Event::EventManager * eventManager(void) const = 0;

		/*!
		 * @brief Scene Manager
		 */
		virtual Game::SceneManager * sceneManager(void) const = 0;

		/*!
		 * @brief Game Factory
		 */
		virtual Game::IFactory * factory(void) const = 0;

		/*
		 * Features
		 */

		/*!
		 * @brief Add engine feature
		 */
		virtual void addFeature(Game::IEngineFeature *feature) = 0;

		/*!
		 * @brief Remove engine feature
		 */
		virtual void removeFeature(Game::IEngineFeature *feature) = 0;

		/*!
		 * @brief Remove engine feature of a certain type
		 */
		virtual Game::IEngineFeature * removeFeature(const Core::Type &type) = 0;

		/*!
		 * @brief Get engine feature of a certain type
		 * @return Engine feature pointer or null if the feature was not found
		 */
		virtual Game::IEngineFeature * getFeature(const Core::Type &type) = 0;
	};

} /*********************************************************** Game Namespace */
MARSHMALLOW_NAMESPACE_END

#endif
