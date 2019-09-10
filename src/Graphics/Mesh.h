/* openblack - A reimplementation of Lionhead's Black & White.
 *
 * openblack is the legal property of its developers, whose names
 * can be found in the AUTHORS.md file distributed with this source
 * distribution.
 *
 * openblack is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 3
 * of the License, or (at your option) any later version.
 *
 * openblack is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with openblack. If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#include <cstdint>

#include <Graphics/IndexBuffer.h>
#include <Graphics/VertexBuffer.h>

using namespace openblack::graphics;

namespace openblack
{
namespace graphics
{

class Mesh
{
  public:
	enum class Topology
	{
		PointList,
		LineList,
		LineStrip,
		TriangleList,
		TriangleStrip,
	};

	explicit Mesh(VertexBuffer* vertexBuffer, Topology topology = Topology::TriangleList);
	Mesh(VertexBuffer* vertexBuffer, IndexBuffer* indexBuffer, Topology topology = Topology::TriangleList);
	~Mesh();

	[[nodiscard]] const VertexBuffer& GetVertexBuffer() const;
	[[nodiscard]] const IndexBuffer& GetIndexBuffer() const;

	[[nodiscard]] Topology GetTopology() const noexcept;

	void Draw();
	void Draw(uint32_t count, uint32_t startIndex);

  protected:
	std::unique_ptr<VertexBuffer> _vertexBuffer;
	std::unique_ptr<IndexBuffer> _indexBuffer;

  private:
	uint32_t _vao;
	Topology _topology;
};

} // namespace graphics
} // namespace openblack
