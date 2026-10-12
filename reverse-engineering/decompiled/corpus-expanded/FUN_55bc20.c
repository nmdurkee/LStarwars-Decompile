/* Ghidra pseudocode, not original source.
 * ev_ad94bec40fb329b942d4f858c664032de23cf17ab2243631134a23feb763d3d7
 * Entry: 0x55bc20; label: FUN_0055bc20
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_0055bc20(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  if (DAT_0093b280 == 0) {
    return -1;
  }
  iVar3 = 0;
  if (0 < DAT_0093b26c) {
    iVar2 = 0;
    do {
      iVar1 = FUN_004f8b10(*(undefined4 *)(iVar2 + DAT_0093b280),param_1);
      if (iVar1 == 0) {
        return iVar3;
      }
      iVar3 = iVar3 + 1;
      iVar2 = iVar2 + 0xc;
    } while (iVar3 < DAT_0093b26c);
  }
  return -1;
}

