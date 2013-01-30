package com.example.ilikeyou;

import java.io.IOException;
import java.util.List;

import org.apache.http.HttpEntity;
import org.apache.http.ParseException;
import org.apache.http.util.EntityUtils;

import android.animation.Animator;
import android.animation.AnimatorListenerAdapter;
import android.annotation.TargetApi;
import android.app.Activity;
import android.content.Intent;
import android.os.Build;
import android.os.Bundle;
import android.os.StrictMode;
import android.view.Menu;
import android.view.View;
import android.widget.EditText;

import com.example.ilikeyou.network.HttpGetAsyncTask;
import com.example.ilikeyou.network.HttpGetParams;
import com.example.ilikeyou.network.PostExecHandler;
import com.facebook.Request;
import com.facebook.Response;
import com.facebook.Session;
import com.facebook.SessionState;
import com.facebook.model.GraphUser;

public class ProfileActivity extends Activity implements PostExecHandler {

	private HttpGetAsyncTask mHttpGetTask;
	private View mProfileStatusView;
	private View mProfileDetailView;

	@Override
	protected void onCreate(Bundle savedInstanceState) {

		// StrictMode.setThreadPolicy(new StrictMode.ThreadPolicy.Builder()
		// .detectDiskReads()
		// .detectDiskWrites()
		// .detectNetwork()
		// .penaltyLog()
		// .build());

		// or
		StrictMode.enableDefaults();

		super.onCreate(savedInstanceState);
		setContentView(R.layout.activity_profile);
		
		
		mProfileStatusView = findViewById(R.id.profile_status);
		mProfileDetailView = findViewById(R.id.profile_detail);

		
		findViewById(R.id.get_profile_button).setOnClickListener(
				new View.OnClickListener() {
					@Override
					public void onClick(View view) {
						showProgress(true);
						mHttpGetTask = new HttpGetAsyncTask();
						mHttpGetTask.execute(new HttpGetParams("http://www.daum.net", ProfileActivity.this));
					}
				});
		
		findViewById(R.id.get_facebook_friendlist_button).setOnClickListener(
				new View.OnClickListener() {

					@Override
					public void onClick(View v) {
						// start Facebook Login
						Session.openActiveSession(ProfileActivity.this, true, new Session.StatusCallback() {

							// callback when session changes state
							@Override
							public void call(Session session, SessionState state, Exception exception) {
								if (session.isOpened()) {
									// get Friends list
									Request.executeMyFriendsRequestAsync(session, new Request.GraphUserListCallback() {

										@Override
										public void onCompleted(List<GraphUser> users, Response response) {
											String FriendList = "";
											if (users != null) {
												for(int i=0; i<users.size(); i++) {
													FriendList += users.get(i).getName() + ", " + users.get(i).getId() + "\n";
												}
												EditText detail = (EditText) findViewById(R.id.profile_detail_text);
												if(detail != null) {
													detail.setText(FriendList);
												}
											}
										}
									});
								}
							}
						});


					}
				}
		);
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


	@Override
	public void run(HttpEntity entity) {
		
		EditText detail = (EditText) findViewById(R.id.profile_detail_text);

		if (detail != null) {
			try {
				detail.setText(EntityUtils.toString(entity));
			} catch (ParseException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			} catch (IOException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			} finally {
				mHttpGetTask = null;
				showProgress(false);
			}
		}
	}
	
	/**
	 * Shows the progress UI and hides the login form.
	 */
	@TargetApi(Build.VERSION_CODES.HONEYCOMB_MR2)
	private void showProgress(final boolean show) {
		// On Honeycomb MR2 we have the ViewPropertyAnimator APIs, which allow
		// for very easy animations. If available, use these APIs to fade-in
		// the progress spinner.
		if (Build.VERSION.SDK_INT >= Build.VERSION_CODES.HONEYCOMB_MR2) {
			int shortAnimTime = getResources().getInteger(
					android.R.integer.config_shortAnimTime);

			
			mProfileStatusView.setVisibility(View.VISIBLE);
			mProfileStatusView.animate().setDuration(shortAnimTime)
					.alpha(show ? 1 : 0)
					.setListener(new AnimatorListenerAdapter() {
						@Override
						public void onAnimationEnd(Animator animation) {
							mProfileStatusView.setVisibility(show ? View.VISIBLE
									: View.GONE);
						}
					});
			
			mProfileDetailView.setVisibility(View.VISIBLE);
			mProfileDetailView.animate().setDuration(shortAnimTime)
					.alpha(show ? 0 : 1)
					.setListener(new AnimatorListenerAdapter() {
						@Override
						public void onAnimationEnd(Animator animation) {
							mProfileDetailView.setVisibility(show ? View.GONE
									: View.VISIBLE);
						}
					});
					
		} else {
			// The ViewPropertyAnimator APIs are not available, so simply show
			// and hide the relevant UI components.
			
			mProfileStatusView.setVisibility(show ? View.VISIBLE : View.GONE);
			
			mProfileDetailView.setVisibility(show ? View.GONE : View.VISIBLE);
			
		}
	}
}
>>>>>>> b7cf955d50905e8e80d6cf0bc29ce34a6a45fef7
