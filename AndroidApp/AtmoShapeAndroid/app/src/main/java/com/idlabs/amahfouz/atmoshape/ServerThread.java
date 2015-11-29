package com.idlabs.amahfouz.atmoshape;

import android.util.Log;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Map;

/**
 * Created by Mido Mahfouz on 11/6/2015.
 */
class ServerThread implements Runnable {

    private ServerSocket serverSocket;
    public static final int SERVERPORT = 30000;
    private ArrayList<Socket> clientSockets;
    private Map<String, Integer> clientInfo;

    public ServerThread(){
        clientSockets = new ArrayList<Socket>();
        clientInfo = new HashMap<String, Integer>();
    }
    public void run() {
        Socket socket = null;
        try {
            serverSocket = new ServerSocket(SERVERPORT);
        } catch (IOException e) {
            e.printStackTrace();
        }
        while (!Thread.currentThread().isInterrupted()) {

            try {
                BufferedReader input;
                socket = serverSocket.accept();
                input = new BufferedReader(new InputStreamReader(socket.getInputStream()));
                String clientName = input.readLine();
                Integer clientPort =  socket.getPort();
                clientInfo.put(clientName, clientPort);
                clientSockets.add(socket);
                Log.d("amr", "client name = "+clientName+"   client port = "+clientPort);
            } catch (IOException e) {
                e.printStackTrace();
            }
        }
    }

    public void broadcastMessageToAllClients(String message){
        for(int i=0;i<clientSockets.size();i++) {
            try {
                PrintWriter out1 = null;
                out1 = new PrintWriter(new BufferedWriter(
                        new OutputStreamWriter(clientSockets.get(i).getOutputStream())),
                        true);
                out1.println(message);
            } catch (IOException e) {
                e.printStackTrace();
            }
        }
    }

    public void stopServer(){
        try {
            serverSocket.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
