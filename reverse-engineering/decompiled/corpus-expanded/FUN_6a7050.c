/* Ghidra pseudocode, not original source.
 * ev_d0baaaa1d022e9a6bc644bf87cbac2e9d23f713faf88b9587519a457b813b0f8
 * Entry: 0x6a7050; label: FUN_006a7050
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006a7050(float param_1,float *param_2,undefined4 *param_3)

{
  uint uVar1;
  uint uVar2;
  uint unaff_ESI;
  uint unaff_EDI;
  
  uVar2 = (int)(unaff_EDI - unaff_ESI) >> 0x1f;
  uVar1 = ((int)unaff_ESI < (int)unaff_EDI) - 1;
  uVar2 = 0x1f - ((unaff_EDI - unaff_ESI ^ uVar2) - uVar2);
  *param_2 = *(float *)(&DAT_00816b90 + (~uVar1 & unaff_EDI | uVar1 & unaff_ESI) * 4) *
             (*(float *)(&DAT_00816f90 + (((int)uVar2 < 0) - 1 & uVar2) * 4) + 1.0) * param_1;
  *param_3 = 0;
  return;
}

