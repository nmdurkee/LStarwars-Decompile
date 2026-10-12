/* Ghidra pseudocode, not original source.
 * ev_119981038e8c19adfdb272c0e357e55b3a12ebc602b993d3e023990f2be0b94d
 * Entry: 0x68b170; label: FUN_0068b170
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0068b170(int param_1,undefined4 *param_2)

{
  undefined4 *puVar1;
  
  param_1 = param_1 * 0x50;
  puVar1 = (undefined4 *)(param_1 + 8 + DAT_02962a14);
  *puVar1 = *param_2;
  puVar1[1] = param_2[1];
  puVar1[2] = param_2[2];
  *(undefined4 *)(param_1 + 0x14 + DAT_02962a14) = _DAT_02948ee8;
  *(undefined2 *)(param_1 + 0x34 + DAT_02962a14) = (undefined2)DAT_029629ec;
  *(undefined2 *)(param_1 + 0x36 + DAT_02962a14) = (undefined2)DAT_029629f0;
  if ((DAT_00810a88 != 3) &&
     ((DAT_0292318c - *(int *)(param_1 + 4 + DAT_02962a14)) + DAT_029629d8 < 0x3001)) {
    *(int *)(param_1 + 4 + DAT_02962a14) = DAT_0292318c;
  }
  DAT_029629fc = *(int *)(param_1 + 0x4c + DAT_02962a14) +
                 *(int *)(param_1 + 4 + DAT_02962a14) * 0xc;
  FUN_00689f70();
  return;
}

