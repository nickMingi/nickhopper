PlayerWalkState = Class{__includes = EntityWalkState}

function PlayerWalkState:init(entity, level)
    EntityWalkState.init(self, entity, level)
    self.encounterFound = false
end

function PlayerWalkState:enter()
    self:checkForEncounter()

    if not self.encounterFound then
        self.attemptMove()
    end
end

function PlayerWalkState:checkForEncounter()
    local x, y = self.entity.mapX, self.entity.mapY

    -- chance to go to battle if we're walking into a grass tile
    if self.level.grassLayer.tiles[y][x].id == TILE_IDS['tall-grass'] and math.random(10) == 1 then
        self.entity:changeState('idle')

        -- trigger music changes
        gSounds['field-music']:pause()
        gSounds['battle-music']:play()

        -- first, push a fade in;
        -- out, which will fall back to the battle state once
        gStateStack:push(
            FadeInState({
                r = 255, g = 255, b = 255,
            }, 1,
            -- callback that will execute once the fade in is complete
            function()
                gStateStack:push(BattleState(self.entity))
                gStateStack:push(FadeOutState({
                    r = 255, g = 255, b = 255
                }, 1,
                
                function()
                    -- nothing to do
                end))
            end)
        )

        self.encounterFound = true
    else
        self.encounterFound = false
    end
end


