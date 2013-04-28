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

#include "game/scenelayerbase.h"

/*!
 * @file
 *
 * @author Guillermo A. Amaral B. (gamaral) <g@maral.me>
 */

#include "core/identifier.h"
#include "core/type.h"

#include <tinyxml2.h>

MARSHMALLOW_NAMESPACE_BEGIN
namespace Game { /******************************************** Game Namespace */

struct SceneLayerBase::Private
{
	Private(const Core::Identifier &i, IScene &s, int f)
	    : id(i)
	    , scene(s)
	    , flags(f)
	    , killed(false) {}

	Core::Identifier id;
	IScene &scene;
	int flags;
	bool killed;
};

SceneLayerBase::SceneLayerBase(const Core::Identifier &i, IScene &s, int f)
    : PIMPL_CREATE_X(i, s, f)
{
}

SceneLayerBase::~SceneLayerBase(void)
{
	PIMPL_DESTROY;
}

const Core::Identifier &
SceneLayerBase::id(void) const
{
	return(PIMPL->id);
}

IScene &
SceneLayerBase::scene(void)
{
	return(PIMPL->scene);
}

int
SceneLayerBase::flags(void) const
{
	return(PIMPL->flags);
}

void
SceneLayerBase::kill(void)
{
	PIMPL->killed = true;
}

bool
SceneLayerBase::isZombie(void) const
{
	return(PIMPL->killed);
}

bool
SceneLayerBase::serialize(XMLElement &n) const
{
	n.SetAttribute("id", id().str().c_str());
	n.SetAttribute("type", type().str().c_str());
	return(true);
}

bool
SceneLayerBase::deserialize(XMLElement &n)
{
	MMUNUSED(n);
	return(true);
}

} /*********************************************************** Game Namespace */
MARSHMALLOW_NAMESPACE_END

