/* Ghidra analysis pseudocode, not original source.
 * ev_28935bb75220519b9cd6c8dd2893feffbabc6fed0a1828833445fdd6a861260d
 * Entry: 0x683e90; label: FUN_00683e90
 */

void FUN_00683e90(int param_1,int param_2)

{
  int iVar1;
  short sVar2;
  
  iVar1 = *(int *)(DAT_0296209c + *(short *)(param_1 + 0x182) * 4);
  *(short *)(param_1 + 0x18e) = (short)param_2;
  if (*(char *)(iVar1 + 0x2e) == '\a') {
    param_2 = param_2 + 0xb;
    sVar2 = ((short)(param_2 / 0xc) + (short)(param_2 >> 0x1f)) -
            (short)((longlong)param_2 * 0x2aaaaaab >> 0x3f);
  }
  else {
    sVar2 = (short)((int)(param_2 + 0x1f + (param_2 + 0x1f >> 0x1f & 0x1fU)) >> 5);
  }
  *(short *)(param_1 + 0x18c) = sVar2;
  if (0x20 < *(short *)(param_1 + 0x18c)) {
    *(undefined2 *)(param_1 + 0x18c) = 0x20;
    *(ushort *)(param_1 + 0x18e) = (-(ushort)(*(char *)(iVar1 + 0x2e) != '\a') & 0x280) + 0x180;
  }
  if (*(short *)(param_1 + 0x18c) == *(short *)(param_1 + 0x180)) {
    *(undefined2 *)(param_1 + 0x186) = *(undefined2 *)(param_1 + 0x18e);
    return;
  }
  if ((*(short *)(param_1 + 0x18c) != 0) && (*(short *)(param_1 + 0x180) == 0)) {
    FUN_00683560(param_1);
  }
  return;
}

