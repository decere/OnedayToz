package com.example.ilikeyou.network;

import java.io.IOException;

import org.apache.http.HttpResponse;
import org.apache.http.client.ClientProtocolException;
import org.apache.http.client.HttpClient;
import org.apache.http.client.methods.HttpGet;
import org.apache.http.impl.client.DefaultHttpClient;

import android.net.TrafficStats;
import android.os.AsyncTask;

public class HttpGetAsyncTask extends
		AsyncTask<HttpGetParams, Void, HttpResponse> {

	private PostExecHandler handler;

	@Override
	protected HttpResponse doInBackground(HttpGetParams... httpGetParams) {
		
		HttpResponse responseGet = null;
		String getURL = httpGetParams[0].getUrl();
		handler = httpGetParams[0].getHandler();
		
		
		try {
			// Simulate network access.
			Thread.sleep(500);
		} catch (InterruptedException e) {
			return null;
		}
		
		try {
			TrafficStats.setThreadStatsTag(0xF00D);
			
			HttpClient client = new DefaultHttpClient();
			responseGet = client.execute(new HttpGet(getURL));
		} catch (ClientProtocolException e) {
			e.printStackTrace();
		} catch (IOException e) {
			e.printStackTrace();
		} finally {
			TrafficStats.clearThreadStatsTag();
		}

		return responseGet;
	}

	@Override
	protected void onPostExecute(HttpResponse result) {
		try {
			handler.run(result.getEntity());
		} catch (IllegalStateException e) {
			e.printStackTrace();
		}
	}

}