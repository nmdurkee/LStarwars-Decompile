/* Ghidra pseudocode, not original source.
 * ev_1c43a4838a2574475d6c9682bec7b0db8a67988369837137b0115a570ceb3a0a
 * Entry: 0x4fadd0; label: FUN_004fadd0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_004fadd0(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  if ((DAT_0297dc08 == 1) && (DAT_0297dc14 != DAT_0297dc0c)) {
    if ((param_1 != 0) &&
       (iVar2 = FUN_004fa3f0(param_1,1,DAT_0091ee88,0), iVar1 = DAT_0297dc0c, iVar2 != 0)) {
      iVar3 = DAT_0297dc14 - DAT_0297dc0c;
      FUN_004f04b0(iVar2,iVar3);
      FUN_004f03d0(iVar2,iVar1,iVar3);
      FUN_004f0530(iVar2,0xe0f);
      FUN_004f99e0(iVar2);
    }
    DAT_0297dc20 = 0;
    DAT_0297dc08 = 0;
  }
  return;
}

