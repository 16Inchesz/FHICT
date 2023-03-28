using Microsoft.VisualBasic.ApplicationServices;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace StreamingMusicApp
{
    public class StreamingMusicService
    {
        private int userId;
        private int songIdSeeder;
        private string name;
        private string username;
        private List<Song> songs;
        private List<User> users;

        public StreamingMusicService(string name)
        {
            this.songIdSeeder = 1;
            this.userId = 1;
            this.name = name;
            this.songs = new List<Song>();
            this.users = new List<User>();
        }

        public void AddUser(string username, string email, string address)
        {
            this.users.Add(new User(this.userId, username, email, address));
            this.userId++;
        }
        public void AddSong(string artist, string title, int durationInSeconds, string genre)
        {
            this.songs.Add(new Song(this.songIdSeeder, artist, title, durationInSeconds, genre));
            this.songIdSeeder++;
        }

        public Song GetSong(int id)
        {
            foreach (Song s in this.songs)
            {
                if (id == s.GetId())
                { return s; }
            }
            return null;
        }
        public User GetUser(int userid)
        {
            foreach (User u in this.users)
            {
                if (userid == u.GetUserID()) { return u; }
            }
            return null;
        }

        public Song[] GetSongs()
        {
            return this.songs.ToArray();
        }
        public User[] GetUsers()
        {
            return this.users.ToArray();
        }

        public Song[] GetSongs(string artist)
        {
            List<Song> foundSongs = new List<Song>();
            foreach (Song s in this.songs)
            {
                if(artist == s.GetArtist())
                { foundSongs.Add(s); }
            }
            return foundSongs.ToArray();
        }
        public User[] GetUsers(string Username)
        {
            List<User> foundUsers = new List<User>();
            foreach (User u in this.users)
            {
                if (username == u.GetUserName())
                { foundUsers.Add(u); }
            }
            return foundUsers.ToArray();
        }

        public string GetInfo()
        {
            return $"Streaming Music service: {this.name} ({this.songs.Count} songs)";
        }
    }
}
