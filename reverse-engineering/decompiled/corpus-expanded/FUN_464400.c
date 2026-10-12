/* Ghidra pseudocode, not original source.
 * ev_8835491dd236cf2d19dd2fa5a5f724a0610b648b7dd0bb4146e1223777a8cf17
 * Entry: 0x464400; label: FUN_00464400
 * Boundary hypotheses: reports/native-boundary-seeds.json.
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

