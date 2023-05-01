using System;
using System.Collections.Generic;
using System.Linq;
using System.Net.Sockets;
using System.Net;
using System.Text;
using System.Threading.Tasks;
using System.IO;
using System.Windows.Forms;

namespace Assignment_2A_SEM2
{
    internal class Server
    {
        string output = "";
        StateMachine stateMachine = new StateMachine();
        public async void Start_server()
        {
            //local host 127.0.0.1
            const string ADRESS = "0.0.0.0"; //Any adress
            const int port = 8090;
            IPAddress ipAddr = IPAddress.Parse(ADRESS);
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
        private async void HandleConnectionAsync(Socket clientSocket)
        {

            NetworkStream networkStream = new NetworkStream(clientSocket);
            StreamReader streamReader = new StreamReader(networkStream);
            StreamWriter streamWriter = new StreamWriter(networkStream);
            StateMachine.State state;
            stateMachine.ResetState();
            streamWriter.WriteLine("Welcome");
            streamWriter.Flush();
            string line = await streamReader.ReadLineAsync();
            while (line != null)
            {
                if (line != null)
                {
                    state = stateMachine.GetState();
                    if (state == StateMachine.State.ACK)
                    {
                        stateMachine.SwitchState(line, state);
                        clientSocket.Disconnect(true);
                        line = null;
                    }
                    else if (state == StateMachine.State.ERR)
                    {
                        streamWriter.WriteLine("ERR");
                        streamWriter.Flush();
                        clientSocket.Disconnect(true);
                        line = null;
                    }
                    else
                    {
                        // read
                        line = await streamReader.ReadLineAsync();
                        stateMachine.SwitchState(line, state);

                        // send
                        string response = stateMachine.getResponse();
                        output = response;
                        streamWriter.WriteLine(response);
                        streamWriter.Flush();
                    }
                }
            }
        }
        public List<Container> getListOfContainers()
        {
            return stateMachine.getListOfContainers();
        }
        public string GetOutput()
        {
            return output;
        }
    }
}

