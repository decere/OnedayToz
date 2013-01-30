package com.example.ilikeyou.network;

import org.apache.http.HttpEntity;

public interface ExecutionHandler {
	void run(HttpEntity entity);
}
