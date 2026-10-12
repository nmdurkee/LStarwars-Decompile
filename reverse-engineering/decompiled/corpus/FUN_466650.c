/* Ghidra analysis pseudocode, not original source.
 * ev_ca54e982c9f1bc50e375bb5e2806226defe8bc9769d9e20e94a8e2507c387560
 * Entry: 0x466650; label: FUN_00466650
 */

void FUN_00466650(undefined4 param_1,int *param_2,undefined4 *param_3)

{
  int iVar1;
  uint uVar2;
  byte *pbVar3;
  int iVar4;
  
  if (param_3 != (undefined4 *)0x0) {
    *param_3 = 0xffffffff;
    param_3[1] = 0xffffffff;
    param_3[2] = 0xffffffff;
    param_3[3] = 0xffffffff;
    param_3[4] = 0xffffffff;
    param_3[5] = 0xffffffff;
    iVar4 = 0;
    if ((short)param_2[1] != 0) {
      pbVar3 = (byte *)(*param_2 + 0x2a);
      do {
        if (0x5f < iVar4) {
          return;
        }
        iVar1 = (int)(iVar4 + (iVar4 >> 0x1f & 0x1fU)) >> 5;
        uVar2 = 1 << ((byte)iVar4 & 0x1f);
        if ((*pbVar3 & 2) == 0) {
          param_3[iVar1 + 3] = param_3[iVar1 + 3] & ~uVar2;
        }
        if ((*pbVar3 & 1) == 0) {
          param_3[iVar1] = param_3[iVar1] & ~uVar2;
        }
        iVar4 = iVar4 + 1;
        pbVar3 = pbVar3 + 0x2c;
      } while (iVar4 < (int)(uint)*(ushort *)(param_2 + 1));
    }
  }
  return;
}

