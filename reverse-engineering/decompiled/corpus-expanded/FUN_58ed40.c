/* Ghidra pseudocode, not original source.
 * ev_d7fef5854a4ea50d405948ed3aa82c9004ffbc8626dda7a7f3cbba7e59036064
 * Entry: 0x58ed40; label: FUN_0058ed40
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0058ed40(int param_1,undefined4 param_2)

{
  byte bVar1;
  uint uVar2;
  
  bVar1 = *(byte *)(param_1 + 0x6c);
  if (bVar1 != 0) {
    uVar2 = (uint)*(byte *)(param_1 + 0x6f);
    if (bVar1 <= uVar2) {
      uVar2 = bVar1 - 1;
    }
    FUN_0058bee0(param_2,*(int *)(*(int *)(*(int *)(param_1 + 0x14) + uVar2 * 4) + 0x24) + 0x30,0,
                 0x40000000,0x3f800000,0x40000000);
  }
  return;
}

