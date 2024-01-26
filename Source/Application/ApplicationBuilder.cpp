// SPDX-License-Identifier: GPL-3.0-or-later
/*
 * Copyright (C) 2024 Chirag Singla
 */

#include "Application/ApplicationBuilder.h"
#include "Core/Log.h"

std::unique_ptr<Render3D::Application> Render3D::ApplicationBuilder::build() {
    return std::make_unique<Render3D::Application>(m_ApplicationSpec);
}

Render3D::ApplicationBuilder &Render3D::ApplicationBuilder::title(const std::string &title) {
    R3D_TRACE("Set title: {}", title);
    m_ApplicationSpec.Title = title;
    return *this;
}

Render3D::ApplicationBuilder &Render3D::ApplicationBuilder::width(uint32_t width) {
    R3D_TRACE("Set width: {}", width);
    m_ApplicationSpec.Width = width;
    return *this;
}

Render3D::ApplicationBuilder &Render3D::ApplicationBuilder::height(uint32_t height) {
    R3D_TRACE("Set height: {}", height);
    m_ApplicationSpec.Height = height;
    return *this;
}

Render3D::ApplicationBuilder &Render3D::ApplicationBuilder::withScript(const std::string &script) {
    m_ApplicationSpec.Script = script;
    return *this;
}
