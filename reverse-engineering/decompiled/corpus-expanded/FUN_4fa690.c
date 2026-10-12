/* Ghidra pseudocode, not original source.
 * ev_1c43a4838a2574475d6c9682bec7b0db8a67988369837137b0115a570ceb3a0a
 * Entry: 0x4fa690; label: FUN_004fa690
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

longlong FUN_004fa690(char *param_1)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int extraout_EDX;
  longlong lVar4;
  
  uVar1 = DAT_0091ee90;
  iVar3 = DAT_0091ee88;
  DAT_0091ee90 = 0;
  if ((DAT_0091ee88 != 0) && (iVar2 = FUN_004f9aa0(DAT_0091ee88,param_1), -1 < iVar2)) {
    return (longlong)*(int *)(*(int *)(iVar3 + 8) + 8 + iVar2 * 0x10);
  }
  lVar4 = -1;
  if (((param_1 != (char *)0x0) && (lVar4 = -1, *param_1 != '\0')) &&
     (iVar3 = FUN_004fa3f0(param_1,0,iVar3,0), lVar4 = -1, iVar3 != 0)) {
    do {
      FUN_004f6de0(iVar3,0,0,2);
    } while (extraout_EDX < 0);
    lVar4 = FUN_004f6d10(iVar3);
    FUN_004f99e0(iVar3);
  }
  DAT_0091ee90 = uVar1;
  return lVar4;
}

