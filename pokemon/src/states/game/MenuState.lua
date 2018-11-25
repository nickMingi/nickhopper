--[[
    GD50
    Pokemon

    Author: Colton Ogden
    cogden@cs50.harvard.edu
]]

MenuState = Class{__includes = BaseState}

function MenuState:init(params,player)
    self.item = params
    self.player = player
    self.items = 0
    if params == 'Bag' then
        local test = MenuState:makeItem(self.player.bag.items)
        self.itemMenu = Menu {
            x = VIRTUAL_WIDTH - 300,
            y = VIRTUAL_HEIGHT - 150,
            width = 300,
            height = 150,
            items = test
        }

    elseif params == 'Pokemon' then
        local pokemon = MenuState:makeItem(self.player.party.pokemon)
        self.itemMenu = Menu {
            x = VIRTUAL_WIDTH - 300,
            y = VIRTUAL_HEIGHT - 150,
            width = 300,
            height = 150,
            items = pokemon
        }
    end
    
end

function MenuState:makeItem(param)
    local items = {}
        for i = 1, #param do 
           table.insert(items, {text = param[i].name,
                onSelect = function()
                end
            })
        end
    return items
end

function MenuState:update(dt)
    if love.keyboard.wasPressed('q') then
        gStateStack:pop()
    end
    self.itemMenu:update(dt)
end

function MenuState:render()
    self.itemMenu:render()
end