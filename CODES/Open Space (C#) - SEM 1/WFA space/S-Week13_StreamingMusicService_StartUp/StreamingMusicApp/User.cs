using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace StreamingMusicApp
{
     public class User
    {
        public const int MAX_SONGS_IN_FAVORURITES = 50;
        private int userid;
        private string username;
        private string email;
        private string address;
        private int total_favorite_songs;
        private string user_favorite_songs;

        public User()
        {
        }
        public User(int userid, string userName, string email)
        {
            this.userid = userid;
            this.username = userName;
            this.email = email;
        }
        public User(int userid, string userName, string email, string address)
        {
            this.userid = userid;
            this.username = userName;
            this.email = email;
            this.address = address;
        }
        public void AddSongToFavorites()
        {
            if (total_favorite_songs < MAX_SONGS_IN_FAVORURITES)
            {
                total_favorite_songs++;
            }
        }
        public void RemoveSongFromFavorites()
        {
            
        }
        public int GetUserID()
        {
            return this.userid;
        }
        public string GetUserName()
        {
            return this.username;
        }
        public string GetFavoriteSongs()
        {
            if (total_favorite_songs == 0)
            {
                return null;
            }
            else
            {
                return $"Favourite songs of {this.userid}:";
            }
        }
    }
}