#include <curl/curl.h>

int main() {
	CURL *curl = curl_easy_init();
	if(curl) {
		curl_easy_setopt(curl, CURLOPT_URL, "https://username:password@account.cloudant.com/test");

		struct curl_slist *chunk = NULL;
		chunk = curl_slist_append(chunk, "Content-Type: application/json");
		curl_easy_setopt(curl, CURLOPT_HTTPHEADER, chunk);

		curl_easy_setopt(curl, CURLOPT_POSTFIELDS, "{\"abc\":123}");

		/* Perform the request */
		curl_easy_perform(curl);

		/* Cleanup */
		curl_easy_cleanup(curl);
	}
	return 0;
}
