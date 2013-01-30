package com.example.ilikeyou.network;


public class HttpGetParams {
	public HttpGetParams(String url, ExecutionHandler handler) {
		this.url = url;
		this.handler = handler;
		
	}
	private String url;
	private ExecutionHandler handler;
	
	public String getUrl() {
		return url;
	}
	
	public ExecutionHandler getHandler() {
		return handler;
	}

}
