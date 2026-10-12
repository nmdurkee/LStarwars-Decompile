/* Ghidra pseudocode, not original source.
 * ev_1e128395f166d68d7029ddd19e18d2d5e170338b26e7199f616481a8a2050617
 * Entry: 0x4edfe0; label: FUN_004edfe0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_004edfe0(int param_1)

{
  int iVar1;
  int iVar2;
  float10 fVar3;
  float10 fVar4;
  undefined4 local_8;
  float local_4;
  
  local_8 = 0x11;
  iVar1 = **(int **)(param_1 + 0x50b8);
  DAT_0088a6cc = 0;
  DAT_0088a56c = 0;
  DAT_0088a56d = 0;
  for (iVar2 = 0; (iVar1 != 0 && (iVar2 < *(int *)(*(int *)(param_1 + 0x50b8) + 8)));
      iVar2 = iVar2 + 1) {
    if (((*(byte *)(iVar1 + 0x17) & 8) == 0) && ((byte)(*(char *)(iVar1 + 0x18) - 2U) < 3)) {
      *(undefined1 *)(iVar1 + 0x24) = 0;
    }
    if (*(char *)(iVar1 + 0x18) == '\x04') {
      fVar3 = (float10)FUN_005b9d90(&local_8);
      fVar4 = (float10)FUN_005b9d90(&local_8);
      local_4 = (float)((fVar4 * (float10)4.0 - (float10)5.871) - (float10)1.5);
      *(float *)(iVar1 + 8) = (float)((fVar3 * (float10)4.0 - (float10)7.656) - (float10)1.5);
      *(float *)(iVar1 + 0x10) = local_4;
    }
    iVar1 = iVar1 + 0x2c;
  }
  return;
}

