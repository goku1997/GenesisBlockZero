#include <stdio.h>
#include "sha256.h"

unsigned char *SHA256(const unsigned char *d, size_t n,unsigned char *md) {
  CSHA256 bob;
  bob.Write(d,n);
  bob.Finalize(md);
  return md;
}

//msg: 00CDF9B24885C203B8F2C7939DABE2D5F6668C0C9C
//hsh: 0B49BA51CE57043361EB1DC5D7779DADE79D23C61F679A90EBABE48B39CFFBCC
//msg: 0B49BA51CE57043361EB1DC5D7779DADE79D23C61F679A90EBABE48B39CFFBCC
//hsh: 6A57B86D3FB0203A6111CFD765410CABFB506C2788BF1D9888AD321AE2023262

//5184BCF58C538C38B26535897BB35EA2D22CA8BF81FC5F3C0254677049A7B2B4

int main() {
	int i;
	uint8_t out[0x20];
	SHA256((const unsigned char *)"\x00\xCD\xF9\xB2\x48\x85\xC2\x03\xB8\xF2\xC7\x93\x9D\xAB\xE2\xD5\xF6\x66\x8C\x0C\x9C", 20, out);
	for (i=0;i<0x20;i++) { printf("%02X", out[i]); } printf("\n");
	return 0;
}