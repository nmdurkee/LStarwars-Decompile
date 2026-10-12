/* Ghidra analysis pseudocode, not original source.
 * ev_82de32114f0a758998fb1b139028178946084d97602e6dd81f3d90db1eb3e6aa
 * Entry: 0x5ae720; label: FUN_005ae720
 */

void FUN_005ae720(int param_1,undefined4 param_2,undefined4 *param_3)

{
  int *piVar1;
  int iVar2;
  uint uVar3;
  byte *pbVar4;
  int iVar5;
  
  if (param_3 != (undefined4 *)0x0) {
    *param_3 = 0xffffffff;
    param_3[1] = 0xffffffff;
    param_3[2] = 0xffffffff;
    param_3[3] = 0xffffffff;
    param_3[4] = 0xffffffff;
    param_3[5] = 0xffffffff;
    param_3[6] = 0xffffffff;
    param_3[7] = 0xffffffff;
    param_3[8] = 0;
    param_3[9] = 0;
    param_3[10] = 0;
    param_3[0xb] = 0;
    param_3[0xc] = 0;
    param_3[0xd] = 0;
    param_3[0xe] = 0;
    param_3[0xf] = 0;
    if (((param_1 != 0) && (piVar1 = *(int **)(param_1 + 0x5108), piVar1 != (int *)0x0)) &&
       (piVar1[1] != 0)) {
      iVar5 = 0;
      if (0 < piVar1[1]) {
        pbVar4 = (byte *)(*piVar1 + 0x24);
        do {
          iVar2 = (int)(iVar5 + (iVar5 >> 0x1f & 0x1fU)) >> 5;
          uVar3 = 1 << ((byte)iVar5 & 0x1f);
          if ((*pbVar4 & 2) == 0) {
            param_3[iVar2] = param_3[iVar2] & ~uVar3;
          }
          if ((*pbVar4 & 1) != 0) {
            param_3[iVar2 + 8] = param_3[iVar2 + 8] | uVar3;
          }
          iVar5 = iVar5 + 1;
          pbVar4 = pbVar4 + 0x28;
        } while (iVar5 < *(int *)(*(int *)(param_1 + 0x5108) + 4));
      }
    }
  }
  return;
}

