/* Ghidra pseudocode, not original source.
 * ev_35392dc412ffe2b2a558f5a6ba3fa7479ff279a31c4c87c94d67c76968103d24
 * Entry: 0x615e90; label: FUN_00615e90
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_00615e90(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int in_ECX;
  int iVar3;
  
  iVar1 = *(int *)(in_ECX + 4);
  if (iVar1 != 0) {
    if (*(int *)(iVar1 + 4) == 0) {
      iVar3 = 0;
    }
    else {
      iVar3 = 0x4af - *(int *)(iVar1 + 0xc);
    }
    if (iVar3 < param_1) {
      FUN_006153c0(iVar1,in_ECX,1);
      iVar1 = *(int *)(in_ECX + 4);
      if (iVar1 != 0) {
        iVar3 = *(int *)(iVar1 + 4);
        if (iVar3 != 0) {
          if (*(uint *)(iVar3 + 0x4b0) < 2) {
            *(undefined4 *)(iVar3 + 0x4b0) = 0;
          }
          else {
            *(uint *)(iVar3 + 0x4b0) = *(uint *)(iVar3 + 0x4b0) - 1;
          }
        }
        FUN_006334d0(iVar1,0x10);
      }
      *(undefined4 *)(in_ECX + 4) = 0;
    }
  }
  if (*(int *)(in_ECX + 4) == 0) {
    iVar1 = FUN_00633440(0x10,1);
    if (iVar1 != 0) {
      uVar2 = FUN_0053d5d0(0x20);
      *(undefined4 *)(in_ECX + 4) = uVar2;
      return uVar2;
    }
    *(undefined4 *)(in_ECX + 4) = 0;
  }
  return *(undefined4 *)(in_ECX + 4);
}

