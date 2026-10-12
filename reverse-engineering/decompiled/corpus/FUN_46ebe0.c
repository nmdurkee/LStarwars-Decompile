/* Ghidra analysis pseudocode, not original source.
 * ev_656543c8328aa29e7546f4f9ed4e60ad4c1e465caa45a29e90694e112f58dfef
 * Entry: 0x46ebe0; label: FUN_0046ebe0
 */

void FUN_0046ebe0(int param_1,undefined4 param_2,undefined4 *param_3)

{
  int *piVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  
  if (param_3 != (undefined4 *)0x0) {
    *param_3 = 0;
    param_3[1] = 0xffffffff;
    param_3[2] = 0xffffffff;
    if ((((param_1 != 0) && (piVar1 = *(int **)(param_1 + 0x5070), piVar1 != (int *)0x0)) &&
        (piVar1[1] != 0)) && (iVar6 = 0, 0 < *piVar1)) {
      iVar4 = 0;
      do {
        if (0x11ff < iVar4) {
          return;
        }
        iVar5 = piVar1[1] + iVar4;
        iVar2 = (int)(iVar6 + (iVar6 >> 0x1f & 0x1fU)) >> 5;
        uVar3 = 1 << ((byte)iVar6 & 0x1f);
        if ((*(byte *)(iVar5 + 0x62) & 2) != 0) {
          param_3[iVar2] = param_3[iVar2] | uVar3;
        }
        if ((*(byte *)(iVar5 + 0x62) & 4) == 0) {
          param_3[iVar2 + 2] = param_3[iVar2 + 2] & ~uVar3;
        }
        if ((*(byte *)(iVar5 + 0x62) & 8) == 0) {
          param_3[iVar2 + 1] = param_3[iVar2 + 1] & ~uVar3;
        }
        piVar1 = *(int **)(param_1 + 0x5070);
        iVar6 = iVar6 + 1;
        iVar4 = iVar4 + 0x90;
      } while (iVar6 < *piVar1);
    }
  }
  return;
}

