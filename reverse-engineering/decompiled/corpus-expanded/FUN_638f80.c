/* Ghidra pseudocode, not original source.
 * ev_a84f6211ef148f15ea828e3da9a2e76ee785c1544a3c74f6da418557eb34fa98
 * Entry: 0x638f80; label: FUN_00638f80
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00638f80(undefined4 param_1,int param_2)

{
  undefined4 uVar1;
  int iVar2;
  
  iVar2 = DAT_029134f0;
  uVar1 = *(undefined4 *)(param_2 + 0x54);
  if (DAT_029134f0 != 0) {
    *(undefined4 *)(DAT_029134f0 + 0x5c) = uVar1;
    FUN_0061d810(iVar2,*(undefined4 *)(iVar2 + 0x54),0,0);
  }
  iVar2 = DAT_029138a4;
  if (DAT_029138a4 != 0) {
    *(undefined4 *)(DAT_029138a4 + 0x5c) = uVar1;
    FUN_0061d810(iVar2,*(undefined4 *)(iVar2 + 0x54),0,0);
  }
  iVar2 = DAT_02913544;
  if (DAT_02913544 != 0) {
    *(undefined4 *)(DAT_02913544 + 0x5c) = uVar1;
    FUN_0061d810(iVar2,*(undefined4 *)(iVar2 + 0x54),0,0);
  }
  iVar2 = DAT_029134ec;
  if (DAT_029134ec != 0) {
    *(undefined4 *)(DAT_029134ec + 0x5c) = uVar1;
    FUN_0061d810(iVar2,*(undefined4 *)(iVar2 + 0x54),0,0);
  }
  return;
}

