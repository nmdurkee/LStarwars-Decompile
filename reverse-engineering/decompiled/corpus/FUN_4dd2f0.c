/* Ghidra analysis pseudocode, not original source.
 * ev_d881831d71d8ed35fa38d5b5eaee7ca2bcae4cde952964886fd1c7ddf43d442a
 * Entry: 0x4dd2f0; label: FUN_004dd2f0
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004dd2f0(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  _DAT_0095df34 = FUN_005806f0("trooper_red",param_1);
  DAT_0095df3c = 0;
  DAT_0095df3d = 0;
  DAT_0095df3e = 0;
  iVar1 = FUN_005cf5b0(*(undefined4 *)(param_1 + 0x13c),&DAT_0087aad8,"minifig_1_1",1);
  iVar2 = FUN_005cf5b0(*(undefined4 *)(param_1 + 0x13c),&DAT_0087aae4,"minifig_1_2",1);
  iVar3 = FUN_005cf5b0(*(undefined4 *)(param_1 + 0x13c),&DAT_0087aaf0,"minifig_1_3",1);
  if (iVar3 + iVar1 + iVar2 == 3) {
    DAT_0095df30 = &DAT_0087aad8;
  }
  return;
}

