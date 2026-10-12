/* Ghidra pseudocode, not original source.
 * ev_5fa8a0c629ff9dcf3dc3d25725019308ff1f1a9e08c812d6ee08209fa3308603
 * Entry: 0x654fa0; label: FUN_00654fa0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00654fa0(void)

{
  int iVar1;
  int iVar2;
  float local_8;
  undefined2 local_4;
  
  DAT_00810964 = DAT_00810964 + -1;
  if (DAT_00810964 < 1) {
    DAT_00810964 = 6;
    iVar2 = DAT_029620c0;
    if ((&DAT_0292fd30)[DAT_029620c0] == 0) {
      do {
        iVar2 = iVar2 + 1;
        if (4 < iVar2) {
          iVar2 = 0;
        }
      } while ((iVar2 != DAT_029620c0) && ((&DAT_0292fd30)[iVar2] == 0));
      DAT_029620c0 = iVar2;
      if ((&DAT_0292fd30)[iVar2] == 0) {
        DAT_00810964 = 6;
        return;
      }
    }
    for (iVar2 = (&DAT_0292fd30)[DAT_029620bc]; iVar2 != 0; iVar2 = *(int *)(iVar2 + 0x5c)) {
      iVar1 = *(int *)(iVar2 + 8);
      if (iVar1 != 0) {
        if (*(char *)(iVar1 + 0x2f8) == '\0') {
          *(undefined2 *)(iVar2 + 0x60) = *(undefined2 *)(iVar1 + 0x328);
        }
        else {
          local_8 = (float)*(ushort *)(iVar1 + 0x328) + *(float *)(iVar1 + 0x31c) * 25.0;
          if (65535.0 < local_8) {
            local_8 = 65535.0;
          }
          local_4 = (undefined2)(int)ROUND(local_8);
          *(undefined2 *)(iVar2 + 0x60) = local_4;
        }
      }
    }
  }
  return;
}

