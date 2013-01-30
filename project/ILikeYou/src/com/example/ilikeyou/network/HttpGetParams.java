package com.example.ilikeyou.network;


public class HttpGetParams {
	public HttpGetParams(String url, PostExecHandler handler) {
		this.url = url;
		this.handler = handler;
		
	}
	private String url;
	private PostExecHandler handler;
	
	public String getUrl() {
		return url;
	}
	
	public PostExecHandler getHandler() {
		return handler;
	}

}
