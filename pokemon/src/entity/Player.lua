--[[
    GD50
    Pokemon

    Author: Colton Ogden
    cogden@cs50.harvard.edu
]]

Player = Class{__includes = Entity}

function Player:init(def)
    Entity.init(self, def)

    self.party = Party {
        pokemon = {
            Pokemon(POKEMON_DEFS['Pikachu'],6),
            Pokemon(Pokemon.getRandomDef(), 5),
            Pokemon(Pokemon.getRandomDef(), 5)
        },
        pokemonFriend = {

        }
    }
    self.bag = Bag{
        items = {
            Item(ITEM_DEFS['Monsterball'])
        },
        money = 10000
    }
end