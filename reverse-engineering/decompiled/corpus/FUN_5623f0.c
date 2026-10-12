/* Ghidra analysis pseudocode, not original source.
 * ev_ac23db90eeef6e74a247016e3a520edd15ea735459e03f7d3b11d2be7c6b3fca
 * Entry: 0x5623f0; label: FUN_005623f0
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005623f0(int param_1)

{
  float fVar1;
  int iVar2;
  
  if ((DAT_0080286c != -1) && (*(char *)(param_1 + 0x7b5) == DAT_0080286c)) {
    if (((*(uint *)(param_1 + 0xe20) & 0x100000) != 0) &&
       ((*(uint *)(*(int *)(param_1 + 0xca4) + 4) & DAT_00802278) == 0)) {
      *(uint *)(param_1 + 0xe20) = *(uint *)(param_1 + 0xe20) & 0xffefffff;
    }
    if (((*(int *)(*(int *)(*(int *)(param_1 + 0x50) + 0xc) + *(short *)(param_1 + 0x7aa) * 4) == 0)
        || (iVar2 = FUN_0062f1a0(param_1 + 8), iVar2 == *(short *)(param_1 + 0x7aa))) &&
       (fVar1 = *(float *)(param_1 + 0x77c) - _DAT_00925018, *(float *)(param_1 + 0x77c) = fVar1,
       fVar1 <= 0.0)) {
      *(undefined1 *)(param_1 + 0x7b5) = 0xff;
      if (((*(uint *)(*(int *)(param_1 + 0xca4) + 4) & DAT_00802278) != 0) &&
         ((*(uint *)(param_1 + 0xe20) & 0x100000) == 0)) {
        FUN_00562310(param_1);
        return;
      }
      *(undefined4 *)(param_1 + 0x68) = 0;
      *(undefined4 *)(param_1 + 0x70) = 0;
      return;
    }
  }
  return;
}

