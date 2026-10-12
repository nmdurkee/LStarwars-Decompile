/* Ghidra analysis pseudocode, not original source.
 * ev_14516b90afd78e4126f0b3f4a370dbc2a5912f8e0102dea09dbec3c8384d0f78
 * Entry: 0x6e3720; label: FUN_006e3720
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_006e3720(int param_1,int param_2)

{
  int in_ECX;
  
  if ((param_1 == 0) || (*(int *)(param_1 + 8) == 0)) {
    if (param_2 != 0) {
      FUN_006e2880(param_2,0);
      return;
    }
    if (*(int *)(in_ECX + 0x638) == 0) {
      FUN_006e2880(0,*(undefined4 *)(in_ECX + 0x6c4));
      *(undefined4 *)(in_ECX + 0x6e8) = *(undefined4 *)(in_ECX + 0x6c4);
    }
    else {
      FUN_006e2880(0,*(undefined4 *)(in_ECX + 0x6b0));
      FUN_006e5340(0xa8,0);
      *(undefined4 *)(in_ECX + 0x6e8) = *(undefined4 *)(in_ECX + 0x6b0);
    }
    DAT_00973900 = *(uint *)(in_ECX + 0x138);
    DAT_00973904 = *(uint *)(in_ECX + 0x13c);
  }
  else {
    FUN_006e2880(param_2,*(int *)(param_1 + 8));
    if (param_2 != 0) {
      return;
    }
    DAT_00973900 = (uint)*(ushort *)(param_1 + 0x14);
    DAT_00973904 = (uint)*(ushort *)(param_1 + 0x16);
  }
  _DAT_0080202c = (int)DAT_00973900 / 2;
  _DAT_00802030 = (int)DAT_00973904 / 2;
  FUN_006e2510();
  return;
}

