/* Ghidra analysis pseudocode, not original source.
 * ev_fba68665c2ecb02d4c13d026ba12834cd95aaa1020801387b253bb991a5bde4e
 * Entry: 0x4e3810; label: FUN_004e3810
 */

void FUN_004e3810(int param_1)

{
  int iVar1;
  
  if (param_1 == DAT_008895c0) {
    iVar1 = 0;
  }
  else {
    if (param_1 != DAT_008895c4) {
      return;
    }
    iVar1 = 1;
  }
  if (param_1 != 0) {
    if (DAT_008000a8 != -1) {
      FUN_0056a8c0(PTR_DAT_00802c54,DAT_008000a8,param_1 + 0x30);
    }
    FUN_005cfc00(&DAT_0087aad8 + iVar1 * 3,0);
    *(undefined4 *)((&DAT_0087a810)[iVar1] + 0x4c) = 0;
    *(uint *)((&DAT_0087a810)[iVar1] + 0x50) = *(uint *)((&DAT_0087a810)[iVar1] + 0x50) & 0xfffffffe
    ;
    (&DAT_008895c0)[iVar1] = 0;
  }
  return;
}

