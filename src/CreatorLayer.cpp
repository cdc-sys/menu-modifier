#include <Geode/Geode.hpp>
#include <Geode/modify/CreatorLayer.hpp>

using namespace geode::prelude;

class $modify(CreatorLayer) {
    bool init() {
        if (!CreatorLayer::init()) return false;
        if (!Mod::get()->getSettingValue<bool>("creatorlayer_enabled")) return true;

        auto creatorButtonsMenu = this->getChildByID("creator-buttons-menu");
        auto versusButton = creatorButtonsMenu->getChildByID("versus-button");
        auto mapButton = creatorButtonsMenu->getChildByID("map-button");
        auto eventButton = creatorButtonsMenu->getChildByID("event-button");
        auto createButton = creatorButtonsMenu->getChildByID("create-button");
        auto savedButton = creatorButtonsMenu->getChildByID("saved-button");
        auto scoresButton = creatorButtonsMenu->getChildByID("scores-button");
        auto pathsButton = creatorButtonsMenu->getChildByID("paths-button");
        auto questsButton = creatorButtonsMenu->getChildByID("quests-button");
        auto dailyButton = creatorButtonsMenu->getChildByID("daily-button");
        auto weeklyButton = creatorButtonsMenu->getChildByID("weekly-button");
        auto gauntletsButton = creatorButtonsMenu->getChildByID("gauntlets-button");
        auto featuredButton = creatorButtonsMenu->getChildByID("featured-button");
        auto listsButton = creatorButtonsMenu->getChildByID("lists-button");
        auto mapPacksButton = creatorButtonsMenu->getChildByID("map-packs-button");
        auto searchButton = creatorButtonsMenu->getChildByID("search-button");

        versusButton->setVisible(false);
        mapButton->setVisible(false);
        eventButton->setVisible(false);

        createButton->setPosition(89.6, 244.6);
        savedButton->setPosition(179.2, 244.6);
        scoresButton->setPosition(268.8, 244.6);
        pathsButton->setPosition(358.4, 244.6);
        questsButton->setPosition(89.6, 155);
        dailyButton->setPosition(179.2, 155);
        weeklyButton->setPosition(268.8, 155);
        gauntletsButton->setPosition(358.4, 155);
        featuredButton->setPosition(89.6, 65.4);
        listsButton->setPosition(179.2, 65.4);
        mapPacksButton->setPosition(268.8, 65.4);
        searchButton->setPosition(358.4, 65.4);

        return true;
    }
};