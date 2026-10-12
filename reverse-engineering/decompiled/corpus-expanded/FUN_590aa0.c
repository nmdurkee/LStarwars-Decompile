/* Ghidra pseudocode, not original source.
 * ev_b142addbfc413d4476e6a560937bb6deb0d869285f4b587c6bb2379626f1bfc8
 * Entry: 0x590aa0; label: FUN_00590aa0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00590aa0(undefined4 param_1,int *param_2,undefined4 *param_3)

{
  int iVar1;
  uint uVar2;
  ushort *puVar3;
  int iVar4;
  
  if (param_3 != (undefined4 *)0x0) {
    *param_3 = 0;
    param_3[1] = 0;
    param_3[2] = 0xffffffff;
    param_3[3] = 0xffffffff;
    param_3[4] = 0xffffffff;
    param_3[5] = 0xffffffff;
    param_3[6] = 0;
    param_3[7] = 0;
    _memset(param_3 + 8,0,0x40);
    iVar4 = 0;
    if ((short)param_2[1] != 0) {
      puVar3 = (ushort *)(*param_2 + 0x7a);
      do {
        if (0x3f < iVar4) {
          return;
        }
        iVar1 = (int)(iVar4 + (iVar4 >> 0x1f & 0x1fU)) >> 5;
        uVar2 = 1 << ((byte)iVar4 & 0x1f);
        if (*(byte *)((int)puVar3 + -0xd) != 0) {
          param_3[iVar1] = param_3[iVar1] | uVar2;
        }
        if ((*puVar3 & 2) == 0) {
          param_3[iVar1 + 4] = param_3[iVar1 + 4] & ~uVar2;
        }
        if ((*puVar3 & 1) == 0) {
          param_3[iVar1 + 2] = param_3[iVar1 + 2] & ~uVar2;
        }
        if ((*puVar3 & 0x200) != 0) {
          param_3[iVar1 + 6] = param_3[iVar1 + 6] | uVar2;
        }
        *(byte *)(iVar4 + (int)(param_3 + 8)) = *(byte *)((int)puVar3 + -0xb);
        iVar4 = iVar4 + 1;
        puVar3 = puVar3 + 0x3e;
      } while (iVar4 < (int)(uint)*(ushort *)(param_2 + 1));
    }
  }
  return;
}

