package com.example.ilikeyou.network;

import java.io.IOException;
import java.util.ArrayList;
import java.util.List;

import org.apache.http.HttpEntity;
import org.apache.http.HttpResponse;
import org.apache.http.NameValuePair;
import org.apache.http.client.ClientProtocolException;
import org.apache.http.client.HttpClient;
import org.apache.http.client.entity.UrlEncodedFormEntity;
import org.apache.http.client.methods.HttpGet;
import org.apache.http.client.methods.HttpPost;
import org.apache.http.impl.client.DefaultHttpClient;
import org.apache.http.message.BasicNameValuePair;
import org.apache.http.protocol.HTTP;
import org.apache.http.util.EntityUtils;

import android.net.TrafficStats;
import android.os.AsyncTask;
import android.util.Log;

public class HttpGetAsyncTask extends
		AsyncTask<HttpGetParams, Void, HttpResponse> {

	private ExecutionHandler handler;

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
		
		try
		{
		        HttpClient client = new DefaultHttpClient();  
		        String postURL = "http://www.snee.com/xml/crud/posttest.html";
		        HttpPost post = new HttpPost(postURL); 
		        List<NameValuePair> params = new ArrayList<NameValuePair>();
		        params.add(new BasicNameValuePair("fnale", "123"));
		        params.add(new BasicNameValuePair("lname", "abc"));
		        UrlEncodedFormEntity ent = new UrlEncodedFormEntity(params,HTTP.UTF_8);
		        post.setEntity(ent);
		        HttpResponse responsePOST = client.execute(post);  
		        HttpEntity resEntity = responsePOST.getEntity();
		        
		        if (resEntity != null)
		        {    
		                Log.i("RESPONSE", EntityUtils.toString(resEntity));
		        }
		}
		catch (Exception e)
		{
		        e.printStackTrace();
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