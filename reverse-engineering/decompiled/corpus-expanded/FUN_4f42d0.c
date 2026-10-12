/* Ghidra pseudocode, not original source.
 * ev_621a163f2f4eeffab67db0a5a6d80d4261cbfd10193b5f3a01bc1d3544017af8
 * Entry: 0x4f42d0; label: FUN_004f42d0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_004f42d0(int param_1,int param_2)

{
  int iVar1;
  
  iVar1 = (&DAT_0297e044)[param_1 * 3];
  if (-1 < iVar1) {
    if (param_2 == 0) {
      (&DAT_0297e048)[param_1 * 3] = 0;
      (&DAT_00917004)[iVar1 * 0x21] = 0xffffffff;
      return;
    }
    (&DAT_00917004)[iVar1 * 0x21] = param_1;
  }
  if (param_2 == 1) {
    if (DAT_0091ef30 == 0) {
      DAT_00800518 = iVar1;
    }
    DAT_0091ef30 = 1;
  }
  (&DAT_0297e048)[param_1 * 3] = param_2;
  return;
}

