/* Ghidra pseudocode, not original source.
 * ev_9a3410a9c272a2064cc0564fa84db44ccced53000acc775659afcf5219797551
 * Entry: 0x4e5b70; label: FUN_004e5b70
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_004e5b70(int param_1)

{
  int iVar1;
  
  iVar1 = 0;
  do {
    if ((&DAT_00889618)[iVar1] == param_1) {
      (&DAT_00889618)[iVar1] = 0;
      return;
    }
    iVar1 = iVar1 + 1;
  } while (iVar1 < 3);
  return;
}

