#include <bits/stdc++.h>
using namespace std;
class Meet
{

public:
    int user_id;
    int start_time;
    int end_time;

    Meet(int user_id, int start_time, int end_time)
    {
        this->user_id = user_id;
        this->start_time = start_time;
        this->end_time = end_time;
    }
};
bool comp(const Meet &meet1, const Meet &meet2)
{
    return meet1.end_time < meet2.start_time;
}
class Calender
{
    map<int, vector<Meet>> list;

public:
    Calender()
    {
        list = map<int, vector<Meet>>();
    }

    bool add_room(int room_id)
    {
        if (list.find(room_id) != list.end())
            return false;

        list[room_id] = vector<Meet>();
        return true;
    }

    int add_meeting(int user_id, int start_time, int end_time)
    {
        Meet meet = Meet(user_id, start_time, end_time);

        for (auto &room : list)
        {
            int room_id = room.first;
            auto meet_list = room.second;

            if (meet_list.empty())
            {
                room.second.push_back(meet);
                return room_id;
            }
            else
            {
                auto it_next = upper_bound(meet_list.begin(), meet_list.end(), meet, comp);
                auto it_prev = it_next;
                it_prev--;
                if (it_next == meet_list.end())
                {
                    if (meet.start_time > it_prev->end_time)
                    {
                        room.second.push_back(meet);
                        return room_id;
                    }
                    else
                        continue;
                }
                else if (meet.start_time > it_prev->end_time && meet.end_time < it_next->start_time)
                {
                    room.second.insert(it_prev, meet);
                    return room_id;
                }
            }
        }
        return -1;
    }

    void display_meetings(int room_id)
    {
        if (list.find(room_id) == list.end())
            return;

        for (auto &meet : list[room_id])
        {
            cout << "User: " << meet.user_id << " ,Time: " << meet.start_time << " - " << meet.end_time << "\n";
        }
    }
};
int main()
{
    Calender calneder;
    calneder.add_room(1);
    calneder.add_room(3);

    cout << calneder.add_meeting(100, 8, 9) << "\n";
    cout << calneder.add_meeting(200, 10, 12) << "\n";
    cout << calneder.add_meeting(300, 9, 10) << "\n";
    cout << calneder.add_meeting(400, 8, 11) << "\n";
    return 0;
}

/*
1 -> (8,9), (10,12)
3 -> (9,10)
*/