#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <openssl/sha.h>

//0x4b 0x65 0x72 0x6e 0x65 0x6c 0x7b 0x66 0x31 0x64 0x39 0x65 0x65 0x34 0x39 0x35 0x66 0x31 0x32 0x64 0x31 0x66 0x31 0x63 0x62 0x38 0x33 0x35 0x34 0x63 0x39 0x66 0x32 0x64
//0x65 0x61 0x65 0x32 0x64 0x7d
//0x62,0x85,0x81,0x50,0xef,0x73,0x51,0xd2,0xf7,0x6d,0xc3,0xeb,0x22,0x8a,0xac,0x80,0x17,0x8b,0x50,0xbb,0x24,0xfb,0xff,0x42,0x9d,0x39,0xc2,0x16,0x93,0x0c,0x16,0x92,0x58,0x96,
//0x69,0xce,0x8e,0xe9,0xed,0x47,0xf3,0x83,0xe2,0x00,0xac,0x2b,0x22,0xf0,0xae,0x2c,0xde,0x03,0x42,0xdc,0xb2,0x6b,0xcb,0x1a,0xa0,0x93,0x92,0x5a,0xfa,0x5f,

char* buff;
void interuptHandler()
{

   exit(0);
}

void CruleAndUnusualExit(int flag)
{
char salt[] ={0x29,0xe0,0xf3,0x3e,0x8a,0x1f,0x2a,0xb4,0xc6,0x09,0xfa,
                      0x8e,0x47,0xbe,0x95,0xb5,0x71,0xba,0x62,0xdf,0x15,0x9d,
                      0xce,0x21,0xff,0x01,0xf1,0x23,0xa7,0x6f,0x2f,0xf4,0x6a,
                      0xf2,0x0c,0xaf,0xeb,0xdb,0x89,0x3a,0xf3,0x83,0xe2,0x00,
                      0xac,0x2b,0x22,0xf0,0xae,0x2c,0xde,0x03,0x42,0xdc,0xb2,
                      0x6b,0xcb,0x1a,0xa0,0x93,0x92,0x5a,0xfa,0x5f};

char CTflag[]= {0x1a,0x18,0x8a,0x18,0x2b,0xb5,0x74,0x13,0xed,0xbd,0xb2,0x8d,0x7d,0x52,0xd3,0x31,0x68,0x59,0xb8,0x78,0x05,0x88,0xe3,0x27,0x29,0x73,0x09,0xcc,0xb8,0x66,0x96,0x37,0xeb,0xe1,0x99,0x6f,0xfe,0x11,0xec,0x12,0x92,0xe1,0x44,0xf3,0xbe,0x07,0xca,0x36,0x9f,0xd7,0x29,0x97,0x81,0x83,0x71,0x9c,0x19,0x6d,0xde,0xc4,0xa6,0xde,0x15,0x29};

signal(SIGINT,interuptHandler);
    if (!flag)
    {
        printf("access: PERMISSION DENIED.");
        fflush(stdout);
        usleep(500000);
        printf("...and...\n");
        while(1)
        {

           usleep(200000);
           printf("YOU DIDN'T CHANGE THE MAGIC PARAMATER!\n");

        }
    }
    else{
    for(int x = 0; x < SHA512_DIGEST_LENGTH; x++)
            {

            *(buff+x)=(unsigned char)(char)*(buff+x) ^ (unsigned char)(char)*(salt+x) ;
            *(buff+x)=(unsigned char)(char)*(buff+x)^(unsigned char)(char)*(CTflag+x) ;
            }
            printf("%s\n",buff);
    }
}

int main()
{

    char* k = malloc(255);
    char* key1 = malloc(SHA512_DIGEST_LENGTH);
    char* key2 = malloc(SHA512_DIGEST_LENGTH);
    char* key3 = malloc(SHA512_DIGEST_LENGTH);
    buff = malloc(SHA512_DIGEST_LENGTH);
    char hash1[] = {0x62,0xeb,0xb9,0xf6,0x23,0x1b,0xcc,0xf6,0x25,0x8e,
                    0x22,0xf7,0x93,0xf4,0xec,0x1f,0xf9,0x75,0xdf,0x1d,
                    0x28,0xfd,0x06,0xe9,0x5e,0x6e,0x96,0x5f,0xe9,0xfc,
                    0xaa,0x7f,0xa6,0x63,0xce,0x94,0x45,0x9a,0x33,0x22,
                    0xbd,0x86,0x81,0x2c,0xf5,0xfd,0x43,0x60,0xbe,0x39,
                    0xb1,0xda,0x5d,0x60,0x6a,0x54,0x5c,0x08,0xed,0x68,
                    0x89,0xfe,0x13,0xfa};
    char hash2[] = {0xeb,0x38,0x4b,0x9b,0x87,0xb4,0x5c,0xe3,0x95,0xc3,
                    0x2f,0x5e,0xb0,0x42,0xce,0x83,0x64,0x6c,0x04,0xa7,
                    0xd0,0x89,0x03,0x38,0x1c,0x5d,0x77,0xb4,0x3c,0x0a,
                    0x5a,0x07,0x65,0x28,0xce,0x2c,0x50,0xcb,0xc6,0xfe,
                    0x2d,0x2d,0xdb,0x0d,0x30,0xaf,0x61,0x39,0x65,0x17,
                    0x98,0x30,0xca,0x1d,0x68,0xbd,0x21,0x68,0x39,0xb0,
                    0x18,0xd8,0x8f,0x6d};
    char hash3[] = {0x9b,0xe7,0x07,0x03,0x2b,0x83,0xbf,0x60,0x8a,0xb4,
                    0x46,0x6d,0x0f,0x6a,0x31,0xc3,0xf2,0xef,0x99,0xb4,
                    0xbf,0x06,0x47,0xfc,0x11,0x1f,0x83,0x47,0xd7,0x4b,
                    0x96,0x1d,0xf8,0xa0,0x97,0x37,0xdb,0xf2,0x44,0x64,
                    0x22,0x88,0x9f,0xe3,0x71,0x3a,0x22,0x6d,0x70,0xdd,
                    0x36,0x25,0x48,0x0c,0x02,0x6d,0xac,0x31,0xb1,0x2c,
                    0xfe,0x0a,0x79,0x48};
    int bool1 = 1;


    SHA512_CTX shactx;
    SHA512_Init(&shactx);
    printf("Jurassic Park, System Security Interface\n");
    printf("Version 4.0.5, Alpha E\n");
    printf("Ready...\n");
        printf("> ");
        fgets(k,255,stdin);
        *(k+strlen(k))=0x00;
        SHA512_Update(&shactx,k,strlen(k));
        SHA512_Final(key1,&shactx);
        SHA512_Update(&shactx,key1,SHA512_DIGEST_LENGTH);
        SHA512_Final(buff,&shactx);
        for(int x = 0; x < SHA512_DIGEST_LENGTH; x++)
        {
          //  printf("0x%02x,",(unsigned char)(char)*(buff+x));
           bool1 &= (unsigned char)(char)*(hash1+x) == (unsigned char)(char)*(buff+x);
        }

        if(bool1)
        {
            printf("access: PERMISSION DENIED.\n");
            printf("> ");
            fgets(k,255,stdin);
            *(k+strlen(k))=0x00;
            SHA512_Update(&shactx,k,strlen(k));
            SHA512_Final(key2,&shactx);
            SHA512_Update(&shactx,key2,SHA512_DIGEST_LENGTH);
            SHA512_Final(buff,&shactx);
            for(int x = 0; x < SHA512_DIGEST_LENGTH; x++)
            {
                //printf("0x%02x,",(unsigned char)(char)*(buff+x));
               bool1 &= (unsigned char)(char)*(hash2+x) == (unsigned char)(char)*(buff+x);
            }

            if(bool1)
            {
                printf("access: PERMISSION DENIED.\n");
                printf("> ");
                fgets(k,255,stdin);
                *(k+strlen(k))=0x00;
                SHA512_Update(&shactx,k,strlen(k));
                SHA512_Final(key3,&shactx);
                SHA512_Update(&shactx,key3,SHA512_DIGEST_LENGTH);
                SHA512_Final(buff,&shactx);
                for(int x = 0; x < SHA512_DIGEST_LENGTH; x++)
                {
                  // printf("0x%02x,",(unsigned char)(char)*(buff+x));
                   bool1 &= (unsigned char)(char)*(hash3+x) == (unsigned char)(char)*(buff+x);
                }

                if(bool1)
                {
                  for(int x = 0; x < SHA512_DIGEST_LENGTH; x++)
                  {
                    *(buff+x) = (unsigned char)(char)*(key1+x)^(unsigned char)(char)*(key2+x)^(unsigned char)(char)*(key3+x);
                  }
                   CruleAndUnusualExit(0);
                }



            }
        }

    return 0;
}