/* Ghidra pseudocode, not original source.
 * ev_119981038e8c19adfdb272c0e357e55b3a12ebc602b993d3e023990f2be0b94d
 * Entry: 0x68c440; label: FUN_0068c440
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_0068c440(int param_1,int param_2)

{
  int *piVar1;
  
  if ((&DAT_02924b5c)[param_1 * 0x16] != param_2) {
    piVar1 = &DAT_02924b60 + param_1 * 0x16;
    if ((&DAT_02924b60)[param_1 * 0x16] != -1) {
      if ((&DAT_02924b60)[param_1 * 0x16] != 99999) {
        FUN_00684400(piVar1);
      }
      DAT_02962a2c = DAT_02962a2c + -1;
      *piVar1 = -1;
    }
    FUN_00684ee0(piVar1,param_2,(&DAT_02924b50)[param_1 * 0x16],(&DAT_02924b54)[param_1 * 0x16],
                 (&DAT_02924b58)[param_1 * 0x16]);
    if (*piVar1 != -1) {
      *(undefined1 *)(*piVar1 * 0x330 + 0x2f9 + DAT_029620a4) = 0;
    }
    (&DAT_02924b5c)[param_1 * 0x16] = param_2;
  }
  return param_1;
}

