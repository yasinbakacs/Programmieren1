#include "FootballManager.hpp"

#include <iostream>

namespace
{
constexpr int MIN_PROFESSIONAL_AGE = 16;
constexpr int MIN_TRAINING_INTENSITY = 0;
constexpr int MAX_STANDARD_TRAINING_INTENSITY = 100;
constexpr int MAX_RECOVERY_TRAINING_INTENSITY = 30;

const char *status_to_text(PlayerStatus status)
{
    switch (status)
    {
    case PlayerStatus::Available:
        return "available";
    case PlayerStatus::Injured:
        return "injured";
    }

    return "unknown";
}
} // namespace

Player::Player(const std::string &name, int age, PlayerStatus status)
    : name(name),
      age(age),
      status(status)
{
}

std::string Player::get_name() const
{
    return name;
}

int Player::get_age() const
{
    return age;
}

PlayerStatus Player::get_status() const
{
    return status;
}

bool Player::is_available_for_match() const
{
    return status == PlayerStatus::Available;
}

bool StandardTrainingPlan::train(Player &player, int intensity) const
{
    if (intensity < MIN_TRAINING_INTENSITY || intensity > MAX_STANDARD_TRAINING_INTENSITY)
    {
        std::cout << "Invalid standard training intensity. Use a value between 0 and 100.\n";
        return false;
    }

    std::cout << player.get_name()
              << " trains with standard intensity "
              << intensity
              << ".\n";
    return true;
}

bool RecoveryTrainingPlan::train(Player &player, int intensity) const
{
    if (intensity < MIN_TRAINING_INTENSITY || intensity > MAX_RECOVERY_TRAINING_INTENSITY)
    {
        std::cout << "Invalid recovery training intensity. Use a value between 0 and 30.\n";
        return false;
    }

    std::cout << player.get_name()
              << " performs recovery training with intensity "
              << intensity
              << ".\n";
    return true;
}

void OffensiveStrategy::apply() const
{
    std::cout << "Strategy: offensive pressing.\n";
}

void DefensiveStrategy::apply() const
{
    std::cout << "Strategy: compact defense.\n";
}

void FilePlayerRepository::save(const Player &player)
{
    std::cout << "Saving " << player.get_name() << " to player_file.txt.\n";
}

void EmailNotifier::send(const Player &player, const std::string &message)
{
    std::cout << "Sending email to " << player.get_name() << ": " << message << "\n";
}

void ConsoleSponsorReportPrinter::print_report(const Player &player)
{
    std::cout << "Sponsor Report\n";
    std::cout << "Player: " << player.get_name() << "\n";
    std::cout << "Age: " << player.get_age() << "\n";
    std::cout << "Status: " << status_to_text(player.get_status()) << "\n";
}

FootballManager::FootballManager(
    PlayerRepository &repository,
    PlayerNotifier &notifier,
    SponsorReportPrinter &report_printer)
    : repository(repository),
      notifier(notifier),
      report_printer(report_printer)
{
}

void FootballManager::manage_player(
    Player &player,
    const TrainingPlan &training_plan,
    const MatchStrategy &match_strategy,
    int training_intensity)
{
    std::cout << "Managing player " << player.get_name() << ".\n";

    if (player.get_age() < MIN_PROFESSIONAL_AGE)
    {
        std::cout << player.get_name() << " is too young for the professional team.\n";
        return;
    }

    select_match_strategy(player, match_strategy);

    if (!train_player(player, training_plan, training_intensity))
    {
        return;
    }

    save_player(player);
    send_message(player, "Training preparation completed.");
    print_sponsor_report(player);
}

bool FootballManager::train_player(Player &player, const TrainingPlan &training_plan, int intensity) const
{
    return training_plan.train(player, intensity);
}

void FootballManager::select_match_strategy(const Player &player, const MatchStrategy &match_strategy) const
{
    if (!player.is_available_for_match())
    {
        std::cout << player.get_name() << " is injured and is not selected for the match.\n";
        return;
    }

    match_strategy.apply();
}

void FootballManager::save_player(const Player &player)
{
    repository.save(player);
}

void FootballManager::send_message(const Player &player, const std::string &message)
{
    notifier.send(player, message);
}

void FootballManager::print_sponsor_report(const Player &player)
{
    report_printer.print_report(player);
}

int main()
{
    Player player("Alex Striker", 24, PlayerStatus::Available);
    Player injured_player("Ben Defender", 29, PlayerStatus::Injured);

    FilePlayerRepository repository;
    EmailNotifier notifier;
    ConsoleSponsorReportPrinter report_printer;

    StandardTrainingPlan standard_training;
    RecoveryTrainingPlan recovery_training;
    OffensiveStrategy offensive_strategy;
    DefensiveStrategy defensive_strategy;

    FootballManager manager(repository, notifier, report_printer);

    manager.manage_player(player, standard_training, offensive_strategy, 70);
    std::cout << "\n";
    manager.manage_player(injured_player, recovery_training, defensive_strategy, 20);

    return 0;
}
