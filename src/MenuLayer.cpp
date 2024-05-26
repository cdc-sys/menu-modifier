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

        auto robtopLogo = socialMediaMenu ? socialMediaMenu->getChildByID("robtop-logo-button") : nullptr;
        auto facebookButton = socialMediaMenu ? socialMediaMenu->getChildByID("facebook-button") : nullptr;
        auto twitterButton = socialMediaMenu ? socialMediaMenu->getChildByID("twitter-button") : nullptr;
        auto youtubeButton = socialMediaMenu ? socialMediaMenu->getChildByID("youtube-button") : nullptr;
        auto twitchButton = socialMediaMenu ? socialMediaMenu->getChildByID("twitch-button") : nullptr;
        auto discordButton = socialMediaMenu ? socialMediaMenu->getChildByID("discord-button") : nullptr;
        auto moreGamesButton = moreGamesMenu ? moreGamesMenu->getChildByID("more-games-button") : nullptr;
        auto dailyChestButton = rightSideMenu ? rightSideMenu->getChildByID("daily-chest-button") : nullptr;

        bool hideRobtopLogo = Mod::get()->getSettingValue<bool>("main_menu_robtoplogo");
        bool hideSocials = Mod::get()->getSettingValue<bool>("main_menu_socials");
        bool hideMoreGames = Mod::get()->getSettingValue<bool>("main_menu_moregames");
        bool moveProfile = Mod::get()->getSettingValue<bool>("main_menu_move_profile");
        bool moveDaily = Mod::get()->getSettingValue<bool>("main_menu_move_daily");

        if (hideRobtopLogo && robtopLogo) {
            robtopLogo->setVisible(false);
        }
        
        if (hideSocials) {
            if (facebookButton) facebookButton->setVisible(false);
            if (twitterButton) twitterButton->setVisible(false);
            if (youtubeButton) youtubeButton->setVisible(false);
            if (twitchButton) twitchButton->setVisible(false);
            if (discordButton) discordButton->setVisible(false);
        } else if (hideRobtopLogo) {
            if (socialMediaMenu) socialMediaMenu->setScale(0.9);
            if (facebookButton) facebookButton->setPosition(12.6, 12.2);
            if (twitterButton) twitterButton->setPosition(41.5, 12.2);
            if (youtubeButton) youtubeButton->setPosition(70.4, 12.2);
            if (twitchButton) twitchButton->setPosition(99.3, 12.2);
            if (discordButton) discordButton->setPosition(128.1, 12.2);
        }

        if (hideMoreGames && moreGamesButton) {
            moreGamesButton->setVisible(false);
        }

        if (moveProfile && (hideRobtopLogo && hideSocials)) {
            if (profileMenu) profileMenu->setPosition(91, 85);
            if (playerUsername) playerUsername->setPosition(47, 121);
        }

        if (moveDaily && dailyChestButton) {
            dailyChestButton->setPosition(24.25, 0);
        }

        return true;
    }
};
