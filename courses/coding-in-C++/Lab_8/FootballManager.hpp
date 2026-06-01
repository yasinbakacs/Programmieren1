#ifndef FOOTBALL_MANAGER_HPP
#define FOOTBALL_MANAGER_HPP

#include <string>

/*
 * SOLID findings in the original BugHunt version:
 * - SRP: FootballManager violated the Single Responsibility Principle because
 *   it selected strategies, trained players, saved data and sent messages.
 * - OCP: FootballManager::select_strategy used if/else checks on strategy
 *   strings, so adding a new strategy required changing existing code.
 * - LSP: InjuredPlayer was problematic because it inherited from Player but
 *   accepted only lower training intensities, strengthening the base contract.
 * - ISP: ClubService forced training, saving and notification into one large
 *   interface although clients may need only one of those responsibilities.
 * - DIP: FootballManager depended directly on FilePlayerRepository and
 *   EmailNotifier; these concrete dependencies should be replaced by
 *   repository, notification and report abstractions.
 */

enum class PlayerStatus
{
    Available,
    Injured
};

class Player
{
private:
    std::string name;
    int age;
    PlayerStatus status;

public:
    Player(const std::string &name, int age, PlayerStatus status);

    std::string get_name() const;
    int get_age() const;
    PlayerStatus get_status() const;
    bool is_available_for_match() const;
};

class TrainingPlan
{
public:
    virtual ~TrainingPlan() = default;

    virtual bool train(Player &player, int intensity) const = 0;
};

class StandardTrainingPlan : public TrainingPlan
{
public:
    bool train(Player &player, int intensity) const override;
};

class RecoveryTrainingPlan : public TrainingPlan
{
public:
    bool train(Player &player, int intensity) const override;
};

class MatchStrategy
{
public:
    virtual ~MatchStrategy() = default;

    virtual void apply() const = 0;
};

class OffensiveStrategy : public MatchStrategy
{
public:
    void apply() const override;
};

class DefensiveStrategy : public MatchStrategy
{
public:
    void apply() const override;
};

class PlayerRepository
{
public:
    virtual ~PlayerRepository() = default;

    virtual void save(const Player &player) = 0;
};

class FilePlayerRepository : public PlayerRepository
{
public:
    void save(const Player &player) override;
};

class PlayerNotifier
{
public:
    virtual ~PlayerNotifier() = default;

    virtual void send(const Player &player, const std::string &message) = 0;
};

class EmailNotifier : public PlayerNotifier
{
public:
    void send(const Player &player, const std::string &message) override;
};

class SponsorReportPrinter
{
public:
    virtual ~SponsorReportPrinter() = default;

    virtual void print_report(const Player &player) = 0;
};

class ConsoleSponsorReportPrinter : public SponsorReportPrinter
{
public:
    void print_report(const Player &player) override;
};

class FootballManager
{
private:
    PlayerRepository &repository;
    PlayerNotifier &notifier;
    SponsorReportPrinter &report_printer;

public:
    FootballManager(
        PlayerRepository &repository,
        PlayerNotifier &notifier,
        SponsorReportPrinter &report_printer);

    void manage_player(
        Player &player,
        const TrainingPlan &training_plan,
        const MatchStrategy &match_strategy,
        int training_intensity);

    bool train_player(Player &player, const TrainingPlan &training_plan, int intensity) const;
    void select_match_strategy(const Player &player, const MatchStrategy &match_strategy) const;
    void save_player(const Player &player);
    void send_message(const Player &player, const std::string &message);
    void print_sponsor_report(const Player &player);
};

#endif
