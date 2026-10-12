/* Ghidra analysis pseudocode, not original source.
 * ev_2c014b146e9258db07d80d50b3912bad4b2773c74b3e67189abd65c219d7972f
 * Entry: 0x5ad460; label: FUN_005ad460
 */

void FUN_005ad460(undefined4 param_1,int *param_2,undefined4 *param_3)

{
  int iVar1;
  uint uVar2;
  ushort *puVar3;
  int iVar4;
  
  if (param_3 != (undefined4 *)0x0) {
    *param_3 = 0xffffffff;
    param_3[1] = 0xffffffff;
    param_3[2] = 0xffffffff;
    param_3[3] = 0xffffffff;
    param_3[4] = 0;
    param_3[5] = 0;
    param_3[6] = 0;
    param_3[7] = 0;
    param_3[8] = 0;
    param_3[9] = 0;
    param_3[10] = 0;
    param_3[0xb] = 0;
    _memset(param_3 + 0xc,0xff,0x40);
    iVar4 = 0;
    if ((short)param_2[2] != 0) {
      puVar3 = (ushort *)(*param_2 + 0x13a);
      do {
        if (0x3f < iVar4) {
          return;
        }
        iVar1 = (int)(iVar4 + (iVar4 >> 0x1f & 0x1fU)) >> 5;
        uVar2 = 1 << ((byte)iVar4 & 0x1f);
        if ((*puVar3 & 4) == 0) {
          param_3[iVar1 + 2] = param_3[iVar1 + 2] & ~uVar2;
        }
        if ((*puVar3 & 2) == 0) {
          param_3[iVar1] = param_3[iVar1] & ~uVar2;
        }
        if ((*puVar3 & 8) != 0) {
          param_3[iVar1 + 4] = param_3[iVar1 + 4] | uVar2;
        }
        if ((*puVar3 & 0x10) != 0) {
          param_3[iVar1 + 6] = param_3[iVar1 + 6] | uVar2;
        }
        if ((*puVar3 & 0x20) != 0) {
          param_3[iVar1 + 8] = param_3[iVar1 + 8] | uVar2;
        }
        if ((*puVar3 & 0x400) != 0) {
          param_3[iVar1 + 10] = param_3[iVar1 + 10] | uVar2;
        }
        *(byte *)(iVar4 + (int)(param_3 + 0xc)) = (byte)puVar3[-6];
        iVar4 = iVar4 + 1;
        puVar3 = puVar3 + 0x9e;
      } while (iVar4 < (int)(uint)*(ushort *)(param_2 + 2));
    }
  }
  return;
}

