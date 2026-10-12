/* Ghidra pseudocode, not original source.
 * ev_071b5a91353aec3b9b3ca880d0ad8ff1dbba963601d7a5f67d3b8ab6c7f681aa
 * Entry: 0x6ec9b2; label: __statusfp
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* Library Function - Single Match
    __statusfp
   
   Library: Visual Studio 2005 Release */

uint __cdecl __statusfp(void)

{
  uint uVar1;
  uint uVar2;
  ushort in_FPUStatusWord;
  
  uVar2 = 0;
  if ((in_FPUStatusWord & 0x3f) != 0) {
    if ((in_FPUStatusWord & 1) != 0) {
      uVar2 = 0x10;
    }
    if ((in_FPUStatusWord & 4) != 0) {
      uVar2 = uVar2 | 8;
    }
    if ((in_FPUStatusWord & 8) != 0) {
      uVar2 = uVar2 | 4;
    }
    if ((in_FPUStatusWord & 0x10) != 0) {
      uVar2 = uVar2 | 2;
    }
    if ((in_FPUStatusWord & 0x20) != 0) {
      uVar2 = uVar2 | 1;
    }
    if ((in_FPUStatusWord & 2) != 0) {
      uVar2 = uVar2 | 0x80000;
    }
  }
  if (DAT_029a9c48 != 0) {
    uVar1 = 0;
    if ((MXCSR & 0x3f) != 0) {
      if ((MXCSR & 1) != 0) {
        uVar1 = 0x10;
      }
      if ((MXCSR & 4) != 0) {
        uVar1 = uVar1 | 8;
      }
      if ((MXCSR & 8) != 0) {
        uVar1 = uVar1 | 4;
      }
      if ((MXCSR & 0x10) != 0) {
        uVar1 = uVar1 | 2;
      }
      if ((MXCSR & 0x20) != 0) {
        uVar1 = uVar1 | 1;
      }
      if ((MXCSR & 2) != 0) {
        uVar1 = uVar1 | 0x80000;
      }
    }
    uVar2 = uVar1 | uVar2;
  }
  return uVar2;
}

