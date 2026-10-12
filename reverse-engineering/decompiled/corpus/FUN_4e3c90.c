/* Ghidra analysis pseudocode, not original source.
 * ev_fba68665c2ecb02d4c13d026ba12834cd95aaa1020801387b253bb991a5bde4e
 * Entry: 0x4e3c90; label: FUN_004e3c90
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004e3c90(void)

{
  uint *puVar1;
  int in_EAX;
  int iVar2;
  undefined1 *puVar3;
  int local_4b4;
  undefined1 local_4b0 [1200];
  
  iVar2 = FUN_0051adf0(*(int *)(in_EAX + 0x2ae8),
                       *(undefined4 *)(*(int *)(*(int *)(in_EAX + 0x2ae8) + 0x10) + 8),"Block1_a",
                       "Block1_b",&local_4b4);
  if (iVar2 != 0) {
    puVar1 = (uint *)(iVar2 + local_4b4 * 4);
    *puVar1 = *puVar1 | 0x80000000;
  }
  DAT_008895dc = FUN_00468710();
  DAT_008895e0 = FUN_00468710();
  _DAT_008895e4 = FUN_00468710();
  _DAT_008895e8 = FUN_00468710();
  _DAT_008895d4 = _DAT_008000bc;
  DAT_008895d8 = 1;
  FUN_005ab050(DAT_0095df4c,"InControlRoom",0x3f800000,DAT_008895c8);
  FUN_005ab050(DAT_0095df4c,"ceiling_collapse",0x3f800000,DAT_008895cc);
  iVar2 = FUN_005cf8a0(*(undefined4 *)(in_EAX + 0x13c),local_4b0,"wobble",100,0);
  if (0 < iVar2) {
    puVar3 = local_4b0;
    do {
      FUN_005cfc00(puVar3,0);
      puVar3 = puVar3 + 0xc;
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
  }
  return;
}

