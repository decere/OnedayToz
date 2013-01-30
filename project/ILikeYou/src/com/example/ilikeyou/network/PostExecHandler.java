package com.example.ilikeyou.network;

import org.apache.http.HttpEntity;

public interface PostExecHandler {
	void run(HttpEntity entity);
}
