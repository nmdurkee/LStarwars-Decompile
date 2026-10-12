/* Ghidra pseudocode, not original source.
 * ev_da30da9df459bd28e82b339ffdc0f4cd1266c83ded903d656831cff2a8a86063
 * Entry: 0x46f620; label: FUN_0046f620
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0046f620(int param_1,undefined4 param_2,int param_3)

{
  int *piVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  
  iVar4 = 0;
  if ((((param_1 != 0) && (piVar1 = *(int **)(param_1 + 0x5070), piVar1 != (int *)0x0)) &&
      (piVar1[1] != 0)) && (0 < *piVar1)) {
    param_1 = 0;
    do {
      iVar5 = piVar1[1] + param_1;
      FUN_0046f4d0(iVar5);
      if ((param_3 != 0) && (iVar4 < 0x20)) {
        iVar2 = (int)(iVar4 + (iVar4 >> 0x1f & 0x1fU)) >> 5;
        uVar3 = 1 << ((byte)iVar4 & 0x1f);
        if ((*(uint *)(param_3 + iVar2 * 4) & uVar3) != 0) {
          *(byte *)(iVar5 + 0x62) = *(byte *)(iVar5 + 0x62) | 2;
        }
        *(byte *)(iVar5 + 0x62) =
             *(byte *)(iVar5 + 0x62) ^
             (((*(uint *)(param_3 + 8 + iVar2 * 4) & uVar3) != 0) * '\x04' ^ *(byte *)(iVar5 + 0x62)
             ) & 4;
        *(byte *)(iVar5 + 0x62) =
             (((*(uint *)(param_3 + 4 + iVar2 * 4) & uVar3) != 0) * '\b' ^ *(byte *)(iVar5 + 0x62))
             & 8 ^ *(byte *)(iVar5 + 0x62);
      }
      param_1 = param_1 + 0x90;
      iVar4 = iVar4 + 1;
    } while (iVar4 < *piVar1);
  }
  return;
}

