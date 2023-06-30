#include "messages.h"

Message::Message()
{

}

Message::~Message()
{

}

Message::Message(string const& text, string const& sender, string const& receiver)
{
    setText(text);
    setSender(sender);
    setReceiver(receiver);
}

string const& Message::getText() const
{
    return _text;
}

void Message::setText(string const& text)
{
    _text = text;
}

string const& Message::getSender() const
{
    return _sender;
}

void Message::setSender(string const& sender)
{
    _sender = sender;
}

string const& Message::getReceiver() const
{
    return _receiver;
}

void Message::setReceiver(string const& receiver)
{
    _receiver = receiver;
}

vector<Message> read_messages(string const& filename)
{
    fstream fin(filename, std::ios::in);
    if (!fin)
        return {};
    vector<Message> messages;
    while (true)
    {
        string text, sender, receiver;
        fin >> text >> sender >> receiver;
        if (fin.eof())
            break;
        messages.push_back({text, sender, receiver});
    }
    fin.close();
    return messages;
}

void write_messages(string const& filename, vector<Message> const& messages)
{
    ofstream fout(filename, std::ios::out | std::ios::app);
    if(!fout)
        return;
    for (auto const& message : messages)
    {
        fout << message.getText() << endl
                << message.getSender() << endl
                    << message.getReceiver() << endl;
    }
    fout.close();
}

void print_messages(vector<Message> const& messages)
{
    cout << messages.size() << endl;
    for (auto const& message : messages)
    {
        cout << message.getText() << endl
                << message.getSender() << endl
                    << message.getReceiver() << endl;
    }
}
