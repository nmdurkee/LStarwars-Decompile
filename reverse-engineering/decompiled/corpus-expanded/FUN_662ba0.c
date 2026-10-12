/* Ghidra pseudocode, not original source.
 * ev_48e8314641b8677069cf0b2f56163e168ef7ac8043ee4515292faa1f02998c89
 * Entry: 0x662ba0; label: FUN_00662ba0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00662ba0(int param_1,int param_2)

{
  char cVar1;
  int iVar2;
  int iVar3;
  
  if (((DAT_029231a8 != -1) && ((&DAT_02924b60)[DAT_029231a8 * 0x16] != -1)) &&
     (iVar2 = *(int *)(DAT_0296209c +
                      *(short *)((&DAT_02924b60)[DAT_029231a8 * 0x16] * 0x330 + 0x182 + DAT_029620a4
                                ) * 4), param_1 != 0)) {
    if (param_1 == DAT_02924b3c) {
      cVar1 = *(char *)(iVar2 + 0x2c);
      if (((cVar1 == '\0') || (cVar1 == '\b')) || ((cVar1 == '\t' || (cVar1 == '\n')))) {
        *(undefined4 *)(iVar2 + 0x50) = *(undefined4 *)(param_2 + 0x54);
        return;
      }
      if ((((cVar1 == '\x06') || (cVar1 == '\a')) || (cVar1 == '\v')) || (cVar1 == '\f')) {
        iVar3 = FUN_006e6b90();
        *(float *)(iVar2 + 0x50) = (float)iVar3;
        return;
      }
    }
    else if (param_1 == DAT_0292fe10) {
      cVar1 = *(char *)(iVar2 + 0x2c);
      if ((((cVar1 == '\0') || (cVar1 == '\b')) || (cVar1 == '\t')) || (cVar1 == '\n')) {
        *(undefined4 *)(iVar2 + 0x5c) = *(undefined4 *)(param_2 + 0x54);
        return;
      }
      if (((cVar1 == '\x06') || (cVar1 == '\a')) || ((cVar1 == '\v' || (cVar1 == '\f')))) {
        iVar3 = FUN_006e6b90();
        *(float *)(iVar2 + 0x5c) = (float)iVar3;
        return;
      }
    }
    else if (param_1 == DAT_029211a4) {
      cVar1 = *(char *)(iVar2 + 0x2c);
      if (((cVar1 == '\0') || (cVar1 == '\b')) || ((cVar1 == '\t' || (cVar1 == '\n')))) {
        *(undefined4 *)(iVar2 + 0x68) = *(undefined4 *)(param_2 + 0x54);
      }
      else if (((cVar1 == '\x06') || (cVar1 == '\a')) || ((cVar1 == '\v' || (cVar1 == '\f')))) {
        iVar3 = FUN_006e6b90();
        *(float *)(iVar2 + 0x68) = (float)iVar3;
        return;
      }
    }
  }
  return;
}

