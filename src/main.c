#include <stdio.h>
#include <curl/curl.h>

static int data = 123;
static size_t write_data(void *buffer, size_t size, size_t nmemb, void *userp);

int main(int argc, char **argv)
{
  CURLcode code = curl_global_init(CURL_GLOBAL_SSL);
  printf("Hello from main!\n");

  CURL *const easyhandle = curl_easy_init();
  curl_easy_setopt(easyhandle, CURLOPT_URL, "https://www.google.co.uk");
  curl_easy_setopt(easyhandle, CURLOPT_WRITEFUNCTION, write_data);
  curl_easy_setopt(easyhandle, CURLOPT_WRITEDATA, &data);
  curl_easy_setopt(easyhandle, CURLOPT_VERBOSE, 1);
  curl_easy_setopt(easyhandle, CURLOPT_SSL_VERIFYPEER, 0L);
  curl_easy_setopt(easyhandle, CURLOPT_SSL_VERIFYHOST, 0L);
//  curl_easy_setopt(easyhandle, CURLOPT_PROXY, "");
  int i;
  for (i = 0; i < 1; ++i) {
    const int success = curl_easy_perform(easyhandle);
    printf("Finished:%d\n", success);
  }

  // clean-up
  curl_easy_cleanup(easyhandle);
  curl_global_cleanup();
  return 0;
}

size_t write_data(void *buffer, size_t size, size_t nmemb, void *userp)
{
  printf("Size:%d, %d\n", (int)size, (int)nmemb);
  printf("Block:[%s]\n", (const char *)buffer);
  if (buffer) {
    const char ch1 = *((const char *)buffer);
    printf("Data: [0x%x]:[%c]\n", ch1, ch1);
  } else {
    printf("Null buffer pointer\n");
  }
  printf("Pointers: %p : %p\n", userp, &data);
  return nmemb;
}
