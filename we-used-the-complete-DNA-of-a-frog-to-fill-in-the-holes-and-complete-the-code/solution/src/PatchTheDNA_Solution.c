/**
    @author Qu3b411 (Jacob Mohrbutter)

    Title: Patch the Dino Dna;
    Description:
    their are 2 strands of "DNA" generated in the DNA file, you must
    disassembe that file to get the dna sequences. the dino dna has
    several calls to HoleInDNA you must replace that Protien sequence with
    the correspondinI function call in the Frog Dna sequence, the following
    a rough example.
    I Have provided you with template macros to create these calls for you in
    DinoDnaSeqPatched, if you so chose to use these macros they will ensure
    proper function calls. the following is an example of a function call

    Dino        | Frog
    ------------+-------
    UUU(0)      | UUC(1)
    GCG(0)      | GUU(1)
    CUU(0)      | GCU(1)
    HoleInDNA(0)| CCU(1)

    would become

    Dino        | Frog
    ------------+-------
    UUU(0)      | UUC(1)
    GCG(0)      | GUU(1)
    CUU(0)      | GCU(1)
    CCU(1)      | CCU(1)

    find all the holes in the dna and after fixing the holes in the
    genetic sequence you will get the kernel flag
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <openssl/md5.h>
#include <openssl/sha.h>


/**
    their are four protiens that exist in the DNA mRNA
    sequence that build the amino acids in living organisms,
    to make it interesting i have assigned different values to these
    sequences between the frog/dino sequence, this is important to remember
    the dinosors dna was patched using frog dna, that means the contestant
    must load the dna sequence where the holes exist, and then they must
    change a boolean value to get the correct return. if the criteria is not
    met then the solution cannot be reached
*/
#define U(type) (type==1) ? 0x2A:0xBE
#define C(type) (type==1) ? 0x45:0x7f
#define A(type) (type==1) ? 0x3c:0x5a
#define G(type) (type==1) ? 0xAF:0x45
/**
    this is the prototype of all the functions
    it creates an amino acid sequence given the
    protiens.
*/
#define dna_template(A_,B_,C_)\
uint32_t A_ ## B_ ## C_  (int Species)\
{\
    uint32_t dna = 0x00000000;\
    if(Species)\
    {\
        dna ^=A_(1);\
        dna <<=8;\
        dna ^=B_(1);\
        dna <<=8;\
        dna ^=C_(1);\
        dna <<=8;\
        dna ^=0xA4;\
    }\
    else\
    {\
        dna ^=A_(0);\
        dna <<=8;\
        dna ^=B_(0);\
        dna <<=8;\
        dna ^=C_(0);\
        dna <<=8;\
        dna ^=0xA4;\
    }\
    return dna;\
}
/**
    the dna_Template_Line creates 4 primitive
    dna_tempates given that the other 2 protines
    in the sequence are accounted for.
*/
#define dna_template_line(A_,B_)\
    dna_template(A_,U,B_);\
    dna_template(A_,C,B_);\
    dna_template(A_,A,B_);\
    dna_template(A_,G,B_)
/**
    the dna_template_block creates 4 dna_template_lines
    or 16 primitive functions in one call given a constent
    protine as the first element.
*/
#define dna_template_block(A_)\
    dna_template_line(A_,U);\
    dna_template_line(A_,C);\
    dna_template_line(A_,A);\
    dna_template_line(A_,G)
#define Dino 0
#define Frog 1

/**
    create all permutations of the protiene
    sequence U**!
*/
dna_template_block(U);
/**
    create all permutations of the protiene
    sequence C**!
*/
dna_template_block(C);
/**
    create all permutations of the protiene
    sequence A**!
*/
dna_template_block(A);
/**
    create all permutations of the protiene
    sequence G**!
*/
dna_template_block(G);
/**
    creates a "hole " in the protiene sequence
    this hole must be patched by frog dna.
    the nth codon "protien sequence" in the frog DNA
    corresponds to the nth codon in the dino DNA
*/
int32_t HoleInDNA(int species)
{
    uint32_t dna = 0x00000000;
    return dna;
}
/**
    generate the Dino's amino acid chain sequence.
*/
uint32_t *DinoDnaSeqPatched()
{
    #define dnaSet(X,Y)\
        *(DNAseq + X) = Y(Dino)
    #define dnaSetFrogPatch(X,Y)\
	*(DNAseq + X) = Y(Frog)
    uint32_t *DNAseq = malloc(64*sizeof(uint32_t));
	/**
		YOU MUST GET THE 64 FUNCTION CALLS TO GENERATE THE DNA SEQUENCE CORRECT IN THIS AREA BEFORE THE RETURN
		ANY CALL TO HoleInDna MUST BE PATCHED WITH FROG DNA!!
	*/
    dnaSet(  0,GUC);dnaSet(  1,CCU);dnaSet(  2,GCU);dnaSet(  3,UGU);dnaSetFrogPatch(  4,GUC);dnaSet(  5,ACA);dnaSet(  6,AAU);dnaSet(  7,GUA);
    dnaSetFrogPatch(  8,GGG);dnaSet(  9,UUU);dnaSet( 10,GAC);dnaSet( 11,CGU);dnaSet( 12,GCC);dnaSet( 13,ACU);dnaSet( 14,GUA);dnaSet( 15,AAA);
    dnaSet( 16,CGG);dnaSet( 17,GCU);dnaSet( 18,UCC);dnaSet( 19,CGC);dnaSetFrogPatch( 20,AGC);dnaSet( 21,ACG);dnaSet( 22,AGG);dnaSet( 23,CUA);
    dnaSet( 24,CAC);dnaSet( 25,GGG);dnaSet( 26,CAU);dnaSetFrogPatch( 27,CUA);dnaSet( 28,UCU);dnaSet( 29,CAU);dnaSet( 30,GUG);dnaSet( 31,UGA);
    dnaSet( 32,GCA);dnaSet( 33,CCC);dnaSetFrogPatch( 34,AGC);dnaSet( 35,UCC);dnaSet( 36,UUC);dnaSet( 37,AGG);dnaSet( 38,AUU);dnaSet( 39,GUC);
    dnaSet( 40,ACG);dnaSetFrogPatch( 41,CUU);dnaSet( 42,GCA);dnaSet( 43,CGC);dnaSet( 44,UCU);dnaSet( 45,UAC);dnaSet( 46,GGA);dnaSet( 47,AUA);
    dnaSet( 48,CGA);dnaSet( 49,GUC);dnaSet( 50,ACG);dnaSet( 51,CCC);dnaSet( 52,CGU);dnaSet( 53,ACC);dnaSet( 54,ACG);dnaSetFrogPatch( 55,GUA);
    dnaSet( 56,ACC);dnaSet( 57,GUG);dnaSet( 58,CUC);dnaSet( 59,AGU);dnaSet( 60,UCC);dnaSetFrogPatch( 61,GCA);dnaSet( 62,GGA);dnaSet( 63,UGC);


	/**
		end of function calls
	*/
    return DNAseq;

    #undef dnaSet
}
/**
    generate the frog's amino acid chain sequence.
*/

/**
    calls DinoDnaSeq and gets a 256 byte string
    md5 hashes the result.
    sha256 hashes the md5,
    if the sha256 hash of the md5 hash == the hard coded sha256 hash
    then
    print the kernel with the md5,
    else
    print a message telling the contestant that the sequence is wrong.

    WARNING: do not modify this function. doing so could result in you not
    being able to retrive the Flag.
*/
int main()
{

    uint32_t *DinoDna = DinoDnaSeqPatched();
    int x ;
    uint8_t* dnabuffer = (uint8_t*)DinoDna;
    SHA256_CTX shactx;
    unsigned char* buff = (unsigned char*)malloc(16);
    unsigned char* shaBuff = (unsigned char*)malloc(SHA256_DIGEST_LENGTH);
    /**********************************DO NOT ***************************************************************
        MODIFY THIS KEY AT ALL!!
        if you do you will not be able to varify that your baby dinos dna was correct, and you will not be
        able to get the Kernel Period.
    **/
     const unsigned char ShaKey[] = {0x2f,0x6,0x2d,0x2e,0x10,0x4c,0x63,0xe6,0xc2,0x5f,0x78,0x5a,0x9c,
     0x33,0x64,0xcf,0xb7,0xe9,0xcb,0xf7,0x51,0xf9,0x1e,0xa9,0xa7,0x35,0xfc,0x22,0x73,0xb6,0x45,0x33};

    int correct=0x01;
    /*
        To Produce the kernel flag we must first get the md5 hash
        of the dna buffer, that will be stored in the buff var.

    */
    MD5_CTX ctx;
    MD5_Init(&ctx);
    MD5_Update(&ctx,(const void*)dnabuffer,256);
    MD5_Final(buff,&ctx);
    /*
          Produce the sha 256 hash of the previous md5 hash, this is to
          varify that the contestant did indeed get the real flag. if this
          flag is false we dont want to be telling them that they got the real
          flag!
    */
    SHA256_Init(&shactx);
    SHA256_Update(&shactx,buff,16);
    SHA256_Final(shaBuff,&shactx);
    //printf("    const unsigned char ShaKey[] = {");
    for (x=0; x<SHA256_DIGEST_LENGTH;x++)
    {
     /*  printf("0x%x",*(shaBuff+x));
       if(x<SHA256_DIGEST_LENGTH-1)
       {
            printf(",");
       }
       else
       {
        printf("};\n");
       }*/
        correct &= (ShaKey[x]==*(shaBuff+x));
    }
    if(correct)
    {
        printf("Kernel{");
        for(x=0;x<MD5_DIGEST_LENGTH;x++)
        {
            printf("%02x",*(buff+x));
        }
        printf("}");
    }
    else
    {
        printf("You did not correct the dna strand, your baby dino is a mutated freek of nature.");
    }
    return 0;
}
