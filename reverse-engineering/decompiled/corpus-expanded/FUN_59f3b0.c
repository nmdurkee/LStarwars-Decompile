/* Ghidra pseudocode, not original source.
 * ev_4c4127be7d58e8981fbef62e7b9304e5f7a8f47caff33366593b2d257bcf3f12
 * Entry: 0x59f3b0; label: FUN_0059f3b0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0059f3b0(int param_1,undefined4 *param_2)

{
  int iVar1;
  uint uVar2;
  ushort *puVar3;
  int iVar4;
  
  if ((param_1 != 0) && (param_2 != (undefined4 *)0x0)) {
    _memset(param_2,0,0x144);
    *param_2 = 1;
    iVar4 = 0;
    if (0 < *(int *)(param_1 + 4)) {
      puVar3 = (ushort *)(*(int *)(param_1 + 8) + 10);
      do {
        iVar1 = (int)(iVar4 + (iVar4 >> 0x1f & 0x1fU)) >> 5;
        uVar2 = 1 << ((byte)iVar4 & 0x1f);
        if ((*puVar3 & 1) != 0) {
          param_2[iVar1 + 1] = param_2[iVar1 + 1] | uVar2;
        }
        if ((*puVar3 & 0x100) != 0) {
          param_2[iVar1 + 0x11] = param_2[iVar1 + 0x11] | uVar2;
        }
        if ((*puVar3 & 2) != 0) {
          param_2[iVar1 + 0x21] = param_2[iVar1 + 0x21] | uVar2;
        }
        if ((*puVar3 & 0x20) != 0) {
          param_2[iVar1 + 0x31] = param_2[iVar1 + 0x31] | uVar2;
        }
        if ((*puVar3 & 0x400) != 0) {
          param_2[iVar1 + 0x41] = param_2[iVar1 + 0x41] | uVar2;
        }
        iVar4 = iVar4 + 1;
        puVar3 = puVar3 + 0x10;
      } while (iVar4 < *(int *)(param_1 + 4));
    }
  }
  return;
}

