package com.onedaytoz.ilikeyou;

import java.util.List;

import com.facebook.*;
import com.facebook.model.*;

import android.os.Bundle;
import android.app.Activity;
import android.view.Menu;

import android.widget.TextView;
import android.content.Intent;


public class MainActivity extends Activity {
	
	/* 397785613644469 */
	/* a9227f39d2e282be9257aa4902549a85 */

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        
        // start Facebook Login
        Session.openActiveSession(this, true, new Session.StatusCallback() {
        	// callback when session changes state
			@Override
			public void call(Session session, SessionState state, Exception exception) {
				if (session.isOpened()) {
					// make request to the /me API
/*					Request.executeMeRequestAsync(session, new Request.GraphUserCallback() {
						// callback after Graph API response with user object
						@Override
						public void onCompleted(GraphUser user, Response response) {
							if (user != null) {
								TextView welcome = (TextView) findViewById(R.id.welcome);
								welcome.setText("Hello " + user.getName() + "!");
							}
						}
					});
*/					
			        // get Friends list
					Request.executeMyFriendsRequestAsync(session, new Request.GraphUserListCallback() {
						
						@Override
						public void onCompleted(List<GraphUser> users, Response response) {
							// TODO Auto-generated method stub
							String FriendList = "";
							if (users != null) {
								for(int i=0; i<users.size(); i++) {
									FriendList += users.get(i).getName() + ", " + users.get(i).getId() + "\n";
								}
								
								GraphUser user;
								user = users.get(0);
								
								/*
								// id field, name filed is only available
								FriendList += user.getBirthday() + "\n"
												+ user.getFirstName() + "\n"
												+ user.getId() + "\n"
												+ user.getLastName() + "\n"
												+ user.getLink() + "\n"
												+ user.getMiddleName() + "\n"
												+ user.getName() + "\n"
												+ user.getUsername() + "\n"
												+ user.toString() + "\n";
								*/
								TextView welcome = (TextView) findViewById(R.id.welcome);
								welcome.setText("Friend List:\n" + FriendList);
							}
						}
					});
				}
			}
        });
    }
    
    @Override
    public void onActivityResult(int requestCode, int resultCode, Intent data) {
        super.onActivityResult(requestCode, resultCode, data);
        Session.getActiveSession().onActivityResult(this, requestCode, resultCode, data);
    }

    @Override
    public boolean onCreateOptionsMenu(Menu menu) {
        // Inflate the menu; this adds items to the action bar if it is present.
        getMenuInflater().inflate(R.menu.activity_main, menu);
        return true;
    }
    
}
