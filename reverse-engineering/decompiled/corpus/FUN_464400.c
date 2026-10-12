/* Ghidra analysis pseudocode, not original source.
 * ev_ca54e982c9f1bc50e375bb5e2806226defe8bc9769d9e20e94a8e2507c387560
 * Entry: 0x464400; label: FUN_00464400
 */

void FUN_00464400(undefined4 param_1,undefined4 param_2,int param_3,int param_4)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  
  iVar4 = 0;
  iVar3 = 0;
  if (0 < param_4) {
    do {
      iVar1 = FUN_004f8a70(*(undefined4 *)(param_3 + iVar4 * 4),"part_effect");
      if (iVar1 == 0) {
        FUN_004f8b10(*(undefined4 *)(param_3 + iVar4 * 4),"FALSE");
      }
      else {
        iVar3 = FUN_004f1ff0("part_effect");
        iVar3 = iVar3 + 1 + iVar1;
      }
      iVar4 = iVar4 + 1;
    } while (iVar4 < param_4);
    if (iVar3 != 0) {
      uVar2 = FUN_0064afd0(iVar3);
      FUN_0064b370(uVar2,DAT_0093d7f0 + 0x80,0x32);
    }
  }
  return;
}

