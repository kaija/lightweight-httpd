#include <evhttp.h>
#include <event.h>
/*
    This program is a simple http server built by evhttp api in libevent library
*/
void routerfnc (struct evhttp_request * req, void * arg) {
	struct evbuffer* databuf;
	const char * reason = "Test Page";
	int code = 200;
	const char * content = "Hello World!";

	databuf = evbuffer_new();
	evbuffer_add_printf(databuf, content);
	//printf("request uri%s\n", evhttp_request_uri(req));
	evhttp_send_reply(req, code, reason, databuf);
	evbuffer_free(databuf);
}

int main () {
	struct event_base * base;
	struct evhttp * evh;
	const char* addr = "localhost";
	int http_srv_fd;
	u_short port = 5050;

	base = event_init();
	evh = evhttp_new(base);
	http_srv_fd = evhttp_bind_socket(evh, addr, port);

	if (http_srv_fd == -1) {
		printf("evhttp_bind_socket error");
	}else {
		evhttp_set_gencb(evh, routerfnc, NULL);
		event_base_dispatch(base);
	}
}
