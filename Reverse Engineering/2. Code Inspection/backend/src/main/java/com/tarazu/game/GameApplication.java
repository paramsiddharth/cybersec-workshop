package com.tarazu.game;

import java.io.Serializable;

import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestBody;
import org.springframework.web.bind.annotation.ResponseBody;
import org.springframework.web.bind.annotation.RestController;
import org.springframework.http.ResponseEntity;
import org.springframework.http.HttpStatus;
import org.springframework.http.HttpHeaders;

@SpringBootApplication
@RestController
public class GameApplication {

	public static void main(String[] args) {
		SpringApplication.run(GameApplication.class, args);
	}

	@ResponseBody
	@RequestMapping(path = "/verify", consumes = "application/json", produces = "application/json")
	public ResponseEntity<Resp> verify(@RequestBody final Token token) {
		if ("1QQDZ1Y-8AHMEHM-J33J69X-Q8VXMW3".equals(token.getKey())) {
			return new ResponseEntity<>(new Resp("OK!"), HttpStatus.OK);
		}
		return new ResponseEntity<>(new Resp("Not OK!"), HttpStatus.UNAUTHORIZED);
	}

}

class Token implements Serializable {
	private String key;
	String getKey() { return key; }
	void setKey(String k) { key = k; }
}

class Resp implements Serializable {
	private String msg;
	public String getMsg() { return msg; }
	public void setMsg(String m) { msg = m; }
	Resp(String msg) { this.msg = msg; }
}