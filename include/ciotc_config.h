const char *ssid = "tid51m";
const char *password = "audiovisualHQ2020";
 
// Cloud iot details.
const char *project_id = "directed-will-245201";
const char *location = "us-central1";
const char *registry_id = "esp32Reg";
const char *device_id = "esp32";
 
// Configuration for NTP
const char* ntp_primary = "pool.ntp.org";
const char* ntp_secondary = "time.nist.gov";
 
#ifndef LED_BUILTIN
#define LED_BUILTIN 13
#endif
 
const char *private_key_str =
    "-----BEGIN PRIVATE KEY-----\n"
"MIIEvgIBADANBgkqhkiG9w0BAQEFAASCBKgwggSkAgEAAoIBAQDWe/zXEsWRZs+X\n"
"RIAgehyj4hO2sbkcyZtGtf48LvF7xJ06Lb2oSpMCAKsuIllkhtdmxGJ67wGys7Ou\n"
"axFOSFo4qRVoqaf38u53EqUE5V3U1mJ15yg9btBRdFZQyabu9UyY+YsVnCl1EBBB\n"
"0sD3oth84rBUazAV6DZI5bc+jr9EjFrwWWM2y72qYFil45uMXyZLOHB2A55atf/8\n"
"k4n5zBChYFdUBdm6fflXT/yTSzRKJOlbvAzaQvV7qt031WMwK678cQtwhBZA/t9l\n"
"H4UE9YslW9RwxTa2dECvP1XaaZUNUx3AafmKTRsl5NJ+SLIdUg85+6KFSndZFZ6P\n"
"mKyyqb7ZAgMBAAECggEACW6WZdbbfVNqGZrXj5YPIF3WxBf4rf1nqKpkLb1avTie\n"
"OWq9hmMRJ+tjm7nC+Jq9ajWEpydPic5BPpBSyICCBy/YUyvyyQKT3gSh4R89CxkK\n"
"Z2js6havboWRLihQAP4kii2fIiol4JH+RQbBmaI9pvBJFM1J5gy6JmaDsmqQmrEE\n"
"ubjrJJnosVaXMmb2FKAkx9rXfI1AGQaWcjfosKmyBtrfstCSbkoyyLWEJbyulLil\n"
"LpNcIyj1vx/ozLZVAwvrLmNwBG3Q++ZX+PLPRae5aNDlkCZWC2Fkw19PAWKhS+00\n"
"z+++hrQtzZlaPT2rGzT///2d2SW0JGeGuLLnizY6IQKBgQD98kyp4xDVoOiZBgeu\n"
"XhRuGO+1mWKBug2KAIVoWdw8J6ohS/7cZpuyX6D2XeHAh+XWrvi3QSFS48v1vpqg\n"
"AgD4PikVcTaYFZ9+IfsT6AuQ6SVTS+pc2zcE4VdKXP+1oibPi6jhWL8G6ZMxIvo+\n"
"F3adzmsmmbaNDnqDV/z8xrkrJQKBgQDYN/8lNLmMQauTelwmbBh+/eja5LxptH6U\n"
"0ynDxb40AS6ckMwTR79cj40xn2Xe7/jodlpG+/zHtysf6ZWRfgdXI0+93s6Fp/fR\n"
"mk0a6MXRrphbvlt0nlqIqSAmboXhrb+xadLRn/5PxQKWpQqO8ta3gXMvdgKoMcOC\n"
"8oioGDIwpQKBgQCkGqNeGaU0WCJXWOU30gYjy6uEUBWvPXsoVgPgFknS+dLgZ4rQ\n"
"BOLSlyeebbbIQ0nMvQ9u5QDS3vBb4wtrIUBdK1ZDTAD6sOZ7jRwCli57O57qQCG4\n"
"VdUtKy3MmWKJjrrD3j2JOl9f6Ss8Up0h6Om3OsBVlnm4l8WmAQM0mnronQKBgQCA\n"
"heiYCRsyD+cZJuaXwDFfazZ6xvRoMO39MPfmcyh4aSt3zWpBG6jYMExRbtpzBloC\n"
"dDd9clPzsyFjOsm5Thy24zqHNmW0dP+ODBZBJJRR62KNRj2+uFJAYafGsHPMjicg\n"
"IjM6f8v/RrAfM8Nu7VJMihoZ4B/8Mnhw4hHxOVC8MQKBgHom/8GU2EHQ3gs538PA\n"
"fNMDAXpUIKNG/xKrmdRF3ECHjHCSC5JoZzY2FtyN4iiGn8oFvhS0UnyjDh7ztP75\n"
"3CZTGIJOdcysP2HMOWa8/oPPrlJCqRF1ZfUi+03NA1SOlM7928wDUOLaujlzgNTs\n"
"24wHLDeyMgGPolo8MHBoMUto\n"
"-----END PRIVATE KEY-----\n";
 
// Time (seconds) to expire token += 20 minutes for drift
const int jwt_exp_secs = 3600; // Maximum 24H (3600*24)
 
const char *root_cert =

"-----BEGIN CERTIFICATE-----\n"
"MIIDAzCCAeugAwIBAgIUbLPQjuOhYseFn7NolJK+ln1KP2kwDQYJKoZIhvcNAQEL\n"
"BQAwETEPMA0GA1UEAwwGdW51c2VkMB4XDTIwMDMwNDE3NTY0M1oXDTIwMDQwMzE3\n"
"NTY0M1owETEPMA0GA1UEAwwGdW51c2VkMIIBIjANBgkqhkiG9w0BAQEFAAOCAQ8A\n"
"MIIBCgKCAQEA1nv81xLFkWbPl0SAIHoco+ITtrG5HMmbRrX+PC7xe8SdOi29qEqT\n"
"AgCrLiJZZIbXZsRieu8BsrOzrmsRTkhaOKkVaKmn9/LudxKlBOVd1NZidecoPW7Q\n"
"UXRWUMmm7vVMmPmLFZwpdRAQQdLA96LYfOKwVGswFeg2SOW3Po6/RIxa8FljNsu9\n"
"qmBYpeObjF8mSzhwdgOeWrX//JOJ+cwQoWBXVAXZun35V0/8k0s0SiTpW7wM2kL1\n"
"e6rdN9VjMCuu/HELcIQWQP7fZR+FBPWLJVvUcMU2tnRArz9V2mmVDVMdwGn5ik0b\n"
"JeTSfkiyHVIPOfuihUp3WRWej5issqm+2QIDAQABo1MwUTAdBgNVHQ4EFgQUDynC\n"
"mQMNpto+VujAZDPiw650zpIwHwYDVR0jBBgwFoAUDynCmQMNpto+VujAZDPiw650\n"
"zpIwDwYDVR0TAQH/BAUwAwEB/zANBgkqhkiG9w0BAQsFAAOCAQEAIS6yVjNCCFPl\n"
"a6b1bABLhcayLnw68kZmTh+6qQ9jMcsE73ZLtc0K9ORT8Ba0VZxCOuyJ/b1GbtIp\n"
"Qk8bLT0Qf0I3VIjbRip8HXhB/e1sODbf1Uz43tSy4HWL3oMcbGfSRzqfSvmyhe87\n"
"Muo9fj66PvgdiQlX2q/MYa5FYWzbyjs/ghJoBy4RI6bpEYl2hYRyod3vzLUKcpMV\n"
"DvrYnKfCHROitlXYqnr48OsEYiuBmAjXYE5Bfq7VA0F+XDxmIUw2aAv5+zS9dxFf\n"
"L/hJMjZHBD3iKgJn+erg/QynSQcVQrkqxpDLcuNk8EZFssynWFK3HV4hvUqUt4mx\n"
"SBw36oRlIA==\n"
"-----END CERTIFICATE-----\n";