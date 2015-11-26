#include <stdio.h>
#include <curl/curl.h>

int main(int argc, char **argv)
{
  CURLcode code = curl_global_init(CURL_GLOBAL_SSL);
  printf("Hello from main!\n");

  // clean-up
  curl_global_cleanup();
  return 0;
}
