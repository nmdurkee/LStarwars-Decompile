/* Ghidra pseudocode, not original source.
 * ev_b0f5904faee5764ce17927395194cf9c706559b4251213f14920f3fe78cd8be0
 * Entry: 0x43c7a0; label: FUN_0043c7a0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_0043c7a0(byte param_1)

{
  int iVar1;
  
  if ((int)(uint)param_1 < DAT_0093d500) {
    iVar1 = (uint)param_1 * 0x10d8 + DAT_0093d504;
    if ((((*(uint *)(iVar1 + 0x1fc) & 1) != 0) &&
        (((*(uint *)(iVar1 + 0x1fc) & 0x1000) != 0 || (*(char *)(iVar1 + 0x406) == '\x03')))) &&
       ((*(char *)(iVar1 + 0x28b) == '\0' || (0.0 < *(float *)(iVar1 + 0x1010))))) {
      return iVar1;
    }
  }
  return 0;
}

