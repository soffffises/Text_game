#pragma once

#include <string>
#include <vector>
#include <map>

#include "World.h"
#include "Utils.h"

// The task of this class is as follows:
// - Take the user input as a vector of words (["show", "my", "inventory"])
// - Process the command and figure out if you can respond to it (usually by the first word)
class Command {
    public:
        Command() {};
        virtual ~Command() {};
        virtual void execute(std::vector<std::string>& args, World& world) = 0;
};

class ShowCommand: public Command {
    public:
        ShowCommand() {};
        ~ShowCommand() {};
        void execute(std::vector<std::string>& args, World& world) override;
};

class ExitCommand: public Command {
    public:
        ExitCommand() {};
        ~ExitCommand() {};
        void execute(std::vector<std::string>& args, World& world) override;
};

class UnknownCommand: public Command {
    public:
        UnknownCommand() {};
        ~UnknownCommand() {};
        void execute(std::vector<std::string>& args, World& world) override;
};

class WhereCommand: public Command {
    public:
        WhereCommand() {};
        ~WhereCommand() {};
        void execute(std::vector<std::string>& args, World& world) override;
};

class DescribeCommand: public Command {
    public:
        DescribeCommand() {};
        ~DescribeCommand() {};
        void execute(std::vector<std::string>& args, World& world) override;
};

class GoCommand: public Command {
    public:
        GoCommand() {};
        ~GoCommand() {};
        void execute(std::vector<std::string>& args, World& world) override;
};

class UseCommand: public Command {
    public:
        UseCommand() {};
        ~UseCommand() {};
        void execute(std::vector<std::string>& args, World& world) override;
};


class CommandExecutor {
    public:
        CommandExecutor();
        ~CommandExecutor();
        void execute(std::vector<std::string>& args, World& world);

    private:
        std::map<std::string, Command*> command_mapping;
};
