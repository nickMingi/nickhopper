--[[
    GD50
    Pokemon

    Author: Colton Ogden
    cogden@cs50.harvard.edu
]]

Level = Class{}

function Level:init(param)
    if param == 'database' then
        self.tileWidth = gLevelDataNew['tileWidth']
        self.tileHeight = gLevelDataNew['tileHeight']
        self.mapx = gPlayerDataNew['mapX']
        self.mapy = gPlayerDataNew['mapY']
        self.width = gLevelDataNew['width']
        self.height = gLevelDataNew['height']
    elseif param == 'savedData' then
        self.tileWidth = gLevelData['tileWidth']
        self.tileHeight = gLevelData['tileHeight']
        self.mapx = gPlayerData['mapX']
        self.mapy = gPlayerData['mapY']
        self.width = gLevelData['width']
        self.height = gLevelData['height']
    end

    self.baseLayer = TileMap(self.tileWidth, self.tileHeight)
    self.grassLayer = TileMap(self.tileWidth, self.tileHeight)
    self.halfGrassLayer = TileMap(self.tileWidth, self.tileHeight)

    self:createMaps()

    self.player = Player {
        animations = ENTITY_DEFS['player'].animations,
        mapX = self.mapx,
        mapY = self.mapy,
        width = 16,
        height = 16,
    }

    self.player.stateMachine = StateMachine{
        ['walk'] = function() return PlayerWalkState(self.player, self) end,
        ['idle'] = function() return PlayerIdleState(self.player) end
    }
    self.player.stateMachine:change('idle')
end

function Level:createMaps()

    -- fill the base tiles table with random grass IDs
    for y = 1, self.tileHeight do
        table.insert(self.baseLayer.tiles, {})

        for x = 1, self.tileWidth do
            local id = TILE_IDS['grass'][math.random(#TILE_IDS['grass'])]

            table.insert(self.baseLayer.tiles[y], Tile(x, y, id))
        end
    end

    -- place tall grass in the tall grass layer
    for y = 1, self.tileHeight do
        table.insert(self.grassLayer.tiles,{})
        table.insert(self.halfGrassLayer.tiles, {})

        for x = 1, self.tileWidth do
            local id = y > 10 and TILE_IDS['tall-grass'] or TILE_IDS['empty']

            table.insert(self.grassLayer.tiles[y], Tile(x, y, id))
        end
    end
end

function Level:update(dt)
    self.player:update(dt)
end

function Level:render()
    self.baseLayer:render()
    self.grassLayer:render()
    self.player:render()
end
