/* Ghidra pseudocode, not original source.
 * ev_cad26e3a9467a6f282c08bc6ac149c0630e72073e26a30c176ee0d766772994c
 * Entry: 0x566ac0; label: FUN_00566ac0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00566ac0(int param_1,undefined4 param_2,void *param_3)

{
  uint *puVar1;
  int iVar2;
  uint uVar3;
  uint *puVar4;
  int iVar5;
  
  if (param_3 != (void *)0x0) {
    _memset(param_3,0,0x40);
    _memset((void *)((int)param_3 + 0x40),-1,0x40);
    _memset((void *)((int)param_3 + 0x80),-1,0x40);
    _memset((void *)((int)param_3 + 0xc0),0,0x40);
    if (((param_1 != 0) && (*(int *)(param_1 + 0x50c8) != 0)) &&
       (iVar5 = 0, 0 < *(int *)(param_1 + 0x50c0))) {
      puVar4 = (uint *)(*(int *)(param_1 + 0x50c8) + 0x94);
      do {
        if (0x1ff < iVar5) {
          return;
        }
        iVar2 = (int)(iVar5 + (iVar5 >> 0x1f & 0x1fU)) >> 5;
        uVar3 = 1 << ((byte)iVar5 & 0x1f);
        if ((*puVar4 & 1) != 0) {
          puVar1 = (uint *)((int)param_3 + iVar2 * 4);
          *puVar1 = *puVar1 | uVar3;
        }
        if ((*puVar4 & 0x4000) == 0) {
          puVar1 = (uint *)((int)param_3 + iVar2 * 4 + 0x80);
          *puVar1 = *puVar1 & ~uVar3;
        }
        if ((*puVar4 & 0x800000) == 0) {
          puVar1 = (uint *)((int)param_3 + iVar2 * 4 + 0x40);
          *puVar1 = *puVar1 & ~uVar3;
        }
        if ((*puVar4 & 0x10000000) != 0) {
          puVar1 = (uint *)((int)param_3 + iVar2 * 4 + 0xc0);
          *puVar1 = *puVar1 | uVar3;
        }
        iVar5 = iVar5 + 1;
        puVar4 = puVar4 + 0x45;
      } while (iVar5 < *(int *)(param_1 + 0x50c0));
    }
  }
  return;
}

