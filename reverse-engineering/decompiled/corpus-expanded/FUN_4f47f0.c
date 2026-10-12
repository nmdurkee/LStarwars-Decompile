/* Ghidra pseudocode, not original source.
 * ev_621a163f2f4eeffab67db0a5a6d80d4261cbfd10193b5f3a01bc1d3544017af8
 * Entry: 0x4f47f0; label: FUN_004f47f0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_004f47f0(int param_1,int param_2)

{
  int iVar1;
  
  if (-1 < param_2) {
    FUN_006d6720();
    iVar1 = (&DAT_0297e044)[param_1 * 3];
    if (-1 < iVar1) {
      (&DAT_00917004)[iVar1 * 0x21] = 0xffffffff;
    }
    (&DAT_0297e048)[param_1 * 3] = 0;
    if (-1 < iVar1) {
      (&DAT_00917004)[iVar1 * 0x21] = 0xffffffff;
    }
    (&DAT_00917014)[param_2 * 0x21] = 0;
    (&DAT_0297e044)[param_1 * 3] = param_2;
    (&DAT_00917004)[param_2 * 0x21] = param_1;
    if (DAT_0091ef30 == 0) {
      DAT_00800518 = param_2;
    }
    *(short *)(&DAT_00800520 + param_1 * 2) = (short)param_2;
    DAT_0091ef30 = 1;
    (&DAT_0297e048)[param_1 * 3] = 1;
    FUN_006d9540();
    return;
  }
  if (-1 < (int)(&DAT_0297e044)[param_1 * 3]) {
    (&DAT_00917004)[(&DAT_0297e044)[param_1 * 3] * 0x21] = 0xffffffff;
  }
  (&DAT_0297e048)[param_1 * 3] = 0;
  return;
}

