#pragma once

#include <optional>
#include <tuple>
#include <vector>

#include "grid.h"
#include "room.h"
#include "vec.h"

void print_layout(const Grid<int>& layout);

class Builder {
   public:
    Builder(int room_placement_attempts);
    std::pair<Grid<int>, Rooms> generate(int width, int height);
    std::pair<Grid<int>, Rooms> test(int width, int height);

   private:
    int room_placement_attempts;
    int id;
    Rooms rooms;

    void add_rooms(Grid<int>& layout);
    Room generate_room(const Grid<int>& layout) const;
    void imprint_room(Grid<int>& layout, const Room& room, int id) const;

    void create_corridors(Grid<int>& layout);
    void carve_corridor(Grid<int>& layout, const Vec& position,
                        std::array<Vec, 4> directions) const;

    using Connector = std::tuple<Vec, int, int>;
    std::optional<Connector> maybe_connector(const Grid<int>& layout,
                                             const Vec& position) const;
    std::vector<Connector> find_all_connectors(const Grid<int>& layout) const;
    std::vector<Vec> reduce_connectors(
        const std::vector<Connector>& connectors) const;

    void remove_deadends(Grid<int>& layout) const;
    void mark_surrounded_walls(Grid<int>& layout) const;
};
