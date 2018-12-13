--[[
    GD50
    Pokemon

    Author: Colton Ogden
    cogden@cs50.harvard.edu
]]

FieldMenuState = Class{__includes = BaseState}

function FieldMenuState:init(level)
    self.player = level.player
    self.fieldMenu = Menu{
        x = VIRTUAL_WIDTH -248,
        y = VIRTUAL_HEIGHT - 64,
        width = 248,
        height = 64,
        items = {
            {
                text = 'Pokemon',
                onSelect = function()
                    gStateStack:pop()
                    gStateStack:push(MenuState("Pokemon",self.player))
                end
            },
            {
                text = 'Bag',
                onSelect = function()
                    gStateStack:pop()
                    gStateStack:push(MenuState("Bag",self.player))
                end
            },
            {
                text = 'Save',
                onSelect = function()
                    gStateStack:pop()
                    gStateStack:push(SaveGameState(level))
                end
            }
        }
    }    
end

function FieldMenuState:update(dt)
    if love.keyboard.wasPressed('q') then
        gStateStack:pop()
    end
    self.fieldMenu:update(dt)
end

function FieldMenuState:render()
    self.fieldMenu:render()
end