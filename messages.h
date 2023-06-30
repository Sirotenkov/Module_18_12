#pragma once

#include <fstream>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Message final
{
    public:
        Message();
        ~Message();
        Message(string const& text, string const& sender, string const& receiver);

        string const& getText() const;
        void setText(string const& text);

        string const& getSender() const;
        void setSender(string const& sender);

        string const& getReceiver() const;
        void setReceiver(string const& receiver);

    private:
        string _text;
        string _sender;
        string _receiver;
};

vector<Message> read_messages(string const& filename);
void write_messages(string const& filename, vector<Message> const& messages);
void print_messages(vector<Message> const& messages);
