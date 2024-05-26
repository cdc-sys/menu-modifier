#include <Geode/Geode.hpp>
#include <Geode/modify/MenuLayer.hpp>

using namespace geode::prelude;

class $modify(MenuLayer) {
    bool init() override {
        if (!MenuLayer::init()) return false;
        if (!Mod::get()->getSettingValue<bool>("main_menu_enabled")) return true;

        auto socialMediaMenu = this->getChildByID("social-media-menu");
        auto moreGamesMenu = this->getChildByID("more-games-menu");
        auto profileMenu = this->getChildByID("profile-menu");
        auto playerUsername = this->getChildByID("player-username");
        auto rightSideMenu = this->getChildByID("right-side-menu");

        auto robtopLogo = socialMediaMenu->getChildByID("robtop-logo-button"); 
        auto facebookButton = socialMediaMenu->getChildByID("facebook-button");
        auto twitterButton = socialMediaMenu->getChildByID("twitter-button");
        auto youtubeButton = socialMediaMenu->getChildByID("youtube-button");
        auto twitchButton = socialMediaMenu->getChildByID("twitch-button");
        auto discordButton = socialMediaMenu->getChildByID("discord-button");
        auto moreGamesButton = moreGamesMenu->getChildByID("more-games-button");
        auto dailyChestButton = rightSideMenu->getChildByID("daily-chest-button");

        bool hideRobtopLogo = Mod::get()->getSettingValue<bool>("main_menu_robtoplogo");
        bool hideSocials = Mod::get()->getSettingValue<bool>("main_menu_socials");
        bool hideMoreGames = Mod::get()->getSettingValue<bool>("main_menu_moregames");
        bool moveProfile = Mod::get()->getSettingValue<bool>("main_menu_move_profile");
        bool moveDaily = Mod::get()->getSettingValue<bool>("main_menu_move_daily");

        if (hideRobtopLogo) {
            robtopLogo->setVisible(false);
            if (hideSocials) {
                facebookButton->setVisible(false);
                twitterButton->setVisible(false);
                youtubeButton->setVisible(false);
                twitchButton->setVisible(false);
                discordButton->setVisible(false);
            } else {
                socialMediaMenu->setScale(0.9);
                facebookButton->setPosition(12.6, 12.2);
                twitterButton->setPosition(41.5, 12.2);
                youtubeButton->setPosition(70.4, 12.2);
                twitchButton->setPosition(99.3, 12.2);
                discordButton->setPosition(128.1, 12.2);
            }
        } else if (hideSocials) {
            facebookButton->setVisible(false);
            twitterButton->setVisible(false);
            youtubeButton->setVisible(false);
            twitchButton->setVisible(false);
            discordButton->setVisible(false);
        }

        if (hideMoreGames) {
            moreGamesButton->setVisible(false);
        }

        if (moveProfile && (hideRobtopLogo && hideSocials)) {
            profileMenu->setPosition(91, 85);
            playerUsername->setPosition(47, 121);
        }
        if (moveDaily) {
            dailyChestButton->setPosition(24.25, 0);
        }

        return true;
    }
};
