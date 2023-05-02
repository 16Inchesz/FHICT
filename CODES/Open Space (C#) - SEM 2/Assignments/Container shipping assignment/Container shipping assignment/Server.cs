using System;
using System.Collections.Generic;
using System.Linq;
using System.Net.Sockets;
using System.Net;
using System.Text;
using System.Threading.Tasks;
using System.IO;
using System.Windows.Forms;

namespace Container_shipping_assignment
{
    public class Server
    {
        string output = "";
        Manager manager = new Manager();    //new manager object.
       
        /// <summary>
        /// method that establishes a connection with PuTTY
        /// </summary>
        public async void Start_server()
        {
            //local host 127.0.0.1
            const string ADDRESS = "127.0.0.1"; 
            const int port = 23;
            IPAddress ipAddr = IPAddress.Parse(ADDRESS);
            IPEndPoint localEndPoint = new IPEndPoint(ipAddr, port);
            Socket listener = new Socket(ipAddr.AddressFamily, SocketType.Stream, ProtocolType.Tcp);
            listener.Bind(localEndPoint);
            listener.Listen(10);
            while (true)
            {
                Socket clientSocket = await listener.AcceptAsync();
                HandleConnectionAsync(clientSocket);
            }
        }

        /// <summary>
        /// method that handles the connection between program and PuTTY. 
        /// Method also processes and handles messages.
        /// </summary>
        /// <param name="clientSocket"></param>
        private async void HandleConnectionAsync(Socket clientSocket)
        {

            NetworkStream networkStream = new NetworkStream(clientSocket);
            StreamReader streamReader = new StreamReader(networkStream);
            StreamWriter streamWriter = new StreamWriter(networkStream);
            Manager.Commands commands;
            manager.ResetState();
            streamWriter.WriteLine("Welcome");
            streamWriter.Flush();
            string? line = await streamReader.ReadLineAsync();
            while (line != null)
            {
                if (line != null)
                {
                    commands = manager.GetCommand();
                    if (commands == Manager.Commands.ACK)
                    {
                        manager.StateChange(line, commands);
                        clientSocket.Disconnect(true);
                        line = null;
                    }
                    else if (commands == Manager.Commands.ERR)
                    {
                        streamWriter.WriteLine("ERR");
                        streamWriter.Flush();
                        clientSocket.Disconnect(true);
                        line = null;
                    }
                    else
                    {
                        // reading messages from PuTTY
                        line = await streamReader.ReadLineAsync();
                        if (line != null)
                        {
                            manager.StateChange(line, commands);
                        }

                        // sending messages to PuTTY
                        string response = manager.GetResponse();
                        output = response;
                        streamWriter.WriteLine(response);
                        streamWriter.Flush();
                    }
                }

            }
        }

        /// <summary>
        /// method that returns list of containers
        /// </summary>
        /// <returns></returns>
        public List<Container> GetListOfContainers()
        {
            return manager.GetListOfContainers();
        }

        /// <summary>
        /// method that returns the output.
        /// </summary>
        /// <returns></returns>
        public string GetOutput()
        {
            return output;
        }

    }
}
