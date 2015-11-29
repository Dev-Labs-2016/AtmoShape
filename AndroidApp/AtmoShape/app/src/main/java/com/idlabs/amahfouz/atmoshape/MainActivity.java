package com.idlabs.amahfouz.atmoshape;

import android.app.Activity;
import android.os.Bundle;
import android.view.View;
import android.view.Menu;
import android.view.MenuItem;
import android.widget.Button;
import android.widget.ListView;
import android.widget.SimpleAdapter;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;

public class MainActivity extends Activity {

    private ServerThread serverThread;

    private String[] listViewButtons;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.main);

        Button toTheSee = (Button)findViewById(R.id.toTheSee);
        toTheSee.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                String message = "toTheSea";
                serverThread.broadcastMessageToAllClients(message);
            }
        });

        Button toAnotherLocation = (Button)findViewById(R.id.toAnotherLocation);
        toAnotherLocation.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                String message = "toAnotherLocation";
                serverThread.broadcastMessageToAllClients(message);
            }
        });

        Button behindTheWalls = (Button)findViewById(R.id.behindTheWalls);
        behindTheWalls.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                String message = "behindTheWalls";
                serverThread.broadcastMessageToAllClients(message);
            }
        });

        serverThread = new ServerThread();
        Thread thread = new Thread(serverThread);
        thread.start();

    }

    @Override
    public boolean onCreateOptionsMenu(Menu menu) {
        // Inflate the menu; this adds items to the action bar if it is present.
        getMenuInflater().inflate(R.menu.menu_main, menu);
        return true;
    }

    @Override
    public boolean onOptionsItemSelected(MenuItem item) {
        // Handle action bar item clicks here. The action bar will
        // automatically handle clicks on the Home/Up button, so long
        // as you specify a parent activity in AndroidManifest.xml.
        int id = item.getItemId();

        //noinspection SimplifiableIfStatement
        if (id == R.id.action_settings) {
            return true;
        }

        return super.onOptionsItemSelected(item);
    }
}
