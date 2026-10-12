/* Ghidra pseudocode, not original source.
 * ev_c99ba83a21253fbea00a1b2af974464e548d813850fcca855330552d9e62c3cd
 * Entry: 0x408640; label: FUN_00408640
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_00408640(int param_1,uint param_2)

{
  short sVar1;
  
  sVar1 = *(short *)(param_1 + 0x1064);
  if ((((sVar1 == DAT_007f1a1c) || (sVar1 == DAT_007f1ad0)) || (sVar1 == DAT_007f1ad8)) ||
     (((sVar1 == DAT_007f1ae4 || (sVar1 == DAT_007f1ae8)) || (sVar1 == DAT_007f1aec)))) {
    if (((*(char *)(param_1 + 0xe3a) == '\0') && ((param_2 == 0 || (param_2 == 2)))) ||
       ((*(char *)(param_1 + 0xe3a) == '\x01' && ((param_2 == 1 || (param_2 == 3)))))) {
      return 0;
    }
  }
  else if ((sVar1 == DAT_007f19a4) || (sVar1 == DAT_007f1af0)) {
    if (param_2 != *(byte *)(param_1 + 0xe3a)) {
      return 0;
    }
  }
  else if ((((sVar1 == DAT_007f18f4) || (sVar1 == DAT_007f19e8)) || (sVar1 == DAT_007f19e4)) &&
          (param_2 != *(byte *)(param_1 + 0xe3a))) {
    return 0;
  }
  return 1;
}

