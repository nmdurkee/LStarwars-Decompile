/* Ghidra pseudocode, not original source.
 * ev_089833714d61d65eb350d99c3da767c9514a7b314bb0b1f84b7d509473600b9f
 * Entry: 0x627ee0; label: FUN_00627ee0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00627ee0(undefined4 param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_00627da0(param_1,param_2,FUN_00627d40);
  if (iVar1 != 0) {
    FUN_004f1f10(iVar1 + 0x4c,*(undefined4 *)(param_2 + 100));
    uVar2 = FUN_004f1ff0(iVar1 + 0x4c);
    *(undefined4 *)(iVar1 + 0x154) = uVar2;
    *(undefined4 *)(iVar1 + 0x28) = *(undefined4 *)(param_2 + 0x28);
    *(undefined4 *)(iVar1 + 0x2c) = *(undefined4 *)(param_2 + 0x2c);
    *(undefined4 *)(iVar1 + 0x30) = *(undefined4 *)(param_2 + 0x30);
    *(undefined4 *)(iVar1 + 0x34) = *(undefined4 *)(param_2 + 0x34);
  }
  return;
}

