/* Ghidra pseudocode, not original source.
 * ev_a061266dd45b392e87f7d3689b136f273b070abf9372dc393200501f91b0ff88
 * Entry: 0x6eccca; label: __clearfp
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Removing unreachable block (ram,0x006ecd54) */
/* WARNING: Removing unreachable block (ram,0x006ecd44) */
/* WARNING: Removing unreachable block (ram,0x006ecd34) */
/* WARNING: Removing unreachable block (ram,0x006ecd2f) */
/* WARNING: Removing unreachable block (ram,0x006ecd37) */
/* WARNING: Removing unreachable block (ram,0x006ecd3c) */
/* WARNING: Removing unreachable block (ram,0x006ecd3f) */
/* WARNING: Removing unreachable block (ram,0x006ecd47) */
/* WARNING: Removing unreachable block (ram,0x006ecd4c) */
/* WARNING: Removing unreachable block (ram,0x006ecd4f) */
/* WARNING: Removing unreachable block (ram,0x006ecd57) */
/* WARNING: Removing unreachable block (ram,0x006ecd5c) */
/* Library Function - Single Match
    __clearfp
   
   Library: Visual Studio 2005 Release */

uint __cdecl __clearfp(void)

{
  uint uVar1;
  ushort in_FPUStatusWord;
  
  if (DAT_029a9c48 == 0) {
    uVar1 = 0;
    if ((in_FPUStatusWord & 0x3f) != 0) {
      if ((in_FPUStatusWord & 1) != 0) {
        uVar1 = 0x10;
      }
      if ((in_FPUStatusWord & 4) != 0) {
        uVar1 = uVar1 | 8;
      }
      if ((in_FPUStatusWord & 8) != 0) {
        uVar1 = uVar1 | 4;
      }
      if ((in_FPUStatusWord & 0x10) != 0) {
        uVar1 = uVar1 | 2;
      }
      if ((in_FPUStatusWord & 0x20) != 0) {
        uVar1 = uVar1 | 1;
      }
      if ((in_FPUStatusWord & 2) != 0) {
        uVar1 = uVar1 | 0x80000;
      }
    }
    return uVar1;
  }
  uVar1 = 0;
  if ((in_FPUStatusWord & 0x3f) != 0) {
    if ((in_FPUStatusWord & 1) != 0) {
      uVar1 = 0x10;
    }
    if ((in_FPUStatusWord & 4) != 0) {
      uVar1 = uVar1 | 8;
    }
    if ((in_FPUStatusWord & 8) != 0) {
      uVar1 = uVar1 | 4;
    }
    if ((in_FPUStatusWord & 0x10) != 0) {
      uVar1 = uVar1 | 2;
    }
    if ((in_FPUStatusWord & 0x20) != 0) {
      uVar1 = uVar1 | 1;
    }
    if ((in_FPUStatusWord & 2) != 0) {
      uVar1 = uVar1 | 0x80000;
    }
  }
  MXCSR = MXCSR & 0xffffffc0;
  return uVar1;
}

